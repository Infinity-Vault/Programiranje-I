<<<<<<< HEAD
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
=======
#include<iostream>
using namespace std;
bool prost(int);
bool palindrom(int);
int main()
{
	int unos;
	do
	{
		cout << "Unesite broj : " << endl;
		cin >> unos;
	}while(unos < 100);
	if (prost(unos) && palindrom(unos))
		cout << "Uneseni broj je i prost i palindrom." << endl;
	else
		cout << "Uneseni broj ne ispunjava jedan od uslova." << endl;
	cin.get();
	return 0;
}
bool prost(int broj)
{
	if (broj == 1)
		return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
bool palindrom(int broj)
{
	int kopija = broj, suma = 0;
	do
	{
		suma =suma* 10 + broj % 10;
		broj /= 10;
	} while (broj > 0);
	if (suma == kopija)
		return true;
	return false;
}
>>>>>>> b748b30895c9a2e0efe67b292a0ef14c2f473c87
