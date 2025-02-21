//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    Token * lex = new Token_Symbol{ 33, 14, SYMBOL, SYMBOL_COMP_EQUAL };

    try {

        PRINT_INFO( *dynamic_cast< Token_Symbol * >( lex ) );

        lex->set_row( 150 );

    } catch( const Type_Missmatch_Exception & tme ) {
        PRINT_ERROR( tme.what(), "At:", tme.get_parsed_object());
    } // try

    delete lex;

} // main
