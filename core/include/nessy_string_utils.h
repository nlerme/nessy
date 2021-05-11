#ifndef __NESSY_STRING_UTILS_H__
#define __NESSY_STRING_UTILS_H__

#include <string>
#include <sstream>


namespace Nessy
{
	namespace StringUtils
	{
		template<typename T> static std::string ToString( const T & Value )
		{
			std::ostringstream Oss;
			Oss << Value;
			return Oss.str();
		}

		template<typename T> static bool FromString( const std::string & String, T & Destination )
		{
			std::istringstream Iss(String);
			return Iss >> Destination != 0;
		}
	} // namespace StringUtils
} // namespace Nessy

#endif //__NESSY_STRING_UTILS_H__
