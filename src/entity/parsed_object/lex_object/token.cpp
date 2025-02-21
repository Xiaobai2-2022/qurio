//
// Created by xiaobai2-2025 on 2/19/25.
//

#include "token.h"

Token::Token( const unsigned long & row, const unsigned long & col, const Parsed_Lex_Type & type ) noexcept
    : Parsed_Object{ row, col }, _type{ type } {}

Parsed_Lex_Type Token::get_type() const noexcept {
    return this->_type;
}

void Token::set_type( const Parsed_Lex_Type & type ) noexcept {
    this->_type = type;
}

std::ostream & operator<<( std::ostream & os, const Token & lex_object ) noexcept {
    const Parsed_Object & base = lex_object;
    os << "Parsed Lex Object is a: " << base;
    return os;
}
