#pragma once

#include "Meiro/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Meiro {
	class WindowsWindow : public Window {
	private:
		struct WindowData {
			std::string title;
			uint32 width, height;
			bool vsync;
			EventCallbackFn eventCallback;
		};

	public:
		WindowsWindow(const WindowProps &props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		uint32 GetWidth() const override { return mData.width; }
		uint32 GetHeight() const override { return mData.height; }

		void SetEventCallback(const EventCallbackFn& callback) override { mData.eventCallback = callback; }
		void EnableVSync(const bool enable) override;
		bool IsVSyncEnabled() const override { return mData.vsync; }

	private:
		void Init(const WindowProps &props);
		void Shutdown();

	private:
		GLFWwindow* mWindow;
		WindowData mData;
	};
}
