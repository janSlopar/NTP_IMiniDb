#include <vcl.h>
#pragma hdrstop
#include "DataTypes.h"

// ================================================================== KORISNIK ==================================================================
void Korisnik::setIme(AnsiString _ime){
	if (_ime.IsEmpty())
		throw Exception("Ime ne smije biti prazno!");
	ime = _ime;
}

void Korisnik::setPrezime(AnsiString _prezime){
	if (_prezime.IsEmpty())
		throw Exception("Prezime ne smije biti prazno!");
	prezime = _prezime;
}

void Korisnik::setKorisnickoIme(AnsiString _korIme){
	if (_korIme.IsEmpty())
		throw Exception("Korisničko ime ne smije biti prazno!");
	korIme = _korIme;
}
void Korisnik::setEmail(AnsiString _email){
	if (_email.IsEmpty())
		throw Exception("E-mail ne smije biti prazan!");
	email = _email;
}
void Korisnik::setLozinka(AnsiString _lozinka){
	if(_lozinka.IsEmpty())
		throw Exception("Lozinka ne smije biti prazna!");
    lozinkaHash = _lozinka;
}

AnsiString Korisnik::getKorIme() const { return korIme;}

Korisnik::Korisnik(int id, AnsiString korIme, AnsiString email, AnsiString lozinka) : id(id), korIme(korIme), email(email){
	this->lozinkaHash  = hashirajLozinku(lozinka);
}

bool Korisnik::prijava(AnsiString lozinka){
    return lozinkaHash == hashirajLozinku(lozinka);
}

AnsiString Korisnik::hashirajLozinku(AnsiString lozinka){
	// kriptiranje ...
    return lozinka;
}




// ================================================================== ADMINISTRATOR ==================================================================
Admin::Admin(int id, AnsiString username, AnsiString email, AnsiString lozinka, int razina, AnsiString odjel)
	: Korisnik(id, username, email, lozinka), razina(razina), odjel(odjel)
{

}



// ================================================================== FILM ==================================================================
Film::Film(int id, AnsiString naslov, int godina, int trajanje, AnsiString opis) : id(id), naslov(naslov), godina(godina), trajanje(trajanje), opis(opis)
{
	if (godina < 1888 || godina > 2026)
		this->godina = 2026;
    else
        this->godina = godina;
}

int Film::GetId()               { return id; }
AnsiString Film::GetNaslov()    { return naslov; }
int Film::GetGodina()           { return godina; }
int Film::GetTrajanje()         { return trajanje; }
AnsiString Film::GetOpis()      { return opis; }
TBytes Film::GetPoster()        { return poster; }

float Film::izracunajOcjenu() {
    // dohvati sve recenzije za ovaj film iz baze i izračunaj prosjek
    // else return 0.0;
}



// ================================================================== RECENZIJA ==================================================================
Recenzija::Recenzija(int filmId, int korisnikId, AnsiString tekst, int ocjena) : filmId(filmId), korisnikId(korisnikId), tekst(tekst)
{
    if (ocjena < 1 || ocjena > 10)
        this->ocjena = 1;
    else
        this->ocjena = ocjena;

	this->datum = Now();
}

bool Recenzija::validiraj() {
    if (tekst.IsEmpty()) return false;
    if (ocjena < 1 || ocjena > 10) return false;
    return true;
}



// ================================================================== WATCHLISTA ==================================================================
Watchlista::Watchlista(int korisnikId, AnsiString naziv, bool javna)
    : id(korisnikId), naziv(naziv), javna(javna)
{
    this->datumKreiranja = Now();
    this->filmovi = new TList();
}

Watchlista::~Watchlista() {
    delete filmovi;
}

void Watchlista::dodajFilm(Film* film) {
    // duplikati ...
    for (int i = 0; i < filmovi->Count; i++) {
        if (filmovi->Items[i] == film) {
            ShowMessage("Film je već na watchlisti!");
            return;
        }
    }
    filmovi->Add(film);
}
