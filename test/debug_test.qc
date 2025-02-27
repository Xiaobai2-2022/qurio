unsigned int function1( unsigned int );

unsigned int function1( unsigned int i) {

    unsigned int x = 1;

    while( x < 10 ) {
        for( i; i < 100; i += 10 ){
            int j = i % x;
            if( j == 0 ) x++;
            else ++i;
        }
    }

    // Return the result of the greater of i or x
    return x > i ? x : i;

}
