#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <iostream>

namespace ZOM {
	using logPtr = std::shared_ptr<spdlog::logger>;

	class ZOM_API Log {
	public:
		static bool init();
#ifndef ZOM_DISTRIBUTE
		inline static const logPtr& getCore() { return s_Core; }
#else
		inline static const logPtr& getCore()
		{
			return s_Client;
		}
#endif
		inline static const logPtr& getClient() { return s_Client; }

	private:
#ifndef ZOM_DISTRIBUTE
		static logPtr s_Core;
#endif
		static logPtr s_Client;
	};
}





































