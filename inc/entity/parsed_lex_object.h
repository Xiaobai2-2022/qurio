//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

#include <iostream>

#include "../debug_level.h"
#include "../util/log.h"

#include "parsed_lex_type.h"
#include "parsed_object.h"

class Parsed_Lex_Object : public Parsed_Object {

    private:
        Parsed_Lex_Type _type;
        void * value;

    public:
        Parsed_Lex_Object( unsigned long, unsigned long, Parsed_Lex_Type );
        virtual ~Parsed_Lex_Object();

    public:
        Parsed_Lex_Type get_type() const;
        virtual void * get_value() const;
        void set_type( const Parsed_Lex_Type & );
        virtual void set_value( const void * );

    public:
        virtual void print() const;

    friend std::ostream & operator<<( std::ostream &, const Parsed_Lex_Object & );

}; // class parsed_lex_object
