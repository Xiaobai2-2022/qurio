//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_number.h"

#include "log.h"
#include "type_missmatch_exception.h"
#include "qurio_string.h"

Token_Number::Token_Number( const unsigned long & row, const unsigned long & col,
    const std::string & value) :
    Token{ row, col, NUMBER }, _value{ value } {

    if ( !Qurio_String::is_valid_number( value ) ) {
        PRINT_ERROR(
            "Type Missmatch Exception thrown",
            "in parse_token_number.cpp",
            "in Token_Number::Token_Number( const unsigned long &, const unsigned long &, const Parsed_Lex_Type, const std::string & )."
        );

        std::string error_msg = "Invalid token, \"";
        error_msg += value;
        error_msg += "\" is not a valid number";
        throw Type_Missmatch_Exception{
            error_msg,
            this->_row,
            this->_col
        };
    }

}

std::any Token_Number::get_value() const noexcept {
    return this->_value;
}

std::ostream & operator<<( std::ostream & os, const Token_Number & token_number ) noexcept {

    const Token & base = token_number;
    os << "Token Number: { Type: " << token_number._type <<
        ", Value: " << token_number._value << " } is a: " << base;
    return os;

}
