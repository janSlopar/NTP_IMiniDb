//---------------------------------------------------------------------------

#ifndef PrijavaH
#define PrijavaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormPrijava : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBoxPrijava;
	TButton *ButtonPrijava;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditKorImePrijava;
	TEdit *EditLozinkaPrijava;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	void __fastcall ButtonPrijavaClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonHRVClick(TObject *Sender);
	void __fastcall ButtonENGClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormPrijava(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
#endif
