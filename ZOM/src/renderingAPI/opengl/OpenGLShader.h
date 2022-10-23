#pragma once

#include "renderer/Shader.h"

namespace ZOM {
	struct OpenGLSubShadersID {
		unsigned int m_VertexID;
		unsigned int m_FragmentID;
	};

	struct OpenGLSubShadersSources {
		std::string m_VertexSrc;
		std::string m_FragmentSrc;
	};

	class OpenGLShader : public Shader {
	public:
		OpenGLShader(const std::string& path);
		OpenGLShader();
		~OpenGLShader();

		void bind() const override;
		void unbind() const override;

		void release() override;

		bool compile() override;

		VertexBufferLayout getLayout() override;
		void setUniform(const std::string& name, void* data) override;

	private:
		unsigned int createShader(GLenum id, const std::string& source);
		OpenGLSubShadersID attatchShaders(const OpenGLSubShadersSources& vertex_source);
		bool compileShaders(const OpenGLSubShadersID& shader_ids);
		bool checkCompilation(unsigned int shader_id);
		void deleteShaders(const OpenGLSubShadersID& shader_ids);
		OpenGLSubShadersSources readShaderFile();

		void readAndAddVBL(char* buff, size_t size);
		int readLayoutLocation(char* buff, size_t size);
		InShaderDataType readLayoutType(char* buff, size_t size);

		void removeSpacesBefore(std::string& str);

		void createBufferLayout();
		std::string readLayoutName(char* buff, size_t size);

		void readAndAddUnifrom(char* linebuff, size_t buffSize);
		std::string readUniformName(char* linebuff, size_t buffSize);
		InShaderDataType readUniformType(char* linebuff, size_t buffSize);
		void mapUniforms();
		bool isUniformStored(const std::string& name);
		void sendToUniform(unsigned int id, InShaderDataType dt, void* data);
	private:
		std::string m_Path;
		bool m_Created = false;
		VertexBufferLayout m_Layout;
		std::vector<std::tuple<int,InShaderDataType,std::string>> m_LayoutVector;
		std::vector<std::tuple<InShaderDataType,std::string>> m_UnifromVector;
		std::unordered_map<std::string, std::tuple<InShaderDataType, unsigned int>> m_UnifromMap;
	};
};