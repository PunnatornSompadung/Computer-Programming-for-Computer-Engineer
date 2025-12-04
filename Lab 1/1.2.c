#include <stdio.h>

int* GetSet( int *n )
{
    static int set[100] ;   // ขนาดสูงสุด 100 ตัว (ปรับได้)
    int i ;

    printf( "Enter Number : " ) ;
    scanf( "%d", n ) ;

    for( i = 0; i < *n; i++ ) {
        printf( "Number [%d] : ", i+1 ) ;
        scanf( "%d", &set[i] ) ;
    }

    return set ;
}

int main()
{
    int *data, num, i ;

    data = GetSet( &num ) ;

    printf( "\nNumber: " ) ;
    for( i = 0 ; i < num ; i++ ) {
        printf( "[%d]", data[i] ) ;
    }

    return 0 ;
}
