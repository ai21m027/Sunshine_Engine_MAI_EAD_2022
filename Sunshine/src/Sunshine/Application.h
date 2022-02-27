#pragma once
#include "Core.h"

namespace Sunshine {

	class SUNSHINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	//To be defined in client
	Application* CreateApplication();

}

