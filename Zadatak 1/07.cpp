#include <iostream>

using namespace std;

/*
 * Napišite program, poštujući sve faze procesa programiranja, koji će ispisati
 * sve troznamenkaste brojeve koji su jednaki sumi faktorijela svojih znamenki – ABC = A! + B! + C!
 * Upotrijebite funkcije:
 */

void ispis();
int sumaFaktorijelaCifri(int n);

int main()
{
	ispis();

	
	return 0;
}

int sumaFaktorijelaCifri(int n)
{
	int suma = 0;

	while (n > 0)
	{
		int temp = n % 10;
		int faktorijel = 1;

		for (int i = 1; i <= temp; i++)
		{
			faktorijel *= i;
		}

		suma += faktorijel;
		n /= 10;
	}

	return suma;
}

void ispis()
{
	for (int i = 100; i <= 999; i++)
	{
		if (i == sumaFaktorijelaCifri(i))
			cout << i << endl;
	}
}