#include <iostream>
using namespace std;

int rekurzija(int n, int k = 2, int l = 2)
{
	if (k * l == n)
		return n;
	else if (n > k * l)
		return rekurzija(n, k + 1, l + 1);
}

int main()
{
	int n;
	cout << "Unesite n " << endl;
	cin >> n;
	cout << rekurzija(n);
	system("pause>0");
	return 0;
}
