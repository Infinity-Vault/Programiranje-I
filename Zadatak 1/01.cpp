#include <iostream>
#include <cmath>

using namespace std;

float proracun(float x, char izbor);

int main()
{
	float x;
	char izbor;

	cout << "Unesite realni broj x: ";
	cin >> x;

	do
	{
		cout << "Unesite zeljenu funkciju (s - sin, c - cos): ";
		cin >> izbor;

		if (izbor != 's' && izbor != 'c')
			cout << "Niste unijeli korektnu funkciju, ponovite unos" << endl;
		
	} while (izbor != 's' && izbor != 'c');

	cout << "Proracun datog izraza je: " << proracun(x, izbor) << endl;

	return 0;
}

float proracun(float x, char izbor)
{
	if (izbor == 's')
	{
		float rezultat = 0.0f;

		for (int i = 1; i <= x; i++)
		{
			rezultat += i / (sin(x / i) + x);
		}

		return rezultat;
	}

	else
	{
		float rezultat = 0.0f;

		for (int i = 1; i <= x; i++)
		{
			rezultat += i / (cos(x / i) + x);
		}

		return rezultat;
	}
}