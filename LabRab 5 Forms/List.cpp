//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
List::List()
{
	head = NULL;
	Tail = NULL;
	kolMin = 0;
	kolMax = 0;
}

void List::Push(int x)
{
	if (IsEmpty()) {
		element *newElement = new element;
		newElement->prev = NULL;
		newElement->next = NULL;
		newElement->data = x;
		Tail = head = newElement;
        max[0] = head;
		min[0] = head;
		kolMax = 1;
		kolMin = 1;
	} else {
		element *prevTail = Tail;
		element *newTail = new element;
		newTail->prev = prevTail;
		newTail->next = NULL;
		newTail->data = x;
		Tail = newTail;
		prevTail->next = newTail;
		if(newTail->data == max[0]->data) {max[kolMax] = newTail; kolMax++;}
		if(newTail->data == min[0]->data) {min[kolMin] = newTail; kolMin++;}
		if(newTail->data > max[0]->data) {max[0] = newTail; kolMax = 1;}
		if(newTail->data < min[0]->data) {min[0] = newTail; kolMin = 1;}
	}
}

 int List::ShowFirst()
 {
	int result = head->data;
	if (head == NULL) {
		 return 0;
	}
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
	}
	return result;
 }

bool List::IsEmpty()
{
	return head == NULL ? true : false;
}

element* List::GetMax()
{
	if (head == NULL) {
		return NULL;
	}

	element *max = head;
	element *current = head;
	while (current != NULL) {
		if (current->data > max->data)
		{
			max = current;
		}
		current = current->next;
	}

	return max;
}

element* List::GetMin()
{
	if (head == NULL) {
		return NULL;
	}

	element *min = head;
	element *current = head;
	while (current != NULL) {
		if (current->data < min->data) {
			min = current;
		}
		current = current->next;
	}

	return min;
}



#pragma package(smart_init)
