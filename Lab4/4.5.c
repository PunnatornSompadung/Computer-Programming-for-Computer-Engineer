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
void GoNext2(struct studentNode **walk);

int main() {
	struct studentNode *start, **now2;
	
	start = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start, "one", 6, 'M', 3.11);
	
	start->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next, "two", 8, 'F', 3.22);
	
	start->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next->next, "three", 10, 'M', 3.33);

	start->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next->next->next, "four", 12, 'F', 3.44);
	start->next->next->next->next = NULL;

	now2 = &start;

	GoNext2(now2);
	printf("%s ", (*now2)->name);

	free(start->next->next->next);
	free(start->next->next);
	free(start->next);
	free(start);
	
	return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
	strcpy(child->name, n);
	child->age = a;
	child->sex = s;
	child->gpa = g;
}

void GoNext2(struct studentNode **walk) {
    if ((*walk)->next != NULL) {
        walk = &(*walk)->next;
        printf("%s ", (*walk)->name);
    }
}