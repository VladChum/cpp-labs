//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TTreeView *TreeView1;
	TStringGrid *StringGrid1;
	TLabel *Label1;
	TEdit *EditSecondName;
	TLabel *Label2;
	TEdit *EditNumber;
	TMemo *Memo1;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *ButtonExit;
	TButton *ButtonDelete;
	TButton *ButtonAddClick;
	TButton *ButtonScan;
	TButton *ButtonBalansing;
	TButton *ButtonMidl;
	void __fastcall ButtonAddClickClick(TObject *Sender);
	void __fastcall ButtonScanClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonBalansingClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall ButtonMidlClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
