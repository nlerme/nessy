#ifndef __NESSY_CALCULUS_H__
#define __NESSY_CALCULUS_H__

#include <map>
#include "nessy_types.h"
#include "nessy_node.h"


namespace Nessy
{
	class CCalculus
	{
	     private :
		class CInterval
		{
		     public :
			Integer Min, Max;
			CInterval( const Integer _Min = 0, const Integer _Max = 0 );
		};

		std::map<const Integer, CInterval> m_IndexMap;
		std::map<const Integer, CInterval> m_NodeMap;
		CNode * _RecursiveNthBinaryTree( const Integer Index );
		void _FillMaps( const Integer Index );


	     public :

		CCalculus();
		~CCalculus();
		CNode * NthBinaryTree( const Integer Index );
		CNode * RandomBinaryTree( const Integer NumberOfNodes );
	};
} // namespace Nessy

#endif //__NESSY_CALCULUS_H__
