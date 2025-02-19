//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "../inc/main.h"

int main() {

    PRINT_DEBUG( "TEST DEBUG", 1, "TEST" );
    PRINT_WARN( "TEST WARN", 2 );
    PRINT_ERROR( "TEST ERROR", 3, "ERROR" );
    PRINT_INFO( "TEST INFO", 4, "IN", "FO" );

    // Parsed_Object parsed_object{3, 4};
    //
    // parsed_object.print();
    //
    // parsed_object.set_col(5);
    // parsed_object.print();

    // PRINT_DEBUG( parsed_object.get_row() );
    //
    // parsed_object.set_row(10);
    // parsed_object.print();
    //
    // PRINT_WARN( parsed_object.get_col() );

}