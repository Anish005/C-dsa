#include <stdio.h>
#include <stdlib.h> // For malloc and free

#define MAX_SIZE 10 // Define the maximum capacity of the stack

// Define the Stack structure
typedef struct {
    int top;         // Index of the top element
    int capacity;    // Maximum capacity of the stack
    int *array;      // Pointer to the array storing stack elements
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        return NULL; // Handle memory allocation failure
    }
    stack->capacity = capacity;
    stack->top = -1; // Initialize top to -1 indicating an empty stack
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        free(stack); // Free stack if array allocation fails
        return NULL;
    }
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Or some other error indicator
    }
    return stack->array[stack->top--];
}

// Function to peek at the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, no element to peek\n");
        return -1; // Or some other error indicator
    }
    return stack->array[stack->top];
}

// Function to free the memory allocated for the stack
void destroyStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}

// Main function to demonstrate stack operations
int main() {
    Stack* myStack = createStack(MAX_SIZE);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("Top element is %d\n", peek(myStack));
    printf("%d popped from stack\n", pop(myStack));
    printf("Top element is now %d\n", peek(myStack));

    destroyStack(myStack); // Clean up memory

    return 0;
}