#pragma once

#include "Meiro/Core/Core.h"

#include <string>
#include <functional>

namespace Meiro {
#define EXPAND_EVENT_TYPE(x) Event::Type::x
#define EVENT_CLASS_TYPE(type) \
	static Event::Type GetStaticType() { return EXPAND_EVENT_TYPE(type); } \
	Event::Type GetEventType() const override { return GetStaticType(); } \
	const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return (category); }

	class Event {
		friend class EventDispatcher;
	public:
		enum class Type {
			None,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			AppTick, AppUpdate, AppRender,
			KeyPressed, KeyReleased,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		enum Category {
			None,
			Application = BIT(0),
			Input = BIT(1),
			Keyboard = BIT(2),
			Mouse = BIT(3),
			MouseButton = BIT(4)
		};

	public:
		virtual Type GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		inline bool IsInCategory(Category category) const { return GetCategoryFlags() & category; }

	protected:
		bool mHandled = false;
	};

	class EventDispatcher {
		template <typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e) : mEvent(e) {}

		template <typename T>
		bool Dispatch(EventFn<T> func) {
			if (mEvent.GetEventType() == T::GetStaticType()) {
				mEvent.mHandled = func(*(T*)&mEvent);
				return true;
			}
			return false;
		}

	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
