#include <queue>
#include <iostream>
#include "nessy_binary_tree.h"
#include "nessy_algebra.h"


namespace Nessy
{
	void CBinaryTree::_GenerateLeftComb( const Integer Height )
	{
		CNode * Node(m_pRootNode);

		for( Integer I=1; I<Height; I++ )
		{
			Node->SetLeftNode(new CNode);
			Node->SetRightNode(new CNode);
			Node = Node->GetLeftNode();
		}
	}

	void CBinaryTree::_GenerateRightComb( const Integer Height )
	{
		CNode * Node(m_pRootNode);

		for( Integer I=1; I<Height; I++ )
		{
			Node->SetLeftNode(new CNode);
			Node->SetRightNode(new CNode);
			Node = Node->GetRightNode();
		}
	}

	void CBinaryTree::_GeneratePerfectBinaryTree( const Integer Height )
	{
		std::queue<CNode *> Queue;
		Integer I(1);
		CNode * Node;

		Queue.push(m_pRootNode);

		while( !Queue.empty() )
		{
			Node = Queue.front();
			Queue.pop();
			Node->SetLeftNode(new CNode);
			Node->SetRightNode(new CNode);

			if( I < Algebra::Power(2, Height - 2) )
			{
				Queue.push(Node->GetLeftNode());
				Queue.push(Node->GetRightNode());
				I++;
			}
		}
	}

	CBinaryTree::CBinaryTree( CNode * RootNode ) : m_pRootNode(RootNode){}

	CBinaryTree::CBinaryTree( const Integer Height, const CBinaryTree::EBinaryTreeType BinaryTreeType )
	{
		if( Height == 0 )
		{
			m_pRootNode = NULL;
			return;
		}

		m_pRootNode = new CNode;

		if( Height == 1 )
			return;

		if( BinaryTreeType == LEFT_COMB )
			_GenerateLeftComb(Height);
		else if( BinaryTreeType == RIGHT_COMB )
			_GenerateRightComb(Height);
		else
			_GeneratePerfectBinaryTree(Height);
	}

	CBinaryTree::~CBinaryTree()
	{
		if( m_pRootNode )
		{
			delete m_pRootNode;
			m_pRootNode = NULL;
		}
	}

	void CBinaryTree::SetRootNode( CNode * RootNode )
	{
		m_pRootNode = RootNode;
	}

	CNode * CBinaryTree::GetRootNode() const
	{
		return m_pRootNode;
	}

	Integer CBinaryTree::CountNodes() const
	{
		if( !m_pRootNode )
			return 0;

		return m_pRootNode->CountNodes();
	}

	std::string CBinaryTree::ToString( const std::string & OpeningString, const std::string & NodeSeparator, const std::string & ClosingString ) const
	{
		if( !m_pRootNode )
			return "";

		return m_pRootNode->ToString(OpeningString, NodeSeparator, ClosingString);
	}
} //namespace Nessy
