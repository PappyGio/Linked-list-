#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseLinkedList(struct ListNode* head) {
    // Implement me!
    struct ListNode* next = NULL;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    
    
    while (curr!= NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* createNode(int x) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

int main() {
    int n, val;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* node = createNode(val);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    struct ListNode* reversed = reverseLinkedList(head);
    printf("The reversed linked list is:\n");
    while (reversed != NULL) {
        printf("%d ", reversed->val);
        reversed = reversed->next;
    }

    return 0;
}
