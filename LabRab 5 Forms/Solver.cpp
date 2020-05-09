//---------------------------------------------------------------------------

#pragma hdrstop

#include "Solver.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Solver::Solver() : Queue() {

}

 void Solver::Swap()
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
