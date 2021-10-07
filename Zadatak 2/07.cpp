#include <iostream>
#include <ctime>
using namespace std;

bool prost(int broj)
{
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}if (broj == 1)
		return false;
	return true;
}

int unos()
{
	int broj;
	do
	{
		cout << "Unesite broj veci od 10 i manji od 1000 " << endl;
		cin >> broj;
	} while (broj < 10 || broj>1000);
	return broj;
}

int main()
{ 
	srand(time(0));
	int n = unos();
	float brojac = 0;

	for (int i = 0; i < n; i++)
	{
		int varijabla = rand() % 1000 + 1;
		if (prost(varijabla))
			brojac++;
	}
	cout << "Ima " << brojac << " prostih brojeva " << endl;
	cout << "Procenat prostih brojeva je " << brojac / n * 100.0 << " % " << endl;
	system("pause>0");
	return 0;
}
