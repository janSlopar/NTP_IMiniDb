//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prijava.h"
#include "DataTypes.h"
#include "Jezik_INI.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
__fastcall TFormPrijava::TFormPrijava(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonPrijavaClick(TObject *Sender)
{
 	EditLozinkaPrijava->PasswordChar = '*';
	Korisnik K_prijava;

	AnsiString korisnickoIme = EditKorImePrijava->Text;
	AnsiString lozinka = EditLozinkaPrijava->Text;

	if (korisnickoIme.IsEmpty() || lozinka.IsEmpty()) {
        ShowMessage("Unesite korisničko ime i lozinku.");
        return;
    }

    try {
		FDQueryPrijava->Close();
		FDQueryPrijava->SQL->Clear();
		FDQueryPrijava->SQL->Add("SELECT COUNT(*) AS Broj FROM korisnik "
                          "WHERE korisnicko_ime = :korIme AND lozinka_hash = :loz");
		FDQueryPrijava->ParamByName("korIme")->AsString = korisnickoIme;
		FDQueryPrijava->ParamByName("loz")->AsString    = lozinka;
		FDQueryPrijava->Open();

		if (FDQueryPrijava->FieldByName("Broj")->AsInteger == 1) {
            ShowMessage("Uspješna prijava!\nPozdrav, " + korisnickoIme + "!");

            // ovdje otvori glavnu formu, sakrij prijavu itd.
        } else {
            ShowMessage("Neispravno korisničko ime ili lozinka.");
        }

		FDQueryPrijava->Close();
    }
    catch (Exception &e) {
        ShowMessage("Greška pri spajanju na bazu: " + e.Message);
    }

}
//---------------------------------------------------------------------------


void __fastcall TFormPrijava::FormCreate(TObject *Sender)
{

	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	FormPrijava->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");
	GroupBoxPrijava->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");



	delete ini;

}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonHRVClick(TObject *Sender) { PostaviJezik(this, "HR"); }
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonENGClick(TObject *Sender){ PostaviJezik(this, "ENG"); }
//---------------------------------------------------------------------------

