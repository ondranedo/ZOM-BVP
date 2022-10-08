#pragma once

#include "Window.h"

namespace ZOM {
	typedef void (*ZOMProc)(void);
	typedef ZOMProc(*ZOMProcFun)(const char* name);

	class ZOM_API RenderContext {
	public:
		virtual ~RenderContext() {};
		virtual void init(ZOMProcFun procFn) = 0;
		virtual void destroy() = 0;
		
		static RenderContext* createContext();
	};
}