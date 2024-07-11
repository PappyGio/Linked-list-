#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

// Function Prototypes
void print(node* head);
void insert(node** head, adventurer adv);
void populate(node** head);

// Function to print all adventurers in the linked list
void print(node* head) {
    node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Adventurer %d\n", count);
        printf("Name: %s\n", current->Adventurer.name);
        printf("Profession: %s, Role: %s\n", current->Adventurer.profession.type, current->Adventurer.profession.role);
        printf("Gear Score: %d\n", current->Adventurer.gearscore);
        printf("Gear:\n");
        for (int i = 0; i < 3; ++i) {
            if (strlen(current->Adventurer.gear[i].type) > 0) {
                printf("  Type: %s, Level: %d\n", current->Adventurer.gear[i].type, current->Adventurer.gear[i].gearLevel);
            }
        }
        printf("\n");
        current = current->next;
        count++;
    }
}

// Function to insert a new adventurer node at the beginning of the list
void insert(node** head, adventurer adv) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    new_node->Adventurer = adv;
    new_node->next = *head;
    *head = new_node;
}

// Function to populate the linked list with sample data
void populate(node** head) {
    // Example adventurers
    adventurer adv1 = {"Conan", {"Barbarian", "DPS"}, NULL, 1500};
    equipment gear1[3] = {{"Sword", 20}, {"Shield", 15}, {"", 0}};
    adv1.gear = gear1;
    insert(head, adv1);

    adventurer adv2 = {"Gandalf", {"Wizard", "Healer"}, NULL, 1800};
    equipment gear2[3] = {{"Staff", 22}, {"", 0}, {"", 0}};
    adv2.gear = gear2;
    insert(head, adv2);

    adventurer adv3 = {"Aragorn", {"Fighter", "Tank"}, NULL, 1600};
    equipment gear3[3] = {{"Sword", 18}, {"Shield", 20}, {"", 0}};
    adv3.gear = gear3;
    insert(head, adv3);

    adventurer adv4 = {"Priest", {"Cleric", "Healer"}, NULL, 1400};
    equipment gear4[3] = {{"Staff", 15}, {"", 0}, {"", 0}};
    adv4.gear = gear4;
    insert(head, adv4);
}

// Example usage of the functions
int main() {
    node* head = NULL;

    populate(&head);

    printf("Printing all adventurers:\n");
    print(head);

    // Clean up memory (free allocated nodes)
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
