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
    stk *s = (stk *)malloc(sizeof(stk));
    if(s == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->capacity = size;
    s->top = -1;
    s->array =(int *)malloc(s->capacity * sizeof(int));
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
int precedence(char op){
    switch (op)
    {
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
//first convert infix to postfix then evaluate postfix
int infix_to_postfix(stk *s, char exp[], char output[]){
    int i,k = 0 ;
    for(i= 0 ; i < strlen(exp); i++){
        char  c = exp[i];
        if(c >= '0' && c <= '9'){
            output[k++] = c;
        }
        else if(c == '('){
            push(s,c);
        }
        else if(c == ')'){
            while(s->top != -1 && peek(s) != '('){
                output[k++] = pop(s);
            }
            pop(s); //pop the '('
        }
        else{
            while(s->top != -1 && precedence(peek(s)) >= precedence(c)){
                output[k++] = pop(s);
            }
            push(s,c);
        }
    }
    //pop all the remaining element from stack
    while (s->top != -1) {
        output[k++] = pop(s);
    }
    output[k] = '\0';
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
    char exp[20];
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    stk *s = createStack(20);
    char postfix[40];
    infix_to_postfix(s, exp, postfix);
    printf("Postfix Expression: %s\n", postfix);
    stk *s2 = createStack(40);
    int result = postfixEval(s2, postfix);
    printf("Result: %d\n", result);
    return 0;
}
