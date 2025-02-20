//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

#include <iostream>

#include "debug_level.h"
#include "util/log.h"

#include "types.h"
#include "parsed_object.h"

class Parsed_Lex_Object : public Parsed_Object {

    protected:
        Parsed_Lex_Type _type;
        void * _value;

    public:
        Parsed_Lex_Object( const unsigned long &, const unsigned long &, const Parsed_Lex_Type & ) noexcept;
        virtual ~Parsed_Lex_Object() noexcept = 0;

    public:
        Parsed_Lex_Type get_type() const noexcept;
        virtual void * get_value() const noexcept = 0;
        void set_type( const Parsed_Lex_Type & ) noexcept;
        virtual void set_value( const void * ) noexcept = 0;

    friend std::ostream & operator<<( std::ostream &, const Parsed_Lex_Object & ) noexcept;

}; // class parsed_lex_object <- Abstract
