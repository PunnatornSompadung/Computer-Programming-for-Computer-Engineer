#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char piece [20][10];
    int total;

    explode("I/Love/You", '/', piece , &total);

    for (int i = 0; i < total; i++) {
        printf("%s\n", piece [i]);
    }

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int buckets = 0;
    int pos = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == splitter) {
            str2[buckets][pos] = '\0';
            buckets++;
            pos = 0;
        } else {
            str2[buckets][pos++] = str1[i];
        }
    }

    str2[buckets][pos] = '\0';
    *count = buckets + 1;
}