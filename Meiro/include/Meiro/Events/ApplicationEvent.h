#pragma once

#include "Meiro/Events/Event.h"

#include <sstream>

namespace Meiro {
	class WindowResizedEvent : public Event {
	public:
		WindowResizedEvent(uint32 width, uint32 height) :
			mWidth(width), mHeight(height) {}

		uint32 GetWidth() const { return mWidth; }
		uint32 GetHeight() const { return mHeight; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizedEvent: " << mWidth << ", " << mHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(Event::Category::Application)

	private:
		uint32 mWidth, mHeight;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(Event::Category::Application)
	};

	class AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(Event::Category::Application)
	};

	class AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(Event::Category::Application)
	};

	class AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(Event::Category::Application)
	};
}
