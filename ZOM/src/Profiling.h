#pragma once

namespace ZOM
{
	struct ZOM_API profileData {
		std::string m_Name      = "blank";
		std::string m_TimePoint = "us";
		size_t m_Start          = 0;
		size_t m_End            = 0;
	};

	class ZOM_API MeasureTime {
	public:
		MeasureTime(const std::string& name);
		~MeasureTime();

	private:
		std::chrono::time_point<std::chrono::steady_clock> m_Start;
		std::string m_Name;
	};

	class ZOM_API ChromeProfiling {
	public:
		static void init();
		static void release();

		static void profile(const profileData& data);

	private:
		static void header();
		static void footer();

		static std::string m_SPath;
		static std::ofstream m_SFile;
		static size_t m_SProfileCount;
	};
}
