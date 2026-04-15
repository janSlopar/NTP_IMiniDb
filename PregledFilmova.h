//---------------------------------------------------------------------------

#ifndef PregledFilmovaH
#define PregledFilmovaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.XMLIntf.hpp>
//---------------------------------------------------------------------------
class TFormSviFilmovi : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonDodajWatchlistu;
	TEdit *EditNoviNaziv;
	TEdit *EditNovaGodina;
	TLabel *Label6;
	TLabel *Label7;
	TButton *ButtonOmiljeniFilmovi;
	TListView *listViewOFilmovi;
	TImage *Image1;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	TXMLDocument *XMLDocumentOmiljeniFilmovi;
	TButton *ButtonDodajNoviOFilm;
	TButton *ButtonUkloni;
	TEdit *EditNovoTrajanje;
	TLabel *Label8;
	TMemo *MemoOpisNovogFilma;
	TLabel *Label9;
	TButton *ButtonPregledajListu;
	TLabel *Label1;
	TLabel *LabelOmiljeniFilmoviNaslov;
	TLabel *LabelListaZaGledanje;
	TButton *Button1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonOmiljeniFilmoviClick(TObject *Sender);
	void __fastcall ButtonHRVClick(TObject *Sender);
	void __fastcall ButtonENGClick(TObject *Sender);
	void __fastcall ButtonDodajNoviOFilmClick(TObject *Sender);
	void __fastcall ButtonUkloniClick(TObject *Sender);
	void __fastcall OsvjeziListu();
	void __fastcall OcistiPolja();
	void __fastcall ButtonDodajWatchlistuClick(TObject *Sender);
	void __fastcall ButtonPregledajListuClick(TObject *Sender);
	void __fastcall listViewOFilmoviSelectItem(TObject *Sender, TListItem *Item, bool Selected);

private:	// User declarations
public:		// User declarations
	__fastcall TFormSviFilmovi(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSviFilmovi *FormSviFilmovi;
//---------------------------------------------------------------------------
#endif
