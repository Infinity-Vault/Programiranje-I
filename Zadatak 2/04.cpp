#include<iostream>
using namespace std;

/*
Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo). Napisati program koji će najprije učitati
dva prirodna broja n1 i n2 (n2 > n1). Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.
*/

bool Prost(int);
void Goldbach(int);
void PozivGoldbacha(int, int);

int main()
{
	int n1, n2;
	do
	{
		cout << "Unesite prvi prirodan broj: " << endl;
		cin >> n1;
		cout << "Unesite drugi prirodni broj: " << endl;
		cin >> n2;
	
	} while (n1 <= 0 || n2 <= 0);
	cout << endl;

	PozivGoldbacha(n1, n2);

	system("pause>0");
	return 0;
}

bool Prost(int broj)
{
	for (int i = 2; i < broj; i++)
		if (broj % i == 0)
			return false;
	return true;
}

void Goldbach(int broj)
{
	for (int i = broj / 2, j = broj / 2; i <= broj; i++, j--)
		if (Prost(i) && Prost(j))
		{
			cout << broj << "=" << i << "+" << j << endl;
			break;
		}
}

void PozivGoldbacha(int n1, int n2)
{
	if (n1 > n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	if (n1 % 2 != 0)
		n1++;
	for (int i = n1; i <= n2; i += 2)
		Goldbach(i);
}
