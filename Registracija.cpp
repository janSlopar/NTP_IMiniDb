//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Registracija.h"
#include "DataTypes.h"
#include "Stilovi.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegistracija *FormRegistracija;
//---------------------------------------------------------------------------
__fastcall TFormRegistracija::TFormRegistracija(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistracija::ButtonRegistrirajClick(TObject *Sender)
{
    EditLozinka->PasswordChar = '*';
	Korisnik K_test;

	K_test.setIme(EditIme->Text);
    K_test.setPrezime(EditPrezime->Text);
	K_test.setKorisnickoIme(EditKorIme->Text);
	K_test.setEmail(EditEmail->Text);
	K_test.setLozinka(EditLozinka->Text);

	ShowMessage("Pozdrav, " + K_test.getKorIme() + "!");

}
//---------------------------------------------------------------------------



void __fastcall TFormRegistracija::FormCreate(TObject *Sender)
{

	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	ButtonKonf->StyleName = ini->ReadString("Stilovi", "stil2", "0");

		ini->WriteString("HR", "label1", Label1->Caption);
		ini->WriteString("HR", "label2", Label2->Caption);
		ini->WriteString("HR", "label3", Label3->Caption);
		ini->WriteString("HR", "label4", Label4->Caption);
		ini->WriteString("HR", "label5", Label5->Caption);
		ini->WriteString("HR", "ButtonRegistriraj", ButtonRegistriraj->Caption);
		ini->WriteString("HR", "ButtonKonf", ButtonKonf->Caption);
		ini->WriteString("HR", "ButtonPrijava", "Prijavi se!");

		ini->WriteString("ENG", "label1", "Name:");
		ini->WriteString("ENG", "label2", "Surname:");
		ini->WriteString("ENG", "label3", "Username:");
		ini->WriteString("ENG", "label4", "e-mail:");
		ini->WriteString("ENG", "label5", "password:");
		ini->WriteString("ENG", "ButtonRegistriraj", "Register!");
		ini->WriteString("ENG", "ButtonKonf", "Save config");
		ini->WriteString("ENG", "ButtonPrijava", "Login!");

    delete ini;

	TRegistry* reg = new TRegistry;
	reg->RootKey = HKEY_LOCAL_MACHINE;
	reg->Access = KEY_READ | KEY_WRITE;

	/*
    if (reg->OpenKey("Software\\IMiniDB", true))
	{
		if (!reg->ValueExists("IMiniDB"))
			reg->WriteString("IMiniDB", FormatDateTime("dd.mm.yyyy", today));
		reg->CloseKey();
	}

	if (reg->OpenKey("Software\\IMiniDB\\Broj_otvaranja_apk", true))
	{
		if (!reg->ValueExists("IMiniDB_korisnika"))
			reg->WriteInteger("IMiniDB_korisnika", 0);
		reg->CloseKey();
	}
	  */

	try
	{
		if (reg->OpenKey("Software\\IMiniDB", true))
		{
			if (!reg->ValueExists("IMiniDB"))
				reg->WriteString("IMiniDB", FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()));

			if (!reg->ValueExists("IMiniDB_br_otvaranja"))
				reg->WriteInteger("IMiniDB_br_otvaranja", 0);

			int trenutni = reg->ReadInteger("IMiniDB_br_otvaranja");
			reg->WriteInteger("IMiniDB_br_otvaranja", trenutni + 1);

			reg->CloseKey();
		}
	}
	__finally
	{
		reg->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormRegistracija::ButtonKonfClick(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");

	TIniFile* ini = new TIniFile(path);

	ini->WriteString("Stilovi", "stil1", FormRegistracija->StyleName);
	ini->WriteString("Stilovi", "stil2", GroupBoxRegistracija->StyleName);
	ini->WriteString("Stilovi", "boja1", FormRegistracija->Color);
	ini->WriteString("Stilovi", "zadnja-pohrana", FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()));

	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegistracija::ButtonHRVClick(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	Label1->Caption = ini->ReadString("HR", "label1", "-");
	Label2->Caption = ini->ReadString("HR", "label2", "-");
	Label3->Caption = ini->ReadString("HR", "label3", "-");
	Label4->Caption = ini->ReadString("HR", "label4", "-");
	Label5->Caption = ini->ReadString("HR", "label5", "-");
	ButtonRegistriraj->Caption = ini->ReadString("HR", "ButtonRegistriraj", "-");
	ButtonKonf->Caption = ini->ReadString("HR", "ButtonKonf", "-");

	 delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegistracija::ButtonENGClick(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	Label1->Caption = ini->ReadString("ENG", "label1", "-");
	Label2->Caption = ini->ReadString("ENG", "label2", "-");
	Label3->Caption = ini->ReadString("ENG", "label3", "-");
	Label4->Caption = ini->ReadString("ENG", "label4", "-");
	Label5->Caption = ini->ReadString("ENG", "label5", "-");
	ButtonRegistriraj->Caption = ini->ReadString("ENG", "ButtonRegistriraj", "-");
	ButtonKonf->Caption = ini->ReadString("ENG", "ButtonKonf", "-");

	delete ini;
}
//---------------------------------------------------------------------------

