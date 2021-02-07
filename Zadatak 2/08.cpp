#include <iostream>

using namespace std;

/*
 * Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo). Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1). Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja. U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.
 */

bool isProst(int n);

void ispis(int n1, int n2);

int main()
{
	int n1, n2;

	do
	{
		cout << "Unesite prvi prirodni broj: ";
		cin >> n1;
		cout << "Unesite drugi prirodni broj: ";
		cin >> n2;
		
	} while (n1 < 1 && n2 < 1);

	ispis(n1, n2);

	return 0;
}

bool isProst(int n)
{
	if (n == 1) // 1 po pravilu nije prost broj
		return false;

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

void ispis(int n1, int n2)
{
	if (n1 > n2)
	{
		int temp = n2;
		n2 = n1;
		n1 = temp;
	}

	n1 % 2 != 0 ? n1++ : 0;

	for (int i = n1; i <= n2; i += 2)
	{
		
		for (int j = i / 2, k = i / 2; j <= i; j++, k--)
		{
			if (isProst(j) && isProst(k))
			{
				cout << j << " + " << k << " = " << j + k << endl;
				break;
			}
		}
	}

}