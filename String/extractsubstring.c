#include<stdio.h>

int main(){
    char str[100], substr[100];
    int i = 0, j = 0, start,end;
    printf("\n Enter a string: ");
    gets(str);
    printf("\n Enter starting position: ");
    scanf("%d",&start);
    printf("\n Enter ending position: ");
    scanf("%d",&end);
    i = start;
    while(str[i] != '\0' && end > 0){
        substr[j] = str[i];
        i++;
        j++;
        end--;
    }
    substr[j] = '\0';
    printf("\n Extracted substring is: %s");


    return 0;
}