#include "SandboxApp.h"

#include <Meiro/Core/Log.h>

Meiro::Application* Meiro::CreateApplication() {
	return new SandboxApp();
}

void SandboxApp::OnUpdate() {
	MEIRO_TRACE("Update Sandbox app");
}
