//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_lexer.h"

#include "log.h"
#include "lexer_msg.h"

std::vector< Token * >Qurio_Lexer::tokenizer( const std::string & f_name ) {

    PRINT_DEBUG( LEXER_OUT , LEXER_BEGIN );

    std::fstream file;

    PRINT_DEBUG( LEXER_OUT , LEXER_OPEN_FILE, f_name );

    file.open( f_name );

    if (!file){
        PRINT_ERROR( LEXER_OUT, LEXER_NO_FILE, f_name );
        throw File_Not_Found_Exception{
            "Tokenizer Failed to open file:",
            f_name
        };
    }

    PRINT_DEBUG( LEXER_OUT, LEXER_FILE_OPEN, f_name );



    std::vector< Token * > tokens;

    PRINT_DEBUG( LEXER_OUT , LEXER_END );

    return tokens;

}