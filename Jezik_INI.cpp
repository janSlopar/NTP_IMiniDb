#pragma hdrstop
#include "Jezik_INI.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Classes.hpp>

void PostaviJezik(TForm* AForm, String jezik) {
    String p = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
    TIniFile* ini = new TIniFile(p);
    try {
        TStrings* kljucevi = new TStringList();
        try {
            ini->ReadSection(jezik, kljucevi);
            for (int i = 0; i < kljucevi->Count; i++) {
				TObject* obj = AForm->FindComponent(kljucevi->Strings[i]);
                String value = ini->ReadString(jezik, kljucevi->Strings[i], "");
                if      (dynamic_cast<TLabel*>(obj))    dynamic_cast<TLabel*>(obj)->Caption    = value;
                else if (dynamic_cast<TButton*>(obj))   dynamic_cast<TButton*>(obj)->Caption   = value;
                else if (dynamic_cast<TCheckBox*>(obj)) dynamic_cast<TCheckBox*>(obj)->Caption = value;
                else if (dynamic_cast<TGroupBox*>(obj)) dynamic_cast<TGroupBox*>(obj)->Caption = value;
                else if (dynamic_cast<TPanel*>(obj))    dynamic_cast<TPanel*>(obj)->Caption    = value;
				else if (dynamic_cast<TForm*>(obj))     dynamic_cast<TForm*>(obj)->Caption     = value;

            }
        } __finally {
            delete kljucevi;
        }
    } __finally {
        delete ini;
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
