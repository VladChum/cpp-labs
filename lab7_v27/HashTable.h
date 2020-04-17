//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef HashTableH
#define HashTableH

class HashNode
{
public:
	int key;
	int nodes;
	AnsiString info;
	HashNode *pNext;
	HashNode(int, AnsiString);
};

class HashTable
{
private:
	HashNode **elements;
	static const int size = 15;
	int Hash(int);
public:
	void Add(int, AnsiString);
	void Create();
	void Delete(TMemo*, int);
	void MidlValue(TMemo*, int);
	void Show(TMemo*);
	void Search(TMemo*, int);
};
//---------------------------------------------------------------------------
#endif
