#ifndef __NESSY_TIME_H__
#define __NESSY_TIME_H__

#include <cstdlib>
#ifndef _WIN32
#	include <sys/time.h>
#else
#	include <windows.h>
#endif
#include "nessy_types.h"


namespace Nessy
{
	namespace Time
	{
		class CLocalTimer
		{
		     private :
			#ifndef _WIN32
				timeval m_AbsoluteTime;
			#else
				LARGE_INTEGER m_AbsoluteTime, m_TicksPerSecond;
			#endif


		     public :
			CLocalTimer();
			void Init();
			double GetTime() const;
		};
	} // namespace Time
} //namespace Nessy

#endif //__NESSY_TIME_H__
