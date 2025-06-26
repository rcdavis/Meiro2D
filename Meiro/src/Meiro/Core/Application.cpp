#include "Meiro/Core/Application.h"

#include "Meiro/Core/Log.h"
#include "Meiro/Core/Window.h"
#include "Meiro/Events/ApplicationEvent.h"

// TODO: Remove once done with testing
#include <GLFW/glfw3.h>

namespace Meiro {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() :
		mWindow(std::unique_ptr<Window>(Window::Create()))
	{
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {}

	void Application::Run() {
		while (mIsRunning) {
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
			OnUpdate();
		}
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		MEIRO_CORE_TRACE(e.ToString());
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		mIsRunning = false;
		return true;
	}
}
