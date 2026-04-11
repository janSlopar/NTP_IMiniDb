//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recenzija.h"
#include "DataTypes.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRecenzija *FormRecenzija;
//---------------------------------------------------------------------------
__fastcall TFormRecenzija::TFormRecenzija(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::ButtonSpremiClick(TObject *Sender)
{
	if (memTekst->Lines->Text.IsEmpty() ||
		edtFilmID->Text.IsEmpty() 		||
		edtKorisnikID->Text.IsEmpty())
	{
        ShowMessage("Molimo ispunite sva obavezna polja!");
		return;
	}

	//int idRecenzije   = iz baze +1
	String tekst      = memTekst->Lines->Text;
    int ocjena 		  = TrackBarOcjena->Position;
	TDateTime datum   = dtpDatum->Date;
    int filmID        = StrToInt(edtFilmID->Text);
    int korisnikID    = StrToInt(edtKorisnikID->Text);

	ShowMessage("Recenzija uspješno spremljena!");

	/*

    ADOQuery1->SQL->Text =
    "INSERT INTO Recenzije (IDRecenzije, Tekst, Ocjena, Datum, FilmID, KorisnikID) "
    "VALUES (:id, :tekst, :ocjena, :datum, :filmid, :korisnikid)";

	ADOQuery1->Parameters->ParamByName("id")->Value       = idRecenzije;
	ADOQuery1->Parameters->ParamByName("tekst")->Value    = tekst;
	ADOQuery1->Parameters->ParamByName("ocjena")->Value   = ocjena;
	ADOQuery1->Parameters->ParamByName("datum")->Value    = datum;
	ADOQuery1->Parameters->ParamByName("filmid")->Value   = filmID;
	ADOQuery1->Parameters->ParamByName("korisnikid")->Value = korisnikID;

	ADOQuery1->ExecSQL();

    */
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::ButtonOdustaniClick(TObject *Sender)
{
    memTekst->Clear();
    dtpDatum->Date = Now();
    edtFilmID->Clear();
	edtKorisnikID->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::FormCreate(TObject *Sender)
{
 	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");

	TIniFile* ini = new TIniFile(path);

	FormRecenzija->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");
	GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");

	delete ini;
}
//---------------------------------------------------------------------------

