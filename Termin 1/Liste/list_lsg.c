#include<stdio.h>
#include<stdlib.h>

//Definition von methoden
void ListInit();
struct node *InsertIndex(int, int);
struct node *InsertAfter(int, struct node *);
int getSize();
struct node *getByIndex(int);
struct node *getByData(int);
int removeIndex(int);
int removeData(int);
void printIndex(int);
void printNode(struct node *);
void cleanup();

//Knoten
struct node{
	int data;
	struct node *Next;
};

//globale Zeiger für Head und Tail
struct node *Head, *Z;

//Main
int main(int argc, char* argv[]){
	printf("Aufgaben\n 1)Die fehlenden Methoden zu implementieren. \n 2)Die Liste umdrehen und ausgeben. \n3)Die Liste bereinigen mit dem eigenen Namen füllen und den Namen alphabestisch sortieren und ausgeben.\n");

	ListInit();
	
	
	cleanup();
return 0;
}


//Funktionen implementierung

void ListInit(){
	//Speicher allokieren. Achtung muss irgenwann noch freigegeben werden!
	Head = (struct node *) malloc(sizeof(*Head));
	Z = (struct node *) malloc(sizeof(*Z));
	//Liste Verknüpfen
	Head->Next = Z;
	Z->Next = Z;
	//Startknoten mit Daten versehen
	Head->data = -1;
	Z->data = -2;
	//Testliste konstruieren
	char wort[] = "Liste";
	struct node *vor = Head;
	for(int i = 0; i < (sizeof(wort)); i++){
		//printf("durchlauf %d\n",i);
		vor = InsertAfter((int)wort[i], vor);
	}
	vor = Head->Next;
	while(vor != vor->Next){
		printNode(vor);
		vor = vor->Next;
	}
}

/*
Incices starten bei 0 und der 0. Knoten ist der erste Knoten nach dem Head mit Inhalt(nicht Z).
data <0 Bedeutet es handelt sich um einen nicht Inhaltskonoten, also Head oder Z.
*/



//Fügt einen Konoten mit dem Inhalt dt an gewünschtem index ein und gibt einen Pointer auf diesen zurück. Bei fehlschlag gibt es einen NULL pointer zuruück.
struct node *InsertIndex(int dt, int i){
	return NULL;
}
//Fügt einen Konoten mit dem Inhalt dt nach gewünschtem Knoten ein und gibt einen Pointer auf diesen zurück. Bei fehlschlag gibt es einen NULL pointer zuruück.
struct node *InsertAfter(int dt, struct node *T){
	struct node *neu;
	neu = (struct node *) malloc(sizeof(*neu));
	neu->data = dt;
	neu->Next = T->Next;
	T->Next = neu;
	return neu;
}
//Gibt die Menge an Inhaltsknoten zurück.
int getSize(){
	return 0;
}
//Gibt einen Pointer auf den Knoten an dem index zurück. Bei fehlschlag gibt es einen NULL pointer zuruück.
struct node *getByIndex(int i){
	return NULL;
}
//Gibt einen Pointer auf den Knoten mit dem Inhalt zurück. Bei fehlschlag gibt es einen NULL pointer zuruück.
struct node *getByData(int dt){
	return NULL;
}
//Entfernt einen Knoten an dem Index. Bei Fehlschlag gibt es -1 und bei Erfolg 0 zurück.
int removeIndex(int i){
	return 0;
}
//Entfernt einen Knoten mit dem Inhalt. Bei Fehlschlag gibt es -1 und bei Erfolg 0 zurück.
int removeData(int dt){
	return 0;
}
//Gibt den Knoten an dem Pointer in der Konsole aus.
void printNode(struct node *T){
	printf("%c\n",(char)T->data);
}
//Gibt einen Knoten mit dem Index in der Konsole aus.
void printIndex(int i){

}
/*Tauscht die 2 angegebenen Knoten mit einander(Müssen in der liste vorhanden sein) 
Bei Fehlschlag gibt es -1 und bei Erfolg 0 zurück.*/
int switchNodes(struct node *A,struct node *B){
	return 0;
}
void cleanup(){
	struct node *point = Head;
	struct node *prev;
	while(point != point->Next){
		prev = point;
		point = point->Next;
		free(prev);
	}
	free(point);
}
