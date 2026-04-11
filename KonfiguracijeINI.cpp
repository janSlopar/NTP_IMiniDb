	#include <registry.hpp>
	#include <System.IOUtils.hpp>
	//---------------------------------------------------------------------------
	#pragma package(smart_init)
	#pragma resource "*.dfm"

	void Konf(){
        String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
		TIniFile* ini = new TIniFile(path);

		

		delete ini;

	}
