//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_identifier.h"

Token_Identifier::Token_Identifier( const unsigned long & row, const unsigned long & col,
    const std::string & value, std::string str_val ) noexcept :
    Token{ row, col, IDENTIFIER, std::move( str_val ) }, _value{ value } {}

std::any Token_Identifier::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Identifier & token_identifier) noexcept {

    const Token & base = token_identifier;
    os << "Token Identifier: { Type: " << token_identifier._type <<
        ", Value: " << token_identifier._value << " } is a: " << base;
    return os;

}
