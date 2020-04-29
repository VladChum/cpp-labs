//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	numOfStudents = 0;
	newid = 0;
}

bool TForm1::IsEmptyEdit()
{
	bool isempty = false;
	if(EditName->Text.IsEmpty()) isempty = true;
	else if(EditFatherName->Text.IsEmpty()) isempty = true;
	else if(EditLastName->Text.IsEmpty()) isempty = true;
	else if(EditGrupp->Text.IsEmpty()) isempty = true;
	else if(EditMaks->Text.IsEmpty()) isempty = true;
	else if(EditIncome->Text.IsEmpty()) isempty = true;
	if(isempty) return true;
	else return false;
}

void TForm1::VisibleEdits()
{
	if(EditName->Visible == false)
	{
		EditLastName->Visible = true;
		EditName->Visible = true;
		EditFatherName->Visible = true;
		EditGrupp->Visible = true;
		EditMaks->Visible = true;
		EditIncome->Visible = true;
		ButtonAddOK->Visible = true;
	}
	else
	{
		EditLastName->Visible = false;
		EditName->Visible = false;
		EditFatherName->Visible = false;
		EditGrupp->Visible = false;
		EditMaks->Visible = false;
		EditIncome->Visible = false;
		ButtonAddOK->Visible = false;
	}
}

