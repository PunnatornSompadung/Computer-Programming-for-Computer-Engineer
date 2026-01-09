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

void InsNode(struct studentNode **now, char *name, int age, char sex, float gpa);
void GoNext(struct studentNode ***now);
void DelNode(struct studentNode **now);
void ShowAll(struct studentNode **walk);

int main() {
    struct studentNode *start, **now;
    start = NULL;
    now = &start;
    InsNode(now, "one", 6, 'M', 3.11); ShowAll(&start);
    InsNode(now, "two", 8, 'F', 3.22); ShowAll(&start);
    GoNext(&now);
    InsNode(now, "three", 10, 'M', 3.33); ShowAll(&start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(&start);
    GoNext(&now);
    DelNode(now); ShowAll(&start);
    return 0;
}

void ShowAll(struct studentNode **walk) {
    while(*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &(*walk)->next;
    }
    printf("\n");
}

void InsNode(struct studentNode **now, char *name, int age, char sex, float gpa) {
    struct studentNode *newNode;
    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = *now;
    *now = newNode;
}

void GoNext(struct studentNode ***now) {
    if(*now != NULL && **now != NULL) {
        *now = &((**now)->next);
    }
}

void DelNode(struct studentNode **now) {
    struct studentNode *temp;
    if(*now != NULL) {
        temp = *now;
        *now = temp->next;
        free(temp);
    }
}