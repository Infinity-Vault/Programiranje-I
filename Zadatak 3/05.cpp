#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	else
	{
		*(niz + brojac) = rand() % 100 + 1;
		if (*(niz + brojac) == *(niz + brojac - 1) && *(niz + brojac) == *(niz + brojac - 2))
			return;
	}
	rekurzija(niz, vel, brojac + 1);
}

int main()
{
	srand(time(0));
	int vel;
	do
	{
		cout << "Unesite velicinu niza " << endl;
		cin >> vel;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);
	for (int i = 0; i < vel; i++)
		cout << *(niz + i) << endl;
	delete[]niz;
	niz = nullptr;
}
