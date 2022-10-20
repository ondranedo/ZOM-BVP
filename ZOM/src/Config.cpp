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
			ZOM_CLIENT_CRITICAL("Can't find config.json file!");
		}
	}

	void Config::release(){}

	bool Config::logEvents(){
		return m_Config["logEvents"].asBool();
	}

	std::string Config::logEventPath()
	{ 
		return m_Config["logEventPath"].asString();
	}

	ZOM::RenderingAPI Config::renderingAPI() {
		if (m_Config["renderingAPI"].asString() == "OpenGL") return RenderingAPI::OPENGL;

		return RenderingAPI::OPENGL;
	}

	ZOM::RenderingApiConfig Config::renderingAPIs(const std::string& name){
		RenderingApiConfig ret;
		for (const auto& li : m_Config["renderingAPIs"])
		{
			if (li["name"].asString() == getStrRenderingApi(Renderer::getAPI()))
			{
				ret.name = li["name"].asString();
				for (const auto& li2 : li["platforms"])
					ret.platforms.push_back(li2.asString());
				ret.shaderFile = li["shaderFile"].asString();

				break;
			}
		}
		if (ret.name == "")
			ZOM_ERROR("Can't find rendering api specification in config.json");
		return ret;
	}

	std::vector<std::string> Config::shaderPaths(){
		std::vector<std::string> ret;
		for (const auto& li2 : m_Config["shaderPaths"])
			ret.push_back(li2.asString());
		return ret;
	}


	Json::Value Config::m_Config;
}