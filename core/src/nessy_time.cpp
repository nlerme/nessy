#include "nessy_time.h"


namespace Nessy
{
	Time::CLocalTimer::CLocalTimer()
	{
		Init();
	}

	void Time::CLocalTimer::Init()
	{
		#ifdef _WIN32
			QueryPerformanceFrequency(&m_TicksPerSecond);
			QueryPerformanceCounter(&m_AbsoluteTime);
		#else
			gettimeofday(&m_AbsoluteTime,NULL);
		#endif
	}

	double Time::CLocalTimer::GetTime() const
	{
		double ElapsedTime;

		#ifdef _WIN32
			LARGE_INTEGER NewTime;
			QueryPerformanceCounter(&NewTime);
			ElapsedTime = (double(NewTime.QuadPart) - double(m_AbsoluteTime.QuadPart)) / double(m_TicksPerSecond.QuadPart);
		#else
			timeval NewTime;
			gettimeofday(&NewTime,NULL);
			ElapsedTime = (NewTime.tv_usec - m_AbsoluteTime.tv_usec) / 1000000. + NewTime.tv_sec - m_AbsoluteTime.tv_sec;
		#endif

		return ElapsedTime;
	}
} //namespace Nessy
