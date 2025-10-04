#include<stdio.h>
void binary_search_recursive(int a[], int l, int u, int key){
    int mid;
    if(l > u){
        printf("\n %d not found in the list", key);
        return;
    }
    mid = (l + u)/2;
    if(a[mid] == key){
        printf("\n %d found at position %d", key, mid+1);
        return;
    }
    else if(a[mid] < key)
        binary_search_recursive(a, mid + 1, u, key);
    else
        binary_search_recursive(a, l, mid - 1, key);
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
    binary_search_recursive(a, 0, n - 1, key);
    return 0;
}