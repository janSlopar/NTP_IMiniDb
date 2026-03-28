//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <DataTypes.h>
#include <DataTypes.cpp>
//---------------------------------------------------------------------------
USEFORM("Registracija.cpp", FormRegistracija);
USEFORM("Prijava.cpp", FormPrijava);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormRegistracija), &FormRegistracija);
		Application->CreateForm(__classid(TFormPrijava), &FormPrijava);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
