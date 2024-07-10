#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(Node *head) {
    Node *current = head;
    printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to group closest pairs
void groupClosestPairs(Node *head) {
    if (head == NULL) {
        printf("No elements in the list.\n");
        return;
    }
    
    Node *current = head;
    printf("Closest pairs: \n");
    while (current != NULL && current->next != NULL) {
        printf("(%d, %d)\n", current->data, current->next->data);
        current = current->next->next;
    }
    if (current != NULL && current->next == NULL) {
        printf("(%d, -)\n", current->data);
    }
}

// Function to free the linked list
void freeLinkedList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to sort the linked list by swapping data
void sortLinkedList(Node *head) {
    if (head == NULL) return;
    Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    Node *head = NULL;
    int n, i, num;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        insertAtEnd(&head, num);
    }

    // Print the linked list
    printLinkedList(head);

    // Sort the linked list
    sortLinkedList(head);

    // Print the sorted linked list
    printf("Sorted ");
    printLinkedList(head);

    // Group closest pairs
    groupClosestPairs(head);

    // Free memory used by the linked list
    freeLinkedList(head);

    return 0;
}

