#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// Function to print all the nodes in the linked list
void printNodes(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Function to print all the nodes in the linked list in reverse order
void printNodesReverse(struct node *head) {
    struct node *current = head;
    int count = 0;
    
    // Calculate the number of nodes
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    // Create an array to store the node values
    int *values = malloc(count * sizeof(int));
    
    // Populate the array with node values
    current = head;
    for (int i = 0; i < count; i++) {
        values[i] = current->value;
        current = current->next;
    }
    
    // Print the node values in reverse order
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", values[i]);
        if (i != 0) {
            printf(" <- ");
        }
    }
    printf("\n");
    
    // Free the allocated memory
    free(values);
}

int main() {
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    struct node *four = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));

    printf("Enter number 1: ");
    scanf("%d", &one->value);
    printf("Enter number 2: ");
    scanf("%d", &two->value);
    printf("Enter number 3: ");
    scanf("%d", &three->value);
    printf("Enter number 4: ");
    scanf("%d", &four->value);
    printf("Enter number 5: ");
    scanf("%d", &five->value);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    // Print the values in the original order
    printNodes(one);

    // Print the values in the reverse order
    printNodesReverse(one);

    // Free the allocated memory
    free(one);
    free(two);
    free(three);
    free(four);
    free(five);

    return 0;
}
