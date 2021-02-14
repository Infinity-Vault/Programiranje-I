#include <iostream>
using namespace std;
int unos();
bool djeljivost(int);
void ispisiBrojeve(int, int);
int brojCifri(int);
int main()
{
	int X = unos(), Y = unos();
	//cout << djeljivost(13);
	ispisiBrojeve(X, Y);


	cin.get();
	return 0;
}
int unos()
{
	int br;
	do
	{
		cout << "Unesite broj: " << endl;
		cin >> br;
	} while (br < 10 || br>6000);
	return br;
}
bool djeljivost(int broj)
{
	int brojac = 0;
	int cifra;
	int kopija = broj;
	while (broj > 0)
	{
		cifra = broj % 10;
		if (cifra != 0) {
			if (kopija % cifra == 0) {
				brojac++;
				broj /= 10;
			}
			else
				broj /= 10;
		}
		else
		{
			brojac--;
			broj /= 10;
		}

	}
	if (brojac == brojCifri(kopija))//Samo ako je svaka cifra unesenog broja djeljiva sa njim, ce se vratiti true!
		return true;
	else
		return false;
}
int brojCifri(int broj)
{
	int brojac = 0;
	while (broj > 0)
	{
		broj /= 10;
		brojac++;
	}
	return brojac;
}
void ispisiBrojeve(int X, int Y)
{
	if (X > Y)
	{
		int temp = Y;
		Y = X;
		X = temp;
	}
	cout << "Brojevi koji su djeljivi svim svojim ciframa iz datog intervala  su: " << endl;
	for (int i = X; i <= Y; i++)
	{
		if (djeljivost(i))
			cout << i << " ";
	}
}
