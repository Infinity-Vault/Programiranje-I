#include <iostream>
using namespace std;
int unos();
bool djeljivost(int);
void ispisiBrojeve(int, int);
int brojCifri(int);
int main()
{
	int X = unos(), Y = unos();
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

//Drugi nacin  ako je nekome mozda jednostavniji za shvatiti: 

#include<iostream>
using namespace std;
bool ispitaj(int a)
{
        while (a)
        {
                if (a % 10 == 0)
                        return false;
                if (a % (a % 10) != 0)
                        return false;
                a /= 10;
        }
        return true;
}
int main()
{
        int x, y;
        while (cout << "Unesite x\t", cin >> x, x < 10 || x>6000);
        while (cout << "Unesite y\t", cin >> y, y < 10 || y>6000);
        if (x>y)
        {
                int y1 = y;
                y = x;
                x = y1;
        }
        for (size_t i = x; i <= y; i++)
        {
                if (ispitaj(i))
                        cout << "Broj " << i << " je djeljiv sa svim svojim ciframa\n";
        }
        cin.get();
        return 0;
}
