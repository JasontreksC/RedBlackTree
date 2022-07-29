#include "BST.h"

TreeNode::TreeNode()
	: Data()
	, pParent(nullptr)
	, pLChild(nullptr)
	, pRChild(nullptr)
	, color(BLACK)
{
}
TreeNode::TreeNode(const int& _Data)
	: Data(_Data)
	, pParent(nullptr)
	, pLChild(nullptr)
	, pRChild(nullptr)
	, color(RED)
{
}
TreeNode::~TreeNode()
{
}

Tree::Tree()
	: pRoot(nullptr)
	, NIL(nullptr)
	, iSize(0)
{
	NIL = new TreeNode;
	pRoot = NIL;
}
Tree::~Tree()
{
	delete pRoot;
}

void Tree::InOrder(TreeNode* _Start)
{
	if (_Start == nullptr) return;
	InOrder(_Start->pLChild);
	if (_Start->Data != 0)
	{
		if (_Start == pRoot)
			cout << "[ROOT]<--";
		else
			cout << "         ";
		cout << _Start->Data;
		if (_Start->color == RED)
			cout << "[RED]\n";
		else
			cout << "     [BLACK]\n";
	}

	InOrder(_Start->pRChild);
}

void Tree::Insert(const int& _Data)
{
	TreeNode* pNew = new TreeNode(_Data);
	if (iSize == 0)
	{
		pRoot = pNew;
		pRoot->color = BLACK;
		pNew->pLChild = NIL;
		pNew->pRChild = NIL;
	}
	else
	{
		InsertHelper(*this, pNew, pRoot);
		pNew->pLChild = NIL;
		pNew->pRChild = NIL;
	}
	++iSize;
	
	Reset(pNew);


}

void InsertHelper(Tree& _tree, TreeNode* _pNew, TreeNode* _pParent)
{
	TreeNode* temp = _pParent;
	if (_pNew->Data <= temp->Data)
	{
		if (temp->pLChild == _tree.NIL)
		{
			temp->pLChild = _pNew;
			_pNew->pParent = temp;
		}
		else
			InsertHelper(_tree, _pNew, temp->pLChild);
	}
	else
	{
		if (temp->pRChild == _tree.NIL)
		{
			temp->pRChild = _pNew;
			_pNew->pParent = temp;
		}
		else
			InsertHelper(_tree, _pNew, temp->pRChild);
	}
}

void Tree::RotateL(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U)
{
	if (G != pRoot)
	{
		if (G == G->pParent->pLChild)
			G->pParent->pLChild = P;
		else
			G->pParent->pRChild = P;
		P->pParent = G->pParent;
	}
	else
	{
		pRoot = P;
		P->pParent = nullptr;
	}
	if (P->pLChild != NIL) 
	{
		G->pRChild = P->pLChild;
		P->pLChild->pParent = G;
		P->pLChild = G;
	}
	else
	{
		P->pLChild = G;
		G->pRChild = NIL;
	}
	G->pParent = P;

	P->color = BLACK;
	P->pLChild->color = RED;
	P->pRChild->color = RED;
}
void Tree::RotateR(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U)
{
	if (G != pRoot)
	{
		if (G == G->pParent->pLChild)
			G->pParent->pLChild = P;
		else
			G->pParent->pRChild = P;
		P->pParent = G->pParent;
	}
	else
	{
		pRoot = P;
		P->pParent = nullptr;
	}
	if (P->pRChild != NIL)
	{
		G->pLChild = P->pRChild;
		P->pRChild->pParent = G;
		P->pRChild = G;
	}
	else
	{
		P->pRChild = G;
		G->pLChild = NIL;
	}
	G->pParent = P;

	P->color = BLACK;
	P->pLChild->color = RED;
	P->pRChild->color = RED;
}

void Tree::Recolor(TreeNode* _target)
{
	TreeNode* I, * P, * G, * U; // inserted, parent, g-parent, uncle
	I = _target;
	P = I->pParent;
	G = P->pParent;
	if (P == G->pLChild)
		U = G->pRChild;
	else
		U = G->pLChild;

	P->color = BLACK;
	U->color = BLACK;
	G->color = RED;
	if (G == pRoot)
		G->color = BLACK;
	else
		Reset(G);
}
void Tree::Restruct(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U)
{
	if (P == G->pLChild)    
	{
		if (I == P->pLChild)      // IPG
		{
			RotateR(I, P, G, U);
		}
		else if (I == P->pRChild) // PIG
		{
			G->pLChild = I; I->pParent = G;
			I->pLChild = P; P->pParent = I;
			P->pRChild = NIL;
			RotateR(P, I, G, U); 
		}
	}
	else if (P == G->pRChild) 
	{
		if (I == P->pLChild)      // GIP
		{
			G->pRChild = I; I->pParent = G;
			I->pRChild = P; P->pParent = I;
			P->pLChild = NIL;
			RotateL(P, I, G, U);
		}
		else if (I == P->pRChild) // GPI
		{
			RotateL(I, P, G, U);
		}
	}

}
void Tree::Reset(TreeNode* _target)
{
	if (_target->pParent == nullptr)
		return;
	if (!(_target->color == RED && _target->pParent->color == RED))
		return;

	TreeNode* I, * P, * G, * U; // inserted, parent, g-parent, uncle
	I = _target;
	P = I->pParent;
	G = P->pParent;
	if (P == G->pLChild)
		U = G->pRChild;
	else
		U = G->pLChild;

	if (U->color == BLACK)
		Restruct(I, P, G, U);

	else
		Recolor(I);

}
