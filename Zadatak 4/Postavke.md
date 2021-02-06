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
godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve ur angu 1980 - 2000
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

U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. 
Obavezno koristiti aritmetiku pokazivača.

## [**03](03.cpp)
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

U zadataku koristiti artimetiku pokazivaca.