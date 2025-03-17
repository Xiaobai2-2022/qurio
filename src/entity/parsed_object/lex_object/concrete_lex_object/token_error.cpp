//
// Created by xiaobai2-2025 on 2/24/25.
//

#include "token_error.h"

Token_Error::Token_Error( const unsigned long & row, const unsigned long & col,
    const std::string & value, std::string str_val ) noexcept :
    Token{ row, col, ERROR_TYPE, std::move( str_val ) }, _value{ value } {}

std::any Token_Error::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Error & token_error ) noexcept {
    const Token & base = token_error;
    os << "Token Error: { Type: " << token_error._type <<
        ", Value: " << token_error._value << " } is a: " << base;
    return os;
}