#pragma once

#include "Meiro/Events/Event.h"

#include <sstream>

namespace Meiro {
	class MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(f32 x, f32 y) : mMouseX(x), mMouseY(y) {}

		f32 GetX() const { return mMouseX; }
		f32 GetY() const { return mMouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(Event::Category::Mouse | Event::Category::Input)

	private:
		f32 mMouseX, mMouseY;
	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(f32 offsetX, f32 offsetY) : mOffsetX(offsetX), mOffsetY(offsetY) {}

		f32 GetOffsetX() const { return mOffsetX; }
		f32 GetOffsetY() const { return mOffsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << mOffsetX << ", " << mOffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(Event::Category::Mouse | Event::Category::Input)

	private:
		f32 mOffsetX, mOffsetY;
	};

	class MouseButtonEvent : public Event {
	public:
		int32 GetMouseButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(Event::Category::Mouse | Event::Category::Input)

	protected:
		MouseButtonEvent(int32 button) : mButton(button) {}

		int32 mButton;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int32 button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int32 button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
