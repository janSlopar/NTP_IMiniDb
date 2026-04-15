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
#include <System.JSON.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSviFilmovi *FormSviFilmovi;
//---------------------------------------------------------------------------
/*
	 TO-DO
	 - Editiranje naslova, godine, trajanja ili opisa filma uz upozorenje
	   (pop-up ping !!!) prilikom potvrde. -> za zadatak JSON / XML
	 - ...
	 - Ljepše formuliraj objašnjenja u prijavnici

     Što trebaš implementirati (CRUD)
	OperacijaŠto radiČitanjePrikaži sve recenzije za selektirani film u listViewuPisanjeDodaj novu recenziju (ocjena + komentar + datum)UređivanjePromijeni ocjenu ili komentar postojeće recenzijeBrisanjeUkloni recenziju za selektirani film

	Tok u aplikaciji

	Korisnik selektira film u listViewOFilmovi
	Klikne npr. "Dodaj recenziju" → upiše ocjenu i komentar
	Sprema se u recenzije.json
	Može pregledavati, mijenjati ili brisati recenzije


	Zašto ovo prolazi Napomenu 2

	XML → struktura Film (naslov, godina, trajanje, opis)
	JSON → struktura Recenzija (film_naslov, ocjena, komentar, datum)

	To su potpuno različiti entiteti, što je upravo ono što ocjenjivač traži. Uz potpuni CRUD na oba, realno gledaš 7–8 bodova.

*/
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
    LabelOmiljeniFilmoviNaslov->Visible = false;
	LabelListaZaGledanje->Visible = false;

	String path = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(path);

	FormSviFilmovi->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");

	ini->WriteString("HR", "ButtonDodajNoviOFilm", ButtonDodajNoviOFilm->Caption);
    ini->WriteString("HR", "ButtonUkloni", ButtonUkloni->Caption);
	ini->WriteString("HR", "ButtonDodajWatchlistu", ButtonDodajWatchlistu->Caption);
	ini->WriteString("HR", "ButtonOmiljeniFilmovi", ButtonOmiljeniFilmovi->Caption);

	ini->WriteString("ENG", "label6", "Movie name");
	ini->WriteString("ENG", "label7", "Year");
	ini->WriteString("ENG", "label8", "Duration");
	ini->WriteString("ENG", "label9", "Plot");
	ini->WriteString("ENG", "ButtonDodajNoviOFilm", "Add to Favourites");
	ini->WriteString("ENG", "ButtonUkloni", "Remove from Favourites");
	ini->WriteString("ENG", "ButtonDodajWatchlistu", "Add to Watchlist");
	ini->WriteString("ENG", "ButtonOmiljeniFilmovi", "Favourite movies");
	//GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");

	ButtonDodajNoviOFilm->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonDodajWatchlistu->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonOmiljeniFilmovi->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonPregledajListu->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonUkloni->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonHRV->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonENG->StyleName = ini->ReadString("Stilovi", "stil2", "0");

    ini->WriteString("HR", "LabelOmiljeniFilmoviNaslov", "Omiljeni Filmovi");
	ini->WriteString("HR", "LabelListaZaGledanje", "Lista za gledanje");
	ini->WriteString("ENG", "LabelOmiljeniFilmoviNaslov", "Favourite Movies");
	ini->WriteString("ENG", "LabelListaZaGledanje", "Watchlist");


	delete ini;

	int w = listViewOFilmovi->Width;
	listViewOFilmovi->Columns->Items[0]->Width = w * 2 / 16;  // naslov
	listViewOFilmovi->Columns->Items[1]->Width = w * 1.5 / 16;  // godina
	listViewOFilmovi->Columns->Items[2]->Width = w * 1.5 / 16;  // trajanje
	listViewOFilmovi->Columns->Items[3]->Width = w * 11 / 16;  // opis

	LabelOmiljeniFilmoviNaslov->Font->Size    = 16;
	LabelOmiljeniFilmoviNaslov->Font->Style   = TFontStyles() << fsBold;
	LabelOmiljeniFilmoviNaslov->Font->Color   = (TColor)0x00FFD700;
	LabelOmiljeniFilmoviNaslov->Alignment     = taCenter;
	LabelOmiljeniFilmoviNaslov->Transparent   = true;

    LabelListaZaGledanje->Font->Size  = 16;
	LabelListaZaGledanje->Font->Style = TFontStyles() << fsBold;
	LabelListaZaGledanje->Font->Color = (TColor)0x00FFD700;
	LabelListaZaGledanje->Alignment   = taCenter;
	LabelListaZaGledanje->Transparent = true;
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
	LabelOmiljeniFilmoviNaslov->Visible = true;
	LabelListaZaGledanje->Visible = false;
	OsvjeziListu();
}
//---------------------------------------------------------------------------


