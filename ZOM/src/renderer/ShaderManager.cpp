#include "ShaderManager.h"

namespace ZOM {
	
	void ShaderManager::setShaderPaths(const std::vector<std::string>& name_paths)
	{
		//  
		//  name_path = /assets/shaders/basic
		//  shader_path (per RenderingAPI) = /assets/shaders/basic.glsl
		//  							   = /assets/shaders/basic.hlsl
		//  
		
		ZOM_TRACE("Setting shader paths");

		for (const std::string& name_path : name_paths)
		{
			std::string shader_path = shaderPathFromNamePath(name_path);
			std::string shader_name = shaderNameFromNamePath(name_path);

			m_ShaderPaths[shader_name] = shader_path;
		}
	}

	size_t ShaderManager::compileAllShaders()
	{
		ZOM_TRACE("Creating shaders", m_Shaders.size());
		for (const std::pair<std::string, std::string>& shader_path : m_ShaderPaths)
		{
			m_Shaders[shader_path.first] = Shader::create(shader_path.second);
		}

		if(m_Shaders.size() == 1)
			ZOM_TRACE("Starting to compile {} shader", 1);
		else
			ZOM_TRACE("Starting to compile {} shaders", m_Shaders.size());

		for (const std::pair<std::string, std::shared_ptr<Shader>>& shader_entry : m_Shaders)
		{
			ZOM_TRACE("Compiling {} shader", shader_entry.first);
			if (!shader_entry.second->compile())
			{
				ZOM_ERROR("Compilation error!");
			}
		}

		return m_Shaders.size();
	}

	void ShaderManager::deleteAllShaders()
	{
		if (m_Shaders.size() == 1)
			ZOM_TRACE("deleteing 1 shader");
		else
			ZOM_TRACE("deleteing {} shaders", m_Shaders.size());

		for (const std::pair<std::string, std::shared_ptr<Shader>>& shader_entry : m_Shaders)
		{
			shader_entry.second->release();
		}
	}

	const std::shared_ptr<Shader>& ShaderManager::getShader(const std::string& name)
	{

		if (m_Shaders[name]) return  m_Shaders[name];
		
		ZOM_WARNING("Can't find {0} shader, setting {0} to default shader", name);
		m_Shaders[name] = Shader::createDefault();
		m_Shaders[name]->compile();
		return  m_Shaders[name];
	}

	std::string ShaderManager::shaderPathFromNamePath(const std::string& path)
	{
		std::string fileEnding =  Config::renderingAPIs(getStrRenderingApi(Renderer::getAPI())).shaderFile;
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return path + fileEnding;
		}

		ZOM_ERROR("Unknown rendering api when loading shaders");
		return "";
	}

	std::string ShaderManager::shaderNameFromNamePath(const std::string& name_path)
	{
		std::string ret_str;

		size_t lastPer = name_path.find_last_of("/");
		ret_str = name_path.substr(lastPer + 1);

		return ret_str;
	}

}