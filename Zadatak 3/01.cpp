#include <iostream>
using namespace std;

void napuniNiz(int*, int, int brojac = 0);
void ispisiNiz(int*, int, int brojac = 0);
long long int suma(int*, int, int brojac = 0);

int main() {
	
	int velicina;
	
	do {
		cout << "Unesite velicinu niza: " << endl;
		cin >> velicina;
	} while (velicina < 2);
	
	int* niz = new int[velicina] {};//{} - inicijalizacija 0;
	napuniNiz(niz, velicina);//Treci parametar je default;
	ispisiNiz(niz, velicina);//Treci parametar je default;
	cout << endl;
	
	cout << "Suma svih elemenata niza je: " << suma(niz, velicina);//Treci parametar je default;

	//Dealokacija:
	delete[] niz;
	niz = nullptr;
	cin.get();
	return 0;
 }

void napuniNiz(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina)
		return;//Bazni;
	
	if (brojac < velicina) {
		
		if (brojac == 0)
			*(niz + brojac) = 1;
		
		if (brojac == 1)
			*(niz + brojac) = 3;
		
		if (brojac > 1) {
			int temp = *(niz + brojac - 1) * *(niz + brojac - 2);
			
			if (temp < 0)
				return;//U slucaju  overflowa;
			
			*(niz + brojac) = temp;
		}
		napuniNiz(niz, velicina, brojac + 1);
	}
}

void ispisiNiz(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina)
		return;//Bazni;
	
	cout << *(niz + brojac) << " ";
	
	ispisiNiz(niz, velicina, brojac + 1);
}

long long int suma(int* niz, int velicina, int brojac) {
	
	if (brojac == velicina)
		return 0;
	
	return *(niz + brojac) + suma(niz, velicina, brojac + 1);
}
