#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char str1[]);

int main() {
    char text[50] = "Hello World";
    char *out;

    out = reverse(text);
    printf("%s\n", out); //

    free(out);
    return 0;
}

char* reverse(char str1[]) {
    int x = strlen(str1);
    char *flipped = (char *)malloc(x + 1);

    int p = 0;
    for (int a = x - 1; a >= 0; a--) {
        flipped[p++] = str1[a];
    }
    flipped[p] = '\0';

    return flipped;
}