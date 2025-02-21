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
        const Parsed_Object & _parsed_object;

    public:
        explicit Type_Missmatch_Exception( const std::string &, const Parsed_Object & ) noexcept;

    public:
        [[nodiscard]] const char * what() const noexcept override;

    public:
        [[nodiscard]] const Parsed_Object & get_parsed_object() const noexcept;

}; // class Type_Missmatch_Exception <- Exception
