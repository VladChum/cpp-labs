//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
#include "List.h"

class Queue : public List
{
	public:
	Queue();
	void Push(int x);
	int ShowFist();
	bool IsEmpty();
};





#endif


