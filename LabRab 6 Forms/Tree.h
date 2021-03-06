//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef TreeH
#define TreeH

class Node
{
public:
	AnsiString surname;
	int number;
	Node *pLeft, *pRight;
};

class Tree
{
private:
	Node *pHead;
	Node* SearchFree(Node*, int);
	void PrintTree(Node*, TTreeView*, int&);
	void ToArray(Node*, int*, AnsiString*, int&);
    Node* MakeTree(int*, AnsiString*, int, int);
	void Delete(Node*);
	void NLR(TMemo*, Node*);
	void TraversalPostOrder(TMemo*, Node*);
	void TraversalPreOrder(TMemo*, Node*);
	void Check(TMemo *, Node *, float, int);
	void Count(Node*, int&);
public:
	int numb;
	int NumNodes;
	Tree();
	void AddNode(AnsiString, int);
	void ShowTree(TTreeView*);
	AnsiString GetStudent(int);
	void DeleteNode(int);
	void Balance();
	void Right(TMemo*);
	void Back(TMemo*);
	void Growth(TMemo*);
	void ScanElement(TMemo*, float);
};

//---------------------------------------------------------------------------
#endif
