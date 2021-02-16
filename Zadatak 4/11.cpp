#include <iostream>
#include<time.h> //dodajemo kako bi komanda na 11 liniji radila
using namespace std;
const int x = 10, y = 10; //deklarišemo dvije konstante za našu matricu gdje je x red a y kolona

int brCif(int); //funkcija koja racuna koliko cifri ima nas uneseni broj
void unos(int[][y]); //funckija za unos elemenata u matricu
void ispis(int[][y]); //funkcija za ispis matrice
void red_i_kolona(int[][y]); //funkcija za racunanje najboljeg reda i kolone
int main() {
	srand((time(0))); //sluzi za generisanje uvijek drugacijek slucajnog broja pri pokretanju programa, ako bi se izbrisala ova linija slucajni broj kod plate uvijek bi bio isti
	int niz[x][y];
	unos(niz);
	ispis(niz);
	red_i_kolona(niz);

	cin.get();
	return 0;

}
int brCif(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;
	}
	return brojac;
}
void unos(int niz[][y]) {
	int temp;
	cout << "Molim vas unesite " << x * y << " elemanata u niz: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			do { 
				//cin >> temp;
				temp = rand() % 1000 + 1;
				niz[i][j] = temp;
				/*if (brCif(temp) % 2 == 0)
					cout << "Unijeli ste broj sa PARNIM  brojem cifri!!!" << endl;
					*/ //posto unosimo sa komandom rand a ne manuelno ovaj if nam ne teba a i kod manuelnog unosenja stavljamo ga samo da ljepse kod izgleda
			} while (brCif(temp) % 2 == 0); //da se ponavlja unos sve dok je broj cifri paran

		}
	}
}
void ispis(int niz[][y]) {
	cout << endl;
	cout << "Unijeli ste " << x * y << " elemenata u niz a oni su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << "\t";
		}
		cout << endl;
	}
}
void red_i_kolona(int niz[][y]) {
	float rednP[x] = { 0 }; //pomocni niz u kojeg spremamo sve vrijednosti redova
	float kolonanP[y] = { 0 }; //pomocni niz za kolone gdje spremamo sve vrijednosti kolona
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			rednP[i] += niz[i][j]; //sabiramo sve elemente jednog reda u jednu jedinstvenu cifru
		}
		rednP[i] /= y; //djelimo sa brojem kolona tako da dobijemo prosjek
	}
	int indeksNajvecegR = 0;
	for (int i = 0; i < x; i++)
	{
		if (rednP[i] > rednP[indeksNajvecegR]) { //radimo poredenje razlicitih elemenata u pomocnom nizu tako da saznamo koji je red najveci
			indeksNajvecegR = i;
		}
	}
	cout << "Indeks reda sa najvecim prosjekom je: " << indeksNajvecegR << endl;
	cout << "\n";
	cout << "Ispis reda sa najvecim prosjekom: " << endl;
	for (int j = 0; j < y; j++)
	{
		cout << niz[indeksNajvecegR][j] << "\t";
	}
	cout << endl;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			kolonanP[i] += niz[j][i]; //sabiramo sve elemente jedne kolone u jedinstvenu cifru
		}
		kolonanP[i] /= x; //djelimo sa brojem redova da dobijemo prosjek te kolone
	} 
	int indeksNajveceK = 0;
	for (int i = 0; i < y; i++)
	{
		if (kolonanP[i] > kolonanP[indeksNajveceK]) { //radimo poredenje razlicitih elemenata u pomocnom nizu tako da saznamo koja je kolona najveci
			indeksNajveceK = i;
		}
	}
	cout << "Indeks kolone sa najvecim prosjekom je: " << indeksNajveceK << endl;
	cout << "\n";
	cout << "Ispis kolone sa najvecim prosjekom: " << endl;
	for (int i = 0; i < x; i++)
	{
		cout << niz[i][indeksNajveceK] << endl;
	}
	cout << endl;
}
