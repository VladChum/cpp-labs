//---------------------------------------------------------------------------
#pragma hdrstop
#include "HashTable.h"
HashNode :: HashNode(int k, AnsiString i)
{
	key = k;
	info = i;
	nodes = 1;
	pNext = nullptr;
}

void HashTable :: Create()
{
	elements = (HashNode**)calloc(size, sizeof(HashNode));
	for(int i = 0; i < size; i++)
	{
		elements[i] = (HashNode*)calloc(1, sizeof(HashNode));
        elements[i] = nullptr;
	}
}

void HashTable :: Add(int n, AnsiString str)
{
	int i = Hash(n);
	if(!elements[i]) elements[i] = new HashNode(n, str);
	else
	{
		HashNode *temp = elements[i];
		while(temp->pNext) temp = temp->pNext;
		temp->pNext = new HashNode(n, str);
		elements[i]->nodes++;
	}
}

void HashTable :: Delete(TMemo *Memo, int num)
{
	int i = Hash(num);
	int marker = 0;
	for(HashNode *del = elements[i], *temp = nullptr; del; del = del->pNext)
	{
		if(del->key == num)
		{
			if(!temp) elements[i] = del->pNext;
			else
			{
				temp->pNext = del->pNext;
                elements[i]->nodes--;
			}
			del = nullptr;
			marker++;
			break;
		}
		temp = del;
	}
	if(!marker) ShowMessage("Нет элемента с таким ключом");
}

int HashTable :: Hash(int num)
{
	if(!num) return num % size + 10;
	else return num % size;
}

void HashTable :: Show(TMemo *Memo)
{
	Memo->Lines->Clear();
	for(int  i = 0; i < size; i++)
	{
		if(elements[i])
		{
			AnsiString str = "(" + IntToStr(elements[i]->key) + ", " + elements[i]->info + ")";
			if(!elements[i]->pNext) Memo->Lines->Add(str);
			else
			{
				AnsiString s = "";
				HashNode *temp = elements[i]->pNext;
				while(temp)
				{
					s += "   (" + IntToStr(temp->key) +", " + temp->info + ")";
					temp = temp->pNext;
				}
				str += s;
				Memo->Lines->Add(str);
            }
		}
	}
	Memo->Lines->Add("\n");
}

void HashTable :: Search(TMemo *Memo, int num)
{
	int i = Hash(num);
	if(!elements[i])
	{
		ShowMessage("Нет элемента с таким ключом");
        return;
	}
	if(elements[i]->key == num)
	{
		Memo->Lines->Add("Элемент найден");
		Memo->Lines->Add("Ключ: " + IntToStr(elements[i]->key) + "   Значение: " +
		elements[i]->info);
	}
	else
	{
		int marker = 0;
		for(HashNode *temp = elements[i]->pNext; temp; temp = temp->pNext)
		{
			if(temp->key == num)
			{
				marker++;
                Memo->Lines->Add("Элемент найден");
				Memo->Lines->Add("Ключ: " + IntToStr(temp->key) + "   Значение: " +
				temp->info);
				break;
			}
		}
		if(!marker) ShowMessage("Нет элемента с таким ключом");
	}
	Memo->Lines->Add("\n");
}

void HashTable :: MidlValue(TMemo *Memo, int sum)
{
	int length = 0;
	int kol = 0;
	for(int i = 0; i < size; i++)
	{
		if(elements[i])
		{
			if(elements[i]->pNext) length += elements[i]->nodes;
			else length++;
		}
	}
	int midlValue = sum / length;

	for(int i = 0, j = 0; i < size; i++)
	{
		if(elements[i])
			if(!elements[i]->pNext)
			{
				 if(elements[i]->key <= midlValue) kol++;
			}
		else
			{
				HashNode *temp = elements[i];
				while(temp)
				{
					if(temp->key <= midlValue) kol++;
					temp = temp->pNext;
				}
			}
	}
   Memo->Lines->Add("\n");
   Memo->Lines->Add("среднее значение : ");
   Memo->Lines->Add(midlValue);
   Memo->Lines->Add("\nКлючей не привышающих среднее значение: ");
   Memo->Lines->Add(kol);

}

//---------------------------------------------------------------------------
#pragma package(smart_init)
