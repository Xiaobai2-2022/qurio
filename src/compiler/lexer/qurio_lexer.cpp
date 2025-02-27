//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "qurio_lexer.h"

#include <qurio_string.h>
#include <token_error.h>
#include <token_keyword.h>
#include <token_operator.h>
#include <token_string.h>

#include "token_delimiter.h"
#include "token_identifier.h"
#include "token_number.h"

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

    unsigned long row = 1;
    unsigned long col = 1;

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
            col = 1;
            continue;
        }

        try {
            Qurio_Lexer::get_token_helper( row, col, fs, next_char, tokens );
        } catch( std::exception & tme ) {
            LEXER_ERROR( LEXER_RETHROW, tme.what(), "at Qurio_Lexer::tokenizer." );
            // throw;
        }

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

} // tokenizer

void Qurio_Lexer::get_token_helper(
    unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    if( Token_List::delimiter_list.contains( cur_char ) ) {
        Qurio_Lexer::get_token_delimiter_helper( row, col, fs, cur_char, tokens );
    } else if( Token_List::symbol_list.contains( cur_char ) ) {
        if( cur_char == '\'' || cur_char == '\"' )
            try {
                Qurio_Lexer::get_token_string_helper( row, col, fs, cur_char, tokens );
            } catch( std::exception & tme ) {
                LEXER_ERROR( LEXER_ERROR_CAUGHT, tme.what(), "at Qurio_Lexer::get_token_helper." );
            }
        else
            Qurio_Lexer::get_token_operator_helper( row, col, fs, cur_char, tokens );
    } else if( cur_char >= '0' && cur_char <= '9' ) {
        try {
            Qurio_Lexer::get_token_number_helper( row, col, fs, cur_char, tokens );
        } catch( std::exception & tme ) {
            LEXER_ERROR( LEXER_ERROR_CAUGHT, tme.what(), "at Qurio_Lexer::get_token_helper." );
        }
    } else {
        Qurio_Lexer::get_token_identifier_helper( row, col, fs, cur_char, tokens );
    }

} // get_token_helper

void Qurio_Lexer::get_token_delimiter_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    auto * token = new Token_Delimiter { row, col, Token_List::delimiter_list[ cur_char ] };
    tokens.push( token );

    fs.get( cur_char );
    ++col;

} // get_token_delimiter_helper

void Qurio_Lexer::get_token_number_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    unsigned long cur_col = col;

    std::string cur_number;

    while( !fs.eof() &&
        ( !Token_List::symbol_list.contains( cur_char ) ||
        cur_char == '\'' || cur_char == '.' ) &&
        cur_char != ' ' && cur_char != '\n' ) {
        cur_number += cur_char;
        fs.get( cur_char );
        ++cur_col;
    }

    try {
        auto * token = new Token_Number { row, col, cur_number };
        tokens.push( token );
    } catch( Type_Missmatch_Exception & tme ) {
        tokens.push( new Token_Error{ row, col, tme.what() } );
        LEXER_ERROR( LEXER_RETHROW, tme.what(), "at Qurio_Lexer::get_token_number_helper." );
        col = cur_col;
        throw;
    }

    col = cur_col;

} // get_token_number_helper

void Qurio_Lexer::get_token_operator_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    unsigned long cur_col = col;

    std::string cur_operator;
    std::string updated_operator;

    do {
        updated_operator += cur_char;
        cur_operator = updated_operator;
        fs.get( cur_char );
        ++cur_col;
    } while( !fs.eof() &&
        Token_List::symbol_list.contains( cur_char ) &&
        Token_List::operator_list.contains( updated_operator ) );

    auto * token = new Token_Operator { row, col, Token_List::operator_list[ cur_operator ] };
    tokens.push( token );

    col = cur_col;

} // get_token_operator_helper

void Qurio_Lexer::get_token_string_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    unsigned long cur_col = col;

    const bool is_char = cur_char == '\'';

    std::string cur_string;
    std::string updated_string;

    do {
        cur_string = updated_string;
        updated_string += cur_char;
        fs.get( cur_char );
        ++cur_col;
    } while( !fs.eof() &&
        cur_char != '\n' &&
        !Qurio_String::is_last_quote( updated_string + cur_char ) );

    cur_string = updated_string;

    if( !fs.eof() && cur_char != '\n' ) {
        cur_string += cur_char;
        fs.get( cur_char );
        ++cur_col;
    }

    PRINT_WARN ( cur_string, Qurio_String::is_last_quote( cur_string ) );

    if( !Qurio_String::is_last_quote( cur_string ) || ( is_char && !Qurio_String::is_valid_char( cur_string ) ) ) {

        try {
            std::string error_msg = "Invalid token, ";
            error_msg += cur_string;
            error_msg += " is not a valid ";
            error_msg += (is_char ? "char" : "string");
            throw Type_Missmatch_Exception{
                error_msg,
                row,
                col
            };
        } catch ( Type_Missmatch_Exception & tme ) {
            tokens.push( new Token_Error{ row, col, tme.what() } );
            LEXER_ERROR( LEXER_THROW, tme.what(), "at Qurio_Lexer::get_token_string_helper." );
            col = cur_col;
            throw;
        }

    }

    auto * token = new Token_String { row, col,
        (is_char ? CHAR : STRING), cur_string };
    tokens.push( token );

    col = cur_col;

} // get_token_string_helper

void Qurio_Lexer::get_token_identifier_helper(
    const unsigned long & row, unsigned long & col,
    std::fstream & fs, char & cur_char, std::queue< Token * > & tokens ) {

    unsigned long cur_col = col;

    const bool is_char = cur_char == '\'';

    std::string cur_string;

    do {
        cur_string += cur_char;
        fs.get( cur_char );
        ++cur_col;
    } while( !fs.eof() &&
        cur_char != '\n' &&
        cur_char != ' ' &&
        !Token_List::symbol_list.contains( cur_char )
        );

    if( Token_List::keyword_list.contains( cur_string ) ) {
        auto * token = new Token_Keyword { row, col,
            Token_List::keyword_list[ cur_string ] };
        tokens.push( token );
    } else {
        auto * token = new Token_Identifier { row, col,
            cur_string };
        tokens.push( token );
    }

    col = cur_col;

} // get_token_identifier_helper
