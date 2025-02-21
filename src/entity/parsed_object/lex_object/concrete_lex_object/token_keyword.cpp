//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_keyword.h"

#include "log.h"
#include "type_missmatch_exception.h"

Token_Keyword::Token_Keyword( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, const QURIO_Keyword & value) noexcept :
    Token{ row, col, type }, _value{ value } {}

std::any Token_Keyword::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Keyword & lex_keyword ) noexcept {
    const Token & base = lex_keyword;
    os << "Parsed Lex Keyword: { Type: " << lex_keyword._type <<
        ", Value: " << lex_keyword._value << " } is a: " << base;
    return os;
}
