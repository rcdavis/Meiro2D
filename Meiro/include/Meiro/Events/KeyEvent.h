#pragma once

#include "Meiro/Events/Event.h"

#include <sstream>

namespace Meiro {
	class KeyEvent : public Event {
	public:
		int32 GetKeyCode() const { return mKeycode; }

		EVENT_CLASS_CATEGORY(Event::Category::Keyboard | Event::Category::Input)

	protected:
		KeyEvent(int32 keycode) : mKeycode(keycode) {}

		int32 mKeycode;
	};

	class KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int32 keycode, int32 repeatCount) : KeyEvent(keycode), mRepeatCount(repeatCount) {}

		int32 GetRepeatCount() const { return mRepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeycode << " (" << mRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int32 mRepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int32 keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
