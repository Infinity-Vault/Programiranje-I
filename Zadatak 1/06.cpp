#include <iostream>

using namespace std;

int SumaFaktorijela(int);

int faktorijel(int);

int main() {
	int N;
	cout << "Unesite neki cijeli broj: " << endl;
	cin >> N;
	cout << "Suma faktorijela svih neparnih brojeva do unesenog broja je: " << SumaFaktorijela(N) << endl;

	cin.get();
	return 0;
}
int SumaFaktorijela(int N) {
	int suma = 0;
	for (int i = 1; i < N; i += 2)//Kontrola petlje da se samo krece po neparnim;
	{
		suma += faktorijel(i);
	}
	return suma;
}
int faktorijel(int broj) {
	int Faktorijel = 1;
	for (int i = 1; i <= broj; i++)
	{
		Faktorijel = Faktorijel * i;
	}
	return Faktorijel;
}