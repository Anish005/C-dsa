#include <stdio.h>
struct student
{
int r_no;
char name[20];
char course[20];
int fees;
};

int main(){
    struct student s1, *ptr_s1;
    ptr_s1 = &s1;
    printf("Enter the details of the student\n");
    printf("Enter the roll number\n");
    scanf("%d", &ptr_s1->r_no);
    printf("Enter the name\n");
    gets(ptr_s1->name);
    printf("Enter the course\n");
    gets(ptr_s1->course);
    printf("Enter the fees\n");
    scanf("%d", &ptr_s1->fees);
    printf("The details of the student are\n");
    printf("the roll number is %d\n", ptr_s1->r_no);
    printf("the name is %s\n", ptr_s1->name);
    printf("the course is %s\n",ptr_s1->course);
    printf("the fees is %d\n", ptr_s1->fees);
    return 0;
}