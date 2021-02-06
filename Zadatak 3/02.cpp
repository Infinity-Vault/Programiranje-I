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
	if (brojac == velicina)
		return;
	if (brojac < velicina) {
		if (brojac == 0)
			*(niz + brojac) = 2;
		if (brojac == 1)
			*(niz + brojac) = *(niz + brojac - 1) * 2;
		if (brojac > 1) {
			int temp = *(niz + brojac - 1) * 2;
			if (temp < 0)
				return;
			*(niz + brojac) = temp;
		}
		napuniNiz(niz, velicina, brojac + 1);
	}
}
void provjeri(int* niz, int velicina, int izbor, int brojac) {
	if (brojac == velicina)
		return;
	if (brojac < velicina) {
		if (*(niz + brojac) == izbor) 
			cout << "Uneseni broj je clan niza!" << endl;
		provjeri(niz, velicina, izbor, brojac + 1);
	}
}