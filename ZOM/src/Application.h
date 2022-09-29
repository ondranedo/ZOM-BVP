#pragma once

namespace ZOM {
	class ZOM_API ZOMGameEngine {
	public:
		ZOMGameEngine();
		virtual ~ZOMGameEngine();


		
		void run();
		void close();

	private:
		bool m_Running;
	};
}