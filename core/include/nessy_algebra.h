#ifndef __NESSY_ALGEBRA_H__
#define __NESSY_ALGEBRA_H__

#include <cmath>
#include <limits>
#include "nessy_types.h"


namespace Nessy
{
	namespace Algebra
	{
		//------------------------------- Non-template -------------------------------
		Integer Factorial( const Integer Number );
		Integer Binomial( const Integer K, const Integer N );
		Integer Catalan( const Integer N );
		bool IsAPowerOf2( const Integer Number );
		Real Exp( const Real Number );
		Real Log( const Real Number, const Integer Base );
		Real Power( const Real X, const Integer Y );
		Integer Divide( const Integer X, const Integer Y );
		Integer Modulo( const Integer X, const Integer Y );

		//--------------------------------- Template ---------------------------------
		template<typename T> T Min( const T A, const T B )
		{
			return A < B ? A : B;
		}

		template<typename T> T Min3( const T A, const T B, const T C )
		{
			return Min(Min(A, B), Min(B, C));
		}

		template<typename T> T Max( const T A, const T B )
		{
			return A > B ? A : B;
		}

		template<typename T> T Max3( const T A, const T B, const T C )
		{
			return Max(Max(A, B), Max(B, C));
		}

		template<typename T> void Swap( const T A, const T B )
		{
			T C(A);
			A = B;
			B = C;
		}
	} // namespace Algebra
} //namespace Nessy

#endif //__NESSY_ALGEBRA_H__
