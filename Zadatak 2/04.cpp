#include <iostream>
using namespace std;

bool isProst(int broj)
{
	for (int i = 2; i < broj; i++)		// Obicna funkcija za provjeravanje prostog broja.
		if (broj % i == 0)
			return false;
	return true;						
}

void Goldbach(int broj)
{
	for (int i=broj/2, j=broj/2; i<=broj; i++, j--)
		if (isProst(i) && isProst(j))				// Brojaci krecu sa polovine broja, prvi se povecava a drugi smanjuje.
		{
			cout << broj << "=" << i << "+" << j << endl;
			return;				// Return koristimo kao prekid funkcije jer nam je dovoljan samo jedan dokaz, a u isto vrijeme i ubrzava izvrsenje koda.
		}
}


int main() 
{
	int n1, n2;
	do {
		cout << "Unesite n1: ";
		cin >> n1;
		cout << "Unesite n2: ";
		cin >> n2;
	} while (n1 == n2 || n1>n2);					// n1 i n2 ne smiju biti jednaki, niti n1 smije biti veci od n2.

	if (n1 % 2 != 0)
		n1++;			// Zbog iduce for petlje trebamo poceti sa parnim brojem, inace ce petlja ici kroz neparne brojeve, u slucaju da je n1 neparan, u ovoj liniji koda se n1 povecava za 1, sto ga cini parnim.
	
	for (int i = n1; i <= n2; i += 2)			// For petlja prolazi kroz sve parne brojeve u intervalu i salje ih u funkciju Goldbach.
		Goldbach(i);
	
	return 0;
}
