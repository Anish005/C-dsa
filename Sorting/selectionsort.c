#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define swap(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
void sort(int [], int); 
int main(){
    int i, n, list[MAX_SIZE];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n < 1 || n > MAX_SIZE){
        printf("Error: number of elements must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 1000; // Random numbers between 0 and 99
        printf("%d ", list[i]);
    }
    sort(list, n);
    printf("\nSorted list:\n");
    for(i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
void sort(int arr[], int n){
    int i, j , min, tmp;
    for(i= 0; i< n-1;i++){
        min = i;
        for(j = i+1 ; j<n ;j++){
            if(arr[j] < arr[min])
                min = j;   
        }
    swap(arr[i], arr[min], tmp);
    }
}