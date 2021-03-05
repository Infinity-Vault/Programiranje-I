#include <iostream>
#include <time.h> //sluzi nam da ukljucimo komande napisane u 10-toj liniji koda
using namespace std;

void punjenje(int*, int, int brojac = 0); //funkcija sa kojom cemo rekurzivno puniti niz, brojac je ono pomocu cega cemo znati do kojeg elementa smo dosli, ovdje ga odmah inicijalizujemo na nulu

void ispis(int*, int, int brojac = 0); //funkcija sa kojom cemo rekurzivno ispisati niz, brojac ima istu svrhu kao i gore navedenu

int main() {
	srand((time(0))); //sluzi nam za postavljanje uvijek drugih slucajnih brojeva pri pisanju rand funkcije
	int n;
	cout << "Molim vas unesite duzinu niza koju zelite : " << endl; //unosimo velicinu niza, ovo smo mogli i preporuceno bi bilo uraditi sa while petljom jer ovaj broj mora uvijek biti pozitivan
	cin >> n;
	int* niz = new int[n]; //kreiramo dinamicki jednodimenzionalni niz
	punjenje(niz, n); //pozivamo funkciju za punjenje niza
	//Ispis:
	//for (int i = 0; i < n; i++)
	//{
	//	cout << *(niz + i) << " ";
	//}
	cout << endl;
	ispis(niz, n); //pozivamo funkciju za ispis niza




	//Dealokacija:
	delete[]niz;
	niz = nullptr;
	cin.get();
	return 0;
}
void punjenje(int* niz, int n, int brojac) { //n nam je nasa velicina niza koju korisnik unese
	if (brojac == n) //ako je brojac koji nam broji koliko se je puta rekurzija izvrsila postane jednak broju n tj. unesenoj velicini niza to znaci da smo popunili cjeli niz i ovo nam je bazni slucaj te onda rekurziju prekidamo returnom
		return;
		
			*(niz + brojac) = rand() % 100 + 1; //punimo niz sa nasim random brojem
		if (brojac > 1) { //provjeravamo da li je brojac presao 2 elementa u nizu jer onda tek ce se mozda ispuniti donji uslov
			if (*(niz + brojac) == *(niz + brojac - 1) && *(niz + brojac) == *(niz + brojac - 2)) { //gledamo da li su 3 uzastopna elementa ista, ako je to slucaj onda prekidamo rekurziju pisanjem returna
				return;
			}
		}
	
	punjenje(niz, n, brojac + 1); //uvijet ponavljanja rekurzije gdje u biti sve sto moramo raditi je povecavati nas brojac da znamo do kojeg smo elementa u nizu dosli
}
void ispis(int* niz, int n, int brojac) {
	if (brojac == n) //ako je brojac koji nam broji koliko se je puta rekurzija izvrsila postane jednak broju n tj. unesenoj velicini niza to znaci da smo popunili cjeli niz i ovo nam je bazni slucaj te onda rekurziju prekidamo returnom
		return;

		cout << *(niz + brojac) << " "; //ispisivamo elemenat niza

		ispis(niz, n, brojac + 1);//uvijet ponavljanja rekurzije gdje u biti sve sto moramo raditi je povecavati nas brojac da znamo do kojeg smo elementa u nizu dosli

}
