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
		m_window1->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);

		RISE_CORE_INFO("{0}", e.toString());
	}

	void Application::PushLayer(Layer* Layer) {
		m_LayerStack.PushLayer(Layer);
	}

	void Application::PushOverlay(Layer* Layer) {
		m_LayerStack.PushOverlay(Layer);
	}

	

}