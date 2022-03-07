#pragma once

#include "Core.h"
#include "Window.h"
#include "Sunshine/LayerStack.h"
#include "Sunshine/Events/Event.h"
#include "Sunshine/Events/ApplicationEvent.h"


namespace Sunshine {

	class SUNSHINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	//To be defined in client
	Application* CreateApplication();

}

