#include <iostream>
using  namespace std;
const int x = 4, y = 4; //deklarisemo konstante koje ce nam biti dimenzije naseg dvodimenzionalnog niza gdje nam je x red a y kolona

int brojCifri(int); //funkcija koja racuna koliko cifri ima nas broj
void unos(int[][y]); //funkcija pomocu koje unosimo elemente u nasu matricu
void ispis(int[][y]); //funkcija pomocu koje ispisujemo elemente iz matrice
void transpose(int[][y]); //funkcija koja će zamjeniti redove i kolone tj. ono sto je prije bilo zapisano u redu sad ce biti zapisano u koloni i naobratno
bool prost_broj(int); //funkcija koja provjerava da li je uneseni broj prosti ili ne
float aritmeticka(int[][y]); //funkcija koja racuna aritmeticku sredinu elemenata ispod sporedne dijagonale
int zbirCifri(int); //funkcija koja zbraja cifre broja 
void simpatican(int[][y]); //funkcija koja ispisiva i provjerava da li je element u nizu simpatican ili ne
int main() {
	int niz[x][y];
	unos(niz);
	ispis(niz);
	transpose(niz);//Ne zamjeni ga funckija zaista samo napravi lokalni niz;
	cout << "Aritmeticka sredina svih prostih brojeva ispod sporedne dijagonale je: " << aritmeticka(niz) << endl;
	simpatican(niz);




	cin.get();
	return 0;
}
int brojCifri(int broj) {
	int br = 0;
	while (broj > 0) {
		broj /= 10;
		br++;
	}
	return br;
}
void unos(int niz[][y]) {
	int temp;
	cout << "Molim vas unesite 16 elemenata niza : " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			do {
				cin >> temp;
				niz[i][j] = temp;
				if (brojCifri(temp) < 2 || brojCifri(temp) > 2)
					cout << "Niste unijeli dvocifren broj!" << endl;
			} while (brojCifri(temp) < 2 || brojCifri(temp) > 2); //provjeravamo da li je uneseni broj dvocifren ili ne
		}
	}
}
void ispis(int niz[][y]) {
	cout << endl;
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << "\t";
		}
		cout << endl;
	}
}
void transpose(int niz[][y]) {
	int niz2[x][y] = { 0 };
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			niz2[i][j] = niz[j][i]; //stavljamo elemente niza u pomocni niz tako da u njemu su obrnuti nase klone i redovi u odnosu na originalni niz
		}
	}
	cout << endl;
	cout << "Niz nakon zamjenjenih kolona i redova : " << endl;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz2[i][j] << "\t";
		}
		cout << endl;
	}
}
bool prost_broj(int broj) {
	if (broj == 1) //1 nije prost broj
		return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
float aritmeticka(int niz[][y]) {
	float aritmeticka = 0.0;
	int brojac = 0;
	/*
	sporedna dijagonala ide : 


	*	*	*	*	/
	*	*	*	/	*
	*	*	/	*	*
	*	/	*	*	*
	/	*	*	*	*


	*/
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i + j) > x - 1) {//Ispod sporedne da smo htjeli i na sporednoj dodas >=!;
				if (prost_broj(niz[i][j])) {
					aritmeticka += niz[i][j];
					brojac++;
				}
			}
		}
	}
	if (brojac != 0)
		aritmeticka /= float(brojac);
	return aritmeticka;
}
int zbirCifri(int broj) {
	int zbir = 0;
	while (broj > 0) {
		zbir += broj % 10;
		broj /= 10;
	}
	return zbir;
}
void simpatican(int niz[][y]) {
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i + j) < x - 1) {
				if (zbirCifri(niz[i][j] * niz[i][j]) == zbirCifri(niz[i][j]) * zbirCifri(niz[i][j])) {
					cout << "Broj " << niz[i][j] << " je simpatican!" << endl;
				}
				else {
					cout << "Broj " << niz[i][j] << " nije simpatican!" << endl;
				}
			}
		}
	}
}
