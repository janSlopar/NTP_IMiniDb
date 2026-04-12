#ifndef DataTypesH
#define DataTypesH

#include <System.hpp>

class Film;

class Korisnik {
    private:
        AnsiString hashirajLozinku(AnsiString lozinka);
    protected:
        int id;
        AnsiString ime, prezime, korIme, email, lozinkaHash;
    public:
        void setIme(AnsiString _ime);
        void setPrezime(AnsiString _prezime);
        void setKorisnickoIme(AnsiString _korIme);
        void setEmail(AnsiString _email);
        void setLozinka(AnsiString _lozinka);
        AnsiString getKorIme() const;
        Korisnik() {}
        Korisnik(int id, AnsiString korIme, AnsiString email, AnsiString lozinka);
        bool prijava(AnsiString lozinka);
};

class Admin : protected Korisnik {
    private:
        int razina;
        AnsiString odjel;
    public:
        Admin() {}
        Admin(int id, AnsiString korIme, AnsiString email,
              AnsiString lozinka, int razina, AnsiString odjel);
        void dodajFilm(Film* film);
        void obrisiKorisnika(int korisnikId);
};

class Film {
    private:
        int id;
        AnsiString naslov;
        int godina;
        int trajanje;
        AnsiString opis;
        TBytes poster;
    public:
		Film(int id, AnsiString naslov, int godina, int trajanje, AnsiString opis);
        int GetId();
        AnsiString GetNaslov();
        int GetGodina();
        int GetTrajanje();
        AnsiString GetOpis();
        TBytes GetPoster();
        float izracunajOcjenu();
        AnsiString dohvatiDetalje();
        void ucitajPoster(AnsiString putanja);
};

class Recenzija {
    private:
        int id;
        AnsiString tekst;
        int ocjena;
        TDateTime datum;
        int filmId;
        int korisnikId;
    public:
        Recenzija(int filmId, int korisnikId, AnsiString tekst, int ocjena);
        bool validiraj();
        void spremi();
};

class Watchlista {
    private:
        int id;
        AnsiString naziv;
        bool javna;
        TDateTime datumKreiranja;
        TList* filmovi;
    public:
        Watchlista(int korisnikId, AnsiString naziv, bool javna);
        ~Watchlista();
        void dodajFilm(Film* film);
        void ukloniFilm(int filmId);
        AnsiString izvezi();
};

#endif
