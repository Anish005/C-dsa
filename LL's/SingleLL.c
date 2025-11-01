#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node  * next;
};
typedef struct node Node;

Node *head = NULL;

// Function declarations
Node *create_node(int new_data);
Node *display(Node *);
Node *insert_beg(Node *);
Node *insert_end(Node *);
Node *insert_after(Node *);
Node *delete_beg(Node *);
Node *delete_end(Node *);
Node *delete_after(Node *);
Node *delete_list(Node *);
Node *reverse_list(Node *);
Node *sort_list(Node *);
Node *search_list(Node *);
Node *find_middle(Node *);
void revdisplay(Node *);
int count_nodes(Node *);

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
                head = create_node(val);
                printf("\nLinked List Created Successfully!");
                break;
            }
            case 2:
                head = display(head);
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
            case 14:
                head = find_middle(head);
                printf("\nMiddle node value: %d", head != NULL ? head->value : -1);
                break;
            case 15:
                revdisplay(head);
                break;
        }
    } while (option !=16 );

    return 0;
}

// --------------------------------------------------
// Creates a new node with a given integer value
Node *create_node(int new_data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->value = new_data;
    new_node->next = NULL;
    return new_node;
}

// --------------------------------------------------
// Displays all nodes in the linked list
Node *display(Node *head) {
    Node *current = head;
    if (current == NULL) {
        printf("\nList is empty!");
        return head;
    }
    printf("\nLinked List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL");
    return head;
}

// --------------------------------------------------
// Counts and returns the total number of nodes
int count_nodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// --------------------------------------------------
// Inserts a new node at the beginning of the list
Node *insert_beg(Node *head) {
    int val;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);
    Node *new_node = create_node(val);
    new_node->next = head;
    head = new_node;
    return head;
}

// --------------------------------------------------
// Inserts a new node at the end of the list
Node *insert_end(Node *head) {
    int val;
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    Node *new_node = create_node(val);

    if (head == NULL) {
        return new_node;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    return head;
}

// --------------------------------------------------
// Inserts a node after a given value in the list
Node *insert_after(Node *head) {
    if (head == NULL) {
        printf("\nList is empty!");
        return head;
    }
    int key, val;
    printf("Enter value after which to insert: ");
    scanf("%d", &key);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    Node *temp = head;
    while (temp != NULL && temp->value != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nNode with value %d not found!", key);
        return head;
    }
//[] []
    Node *new_node = create_node(val);
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// --------------------------------------------------
// Deletes the first node from the list
Node *delete_beg(Node *head) {
    if (head == NULL) {
        printf("\nList is empty!");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    printf("\nFirst node deleted.");
    return head;
}

// --------------------------------------------------
// Deletes the last node from the list
Node *delete_end(Node *head) {
    if (head == NULL) {
        printf("\nList is empty!");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nLast node deleted.");
        return head;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("\nLast node deleted.");
    return head;
}

// --------------------------------------------------
// Deletes the node after a specific value
Node *delete_after(Node *head) {
    if (head == NULL) {
        printf("\nList is empty!");
        return head;
    }
    int key;
    printf("Enter value after which to delete: ");
    scanf("%d", &key);

    Node *temp = head;
    while (temp != NULL && temp->value != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("\nNo node found to delete after %d!", key);
        return head;
    }

    Node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("\nNode deleted after %d.", key);
    return head;
}

// --------------------------------------------------
// Deletes the entire linked list
Node *delete_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

// --------------------------------------------------
// Reverses the linked list
Node *reverse_list(Node *head) {
    Node *prev = NULL, *current = head, *temp = NULL;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
    return head;
}

// --------------------------------------------------
// Sorts the linked list in ascending order
Node *sort_list(Node *head) {
    if (head == NULL)
        return head;

    Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->value > j->value) {
                temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
    return head;
}

// --------------------------------------------------
// Searches for an element in the linked list
Node *search_list(Node *head) {
    if (head == NULL) {
        printf("\nList is empty!");
        return head;
    }
    int key, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);

    Node *temp = head;
    while (temp != NULL) {
        if (temp->value == key) {
            printf("\nValue %d found at position %d", key, pos);
            return head;
        }
        pos++;
        temp = temp->next;
    }
    printf("\nValue %d not found in the list.", key);
    return head;
}
// --------------------------------------------------
//  display reverse of the linked list
void revdisplay(Node *head) {
    if (head == NULL) {
        return;
    }
    revdisplay(head->next);
    printf("%d -> ", head->value);
}
// --------------------------------------------------
// find the middle node of the linked list
Node *find_middle(Node *head) {
    Node *slow , *fast;
    slow = fast = head;
    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
}
