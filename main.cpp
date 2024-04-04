#include<iostream>
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Biblioteka.h"

using namespace std;

int main()
{
    Ksiazka ksiazka_1 ("Lassie wroc", "Eric Knight", "Siedmiorog", 2017);
    Ksiazka ksiazka_2 ("Ania z Zielonego Wzgorza", "Lucy Maud Montgomery", "Greg", 2021);
    Czasopismo czasopismo_1 ("Programista", "Informatyka", 2020, 100, "kwartalnik");
    Biblioteka bibliotekaKasi;
    bibliotekaKasi.dodajDoKatalogu(&ksiazka_1);
    bibliotekaKasi.dodajDoKatalogu(&ksiazka_2);
    bibliotekaKasi.dodajDoKatalogu(&czasopismo_1);
    bibliotekaKasi.pokazZawartoscBiblioteki();
    bibliotekaKasi.usunZKatalogu(1);
    bibliotekaKasi.pokazZawartoscBiblioteki();
    bibliotekaKasi.zapiszKatalogDoPliku("BibliotekaKasi.csv");
    return 0;
}
