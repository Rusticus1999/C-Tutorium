#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tausche(int*, int*);
void invertiere(char*, int);
/*

Aufgabe 1:
Implementiere die Invertiere Funktion ohne die Index schreibweise (name[i])
name == &name[0]
Optional mit scanf:
strlen() von string.h zählt die zeichen in einem string.

Aufgabe 2:
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
printf("Geben sie ihren Namen ein:");
char name[100];
scanf("%s",name);
int len = strlen(name);
printf("Länge = %d\n", len);
printf("%s\n", name);
invertiere(name, strlen(name));
printf("%s\n", name);

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
		save = *(&name[0] + i);
		*(name +i) =  *(&name[0] +len-1-i);
		*(&name[0] +len-1-i) = save;

	}
}
