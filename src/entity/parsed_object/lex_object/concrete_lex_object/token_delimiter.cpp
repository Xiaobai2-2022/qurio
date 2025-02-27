//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_delimiter.h"

#include "type_missmatch_exception.h"

Token_Delimiter::Token_Delimiter( const unsigned long & row, const unsigned long & col,
    const QURIO_Delimiter & value) noexcept :
    Token{ row, col, DELIMITER }, _value{ value } {}

std::any Token_Delimiter::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Delimiter & token_delimiter ) noexcept {
    const Token & base = token_delimiter;
    os << "Token Delimiter: { Type: " << token_delimiter._type <<
        ", Value: " << token_delimiter._value << " } is a: " << base;
    return os;
}
