#include "RisePCH.h"
#include "Application.h"

namespace Rise {
	void Application::Run() {
		while (!glfwWindowShouldClose(m_window1->get())) {
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
}