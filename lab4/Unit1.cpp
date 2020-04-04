#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Steck.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Stack St;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonToSolveClick(TObject *Sender)
{
  St.Stack_init();
  AnsiString ed_txt = EditForEx->Text;
  St.s = ed_txt.c_str();
  St.check();
  if(St.err_code==all_true)
  {
	  St.bspaces();
	  St.s = St.sv;
	  St.postfix();
	  EditTranslated->Text=St.s;
  }
  St.s = ed_txt.c_str();
  if(St.err_code==all_true)
  {
	  St.bspaces();
	  St.s = St.sv;
	  St.postfix();
	  EditTranslated->Text=St.s;
	  float result=St.calc(StrToFloat(EditA->Text), StrToFloat(EditB->Text), StrToFloat(EditC->Text), StrToFloat(EditD->Text), StrToFloat(EditE->Text));
	  EditAnswer->Text=FloatToStr(result);
  }
  else
  St.out_err_code();
}
//---------------------------------------------------------------------------

void Stack::out_err_code()
{
   switch(err_code)
   {
		case all_true: {ShowMessage("���� ���������."); break;}
		case bad_operands: {ShowMessage("� ��������� ���� �������� ��������!"); break;}
		case few_brackets: {ShowMessage("� ��������� �� ������� ������!"); break;}
		case much_brackets: {ShowMessage("� ��������� ������ ������!"); break;}
		case few_operands: {ShowMessage("� ��������� ������������ ���������!"); break;}
		case few_operators: {ShowMessage("� ��������� ������������ ������ ��������!"); break;}
   };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   EditForEx->Text="";
   EditAnswer->Text="";
   EditTranslated->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClearClick(TObject *Sender)
{
   EditForEx->Text="";
   EditAnswer->Text="";
   EditTranslated->Text="";
   EditA->Text="";
   EditB->Text="";
   EditC->Text="";
   EditD->Text="";
   EditE->Text="";
}
//---------------------------------------------------------------------------




