/*
Write a program to find the node at which the intersection of two singly linked lists begins

  */


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* getIntersectionNode(Node* headA, Node* headB){
    if(headA == NULL || headB == NULL)return NULL;
    
    Node* a = headA;
    Node* b = headB;
    
    while (a != b){
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to append a node at the end of the linked luist

void append(Node** head_ref, int new_data){
    Node* new_node = createNode(new_data);
    Node* last = *head_ref;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}


int main(){
    Node* headA = NULL;
    Node* headB = NULL;
    int sizeA, sizeB, i, data, intersectIndex;
    
    printf("Enter the size of first linked list: ");
    scanf("%d", &sizeA);
    printf("Enter the elements of first linked list: ");
    for(i = 0; i < sizeA; i++){
        scanf("%d", &data);
        append(&headA, data);
    }
    
    printf("Enter the size of second linked list: ");
    scanf("%d", &sizeB);
    printf("Enter the elements of second linked list: ");
    for(i = 0; i < sizeB; i++){
        scanf("%d", &data);
        append(&headB, data);
    }
    
    printf("Enter the index of the node at which the intersection of two linked lists begins (-1 if no intersection): ");
    scanf("%d", &intersectIndex);
    
    if(intersectIndex != -1) {
        Node* tempA = headA;
        for(i = 0; i < intersectIndex; i++){
            tempA = tempA->next;
        }
        Node* tempB = headB;
        while(tempB->next != NULL){
            tempB = tempB->next;
        }
        tempB->next = tempA;
    }
    Node* intersection = getIntersectionNode(headA, headB);
    if(intersection != NULL){
        printf("Intersection point is: %d\n", intersection->data);
    }else{
        printf("No intersection point.\n");
    }
    
    return 0;
}
