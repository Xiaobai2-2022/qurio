//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    Parsed_Lex_Object * lex = new Parsed_Lex_Delimiter{ 33, 14, DELIMITER_RPAREN };

    try {

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Delimiter * >( lex ) );

        PRINT_INFO( "Lex is valid:", lex->is_valid(), "." );

        lex->set_value( DELIMITER_LPAREN );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Delimiter * >( lex ) );

        lex->set_row( 150 );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Delimiter * >( lex ) );

        PRINT_WARN( "Illegal Change Here" );

        lex->set_value( KEYWORD );

        PRINT_INFO( *dynamic_cast< Parsed_Lex_Delimiter * >( lex ) );

    } catch( const Type_Missmatch_Exception & tme ) {
        PRINT_ERROR( tme.what(), "At:", tme.get_parsed_object());
    } // try

    delete lex;

} // main
