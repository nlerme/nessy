#ifndef __NESSY_BINARY_TREE_H__
#define __NESSY_BINARY_TREE_H__

#include <string>
#include "nessy_node.h"
#include "nessy_types.h"


namespace Nessy
{
	class CBinaryTree
	{
	     private :
		CNode * m_pRootNode;
		void _GenerateLeftComb( const Integer Height );
		void _GenerateRightComb( const Integer Height );
		void _GeneratePerfectBinaryTree( const Integer Height );


	     public :
		enum EBinaryTreeType
		{
			LEFT_COMB,
			RIGHT_COMB,
			COMPLETE_BINARY_TREE
		};

		CBinaryTree( CNode * RootNode = NULL );
		CBinaryTree( const Integer Height, const EBinaryTreeType BinaryTreeType );
		~CBinaryTree();

		void SetRootNode( CNode * RootNode );
		CNode * GetRootNode() const;
		Integer CountNodes() const;
		std::string ToString( const std::string & OpeningString, const std::string & NodeSeparator, const std::string & ClosingString ) const;
	};
} // namespace Nessy

#endif //__NESSY_BINARY_TREE_H__
