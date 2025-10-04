#include<stdio.h>
typedef struct Employee{
    char name[50];
    char EmpID[10];
    int age;
    float salary;
    char Dept[15];
}e;

int main(){

    e emp[10];
    
    for(int i = 0; i < 10 ; i++){
        printf("Enter the details of employee %d\n",i);
        gets(emp[i].name);
        printf("Enter the Employee ID of employee %d\n",i);
        gets(emp[i].EmpID);
        printf("Enter the age of employee %d\n",i);
        scanf("%d",&emp[i].age);
        printf("Enter the salary of employee %d\n",i);
        scanf("%f",&emp[i].salary);
        printf("Enter the department of employee %d\n",i);
        gets(emp[i].Dept);
    }
    //printing the details 
    for(int i = 0; i < 10 ; i++){
        printf("The details of employee %d\n",i);
        printf("Name: %s\n",emp[i].name);
        printf("Employee ID: %s\n",emp[i].EmpID);
        printf("Age: %d\n",emp[i].age);
        printf("Salary: %.2f\n",emp[i].salary);
        printf("Department: %s\n",emp[i].Dept);
    }

    return 0;
}