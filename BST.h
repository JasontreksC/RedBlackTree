// delete�� ��� �Ҹ��ڿ�.
// ��Ʈ�� ����������.
// ��ȸ ���ȣ�⿡�� ����� ����� ������ InOrder
// LevelOrder �� que�� �̿�
// delete ���ȣ��� ��Ʈ���� �����Ͽ� ��ü ���� ����.
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