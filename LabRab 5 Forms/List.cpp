//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
List::List(int i)
{
	head = NULL;
  //	Tail = NULL;
}

void List::Push(int x)
{
	if(head != NULL)
	{
		element* NewElement = new element;
		NewElement->data= x;
		NewElement->prev = head->prev;
		NewElement->next = head;
		head->prev->next = NewElement;
		head->prev = NewElement;
		if(NewElement->data > max->data) max = NewElement;
		if(NewElement->data < min->data) min = NewElement;
	}
	else
	{
		element* NewElement = new element;
		head = NewElement;
		head->next = head;
		head->prev = head;
		head->data = x;
		max = head;
		min = head;
	}
}

int List::Pop()
{
	int result = head->data;
	if(head == head->next)
	{
		head = NULL;
	}
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
	}
	return result;
}

int List::ShowFirst()
{
	return head->data;
}

bool List::IsEmpty()
{
	if(head == NULL) return true;
	else return false;
}

element* List::GetMax()
{
	return max;
}

element* List::GetMin()
{
	return min;
}

void List::Swap()
{
	element *beforeMin = min->prev;
	element *afterMin = min->next;

	element *beforeMax = max->prev;
	element *afterMax = max->next;


	if (beforeMin)
		beforeMin->next = max;
	if (afterMin)
		afterMin->prev = max;
	if (beforeMax)
		beforeMax->next = min ;
	if (afterMax)
		afterMax->prev = min;

	min->prev = beforeMax;
	min->next = afterMax;

	max->prev = beforeMin;
	max->next = afterMin;
  /*
	if (max->next == NULL)
		Tail = max;
	else if (min->next == NULL)
		Tail = min;
	if (max->prev == NULL)
		head = max;
	else if (min->prev == NULL)
		head = min;
	 */
}
#pragma package(smart_init)