#pragma once

#include "Meiro/Core/Application.h"
#include "Meiro/Core/Log.h"

#include <memory>

int main(int argc, char** argv) {
	Meiro::Log::Init();
	std::unique_ptr<Meiro::Application> app(Meiro::CreateApplication());
	app->Run();
	return 0;
}
