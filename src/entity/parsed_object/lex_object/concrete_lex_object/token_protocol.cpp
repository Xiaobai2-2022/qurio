//
// Created by xiaobai2-2025 on 3/7/25.
//

#include "token_protocol.h"

Token_Protocol::Token_Protocol( const unsigned long & row, const unsigned long & col,
    const QURIO_Protocol & value, std::string str_val ) noexcept :
    Token{ row, col, PROTOCOL, std::move( str_val ) }, _value{ value } {}

std::any Token_Protocol::get_value() const noexcept {
    return this->_value;
}

void Token_Protocol::set_protocol( const QURIO_Protocol & value,  std::string str_val ) noexcept {
    this->_value = value;
    this->_str_val = std::move( str_val );
}


std::ostream & operator<<( std::ostream & os, const Token_Protocol & token_protocol ) noexcept {
    const Token & base = token_protocol;
    os << "Token Protocol: { Type: " << token_protocol._type <<
        ", Value: " << token_protocol._value << " } is a: " << base;
    return os;
}
