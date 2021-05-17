#pragma once

#include <RisePCH.h>
#include "Event.h"

namespace Rise {
	

	//Key events
	class RISE_API KeyEvent : public Event {
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode){}

		int m_KeyCode;
	};

	class RISE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		int getRepeatCount() const { return m_RepeatCount; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();

		}

		EVENT_CLASS_TYPE(KeyPressed)

	protected:
		int m_RepeatCount;
	};

	class RISE_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};



	//mouse Events
	class RISE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};


	class RISE_API MouseButtonPressedEvent : public Event {
	public:
		MouseButtonPressedEvent(int mouseButton)
			: m_mouseButton(mouseButton) {}

		inline int getMouseButton() const { return m_mouseButton; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_mouseButton;
			return ss.str();
		}


		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)

	protected:
		int m_mouseButton;
	};

	class RISE_API MouseButtonReleasedEvent : public Event {
	public:
		MouseButtonReleasedEvent(int mouseButton)
			: m_mouseButton(mouseButton) {}

		inline int getMouseButton() const { return m_mouseButton; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_mouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
	protected:
		int m_mouseButton;
	};

	class RISE_API mouseScrollEvent : public Event {
	public:
		mouseScrollEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset){}

		
		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }


		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};



}