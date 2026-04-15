CREATE DATABASE IMiniDB

-- =========================
-- KORISNICI
-- =========================
CREATE TABLE korisnik (
    id INT AUTO_INCREMENT PRIMARY KEY,
    ime VARCHAR(100),
    prezime VARCHAR(100),
    korisnicko_ime VARCHAR(100) UNIQUE NOT NULL,
    email VARCHAR(150) UNIQUE NOT NULL,
    lozinka_hash VARCHAR(255) NOT NULL
);

-- =========================
-- ADMIN (nasljeđuje korisnika)
-- =========================
CREATE TABLE ADMIN (
    korisnik_id INT PRIMARY KEY,
    razina INT,
    odjel VARCHAR(100),
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);

-- =========================
-- FILM
-- =========================
CREATE TABLE film (
    id INT AUTO_INCREMENT PRIMARY KEY,
    naslov VARCHAR(255) NOT NULL,
    godina INT,
    trajanje INT,
    opis TEXT,
    poster LONGBLOB
);

-- =========================
-- RECENZIJA
-- =========================
CREATE TABLE recenzija (
    id INT AUTO_INCREMENT PRIMARY KEY,
    tekst TEXT,
    ocjena INT CHECK (ocjena BETWEEN 1 AND 10),
    datum DATETIME DEFAULT CURRENT_TIMESTAMP,
    film_id INT,
    korisnik_id INT,
    FOREIGN KEY (film_id) REFERENCES film(id) ON DELETE CASCADE,
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);

-- =========================
-- WATCHLISTA
-- =========================
CREATE TABLE watchlista (
    id INT AUTO_INCREMENT PRIMARY KEY,
    korisnik_id INT,
    naziv VARCHAR(255),
    javna BOOLEAN,
    datum_kreiranja DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (korisnik_id) REFERENCES korisnik(id) ON DELETE CASCADE
);

-- =========================
-- WATCHLISTA_FILMOVI (M:N)
-- =========================
CREATE TABLE watchlista_film (
    watchlista_id INT,
    film_id INT,
    PRIMARY KEY (watchlista_id, film_id),
    FOREIGN KEY (watchlista_id) REFERENCES watchlista(id) ON DELETE CASCADE,
    FOREIGN KEY (film_id) REFERENCES film(id) ON DELETE CASCADE
);