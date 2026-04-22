//---------------------------------------------------------------------------

#ifndef PrijavaH
#define PrijavaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TFormPrijava : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBoxPrijava;
	TButton *ButtonPrijava;
	TLabel *LabelKorImePrijava;
	TLabel *LabelLozinkaPrijava;
	TEdit *EditKorImePrijava;
	TEdit *EditLozinkaPrijava;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	TFDConnection *FDConnectionIMiniDB;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDTable *FDTableKorisnik;
	TDataSource *DataSourceKorisnikPrijava;
	TFDQuery *FDQueryPrijava;
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
