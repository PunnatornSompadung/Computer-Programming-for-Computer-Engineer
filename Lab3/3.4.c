#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

void GetStudent(struct student child[][10], int *room);

int main() {
	struct student children[20][10];
	int group;
	GetStudent(children, &group);
	return 0;
}

void GetStudent(struct student child[][10], int *room) {
	int i, a;
	
	printf("Enter number of rooms: ");
	scanf("%d", room);
	
	for (i = 0; i < *room; i++) {
		printf("\nRoom %d:\n", i + 1);
		for (a = 0; a < 10; a++) {
			printf(" - Student %d Name: ", a + 1);
			scanf("%s", child[i][a].name);
			printf(" - Student %d Age: ", a + 1);
			scanf("%d", &child[i][a].age);
			printf(" - Student %d Sex (M/F): ", a + 1);
			scanf(" %c", &child[i][a].sex);
			printf(" - Student %d GPA: ", a + 1);
			scanf("%f", &child[i][a].gpa);
		}
	}
}