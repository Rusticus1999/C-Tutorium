#include<stdio.h>
#include<stdlib.h>
void tausche(int*, int*);
void invertiere(char*, int);
/*
Aufgabe 1:
Deklarariere und initialisiere die 2 int variablen a und b mit 1 und 2
Deklariere die Funktion tausche

Aufgabe 2:
Implementiere die Funktion tausche.
Sie bekommt die 2 variablen in main Übergeben und Tauscht deren Rückgabewerte.

Entwickle erst einen Ansatz. Was könnte Schiefgehen?

Aufgabe 3:
Allokiere und räume den Speicher in main um deinen Namen global zu Speichern. Welchen Datentypen braucht dieses Array?
Schreibe eine Funktion invert die den namen umdreht.

Aufgabe 4:
Schreibe einen Passwortgenerator benutze dazu rand() und int('0').

Aufgabe 5:
Smart Home
In einem smarten Haushalt gibt es 8 Lampen die ein und ausgeschaltet werden müssen:

Schreibe Funktionen um folgende Funktionalitäten zu implementieren:
-Ausgabe der Lampen in der Konsole als serie von 0en und 1en.
-Ein schalten einzelner Lampen.
-Ausschalten einzelner Lampen.
-Umschalten einzelner Lampen.
-Umschalten aller Lampen ohne nutzung der vorherigen Funktion.
-Lauflicht rechtsrum oder linksrum.

*/

int main(int argc, char* argv[]){

printf("Basic\n");
/*
int a = 1;
int b = 2;
printf("Adressen a %p b %p\n", &a, &b);
printf("a = %d, b = %d\n", a,b);

tausche(&a, &b);

printf("a = %d, b = %d\n", a,b);
*/

char *name = (char*) malloc(4*sizeof(char));
printf("%s\n", name);
char namefill[] = "Nico";
for(int i = 0; i < 4; i++)
{
	name[i] = namefill[i];
}
printf("%s\n", name);
invertiere(name, 4);
printf("%s\n", name);

free(name);
return 0;
}

void tausche(int *pa, int* pb){
	printf("Adressen a %p b %p\n", pa, pb);
	int c = 0;
	c = *pa;
	*pa = *pb;
	*pb = c;

}

void invertiere(char* name, int len){
	char save;
	for(int i = 0; i < len/2; i++){
		save = name[i];
		name[i] = name[len-1-i];
		name[len-1-i] = save;

	}
}
