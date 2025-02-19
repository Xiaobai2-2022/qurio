//
// Created by xiaobai2-2025 on 2/19/25.
//

#include "../../inc/entity/parsed_lex_object.h"

Parsed_Lex_Object::Parsed_Lex_Object( const unsigned long & row, const unsigned long & col, const Parsed_Lex_Type & type ) noexcept
    : Parsed_Object{ row, col }, _type{ type }, _value{ nullptr } {}

Parsed_Lex_Type Parsed_Lex_Object::get_type() const noexcept {
    return this->_type;
}

void Parsed_Lex_Object::set_type( const Parsed_Lex_Type & type ) noexcept {
    this->_type = type;
}
