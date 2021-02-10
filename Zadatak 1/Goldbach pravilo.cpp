#include <iostream>
using namespace std;
/*
* Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja
obavlja zadani posao.
*/
int unos();
bool prost(int);
void Goldbach(int);
void poziv(int, int);

int main() {
int n1, n2;
n1 = unos();
n2 = unos();
poziv(n1, n2); 
return 0;
}
int unos() {
int broj;
broj = rand() % 1000 + 1;
return broj;
}
bool prost(int broj) {
for (int i = 2; i <= broj/2; i++)
{
if (broj % i==0)
return false;
}
if (broj == 1)
return false;
return true;
}
void Goldbach(int broj) {
for (int i = broj/2,j=broj/2; i <=broj; i++,j--)
{
if (prost(i) && prost(j)) {
cout << broj << "=" << i << "+" << j << endl;
break;
}
}
}
void poziv(int n1, int n2) {
if (n1 % 2 != 0) {
n1++;
}
if (n1 > n2) {
int temp = n1;
n1 = n2;
n2 = temp;
}
for (int i = n1; i <n2 ; i+=2)
{
Goldbach(i);
}
}
