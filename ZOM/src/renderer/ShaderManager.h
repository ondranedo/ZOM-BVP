#pragma once

namespace ZOM {
	class ShaderManager {
	public:
		void setShaderPaths(const std::vector<std::string>& shader_paths);
			
		size_t compileAllShaders();
		void deleteAllShaders();

		const std::shared_ptr<Shader>& getShader(const std::string& name);

	private:
		std::string shaderPathFromNamePath(const std::string& path);
		std::string shaderNameFromNamePath(const std::string& name_path);

	private:
		// TODO: Make it std::aray
		std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shaders;	// name -> shader ptr
		std::unordered_map<std::string, std::string> m_ShaderPaths;			// name -> path
	};
}