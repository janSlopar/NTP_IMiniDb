//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recenzija.h"
#include "DataTypes.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include <System.JSON.Readers.hpp>
#include <System.JSON.Writers.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRecenzija *FormRecenzija;
//---------------------------------------------------------------------------
__fastcall TFormRecenzija::TFormRecenzija(TComponent* Owner)
    : TForm(Owner), editIndex(-1)
{
}
//---------------------------------------------------------------------------
void TFormRecenzija::UcitajFilmoveUCombo()
{
    cmbFilm->Items->Clear();
    cmbFilm->Items->Add("---- Nova recenzija ----");

    String putanja = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\recenzija.json");
    if (!TFile::Exists(putanja)) return;

    TStringList *sl = new TStringList();
    sl->LoadFromFile(putanja, TEncoding::UTF8);
    TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
    delete sl;

    if (root && root->ClassNameIs("TJSONArray")) {
        TJSONArray *arr = static_cast<TJSONArray*>(root);
        for (int i = 0; i < arr->Count; i++) {
            TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[i]);
            cmbFilm->Items->Add(obj->GetValue("film")->Value());
        }
        delete root;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::FormCreate(TObject *Sender)
{
    String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");

    TIniFile *ini = new TIniFile(path);
    FormRecenzija->StyleName     = ini->ReadString("Stilovi", "stil1", "Obsidian");
    StyleName                    = ini->ReadString("Stilovi", "stil1", "Obsidian");
    GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");
    delete ini;

    UcitajFilmoveUCombo();
    cmbFilm->ItemIndex = 0;
    editIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormRecenzija::ButtonSpremiRecenzijuClick(TObject *Sender)
{
    if (memTekst->Lines->Text.Trim().IsEmpty()) {
        ShowMessage("Tekst recenzije ne smije biti prazan!");
        return;
    }

    String putanja = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\recenzija.json");

    // ── MOD EDITIRANJA ────────────────────────────────────────────────────────
    if (editIndex >= 0) {
        if (MessageDlg("Sigurno zelis izmijeniti ovu recenziju?",
                mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
            return;

        try {
            TStringList *sl = new TStringList();
            sl->LoadFromFile(putanja, TEncoding::UTF8);
            TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
            delete sl;

            TJSONArray  *arr = static_cast<TJSONArray*>(root);
            TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[editIndex]);

            obj->RemovePair("ocjena"); obj->AddPair("ocjena", new TJSONNumber(TrackBarOcjena->Position));
            obj->RemovePair("tekst");  obj->AddPair("tekst",  memTekst->Lines->Text.Trim());
            obj->RemovePair("datum");  obj->AddPair("datum",  FormatDateTime("yyyy-mm-dd", dtpDatum->Date));

            TFileStream *fs = new TFileStream(putanja, fmCreate);
            TBytes bytes = TEncoding::UTF8->GetBytes(arr->ToString());
            fs->WriteBuffer(&bytes[0], bytes.Length);
            delete fs;
            delete root;

            ShowMessage("Recenzija uspjesno izmijenjena!");
            UcitajFilmoveUCombo();
            cmbFilm->ItemIndex = 0;
            cmbFilmChange(nullptr);
            ModalResult = mrOk;

        } catch (Exception &e) {
            ShowMessage(e.Message);
        }
        return;
    }

    // ── MOD NOVOG UNOSA ───────────────────────────────────────────────────────
    if (edtFilm->Text.Trim().IsEmpty()) {
        ShowMessage("Naziv filma ne smije biti prazan!");
        return;
    }

    try {
        TJSONArray *jsonArray = new TJSONArray();

        if (TFile::Exists(putanja)) {
            TStringList *sl = new TStringList();
            sl->LoadFromFile(putanja, TEncoding::UTF8);
            String sadrzaj = sl->Text.Trim();
            delete sl;

            if (!sadrzaj.IsEmpty()) {
                TJSONValue *parsiran = TJSONObject::ParseJSONValue(sadrzaj);

                if (parsiran && parsiran->ClassNameIs("TJSONArray")) {
                    TJSONArray *postojeciArray = static_cast<TJSONArray*>(parsiran);

                    for (int i = 0; i < postojeciArray->Count; i++) {
                        TJSONObject *obj = static_cast<TJSONObject*>(postojeciArray->Items[i]);

                        if (obj->GetValue("film")->Value() == edtFilm->Text.Trim()) {
                            ShowMessage("Recenzija za ovaj film vec postoji!\nOdaberi ga iz padajuceg izbornika za uredivanje.");
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

        TJSONObject *rec = new TJSONObject();
        rec->AddPair("film",   edtFilm->Text.Trim());
        rec->AddPair("ocjena", new TJSONNumber(TrackBarOcjena->Position));
        rec->AddPair("tekst",  memTekst->Lines->Text.Trim());
        rec->AddPair("datum",  FormatDateTime("yyyy-mm-dd", dtpDatum->Date));

        jsonArray->AddElement(rec);

        String jsonString = jsonArray->ToString();
        TFileStream *fs = new TFileStream(putanja, fmCreate);
        TBytes bytes = TEncoding::UTF8->GetBytes(jsonString);
        fs->WriteBuffer(&bytes[0], bytes.Length);
        delete fs;
        delete jsonArray;

        ShowMessage("Recenzija uspjesno spremljena!");
        UcitajFilmoveUCombo();
        cmbFilm->ItemIndex = 0;
        cmbFilmChange(nullptr);
        ModalResult = mrOk;

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }

	/*
    ADOQuery1->SQL->Text =
    "INSERT INTO Recenzije (IDRecenzije, Tekst, Ocjena, Datum, FilmID, KorisnikID) "
    "VALUES (:id, :tekst, :ocjena, :datum, :filmid, :korisnikid)";

	ADOQuery1->Parameters->ParamByName("id")->Value         = idRecenzije;
	ADOQuery1->Parameters->ParamByName("tekst")->Value      = tekst;
	ADOQuery1->Parameters->ParamByName("ocjena")->Value     = ocjena;
	ADOQuery1->Parameters->ParamByName("datum")->Value      = datum;
	ADOQuery1->Parameters->ParamByName("filmid")->Value     = filmID;
	ADOQuery1->Parameters->ParamByName("korisnikid")->Value = korisnikID;
	ADOQuery1->ExecSQL();
    */
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::ButtonOdustaniClick(TObject *Sender)
{
    cmbFilm->ItemIndex = 0;
    cmbFilmChange(nullptr);
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::cmbFilmChange(TObject *Sender)
{
    if (cmbFilm->ItemIndex <= 0) {
        editIndex = -1;
        edtFilm->Enabled = true;
        edtFilm->Clear();
        memTekst->Clear();
        TrackBarOcjena->Position = 5;
        dtpDatum->Date = Now();
        ButtonSpremiRecenziju->Caption = "Spremi recenziju";
        return;
    }

    editIndex = cmbFilm->ItemIndex - 1;

    String putanja = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\recenzija.json");
    TStringList *sl = new TStringList();
    sl->LoadFromFile(putanja, TEncoding::UTF8);
    TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
    delete sl;

    if (root && root->ClassNameIs("TJSONArray")) {
        TJSONArray  *arr = static_cast<TJSONArray*>(root);
        TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[editIndex]);

        edtFilm->Text            = obj->GetValue("film")->Value();
        edtFilm->Enabled         = false;
        memTekst->Lines->Text    = obj->GetValue("tekst")->Value();
        TrackBarOcjena->Position = StrToIntDef(obj->GetValue("ocjena")->Value(), 5);
        dtpDatum->Date           = StrToDateDef(obj->GetValue("datum")->Value(), Now());
        ButtonSpremiRecenziju->Caption = "Izmijeni recenziju";

        delete root;
    }
}
//---------------------------------------------------------------------------

