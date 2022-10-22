#pragma once

#include <json/json.h>

namespace ZOM {
	struct ZOM_API RenderingApiConfig {
		std::string name;
		std::vector<std::string> platforms;
		std::string shaderFile;
	};

	class ZOM_API Config
	{
	public:
		static void init();
		static void release();
	
		static bool logEvents();
		static std::string logEventPath();
		static RenderingAPI renderingAPI();
		static RenderingApiConfig renderingAPIs(const std::string& name);
		static std::vector<std::string> shaderPaths();
		static std::string profilePath();
		static bool profile();

	private:
		static Json::Value m_Config;
	};
}