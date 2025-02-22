//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_lexer.h"

#include <token_identifier.h>

#include "file_failure_exception.h"

#include "log.h"
#include "lexer_msg.h"

void Qurio_Lexer::tokenizer( const std::string & f_name, std::vector<Token *> & tokens ) {

    LEXER_DEBUG( LEXER_BEGIN );

    std::fstream file;

    LEXER_DEBUG( LEXER_OPEN_FILE, f_name );

    file.open( f_name );

    if ( !file ) {

        LEXER_ERROR( LEXER_NO_FILE, f_name );
        throw File_Failure_Exception{
            "Tokenizer Failed to open file:",
            f_name
        };
    }

    LEXER_DEBUG( LEXER_FILE_OPEN, f_name );

    char next_char;

    LEXER_DEBUG( LEXER_START_SCAN );

    while( file.get( next_char ) ) {
        Qurio_Lexer::get_token_helper( file, next_char, tokens );
    }

    if( !file.eof() ) {
        LEXER_ERROR( LEXER_FILE_READ_FAIL, f_name );
        throw File_Failure_Exception{
            "File read terminated unexpectedly:",
            f_name
        };
    }

    LEXER_DEBUG( LEXER_END_SCAN );

    LEXER_DEBUG( LEXER_END );

}

void Qurio_Lexer::get_token_helper( std::fstream & file, char & next_char, std::vector< Token * > & tokens ) {

    std::string s;

    s += next_char;

    char c;

    while( file.get( c ) ) {
        s+=c;
    }

    Token_Identifier * new_token = new Token_Identifier{0, 0, s};

    tokens.push_back( new_token );

}