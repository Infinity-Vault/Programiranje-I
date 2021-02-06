#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generisiBacanja();

int main()
{
	srand(time(NULL));

	cout << "Tri ista broja dobila su se dva puta uzastopno nakon " << generisiBacanja() << " bacanja" << endl;
	
	return 0;
}

int generisiBacanja()
{
	int broj_bacanja = 0;
	int broj_istih = 0;

	do
	{
		int kocka1 = rand() % 6 + 1;
		int kocka2 = rand() % 6 + 1;
		int kocka3 = rand() % 6 + 1;

		if (kocka1 == kocka2 && kocka2 == kocka3)
		{
			broj_istih++;
		}

		else
			broj_istih = 0;

		broj_bacanja++;
		
	} while (broj_istih < 2);

	return broj_bacanja;
}
