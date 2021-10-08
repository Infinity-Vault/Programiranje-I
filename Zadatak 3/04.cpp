#include <iostream>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = 1;
	else
	{
		*(niz + brojac) = *(niz + brojac - 1) * brojac;
		if (*(niz + brojac - 1) * brojac < *(niz + brojac))
			return;
	}
	rekurzija(niz,vel, brojac + 1);
}

void ispis(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cout << *(niz + i) << endl;
}

int main()
{
	int vel;
	do
	{
		cout << "Unesite velicinu niza " << endl;
		cin >> vel;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);
	ispis(niz, vel);
	delete[]niz;
	niz = nullptr;

	system("pause>0");
	return 0;
}
