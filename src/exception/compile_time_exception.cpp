//
// Created by xiaobai2-2025 on 3/12/25.
//

#include "compile_time_exception.h"

Compile_Time_Exception::Compile_Time_Exception( const std::string & msg,
    AST_Node *& error_node) noexcept :
    _msg{ msg }, _error_node{ error_node } {}

const char * Compile_Time_Exception::what() const noexcept {
    return _msg.c_str();
}

void Compile_Time_Exception::free_node() noexcept {
    this->_error_node->unlink_this();
    delete this->_error_node;
    this->_error_node = nullptr;
}
