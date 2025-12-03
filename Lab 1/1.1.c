#include<stdio.h>

int main() {
    int xx ;
    scanf( "%d", &xx ) ;

    for ( int i = 1; i <= xx; i++ ) { //(0 = 0-xx) ,(1 = 1-xx)
        printf( "[%d] Hello world\n", i ) ;
    }

    return 0;
}