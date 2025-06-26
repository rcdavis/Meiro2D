#pragma once

namespace Meiro {
	class Application {
	public:
		virtual ~Application();

		void Run();
		void Close();

		virtual void OnUpdate() = 0;

	private:
		bool mIsRunning = true;
	};

	Application* CreateApplication();
}
