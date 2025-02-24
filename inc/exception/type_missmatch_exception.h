//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include <exception>
#include <string>

#include "parsed_object.h"

class Type_Missmatch_Exception final : public std::exception {

    private:
        std::string _msg;

    private:
        const unsigned long _row;
        const unsigned long _col;

    public:
        explicit Type_Missmatch_Exception( const std::string &,
            const unsigned long &, const unsigned long & ) noexcept;

    public:
        [[nodiscard]] const char * what() const noexcept override;

    public:
        [[nodiscard]] const unsigned long & get_row() const noexcept;
        [[nodiscard]] const unsigned long & get_col() const noexcept;

}; // class Type_Missmatch_Exception <- Exception
