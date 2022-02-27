#pragma once

#ifdef SU_PLATFORM_WINDOWS

extern Sunshine::Application* Sunshine::CreateApplication();

int main(int argc,char** argv)
{
	//printf("Sunshine Engine started\n");
	auto app = Sunshine::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Sunshine only supports Windows
#endif

