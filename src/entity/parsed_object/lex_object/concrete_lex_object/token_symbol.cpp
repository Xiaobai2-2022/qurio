//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_symbol.h"

#include "type_missmatch_exception.h"

Token_Symbol::Token_Symbol( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, const QURIO_Symbol & value) noexcept :
    Token{ row, col, type }, _value{ value } {}

std::any Token_Symbol::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Symbol & token_symbol ) noexcept {
    const Token & base = token_symbol;
    os << "Token Symbol: { Type: " << token_symbol._type <<
        ", Value: " << token_symbol._value << " } is a: " << base;
    return os;
}
