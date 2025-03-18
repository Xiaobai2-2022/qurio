int test;

int main ( int, string );
unsigned int test_method ( unsigned int, unsigned int );

unsigned int test_method ( unsigned int a, unsigned int b ) {

    if ( a < b ) {
        return a;
    }

    if( unsigned int c = a, c == b ) {
        // return c;
        return a;
    } else
        return b;

}

int main ( int argc, string argv ) {

    for( unsigned int i = 0; unsigned int j = 4, i < j; ++i ) {
        test_method( 3, i );
    }

    return 0;

}
