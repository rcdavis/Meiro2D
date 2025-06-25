#include "Meiro/Core/Application.h"

namespace Meiro {
	Application::~Application() {}

	void Application::Run() {
		while (mIsRunning) {
			OnUpdate();
		}
	}

	void Application::Close() {
		mIsRunning = false;
	}
}
