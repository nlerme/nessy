#ifndef __NESSY_NODE_H__
#define __NESSY_NODE_H__

#include <string>
#include "nessy_types.h"


namespace Nessy
{
	class CNode
	{
	     private :
		CNode * m_pLeftNode, * m_pRightNode;


	     public :
		CNode( CNode * LeftNode = NULL, CNode * RightNode = NULL );
		~CNode();

		bool IsALeaf() const;
		void SetLeftNode( CNode * LeftNode );
		CNode * GetLeftNode() const;
		void SetRightNode( CNode * RightNode );
		CNode * GetRightNode() const;
		std::string ToString( const std::string & OpeningString, const std::string & StringSeparator, const std::string & ClosingString ) const;
		Integer CountNodes() const;
	};
} // namespace Nessy

#endif //__NESSY_NODE_H__
