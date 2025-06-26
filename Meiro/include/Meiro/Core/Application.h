#pragma once

#include <memory>

namespace Meiro {
	class Window;
	class Event;
	class WindowCloseEvent;

	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		virtual void OnUpdate() = 0;

	protected:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> mWindow;
		bool mIsRunning = true;
	};

	Application* CreateApplication();
}
