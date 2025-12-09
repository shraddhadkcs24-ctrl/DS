#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void insertLeft(struct Node** head, int target, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        *head = newNode;

    temp->prev = newNode;
}


void deleteNode(struct Node** head, int target) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", target);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", target);
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;


    insertEnd(&head, 60);
    insertEnd(&head, 70);
    insertEnd(&head, 80);
    displayList(head);


    insertLeft(&head, 70, 15);
    displayList(head);


    deleteNode(&head, 80);
    displayList(head);

    return 0;
}
