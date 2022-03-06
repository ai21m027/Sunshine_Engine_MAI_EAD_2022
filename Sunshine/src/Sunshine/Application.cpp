#include "Application.h"

#include "Sunshine/Events/ApplicationEvent.h"
#include "Sunshine/Log.h"

namespace Sunshine {

	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if(e.IsInCategory(EventCategoryApplication))
		{
			SU_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SU_CORE_TRACE(e);
		}


		while (true);
	} 
}
