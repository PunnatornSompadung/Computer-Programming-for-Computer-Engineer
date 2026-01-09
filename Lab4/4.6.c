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

void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext2(struct studentNode ***walk);

int main() {
    struct studentNode *start, *now1, **now2;

    start = (struct studentNode*) malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);

    start->next = (struct studentNode*) malloc(sizeof(struct studentNode));
    SaveNode(start->next, "two", 8, 'F', 3.22);

    start->next->next = (struct studentNode*) malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);

    start->next->next->next = (struct studentNode*) malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);

    now1 = start;
    now2 = &start;

    GoNext2(&now2);

    printf("%s ", (*now2)->name);

    return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

void GoNext2(struct studentNode ***walk) {
    if ((**walk)->next != NULL) {
        printf("%s %d %c %.2f ", (**walk)->next->name, (**walk)->next->age, (**walk)->next->sex, (**walk)->next->gpa);
        *walk = &((**walk)->next);
    }
}