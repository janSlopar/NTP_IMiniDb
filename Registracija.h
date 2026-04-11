//---------------------------------------------------------------------------

#ifndef RegistracijaH
#define RegistracijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormRegistracija : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBoxRegistracija;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditIme;
	TEdit *EditPrezime;
	TLabel *Label3;
	TEdit *EditKorIme;
	TLabel *Label4;
	TEdit *EditEmail;
	TLabel *Label5;
	TEdit *EditLozinka;
	TButton *ButtonRegistriraj;
	TButton *ButtonKonf;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	void __fastcall ButtonRegistrirajClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonKonfClick(TObject *Sender);
	void __fastcall ButtonHRVClick(TObject *Sender);
	void __fastcall ButtonENGClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRegistracija(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegistracija *FormRegistracija;
//---------------------------------------------------------------------------
#endif
