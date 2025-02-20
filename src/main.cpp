//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

#include <type_missmatch_exception.h>

int main() {

    Parsed_Lex_Object * lex = new Parsed_Lex_Keyword{ 33, 14, KEYWORD, KEY_CONTROL_CONTINUE };

    try {

        PRINT_DEBUG( "OK", "Line 1" );

        PRINT_INFO( *dynamic_cast<Parsed_Lex_Keyword *>( lex ) );

        PRINT_DEBUG( "OK", "Line 2" );

        lex->set_value( KEY_CONTROL_BREAK );

        PRINT_DEBUG( "OK", "Line 3" );

        PRINT_INFO( *dynamic_cast<Parsed_Lex_Keyword *>( lex ) );

        PRINT_DEBUG( "OK", "Line 4" );

        lex->set_row( 150 );

        PRINT_DEBUG( "OK", "Line 5" );

        PRINT_INFO( *dynamic_cast<Parsed_Lex_Keyword *>( lex ) );

        PRINT_DEBUG( "OK", "Line 6" );

        PRINT_WARN( "Illegal Change Here" );

        lex->set_value( KEYWORD );

        PRINT_DEBUG( "OK", "Line 7" );

        PRINT_INFO( *dynamic_cast<Parsed_Lex_Keyword *>( lex ) );

        PRINT_DEBUG( "OK", "Line 8" );

    } catch( const Type_Missmatch_Exception & tme ) {
        PRINT_ERROR( tme.what(), "At:", tme.get_parsed_object());
    } // try

    delete lex;

} // main
