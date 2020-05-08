//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Tree.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree tree;
int sum = 0;
int kol = 0;
void Enable()
{
	Form1->ButtonDelete->Enabled = True;
	Form1->ButtonScan->Enabled = True;
	Form1->ButtonBalansing->Enabled = True;
	Form1->Button5->Enabled = True;
	Form1->Button6->Enabled = True;
	Form1->Button7->Enabled = True;
	Form1->ButtonMidl->Enabled = True;
}
void Disable()
{
	Form1->ButtonDelete->Enabled = False;
	Form1->ButtonScan->Enabled = False;
	Form1->ButtonBalansing->Enabled = False;
	Form1->Button5->Enabled = False;
	Form1->Button6->Enabled = False;
	Form1->Button7->Enabled = False;
	Form1->ButtonMidl->Enabled = False;
}
bool IsRepeat(int num)
{
	for(int i = 1 ; i < Form1->StringGrid1->RowCount; i++)
	{
		if(num == Form1->StringGrid1->Cells[1][i].ToInt()) return false;
	}
	return true;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "Фамилия";
	StringGrid1->Cells[1][0] = "Номер Студента";
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonAddClickClick(TObject *Sender)
{
	try
	{
		AnsiString str = EditSecondName->Text;
		int num = StrToInt(EditNumber->Text);
		if(IsRepeat(num) && EditSecondName->Text != "")
		{
			if(num < 1 || num >= 10000)
			{
				EditNumber->Text = "";
				ShowMessage("Некорректный номер или номер не введён!!!\n Номер должен быть максимум четырёх занчным!");
			}
			else
			{
				sum += EditNumber->Text.ToInt();
				kol++;
				StringGrid1->RowCount++;
				StringGrid1->Cells[0][StringGrid1->RowCount - 1] = str;
				StringGrid1->Cells[1][StringGrid1->RowCount - 1] = num;
				tree.AddNode(str, num);
				Memo1->Lines->Add("Добавлен участник");
				Memo1->Lines->Add("Фамилия: " + str);
				Memo1->Lines->Add("Номер: " + IntToStr(num));
				Memo1->Lines->Add("\n");
				tree.ShowTree(Form1->TreeView1);
				Enable();
				EditSecondName->Text = "";
				EditNumber->Text = "";
			}
		}
		else
		{
			EditNumber->Text = "";
			ShowMessage("Номера не могут совпадать или фамилия не введена");
		}
	}
	catch(...)
	{
		Form1->EditNumber->Text = "";
		ShowMessage("Некорректный номер");
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonScanClick(TObject *Sender)
{
	try
	{
		int num = StrToInt(EditNumber->Text);
		if(num > 0 && num < 10000)
		{
			AnsiString str = tree.GetStudent(num);
			if(str != "")
			{
				Memo1->Lines->Add("Участник найден: ");
				Memo1->Lines->Add("Фамилия: " + str);
				Memo1->Lines->Add("Номер: " + IntToStr(num));
				Memo1->Lines->Add("\n");
			}
			else
			{
				Memo1->Lines->Add("Участник не найден");
				Memo1->Lines->Add("\n");
            }
		}
		else
		{
			EditNumber->Text = "";
			ShowMessage("Некорректный номер");
        }
	}
	catch(...)
	{
		EditNumber->Text = "";
		ShowMessage("Некорректный номер или студента с таким номером не существует");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	try
	{
		int num = StrToInt(EditNumber->Text);
		if(!IsRepeat(num))
		{
			sum -= num;
			AnsiString str = tree.GetStudent(num);
			tree.DeleteNode(num);
			tree.ShowTree(TreeView1);
			kol--;
			Memo1->Lines->Add("Студент удален");
			Memo1->Lines->Add("Фамилия: " + str);
			Memo1->Lines->Add("Номер: " + IntToStr(num));
			Memo1->Lines->Add("\n");
			for(int i = 1, j = 1; i < StringGrid1->RowCount; i++)
			{
				if(StringGrid1->Cells[1][i] != num)
				{
					StringGrid1->Cells[0][j] = StringGrid1->Cells[0][i];
					StringGrid1->Cells[1][j] = StringGrid1->Cells[1][i];
					j++;
				}
			}
			StringGrid1->RowCount--;
			EditSecondName->Text = "";
			EditNumber->Text = "";
			if(!tree.NumNodes) Disable();
		}
		else
		{
			EditNumber->Text = "";
			ShowMessage("Нет студента с таким номером");
		}
	}
	catch(...)
	{
		EditNumber->Text = "";
		ShowMessage("Некорректный номер");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonBalansingClick(TObject *Sender)
{
	tree.Balance();
	tree.ShowTree(Form1->TreeView1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Lines->Add("Прямой обход");
	tree.Right(Memo1);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Add("Обратный обход");
	tree.Back(Memo1);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Add("Обход в порядке возрастания ключа");
	tree.Growth(Memo1);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonMidlClick(TObject *Sender)
{
    tree.Balance();
	tree.ShowTree(Form1->TreeView1);
	Memo1->Lines->Add("Среднее значение всех ключей дерева: " + FloatToStr((double)sum / (double)kol));
	Memo1->Lines->Add("\nБлижайший к среднему студент : ");
	tree.ScanElement(Memo1, (double)sum / (double)kol);
	Memo1->Lines->Add("\n");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


