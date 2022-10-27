#include "Shader.h"

#include "renderingAPI/opengl/OpenGLShader.h"

namespace ZOM
{
	std::shared_ptr<Shader> Shader::create(const std::string& path)
	{
		ZOM_FUNCTION_TIMER();

		switch(Renderer::getAPI()) {
			case renderingAPI::opengl: return std::make_shared<OpenGLShader>(path);
			default:
				ZOM_ERROR("Unkown rendering API when creating shader");
		}

		return nullptr;
	}

	std::shared_ptr<Shader> Shader::createDefault()
	{
		ZOM_FUNCTION_TIMER();

		switch(Renderer::getAPI()) {
			case renderingAPI::opengl: return std::make_shared<OpenGLShader>();
			default:
				ZOM_ERROR("Unkown rendering API when creating shader");
		}

		return nullptr;
	}
}
