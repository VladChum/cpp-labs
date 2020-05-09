//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
#pragma package(smart_init)



Queue::Queue() : List() {}

	void Queue::Push(int x){
		List::Push(x);
	}
	int Queue::ShowFist(){
		List::ShowFirst();
	}
	bool Queue::IsEmpty() {
		List::IsEmpty();
    }
