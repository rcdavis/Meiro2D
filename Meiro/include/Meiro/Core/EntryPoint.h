#pragma once

#include "Meiro/Core/Application.h"

#include <memory>

int main(int argc, char** argv) {
	std::unique_ptr<Meiro::Application> app(Meiro::CreateApplication());
	app->Run();
	return 0;
}
