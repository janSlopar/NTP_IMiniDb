//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Registracija.h"
#include "DataTypes.h"
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

/*
bool sadrziBrojeve(String s)
{
    for (int i = 1; i <= s.Length(); i++) {
        if (!IsDigit(s[i])) return false;
    }
    return true;
}
*/

void __fastcall TFormRegistracija::ButtonRegistrirajClick(TObject *Sender)
{
    EditLozinka->PasswordChar = '*';
	Korisnik K_test;

	K_test.setIme(EditIme->Text);
    K_test.setPrezime(EditPrezime->Text);
	K_test.setKorisnickoIme(EditKorIme->Text);
	K_test.setEmail(EditEmail->Text);
    K_test.setLozinka(EditLozinka->Text);

	Application->MessageBoxW("klik Radi!", MB_OK|MB_ICONQUESTION);
	ShowMessage("Pozdrav, " + K_test.getKorIme() + "!");

}
//---------------------------------------------------------------------------


