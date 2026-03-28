//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prijava.h"
#include "DataTypes.h"
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


