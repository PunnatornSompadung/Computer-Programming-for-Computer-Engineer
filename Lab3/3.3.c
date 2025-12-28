#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

struct student upgrade(struct student add);

int main() {
	struct student aboy;
	aboy.sex = 'M';
	aboy.gpa = 3.00;
	
	aboy = upgrade(aboy);
	
	printf("%.2f", aboy.gpa);
	return 0;
}

struct student upgrade(struct student add) {
	if (add.sex == 'M') {
		add.gpa = add.gpa * 1.1;
	} else if (add.sex == 'F') {
		add.gpa = add.gpa * 1.2;
	}
	return add;
}