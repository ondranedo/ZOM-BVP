#include "spdlog/spdlog.h"

namespace ZOM
{
#ifndef ZOM_DISTRIBUTE
	logPtr Logger::m_SCore;
#endif
	logPtr Logger::m_SClient;

	void Logger::init()
	{
		// Core console setup
#ifndef ZOM_DISTRIBUTE
		m_SCore = spdlog::stdout_color_mt("core");
		m_SCore->set_pattern("%^| %-8T:%-8f %v%$");
#endif

		//Client side console setup
		m_SClient = spdlog::stdout_color_mt("client");
#ifndef ZOM_DISTRIBUTE
		m_SClient->set_pattern("%^> %-8T:%-8f %v%$");
#else

		// Console for distribution
		m_SClient->set_pattern("%^[%-8T]  %-8l %v%$");
#endif

#ifdef ZOM_DEBUG
		m_SCore->set_level(spdlog::level::trace);
		m_SClient->set_level(spdlog::level::trace);
#elif ZOM_RELEASE
		m_SCore->set_level(spdlog::level::warn);
		m_SClient->set_level(spdlog::level::trace);
#elif ZOM_DISTRIBUTE
		m_SClient->set_level(spdlog::level::trace);
#endif

		ZOM_TRACE("Logger initialized");
	}

	void Logger::release()
	{
		ZOM_TRACE("Logger released");
		m_SClient.reset();

#ifndef ZOM_DISTRIBUTE
		m_SCore.reset();
#endif
	}
}
