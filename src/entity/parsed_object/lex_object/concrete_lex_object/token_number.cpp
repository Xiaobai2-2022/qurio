//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "token_number.h"

#include "log.h"
#include "type_missmatch_exception.h"
#include "qurio_string.h"

Token_Number::Token_Number( const unsigned long & row, const unsigned long & col,
    const Parsed_Lex_Type & type, const std::string & value) :
    Token{ row, col, type }, _value{ value } {

    if ( !Qurio_String::is_valid_number( value ) ) {
        PRINT_DEBUG(
            "Type Missmatch Exception thrown",
            "in parse_lex_number.cpp",
            "in Token_Number::Token_Number( const unsigned long &, const unsigned long &, const Parsed_Lex_Type, const std::string & )."
        );
        throw Type_Missmatch_Exception{
            "Invalid Token",
            *this
        };
    }

}

std::any Token_Number::get_value() const noexcept {
    return this->_value;
}

void Token_Number::set_value( const std::any & value ) {

    try {
        this->_value = std::any_cast< std::string >( value );
    } catch ( const std::bad_any_cast & ) {
        PRINT_DEBUG( "Type Missmatch Exception thrown",
            "in parse_lex_number.cpp",
            "in Token_Number::set_value( const std::any )."
        );
        throw Type_Missmatch_Exception {
            "Unexpected Control Keyword Replacement",
            *this
        };
    }

    if ( !Qurio_String::is_valid_number( this->_value ) )
    {
        PRINT_DEBUG(
            "Type Missmatch Exception thrown",
            "in parse_lex_number.cpp",
            "in Token_Number::set_value( const std::any )."
        );
        throw Type_Missmatch_Exception{
            "Invalid Number Token",
            *this
        };
    }

}

std::ostream & operator<<( std::ostream & os, const Token_Number & lex_number ) noexcept {

    const Token & base = lex_number;
    os << "Parsed Lex Number: { Type: " << lex_number._type <<
        ", Value: " << lex_number._value << " } is a: " << base;
    return os;

}
