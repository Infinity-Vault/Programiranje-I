
#include <iostream>
#include <cmath>
using namespace std;
	float sinx(float);
	float cosx(float);
	int main() {
	float broj = 0.0f;
	char izbor;
	cout << "Unesite neki realan broj. " << endl;
	cin >> broj;
	do{
		cout << "Odaberite funkciju. s za sinus i c za cosinus." << endl;
		cin >> izbor;
		if (izbor == 's')
		cout << sinx(broj);
		else if (izbor == 'c')
		cout << cosx(broj);
		else cout << "Niste unijeli odgovarajuci unos. Molimo unesite ispravnu funkciju." << endl;
	} while (izbor !='s' && izbor!='c');
		system("pause>null");
		return 0;
	}
	float sinx(float broj) {
	double suma=1.0f;
	float const PI = 3.14159265;
	for (int i = 1; i <= broj; i++)
	{
		suma += i / (sin(PI / 180 *( broj / i)) + broj);
	}
	cout << "Rezultat unesene funkcije je: ";
	return suma;
	}
	float cosx(float broj) {
	double suma = 1.0f;
	float const PI = 3.14159265;
	for (int i=1 ; i <= broj; i++)
	{
		suma += i / (cos(PI / 180 *(broj / i)) + broj);
	}
	cout << "Rezulatat unesene funkcije je: ";
	return suma;
}
