#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}node, *nodePtr;

int main(){
    nodePtr List;
    List = (struct Node*)malloc(sizeof(node));
    List->next = NULL;
    List->value = 1;
    
    nodePtr current = (struct Node*)malloc(sizeof(node));
    current->next = NULL;
    current->value=2;
    List->next = current;
    
    current = (struct Node*)malloc(sizeof(node));
    current ->next = NULL;
    current->value = 3;
    List->next->next = current;
    
    
    // printf("Node 1:%d\n", List->value);
    // printf("Node 2:%d\n", List->next->value);
    // printf("Node 3:%d\n", List->next->next->value);
    
    nodePtr ptr = List;
    int i = 0;
    while(ptr != NULL){
        printf("Node %d: %d\n", i + 1, ptr->value);
        ptr = ptr->next;
        i++;
    }
    return 0;
}
