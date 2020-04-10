//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
struct element
{
	element* next;
	element* prev;
	int data;
};

class List
{
		element *Tail;
	public:
		element* head;
		element* max;
		element* min;
		List(int i);
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
