#ifndef __NESSY_TYPES_H__
#define __NESSY_TYPES_H__

#define WANT_OBFUSCATING_OPERATORS
#include <cln/real.h>
#include <cln/integer.h>


namespace Nessy
{
	// Definition of basic data types
	typedef cln::cl_R Real;
	typedef cln::cl_I Integer;
} //namespace Nessy

#endif //__NESSY_TYPES_H__
