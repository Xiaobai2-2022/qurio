//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_keyword.h"

#include "log.h"
#include "type_missmatch_exception.h"

Token_Keyword::Token_Keyword( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, const QURIO_Keyword & value) noexcept :
    Token{ row, col, type }, _value{ value } {}

std::any Token_Keyword::get_value() const noexcept {
    return this->_value;
}

void Token_Keyword::set_value( const std::any & value ) {

    try {
        this->_value = std::any_cast< QURIO_Keyword >( value );
    } catch ( const std::bad_any_cast & ) {
        PRINT_DEBUG( "Type Missmatch Exception thrown",
            "in parse_lex_keyword.cpp",
            "in Token_Keyword::set_value( const std::any )."
        );
        throw Type_Missmatch_Exception {
            "Unexpected Control Keyword Replacement",
            *this
        };
    }

}

std::ostream & operator<<( std::ostream & os, const Token_Keyword & lex_keyword ) noexcept {
    const Token & base = lex_keyword;
    os << "Parsed Lex Keyword: { Type: " << lex_keyword._type <<
        ", Value: " << lex_keyword._value << " } is a: " << base;
    return os;
}
