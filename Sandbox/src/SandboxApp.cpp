#include "SandboxApp.h"

#include <iostream>

Meiro::Application* Meiro::CreateApplication() {
	return new SandboxApp();
}

void SandboxApp::OnUpdate() {
	std::cout << "Update Sandbox app" << std::endl;
}
