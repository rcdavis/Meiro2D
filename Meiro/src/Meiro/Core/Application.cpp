#include "Meiro/Core/Application.h"

// TODO: Remove once done with testing
#include <GLFW/glfw3.h>

namespace Meiro {
	Application::Application() :
		mWindow(std::unique_ptr<Window>(Window::Create())) {}

	Application::~Application() {}

	void Application::Run() {
		while (mIsRunning) {
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
			OnUpdate();
		}
	}

	void Application::Close() {
		mIsRunning = false;
	}
}
