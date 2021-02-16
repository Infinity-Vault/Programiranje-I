#include <iostream>
using namespace std;
const int x = 10, y = 10; //deklarisemo konstante matrice koja ima 10 redova (x) i 10 kolona (y)
int niz[x][y]; //pravimo matricu


void unos(int[][y]); //funkcija za unos elemenata u matricu
void ispis(int[][y]); //funkcija za ispis elemenata matrice
void obrni(int[][y]); //funkcija koja mjenja sadrzaj redova i kolona jedno sa drugim
void Aritmeticka_sredina_nacrnim_Poljima(int[][y]);
int main() {

	unos(niz);
	ispis(niz);
	obrni(niz);
	Aritmeticka_sredina_nacrnim_Poljima(niz);


	cin.get();
	return 0;

}
void unos(int niz[][y]) {
	//OVAJ NACIN RADI ALI STANE NA 1024...
	/*niz[0][0] = 1;
	for (int i = 0; i < x; i++)
	{
		for (int j = 2; j <= y; j++)
		{
			niz[0][1] = 2;
			niz[0][2] = 4;
			int temp;
			temp = niz[i][j - 1] * 2;
			if (temp < 0)
				niz[i][j] = 0000;
			niz[i][j] = temp;
		}
	}*/

	//Drugi nacin:
	bool overflow = false; //sa ovom varijablom provjeravamo da li je doslo do overflowa
	int eksponent = 0;//Svaki broj na 0 je 1!
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			niz[i][j] = pow(2, eksponent);
			eksponent++;
			if (niz[i][j] < 0) { //ako je doslo do owerflowa onda ce trenutni element niza otici u minus jer je to najmanja moguca vrijednost kod intidzera i to gledamo da lis e je desilo
				//return;
				niz[i][j] = 0; //ako se to desava onda nek se trenutni clan na kojem je bio owerflow vrati na 0
				overflow = true;
			}
		}
		if (overflow) //ako je ovo ispunjeno nek se izade iz for petlje
			break;
	}
}
void ispis(int niz[][y]) {
	cout << endl;
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[i][j] << "\t";
		}
		cout << endl;
	}
}
void obrni(int niz[][y]) {
	cout << endl;
	cout << "Elementi niza su: " << endl;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << niz[j][i] << "\t";
		}
		cout << endl;
	}
}
void Aritmeticka_sredina_nacrnim_Poljima(int niz[][y]) {
	long double Average = 0;
	int brojacProlaza = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)//Stavimo j=i da bi uzimao i elemente sa glavne dijagonale a i iznad , ali posto se nama trazi IZNAD glavne dijagonale ne treba nam ovo;
		{
			if (i < j && (i + j) % 2 == 0) {
				Average += niz[i][j];
				brojacProlaza++;
			}
		}
	}
	cout << "Aritmeticka sredina svih brojeva na crnim poljima iznad glavne dijagonale je: " << Average / brojacProlaza << endl;
}
