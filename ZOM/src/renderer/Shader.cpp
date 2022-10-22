#include "Shader.h"

#include "renderingAPI/opengl/OpenGLShader.h"

namespace ZOM {
	std::shared_ptr<Shader> Shader::create(const std::string& path)
	{
		ZOM_FUNCTION_TIMER();

		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<Shader>(new OpenGLShader(path));
		default:
			ZOM_ERROR("Unkown rendering API when creating shader");
		}

		return nullptr;
	}

	std::shared_ptr<ZOM::Shader> Shader::createDefault()
	{
		ZOM_FUNCTION_TIMER();

		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<Shader>(new OpenGLShader);
		default:
			ZOM_ERROR("Unkown rendering API when creating shader");
		}

		return nullptr;
	}

}