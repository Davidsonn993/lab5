#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

// Definición de la estructura Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Declaraciones de funciones
void insertBeginning(int data, struct Node** head);
void insertEnd(int data, struct Node** head);
void printList(struct Node* head);
void insertAtPosition(int data, int position, struct Node** head);
void freelist(struct Node* head);
void deleteNodeByValue(int data, struct Node** head);
struct Node* findNodeByValue(int data, struct Node* head);

#endif // DOUBLE_LIST_H
