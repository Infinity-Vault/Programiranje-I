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

//Drugi nacin(ovaj nacin je tacniji nego prethodni)
//funkcija potencija isto radi sto i ugradjena funkcija pow.
//Funk. potencija radi tako sto ako naprimjer imamo 5 na trecu,u prvom krugu for petlje k(k je 5) pomnozi 5*5=25,i drugom krugu k postaje 25 te
// 25*=5 jeste 125 to vam je 5^3.
//u funkciji rekurzija pita je li m(sto je potencija) jednako ili vece trazenom broju n,ako jeste vraca broj najblizi n ili jednak n.
//else if ako je n i dalje vece od m poveca l za 1,tako sve u krug dok ne dodjemo do trazenog broja
#include <iostream>
using namespace std;

int potencija(int k, int l)
{

    int temp = k;
        for (int i = 1; i < l; i++)
        {
            k *= temp;
        }

    return k;
}
int rekurzija(int n, int k = 2, int l = 2) {
    int m = potencija(k, l);
    if (m >= n)
        return m;
    else if (n > m)
        return rekurzija(n, k, l + 1);

}
int main() {
    int n;
    cout << "Unesite n: " << endl;
    cin >> n;

    cout << "Broj priblizan n je :" << rekurzija(n);
    system("pause>null");
    return 0;
}
