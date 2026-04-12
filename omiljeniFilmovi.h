
// *************************************************************************** //
//                                                                           
//                             XML Data Binding                              
//                                                                           
//         Generated on: 12.4.2026. 11:39:50                                 
//       Generated from: C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xml   
//   Settings stored in: C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xdb   
//                                                                           
// *************************************************************************** //

#ifndef   omiljeniFilmoviH
#define   omiljeniFilmoviH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLfilmoviType;
typedef System::DelphiInterface<IXMLfilmoviType> _di_IXMLfilmoviType;
__interface IXMLfilmType;
typedef System::DelphiInterface<IXMLfilmType> _di_IXMLfilmType;

// IXMLfilmoviType 

__interface INTERFACE_UUID("{E55E3F02-CEBA-406F-95D7-3B3893E6FE3E}") IXMLfilmoviType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLfilmType __fastcall Get_film(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLfilmType __fastcall Add() = 0;
  virtual _di_IXMLfilmType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLfilmType film[const int Index] = { read=Get_film };/* default */
};

// IXMLfilmType 

__interface INTERFACE_UUID("{C3C346DB-CB5C-4C26-A67F-3A3EC8F5246F}") IXMLfilmType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_id() = 0;
  virtual System::UnicodeString __fastcall Get_naslov() = 0;
  virtual int __fastcall Get_godina() = 0;
  virtual int __fastcall Get_trajanje() = 0;
  virtual System::UnicodeString __fastcall Get_opis() = 0;
  virtual System::UnicodeString __fastcall Get_poster() = 0;
  virtual void __fastcall Set_id(const int Value) = 0;
  virtual void __fastcall Set_naslov(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_godina(const int Value) = 0;
  virtual void __fastcall Set_trajanje(const int Value) = 0;
  virtual void __fastcall Set_opis(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_poster(const System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property int id = { read=Get_id, write=Set_id };
  __property System::UnicodeString naslov = { read=Get_naslov, write=Set_naslov };
  __property int godina = { read=Get_godina, write=Set_godina };
  __property int trajanje = { read=Get_trajanje, write=Set_trajanje };
  __property System::UnicodeString opis = { read=Get_opis, write=Set_opis };
  __property System::UnicodeString poster = { read=Get_poster, write=Set_poster };
};

// Forward Decls 

class TXMLfilmoviType;
class TXMLfilmType;

// TXMLfilmoviType 

class TXMLfilmoviType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLfilmoviType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLfilmoviType 
  virtual _di_IXMLfilmType __fastcall Get_film(const int Index);
  virtual _di_IXMLfilmType __fastcall Add();
  virtual _di_IXMLfilmType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLfilmType 

class TXMLfilmType : public Xml::Xmldoc::TXMLNode, public IXMLfilmType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLfilmType 
  virtual int __fastcall Get_id();
  virtual System::UnicodeString __fastcall Get_naslov();
  virtual int __fastcall Get_godina();
  virtual int __fastcall Get_trajanje();
  virtual System::UnicodeString __fastcall Get_opis();
  virtual System::UnicodeString __fastcall Get_poster();
  virtual void __fastcall Set_id(const int Value);
  virtual void __fastcall Set_naslov(const System::UnicodeString Value);
  virtual void __fastcall Set_godina(const int Value);
  virtual void __fastcall Set_trajanje(const int Value);
  virtual void __fastcall Set_opis(const System::UnicodeString Value);
  virtual void __fastcall Set_poster(const System::UnicodeString Value);
};

// Global Functions 

_di_IXMLfilmoviType __fastcall Getfilmovi(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLfilmoviType __fastcall Getfilmovi(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLfilmoviType __fastcall Loadfilmovi(const System::UnicodeString& FileName);
_di_IXMLfilmoviType __fastcall  Newfilmovi();

#define TargetNamespace ""

#endif