#include <iostream>
using  namespace std;
const int x = 4, y = 4;

int brojCifri(int);
void unos(int[][y]);
void ispis(int[][y]);
void transpose(int[][y]);
bool prost_broj(int);
float aritmeticka(int[][y]);
int zbirCifri(int);
void simpatican(int[][y]);
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
	cout << "Molim vas unesite elemente niza: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			do {
				cin >> temp;
				niz[i][j] = temp;
				if (brojCifri(temp) < 2 || brojCifri(temp) > 2)
					cout << "Niste unijeli dvocifren broj!" << endl;
			} while (brojCifri(temp) < 2 || brojCifri(temp) > 2);
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
			niz2[i][j] = niz[j][i];
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
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	if (broj == 1)
		return false;
	return true;
}
float aritmeticka(int niz[][y]) {
	float aritmeticka = 0.0;
	int brojac = 0;
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