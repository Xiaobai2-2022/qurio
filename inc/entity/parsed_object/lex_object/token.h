//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

#include <any>
#include <iostream>

#include "parsed_object.h"
#include "token_enums.h"

class Token : public Parsed_Object {

    protected:
        Parsed_Lex_Type _type;

    public:
        Token( const unsigned long &, const unsigned long &, const Parsed_Lex_Type & ) noexcept;
        ~Token() noexcept override = default;

    public:
        [[nodiscard]] Parsed_Lex_Type get_type() const noexcept;
        void set_type( const Parsed_Lex_Type & ) noexcept;

    public:
        [[nodiscard]] virtual std::any get_value() const noexcept = 0;

    public:
        static void print_token( std::ostream & os, Token * );

    friend std::ostream & operator<<( std::ostream &, const Token & ) noexcept;

}; // class Token <- Abstract
