// Stack implementation using linked list in C
/*
the insertion and deletion operations are performed 
at the beginning of the linked list to ensure O(1) time complexity for both push and pop operations.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int val;
    struct node* next;
};

// Define the head pointer (top of the stack)
struct node* head = NULL;

// Function to push an element onto the stack
void push() {
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Unable to push the element. Memory allocation failed.\n");
        return;
    }

    printf("Enter the value to push: ");
    scanf("%d", &val);

    ptr->val = val;
    ptr->next = head;  // Point the new node to the current top node
    head = ptr;        // Update the head to the new node

    printf("Item %d pushed to stack\n", val);
}

// Function to pop an element from the stack
void pop() {
    if (head == NULL) {
        printf("Underflow: Stack is empty\n");
        return;
    }

    struct node* ptr = head;
    int item = head->val;

    head = head->next;  // Move the head pointer to the next node
    free(ptr);          // Free the memory of the popped node

    printf("Item %d popped from stack\n", item);
}

// Function to peek at the top element of the stack
void peek() {
    if (head == NULL) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element is: %d\n", head->val);
    }
}

// Function to display the stack elements
void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if the stack is empty
int isEmpty() {
    return (head == NULL);
}

// Function to return the size of the stack
int size() {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function to test the stack operations
int main() {
    int choice;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Get Stack Size\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                printf("Stack size: %d\n", size());
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}