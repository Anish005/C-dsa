#include<stdio.h>
//binary search iterative
void binary_search(int a[], int n , int key){
    int l=0, u = n-1, mid;
    
    while(l <= u){
        mid = (l+u)/2;
        if(a[mid] == key){
            printf("\n %d found at position %d", key, mid+1);
            return;
        }
        else if(a[mid] < key)
            l = mid + 1;
        else
            u = mid - 1;
        
    }

    printf("\n %d not found in the list", key);

}
int main(){
    int i, n, key, a[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d integers in sorted order: ", n);
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    binary_search(a, n , key);
    return 0;
}