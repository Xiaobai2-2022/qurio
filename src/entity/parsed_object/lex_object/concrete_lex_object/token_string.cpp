//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_string.h"

#include "log.h"

Token_String::Token_String( const unsigned long & row, const unsigned long & col,
    const std::string & value) noexcept :
    Token{ row, col, STRING }, _value{ value } {}

std::any Token_String::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_String & token_string ) noexcept {

    const Token & base = token_string;
    os << "Parsed Lex Number: { Type: " << token_string._type <<
        ", Value: " << token_string._value << " } is a: " << base;
    return os;

}
