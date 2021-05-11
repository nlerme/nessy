#include "nessy_algebra.h"
#include "nessy_random.h"


namespace Nessy
{
	Integer Algebra::Factorial( const Integer Number )
	{
		if( Number < 0 )
			return 0;

		return cln::factorial(cln::cl_I_to_ulong(Number));
	}

	Integer Algebra::Binomial( const Integer K, const Integer N )
	{
		if( K < 0 || K > N )
			return 0;

		return cln::binomial(cln::cl_I_to_ulong(N), cln::cl_I_to_ulong(K));
	}

	Integer Algebra::Catalan( const Integer N )
	{
		if( N < 0 )
			return 0;

		return Divide(Binomial(N,2*N),N+1);
	}

	bool Algebra::IsAPowerOf2( const Integer Number )
	{
		return cln::power2p(Number) != 0 ? true : false;
	}

	Real Algebra::Exp( const Real Number )
	{
		return cln::exp(Number);
	}

	Real Algebra::Log( const Real Number, const Integer Base )
	{
		return cln::log(Number, Base);
	}

	Real Algebra::Power( const Real X, const Integer Y )
	{
		return cln::expt(X, Y);
	}

	Integer Algebra::Divide( const Integer X, const Integer Y )
	{
		return cln::truncate1(X, Y);
	}

	Integer Algebra::Modulo( const Integer X, const Integer Y )
	{
		return cln::rem(X, Y);
	}
} //namespace Nessy
