//
// Created by xiaobai2-2025 on 2/19/25.
//

#include "token.h"

#include <log.h>

#include <utility>

#include "token_delimiter.h"
#include "token_error.h"
#include "token_identifier.h"
#include "token_keyword.h"
#include "token_number.h"
#include "token_operator.h"
#include "token_protocol.h"
#include "token_string.h"

Token::Token( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, std::string str_val ) noexcept
    : Parsed_Object{ row, col }, _type{ type }, _str_val{ std::move( str_val ) } {}

Parsed_Lex_Type Token::get_type() const noexcept {
    return this->_type;
}

void Token::set_type( const Parsed_Lex_Type & type ) noexcept {
    this->_type = type;
}

std::string Token::to_string() const noexcept {
    return this->_str_val;
}

void Token::print_token( std::ostream & os, Token * token ) {

    if( token->get_type() == ERROR_TYPE ) {
        const auto * token_error = dynamic_cast< Token_Error * > ( token );
        os << *token_error;
    }

    if( token->get_type() == DELIMITER ) {
        const auto * token_delimiter = dynamic_cast< Token_Delimiter * > ( token );
        os << * token_delimiter;
    }

    if( token->get_type() == KEYWORD ) {
        const auto * token_keyword = dynamic_cast< Token_Keyword * > ( token );
        os << * token_keyword;
    }

    if( token->get_type() == IDENTIFIER ) {
        const auto * token_identifier = dynamic_cast< Token_Identifier * > ( token );
        os << * token_identifier;
    }

    if( token->get_type() == NUMBER ) {
        const auto * token_number = dynamic_cast< Token_Number * > ( token );
        os << * token_number;
    }

    if( token->get_type() == OPERATOR ) {
        const auto * token_number = dynamic_cast< Token_Operator * > ( token );
        os << * token_number;
    }

    if( token->get_type() == STRING || token->get_type() == CHAR ) {
        const auto * token_string = dynamic_cast< Token_String * > ( token );
        os << * token_string;
    }

    if ( token->get_type() == PROTOCOL ) {
        const auto * token_protocol = dynamic_cast< Token_Protocol * > ( token );
        os << * token_protocol;
    }
    
}


std::ostream & operator<<( std::ostream & os, const Token & token ) noexcept {
    const Parsed_Object & base = token;
    os << "Token: { String Value: \"" << token._str_val  << "\" } is a: " << base;
    return os;
}
