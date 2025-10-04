#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char * ptr;
    int u = 0, l = 0;
    printf("\n Enter a string: ");
    gets(str);
    ptr = str;
    while(*ptr != '\0'){
        if(*ptr >= 'A' && *ptr <= 'Z'){
            u++;
        }
        else if(*ptr >= 'a' && *ptr <= 'z'){
            l++;
        }
        ptr++;
}