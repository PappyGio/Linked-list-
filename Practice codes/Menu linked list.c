#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int data;
} Node;

// Function prototypes
void printList(Node *head);
void sortList(Node **head);
void removeOdd(Node **head);
void removeEven(Node **head);
void menu();
void insertElements(Node **head, int n);
void insertAtEnd(Node **head, int value);

int main() {
    Node *head = NULL;
    int n;

    printf("How many elements do you want to insert? ");
    scanf("%d", &n);
    insertElements(&head, n);

    int choice;

    // Menu-driven program
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("How many elements do you want to insert? ");
                scanf("%d", &n);
                insertElements(&head, n);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                sortList(&head);
                break;
            case 4:
                removeOdd(&head);
                break;
            case 5:
                removeEven(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("THIS COMPUTER IS NOW HACKED0.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n---WALCOME TO GIO LINKED LIST------\n");
    printf("\n--- CHOOSE YOUR FIGHTER---\n");
    printf("1. Insert elements\n");
    printf("2. Print list\n");
    printf("3. Sort list In Ascending\n");
    printf("4. Remove odd elements\n");
    printf("5. Remove even elements\n");
    printf("6. HAWA LANG \n");
}

void insertElements(Node **head, int n) {
    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(head, value);
    }
}

void insertAtEnd(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void sortList(Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void removeOdd(Node **head) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data % 2 != 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void removeEven(Node **head) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
