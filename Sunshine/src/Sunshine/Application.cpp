#include "supch.h"
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
			SU_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SU_TRACE(e);
		}


		while (true);
	} 
}
