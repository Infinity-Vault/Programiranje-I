#include <iostream>

using namespace std;

void napuniNiz(int*, int, int brojac = 0); // int brojac = 0 je default parametar, važi za svaki poziv funkcije tako da se ne mora proslijeđivati
void ispisiNiz(int*, int, int brojac = 0);

long long int suma(int*, int, int brojac = 0); // Koristimo long long int zbog mogućnosti velikog rezultata

int main() {
	
	int velicina;
	
	do {
		
		cout << "Unesite velicinu niza: " << endl;
		cin >> velicina;
		
	} while (velicina < 2);
	
	int* niz = new int[velicina] {};//{} - inicijalizacija 0;
	
	napuniNiz(niz, velicina);
	ispisiNiz(niz, velicina);
	
	cout << endl;
	
	cout << "Suma svih elemenata niza je: " << suma(niz, velicina);//Treci parametar je default;

	// Dealokacija:
	delete[] niz;
	niz = nullptr;
	
	cin.get();
	return 0;
 }

void napuniNiz(int* niz, int velicina, int brojac) {

	// Kada brojac dođe do velicine niza, tada se rekurzija prekida jer ne želimo pisati van njegovog opsega
	if (brojac == velicina)
		return;

	// Sve dok je brojac manji od velicine rekurzija se izvrsava
	if (brojac < velicina) { 

		// Postavljamo prva dva elementa niza kao 1 i 3 zbog zahtjeva zadatka
		if (brojac == 0)
			*(niz + brojac) = 1;
		
		if (brojac == 1)
			*(niz + brojac) = 3;

		// Kada postavimo prva dva elementa onda nalazimo sljedece
		if (brojac > 1) {

			// Umnozak dva prethodna pohranjujemo u temp varijablu
			int temp = *(niz + brojac - 1) * *(niz + brojac - 2);
			
			if (temp < 0) // Prekidamo rekurziju ako se desi overflow na int temp (overflow na signed int promijeni vrijednost u negativni broj)
				return;
			
			*(niz + brojac) = temp; 
		}

		// Nakon svakog postavljanja novog elementa nastavljamo rekurziju novim pozivom gdje se brojac inkrementuje za jedan (da bi dosli do sljedeceg elementa)
		napuniNiz(niz, velicina, brojac + 1);
	}
}

void ispisiNiz(int* niz, int velicina, int brojac) {

	if (brojac == velicina)
		return;
	
	cout << *(niz + brojac) << " ";
	
	ispisiNiz(niz, velicina, brojac + 1);
}

long long int suma(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina)
		return 0;

	// Svakim rekurzivnim pozivom sumiramo trenutni element niza a inkrementujemo brojac za 1 kako bi dosli do sljedećeg elementa
	return *(niz + brojac) + suma(niz, velicina, brojac + 1);
}
