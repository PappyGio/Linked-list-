#include<stdio.h>
#include<stdlib.h>


struct  Node{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else{
        struct Node* curr = *head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void print(struct Node *head){
    struct Node *curr = head;
    while(curr!= NULL){
        printf("%d -> ",curr->data);
        curr = curr->next;
    }
}

int main(){
    struct Node *head = NULL;
    int data, size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        insert(&head, data);
    }
    
    printf("Before:\n");
    print(head);
    head = NULL;
    printf("\nAfter: ");
    print(head);
}
