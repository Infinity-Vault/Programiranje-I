#include <iostream>
using namespace std;

int unesi();
int Faktorijel(int);
float Suma(int);
int  main() {
	int n = unesi();
	cout << "Suma je: " << Suma(n) << endl;



	cin.get();
	return 0;
}
int unesi() {
	int n;
	cout << "Unesite cijeli broj n: " << endl;
	cin >> n;
	return n;
}
int Faktorijel(int broj) {
	int F = 1;
	for (int i = 1; i <= broj; i++)
	{
		F *= i;
	}
	return F;
}
float Suma(int n) {
	float Suma = 0;
	for (int i = 1; i <= n; i++)
	{
		Suma += pow(-1, i - 1) * (i / 1 + (Faktorijel(i)));
	}
	return Suma;
}