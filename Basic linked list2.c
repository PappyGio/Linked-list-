#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}node, *nodePtr;

void insertAtEnd(nodePtr *head, int val) {
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Traverse to the end of the list
        nodePtr current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Insert the new node at the end
        current->next = newNode;
    }
}
  int main() {
    nodePtr List = NULL;  // Initialize an empty list

    // Existing nodes (from your main function)
    List = (nodePtr)malloc(sizeof(node));
    List->next = NULL;
    List->value = 1;

    nodePtr current = (nodePtr)malloc(sizeof(node));
    current->next = NULL;
    current->value = 2;
    List->next = current;

    current = (nodePtr)malloc(sizeof(node));
    current->next = NULL;
    current->value = 3;
    List->next->next = current;

    // Inserting new nodes at the end
    insertAtEnd(&List, 4);

    // Printing the list
    nodePtr ptr = List;
    int i = 0;
    while (ptr != NULL) {
        printf("Node %d: %d\n", i + 1, ptr->value);
        ptr = ptr->next;
        i++;
    }

    return 0;
}
