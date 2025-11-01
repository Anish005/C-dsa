#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    /* data */
    int top;
    int capacity;
    int *array;
};

typedef struct stack stk;

stk *createStack(int size){
    stk *s  = (stk *)malloc(sizeof(stk));
    if(s == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->capacity = size;
    s->top = -1;
    s->array = (int *)malloc(s->capacity*sizeof(int));
    return s;
}
void push(stk *s , int val){
    if(s->top == s->capacity-1){
        printf("Stack Overflow\n");
        return;
    }
    s->array[++s->top] = val;
}
int pop(stk *s){
    if(s->top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->array[s->top--];
    
}
int peek(stk *s){
    if(s->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return s->array[s->top];
}
int postfixEval(stk *s, char exp[]){
    int i, firstoperand, secondoperand, result;
    for(i=0 ; i< strlen(exp);i++){
        if(exp[i]>='0' && exp[i]<='9'){
            push(s, exp[i]-'0');
        }
        else{
            secondoperand = pop(s);
            firstoperand = pop(s);
            switch (exp[i])
            {
            case '+':
                result = firstoperand + secondoperand;
                break;
            case '-':
                result = firstoperand - secondoperand;
                break;
            case '*':
                result = firstoperand * secondoperand;
                break;
            case '/':
                result = firstoperand / secondoperand;
                break;
            default:
                printf("Invalid operator %c\n", exp[i]);
                exit(1);
            }
            push(s, result);

        }
    }
    result = pop(s);
    return result;
}
int main(){
    char exp[10];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    stk *s = createStack(10);
    int result = postfixEval(s, exp);
    printf("Result of postfix expression %s is: %d\n", exp, result);
    return 0;
}