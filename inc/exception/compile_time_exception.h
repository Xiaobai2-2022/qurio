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
        const unsigned long _row;
        const unsigned long _col;

    private:
        AST_Node * _error_node;

    public:
        Compile_Time_Exception( const std::string &,
            const unsigned long &, const unsigned long &,
            AST_Node *& ) noexcept;

    public:
    [[nodiscard]] const char * what() const noexcept override;

    public:
        [[nodiscard]] const unsigned long & get_row() const noexcept;
        [[nodiscard]] const unsigned long & get_col() const noexcept;

    public:
    void free_node() noexcept;

}; // class Compile_Time_Exception <- Exception
