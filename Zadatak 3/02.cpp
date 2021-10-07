#include <iostream>
using namespace std;

void rekurzija(int* niz, int vel, int brojac = 0)
{
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = 2;
	else
	{
		if (*(niz + brojac - 1) * 2 < 0)
			return;
		else
			*(niz + brojac) = *(niz + brojac - 1) * 2;
	}
	rekurzija(niz, vel, brojac + 1);
}

void ispis(int* niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cout << *(niz + i) << endl;
}

bool provjera(int* niz, int vel, int izbor, int brojac = 0)
{
	if (brojac == vel)
		return false;
	if (*(niz + brojac) == izbor)
		return true;
	provjera(niz, vel, izbor, brojac + 1);
}
int main()
{
	int vel, izbor;
	do
	{
		cout << "Unesite velicinu niza " << endl;
		cin >> vel;
	} while (vel < 2);
	int* niz = new int[vel];
	rekurzija(niz, vel);
	ispis(niz, vel);
	cout << "Unesite broj za koji zelite provjeriti da li se nalazi u nizu " << endl;
	cin >> izbor;
	if (provjera(niz, vel, izbor))
		cout << "Broj " << izbor << " se nalazi u nizu " << endl;
	else
		cout << "Broj " << izbor << " se ne nalazi u nizu " << endl;
	delete[]niz;
	niz = nullptr;
	system("pause>0");
	return 0;
}
