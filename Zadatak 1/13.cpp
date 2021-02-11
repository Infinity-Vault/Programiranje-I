#include <iostream>
using namespace std;

float unosX();
int unosm();
void Izracun(float, int);
int main() {
	float X = unosX();
	int m = unosm();
	Izracun(X, m);










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
	do {
		cout << "Unesite broj m: " << endl;
		cin >> m;
	} while (m <= 0);
	return m;
}
void Izracun(float X, int m) {
	char izbor;
	do {
		cout << "Unesite karakter:'s' (sabiranje), 'o' (oduzimanje), 'm' (mnozenje), 'd' (dijeljenje): " << endl;
		cin >> izbor;
		if (izbor != 's' && izbor != 'o' && izbor != 'm' && izbor != 'd')
			cout << "Izbor nije validan!" << endl;
	} while (izbor != 's' && izbor != 'o' && izbor != 'm' && izbor != 'd');

	switch (izbor) {
	case 's': {
		long float suma = 0;
		for (int i = 1; i <= m; i++)
		{
			suma += (X - i) * i;
		}
		cout << "Suma je: " << suma << endl;
	}break;
	case 'o': {
		long float razlika = 0;
		for (int i = 1; i <= m; i++)
		{
			razlika -= (X - i) * i;
		}
		cout << "Razlika je: " << razlika << endl;
	}break;
	case 'm': {
		long float umnozak = 1;
		for (int i = 1; i <= m; i++)
		{
			umnozak *= (X - i) * i;
		}
		cout << "Umnozak je: " << umnozak << endl;
	}break;
	case 'd': {
		long float kolicnik = 1;
		for (int i = 1; i <= m; i++)
		{
			kolicnik /= (X - i) * i;
		}
		cout << "Kolicnik je: " << kolicnik << endl;
	}break;
	default: {
		cout << "Doslo je do greske, pokrenite program ponovno!" << endl;
	}
	}
}