//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TEdit *EditForEx;
	TButton *ButtonToSolve;
	TEdit *EditTranslated;
	TButton *ButtonClear;
	TButton *ButtonExit;
	TEdit *EditAnswer;
	TLabel *LabelTranslated;
	TLabel *LabelAnswer;
	TLabel *LabelExercise;
	TEdit *EditA;
	TLabel *LabelA;
	TEdit *EditB;
	TLabel *LabelB;
	TEdit *EditC;
	TLabel *LabelC;
	TEdit *EditD;
	TLabel *LabelD;
	TEdit *EditE;
	TLabel *LabelE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonToSolveClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);

private:
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
