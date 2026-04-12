//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PregledFilmova.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include "DataTypes.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include "Jezik_INI.h"
#include "omiljeniFilmovi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSviFilmovi *FormSviFilmovi;
//---------------------------------------------------------------------------
__fastcall TFormSviFilmovi::TFormSviFilmovi(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TFormSviFilmovi::OsvjeziListu()
{
    _di_IXMLfilmoviType OFilmovi = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    listViewOFilmovi->Items->Clear();
    for(int i = 0; i < OFilmovi->Count; i++){
        TListItem *item = listViewOFilmovi->Items->Add();
        item->Caption = OFilmovi->film[i]->naslov;
        item->SubItems->Add(IntToStr(OFilmovi->film[i]->godina));
        item->SubItems->Add(IntToStr(OFilmovi->film[i]->trajanje));
        item->SubItems->Add(OFilmovi->film[i]->opis);
    }
}

void __fastcall TFormSviFilmovi::OcistiPolja()
{
    EditNoviNaziv->Text = "";
    EditNovaGodina->Text = "";
    EditNovoTrajanje->Text = "";
    MemoOpisNovogFilma->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFormSviFilmovi::FormCreate(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	FormSviFilmovi->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");

	ini->WriteString("HR", "label6", Label6->Caption);
	ini->WriteString("HR", "label7", Label7->Caption);
	ini->WriteString("HR", "ButtonDodajWatchlistu", ButtonDodajWatchlistu->Caption);
	ini->WriteString("HR", "ButtonOmiljeniFilmovi", ButtonOmiljeniFilmovi->Caption);

	ini->WriteString("ENG", "label6", "Movie name:");
	ini->WriteString("ENG", "label7", "Year: ");
	ini->WriteString("ENG", "ButtonDodajWatchlistu", "Add");
	ini->WriteString("ENG", "ButtonOmiljeniFilmovi", "Favourite movies");
	//GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");

	delete ini;

	int w = listViewOFilmovi->Width;
	listViewOFilmovi->Columns->Items[0]->Width = w * 2 / 16;  // naslov
	listViewOFilmovi->Columns->Items[1]->Width = w * 1.5 / 16;  // godina
	listViewOFilmovi->Columns->Items[2]->Width = w * 1.5 / 16;  // trajanje
	listViewOFilmovi->Columns->Items[3]->Width = w * 11 / 16;  // opis
}
//---------------------------------------------------------------------------



void __fastcall TFormSviFilmovi::ButtonOmiljeniFilmoviClick(TObject *Sender)
{

	/*// Ili iz TBytes (ako imaš poster kao byte array)
	TMemoryStream *stream = new TMemoryStream();
	stream->Write(film.poster.get(), film.poster.Length);
	stream->Position = 0;
	Image1->Picture->LoadFromStream(stream);
	delete stream;  */

	OsvjeziListu();
}
//---------------------------------------------------------------------------


void __fastcall TFormSviFilmovi::ButtonHRVClick(TObject *Sender)
{
	PostaviJezik(this, "HR");
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonENGClick(TObject *Sender)
{
	PostaviJezik(this, "ENG");
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonDodajNoviOFilmClick(TObject *Sender)
{
	// doadavanje novih



	_di_IXMLfilmoviType OFilm = Getfilmovi(XMLDocumentOmiljeniFilmovi);
	_di_IXMLfilmType NoviOFilm = OFilm->Add();
	int noviId = OFilm->Count > 0 ? OFilm->film[OFilm->Count - 1]->id + 1 : 1;

    Film *noviFilm = new Film(
		noviId,
		EditNoviNaziv->Text,
		StrToInt(EditNovaGodina->Text),
		StrToInt(EditNovoTrajanje->Text),
		MemoOpisNovogFilma->Text
	);

	NoviOFilm->naslov 	= noviFilm->GetNaslov();
	NoviOFilm->godina 	= noviFilm->GetGodina();
	NoviOFilm->trajanje = noviFilm->GetTrajanje();
	NoviOFilm->opis 	= noviFilm->GetOpis();

    delete noviFilm;
	XMLDocumentOmiljeniFilmovi->SaveToFile(XMLDocumentOmiljeniFilmovi->FileName);
    OcistiPolja();
	OsvjeziListu();

}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonUkloniClick(TObject *Sender)
{
	//ukloni
	String PorukaUpozorenja = "Odaberi film za uklanjanje!";
    if(listViewOFilmovi->Selected == NULL){
		ShowMessage(PorukaUpozorenja);
		return;
	}

	_di_IXMLfilmoviType OFilm = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    OFilm->Delete(listViewOFilmovi->ItemIndex);
	XMLDocumentOmiljeniFilmovi->SaveToFile(XMLDocumentOmiljeniFilmovi->FileName);

	//listViewOFilmovi->Items->Delete(listViewOFilmovi->ItemIndex);
    OsvjeziListu();
}
//---------------------------------------------------------------------------

