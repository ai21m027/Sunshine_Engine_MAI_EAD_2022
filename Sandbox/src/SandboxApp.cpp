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
		//SU_INFO("ExampleLayer::Update");

		if (Sunshine::Input::isKeyPressed(SU_KEY_TAB))
			SU_TRACE("TAB Key is pressed.");
	}

	void OnEvent(Sunshine::Event& event) override
	{
		//SU_TRACE("{0}", event);
		if (event.GetEventType() == Sunshine::EventType::KeyPressed)
		{
			Sunshine::KeyPressedEvent& e = (Sunshine::KeyPressedEvent&)event;
			SU_TRACE("{0}",(char)e.GetKeyCode());
		}
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