#include<stdio.h>
void display();
void show(){
    printf("Hello World");
    display();
}
void display(){
    printf("Welcome to C programming");
}   
int main(){
    show();
    return 0;
}