#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

// Structure to represent a queue
struct Queue {
    int arr[MAX_SIZE]; // Array to store queue elements
    int front;         // Index of the front element
    int rear;          // Index of the rear element
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow: Cannot add more elements.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 when the first element is added
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Queue is empty.\n");
        return -1; // Return a sentinel value indicating underflow
    }
    int dequeued_value = q->arr[q->front];
    q->front++;
    // If front surpasses rear, the queue becomes empty
    if (q->front > q->rear) {
        initializeQueue(q); // Reset front and rear
    }
    printf("%d dequeued from queue.\n", dequeued_value);
    return dequeued_value;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    displayQueue(&myQueue);

    dequeue(&myQueue);
    displayQueue(&myQueue);

    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60); // This will cause an overflow
    displayQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue);
    dequeue(&myQueue); // This will cause an underflow
    displayQueue(&myQueue);

    return 0;
}