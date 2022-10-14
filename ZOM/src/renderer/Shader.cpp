#include "Shader.h"

#include "renderingAPI/opengl/OpenGLShader.h"

namespace ZOM {
	std::shared_ptr<Shader> Shader::create()
	{
		switch (Renderer::getAPI())
		{
		case RenderingAPI::OPENGL:
			return std::shared_ptr<Shader>(new OpenGLShader);
		default:
			ZOM_ERROR("Unkown rendering API when creating vertex buffer");
		}

		return nullptr;
	}
}