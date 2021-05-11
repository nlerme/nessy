#include "nessy_node.h"


namespace Nessy
{
	CNode::CNode( CNode * LeftNode, CNode * RightNode ) : m_pLeftNode(LeftNode), m_pRightNode(RightNode){}

	CNode::~CNode()
	{
		if( m_pLeftNode )
		{
			delete m_pLeftNode;
			m_pLeftNode = NULL;
		}

		if( m_pRightNode )
		{
			delete m_pRightNode;
			m_pLeftNode = NULL;
		}
	}

	bool CNode::IsALeaf() const
	{
		return !(m_pLeftNode || m_pRightNode);
	}

	void CNode::SetLeftNode( CNode * LeftNode )
	{
		m_pLeftNode = LeftNode;
	}

	CNode * CNode::GetLeftNode() const
	{
		return m_pLeftNode;
	}

	void CNode::SetRightNode( CNode * RightNode )
	{
		m_pRightNode = RightNode;
	}

	CNode * CNode::GetRightNode() const
	{
		return m_pRightNode;
	}

	std::string CNode::ToString( const std::string & OpeningString, const std::string & StringSeparator, const std::string & ClosingString ) const
	{
		std::string LeftNode, RightNode;

		if( m_pLeftNode )
			LeftNode = m_pLeftNode->ToString(OpeningString, StringSeparator, ClosingString);

		if( m_pRightNode )
			RightNode = m_pRightNode->ToString(OpeningString, StringSeparator, ClosingString);

		return OpeningString + LeftNode + StringSeparator + RightNode + ClosingString;
	}

	Integer CNode::CountNodes() const
	{
		Integer LeftNode(0), RightNode(0);

		if( m_pLeftNode )
			LeftNode = m_pLeftNode->CountNodes();

		if( m_pRightNode )
			RightNode = m_pRightNode->CountNodes();

		return LeftNode + 1 + RightNode;
	}
} //namespace Nessy
