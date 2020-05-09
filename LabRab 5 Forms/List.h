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

		public:
		List() ;
		element* head;
        element *Tail;
		element* min[50];
		element* max[50];
		element* GetMax();
		element* GetMin();
		int kolMax;
		int kolMin;
		void Push(int x);
		int ShowFirst();
		bool IsEmpty();
};

#endif
