//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
List::List()
{
	head = NULL;
	Tail = NULL;
}

int kolMax = 0;
int kolMin = 0;

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


 void List::Swap()
{
	//element *min = GetMin();
	//element *max = GetMax();

	if (head == NULL || max[0] == min[0]) {
		return;
	}

    int kolTransposition = 0;
	if (kolMin >= kolMax)  kolTransposition = kolMax;
	else
	kolTransposition = kolMin;

    for (int i = 0; i < kolTransposition; i++)
	{
		element *minPrev = min[i]->prev;
		element *minNext = min[i]->next;
		element *maxPrev = max[i]->prev;
		element *maxNext = max[i]->next;

		if (min[i]->next == max[i])
		{
			min[i]->prev = max[i];
			min[i]->next = maxNext;
			max[i]->prev = minPrev;
			max[i]->next = min[i];

			if (minPrev != NULL) {
				minPrev->next = max[i];
			} else {
				head = max[i];
			}

			if (maxNext != NULL) {
				maxNext->prev = min[i];
			} else {
				Tail = min[i];
			}

		} else if (max[i]->next == min[i]) {
			min[i]->prev = maxPrev;
			min[i]->next = max[i];
			max[i]->prev = min[i];
			max[i]->next = minNext;

			if (minNext != NULL) {
				minNext->prev = max[i];
			} else {
				Tail = max[i];
			}

			if (maxPrev != NULL) {
				maxPrev->next = min[i];
			} else {
				head = min[i];
			}
		} else {
			min[i]->prev = maxPrev;
			min[i]->next = maxNext;
			max[i]->prev = minPrev;
			max[i]->next = minNext;

			if (minPrev != NULL) {
				minPrev->next = max[i];
			} else {
				head = max[i];
			}

			if (minNext != NULL) {
				minNext->prev = max[i];
			} else {
				Tail = max[i];
			}

			if (maxPrev != NULL) {
				maxPrev->next = min[i];
			} else {
				head = min[i];
			}

			if (maxNext != NULL) {
				maxNext->prev = min[i];
			} else {
				Tail = min[i];
			}
		}
	}
}

#pragma package(smart_init)
