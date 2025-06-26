#include "Platform/Windows/GlfwWindow.h"

#include "Meiro/Core/Log.h"
#include "Meiro/Events/ApplicationEvent.h"
#include "Meiro/Events/KeyEvent.h"
#include "Meiro/Events/MouseEvent.h"

namespace Meiro {
	static bool s_GLFWInitialized = false;

	static void GlfwErrorCallback(int error, const char *description) {
		MEIRO_CORE_CRITICAL("GLFW Error ({0}): {1}", error, description);
	}

	Window *Window::Create(const WindowProps &props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps &props) {
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

		if (!s_GLFWInitialized)
		{
			glfwSetErrorCallback(GlfwErrorCallback);
			int success = glfwInit();
			MEIRO_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.width, (int)props.height, std::data(props.title), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mData);
		EnableVSync(true);

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow *window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizedEvent e(width, height);
			data.eventCallback(e);
		});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow *window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent e;
			data.eventCallback(e);
		});

		glfwSetKeyCallback(mWindow, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS: {
				KeyPressedEvent e(key, 0);
				data.eventCallback(e);
			}
			break;

			case GLFW_RELEASE: {
				KeyReleasedEvent e(key);
				data.eventCallback(e);
			}
			break;

			case GLFW_REPEAT: {
				KeyPressedEvent e(key, 1);
				data.eventCallback(e);
			}
			break;
            }
		});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow *window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS: {
				MouseButtonPressedEvent e(button);
				data.eventCallback(e);
			}
			break;

			case GLFW_RELEASE: {
				MouseButtonReleasedEvent e(button);
				data.eventCallback(e);
			}
			break;
			}
		});

		glfwSetScrollCallback(mWindow, [](GLFWwindow *window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e(xOffset, yOffset);
			data.eventCallback(e);
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow *window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent e((f32)xPos, (f32)yPos);
			data.eventCallback(e);
		});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(mWindow);
	}
}
