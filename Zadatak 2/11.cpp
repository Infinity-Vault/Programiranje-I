#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

float unosX();
int  unosm();
float proracun_Izraza(float, int);
int main() {
	float X = unosX();
	int m = unosm();
	cout << "Izraz za unesene parametre iznosi: " << proracun_Izraza(X, m) << endl;


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
float proracun_Izraza(float X, int m) {
	float Izracun = 1;//Mnoozi se !!! Ako stavis na 0 sve ce biti nula UVIJEK;
	char izbor;
	do {
		cout << "Unesite 's' za proracun sin izraza, 'c' za proracun cos, 'q' za proracun korijena ili 'p' za proracun stepena: " << endl;
		cin >> izbor;
		if (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p')
			cout << "POGRESAN UNOS!" << endl;
	} while (izbor != 's' && izbor != 'c' && izbor != 'q' && izbor != 'p');
	switch (izbor) {
	case 's': {
		for (int i = 1; i <= m; i++)
		{
			Izracun *= (sin(X) + i);
		}
		return Izracun;
	}break;
	case 'c': {
		for (int i = 1; i <= m; i++)
		{
			Izracun *= (cos(X) + i);
		}
		return Izracun;
	}break;
	case 'q': {
		for (int i = 1; i <= m; i++)
		{
			Izracun *= (sqrt(X) + i);
		}
		return Izracun;
	}break;
	case 'p': {
		for (int i = 1; i <= m; i++)
		{
			Izracun *= (pow(X, 3) + i);
		}
		return Izracun;
	}break;
	default: {
		cout << "Doslo je do greske, pokrenite ponovno program!" << endl;
	}
	}
}