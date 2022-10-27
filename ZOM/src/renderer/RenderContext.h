#pragma once

namespace ZOM
{
	class ZOM_API RenderContext {
	public:
		virtual ~RenderContext() {};
		virtual void init(void* window_pointer) = 0;
		virtual void swap() const = 0;
		virtual void destroy() = 0;
	};
}
