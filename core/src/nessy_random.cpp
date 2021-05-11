#include <cstdlib>
#include "nessy_random.h"


namespace Nessy
{
	//------------------------------- CRandomReal class --------------------------------

	Random::CRandomReal::CRandomReal(){}

	Random::CRandomReal::~CRandomReal(){}

	Real Random::CRandomReal::operator() ( const Real Min, const Real Max ) const
	{
		return Min + cln::random_R(Max - Min);
	}


	//-------------------------------- CRandomInt class --------------------------------

	Random::CRandomInteger::CRandomInteger(){}

	Random::CRandomInteger::~CRandomInteger(){}

	Integer Random::CRandomInteger::operator() ( const Integer Min, const Integer Max ) const
	{
		return Min + cln::random_I(Max - Min);
	}
} //namespace Nessy
