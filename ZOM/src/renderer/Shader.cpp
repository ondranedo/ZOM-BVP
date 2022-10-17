#include "Shader.h"

#include "renderingAPI/opengl/OpenGLShader.h"

namespace ZOM {
	std::shared_ptr<Shader> Shader::create(const std::string& path)
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<Shader>(new OpenGLShader(path));
		default:
			ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}