#include <iostream>
#include <time.h>
using namespace std;

//Kreiranje strukture: 
struct fudbaler {
	int ID;
	char* ime_i_Prezime;
	char* pozicija;//prihvati samo slova N, O i V (napad, vezni i odbrana);
	int* broj_golova;
	//Konstruktor: (koristi se za kreiranje memorijskih lokacija svih dinamicki alociranih varijabli)
	fudbaler() {
		ID = 0;//Cisto da ne bi bio warning da se nije property ID inicijalizirao;
		ime_i_Prezime = new char[20];
		pozicija = new char;
		broj_golova = new int;
	}
	//Destruktor: (koristi se za brisanje i vracanje citave dinamicki alocirane memorije)
	~fudbaler() {
		delete[] ime_i_Prezime;
		ime_i_Prezime = nullptr;
		delete pozicija;
		pozicija = nullptr;
		delete broj_golova;
		broj_golova = nullptr;
	}
};
//Deklaracije funkcija: 
void unos(fudbaler**, int, int);
void ispis(fudbaler**, int, int);
void prosjecan_broj_golova_Po_poziciji(fudbaler**, int, int);
void najbolji_Klub_odabrane_Pozicije(fudbaler**, int, int);
void dealokacija(fudbaler**&, int);
int main() {
	srand((time(0)));
	int red, kolona;
	cout << "Unesite koliko redova zelite: " << endl;
	cin >> red;
	cout << "Unesite koliko kolona zelite: " << endl;
	cin >> kolona;
	//Kreiranje dinamickog 2D niza: 
	fudbaler** niz = new fudbaler * [red];
	for (int i = 0; i < red; i++)
	{
		*(niz + i) = new fudbaler[kolona];
	}
	//Pozivi funkcija: 
	unos(niz, red, kolona);
	ispis(niz, red, kolona);
	prosjecan_broj_golova_Po_poziciji(niz, red, kolona);
	cout << endl;
	najbolji_Klub_odabrane_Pozicije(niz, red, kolona);
	//Dealokacija:
	dealokacija(niz, red);
	cin.get();
	return 0;
}
//Definicije funkcija: 
void unos(fudbaler** niz, int red, int kolona) {
	cout << "Molim vas unesite " << red * kolona << " elemenata: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cin.ignore();
			/*	cout << "Unesite ID: " << endl;
				cin >> (*(niz + i) + j)->ID;*/
				//Radi lakseg testiranja: 
			(*(niz + i) + j)->ID = rand() % 1000 + 100;
			cout << "Unesite ime i prezime: " << endl;
			cin.getline((*(niz + i) + j)->ime_i_Prezime, 20);
			do {
				cout << "Unesite poziciju (N, O i V (napad, vezni i odbrana)): " << endl;
				cin >> *(*(niz + i) + j)->pozicija;
				if (*(*(niz + i) + j)->pozicija != 'N' && *(*(niz + i) + j)->pozicija != 'O' && *(*(niz + i) + j)->pozicija != 'V')
					cout << "POGRESNO UNESENA POZICIJA!" << endl;
			} while (*(*(niz + i) + j)->pozicija != 'N' && *(*(niz + i) + j)->pozicija != 'O' && *(*(niz + i) + j)->pozicija != 'V');
			/*cout << "Unesite broj golova: " << endl;
			cin >> *(*(niz + i) + j)->broj_golova;*/
			//Radi lakseg testiranja: 
			*(*(niz + i) + j)->broj_golova = rand() % 10;

		}
	}
}
void ispis(fudbaler** niz, int red, int kolona) {
	cout << endl;
	cout << "Unijeli ste " << red * kolona << " elemenata, a oni su: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "ID je: " << (*(niz + i) + j)->ID << "\t";
			cout << "Ime i prezime je: " << (*(niz + i) + j)->ime_i_Prezime << "\t";
			cout << "Pozicija je: " << *(*(niz + i) + j)->pozicija << "\t";//Posto nije char niz moramo dereferencirati!
			cout << "Broj golova je: " << *(*(niz + i) + j)->broj_golova << endl;
		}
		cout << endl;
	}
}
void prosjecan_broj_golova_Po_poziciji(fudbaler** niz, int red, int kolona) {
	int brojacO = 0, brojacV = 0, brojacN = 0;
	float odbrana = 0.0f, vezni = 0.0f, napad = 0.0f;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == 'O') {
				odbrana += *(*(niz + i) + j)->broj_golova;
				brojacO++;
			}
			else if (*(*(niz + i) + j)->pozicija == 'V') {
				vezni += *(*(niz + i) + j)->broj_golova;
				brojacV++;
			}
			else if (*(*(niz + i) + j)->pozicija == 'N') {
				napad += *(*(niz + i) + j)->broj_golova;
				brojacN++;
			}
		}
		if (brojacO != 0)
			odbrana /= float(brojacO);
		if (brojacN != 0)
			napad /= float(brojacN);
		if (brojacV != 0)
			vezni /= float(brojacV);
		cout << "Ispis za klub: " << i << " Prosjek igraca na veznim pozicijama: " << vezni << " Prosjek igraca na odbrambenim pozicijama: " << odbrana << " Prosjek igraca na napadackim pozicijama: " << napad << endl;
		odbrana = 0.0f, napad = 0.0f, vezni = 0.0f;//kako bi se varijable koje drze prosjeke ponovno resetovale;
		brojacN = 0, brojacO = 0, brojacV = 0;//kako bi se varijable koje drze prosjeke ponovno resetovale;
	}
}
void najbolji_Klub_odabrane_Pozicije(fudbaler** niz, int red, int kolona) {

	char izbor;
	do {
		cout << "Unesite zeljenu poziciju po kojoj zelite vrsiti pretragu (N, O i V (napad, vezni i odbrana)): " << endl;
		cin >> izbor;
		if (izbor != 'O' && izbor != 'V' && izbor != 'N')
			cout << "POGRESAN UNOS POZICIJE!" << endl;
	} while (izbor != 'O' && izbor != 'V' && izbor != 'N');
	float* prosjeci_Odabranih_pozicija = new float[red] {};
	int brojac = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (*(*(niz + i) + j)->pozicija == izbor) {
				*(prosjeci_Odabranih_pozicija + i) += *(*(niz + i) + j)->broj_golova;
				brojac++;
			}
		}
		if (brojac != 0)
			*(prosjeci_Odabranih_pozicija + i) /= float(brojac);
	}
	int indeks_najboljeg_Kluba = 0;
	for (int i = 0; i < red; i++)
	{
		if (*(prosjeci_Odabranih_pozicija + i) > * (prosjeci_Odabranih_pozicija + indeks_najboljeg_Kluba))
			indeks_najboljeg_Kluba = i;
	}
	cout << "Indeks najboljeg kluba (kluba sa najvecim prosjekom) za poziciju " << izbor << " je: " << indeks_najboljeg_Kluba << endl;
	//Dealokacija lokalnog niza prosjeci_Odabranih_pozicija jer je dinamicki:
	delete[]prosjeci_Odabranih_pozicija;
	prosjeci_Odabranih_pozicija = nullptr;
}
void dealokacija(fudbaler**& niz, int red) {
	for (int i = 0; i < red; i++)
	{
		delete[] * (niz + i);
		*(niz + i) = nullptr;
	}
	delete[]niz;
	niz = nullptr;
}