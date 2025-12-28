#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

void upgrade(struct student *add);

int main() {
	struct student aboy;
	aboy.sex = 'M';
	aboy.gpa = 3.00;
	
	upgrade(&aboy);
	
	printf("%.2f", aboy.gpa);
	return 0;
}

void upgrade(struct student *add) {
	if (add->sex == 'M') {
		add->gpa = add->gpa * 1.1;
	} else if (add->sex == 'F') {
		add->gpa = add->gpa * 1.2;
	}
}