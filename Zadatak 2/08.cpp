#include <iostream>
using namespace std;
const int x = 100;

long long int Fibonacci(int);
void napuniNizfibonacciElementima(long long int[]);
void ispisiNiz(long long int[]);
bool prost(long long int&);
long long int Zbirfaktorijela(long long int[]);
long long int Faktorijel(long long int);
int main() {
	//Kod radi okej ja mislim samo je eksikucija duga..., zato sto je bila koristena rekurzivna funkcija
	long long int niz[x];
	napuniNizfibonacciElementima(niz);
	ispisiNiz(niz);
	cout << "Zbir faktorijela prvih 100 prostih elemenata Fibonacci niza je: " << Zbirfaktorijela(niz);

	cin.get();
	return 0;
}
long long int Fibonacci(int broj) {
	/*if (broj <= 1)
		return 1;
	else {
		return Fibonacci(broj - 2) + Fibonacci(broj - 1);
	}*/
	int prvi = 1;
	int drugi = 1;
	int treci = 0;
	if (broj == 0)
		return 1;
	if (broj == 1)
		return 1;
	for (int i = 2; i <= broj; i++)//Ide od dva jer prva dva zna da su 1 i 1 ( a ide od dva a ne od 3 kao sto bi norm fibb jer ovdje ide indeksacija od nule );
	{
		treci = prvi + drugi;
		prvi = drugi;
		drugi = treci;
	}
	return treci;

}
void napuniNizfibonacciElementima(long long int niz[]) {
	for (int i = 0; i < x; i++)
	{
		niz[i] = Fibonacci(i);
	}
	cout << endl;
}
void ispisiNiz(long long int niz[]) {
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}
bool prost(long long int& broj) {
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	if (broj == 1)
		return false;
	return true;
}
long long int Zbirfaktorijela(long long int niz[]) {
	long long int suma = 0;
	for (int i = 0; i < x; i++)
	{
		if (prost(niz[i])) {
			suma += Faktorijel(niz[i]);
		}
	}
	return suma;

}
long long int Faktorijel(long long int broj) {
	long long int F = 1;
	for (int i = 1; i <= broj; i++)
	{
		F = F * i;
	}
	return F;
}

