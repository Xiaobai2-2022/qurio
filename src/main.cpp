//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    Token * lex = new Token_Delimiter{ 33, 14, DELIMITER_LBRACE };

    try {

        PRINT_INFO( *dynamic_cast< Token_Delimiter * >( lex ) );

        lex->set_value( DELIMITER_RBRACE );

        PRINT_INFO( *dynamic_cast< Token_Delimiter * >( lex ) );

        lex->set_row( 150 );

        PRINT_INFO( *dynamic_cast< Token_Delimiter * >( lex ) );

        PRINT_WARN( "Illegal Change Here" );

        lex->set_value( SYMBOL );

        PRINT_INFO( *dynamic_cast< Token_Delimiter * >( lex ) );

    } catch( const Type_Missmatch_Exception & tme ) {
        PRINT_ERROR( tme.what(), "At:", tme.get_parsed_object());
    } // try

    delete lex;

} // main
