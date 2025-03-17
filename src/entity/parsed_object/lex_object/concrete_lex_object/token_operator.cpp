//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_operator.h"

#include "type_missmatch_exception.h"

Token_Operator::Token_Operator( const unsigned long & row, const unsigned long & col,
    const QURIO_Operator & value, std::string str_val ) noexcept :
    Token{ row, col, OPERATOR, std::move( str_val ) }, _value{ value } {}

std::any Token_Operator::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Operator & token_operator ) noexcept {
    const Token & base = token_operator;
    os << "Token Operator: { Type: " << token_operator._type <<
        ", Value: " << token_operator._value << " } is a: " << base;
    return os;
}
