//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

int main() {

    Token * lex = new Token_Identifier { 33, 14, "SYMBOL_COMP_EQUAL" };

    PRINT_INFO( *dynamic_cast< Token_Identifier * >( lex ) );

    lex->set_row( 140 );

    PRINT_INFO( *dynamic_cast< Token_Identifier * >( lex ) );

    delete lex;

} // main
