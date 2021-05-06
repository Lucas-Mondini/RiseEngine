#pragma once

#include <Rise/Core.h>

namespace Rise {
	class RISE_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void onUpdate() {}

		inline const std::string& getName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}