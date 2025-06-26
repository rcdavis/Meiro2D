#pragma once

#include "Meiro/Core/Window.h"

#include <memory>

namespace Meiro {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void Close();

		virtual void OnUpdate() = 0;

	private:
		std::unique_ptr<Window> mWindow;
		bool mIsRunning = true;
	};

	Application* CreateApplication();
}
