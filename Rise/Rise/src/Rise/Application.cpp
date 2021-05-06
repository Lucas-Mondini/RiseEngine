#include "RisePCH.h"
#include "Application.h"

namespace Rise {
	void Application::Run() {
		while (!glfwWindowShouldClose(m_window1->get())) {

			for (Layer* layer : m_LayerStack)
				layer->onUpdate();

			m_window1->Update();
			glfwPollEvents();
		}

	}

	Application::~Application() {
		delete m_window1;
	}

	Application::Application() {
		m_window1 = new Window(1280, 720, "Rise Engine");
	}

	void Application::PushLayer(Layer* Layer) {
		m_LayerStack.PushLayer(Layer);
	}

	void Application::PushOverlay(Layer* Layer) {
		m_LayerStack.PushOverlay(Layer);
	}
}