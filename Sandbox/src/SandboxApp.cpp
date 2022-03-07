#include <Sunshine.h>

class ExampleLayer :public Sunshine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SU_INFO("ExampleLayer::Update");
	}

	void OnEvent(Sunshine::Event& event) override
	{
		SU_TRACE("{0}", event);
	}
};







class Sandbox : public Sunshine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Sunshine::Application* Sunshine::CreateApplication()
{
	return new Sandbox();
}