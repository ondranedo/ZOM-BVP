#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <iostream>

namespace ZOM
{
	using logPtr = std::shared_ptr<spdlog::logger>;

	class ZOM_API Logger {
	public:
		static void init();
		static void release();

#ifndef ZOM_DISTRIBUTE
		inline static const logPtr& getCore() { return m_SCore; }
#else
		static const logPtr& getCore()
		{
			return m_SClient;
		}
#endif
		static const logPtr& getClient() { return m_SClient; }

	private:
#ifndef ZOM_DISTRIBUTE
		static logPtr m_SCore;
#endif
		static logPtr m_SClient;
	};
}
