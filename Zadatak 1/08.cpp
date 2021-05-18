#include <iostream>
using namespace std;

/*Omoguciti unos dva broja X i Y iz intervala od 10 do 5000. Kreirati program koji ce pronaci i ispisati sve brojeve od X do Y
(ukljucujuci granicne vrijednosti) za koje važi da je obrnuti broj djeljiv sa njegovom sumom cifara.
Za olakšanje rješenja zadataka napraviti funkcije za obrtanje poretka cifara i za sumu cifara.*/

int unos()
{
    int broj;
	do
	{
		cout << "Unesite broj od 10 do 5000 " << endl;
		cin >> broj;
	} while (broj < 10 || broj >5000);
	return broj;
}

int obrni(int broj)
{
	int novi = 0;
	while (broj > 0)
	{
		int temp = broj % 10;
		novi = novi * 10 + temp;
		broj /= 10;
	}return novi;
}

int suma(int broj)
{
	int suma = 0;
	while (broj > 0)
	{
		int temp = broj % 10;
		suma += temp;
		broj /= 10;
	}return suma;
}

int main()
{
	int x = unos();
	int y = unos();
	
	if (x > y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	cout << "Brojevi od " << x << " do " << y << " koji su obrnuti djeljivi sa sumom svojih cifara su : " << endl;
	for (int i = x; i <= y; i++)
	{
		if (obrni(i) % suma(i) == 0)
			cout << i << endl;
	}
	system("pause>0");
	return 0;
}
