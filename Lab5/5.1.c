#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa);
void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);
    DelNode(now); ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while(walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa) {
    struct studentNode *newNode;
    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if(*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *walk = *start;
        while(walk->next != NULL) {
            walk = walk->next;
        }
        walk->next = newNode;
    }
    return newNode;
}

void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa) {
    if(now == NULL) return;
    struct studentNode *newNode;
    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    
    newNode->next = now->next;
    now->next = newNode;
}

void DelNode(struct studentNode *now) {
    struct studentNode *temp;
    if(now != NULL && now->next != NULL) {
        temp = now->next;
        now->next = temp->next;
        free(temp);
    }
}