#include "SandboxApp.h"

#include <Meiro/Core/Log.h>
#include <Meiro/Events/MouseEvent.h>

Meiro::Application* Meiro::CreateApplication() {
	return new SandboxApp();
}

void SandboxApp::OnUpdate() {
	Meiro::MouseMovedEvent e(10.0f, 10.0f);
	if (e.IsInCategory(Meiro::Event::Category::Application)) {
		MEIRO_TRACE(e.ToString());
	}
	if (e.IsInCategory(Meiro::Event::Category::Input)) {
		MEIRO_TRACE(e.ToString());
	}
}
