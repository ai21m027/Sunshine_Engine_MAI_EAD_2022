#pragma once

#include "Core.h"
#include "Window.h"
#include "Sunshine/LayerStack.h"
#include "Sunshine/Events/Event.h"
#include "Sunshine/Events/ApplicationEvent.h"
#include "Sunshine/ImGui/ImGuiLayer.h"


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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; };
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
	
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};


	//To be defined in client
	Application* CreateApplication();

}

