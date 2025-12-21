#include <stdio.h>
#include <stdlib.h>

/* =========================
   NODE DEFINITION
   ========================= */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* =========================
   CREATE A NEW NODE
   Time Complexity: O(1)
   ========================= */

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* =========================
   INSERT AT BEGINNING
   Time Complexity: O(1)
   ========================= */

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

/* =========================
   INSERT AT END
   Time Complexity: O(n)
   ========================= */

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* =========================
   INSERT IN MIDDLE (AFTER POSITION)
   Time Complexity: O(n)
   ========================= */

Node* insertAtPosition(Node* head, int value, int position) {
    if (position == 0)
        return insertAtBeginning(head, value);

    Node* temp = head;
    int i;
    for (i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

/* =========================
   DELETE FROM BEGINNING
   Time Complexity: O(1)
   ========================= */

Node* deleteFromBeginning(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

/* =========================
   DELETE FROM POSITION
   Time Complexity: O(n)
   ========================= */

Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL)
        return NULL;

    if (position == 0)
        return deleteFromBeginning(head);

    Node* temp = head;
    int i;
    for (i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
        return head;

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);

    return head;
}

/* =========================
   TRAVERSAL (PRINT LIST)
   Time Complexity: O(n)
   ========================= */

void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}



int main() {

    Node* head = NULL;

    
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    
    head = insertAtBeginning(head, 5);
    head = insertAtPosition(head, 25, 3);
    head = insertAtEnd(head, 40);

    printf("Linked List after insertions:\n");
    traverseList(head);

    
    head = deleteFromBeginning(head);
    head = deleteFromPosition(head, 2);

    printf("\nLinked List after deletions:\n");
    traverseList(head);

    return 0;
}

