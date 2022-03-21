#pragma once

#include "Sunshine/Layer.h"
#include "Sunshine/Events/KeyEvent.h"
#include "Sunshine/Events/MouseEvent.h"
#include "Sunshine/Events/ApplicationEvent.h"

namespace Sunshine {

	class SUNSHINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnImGuiRender() override;
		
		
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}