void TForm1::RefreshListBox()
{
	ListBoxMain->Items->Clear();
	List *temp;
	temp = HandUndergrad;
	while(temp != NULL)
	{
		ListBoxMain->Items->Add(temp->Undergrad.ShowStudents());
		temp = temp->NextUndergrad;
	}
	delete temp;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddOKClick(TObject *Sender)
{
	if(!IsEmptyEdit())
	{
		try
		{
			if (EditMaks->Text.ToDouble() > 10 || EditMaks->Text.ToDouble() < 0)
			{
				Application->MessageBox(String("Средний бал не может быть больше 10 и меньше 0").w_str(), MB_OK);

			}
			else
			{
			students ThisUndergrad(EditName->Text, EditLastName->Text, EditFatherName->Text, EditGrupp->Text.ToInt(), EditMaks->Text.ToDouble(), EditIncome->Text.ToInt());
			newid++;
			if(numOfStudents == 0)
			{
				LastUndergrad= new List;
				HandUndergrad = LastUndergrad;
			}
			else
			{
				LastUndergrad->NextUndergrad = new List;
				LastUndergrad = LastUndergrad->NextUndergrad;
			}
			LastUndergrad->Undergrad = ThisUndergrad;
			LastUndergrad->NextUndergrad = NULL;
			numOfStudents++;
			VisibleEdits();
			}
            RefreshListBox();
		}
		catch(EConvertError&)
		{
			Application->MessageBox(String("Вы ввели ошибочное число или вообще не вели ничего").w_str(), String("Ошибка").w_str(), MB_OK);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowByIncomeTwoOKClick(TObject *Sender)
{
	int kol = 0;
	try
	{
		double thismaks = EditShowByMaks->Text.ToDouble();
		int thisincome = EditShowByIncomeTwo->Text.ToInt();
		if (thismaks < 0 || thismaks >10) {
			Application->MessageBox(String("Средний бал не может быть больше 10 и меньше 0!!!").w_str(), MB_OK);
			RefreshListBox();
		}
		else
		if (thisincome < 0) {
			Application->MessageBox(String("Доход не может быть меньше 0!!!").w_str(), MB_OK);
			RefreshListBox();
		}
		else
		{
			ListBoxMain->Items->Clear();
			List *temp = HandUndergrad;
			while(temp != NULL)
			{
				if(temp->Undergrad.income >= 2 * thisincome && temp->Undergrad.maks < thismaks)
				{
					ListBoxMain->Items->Add(temp->Undergrad.ShowStudents());
					kol++;
				}
				temp = temp->NextUndergrad;
			}
			delete temp;
			if (kol == 0)
			{
				 Application->MessageBox(String("Таких студентов нет").w_str(), MB_OK);
				 RefreshListBox();
			}
		}
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Вы ввели ошибочное число или не вели ничего").w_str(), String("Ошибка").w_str(), MB_OK);
	}
	EditShowByMaks->Text = "";
	EditShowByIncomeTwo->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowByIncomeOKClick(TObject *Sender)
{
	int kol = 0;
	try
	{
		int thisincome = EditShowByIncome->Text.ToInt();
		 if (thisincome < 0) {
			Application->MessageBox(String("Доход не может быть отрицательным").w_str(), MB_OK);
			 RefreshListBox();
		 }
		 else
		 {
			ListBoxMain->Items->Clear();
			List *temp = HandUndergrad;
			while(temp != NULL)
			{
				if(temp->Undergrad.income >= thisincome)
				{
					ListBoxMain->Items->Add(temp->Undergrad.ShowStudents());
					kol++;
				}
				temp = temp->NextUndergrad;
			}
			delete temp;
			if (kol == 0)
			{
				 Application->MessageBox(String("Таких студентов нет").w_str(), MB_OK);
				 RefreshListBox();
			}
		 }
	}
	catch(EConvertError&)
	{
		Application->MessageBox(String("Вы ввели ошибочное число или не вели ничего").w_str(), String("Ошибка").w_str(), MB_OK);
	}
    EditShowByIncome->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	List *temp = HandUndergrad;
	AnsiString thisstring = AnsiString(ListBoxMain->Items->Strings[ListBoxMain->ItemIndex]);;
	if (temp != NULL && temp->Undergrad.ShowStudents() == thisstring)
	{
		HandUndergrad = HandUndergrad->NextUndergrad;
		delete temp;
	}
	else
	{
		while(temp && temp->NextUndergrad != NULL && temp->NextUndergrad->Undergrad.ShowStudents() != thisstring)
		{
			temp = temp->NextUndergrad;
		}
		if(temp == NULL) return;
		delete temp->NextUndergrad;
		temp->NextUndergrad = temp->NextUndergrad->NextUndergrad;
	}
	numOfStudents--;
	RefreshListBox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowAllOKClick(TObject *Sender)
{
	RefreshListBox();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	VisibleEdits();
	EditName->Text = "";
	EditLastName->Text = "";
	EditFatherName->Text = "";
	EditGrupp->Text = "";
	EditMaks->Text = "";
	EditIncome->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonShowByLastNameOKClick(TObject *Sender)
{
	int kol = 0;
	AnsiString thislastname = EditShowByLastName->Text;
	ListBoxMain->Items->Clear();
	List *temp = HandUndergrad;
	while(temp != NULL)
	{
		if(temp->Undergrad.lastname == thislastname)
		{
			ListBoxMain->Items->Add(temp->Undergrad.ShowStudents());
			kol++;
		}
		temp = temp->NextUndergrad;
	}
	delete temp;
    if (kol == 0)
		{
			 Application->MessageBox(String("Студента с такой фамилией нет. Проверте правельность ввода").w_str(), MB_OK);
			 RefreshListBox();
		}
    EditShowByLastName->Text = "";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ListBoxMainMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	List *temp = HandUndergrad;
	AnsiString thisstring = AnsiString(ListBoxMain->Items->Strings[ListBoxMain->ItemIndex]);;
	while(temp != NULL && temp->Undergrad.ShowStudents() != thisstring)
	{
		temp = temp->NextUndergrad;
	}
	LabelLastNameM->Caption = temp->Undergrad.lastname;
	LabelNameM->Caption = temp->Undergrad.name;
	LabelFatherNameM->Caption = temp->Undergrad.fathername;
	LabelGruppM->Caption = AnsiString(temp->Undergrad.grupp);
	LabelMaksM->Caption = AnsiString(temp->Undergrad.maks);
	LabelIncomeM->Caption = AnsiString(temp->Undergrad.income);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOpenFileClick(TObject *Sender)
{
	if(OpenFile->Execute())
	{
		students ThisUndergrad;
		TFileStream* fs=new TFileStream(OpenFile->FileName, fmOpenRead);
		fs->Read(&numOfStudents, sizeof(numOfStudents));
		HandUndergrad = NULL;
		for(int i = 0; i < numOfStudents; i++)
		{
			fs->Read(&ThisUndergrad, sizeof(students));
			if(i == 0)
			{
				LastUndergrad = new List;
				HandUndergrad= LastUndergrad;
			}
			else
			{
				LastUndergrad->NextUndergrad = new List;
				LastUndergrad = LastUndergrad->NextUndergrad;
			}
			LastUndergrad->Undergrad = ThisUndergrad ;
			LastUndergrad->NextUndergrad = NULL;
		}
		delete fs;
		RefreshListBox();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSaveFileClick(TObject *Sender)
{
	 if(OpenFile->Execute())
	{
		List* temp = HandUndergrad;
		TFileStream* fs=new TFileStream(OpenFile->FileName, fmCreate);
		fs->Write(&numOfStudents, sizeof(numOfStudents));
		for(int i = 0; i < numOfStudents; i++)
		{
			fs->Write(&(temp->Undergrad), sizeof(students));
			temp = temp->NextUndergrad;
		}
		delete temp;
		delete fs;
	}
}



