//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "List.cpp"
#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(0));
}

void TForm1::InTwoCircle(List *InputQueue)
{
	EditMin->Text = AnsiString(InputQueue->GetMin()->data);
	EditMax->Text = AnsiString(InputQueue->GetMax()->data);
	InputQueue->Swap();
	element *current = InputQueue->head;

	while (current != NULL)
		{
			ListBoxFirst->Items->Add(AnsiString(current->data));
			current = current->next;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOKClick(TObject *Sender)
{
	ListBox->Clear();
	ListBoxFirst->Clear();
	try
	{
		List *InputQueue = new List();
		char* str = AnsiString(EditInput->Text).c_str();
		for(int i = 0; str[i]; i++)
		{
			if(!isdigit(str[i]) && str[i] != ' ' && str[i] != '-') throw 1;
		}
		char* pch = strtok (str," ");
		InputQueue->Push(atoi(pch));
		ListBox->Items->Add(AnsiString(pch));
		while (pch != NULL)
		{
		  pch = strtok (NULL, " ");
		  if(pch != NULL)
		  {
			if (pch[0] == '-')
			{
				InputQueue->Push(atoi(pch));
			}
			else InputQueue->Push(atoi(pch));
		  }
		  ListBox->Items->Add(AnsiString(pch));
		}
		InTwoCircle(InputQueue);
	}
	catch(int i)
	{
		Application->MessageBox(String("Incorrect input").c_str(), String("Error").c_str(), MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRandomClick(TObject *Sender)
{
	//srand(time(0));
	ListBox->Clear();
	ListBoxFirst->Clear();

	List *InputQueue = new List();
	int temp;
	for(int i = 0; i < 40; i++)
	{
		temp = rand()%100;
		InputQueue->Push(temp);
		ListBox->Items->Add(AnsiString(temp));
	}
	InTwoCircle(InputQueue);
}
//---------------------------------------------------------------------------

