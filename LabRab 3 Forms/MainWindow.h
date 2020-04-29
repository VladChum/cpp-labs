//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "students.cpp"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
	TListBox *ListBoxMain;
	TButton *ButtonExit;
	TButton *ButtonShowAllOK;
	TButton *ButtonShowByIncomeTwoOK;
	TEdit *EditShowByIncomeTwo;
	TLabel *LabelShowAll;
	TLabel *LabelShowBySecondName;
	TLabel *LabelShowByExp;
	TEdit *EditShowByIncome;
	TButton *ButtonShowByIncomeOK;
	TEdit *EditShowByLastName;
	TLabel *LabelShowByLastName;
	TButton *ButtonShowByLastNameOK;
	TLabel *LabelEmployee;
	TEdit *EditLastName;
	TEdit *EditName;
	TEdit *EditFatherName;
	TEdit *EditGrupp;
	TEdit *EditMaks;
	TButton *ButtonDelete;
	TButton *ButtonAdd;
	TButton *ButtonAddOK;
	TEdit *EditIncome;
	TLabel *LabelLastName;
	TLabel *LabelName;
	TLabel *LabelFatherName;
	TLabel *LabelGroup;
	TLabel *LabelMaks;
	TLabel *IncomePerson;
	TLabel *LabelLastNameM;
	TLabel *LabelNameM;
	TLabel *LabelFatherNameM;
	TLabel *LabelMaksM;
	TLabel *LabelGruppM;
	TLabel *LabelIncomeM;
	TButton *ButtonOpenFile;
	TButton *ButtonSaveFile;
	TOpenDialog *OpenFile;
	TSaveDialog *SaveFile;
	TLabel *Label1;
	TEdit *EditShowByMaks;
	void __fastcall ButtonAddOKClick(TObject *Sender);
	void __fastcall ButtonShowByIncomeTwoOKClick(TObject *Sender);
	void __fastcall ButtonShowByIncomeOKClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonShowAllOKClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonShowByLastNameOKClick(TObject *Sender);
	void __fastcall ListBoxMainMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall ButtonOpenFileClick(TObject *Sender);
	void __fastcall ButtonSaveFileClick(TObject *Sender);
private:
public:
	struct List
	{
		students Undergrad;
		List *NextUndergrad;
	};
	List *HandUndergrad, *LastUndergrad;
	int numOfStudents;
	int newid;

	__fastcall TForm1(TComponent* Owner);
	bool IsEmptyEdit();
	void RefreshListBox();
	void VisibleEdits();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
