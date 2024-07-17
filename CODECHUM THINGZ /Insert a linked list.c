#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void insertAtPos(struct Node* linkedList, int newValue, int pos) {
    // Implement me!
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = newValue;
    struct Node* curr = linkedList;
    for(int i = 0; i < pos - 1; i++){
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

void printList(struct Node* head) {
    // Implement me!
    struct Node* curr = head->next;
    while(curr!=NULL){
        printf("%d", curr->value);
        if(curr->next!=NULL){
            printf(" -> ");
        }
        curr = curr->next;
    }
}

// Do not modify
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/*

MAIN.C


#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void freeLinkedList(struct Node* head);

int main(void) {
    // Create the head node
    struct Node* linkedList = createNode(0);

    // Manually connect the linked lists
    struct Node* node1 = createNode(5);
    linkedList->next = node1;

    struct Node* node2 = createNode(3);
    node1->next = node2;

    struct Node* node3 = createNode(22);
    node2->next = node3;

    struct Node* node4 = createNode(100);
    node3->next = node4;

    struct Node* node5 = createNode(-10);
    node4->next = node5;

    struct Node* node6 = createNode(55);
    node5->next = node6;

    struct Node* node7 = createNode(-7);
    node6->next = node7;

    printf("Original linked list:\n");
    printList(linkedList);
    printf("\n");

    int num1, num2, pos;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter position: ");
    scanf("%d", &pos);

    // Insert num1 and num2 in ascending order at the specified position
    struct Node* current = linkedList;
    int i = 0;
    while (i < pos && current != NULL) {
        current = current->next;
        i++;
    }

    if (current != NULL) {
        struct Node* newNode1 = createNode(num1);
        newNode1->next = current->next;
        current->next = newNode1;

        struct Node* newNode2 = createNode(num2);
        newNode2->next = newNode1->next;
        newNode1->next = newNode2;
    }

    // Display all the values of the linked list
    printList(linkedList);

    // Delete the linked list from memory
    freeLinkedList(linkedList);

    return 0;
}

void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
*/

/*
  NODE.H
#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    struct Node* next;
};

struct Node* createNode(int value);
void insertAtPos(struct Node* linkedList, int newValue, int pos);
void printList(struct Node* head);

#endif
  
*/
