## [**01**](01.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler (fudbaler je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

```c++
struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;
};
```

Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.

Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom. Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova. Radi lakšeg testiranja programa obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće:

```c++
godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve u rangu 1980 - 2000
brojIgraca: rand() % 30 + 1
golovi: rand() % 5
```

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**02**](02.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vozilo
{
    char *markaVozila;
    char *brojSasije;
    char *tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int *kubnihCM;
};
```

Redovi dvodimenzionalnog niza predstavljaju različite firme a u kolone različita vozila u tim firmama.
(radi jednostavnosti rješenja podrazumijevati da svaka firma ima isti broj vozila). 
Omogućiti korisniku unos svih podataka za sva vozila. 

Napisati i testirati funkciju koja će pronaći (firmu) koja ima največu prosječnu kubikazu vozila
(prosjek vrijednosti kubnihCM). 


Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila (prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno 
svih vozila tipa "B" u cijeloj matrici 

(Pošto se trazi u istoj funkciji, vodite računa o optimizaciji petlji jer to utiče na broj bodova). 

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**03**](03.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
```
Redovi matrice predstavljaju firme, kolone automobile.
Izračunati u kojoj je firmi najveća potrošnja goriva po km. 

Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**04**](04.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.
```c++
struct vremenska_prognoza
{
    char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float *temperatura;
    float *vlaznost_vazduha;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane. Omogućiti korisniku unos svih prognoza za sve meteorologe. 
Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane.
Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, odnosno koji je imao najmanju grešku u
procjeni temperatura.
Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.

**(U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**

## [**05**](05.cpp)
2D niz na slici predstavlja šahovsku tablu. Napraviti i testirati u main programu slijedeće funkcije:

a) Funkcija za unos elemenata tako da se u svako crno polje unese parni broj sa neparnim brojem cifara a u svako bijelo polje unese neparni broj sa parnim brojem cifara. 
b) Funkcija koja će računati aritmetičku sredinu svih brojeva na crnim poljima iznad glavne dijagonale.

Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji te kreirati dodatne funkcije po potrebi.

**(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)**


## [**06**](06.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove.
Omogućiti korisniku unos svih podataka za sve košarkaše, te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa).
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) NASAO; i najlošijeg košarkaša u kompletnoj ligi NASAO te izračunati razliku 
u broju postignutih koševa ta dva košarkaša. 

**(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)**


## [**07**](07.cpp)

Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.
```c++
struct figura
{
    int ID
    char *nazivFigure;
    float *visinaFigure;
}
```
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale. 

**(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)**

## [**08**](08.cpp)
Dat je 2D niz dimenzija 8 x 8.
Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svaki neparni red unesu parni brojevi a svaki parni red neparni broj.
Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata.
U istoj funkciji ispisati index pronađene kolone, a u main funkciji sve elemente te kolone.

## [**09**](09.cpp)

Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). 
Omogućiti korisniku da unese dimenzije niza.
```c++
struct uposlenik
{
    char *ID;
    char *imePrezime;
    float *plata;
}
```
Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici (radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika).

Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela 
(indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.

## [**10**](10.cpp)

Neka je dat 2D niz tipa int dimenzija 10x10. Kreirati, a potom u glavnom programu testirati, sljedeće funkcije:
a) Funkciju koja za vrsi generisanje podataka u 2D nizu na nacin da se u elementu sa indexom [0][0] upise vrijednost 1 a svaki slijedeci element da ima vrijednost prethodnog elementa pomnozenog sa 2 kao na slici.Generisanje se prekida ako se desi overflow na varijabli int.
b) Funkciju koja popunjenu matricu iz pod-zadatka a) transponuje tako sto joj zamjeni redove i kolone. 
c) Funkciju koja računa aritmetičku sredinu elemenata na "crnim poljima" iznad glavne dijagonale kao na slici

## [**11**](11.cpp)
Napisati program koji će omogućiti unos elemenata matrice dimenzija 10x10 cijelim brojevima sa neparnim brojem cifara.Za provjeru broja cifara koristiti funkciju brCif(int).
Zatim pronaći i ispisati red sa najvećim prosjekom (aritmetičkom sredinom) elemenata, te kolonu sa najmanjim prosjekom elemenata.

## [**12**](12.cpp)
Dat je 2D niz koji simulira šahovsku tablu. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svako "crno" polje unese parni broj sa neparnim brojem cifara, a u "bijelo polje neparni broj sa parnim brojem cifara.
Izračunati i ispisati prosjeke (aritmetičke sredine) svih elemenata na bijelim poljima iznad glavne dijagonale te na crnim poljima ispod sporedne dijagonale.