void __fastcall TFormSviFilmovi::ButtonHRVClick(TObject *Sender)
{
	PostaviJezik(this, "HR");
	String path = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(path);

    LabelOmiljeniFilmoviNaslov->Caption = ini->ReadString("HR", "LabelOmiljeniFilmoviNaslov", "Omiljeni Filmovi");
	(*listViewOFilmovi->Columns)[0]->Caption = ini->ReadString("HR", "label6", "");
	(*listViewOFilmovi->Columns)[1]->Caption = ini->ReadString("HR", "label7", "");
	(*listViewOFilmovi->Columns)[2]->Caption = ini->ReadString("HR", "label8", "");
	(*listViewOFilmovi->Columns)[3]->Caption = ini->ReadString("HR", "label9", "");


	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonENGClick(TObject *Sender)
{
	PostaviJezik(this, "ENG");
	String path = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(path);

	(*listViewOFilmovi->Columns)[0]->Caption = ini->ReadString("ENG", "label6", "");
	(*listViewOFilmovi->Columns)[1]->Caption = ini->ReadString("ENG", "label7", "");
	(*listViewOFilmovi->Columns)[2]->Caption = ini->ReadString("ENG", "label8", "");
	(*listViewOFilmovi->Columns)[3]->Caption = ini->ReadString("ENG", "label9", "");


	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonDodajNoviOFilmClick(TObject *Sender)
{

	_di_IXMLfilmoviType OFilm = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    int noviId = OFilm->Count > 0 ? OFilm->film[OFilm->Count - 1]->id + 1 : 1;
	_di_IXMLfilmType NoviOFilm = OFilm->Add();


    Film *noviFilm = new Film(
		noviId,
		EditNoviNaziv->Text,
		StrToInt(EditNovaGodina->Text),
		StrToInt(EditNovoTrajanje->Text),
		MemoOpisNovogFilma->Text
	);

    NoviOFilm->id       = noviId;
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
    OcistiPolja();
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonDodajWatchlistuClick(TObject *Sender)
{
    if (listViewOFilmovi->Selected == NULL) {
        ShowMessage("Odaberi film za dodavanje na listu!\nSelect a movie to add to the watchlist!");
        return;
    }

    TListItem *selektiraniItem = listViewOFilmovi->Selected;
    String naslov   = selektiraniItem->Caption;
    String godina   = selektiraniItem->SubItems->Strings[0];
    String trajanje = selektiraniItem->SubItems->Strings[1];
    String opis     = selektiraniItem->SubItems->Strings[2];

	String jsonPath = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\listZaGledanje.json");

	// DEBUG -  path
	//ShowMessage("Path: " + jsonPath);

    try {
        TJSONArray *jsonArray = new TJSONArray();

        if (TFile::Exists(jsonPath)) {
            TStringList *sl = new TStringList();
            sl->LoadFromFile(jsonPath, TEncoding::UTF8);
            String sadrzaj = sl->Text.Trim();
            delete sl;

			//ShowMessage("Sadrzaj filea: " + sadrzaj); // DEBUG

            if (!sadrzaj.IsEmpty()) {
                TJSONValue *parsiran = TJSONObject::ParseJSONValue(sadrzaj);
                if (parsiran && parsiran->ClassNameIs("TJSONArray")) {
                    TJSONArray *postojeciArray = static_cast<TJSONArray*>(parsiran);
                    for (int i = 0; i < postojeciArray->Count; i++) {
                        TJSONObject *obj = static_cast<TJSONObject*>(postojeciArray->Items[i]);
                        if (obj->GetValue("naslov")->Value() == naslov) {
                            ShowMessage("Film je već na listi!\nMovie is already on the watchlist!");
                            delete jsonArray;
                            delete parsiran;
                            return;
                        }
                    }
                    delete jsonArray;
                    jsonArray = postojeciArray;
                } else {
                    delete parsiran;
                }
            }
        }

        TJSONObject *noviFilm = new TJSONObject();
        noviFilm->AddPair("naslov",   naslov);
        noviFilm->AddPair("godina",   godina);
        noviFilm->AddPair("trajanje", trajanje);
        noviFilm->AddPair("opis",     opis);
        jsonArray->AddElement(noviFilm);

        String jsonString = jsonArray->ToString();
        //ShowMessage("Zapisujem: " + jsonString); // DEBUG - vidi sto zapisuje

        TFileStream *fs = new TFileStream(jsonPath, fmCreate);
        TEncoding *enc = TEncoding::UTF8;
        TBytes bytes = enc->GetBytes(jsonString);
        fs->WriteBuffer(&bytes[0], bytes.Length);
        delete fs;

        delete jsonArray;

      	ShowMessage("Uspješno dodano!\nSuccessfully added!");

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonPregledajListuClick(TObject *Sender)
{
    LabelOmiljeniFilmoviNaslov->Visible = false;
	LabelListaZaGledanje->Visible = true;

	String jsonPath = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\listZaGledanje.json");

    if (!TFile::Exists(jsonPath)) {
		ShowMessage("Lista je prazna!\nList is empty!");
        return;
	}

    try {
        TStringList *sl = new TStringList();
        sl->LoadFromFile(jsonPath, TEncoding::UTF8);
        String sadrzaj = sl->Text.Trim();
        delete sl;

        if (sadrzaj.IsEmpty()) {
			ShowMessage("Lista je prazna!\nList is empty!");
            return;
        }

		TJSONValue *parsiran = TJSONObject::ParseJSONValue(sadrzaj);
		if (!parsiran || !parsiran->ClassNameIs("TJSONArray")) {
			ShowMessage("Greška pri čitanju watchliste!\nError reading watchlist!");
			delete parsiran;
            return;
        }

        TJSONArray *jsonArray = static_cast<TJSONArray*>(parsiran);

        listViewOFilmovi->Items->Clear();

        for (int i = 0; i < jsonArray->Count; i++) {
            TJSONObject *obj = static_cast<TJSONObject*>(jsonArray->Items[i]);

            TListItem *item = listViewOFilmovi->Items->Add();
            item->Caption = obj->GetValue("naslov")->Value();
            item->SubItems->Add(obj->GetValue("godina")->Value());
            item->SubItems->Add(obj->GetValue("trajanje")->Value());
            item->SubItems->Add(obj->GetValue("opis")->Value());
        }

        delete parsiran;

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormSviFilmovi::listViewOFilmoviSelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
    if (!Selected || Item == nullptr) return;

    int idx = listViewOFilmovi->ItemIndex;
    if (idx < 0) return;

    _di_IXMLfilmoviType OFilmovi = Getfilmovi(XMLDocumentOmiljeniFilmovi);

    if (idx >= OFilmovi->Count) return;

    EditNoviNaziv->Text      = OFilmovi->film[idx]->naslov;
    EditNovaGodina->Text     = IntToStr(OFilmovi->film[idx]->godina);
    EditNovoTrajanje->Text   = IntToStr(OFilmovi->film[idx]->trajanje);
    MemoOpisNovogFilma->Text = OFilmovi->film[idx]->opis;

    // Poster - provjeri je li prazan
	/*
    IXMLNode *posterNode = film->ChildNodes->FindNode("poster");
    if (posterNode != nullptr && posterNode->Text != "")
    {
        // npr. učitaj sliku ako imaš TImage
        // Image1->Picture->LoadFromFile(posterNode->Text);
        txtPoster->Text = posterNode->Text;
    }
    else
    {
        txtPoster->Text = "(nema postera)";
    }
	*/
}
//---------------------------------------------------------------------------

