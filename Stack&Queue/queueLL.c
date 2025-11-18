#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;               // The data stored in each node
    struct Node* next;      // Pointer to the next node
};

// Initialize front and rear pointers for the queue
struct Node* front = NULL;  // Pointer to the front of the queue
struct Node* rear = NULL;   // Pointer to the rear of the queue

// Function prototypes
void enqueue(int value);
void dequeue();
void displayQueue();
int isEmpty();
int peek();

int main() {
    // Enqueue elements into the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Current Queue: ");
    displayQueue();  // Display current state of the queue
    
    printf("Peek: %d\n", peek());  // Peek at the front element
    
    dequeue();       // Remove an element from the queue
    
    printf("After Dequeue: ");
    displayQueue();  // Display state of the queue after dequeue
    
    printf("Is Queue Empty? %s\n", isEmpty() ? "Yes" : "No");  // Check if queue is empty
    
    return 0;
}

// Function to add an element to the end of the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = value;  // Set the data for the new node
    newNode->next = NULL;   // New node will be at the end, so next is NULL

    if (rear == NULL) { // Check if the queue is empty
        front = rear = newNode; // If empty, both front and rear point to new node
        return;
    }

    rear->next = newNode; // Link new node at end of queue
    rear = newNode;       // Update rear pointer to point to new node
}

// Function to remove an element from the front of the queue
void dequeue() {
    if (front == NULL) { // Check if the queue is empty
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front; // Store pointer to front node
    front = front->next;       // Move front pointer to next node

    if (front == NULL) {       // If queue becomes empty after dequeue
        rear = NULL;           // Update rear pointer to NULL as well
    }

    free(temp);                // Free memory of dequeued node
}


void displayQueue() {
    struct Node* temp = front; // Start from the front of the queue

    if (temp == NULL) {        // Check if queue is empty
        printf("Queue is empty.\n");
        return;
    }

    while (temp != NULL) {     // Traverse through all nodes in the queue
        printf("%d -> ", temp->data); // Print current node's data
        temp = temp->next;     // Move to next node
    }
    
    printf("NULL\n");          // Indicate end of queue
}

int isEmpty() {
    return front == NULL;      // Returns 1 (true) if front is NULL, indicating an empty queue
}

// Function to peek at the front element without removing it
int peek() {
    if (isEmpty()) {           // Check if the queue is empty first
        printf("Queue is empty. Cannot peek.\n");
        return -1;            // Return -1 or any sentinel value indicating failure
    }
    
    return front->data;       // Return data of front node without dequeuing it
}