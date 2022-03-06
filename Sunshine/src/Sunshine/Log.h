#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Sunshine
{
	class SUNSHINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Makros for Core Logger
#define SU_CORE_ERROR(...)   ::Sunshine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SU_CORE_WARN(...)    ::Sunshine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SU_CORE_INFO(...)    ::Sunshine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SU_CORE_TRACE(...)   ::Sunshine::Log::GetCoreLogger()->trace(__VA_ARGS__)

//fatal does not exist
//#define SU_CORE_FATAL(...)   ::Sunshine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Makros for Client Logger
#define SU_ERROR(...)        ::Sunshine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SU_WARN(...)         ::Sunshine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SU_INFO(...)         ::Sunshine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SU_TRACE(...)        ::Sunshine::Log::GetClientLogger()->trace(__VA_ARGS__)

//fatal does not exist
//#define SU_FATAL(...)        ::Sunshine::Log::GetClientLogger()->fatal(__VA_ARGS__)