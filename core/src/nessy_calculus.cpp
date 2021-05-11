#include <iostream>
#include <cln/integer_io.h>
#include "nessy_algebra.h"
#include "nessy_random.h"
#include "nessy_calculus.h"


namespace Nessy
{
	//-------------------------------- CInterval class ---------------------------------
	CCalculus::CInterval::CInterval( const Integer _Min, const Integer _Max ) : Min(_Min), Max(_Max){}

	//-------------------------------- CCalculus class ---------------------------------
	CNode * CCalculus::_RecursiveNthBinaryTree( const Integer Index )
	{
		if( Index == 1 )
			return new CNode;
		else
			return new CNode(_RecursiveNthBinaryTree(m_IndexMap[Index].Min), _RecursiveNthBinaryTree(m_IndexMap[Index].Max));
	}

	void CCalculus::_FillMaps( const Integer Index )
	{
		Integer I(1), J(0), K(0), L(0), M(2), LowerBound(0), UpperBound(0), NumberOfTrees(0), NumberOfNodes(0);
		bool Ok(true);
		CInterval Interval1, Interval2;


		while( LowerBound > Index || Index > UpperBound )
		{
			NumberOfTrees             = Algebra::Divide(Algebra::Binomial(I - 1, (I - 1) << 1), I);
			UpperBound               += NumberOfTrees;
			LowerBound                = UpperBound - NumberOfTrees + 1;
			NumberOfNodes             = (I << 1) - 1;
			m_NodeMap[NumberOfNodes]  = CInterval(LowerBound, UpperBound);

			for( J=(NumberOfNodes - 2); J>=0 && Ok; J-=2 )
			{
				Interval1 = m_NodeMap[J];
				Interval2 = m_NodeMap[NumberOfNodes - J - 1];

				for( K=Interval1.Min; K<=Interval1.Max && Ok; K++ )
				{
					for( L=Interval2.Min; L<=Interval2.Max && Ok; L++ )
					{
						if( M == Index )
							Ok = false;

						m_IndexMap[M] = CInterval(K, L);
						M++;
					}
				}
			}

			I++;
		}
	}

	CCalculus::CCalculus(){}

	CCalculus::~CCalculus(){}

	CNode * CCalculus::NthBinaryTree( const Integer Index )
	{
		if( Index <= 0 )
			return NULL;

		if( Index > m_IndexMap.size() + 1 )
			_FillMaps(Index);

		return _RecursiveNthBinaryTree(Index);
	}

	CNode * CCalculus::RandomBinaryTree( const Integer NumberOfNodes )
	{
		if( NumberOfNodes <= 0 || Algebra::Modulo(NumberOfNodes, 2) == 0 )
			return NULL;

		Integer I(1), LowerBound(0), UpperBound(0), NumberOfTrees(0), SliceIndex((NumberOfNodes + 1) >> 1);
		Random::CRandomInteger * RI = Random::CRandomInteger::Instance();

		while( I <= SliceIndex )
		{
			NumberOfTrees  = Algebra::Divide(Algebra::Binomial(I - 1, (I - 1) << 1), I);
			UpperBound    += NumberOfTrees;
			I++;
		}

		LowerBound = UpperBound - NumberOfTrees + 1;

		return NthBinaryTree((*RI)(LowerBound, UpperBound + 1));
	}
} //namespace Nessy
