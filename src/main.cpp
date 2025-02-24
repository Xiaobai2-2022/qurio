//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

#include <token_error.h>

#include "qurio_lexer.h"

int main() {

    const std::string f_name = "/home/xiaobai2-2025/proj-q/qurio/test/debug_test.qc";

    std::queue< Token * >tokens;

    Qurio_Lexer::tokenizer( f_name, tokens );

    PRINT_DEBUG( tokens.size() );

    while( !tokens.empty() ) {

        Token * token = tokens.front();
        tokens.pop();

        if( token->get_type() == ERROR_TYPE ) {
            const auto * token_error = dynamic_cast< Token_Error * > ( token );
            PRINT_ERROR( * token_error );
        }

        if( token->get_type() == DELIMITER ) {
            const auto * token_delimiter = dynamic_cast< Token_Delimiter * > ( token );
            PRINT_DEBUG( * token_delimiter );
        }

        if( token->get_type() == NUMBER ) {
            const auto * token_number = dynamic_cast< Token_Number * > ( token );
            PRINT_DEBUG( * token_number );
        }

        if( token->get_type() == OPERATOR ) {
            const auto * token_number = dynamic_cast< Token_Operator * > ( token );
            PRINT_DEBUG( * token_number );
        }

        if( token->get_type() == STRING || token->get_type() == CHAR ) {
            const auto * token_string = dynamic_cast< Token_String * > ( token );
            PRINT_DEBUG( * token_string );
        }

        delete token;

    }

} // main
