//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TLabel *Label1;
	TEdit *Edit1;
	TButton *ButtonAdd;
	TButton *ButtonDelete;
	TButton *ButtonSearch;
	TButton *ButtonMidlValue;
	TMemo *Memo1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *ButtonClose;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ButtonMidlValueClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
