#include <iostream>
using namespace std;

void punjenjeNiza(int*, int, int brojac = 0);
void ispisNiza(int*, int, int brojac = 0);
int main() {
	int velicina;
	cout << "Unesite velicinu niza koju zelite: " << endl;
	cin >> velicina;
	int* niz = new int[velicina] {};
	punjenjeNiza(niz, velicina);
	ispisNiza(niz, velicina);


	//Dealokacija:
	delete[] niz;
	niz = nullptr;
	cin.get();
	return 0;
}
void punjenjeNiza(int* niz, int velicina, int brojac) {
	if (brojac == velicina)
		return;
	if (brojac < velicina) {
		if (brojac == 0)
			*(niz + brojac) = 2;
		if (brojac > 0) {
			int temp = pow(*(niz + brojac - 1), 3);
			if (temp < 0)
				return;
			*(niz + brojac) = temp;
		}
		punjenjeNiza(niz, velicina, brojac + 1);
	}
}
void ispisNiza(int* niz, int velicina, int brojac) {
	if (brojac == velicina)
		return;
	cout << *(niz + brojac) << " ";
	ispisNiza(niz, velicina, brojac + 1);
}