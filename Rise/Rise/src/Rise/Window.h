#pragma once
#define GLEW_STATIC
#include <RisePCH.h>

#include <Rise/Event/Event.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Rise {

	inline bool glfwInitialized = false;

	class Window {
	public:
		using eventCallbackFn = std::function<void(Event&)>;

		Window(int width, int height, const char* title);
		~Window();

		int getWidth() const { return m_Properties.width; }
		int getHeight() const { return m_Properties.height; }
		std::string getTitle() const { return m_Properties.title; }

		void Update();

		GLFWwindow* get() const { return m_Window; }

		void setEventCallback(const eventCallbackFn& callback) { this->m_Properties.eventCallback = callback; }


	private:
		GLFWwindow* m_Window;

		struct WindowProperties {
			eventCallbackFn eventCallback;

			int width;
			int height;
			std::string title;
		};

		WindowProperties m_Properties;

		static void ErrorCallback(int err, const char* desc);
	};
}
