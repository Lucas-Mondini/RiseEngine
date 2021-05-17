#include "RisePCH.h"
#include <Rise/Window.h>


namespace Rise {
	Window::Window(int width, int height, const char* title) {

		if (!glfwInitialized) {
			if (!glfwInit()) {
				RISE_CORE_ERROR("Failure to initialize GLFW");
				return;
			}
			glfwInitialized = true;


			//definition of the attributes for OpenGL context
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
			glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_FALSE);


			glfwSetErrorCallback(Window::ErrorCallback);
		}

		//Window creating
		
		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (!m_Window) {
			//TODO fix this shit
			RISE_CORE_ERROR("Failure on creating the window");
			return;
		}

		//turn this window on actual context
		glfwMakeContextCurrent(m_Window);

		GLenum glewErr = glewInit();
		if (glewErr != GLEW_OK) {
			RISE_CORE_ERROR("Failure to initialize GLEW!");
			RISE_CORE_ERROR("Error code {0}", glewErr);
			return;
		}

		const GLubyte* renderer = glGetString(GL_RENDERER);
		const GLubyte* version = glGetString(GL_VERSION);

		RISE_CORE_INFO("Renderer: {0}", renderer);
		RISE_CORE_INFO("OpenGL verion: {0}", version);
		
		
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}



	void Window::Update() {
		glfwMakeContextCurrent(m_Window);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
		glfwSwapBuffers(m_Window);

	}


	void Window::ErrorCallback(int err, const char* desc) {
		RISE_CORE_ERROR("Something went wrong with GLFW!");
		RISE_CORE_ERROR("Error code {0} description: {1}", err, desc);
	}
}