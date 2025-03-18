//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <exception>
#include <string>

#include "ast_node.h"

class Compile_Time_Exception final : public std::exception {

    private:
        std::string _msg;

    private:
        AST_Node * _error_node;

    public:
        Compile_Time_Exception( const std::string &,
            AST_Node *& ) noexcept;

    public:
    [[nodiscard]] const char * what() const noexcept override;

    public:
    void free_node() noexcept;

}; // class Compile_Time_Exception <- Exception
