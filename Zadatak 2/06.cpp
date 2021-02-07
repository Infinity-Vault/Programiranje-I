#include<iostream>
using namespace std;
bool prost(int);
bool palindrom(int);
int main()
{
	int unos;
	do
	{
		cout << "Unesite broj : " << endl;
		cin >> unos;
	}while(unos < 100);
	if (prost(unos) && palindrom(unos))
		cout << "Uneseni broj je i prost i palindrom." << endl;
	else
		cout << "Uneseni broj ne ispunjava jedan od uslova." << endl;
	cin.get();
	return 0;
}
bool prost(int broj)
{
	if (broj == 1)
		return false;
	for (int i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
bool palindrom(int broj)
{
	int kopija = broj, suma = 0;
	do
	{
		suma =suma* 10 + broj % 10;
		broj /= 10;
	} while (broj > 0);
	if (suma == kopija)
		return true;
	return false;
}
