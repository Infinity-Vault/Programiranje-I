#include <iostream>

using namespace std;

void puniNiz(int* niz, int n, int counter = 0);

void ispisNiz(int* niz, int n, int counter = 0);

int main()
{
	int n;

	cout << "Unesite velicinu niza: ";
	cin >> n;
	
	int* niz = new int[n];

	puniNiz(niz, n);

	cout << "Elementi niza sa faktorijelima su: ";
	ispisNiz(niz, n);
	
	return 0;
}

void puniNiz(int* niz, int n, int counter)
{
	if (counter == n)
		return;

	if (counter >= 0)
	{
		if (counter == 0)
			*(niz + counter) = 1;

		else
		{
			int temp = *(niz + counter - 1) * (counter + 1);

			if (temp < 0)
				return;

			*(niz + counter) = temp;
		}
	}

	puniNiz(niz, n, counter + 1);
}

void ispisNiz(int* niz, int n, int counter)
{
	if (counter == n)
		return;

	if (counter >= 0)
	{
		cout << *(niz + counter) << " ";
	}

	ispisNiz(niz, n, counter + 1);
}
