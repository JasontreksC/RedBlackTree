// delete는 노드 소멸자에.
// 루트를 전역변수로.
// 순회 재귀호출에서 출력을 가운데다 놓으면 InOrder
// LevelOrder 는 que를 이용
// delete 재귀호출로 루트에서 시작하여 전체 삭제 가능.
#include <iostream>
using namespace std;
enum Color { RED, BLACK };

class TreeNode
{
public:
	int Data;
	TreeNode* pParent;
	TreeNode* pLChild;
	TreeNode* pRChild;
	int color;

	TreeNode();
	TreeNode(const int& _Data);
	~TreeNode();
};

class Tree
{
public:
	TreeNode* pRoot;
	TreeNode* NIL;
	int iSize;

	Tree();
	~Tree();

	void InOrder(TreeNode* _Start);
	void Insert(const int& _Data);
	//void Find(int _Data);
	void RotateL(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U);
	void RotateR(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U);
	void Restruct(TreeNode* I, TreeNode* P, TreeNode* G, TreeNode* U);
	void Recolor(TreeNode* _target);
	void Reset(TreeNode* _target);
};

void InsertHelper(Tree& _tree, TreeNode* _pNew, TreeNode* _pParent);