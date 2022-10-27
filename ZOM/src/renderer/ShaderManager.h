#pragma once

namespace ZOM {
	class ShaderManager {
	public:
		void setShaderPaths(const std::vector<std::string>& shader_paths);
			
		size_t compileAllShader();
		void deleteAllShader();

		const std::shared_ptr<Shader>& getShader(const std::string& name);

	private:
		std::string shaderPathFromNamePath(const std::string& path);
		std::string shaderNameFromNamePath(const std::string& name_path);

	private:
		// TODO: Make it std::array
		std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shader;	// m_Name -> shader ptr
		std::unordered_map<std::string, std::string> m_ShaderPaths;			// m_Name -> path
	};
}