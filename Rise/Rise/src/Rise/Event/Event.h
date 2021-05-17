#pragma once
#include <RisePCH.h>
#include <Rise/Core.h>

//this whole archive is based on The Cherno - Hazel engine event

namespace Rise {

	enum class EventType {

		//Window Events starts with 1
		WindowClose = 10,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		//App Events starts with 2
		AppTick = 20,
		AppUpdate,
		AppRender,

		//Key Events starts with 3
		KeyPressed = 30,
		KeyReleased,

		//Mouse Events starts with 4
		MouseButtonPressed = 40,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory {
		None = 0,

		EventCategoryApplication	= LShiftbit(0),
		EventCategoryKeyboard		= LShiftbit(1),
		EventCategoryMouse			= LShiftbit(2),
		EventCategoryMouseButton	= LShiftbit(3),
		EventCategoryInput			= LShiftbit(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType getStaticType()				{ return EventType::##type; }\
								virtual EventType getEventType() const override { return getStaticType(); }\
								virtual const char* getName() const override	{ return #type; }


#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class RISE_API Event {
		friend class EventDispatcher;

	public:
		virtual EventType getEventType()	const = 0;
		virtual const char* getName()		const = 0;
		virtual int getCategoryFlags()		const = 0;
		virtual std::string toString() const { return getName(); }


		// @return bool for category flag
		inline bool isInCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;

	};

	class EventDispatcher {
		template<typename T>
		using Fn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(Fn<T> func) {
			if (m_Event.getEventType() == T::getStaticType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream os, const Event& e) {
		return os << e.toString();
	}

}