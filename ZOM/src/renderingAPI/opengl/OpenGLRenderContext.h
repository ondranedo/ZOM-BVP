#pragma once

#include "renderer/RenderContext.h"

namespace ZOM {
	class OpengGLRenderContex : public RenderContext
	{
	public:
		OpengGLRenderContex();
		~OpengGLRenderContex();

		virtual void init(ZOMProcFun procAddres) override;
		virtual void destroy() override;
	};
}