//concatenate two strings using pointers
#include<stdio.h>
int main(){
    char str1[100], str2[100],cpy_str[200];
    char *ptr1,*ptr2, *ptr_cpy;
    ptr1 = str1;
    ptr2 = str2;
    ptr_cpy = cpy_str;
    printf("\n Enter first string: ");
    gets(str1);
    printf("\n Enter second string: ");
    gets(str2);
    while(*ptr1 != '\0'){
        *ptr_cpy = *ptr1;
        ptr_cpy++, ptr1++;
    }
    while(*ptr2 != '\0'){
        *ptr_cpy = *ptr2;
        ptr_cpy++ , ptr2++;

    }
    *ptr_cpy = '\0';
    while (*ptr_cpy != '\0')
    {
        /* code */
        printf("%c",*ptr_cpy);
        ptr_cpy++;
    }
    
    return 0;
 }
