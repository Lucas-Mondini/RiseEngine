#include "RisePCH.h"
#include <Rise/Window.h>

#include <Rise/Event/ApplicationEvent.h>
#include <Rise/Event/InputEvent.h>



namespace Rise {
	Window::Window(int width, int height, const char* title) {

		this->m_Properties.width	= width;
		this->m_Properties.height	= height;
		this->m_Properties.title	= title;

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
		glfwSetWindowUserPointer(m_Window, &m_Properties);


		//glfw callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;

			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS: 
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);

			mouseScrollEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowProperties& data = *(WindowProperties*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);
		});




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