#pragma once

#include <json/json.h>

namespace ZOM {
	class Config
	{
	public:
		static void init();
		static void release();

	private:
		static Json::Value m_Config;
	};
}