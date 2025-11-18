#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data; struct Node* next;
};


struct Node* head = NULL;


// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself if it's the only node
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}


// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}


// Function to display the circular linked listvoid displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}


int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);
    displayList();  // Output: 20 -> 10 -> 30 -> 40 -> (head)
    return 0;
}