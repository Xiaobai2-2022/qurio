//
// Created by xiaobai2-2025 on 2/21/25.
//

#include "file_failure_exception.h"

File_Failure_Exception::File_Failure_Exception( const std::string & msg,
    const std::string & f_name ) noexcept :
    _msg{ msg }, _f_name{f_name} {}

const char * File_Failure_Exception::what() const noexcept {
    return this->_msg.c_str();
}

std::string File_Failure_Exception::get_f_name() const noexcept {
    return this->_f_name;
}
