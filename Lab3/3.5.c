#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int id;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student(*children)[10];
    int group;
    children = GetStudent(&group);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    struct student(*students)[10] = (struct student(*)[10])malloc((*room) * sizeof(struct student[10]));

    for (int a = 0; a < *room; a++) {
        printf("Room %d\n", a + 1);
        for (int o = 0; o < 10; o++) {
            printf("Student %d\n", o + 1);
            printf("ID: ");
            scanf("%d", &students[a][o].id);
            printf("Name: ");
            scanf("%s", students[a][o].name);
        }
    }
    return students;
}