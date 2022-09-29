#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace ZOM {

	logPtr Log::s_Core;
	logPtr Log::s_Client;

	bool Log::init()
	{
		// Sets min log level
		spdlog::set_level(spdlog::level::trace);

		// Core console setup
		s_Core = spdlog::stdout_color_mt("core");
		s_Core->set_pattern("%^| %-8T:%-8f %-8n  %v%$");

		//Client side console setup
		s_Client = spdlog::stdout_color_mt("client");
		s_Client->set_pattern("%^> %-8T:%-8f %-8n  %v%$");

		return true; // Initialized successfully
	}
}