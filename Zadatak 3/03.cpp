#include <iostream>

using namespace std;

int fibonacci(int);
void punjenjeNiza(int*, int, int brojac = 0);
void provjera(int*, int, int, int brojac = 0);

int main() {

	int velicina;
	
	cout << "Unesite velicinu niza: " << endl;
	cin >> velicina;
	
	int* niz = new int[velicina];
	
	punjenjeNiza(niz, velicina);
	
	//Ispis:
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i) << " ";
	}
	
	cout << endl;
	
	int izbor;
	cout << "Molim vas unesite broj za koji zelite znati da li ga ima u nizu: " << endl;
	cin >> izbor;
	
	provjera(niz, velicina, izbor);

	delete[]niz;
	niz = nullptr;
	
	cin.get();
	return 0;
}

int fibonacci(int broj) {

	// Ako se treba naci prvi ili drugi element Fibonnaci onda znamo da su oba 1, pa samo vratimo 1
	if (broj <= 1)
		return 1;

	// U suprotnom trazimo taj element tako što sumiramo dva prethodna elementa, smanjujuci broj prvi svakom pozivu
	return fibonacci(broj - 1) + fibonacci(broj - 2);
}

void punjenjeNiza(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina) // Ako dođemo van opsega niza onda prekidamo rekurziju
		return;
	
	if (brojac < velicina) {

		/*
		if (brojac == 0)
			*(niz + brojac) = fibonacci(brojac);
		
		if (brojac == 1)
			*(niz + brojac) = fibonacci(brojac);
		 */
		
		int temp = fibonacci(brojac);
		
		if (temp < 0)//Provjerimo overflow;
			return;

		*(niz + brojac) = temp;

		punjenjeNiza(niz, velicina, brojac + 1);
	}
}

void provjera(int* niz, int velicina, int izbor, int brojac) {

	// Rekurzija se prekida kada brojac dođe van opsega niza i ispisuje da nije nasao trazeni broj
	if (brojac == velicina)
	{
		cout << "Uneseni element nije u nizu!" << endl;
		return;
	}
	
	if (brojac < velicina) {

		// Ako nađe traženi broj, ispisuje poruku pa prekida rekurziju
		if (*(niz + brojac) == izbor)
		{
			cout << "Uneseni element je u nizu!" << endl;
			return;
		}
		
		provjera(niz, velicina, izbor, brojac + 1);
	}
}