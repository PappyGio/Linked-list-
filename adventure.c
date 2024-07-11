#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char type[50]; //Sword,Axe,CrossBow,staff,spear,shield
	int gearLevel; // 1-25
}equipment;

typedef struct{
	char type[50]; //Barbarian,Fighter,Cleric,Wizard
	char role[50];//Tank, Healer, Dps
}Profession;

typedef struct{
	char name[50];
	Profession profession;
	equipment* gear; // Points to an array up to 3 equipment for the adventurer
	int gearscore;
}adventurer;

typedef struct Node{
	struct Node* next;
	adventurer Adventurer;
}node
