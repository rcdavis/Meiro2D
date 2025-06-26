#pragma once

#include "Meiro/Core/Core.h"
#include "Meiro/Events/Event.h"

namespace Meiro {
	struct WindowProps {
		std::string title;
		uint32 width;
		uint32 height;

		WindowProps(const std::string &title = "Meiro Engine", uint32 width = 1280, uint32 height = 720)
			: title(title), width(width), height(height) {}
	};

	class Window {
	public:
		using EventCallbackFn = std::function<void(Event &)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint32 GetWidth() const = 0;
		virtual uint32 GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
		virtual void EnableVSync(const bool enabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		static Window *Create(const WindowProps &props = WindowProps());
	};
}
