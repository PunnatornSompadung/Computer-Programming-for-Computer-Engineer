#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num;

    explode("I/Love/You", '/', out, &num);

    for (int x = 0; x < num; x++) {
        printf("%s\n", out[x]);
    }

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int piece = 0;
    int letter = 0;

    for (int a = 0; str1[a] != '\0'; a++) {
        if (str1[a] == splitter) {
            str2[piece][letter] = '\0';
            piece++;
            letter = 0;
        } else {
            str2[piece][letter++] = str1[a];
        }
    }

    str2[piece][letter] = '\0';
    *count = piece + 1;
}