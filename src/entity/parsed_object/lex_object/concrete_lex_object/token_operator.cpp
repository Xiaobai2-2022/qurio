//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_operator.h"

#include "type_missmatch_exception.h"

Token_Operator::Token_Operator( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, const QURIO_Operator & value) noexcept :
    Token{ row, col, type }, _value{ value } {}

std::any Token_Operator::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Operator & token_symbol ) noexcept {
    const Token & base = token_symbol;
    os << "Token Symbol: { Type: " << token_symbol._type <<
        ", Value: " << token_symbol._value << " } is a: " << base;
    return os;
}
