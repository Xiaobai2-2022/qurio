//
// Created by xiaobai2-2025 on 2/19/25.
//

#include "parsed_object.h"

Parsed_Object::Parsed_Object( const unsigned long & row, const unsigned long & col) noexcept :
    _row{row}, _col{col} {}

unsigned long Parsed_Object::get_row() const noexcept {
    return this->_row;
}

unsigned long Parsed_Object::get_col() const noexcept {
    return this->_col;
}

void Parsed_Object::set_row( const unsigned long & row) noexcept {
    this->_row = row;
}

void Parsed_Object::set_col( const unsigned long & col) noexcept {
    this->_col = col;
}

std::ostream & operator<<( std::ostream & os, const Parsed_Object & parsed_object) noexcept {
    os << "Parsed Object: { Row: " << parsed_object._row <<
        ", Col: " << parsed_object._col << " }";
    return os;
}
