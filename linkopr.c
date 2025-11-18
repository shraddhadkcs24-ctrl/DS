
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


void concatenateLists(Node** head1, Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;
}


void bubbleSort(Node* head) {
    if (head == NULL) return;

    Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;


    insertEnd(&list1, 3);
    insertEnd(&list1, 1);
    insertEnd(&list1, 4);
    insertEnd(&list1, 2);


    insertEnd(&list2, 5);
    insertEnd(&list2, 6);


    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);


    reverseList(&list1);
    printf("Reversed List 1: ");
    printList(list1);


    concatenateLists(&list1, &list2);
    printf("Concatenated List 1 and List 2: ");
    printList(list1);


    bubbleSort(list1);
    printf("Sorted List: ");
    printList(list1);

    return 0;
}
