//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "file_not_found_exception.h"

File_Not_Found_Exception::File_Not_Found_Exception( const std::string & msg,
    const std::string & f_name ) noexcept :
    _msg{ msg }, _f_name{f_name} {}

const char * File_Not_Found_Exception::what() const noexcept {
    return this->_msg.c_str();
}

std::string File_Not_Found_Exception::get_f_name() const noexcept {
    return this->_f_name;
}

