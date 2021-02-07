#include <iostream>

using namespace std;



int unos();
int prosjekProst(int n);

bool prost(int broj);

int main()
{
	srand(time(0));
	int n = unos();

	cout << "Prosjek prostih brojeva medju nasumicnim brojevima je: " << prosjekProst(n) << "%" << endl;
}

int unos()
{
	int n;

	do
	{
		cout << "Unesite broj n (10 <= n <= 1000): ";
		cin >> n;
	} while (n < 10 || n > 1000);

	return n;
}

int prosjekProst(int n)
{
	int prosjek_prostih = 0;
	int temp_n = n;
	
	while (temp_n != 0)
	{
		int temp = rand() % 1000 + 1;

		if (prost(temp))
			prosjek_prostih++;

		temp_n--;
	}
	
	return  (float)prosjek_prostih / n * 100;
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