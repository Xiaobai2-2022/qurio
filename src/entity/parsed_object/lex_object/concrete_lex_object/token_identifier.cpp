//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "token_identifier.h"

#include "log.h"

Token_Identifier::Token_Identifier( const unsigned long & row, const unsigned long & col,
    const std::string & value) noexcept :
    Token{ row, col, IDENTIFIER }, _value{ value } {}

std::any Token_Identifier::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Identifier & token_identifier) noexcept {

    const Token & base = token_identifier;
    os << "Parsed Lex Number: { Type: " << token_identifier._type <<
        ", Value: " << token_identifier._value << " } is a: " << base;
    return os;

}
