//
// Created by xiaobai2-2025 on 2/19/25.
//

#include "../../inc/entity/parsed_object.h"

Parsed_Object::Parsed_Object( unsigned long row, unsigned long col) :
    _row{row}, _col{col} {}

Parsed_Object::~Parsed_Object() {}

unsigned long Parsed_Object::get_row() const {
    return this->_row;
}

unsigned long Parsed_Object::get_col() const {
    return this->_col;
}

void Parsed_Object::set_row( const unsigned long & row) {
    this->_row = row;
}

void Parsed_Object::set_col( const unsigned long & col) {
    this->_col = col;
}

void Parsed_Object::print() const {
    PRINT_INFO( *this );
}

std::ostream & operator<<( std::ostream & os, const Parsed_Object & parsed_object) {
    os << "Parsed_Object At { Row: " << parsed_object._row << ", Col: " << parsed_object._col << " }";
    return os;
}
