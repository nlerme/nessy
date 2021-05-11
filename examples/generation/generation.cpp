#include <iostream>
#include <cln/integer_io.h>
#include "nessy.h"


int main( const int Argc, char ** Argv )
{
	Nessy::Time::CLocalTimer Timer;
	Nessy::CScreenLogger * Logger(Nessy::CScreenLogger::Instance());
	Nessy::CCalculus Calculus;
	Nessy::CBinaryTree BT;
	Nessy::Integer NumberOfNodes;
	double Time;


	// We get values of arguments
	if( Argc != 2 )
	{
		Logger->Write("Usage: "+Nessy::StringUtils::ToString(Argv[0])+" number-of-nodes\n\n");
		Logger->Write("number-of-nodes: odd positive integer\n");
		return EXIT_FAILURE;
	}

	NumberOfNodes = atoi(Argv[1]);

	if( NumberOfNodes<=0 || Nessy::Algebra::Modulo(NumberOfNodes, 2) == 0 )
	{
		Logger->Write("Error: the number of nodes must be an odd integer\n");
		return EXIT_FAILURE;
	}

	std::cout << NumberOfNodes << '\n';

	// We print the generated tree
	Logger->Write("[ Random generation of perfect binary trees ]\n");
	Logger->Write("---------------------------------------------\n\n");

	Timer.Init();
	BT.SetRootNode(Calculus.RandomBinaryTree(NumberOfNodes));
	Time = Timer.GetTime();

	Logger->Write("Representation  -> " + BT.ToString("(", ",", ")") + "\n");
	Logger->Write("Number of nodes -> " + Nessy::StringUtils::ToString(BT.CountNodes()) + "\n");
	Logger->Write("Running time    -> " + Nessy::StringUtils::ToString(Time) + "\n");

	return EXIT_SUCCESS;
}
