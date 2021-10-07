#include <iostream>
using namespace std;

void unos(int& broj)
{
	cout << "Upisi cifru " << endl;
	cin >> broj;
}

int main()
{
	int broj = 0, novi = 0;
	do
	{
		unos(broj);
		if (broj <= 9 && broj >= 0)
		{
			novi = novi * 10 + broj;
		}

		if (broj > 9)
		{
			cout << "Cifra nije validna " << endl;
		}
	} while (broj >= 0);

	cout << "Sastavljen broj je " << novi << endl;
	system("pause>0");
	return 0;
}
