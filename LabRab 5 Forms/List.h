//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
struct  element
{
	element* next;
	element* prev;
	int data;
};

class List
{
		element *Tail;
	public:
		List() ;
		element* head;
		element* min[30];
		element* max[30];
		void Push(int x);
		int Pop();
		int ShowFirst();
		bool IsEmpty();
		element* GetMax();
		element* GetMin();
		void SetHead(element* newhead);
		void Swap();
};
#endif
