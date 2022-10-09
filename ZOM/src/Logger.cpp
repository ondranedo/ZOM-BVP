
#include "spdlog/spdlog.h"

namespace ZOM {

#ifndef ZOM_DISTRIBUTE
	logPtr Logger::s_Core;
#endif
	logPtr Logger::s_Client;

	void Logger::init()
	{
		// Core console setup
#ifndef ZOM_DISTRIBUTE
		s_Core = spdlog::stdout_color_mt("core");
		s_Core->set_pattern("%^| %-8T:%-8f %v%$");
#endif

		//Client side console setup
		s_Client = spdlog::stdout_color_mt("client");
#ifndef ZOM_DISTRIBUTE
		s_Client->set_pattern("%^> %-8T:%-8f %v%$");
#else

		// Console for distribution
		s_Client->set_pattern("%^[%-8T]  %-8l %v%$");
#endif

#ifdef ZOM_DEBUG
		s_Core->set_level(spdlog::level::trace);
		s_Client->set_level(spdlog::level::trace);
#elif ZOM_RELEASE
		s_Core->set_level(spdlog::level::warn);
		s_Client->set_level(spdlog::level::trace);
#elif ZOM_DISTRIBUTE
		s_Client->set_level(spdlog::level::trace);
#endif

		ZOM_TRACE("Logger initialized");
	}

	void Logger::release()
	{
		ZOM_TRACE("Logger released");
		s_Client.reset();

#ifndef ZOM_DISTRIBUTE
		s_Core.reset();
#endif
	}
}