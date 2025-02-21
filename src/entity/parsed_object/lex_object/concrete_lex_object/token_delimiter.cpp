//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_delimiter.h"

#include "log.h"
#include "type_missmatch_exception.h"

Token_Delimiter::Token_Delimiter( const unsigned long & row, const unsigned long & col,
    const QURIO_Delimiter & value) noexcept :
    Token{ row, col, DELIMITER }, _value{ value } {}

std::any Token_Delimiter::get_value() const noexcept {
    return this->_value;
}

void Token_Delimiter::set_value( const std::any & value ) {

    try {
        this->_value = std::any_cast< QURIO_Delimiter >( value );
    } catch ( const std::bad_any_cast & ) {
        PRINT_DEBUG( "Type Missmatch Exception thrown",
            "in parse_lex_delimiter.cpp",
            "in Token_Delimiter::set_value( const std::any )." );
        throw Type_Missmatch_Exception {
            "Unexpected Delimiter Replacement",
            *this
        };
    }

}

std::ostream & operator<<( std::ostream & os, const Token_Delimiter & lex_keyword ) noexcept {
    const Token & base = lex_keyword;
    os << "Parsed Lex Delimiter: { Type: " << lex_keyword._type <<
        ", Value: " << lex_keyword._value << " } is a: " << base;
    return os;
}
