#include <iostream>
#include <cmath>
using namespace std;

int unos();
float unosX();
double Suma(int, float);
int main() {
	int n = unos();
	float X = unosX();
	cout << "Uneseni su n: " << n << " i X: " << X << " a njihova suma izracunata po formuli: S = cos(x) + cos(x^2 + cos(x^3) + ... + cos(x^n)) je:  " << Suma(n, X) << endl;



	cin.get();
	return 0;
}
int unos() {
	int n;
	do {
		cout << "Unesite prirodan broj: " << endl;
		cin >> n;
	} while (n < 1);
	return n;
}
float unosX() {
	float X;
	cout << "Unesite realan broj X: " << endl;
	cin >> X;
	return X;
}
double Suma(int n, float X) {
	double Suma = 0.0;
	for (int i = 1; i <= n; i++)
	{
		Suma += cos(pow(X, i));//ZAPAMTI DA JE BROJAC i A NE n!!!!
	}
	return Suma;
}
