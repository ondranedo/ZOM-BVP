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
		pd.name = m_Name;
		pd.time_point = "ns";
		pd.start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_Start).time_since_epoch().count();
		pd.end = std::chrono::time_point_cast  <std::chrono::nanoseconds>(end).time_since_epoch().count();

		ChromeProfiling::profile(pd);
	}

	/// 
	/// ChromeProfiling
	/// 

	void ChromeProfiling::init()
	{
		m_Path = Config::profilePath();
		m_File.open(m_Path, std::ios::out);
		header();
	}

	void ChromeProfiling::release()
	{
		footer();
		m_File.close();
	}

	void ChromeProfiling::profile(const profileData& data)
	{
		if (profileCount++ > 0)
			m_File << ",";

		m_File << "{\n";
		m_File << "	    \"name\": \"" << data.name << "\",\n";
		m_File << "		\"cat\" : \"function\",\n";
		m_File << "		\"ph\"  : \"X\",\n";
		m_File << "		\"ts\"  : " << data.start << ",\n";
		m_File << "		\"dur\" : " << (data.end - data.start) << ",\n";
		m_File << "		\"pid\" : 0,\n";
		m_File << "		\"tid\" : 0,\n";
		m_File << "		\"args\": {}\n";
		m_File << "}\n";
		m_File.flush();
	}

	void ChromeProfiling::header()
	{
		m_File << "{\n";
		m_File << " \"traceEvents\": [\n";
		m_File.flush();
	}

	void ChromeProfiling::footer()
	{
		m_File << "],\n";
		m_File << " \"otherData\": {}\n}";
		m_File.flush();
	}

	std::string ChromeProfiling::m_Path;

	std::ofstream ChromeProfiling::m_File;

	size_t ChromeProfiling::profileCount = 0;

}