#include "Profiling.h"

#include <fstream>

namespace ZOM {

	MeasureTime::MeasureTime(const std::string& name) : m_Name(name)
	{
		m_Start = std::chrono::steady_clock::now();
	}

	MeasureTime::~MeasureTime()
	{
		auto end = std::chrono::steady_clock::now();

		profileData pd;
		pd.m_Name = m_Name;
		pd.m_TimePoint = "ns";
		pd.m_Start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_Start).time_since_epoch().count();
		pd.m_End = std::chrono::time_point_cast  <std::chrono::nanoseconds>(end).time_since_epoch().count();

		ChromeProfiling::profile(pd);
	}

	/// 
	/// ChromeProfiling
	/// 

	void ChromeProfiling::init()
	{
		m_SPath = Config::profilePath();
		if (Config::profile())
		{
			m_SFile.open(m_SPath, std::ios::out);
			header();
		}
	}

	void ChromeProfiling::release()
	{
		if (m_SFile.is_open())
		{
			footer();
			m_SFile.close();
		}
	}

	void ChromeProfiling::profile(const profileData& data)
	{
		if (m_SFile.is_open()) {
			if (m_SProfileCount++ > 0)
				m_SFile << ",";

			m_SFile << "{\n";
			m_SFile << "	    \"m_Name\": \"" << data.m_Name << "\",\n";
			m_SFile << "		\"cat\" : \"function\",\n";
			m_SFile << "		\"ph\"  : \"X\",\n";
			m_SFile << "		\"ts\"  : " << data.m_Start << ",\n";
			m_SFile << "		\"dur\" : " << (data.m_End - data.m_Start) << ",\n";
			m_SFile << "		\"pid\" : 0,\n";
			m_SFile << "		\"tid\" : 0,\n";
			m_SFile << "		\"args\": {}\n";
			m_SFile << "}\n";
			m_SFile.flush();
		}
	}

	void ChromeProfiling::header()
	{
		m_SFile << "{\n";
		m_SFile << " \"traceEvents\": [\n";
		m_SFile.flush();
	}

	void ChromeProfiling::footer()
	{
		m_SFile << "],\n";
		m_SFile << " \"otherData\": {}\n}";
		m_SFile.flush();
	}

	std::string ChromeProfiling::m_SPath;

	std::ofstream ChromeProfiling::m_SFile;

	size_t ChromeProfiling::m_SProfileCount = 0;

}