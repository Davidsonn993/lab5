#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"


int main(){
struct Node* head = NULL;

printf("Agregamos 3 números al inicio, empezando en 3 y terminando en 1\n");
insertBeginning(3, &head);
insertBeginning(2, &head);
insertBeginning(1, &head);
printList(head);

printf("insertamos 3 numeros al final empezando en 6 terminando en 8 \n");
insertEnd(6, &head);
insertEnd(7, &head);
insertEnd(8, &head);
printList(head);

printf("Insertamos un 5 en medio en la posicion 3\n");
insertAtPosition(5, 3, &head);
printList(head);

printf("borramos un nodo segun su contenido en data\n");
deleteNodeByValue(3, &head);
printList(head);

struct Node* foundNode = findNodeByValue(5, head);
    if (foundNode != NULL) {
        printf("Nodo con valor 5 encontrado: %p\n", foundNode);
    } else {
        printf("Nodo no encontrado\n");
 }

printf("recorreremos la lista desde el principio hacia atras\n");
printListForward(head);
printf("recorreremos la lista de atras hacia el primero\n");
printListBackward(head);

return 0;

freelist(head);
}
