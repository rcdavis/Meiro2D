#include "Platform/Windows/GlfwWindow.h"

#include "Meiro/Core/Log.h"

namespace Meiro {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::EnableVSync(const bool enable) {
		glfwSwapInterval(enable ? 1 : 0);
		mData.vsync = enable;
	}

	void WindowsWindow::Init(const WindowProps &props) {
		mData.title = props.title;
		mData.width = props.width;
		mData.height = props.height;

		MEIRO_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			MEIRO_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.width, (int)props.height, std::data(props.title), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mData);
		EnableVSync(true);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(mWindow);
	}
}
