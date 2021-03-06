//---------------------------------------------------------------------------
#pragma hdrstop
#include "Tree.h"
#include <math.h>

Tree :: Tree()
{
	pHead = nullptr;
	NumNodes = 0;
}

Node* Tree :: MakeTree(int *arr, AnsiString *str, int first, int last)
{
	if(!last) return nullptr;
	Node *node = new Node;
	node->surname = str[first + last / 2];
	node->number = arr[first + last / 2];
	NumNodes++;
	int lastl = last / 2;
	int lastr = last - lastl - 1;
	node->pLeft = MakeTree(arr, str, first, lastl);
	node->pRight = MakeTree(arr, str, first + lastl + 1, lastr);
	return node;
}
void Tree :: AddNode(AnsiString str, int num)
{
	if(!pHead)
	{
		pHead = new Node;
		pHead->surname = str;
		pHead->number = num;
		pHead->pLeft = pHead->pRight = nullptr;
	}
	else
	{
		Node *node = SearchFree(pHead, num);
		node->surname = str;
		node->number = num;
		node->pLeft = node->pRight = nullptr;
	}
	NumNodes++;
}

Node* Tree :: SearchFree(Node *temp, int num)
{
	if(num < temp->number)
	{
		if(!temp->pLeft)
		{
			temp->pLeft = new Node;
			return temp->pLeft;
		}
		else return SearchFree(temp->pLeft, num);
	}
	else
	{
		if(!temp->pRight)
		{
			temp->pRight = new Node;
			return temp->pRight;
		}
		else return SearchFree(temp->pRight, num);
	}
}

void Tree :: PrintTree(Node* temp, TTreeView *TreeView, int &index)
{
	int i = index;
	if(temp->pLeft)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->pLeft->surname);
		PrintTree(temp->pLeft, TreeView, ++index);
	}
	if(temp->pRight)
	{
		TreeView->Items->AddChild(TreeView->Items->Item[i], temp->pRight->surname);
		PrintTree(temp->pRight, TreeView, ++index);
    }
}

void Tree :: ShowTree(TTreeView *TreeView)
{
	int index = 0;
	TreeView->Items->Clear();
	if(pHead)
	{
		TreeView->Items->Add(NULL, pHead->surname);
		PrintTree(pHead, TreeView, index);
    }
}

AnsiString Tree :: GetStudent(int num)
{
	Node *temp = pHead;
	while(temp->number != num)
	{
		if(num < temp->number) temp = temp->pLeft;
		else temp = temp->pRight;
	}
	if(temp)return temp->surname;
	else return "";
}

void Tree :: DeleteNode(int num)
{
	Node *del, *prevdel, *node, *prevnode;
	del = pHead;
	prevdel = nullptr;
	while(del->number != num)
	{
		prevdel = del;
		if(num < del->number) del = del->pLeft;
		else del = del->pRight;
	}
	if(!del)return;
	if(!del->pRight) node = del->pLeft;
	else if(!del->pLeft) node = del->pRight;
	else
	{
		prevnode = del;
		node = del->pLeft;
		while(node->pRight)
		{
			prevnode = node;
			node = node->pRight;
		}
		if(prevnode == del) node->pRight = del->pRight;
		else
		{
			node->pRight = del->pRight;
			prevnode->pRight = node->pLeft;
			node->pLeft = prevnode;
        }
	}
	if(!prevdel) pHead = prevdel = node;
	else if(del->number < prevdel->number) prevdel->pLeft = node;
	else prevdel->pRight = node;
	delete del;
	NumNodes--;
}

void Tree :: Delete(Node *p)
{
	if(p)
	{
		NumNodes--;
		Delete(p->pLeft);
		Delete(p->pRight);
        delete p;
    }
}

void Tree :: Balance()
{
	int* arr = new int[NumNodes];
	AnsiString* str = new AnsiString[NumNodes];
	int size = 0;
	ToArray(pHead, arr, str, size);
	Delete(pHead);
	pHead = MakeTree(arr, str, 0, size);
}

void Tree :: ToArray(Node *p, int* arr, AnsiString* str, int &index)
{
	if(p->pLeft) ToArray(p->pLeft, arr, str, index);
	str[index] = p->surname;
	arr[index] = p->number;
	index++;
	if(p->pRight) ToArray(p->pRight, arr, str, index);
}


void Tree :: Right(TMemo *Memo)
{
	NLR(Memo, pHead);
}

void Tree :: NLR(TMemo *Memo, Node *p)
{
	if(p)
	{
		Memo->Lines->Add(p->surname);
		NLR(Memo, p->pLeft);
		NLR(Memo, p->pRight);
    }
}

void Tree :: Back(TMemo *Memo)
{
	TraversalPostOrder(Memo, pHead);
}

void Tree :: TraversalPostOrder(TMemo *Memo, Node *p)
{
	if(p)
	{
		TraversalPostOrder(Memo, p->pLeft);
		TraversalPostOrder(Memo, p->pRight);
		Memo->Lines->Add(p->surname);
	}
}
void Tree :: TraversalPreOrder(TMemo *Memo, Node *p)
{
	if(p)
	{
		TraversalPreOrder(Memo, p->pLeft);
		Memo->Lines->Add(p->surname);
		TraversalPreOrder(Memo, p->pRight);
	}
}
void Tree :: Growth(TMemo *Memo)
{
	TraversalPreOrder(Memo, pHead);
}

void Tree :: Check(TMemo *Memo, Node *p, float midl,int element)
{
	if(p)
	{
		Check(Memo, p->pLeft, midl, element);
		Check(Memo, p->pRight, midl, element);
		if ((p->number  <= midl) && ((midl - p->number) <= midl - element)){ element = p->number;}
		if ((p->number > midl) && ((p->number - midl) < abs(element - midl))) { element = p->number;}
		numb = element;
	}

}

void Tree :: ScanElement(TMemo *Memo, float midl)
{
   numb = 0;
   Check(Memo, pHead, midl, 0);
   Memo->Lines->Add(GetStudent(numb) + "  " + IntToStr(numb));
}

//--------------------------------------------------------------------------
#pragma package(smart_init)
