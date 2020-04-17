//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "HashTable.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HashTable table;
int sum = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	table.Create();
	srand(time(0));
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	if(Edit1->Text != "")
	{
		int key = rand() % 100;
		sum += key;
		table.Add(key, Edit1->Text);
		table.Show(Memo1);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	try
	{
		int key = StrToInt(Edit2->Text);
		if(key < 0)
		{
			ShowMessage("¬ведите корректный ключ");
		}
		else
		{
			sum -= key;
			table.Delete(Memo1, key);
			table.Show(Memo1);
		}
	}
	catch(...)
	{
		ShowMessage("¬ведите корректный ключ или элементов больше нет!!!");
	}
	Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSearchClick(TObject *Sender)
{
	try
	{
		int key = StrToInt(Edit2->Text);
		if(key < 0)
		{
			ShowMessage("¬ведите корректный ключ");
			Edit2->Text = "";
		}
		else table.Search(Memo1, key);
	}
	catch(...)
	{
		ShowMessage("¬ведите корректный ключ");
        Edit2->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonMidlValueClick(TObject *Sender)
{
	if (sum > 0) 
	{
		table.MidlValue(Memo1, sum);
	}
	else
		ShowMessage("Ёлементы не введены!!! ¬ведите элементы и повторите оперцию");
	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

