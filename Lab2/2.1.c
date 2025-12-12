#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]) ;

int main() {
    char text[50] = "I Love You" ;
    char out[50] ;

    reverse(text, out) ;
    printf("%s\n", out) ;

    return 0;
}

void reverse(char str1[], char str2[]) {
    int leftt = 0 ;
    int rightt = strlen(str1) - 1 ;
    int x = 0 ;

    while (rightt >= leftt) {
        str2[x++] = str1[rightt--] ;
    }
    str2[x] = '\0' ;
}