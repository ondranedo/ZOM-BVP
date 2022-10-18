#include <stdexcept>

#include "Config.h"

#include <fstream>

namespace ZOM {
	
	void Config::init()
	{
		std::ifstream config_file("config.json", std::ifstream::binary);
		if (config_file)
		{
			config_file >> m_Config;
			ZOM_TRACE("Config file loaded");
			config_file.close();
		}
		else
		{
			ZOM_CRITICAL("Can't find config.json file!");
		}
		
		//std::stringstream ss;
		//
		//for (auto api : config["renderingAPIs"])
		//{
		//	if (api["name"] == "Metal")
		//	{
		//		ss << api["shaderFile"];
		//		ZOM_TRACE("Current shader file ending {} ", ss.str());
		//	}
		//}
		//
	}

	void Config::release()
	{

	}

	Json::Value Config::m_Config;

}