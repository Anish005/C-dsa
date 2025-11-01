#include<stdio.h>
#include<stdlib.h>

struct DLL {
    int data;
    struct DLL *prev;
    struct DLL *next;
};
typedef struct DLL dlnode;

dlnode *head = NULL;

// ---------------- FUNCTION DECLARATIONS ----------------
dlnode *create_dlnode(int new_data);
dlnode *insert_beg(dlnode *head);
dlnode *insert_end(dlnode *head);
dlnode *insert_after(dlnode *head);
dlnode *delete_beg(dlnode *head);
dlnode *delete_end(dlnode *head);
dlnode *delete_after(dlnode *head);
dlnode *delete_list(dlnode *head);
dlnode *reverse_list(dlnode *head);
dlnode *sort_list(dlnode *head);
dlnode *search_list(dlnode *head);
void display_forward(dlnode *head);
void display_backward(dlnode *head);
int count_nodes(dlnode *head);

// ---------------- MAIN FUNCTION ----------------
int main() {
    int option;
    do {
        printf("\n\n*********Main Menu*********\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Count the number of nodes in the list\n");
        printf("4. Insert a node at the beginning\n");
        printf("5. Insert a node at the end\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire list\n");
        printf("11. Reverse the list\n");
        printf("12. Sort the list\n");
        printf("13. Search for an element\n");
        printf("14. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int val;
                printf("Enter value for first node: ");
                scanf("%d", &val);
                head = create_dlnode(val);
                printf("\nDoubly Linked List Created Successfully!");
                break;
            }
            case 2:
                printf("\nDisplay Forward: ");
                display_forward(head);
                printf("\nDisplay Backward: ");
                display_backward(head);
                break;
            case 3:
                printf("\nNumber of nodes: %d", count_nodes(head));
                break;
            case 4:
                head = insert_beg(head);
                break;
            case 5:
                head = insert_end(head);
                break;
            case 6:
                head = insert_after(head);
                break;
            case 7:
                head = delete_beg(head);
                break;
            case 8:
                head = delete_end(head);
                break;
            case 9:
                head = delete_after(head);
                break;
            case 10:
                head = delete_list(head);
                printf("\nList deleted successfully!");
                break;
            case 11:
                head = reverse_list(head);
                printf("\nList reversed successfully!");
                break;
            case 12:
                head = sort_list(head);
                printf("\nList sorted successfully!");
                break;
            case 13:
                head = search_list(head);
                break;
        }
    } while (option != 14);     
    return 0;
}

// ---------------- FUNCTION DEFINITIONS ----------------

dlnode *create_dlnode(int new_data) {
    dlnode *newnode = (dlnode *)malloc(sizeof(dlnode));
    newnode->data = new_data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void display_forward(dlnode *head) {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }
    dlnode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void display_backward(dlnode *head) {
    if (head == NULL) {
        printf("List is empty!");
        return;
    }
    dlnode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int count_nodes(dlnode *head) {
    int count = 0;
    dlnode *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

dlnode *insert_beg(dlnode *head) {
    int val;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);
    dlnode *newnode = create_dlnode(val);
    if (head == NULL)
        head = newnode;
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    return head;
}

dlnode *insert_end(dlnode *head) {
    int val;
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    dlnode *newnode = create_dlnode(val);
    if (head == NULL)
        head = newnode;
    else {
        dlnode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}

dlnode *insert_after(dlnode *head) {
    int val, key;
    if (head == NULL) {
        printf("List is empty!");
        return head;
    }
    printf("Enter the value after which to insert: ");
    scanf("%d", &key);
    printf("Enter the value to insert: ");
    scanf("%d", &val);

    dlnode *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node not found!");
        return head;
    }

    dlnode *newnode = create_dlnode(val);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;

    return head;
}

dlnode *delete_beg(dlnode *head) {
    if (head == NULL) {
        printf("List is empty!");
        return NULL;
    }
    dlnode *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

dlnode *delete_end(dlnode *head) {
    if (head == NULL) {
        printf("List is empty!");
        return NULL;
    }
    dlnode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
    return head;
}

dlnode *delete_after(dlnode *head) {
    int key;
    if (head == NULL) {
        printf("List is empty!");
        return NULL;
    }
    printf("Enter the node value after which to delete: ");
    scanf("%d", &key);
    dlnode *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("No node found after given key!");
        return head;
    }
    dlnode *del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
        del->next->prev = temp;
    free(del);
    return head;
}

dlnode *delete_list(dlnode *head) {
    dlnode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

dlnode *reverse_list(dlnode *head) {
    if (head == NULL)
        return NULL;
    dlnode *temp = NULL;
    dlnode *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

dlnode *sort_list(dlnode *head) {
    if (head == NULL)
        return NULL;
    dlnode *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

dlnode *search_list(dlnode *head) {
    if (head == NULL) {
        printf("List is empty!");
        return head;
    }
    int key, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);
    dlnode *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d", key, pos);
            found = 1;
            break;
        }
        pos++;
        temp = temp->next;
    }
    if (!found)
        printf("Element not found!");
    return head;
}
