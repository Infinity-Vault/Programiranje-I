#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float unosX();
int unosm();
float izracunaj_Izraz(float, int);
int main() {
	int X = unosX();
	int m = unosm();
	cout << "Izraz za unesen parametre iznosi: " << setprecision(3) << izracunaj_Izraz(X, m) << endl;
	cin.get();
	return 0;
}
float unosX() {
	float X;
	cout << "Unesite realan broj X: " << endl;
	cin >> X;
	return X;
}
int unosm() {
	int m;
	cout << "Unesite cijeli broj m: " << endl;
	cin >> m;
	return m;
}
float izracunaj_Izraz(float X, int m) {
	float Izraz = 0;
	char izbor;
	do {
		cout << "Unesite 's' za izracun sin, 'c' za izracun cos, 'q' za izracun korijena ili 'p' za izracun stepenovanja: " << endl;
		cin >> izbor;
		if (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p')
			cout << "POGRESAN UNOS !" << endl;
	} while (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p');
	switch (izbor) {
	case 's': {
		for (int i = 1; i <= m; i++)
		{
			Izraz += i / (sin(X / i) + X);
		}
		return Izraz;
	}break;
	case 'c': {
		for (int i = 1; i <= m; i++)
		{
			Izraz += i / (cos(X / i) + X);
		}
		return Izraz;
	}break;
	case'q': {
		for (int i = 1; i <= m; i++)
		{
			Izraz += i / (sqrt(X / i) + X);
		}
		return Izraz;

	}break;
	case'p': {
		for (int i = 1; i <= m; i++)
		{
			Izraz += i / (pow(X / i, 2) + X);
		}
		return Izraz;
	}break;
	default: {
		cout << "Doslo je do greske, molim Vas pokrenite program ponovno! " << endl;
	}
	}
}