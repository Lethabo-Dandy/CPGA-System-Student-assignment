//---------------------------------------------------------------------------

#include <vcl.h>
#include <jpeg.hpp>

#pragma hdrstop

#include "StudAssignments_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAssignm *frmAssignm;
//---------------------------------------------------------------------------
__fastcall TfrmAssignm::TfrmAssignm(TComponent* Owner): TForm(Owner)
{
	//array for 6 students
	for (int i = 0; i < 6; i++)
		arrScores[i] = 0;           //declare the scores to 0


	//instantiate a string list for the assignments scores
	dataList = new TStringList(this);
}
//-----------------------------------------------------------------------
void __fastcall TfrmAssignm::FormShow(TObject *Sender)
{
	//clear the average caption to make it invisible
	lblAverage->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TfrmAssignm::btnReadClick(TObject *Sender)
{
	//upload the assignments scores into the data list then into the list box
	dataList->LoadFromFile("..\\..\\AssignmData\\Assigns.txt");
	lstResults->Items->LoadFromFile("..\\..\\AssignmData\\Assigns.txt");

	for (int i = 0; i < lstResults->Items->Count; i++)
	{
		AnsiString ln = dataList->Strings[i];

		for (int x = 1; x <= ln.Length(); x++)   // replace with TAB
			if ((ln[x] == '|') || (ln[x] == '#'))
				ln[x] = '\t';
		//Application->ProcessMessages();
		//Sleep(400);
		lstResults->Items->Strings[i] = ln;
		dataList->Strings[i] = ln;

	}
}
//---------------------------------------------------------------------------
AnsiString TfrmAssignm::genStudCode(AnsiString NameSurname)
{
	//a function to generate a student code
	AnsiString lastLett = NameSurname[NameSurname.Length()];
	AnsiString NameSur = NameSurname.UpperCase();
	AnsiString Temp = NameSur[1];

	NameSur = NameSur.Delete(1,NameSur.Pos(" "));
	Temp = Temp + NameSur[1] + lastLett;

	return Temp;
}
//-----------------------------------------------------------------------
AnsiString TfrmAssignm::getStudCode(AnsiString OneDataLine)
{
	//function to get the student code
	OneDataLine = OneDataLine.Delete(1,OneDataLine.Pos("\t"));
	AnsiString Temp = OneDataLine.SubString(1,OneDataLine.Pos("\t")-1);
	return Temp;
}
//----------- Method calcScore() -----------------------------------------
float TfrmAssignm::calcScore(AnsiString OneDataLine)
{
	// Eg: Sam Baloy#SBy|8#8#7#6#7#3  = Sam Baloyi  SBy   8   8   7   6   7   3
	OneDataLine = OneDataLine.Delete(1,OneDataLine.Pos("\t"));
	OneDataLine = OneDataLine.Delete(1,OneDataLine.Pos("\t"));
	AnsiString sTemp = OneDataLine + "\t";

	int i = 0;
	while (sTemp.Pos("\t") > 0)
	{
		arrScores[i] = StrToInt(sTemp.SubString(1,sTemp.Pos("\t")-1));
		sTemp = sTemp.Delete(1,sTemp.Pos("\t"));
		i++;
	}
	float fSum = 0;
	int Lowest = arrScores[0];
	for (int j = 0; j < 6; j++)
	{
		fSum += arrScores[j];
		if (arrScores[j] < Lowest)
			Lowest = arrScores[j];
	}
	return (float(fSum - Lowest) / 5);
}
//-------------------------------------------------------------------------
void __fastcall TfrmAssignm::lstResultsClick(TObject *Sender)
{
	//calculate the average and display the score in pictures
	 AnsiString PicPath = "..\\..\\AssignmData\\UpperAlpha\\";

	 AnsiString CurrListLn = lstResults->Items->Strings[lstResults->ItemIndex];
	 float Scr = calcScore(CurrListLn);
	 lblAverage->Caption = FloatToStrF(Scr,ffFixed,4,2);

	 imgLet1->Stretch = true;
	 imgLet2->Stretch = true;
	 imgLet3->Stretch = true;


	 imgLet1->Picture->LoadFromFile(PicPath
			+ AnsiString(getStudCode(CurrListLn)[1]).UpperCase() + ".jpg");
	 imgLet2->Picture->LoadFromFile(PicPath
			+ AnsiString(getStudCode(CurrListLn)[2]).UpperCase() + ".jpg");
	 imgLet3->Picture->LoadFromFile(PicPath
			+ AnsiString(getStudCode(CurrListLn)[3]).UpperCase() + ".jpg");

}
//------------------------------------------------------------------------
void __fastcall TfrmAssignm::btnBestClick(TObject *Sender)
{
	//displays the best student with the highest average mark
	AnsiString competitorLn;
	AnsiString winnerDetails = lstResults->Items->Strings[0];
	float highScore = calcScore(lstResults->Items->Strings[0]);

	for (int i = 1; i < lstResults->Items->Count; i++)
	{
		competitorLn = lstResults->Items->Strings[i];
		if (highScore < calcScore(competitorLn))
		{
			highScore =  calcScore(competitorLn);
			winnerDetails = competitorLn;
		}
	}
	winnerDetails = winnerDetails.SubString(1, winnerDetails.Pos("\t")-1);
	MessageDlg( "Best candidate is:        >>" + winnerDetails
		+ "<<\nwith an average score of " + FloatToStrF(highScore,ffFixed,4,2)
		+ " (5 best assignments)", mtConfirmation, TMsgDlgButtons()<<mbOK,0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmAssignm::btnSaveResultsToFileClick(TObject *Sender)
{                                        // Use TStreamWriter!
	AnsiString oneLine;
	AnsiString CompFile = "..\\..\\AssignmData\\Assigns(N).txt";
	lstResults->Items->SaveToFile(CompFile);
	ShowMessage("All students written to file.");
}
//--------------------------------------------------------------------------
void __fastcall TfrmAssignm::btnValidateClick(TObject *Sender)
{
	//validate the student code if it's in correspondence with the name and surname
	AnsiString faultyLnNo = "";

	for (int i = 0; i < lstResults->Items->Count; i++)
	{
		AnsiString Ln = lstResults->Items->Strings[i];
		AnsiString name = Ln.SubString(1, Ln.Pos("\t")-1);
		if (genStudCode(name) != getStudCode(Ln))
			faultyLnNo = faultyLnNo + IntToStr(i+1) + ", ";
	}
	edtFaulty->Text = faultyLnNo;
	if (faultyLnNo.Length() > 1)
		pnlFaulty->Visible = true;
}
//---------------------------------------------------------------------------
