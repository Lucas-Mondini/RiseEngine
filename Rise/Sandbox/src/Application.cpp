#include <Rise.h>
#include <Rise/main.h>


class SandboxLayer : public Rise::Layer {
public:
	SandboxLayer(std::string name) :
		Layer(name){}

	void onUpdate() {
		//RISE_CLIENT_INFO("{0}Layer::update", getName());
	}
};


class Sandbox : public Rise::Application{
public:
	Sandbox() {
		PushLayer(new SandboxLayer("Sandbox"));
	}

	~Sandbox() {

	}
};

Rise::Application* Rise::CreateApplication() {
	return new Sandbox();
}
