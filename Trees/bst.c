#include <stdio.h>
#include <stdlib.h>
struct bst
{
    /* data */
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst* createNode(int val){
    struct bst* newNode = (struct bst*)malloc(sizeof(struct bst));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct bst* insert(struct bst* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
struct bst* search(struct bst* root, int val){
    if(root == NULL || root->data == val){
        return root;
    }
    if(val < root->data){
        return search(root->left, val);
    }
    return search(root->right, val);
}
struct bst* findMin(struct bst* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
struct bst* deleteNode(struct bst* root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL){
            struct bst* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct bst* temp = root->left;
            free(root);
            return temp;
        }
        struct bst* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main(){
    struct bst* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    struct bst* searchResult = search(root, 40);
    if(searchResult != NULL){
        printf("Element %d found in the BST\n", searchResult->data);
    }
    else{
        printf("Element not found in the BST\n");
    }

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    searchResult = search(root, 50);
    if(searchResult != NULL){
        printf("Element %d found in the BST\n", searchResult->data);
    }
    else{
        printf("Element not found in the BST\n");
    }
    int mini = findMin(root)->data;
    printf("Minimum element in the BST is: %d\n", mini);

    return 0;
}