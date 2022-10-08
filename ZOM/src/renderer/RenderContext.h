#pragma once

#include "Window.h"

namespace ZOM {
	class ZOM_API RenderContext {
	public:
		virtual ~RenderContext() {};
		virtual void init() = 0;
		virtual void swap() = 0;
		virtual void destroy() = 0;
		
		static RenderContext* createContext(Window* window);
	};
}