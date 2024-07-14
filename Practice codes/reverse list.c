#include<stdio.h>
#include<stdlib.h>

    //Definitionb for singly-linked list
struct ListNode{
    int val;
    struct ListNode *next;
};

//Function to create a new node 

struct ListNode* createNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

//Function to print the list 
void printList(struct ListNode* head){
    struct ListNode* temp = head;
    while (temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

//Function to reverse the linked ListNode
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(head == NULL || left == right) return head;
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    
    //Move prev to the node just before left
    for(int i = 1; i < left; i++){
        prev = prev->next;
    }
    
    struct ListNode* curr = prev->next;
    struct ListNode* next = NULL;
    
    //Reverse the list betweem left and right
    for(int i = 0; i < right - left; i++){
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy.next;
}

//Function to create the list from user input
struct ListNode* createList(int size){
    if(size <= 0 )return NULL;
    
    int val;
    printf("Enter element 1: ");
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* temp = head;
    
    for(int i = 2; i <=size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        temp->next = createNode(val);
        temp = temp->next;
    }
    return head;
}

int main(){
    int size, left, right;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    
    struct ListNode* head = createList(size);
    
    printf("Enter left and right indices (1-indexed): ");
    scanf("%d %d", &left, &right);
    
    head = reverseBetween(head, left, right);
    
    printf("Linked list after reversing between %d and %d: ", left, right);
    printList(head);
    
    return 0;
}
