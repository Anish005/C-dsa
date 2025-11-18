#include<stdio.h>
#define swap(a,b,t) ((t)=(a),(a)=(b),(b)=(t))
void bubble_sort1(int x[], int size){
    int t;
    for(int i =size - 1 ; i > 0 ;i--){
        for(int j = 0; j < i; j ++){
            if(x[j] < x[j + 1]){
                swap(x[j], x[j + 1], t);
            }

        }
    }
}
void bubble_sort2(int x[], int size){
    int t;
    for(int i =0 ; i < size - 1 ;i++){
        for(int j = 0; j < size - i - 1; j ++){
            if(x[j] < x[j + 1]){
                swap(x[j], x[j + 1], t);
            }

        }
    }
}
int main(){
    int i, n, a[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);         
    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    //bubble_sort1(a, n);
    bubble_sort2(a, n);
    printf("Sorted list: ");
    for(i = 0; i < n; i++)
        printf("%d \n ",a[i]);

    return 0;
}
// two diffrent implementations of bubble sort that is in one we 
// start from the end of the array and in the other we start from the beginning