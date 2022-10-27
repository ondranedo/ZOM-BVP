#pragma once

#include "renderer/Shader.h"

namespace ZOM
{
	struct openGLSubShaderID {
		unsigned int m_VertexID;
		unsigned int m_FragmentID;
	};

	struct openGLSubShaderSources {
		std::string m_VertexSrc;
		std::string m_FragmentSrc;
	};

	class OpenGLShader : public Shader {
	public:
		OpenGLShader(const std::string& path);
		OpenGLShader();
		virtual ~OpenGLShader();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void release() override;

		virtual bool compile() override;

		virtual VertexBufferLayout getLayout() override;
		virtual void setUniform(const std::string& name, void* data) override;
		virtual void checkIfUniformAreSet() const override;
		virtual void mapUniforms() override;

	private:
		unsigned int createShader(GLenum id, const std::string& source);
		openGLSubShaderID attachShader(const openGLSubShaderSources& sources);
		bool compileShader(const openGLSubShaderID& shader_ids);
		bool checkCompilation(unsigned int shader_id);
		void deleteShader(const openGLSubShaderID& shader_ids);
		openGLSubShaderSources readShaderFile();

		void readAndAddVbl(char* buff, size_t size);
		int readLayoutLocation(const char* buff, size_t size) const;
		InShaderDataType readLayoutType(const char* buff, size_t size);

		void removeSpacesBefore(std::string& str);

		void createBufferLayout();
		std::string readLayoutName(const char* buff, size_t size);

		void readAndAddUniform(const char* line_buffer, size_t buffer_size);
		std::string readUniformName(const char* line_buffer, size_t buffer_size);
		InShaderDataType readUniformType(const char* line_buffer, size_t buffer_size);
		bool isUniformStored(const std::string& name);
		void sendToUniform(unsigned int id, InShaderDataType dt, void* data);


	private:
		std::string m_Path;
		bool m_Created = false;
		VertexBufferLayout m_Layout;
		std::vector<std::tuple<int, InShaderDataType, std::string>> m_LayoutVector;
		std::vector<std::tuple<InShaderDataType, std::string>> m_UniformVector;
		std::unordered_map<std::string, std::tuple<InShaderDataType, int>> m_UniformMap;
		std::unordered_map<std::string, bool> m_UniformSets;
	};
};
