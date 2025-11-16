#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack {
    int top;
    int capacity;
    int *array;
};
typedef struct stack stk;

stk *createStack(int size) {
    stk *s = (stk *)malloc(sizeof(stk));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->capacity = size;
    s->top = -1;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

void push(stk *s, int val) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->array[++s->top] = val;
}

int pop(stk *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->array[s->top--];
}

int peek(stk *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->array[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Reverse a string and swap '(' <-> ')'
void reverseAndSwap(char exp[]) {
    int len = strlen(exp);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
    for (i = 0; i < len; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

// Convert infix to postfix (same as before)
void infix_to_postfix(stk *s, char exp[], char output[]) {
    int i, k = 0;
    for (i = 0; i < strlen(exp); i++) {
        char c = exp[i];
        if (isdigit(c)) {
            output[k++] = c;
        } else if (c == '(') {
            push(s, c);
        } else if (c == ')') {
            while (s->top != -1 && peek(s) != '(') {
                output[k++] = pop(s);
            }
            pop(s);
        } else {
            while (s->top != -1 && precedence(peek(s)) >= precedence(c)) {
                output[k++] = pop(s);
            }
            push(s, c);
        }
    }
    while (s->top != -1) {
        output[k++] = pop(s);
    }
    output[k] = '\0';
}

// Reverse a string
void reverseString(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Evaluate prefix expression
int evaluatePrefix(char prefix[]) {
    stk *s = createStack(strlen(prefix));
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) {
            push(s, c - '0');
        } else {
            int val1 = pop(s);
            int val2 = pop(s);
            switch (c) {
                case '+': push(s, val1 + val2); break;
                case '-': push(s, val1 - val2); break;
                case '*': push(s, val1 * val2); break;
                case '/': push(s, val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    push(s, res);
                    break;
                }
            }
        }
    }
    return pop(s);
}

int main() {
    char infix[100], prefix[100], temp[100];
    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);

    strcpy(temp, infix);
    reverseAndSwap(temp); // step 1: reverse and swap

    stk *s = createStack(strlen(temp));
    char postfix[100];
    infix_to_postfix(s, temp, postfix); // step 2: postfix of reversed infix

    strcpy(prefix, postfix);
    reverseString(prefix); // step 3: reverse postfix to get prefix

    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Evaluated result: %d\n", result);

    free(s->array);
    free(s);
    return 0;
}
