//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_lexer.h"

#include <token_delimiter.h>
#include <token_identifier.h>
#include <token_number.h>

#include "file_failure_exception.h"
#include "lexer_msg.h"
#include "log.h"
#include "token_list.h"
#include "type_missmatch_exception.h"

void Qurio_Lexer::tokenizer( const std::string & f_name, std::queue<Token *> & tokens ) {

    LEXER_DEBUG( LEXER_BEGIN );

    std::fstream fs;

    LEXER_DEBUG( LEXER_OPEN_FILE, f_name );

    fs.open( f_name );

    if ( !fs ) {
        LEXER_ERROR( LEXER_NO_FILE, f_name );
        throw File_Failure_Exception{
            "Tokenizer Failed to open file:",
            f_name
        };
    }

    LEXER_DEBUG( LEXER_FILE_OPEN, f_name );
    LEXER_DEBUG( LEXER_START_SCAN );

    unsigned long row = 0;
    unsigned long col = 0;

    char next_char;

    fs.get( next_char );

    for ( ; ; ) {

        // Check for End of File
        if( fs.eof() ) break;

        // Check for Whitespace
        if( next_char == ' ' ) {
            fs.get( next_char );
            ++col;
            continue;
        }
        if( next_char == '\n' )
        {
            fs.get( next_char );
            ++row;
            col = 0;
            continue;
        }

        try {
            Qurio_Lexer::get_token_helper( row, col, fs, next_char, tokens );
        } catch( Type_Missmatch_Exception & tme ) {
            LEXER_ERROR( LEXER_RETHROW, tme.what(), "At Qurio_Lexer::tokenizer." );
            throw;
        }
        ++col;

    }

    if( !fs.eof() ) {
        LEXER_ERROR( LEXER_FILE_READ_FAIL, f_name );
        throw File_Failure_Exception{
            "File read terminated unexpectedly:",
            f_name
        };
    }

    LEXER_DEBUG( LEXER_END_SCAN );

    LEXER_DEBUG( LEXER_END );

}

void Qurio_Lexer::get_token_helper(
    unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    if( Token_List::delimiter_list.contains( cur_char ) ) {
        Qurio_Lexer::get_token_delimiter_helper( row, col, cur_char, tokens );
        fs.get( cur_char );
        ++col;
    } else if( cur_char >= '0' && cur_char <= '9' ) {
        try {
            Qurio_Lexer::get_token_number_helper( row, col, fs, cur_char, tokens );
        } catch( Type_Missmatch_Exception & tme ) {
            LEXER_ERROR( LEXER_RETHROW, tme.what(), "At Qurio_Lexer::get_token_helper." );
            throw;
        }
    } else {
        fs.get( cur_char );
        ++col;
    }
}

void Qurio_Lexer::get_token_delimiter_helper(
    const unsigned long & row, const unsigned long & col,
    const char & cur_char, std::queue< Token * > & tokens ) {

    auto * token = new Token_Delimiter { row, col, Token_List::delimiter_list[ cur_char ] };
    tokens.push( token );
}

void Qurio_Lexer::get_token_number_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    unsigned long cur_col = col;

    std::string cur_number;

    while( !fs.eof() && !Token_List::symbol_list.contains( cur_char ) ) {
        cur_number += cur_char;
        fs.get( cur_char );
        ++cur_col;
    }

    try {
        auto * token = new Token_Number { row, col, cur_number };
        tokens.push( token );
    } catch( Type_Missmatch_Exception & tme ) {
        LEXER_ERROR( LEXER_RETHROW, tme.what(), "At Qurio_Lexer::get_token_number_helper." );
        throw;
    }

    col = cur_col;

}
