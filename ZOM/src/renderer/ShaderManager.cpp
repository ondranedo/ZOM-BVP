#include "ShaderManager.h"

namespace ZOM {
	
	void ShaderManager::setShaderPaths(const std::vector<std::string>& shader_paths)
	{
		//  
		//  name_path = /assets/shaders/basic
		//  shader_path (per renderingAPI) = /assets/shaders/basic.glsl
		//  							   = /assets/shaders/basic.hlsl
		//  
		
		ZOM_TRACE("Setting shader paths");

		for (const std::string& name_path : shader_paths)
		{
			const std::string shader_path = shaderPathFromNamePath(name_path);
			std::string shader_name = shaderNameFromNamePath(name_path);

			m_ShaderPaths[shader_name] = shader_path;
		}
	}

	size_t ShaderManager::compileAllShader()
	{
		ZOM_FUNCTION_TIMER();

		ZOM_TRACE("Creating shaders", m_Shader.size());
		for (const auto&[name, path] : m_ShaderPaths)
		{
			m_Shader[name] = Shader::create(path);
		}

		if(m_Shader.size() == 1)
			ZOM_TRACE("Starting to compile {} shader", 1);
		else
			ZOM_TRACE("Starting to compile {} shaders", m_Shader.size());

		for (const auto& [name, shader]  : m_Shader)
		{
			ZOM_TRACE("Compiling {} shader", name);
			if (!shader->compile())
			{
				ZOM_ERROR("Compilation error!");
			}
		}
		for (const auto& [name, shader] : m_Shader)
		{
			ZOM_TRACE("Mapping uniforms of {} shader", name);
			shader->mapUniforms();
		}
			

		return m_Shader.size();
	}

	void ShaderManager::deleteAllShader()
	{
		if (m_Shader.size() == 1)
			ZOM_TRACE("deleteing 1 shader");
		else
			ZOM_TRACE("deleteing {} shaders", m_Shader.size());

		for (const auto&[name, shader] : m_Shader)
		{
			shader->release();
		}
	}

	const std::shared_ptr<Shader>& ShaderManager::getShader(const std::string& name)
	{

		if (m_Shader[name]) return  m_Shader[name];
		
		ZOM_WARNING("Can't find {0} shader, setting {0} to default shader", name);
		m_Shader[name] = Shader::createDefault();
		m_Shader[name]->compile();
		return  m_Shader[name];
	}

	std::string ShaderManager::shaderPathFromNamePath(const std::string& path)
	{
		const std::string file_ending =  Config::renderingAPIs(getStrRenderingApi(Renderer::getAPI())).m_ShaderFile;
		switch (Renderer::getAPI())
		{
		case renderingAPI::opengl:
			return path + file_ending;
		}

		ZOM_ERROR("Unknown rendering api when loading shaders");
		return "";
	}
		

	std::string ShaderManager::shaderNameFromNamePath(const std::string& name_path)
	{
		const size_t last_per = name_path.find_last_of('/');
		std::string ret_str = name_path.substr(last_per + 1);

		return ret_str;
	}

}