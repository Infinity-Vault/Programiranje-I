#include <iostream>

using namespace std;

void napuniNiz(int*, int, int brojac = 0);
void provjeri(int*, int, int, int brojac = 0);

int main() {

	int velicina;
	
	cout << "Unesite velicinu niza koju zelite: " << endl;
	cin >> velicina;
	
	int* niz = new int[velicina] {};
	
	napuniNiz(niz, velicina);
	
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i) << " ";
	}
	
	cout << "\n";
	
	int izbor;
	cout << "Unesite broj koji zelite potraziti u nizu: " << endl;
	cin >> izbor;
	provjeri(niz, velicina, izbor);
	
	//Dealokacija:
	delete[]niz;
	niz = nullptr;
	
	cin.get();
	return 0;
}
void napuniNiz(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina) // Bazni slucaj kada brojac dođe do velicine, tu se rekurzija prekide jer ne zelimo pisati van opsega niza
		return;
	
	if (brojac < velicina) {
		
		if (brojac == 0) // Prvi element mora biti 2 prema postavci zadatka
			*(niz + brojac) = 2;
		
		if (brojac > 0) { // Svaki sljedeci element se nalazi kao umnozak prethodnog
			int temp = *(niz + brojac - 1) * 2;
			
			if (temp < 0) // U slucaju da se desi overflow na int temp, rekurzija se prekida
				return;
			
			*(niz + brojac) = temp;
		}

		// Rekurzija se nastavlja novim pozivom s tim što se brojac inkrementuje kako bi dosli do sljedeceg elementa
		napuniNiz(niz, velicina, brojac + 1);
	}
}

void provjeri(int* niz, int velicina, int izbor, int brojac) {

	// Prekida rekurziju kad dođe van opsega niza i ispise da nije nasao clan
	if (brojac == velicina)
	{
		cout << "Uneseni broj nije clan niza!" << endl;
		return;
	}

	// Ako nađe proslijeđeni broj (int izbor) onda ispise da ga je našao i prekida rekurziju
	if (brojac < velicina) {
		if (*(niz + brojac) == izbor)
		{
			cout << "Uneseni broj je clan niza!" << endl;
			return;
		}
		
		provjeri(niz, velicina, izbor, brojac + 1);
	}
}