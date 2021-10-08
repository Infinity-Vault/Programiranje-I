#include<iostream>
#include<ctime>
using namespace std;

bool savrsen(int broj)
{
	int suma = 0;
	for (int i = 1; i < broj; i++)
	{
		if (broj % i == 0)
			suma += i;
	}

	if (broj == suma)
		return true;
	return false;
}

int unos()
{
	int broj;
	do
	{
		cout << "Unesite broj od 10 do 1000 " << endl;
		cin >> broj;
	} while (broj < 10 || broj>1000);
	return broj;
}


int main()
{
	srand(time(0));
	int n = unos();
	float brojac = 0;
	for (int i = 0; i<n; i++)
	{
		int varijabla = rand() % 1000 + 1;
		if (savrsen(varijabla))
			brojac++;
	}

	cout << "Ima " << brojac << " savrsenih brojeva " << endl;
	cout << "Prosjek savrsenih brojeva je "<< brojac / n * 100.0 << "%"<<endl;
	system("pause>0");
	return 0;
}
