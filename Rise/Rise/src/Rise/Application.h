#pragma once
#include <RisePCH.h>
#include "Core.h"
#include "Window.h"


namespace Rise {
	class RISE_API Application {
	public:
		Application();

		~Application();

		void Run();
	private:
		Rise::Window* m_window;
	};

	Application* CreateApplication();
}
