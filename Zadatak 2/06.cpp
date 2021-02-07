#include <iostream>
#include <time.h>
using namespace std;
const int x = 4, y = 4;

int brojCifri(int);
void unos(int[][y]);
void ispis(int[][y]);
float suma(int[][y]);
int main() {
	srand((time(0)));
	//Deklarisanje 2D niza:
	int niz[x][y];
	unos(niz);
	cout << endl;
	ispis(niz);
	cout << endl;
	cout << "Suma crnih polja iznad glavne dijagonale je: " << suma(niz) << endl;






	cin.get();
	return 0;

}
//Definicije funkcija: 
int brojCifri(int broj) {
	int brojac = 0;
	while (broj > 0) {
		broj /= 10;
		brojac++;
	}
	return brojac;
}
void unos(int niz[][y]) {

	cout << "Molim vas unesite elemente niza: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i + j) % 2 == 0) {
				int broj;
				do {
					broj = rand() % 100 + 1;
					niz[i][j] = broj;
					if (broj % 2 != 0 && brojCifri(broj) % 2 == 0)
						cout << "UNESITE PARAN BROJ SA NEPARNIM BROJEM CIFARA!" << endl;
				} while (broj % 2 != 0 && brojCifri(broj) % 2 == 0);
			}
			else if ((i + j) % 2 != 0) {
				int broj;
				do {
					broj = rand() % 100 + 1;
					niz[i][j] = broj;
					if (broj % 2 == 0 && brojCifri(broj) % 2 != 0)
						cout << "UNESITE NEPARAN BROJ SA PARNIM BROJEM CIFARA" << endl;
				} while (broj % 2 == 0 && brojCifri(broj) % 2 != 0);
			}
		}
	}
}
void ispis(int niz[][y]) {
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << " \t";
		}
		cout << endl;
	}
}
float suma(int niz[][y]) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = i; j < y; j++)//Stavimo j==i radi  uzimanja sa glavnih dijagonala
		{
			if ((i + j) % 2 == 0) {//Radi crnih polja i+j;
				suma += niz[i][j];
				brojac++;
			}
		}
	}
	return suma / brojac;
}