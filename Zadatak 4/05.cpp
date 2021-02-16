#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int brojCifri(int);
void unos(int**, int, int);
void ispis(int**, int, int);
float aritSredina(int**, int, int);

int main() {
	srand((time(0)));
	int red, kolona;
	
	cout << "Unesite broj redova: ";
	cin >> red;
	cout << "Unesite broj kolona: ";
	cin >> kolona;

	// Kreiranje dinamickog 2D int niz
	int** tabla = new int* [red];
	for (int i = 0; i < red; i++)
	{
		*(tabla + i) = new int[kolona];
	}
	
	unos(tabla, red, kolona);
	cout << endl;
	ispis(tabla, red, kolona);
	cout << endl;
	
	cout << "Aritmeticka sredina svih brojeva na crnim poljima iznad glavne dijagonale je: " << aritSredina(tabla, red, kolona) << endl;

	// Dealokacija table
	for (int i = 0; i < red; i++)
	{
		delete[] * (tabla + i);
	}

	delete[] tabla;
	tabla = nullptr;

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
void unos(int** tabla, int red, int kolona) {

	bool unesen = false;

	cout << "Molim vas unesite elemente niza: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			do
			{
				int broj = rand() % 20 + 1;

				// Ako broj zadovolji bilo koja od dva uslova, element u tabli se popuni i bool unesen se postavlja kao true kako bi se prekinuo pronalazak novog broja sa rand()
				if ((i + j) % 2 == 0 && broj % 2 == 0 && brojCifri(broj) % 2 != 0)
				{
					*(*(tabla + i) + j) = broj;
					unesen = true;
				}
				
				else if ((i + j) % 2 != 0 && broj % 2 != 0 && brojCifri(broj) % 2 == 0)
				{
					*(*(tabla + i) + j) = broj;				
					unesen = true;
				}
			} while (unesen == false);

			// Ako se trenutni element prekine, resetuje se bool unesen kako bi se mogao pronaći sljedeći element
			unesen = false;
		}
	}
}
void ispis(int** tabla, int red, int kolona) {
	
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << *(*(tabla + i) + j) << " \t";
		}
		cout << endl;
	}
}
float aritSredina(int** tabla, int red, int kolona) {
	
	float suma = 0.0f;
	int brojac = 0;
	
	for (int i = 0; i < red; i++)
	{
		for (int j = i; j < kolona; j++)//Stavimo j==i kako bi gledali samo elemente iznad glavne dijagonale
		{
			if ((i + j) % 2 == 0) {// Radi crnih polja i+j;
				suma += *(*(tabla + i) + j);
				brojac++;
			}
		}
	}
	
	return suma / brojac;
}