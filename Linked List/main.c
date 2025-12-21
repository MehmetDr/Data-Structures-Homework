#include <stdio.h>
#include <stdlib.h>

/* =========================
   NODE DEFINITION
   ========================= */

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

/* =========================
   ADD NODE TO END (DOUBLY)
   ========================= */

Node* addToEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* =========================
   INSERT NODE IN BETWEEN
   (AFTER GIVEN NODE)
   ========================= */

void insertAfter(Node* prevNode, int value) {
    if (prevNode == NULL)
        return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

/* =========================
   PRINT DOUBLY LINKED LIST
   ========================= */

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* =========================
   DELETE ALL NODES
   (RECURSIVE)
   ========================= */

void deleteAllRecursive(Node* head) {
    if (head == NULL)
        return;

    deleteAllRecursive(head->next);
    free(head);
}



int main() {

    Node* head = NULL;

    
    head = addToEnd(head, 10);
    head = addToEnd(head, 20);
    head = addToEnd(head, 30);

    
    insertAfter(head->next, 25);

    printf("Doubly Linked List:\n");
    printList(head);

   
    deleteAllRecursive(head);
    head = NULL;

    return 0;
}

