#pragma once
#include <iostream>      
#include <string> 

using namespace std;

struct Pracownik {
    string imie;
    string nazwisko;
    string pesel;
    unsigned int rocznik;
};

void pracownik_wyswietl(Pracownik* _Pracownik);
void pracownik_wprowadz(Pracownik& _Pracownik);

void pracownik_stworz(Pracownik*& pracownik);
void pracownik_usun(Pracownik*& pracownik);
void pracownik_wprowadz(Pracownik*& pracownik);

void pracownik_stworz(Pracownik*& pracownik, const unsigned int rozmiar);
void pracownik_usun(Pracownik*& pracownik, const unsigned int rozmiar);
void pracownik_generuj(Pracownik* pracownicy, const unsigned int rozmiar);
void pracownik_wyswietl(Pracownik* pracownicy, const unsigned int rozmiar);

void pracownik_stworz(Pracownik**& pracownicy, const  int rozmiar);
void pracownik_usun(Pracownik**& pracownicy, int& rozmiar);
void pracownik_wyswietl(Pracownik** pracownicy, const  int rozmiar);
void pracownik_generuj(Pracownik** pracownicy, const  int rozmiar);
void pracownik_dodaj(Pracownik**& tablica, int& rozmiar);
void pracownik_usun(Pracownik**& tablica, int& rozmiar, int index);
