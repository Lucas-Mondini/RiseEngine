#pragma once
#include <Rise/Application.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
/***
* this header needs to be included on the game
*
*/

#ifndef RISE_PLATAFORM_UNKNOWN

extern Rise::Application* Rise::CreateApplication();

int main(int argc, char** argv) {

	Rise::Log::Init();

	RISE_CORE_INFO("Initialized Log");
	RISE_CORE_WARN("Creating application...");

	Rise::Application* app = Rise::CreateApplication();

	RISE_CORE_INFO("Application created sucessfully");


	app->Run();
	delete app;
	
}

#endif // SEG_PLATAFORM_WINDOWS
