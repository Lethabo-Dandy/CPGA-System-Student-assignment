//---------------------------------------------------------------------------

#ifndef StudAssignments_uH
#define StudAssignments_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmAssignm : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstResults;
	TLabel *Label9;
	TPanel *pnlCompFinalScore;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *lblAverage;
	TButton *btnBest;
	TButton *btnSaveResultsToFile;
	TButton *btnRead;
	TLabel *Label14;
	TButton *btnValidate;
	TPanel *pnlFaulty;
	TEdit *edtFaulty;
	TLabel *Label1;
	TImage *imgLet1;
	TImage *imgLet2;
	TImage *imgLet3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall lstResultsClick(TObject *Sender);
	void __fastcall btnBestClick(TObject *Sender);
	void __fastcall btnSaveResultsToFileClick(TObject *Sender);
	void __fastcall btnReadClick(TObject *Sender);
	void __fastcall btnValidateClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TfrmAssignm(TComponent* Owner);
	int arrScores[6];
	float calcScore(AnsiString OneDataLine);
    TStringList *dataList;

	AnsiString getStudCode(AnsiString OneDataLine);
	AnsiString genStudCode(AnsiString NameSurname);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAssignm *frmAssignm;
//---------------------------------------------------------------------------
#endif
