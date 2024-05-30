#include <stdio.h>
#include <stdlib.h>

//Definimos la estructura del Nodo
struct Node {
	int data;
	struct Node* next;
	struct Node*  prev;
};


//Funcion para insertar nodo al inicio:
void insertBeginning(int data, struct Node** cabeza){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//reservamos espacio en memoria
	if (newNode == NULL){ //por si falla la reservacion 
	printf("No se reservó en memória\n");
	return;
	}
	
	newNode->data = data;            //asigna el valor de data al nuevo nodo 
        newNode->next = *cabeza;    //el next del nuevo nodo tiene que apuntar al nodo que era la cabeza
	//nextNode->next = NULL;
	newNode->prev = NULL;        //hacer que el next del nuevo nodo apunte a null. no hay nodo anterior a el
	
	if(*cabeza != NULL){       //
	(*cabeza)->prev = newNode;

	}
	
	*cabeza = newNode;   //avanza, se actualiza cabeza  para que apunte al nuevo nodo
}





// Función para insertar un nodo al final
void insertEnd(int data, struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //practicamente lo mismo que antes 
    if (newNode == NULL){
        printf("No se reservó en memória\n");
        return;
    }
    newNode->data = data; // el nuevo nodo contendrá el valor pasado como argumento de la función
    newNode->next = NULL; //sera el ultimo por lo tanto el next debe apuntar a null
    if (*head == NULL) {           //esta condición verifica si la lista esta vacía
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;      //se crea un puntero temporal que se inicializa con la cabeza
    while (temp->next != NULL) {   //se recorre la lista para buscar el ultimo nodo con el while
        temp = temp->next;        
    }
    temp->next = newNode;    // se ligan los nodos
    newNode->prev = temp;
}

// Función para imprimir la lista
void printList(struct Node* head) {  // resive puntero del nodo y la cabeza para imprimir la info
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//funcion para agregar un valor en una posicion especifica
void insertAtPosition(int data, int position, struct Node** head) {
    if (position < 0) {
        printf("Posición inválida\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {     //comprobar que se reservo memoria
        printf("No se reservó en memória\n");
        return;
    }
    newNode->data = data;     //comprobamos si la posicion ingresada es el principio de la lista     
    if (position == 0) {
        newNode->next = *head;  //el next del nuevo nodo debe apuntar a la cabezera
        newNode->prev = NULL;   //como la posicion es 0 no hay nada antes de el
        if (*head != NULL) {       //actualizamos el prv del anterior primer nodo para que apunte a este nuevo
            (*head)->prev = newNode;
        }
        *head = newNode; //actualizamos el head para que apunte a este nuevo nodo
        return;
    }
    struct Node* temp = *head;  //se inicializa un puntero temporal para buscar la posicion para ingresar el nodo
    for (int i = 0; i < position - 1 && temp != NULL; i++){ //for para mover el puntero temp  através de la lista
        temp = temp->next;       //hasta la posicion anterior a la deseada.
    }
    if (temp == NULL) {               //  para asegurarnos que la posicion esta dentro de los limites
        printf("Posición fuera de los límites\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next; // hacemos las ligaduras de los nuevos nodos
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}


//funcion para liberar el espacio en memoria
void freelist(struct Node* head){
	struct Node* actual = head;
	struct Node* next;
	while (actual != NULL){
		next= actual->next;
		free(actual);
		actual=next;
	}
}


int main(){
struct Node* head = NULL;

insertBeginning(5, &head);
insertBeginning(4, &head);
insertBeginning(3, &head);
insertBeginning(2, &head);
insertEnd(9, &head);
insertEnd(10, &head);
insertEnd(11, &head);
insertAtPosition(7, 4, &head);


printList(head);
freelist(head);

return 0;
}



