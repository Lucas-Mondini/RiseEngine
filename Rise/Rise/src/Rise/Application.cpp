#include "RisePCH.h"
#include "Application.h"

namespace Rise {
	void Application::Run() {
		while (true) {
			glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(m_window->get());
		}

	}

	Application::~Application() {
		delete m_window;
	}

	Application::Application() {
		m_window = new Window(800, 600, "Rise Engine");
	}
}