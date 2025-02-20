//
// Created by xiaobai2-2025 on 2/20/25.
//

#include "type_missmatch_exception.h"

Type_Missmatch_Exception::Type_Missmatch_Exception( const std::string & msg,
    const Parsed_Object & parsed_object ) noexcept :
    _msg{ msg }, _parsed_object{parsed_object} {}

const char * Type_Missmatch_Exception::what() const noexcept {
    return this->_msg.c_str();
}

const Parsed_Object & Type_Missmatch_Exception::get_parsed_object() const noexcept {
    return this->_parsed_object;
}
