//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

#include "qurio_lexer.h"

int main() {

    const std::string f_name = "/home/xiaobai2-2025/proj-q/qurio/test/debug_test.qc";

    std::queue< Token * >tokens;

    try {
        Qurio_Lexer::tokenizer( f_name, tokens );
    } catch( Type_Missmatch_Exception tme ) {
        PRINT_ERROR( tme.what(), "at", tme.get_row(), tme.get_col() );
    }

    PRINT_DEBUG( tokens.size() );

    while( !tokens.empty() ) {

        Token * token = tokens.front();
        tokens.pop();

        if( token->get_type() == DELIMITER ) {
            auto * token_delimiter = dynamic_cast< Token_Delimiter * > ( token );
            PRINT_DEBUG( * token_delimiter );
        }

        if( token->get_type() == NUMBER ) {
            auto * token_number = dynamic_cast< Token_Number * > ( token );
            PRINT_DEBUG( * token_number );
        }

        delete token;

    }

} // main
