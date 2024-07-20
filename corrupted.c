#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


//Function Prototype;
Node* arrayCleaning(Node* head, int* cleanedCount);
void display(Node* head);
void freeList(Node* head);

//Functions that are helping

Node* createNode(int data);
void appendNode(Node** head, int data);


int main(){
    Node* head = NULL;
    Node* cleanedHead = NULL;
    int arrCount = 0;
    int cleanedCount = 0;
    int value, i;

    printf("Input how many items in the array: ");
    scanf("%d", &arrCount);
    printf("Input Array Value: ");
    for(i = 0; i < arrCount; i++){
        scanf("%d", &value);
        appendNode(&head, value);
    }

    cleanedHead = arrayCleaning(head, &cleanedCount);
    if(cleanedCount <= 0){
        printf("\nOh no! Data is fully corrupted and cannot be recovered!\n");
    }else{
        display(cleanedHead);
    }

    freeList(head);
    freeList(cleanedHead);

    return 0;

}


Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp -> next = newNode;
    }
}

Node* arrayCleaning(Node* head, int* cleanedCount){
Node* cleanedHead = NULL;
    Node* temp = head;
    int flag = 0;

    while (temp != NULL) {
        if (temp->data == -1) {
            flag = !flag;
        } else if (flag == 0) {
            appendNode(&cleanedHead, temp->data);
            (*cleanedCount)++;
        }
        temp = temp->next;
    }

    return cleanedHead;
}



void display(Node* head) {
    Node* temp = head;
    printf("Data has been recovered!\n");
    printf("Cleaned Data: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
