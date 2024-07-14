#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[50]; // Sword, Axe, Crossbow, Staff, Shield
    int gearLevel; // Gear level 1-25
} equipment;

typedef struct {
    char type[50]; // Barbarian, Fighter, Cleric, Wizard
    char role[50]; // Tank, Healer, DPS
} Profession;

typedef struct {
    char name[50];
    Profession profession;
    equipment* gear; // Points to an array up to 3 equipment for the adventurer
    int gearscore;
} adventurer;

typedef struct Node {
    struct Node* next;
    adventurer Adventurer;
} node;

// Getting the input
void getinput(node** list) {
    node* newNode = (node*)malloc(sizeof(node));
    
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->next = NULL;
    newNode->Adventurer.gearscore = 0;

    // USER INPUT
    printf("Enter your Name: ");
    scanf("%s", newNode->Adventurer.name);
    printf("Enter Your Class: ");
    scanf("%s", newNode->Adventurer.profession.type);
    printf("Enter your Role: ");
    scanf("%s", newNode->Adventurer.profession.role);

    newNode->Adventurer.gear = (equipment*)malloc(sizeof(equipment) * 3);
    if (!newNode->Adventurer.gear) {
        fprintf(stderr, "Memory allocation failed\n");
        free(newNode);
        exit(1);
    }

    for (int i = 0; i < 3; i++) {
        printf("Enter your Gear %d Type: ", i + 1);
        scanf("%s", newNode->Adventurer.gear[i].type);
        printf("Enter your Gear %d level: ", i + 1);
        scanf("%d", &newNode->Adventurer.gear[i].gearLevel);
        newNode->Adventurer.gearscore += newNode->Adventurer.gear[i].gearLevel;
    }

    if (*list == NULL) {
        *list = newNode;
    } else {
        node* trav = *list;
        while (trav->next) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

void display(node* list) {
    node* trav = list;
    while (trav) {
        printf("Name: %s\n", trav->Adventurer.name);
        printf("Class: %s\n", trav->Adventurer.profession.type);
        printf("Role: %s\n", trav->Adventurer.profession.role);
        printf("Gears: \n");

        for (int i = 0; i < 3; i++) {
            printf("Gear %d Type: %s\n", i + 1, trav->Adventurer.gear[i].type);
            printf("Gear %d Level: %d\n", i + 1, trav->Adventurer.gear[i].gearLevel);
        }
        printf("Total Gear Score: %d\n\n", trav->Adventurer.gearscore);
        trav = trav->next;
    }
}

int main() {
    node* list = NULL;
    int n = 0;

    printf("How many Adventurers do you want? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n\n==ADVENTURER %d==\n", i + 1);
        getinput(&list);
    }
    printf("\n==LIST OF ADVENTURERS==\n");
    display(list);

    // Free allocated memory
    node* current = list;
    while (current) {
        node* next = current->next;
        free(current->Adventurer.gear);
        free(current);
        current = next;
    }
    return 0;
}
