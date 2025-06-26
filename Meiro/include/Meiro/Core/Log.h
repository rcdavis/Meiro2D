#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace Meiro {
	class Log {
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#if MEIRO_LOGGING_ENABLED
#	define MEIRO_CORE_TRACE(...)    Meiro::Log::GetCoreLogger()->trace(__VA_ARGS__);
#	define MEIRO_CORE_INFO(...)     Meiro::Log::GetCoreLogger()->info(__VA_ARGS__);
#	define MEIRO_CORE_WARN(...)     Meiro::Log::GetCoreLogger()->warn(__VA_ARGS__);
#	define MEIRO_CORE_ERROR(...)    Meiro::Log::GetCoreLogger()->error(__VA_ARGS__);
#	define MEIRO_CORE_CRITICAL(...) Meiro::Log::GetCoreLogger()->critical(__VA_ARGS__);

#	define MEIRO_TRACE(...)    Meiro::Log::GetClientLogger()->trace(__VA_ARGS__);
#	define MEIRO_INFO(...)     Meiro::Log::GetClientLogger()->info(__VA_ARGS__);
#	define MEIRO_WARN(...)     Meiro::Log::GetClientLogger()->warn(__VA_ARGS__);
#	define MEIRO_ERROR(...)    Meiro::Log::GetClientLogger()->error(__VA_ARGS__);
#	define MEIRO_CRITICAL(...) Meiro::Log::GetClientLogger()->critical(__VA_ARGS__);
#else
#	define MEIRO_CORE_TRACE(...)    ;
#	define MEIRO_CORE_INFO(...)     ;
#	define MEIRO_CORE_WARN(...)     ;
#	define MEIRO_CORE_ERROR(...)    ;
#	define MEIRO_CORE_CRITICAL(...) ;

#	define MEIRO_TRACE(...)    ;
#	define MEIRO_INFO(...)     ;
#	define MEIRO_WARN(...)     ;
#	define MEIRO_ERROR(...)    ;
#	define MEIRO_CRITICAL(...) ;
#endif
