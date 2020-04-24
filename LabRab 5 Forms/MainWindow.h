//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TEdit *EditInput;
	TButton *ButtonOK;
	TLabel *Label1;
	TListBox *ListBox;
	TButton *ButtonRandom;
	TLabel *Label2;
	TListBox *ListBoxFirst;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditMin;
	TEdit *EditMax;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall ButtonOKClick(TObject *Sender);
	void __fastcall ButtonRandomClick(TObject *Sender);
private:
public:
	void ShowOnListBox();
	void InTwoCircle(List *InputQueue);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
