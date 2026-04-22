//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>
#include <IniFiles.hpp>
#include "PostaviJezikGrida.h"
#include "PregledFilmova.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall TFormSviFilmovi::PostaviJezikGrida(String jezik)
{
    String path = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
    TIniFile *ini = new TIniFile(path);

    int idx[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 16, 17};
    String kljuc[] = {"col_naslov", "col_godina", "col_trajanje", "col_opis",
                      "col_zanr", "col_redatelj", "col_scenarist", "col_glumci",
                      "col_jezik", "col_drzava", "col_nagrade", "col_released",
                      "col_tip", "col_boxOffice"};

    for (int i = 0; i < 14; i++)
        DBGridFilmoviBaza->Columns->Items[idx[i]]->Title->Caption =
            ini->ReadString(jezik, kljuc[i], "");

    delete ini;
}
