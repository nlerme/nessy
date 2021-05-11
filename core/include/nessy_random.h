#ifndef __NESSY_RANDOM_H__
#define __NESSY_RANDOM_H__

#include <ctime>
#include <cstdlib>
#include "nessy_types.h"
#include "nessy_singleton.h"


namespace Nessy
{
	namespace Random
	{
		template<typename T> class CRandom
		{
		     protected :
			CRandom()
			{
				srand(time(NULL));
			}

			virtual ~CRandom(){}

			// Generate a random number in [Min, Max[
			virtual T operator() ( const T Min, const T Max ) const = 0;
		};

		class CRandomReal : public CSingleton<CRandomReal>, CRandom<Real>
		{
		     private :
			friend class CSingleton<CRandomReal>;

			CRandomReal();
			virtual ~CRandomReal();


		     public :
			virtual Real operator() ( const Real Min, const Real Max ) const;
		};

		class CRandomInteger : public CSingleton<CRandomInteger>, CRandom<Integer>
		{
		     private :
			friend class CSingleton<CRandomInteger>;

			CRandomInteger();
			virtual ~CRandomInteger();


		     public :
			virtual Integer operator() ( const Integer Min, const Integer Max ) const;
		};
	} // namespace Random
} //namespace Nessy

#endif //__NESSY_RANDOM_H__
