#pragma once
#define GLEW_STATIC
#include <RisePCH.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Rise {

	inline bool glfwInitialized = false;

	class Window {
	public:
		Window(int width, int height, const char* title);

		~Window();

		void Update();

		GLFWwindow* get() const { return m_Window; }


	private:
		GLFWwindow* m_Window;

		static void ErrorCallback(int err, const char* desc);
	};
}
