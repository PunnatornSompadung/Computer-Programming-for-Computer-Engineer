#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define FILENAME "student.txt"

typedef struct Student {
    char name[MAX_NAME];
    int age;
    char sex;
    float gpa;
    struct Student* next;
} Student;

/* ================= Linked List Functions ================= */

Student* createNode(const char* name, int age, char sex, float gpa) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strncpy(newNode->name, name, MAX_NAME - 1);
    newNode->name[MAX_NAME - 1] = '\0';
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    return newNode;
}

void addStudent(Student** head, const char* name, int age, char sex, float gpa) {
    Student* newNode = createNode(name, age, sex, gpa);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Student* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

Student* findStudent(Student* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

int deleteStudent(Student** head, const char* name) {
    if (*head == NULL)
        return 0;

    Student* temp = *head;
    Student* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int editStudent(Student* head, const char* name, int age, char sex, float gpa) {
    Student* target = findStudent(head, name);
    if (target == NULL)
        return 0;

    target->age = age;
    target->sex = sex;
    target->gpa = gpa;
    return 1;
}

void showAll(Student* head) {
    if (head == NULL) {
        printf("No data available.\n");
        return;
    }

    while (head != NULL) {
        printf("%-15s %3d %c %.2f\n",
               head->name,
               head->age,
               head->sex,
               head->gpa);
        head = head->next;
    }
}

void freeList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ================= File Functions ================= */

void loadFromFile(Student** head) {
    FILE* fp = fopen(FILENAME, "r");
    if (fp == NULL)
        return;

    char name[MAX_NAME];
    int age;
    char sex;
    float gpa;

    while (fscanf(fp, "%19s %d %c %f", name, &age, &sex, &gpa) == 4) {
        addStudent(head, name, age, sex, gpa);
    }

    fclose(fp);
}

void saveToFile(Student* head) {
    FILE* fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Cannot open file for writing.\n");
        return;
    }

    while (head != NULL) {
        fprintf(fp, "%s %d %c %.2f\n",
                head->name,
                head->age,
                head->sex,
                head->gpa);
        head = head->next;
    }

    fclose(fp);
}

/* ================= Menu ================= */

void displayMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Add\n");
    printf("2. Edit\n");
    printf("3. Delete\n");
    printf("4. Find\n");
    printf("5. Show All\n");
    printf("0. Exit\n");
    printf("Select: ");
}

int main() {
    Student* head = NULL;
    int choice;

    loadFromFile(&head);

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }

        char name[MAX_NAME];
        int age;
        char sex;
        float gpa;

        switch (choice) {
            case 1:
                printf("Enter Name Age Sex GPA: ");
                scanf("%19s %d %c %f", name, &age, &sex, &gpa);
                addStudent(&head, name, age, sex, gpa);
                printf("Added successfully.\n");
                break;

            case 2:
                printf("Enter name to edit: ");
                scanf("%19s", name);
                if (findStudent(head, name)) {
                    printf("Enter new Age Sex GPA: ");
                    scanf("%d %c %f", &age, &sex, &gpa);
                    editStudent(head, name, age, sex, gpa);
                    printf("Updated successfully.\n");
                } else {
                    printf("Name not found.\n");
                }
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%19s", name);
                if (deleteStudent(&head, name))
                    printf("Deleted successfully.\n");
                else
                    printf("Name not found.\n");
                break;

            case 4:
                printf("Enter name to find: ");
                scanf("%19s", name);
                {
                    Student* s = findStudent(head, name);
                    if (s != NULL)
                        printf("Found: %s %d %c %.2f\n",
                               s->name, s->age, s->sex, s->gpa);
                    else
                        printf("Not found.\n");
                }
                break;

            case 5:
                showAll(head);
                break;

            case 0:
                saveToFile(head);
                printf("Data saved. Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    freeList(head);
    return 0;
}