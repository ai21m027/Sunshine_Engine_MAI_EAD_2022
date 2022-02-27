#pragma once

#ifdef SU_PLATFORM_WINDOWS

// Application created in new Project/Game (see extern)
extern Sunshine::Application* Sunshine::CreateApplication();

int main(int argc,char** argv)
{
	Sunshine::Log::Init();
	SU_CORE_INFO("Initialized the Core Logger");
	SU_INFO("Initialized the Client Logger");

	//printf("Sunshine Engine started\n");
	auto app = Sunshine::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Sunshine only supports Windows
#endif

