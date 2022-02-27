#include <Sunshine.h>

class Sandbox : public Sunshine::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Sunshine::Application* Sunshine::CreateApplication()
{
	return new Sandbox();
}