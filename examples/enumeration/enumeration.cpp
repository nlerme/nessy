#include <iostream>
#include <cln/integer_io.h>
#include "nessy.h"


int main( const int Argc, char ** Argv )
{
	Nessy::Time::CLocalTimer Timer;
	Nessy::CScreenLogger * Logger(Nessy::CScreenLogger::Instance());
	Nessy::CCalculus Calculus;
	Nessy::CBinaryTree BT;
	Nessy::Integer MaxTreeHeight, Index(1);
	double Time;


	// We get values of arguments
	if( Argc != 2 )
	{
		Logger->Write("Usage: "+Nessy::StringUtils::ToString(Argv[0])+" max-tree-height\n\n");
		Logger->Write("index-of-tree: non-negative integer\n");
		return EXIT_FAILURE;
	}

	MaxTreeHeight = atoi(Argv[1]);

	if( MaxTreeHeight<0 )
	{
		Logger->Write("Error: the tree index must be positive integer\n");
		return EXIT_FAILURE;
	}

	// We enumerate the generated tree
	Logger->Write("[ Enumeration of perfect binary trees ]\n");
	Logger->Write("---------------------------------------\n");

	Timer.Init();

	for( Nessy::Integer N=0; N<MaxTreeHeight; N++ )
	{
		Logger->Write("\n[ Trees with height="+Nessy::StringUtils::ToString(N)+" ]\n");

		for( Nessy::Integer K=0; K<Nessy::Algebra::Catalan(N); K++ )
		{
			BT.SetRootNode(Calculus.NthBinaryTree(Index));
			Logger->Write("  * Tree -> "+BT.ToString("(", ",", ")")+" ("+Nessy::StringUtils::ToString(BT.CountNodes())+" nodes)\n");
			Index++;
		}
	}
	
	Time = Timer.GetTime();
	Logger->Write("\n---------------------------------------\n");
	Logger->Write("Overall running time -> " + Nessy::StringUtils::ToString(Time) + " secs\n");

	return EXIT_SUCCESS;
}
