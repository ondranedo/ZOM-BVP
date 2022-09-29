#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ZOM {
	class ZOM_API Logger {
	public:
	private:
		spdlog::stdout_color_mt s_CoreLogger;
	};

	
}