//
// Created by xiaobai2-2025 on 2/18/25.
//

#include "main.h"

#include "qurio_lexer.h"

int main() {

    const std::string f_name = "/home/xiaobai2-2025/proj-q/qurio/test/debug_test.qc";

    std::vector< Token * >tokens;

    Qurio_Lexer::tokenizer( f_name, tokens );

    PRINT_DEBUG( tokens.size() );

    while( !tokens.empty() ) {

        Token_Identifier * token = dynamic_cast< Token_Identifier * >( tokens.at(0) );
        tokens.erase( tokens.begin() );
        PRINT_DEBUG( *token );
        delete token;

    }

} // main
