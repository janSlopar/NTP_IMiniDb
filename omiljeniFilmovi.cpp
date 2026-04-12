
// *************************************************************************** //
//                                                                           
//                             XML Data Binding                              
//                                                                           
//         Generated on: 12.4.2026. 11:39:50                                 
//       Generated from: C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xml   
//   Settings stored in: C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xdb   
//                                                                           
// *************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "omiljeniFilmovi.h"


// Global Functions 

_di_IXMLfilmoviType __fastcall Getfilmovi(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLfilmoviType) Doc->GetDocBinding("filmovi", __classid(TXMLfilmoviType), TargetNamespace);
};

_di_IXMLfilmoviType __fastcall Getfilmovi(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getfilmovi(DocIntf);
};

_di_IXMLfilmoviType __fastcall Loadfilmovi(const System::UnicodeString& FileName)
{
  return (_di_IXMLfilmoviType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("filmovi", __classid(TXMLfilmoviType), TargetNamespace);
};

_di_IXMLfilmoviType __fastcall  Newfilmovi()
{
  return (_di_IXMLfilmoviType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("filmovi", __classid(TXMLfilmoviType), TargetNamespace);
};

// TXMLfilmoviType 

void __fastcall TXMLfilmoviType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("film"), __classid(TXMLfilmType));
  ItemTag = "film";
  ItemInterface = __uuidof(IXMLfilmType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLfilmType __fastcall TXMLfilmoviType::Get_film(const int Index)
{
  return (_di_IXMLfilmType) List->Nodes[Index];
};

_di_IXMLfilmType __fastcall TXMLfilmoviType::Add()
{
  return (_di_IXMLfilmType) AddItem(-1);
};

_di_IXMLfilmType __fastcall TXMLfilmoviType::Insert(const int Index)
{
  return (_di_IXMLfilmType) AddItem(Index);
};

// TXMLfilmType 

int __fastcall TXMLfilmType::Get_id()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("id")]->Text);
};

void __fastcall TXMLfilmType::Set_id(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("id")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLfilmType::Get_naslov()
{
  return GetChildNodes()->Nodes[System::UnicodeString("naslov")]->Text;
};

void __fastcall TXMLfilmType::Set_naslov(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("naslov")]->NodeValue = Value;
};

int __fastcall TXMLfilmType::Get_godina()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("godina")]->Text);
};

void __fastcall TXMLfilmType::Set_godina(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("godina")]->NodeValue = Value;
};

int __fastcall TXMLfilmType::Get_trajanje()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("trajanje")]->Text);
};

void __fastcall TXMLfilmType::Set_trajanje(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("trajanje")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLfilmType::Get_opis()
{
  return GetChildNodes()->Nodes[System::UnicodeString("opis")]->Text;
};

void __fastcall TXMLfilmType::Set_opis(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("opis")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLfilmType::Get_poster()
{
  return GetChildNodes()->Nodes[System::UnicodeString("poster")]->Text;
};

void __fastcall TXMLfilmType::Set_poster(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("poster")]->NodeValue = Value;
};
