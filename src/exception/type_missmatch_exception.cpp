//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "type_missmatch_exception.h"

Type_Missmatch_Exception::Type_Missmatch_Exception( const std::string & msg,
    const unsigned long & row, const unsigned long & col ) noexcept :
    _msg{ msg }, _row{row}, _col{col} {}

const char * Type_Missmatch_Exception::what() const noexcept {
    _cached_msg = _msg +
        " at { Row: " + std::to_string(_row) +
        ", Col: " + std::to_string( _col ) + " }";
    return _cached_msg.c_str();
}

const unsigned long & Type_Missmatch_Exception::get_row() const noexcept {
    return this->_row;
}

const unsigned long & Type_Missmatch_Exception::get_col() const noexcept {
    return this->_col;
}
