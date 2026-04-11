//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prijava.h"
#include "DataTypes.h"
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

	// if K_prijava.getKorIme() == baza.korime
	AnsiString KorisnickoIme = EditKorImePrijava->Text;
	AnsiString lozinka = EditLozinkaPrijava->Text;

	if(//podaci isti u bazi
		!KorisnickoIme.IsEmpty() && !lozinka.IsEmpty()){
        	ShowMessage("Uspiješna prijava!");
			ShowMessage("Pozdrav, " + KorisnickoIme + "!");

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

void __fastcall TFormPrijava::ButtonHRVClick(TObject *Sender)
{

	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	Label1->Caption = ini->ReadString("HR", "label1", "");
	Label2->Caption = ini->ReadString("HR", "label2", "");
	ButtonPrijava->Caption = ini->ReadString("HR", "ButtonPrijava", "");

	delete ini;

}
//---------------------------------------------------------------------------


void __fastcall TFormPrijava::ButtonENGClick(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	TIniFile* ini = new TIniFile(path);

	Label1->Caption = ini->ReadString("ENG", "label1", "");
	Label2->Caption = ini->ReadString("ENG", "label2", "");
	ButtonPrijava->Caption = ini->ReadString("ENG", "ButtonPrijava", "");

	delete ini;
}
//---------------------------------------------------------------------------

