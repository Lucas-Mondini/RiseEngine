#pragma once
#include <RisePCH.h>
#include <Rise/Event/InputEvent.h>
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"


namespace Rise {
	class RISE_API Application {
	public:
		Application();
		~Application();

		void Run();


		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		Rise::Window* m_window1;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}
