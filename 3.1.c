#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

void upgrade(struct student *stddd);

int main() {
	struct student aboy;
	aboy.sex = 'M';
	aboy.gpa = 3.00;
	
	upgrade(&aboy);
	
	printf("%.2f", aboy.gpa);
	return 0;
}

void upgrade(struct student *stddd) {
	if (stddd->sex == 'M') {
		stddd->gpa = stddd->gpa * 1.1;
	} else if (stddd->sex == 'F') {
		stddd->gpa = stddd->gpa * 1.2;
	}
}