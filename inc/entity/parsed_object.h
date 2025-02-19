//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

#include <iostream>

#include "../debug_level.h"

#include "../util/log.h"

class Parsed_Object {

    private:
        unsigned long _row;
        unsigned long _col;

    public:
        Parsed_Object( unsigned long, unsigned long );
        virtual ~Parsed_Object();

    public:
        unsigned long get_row() const;
        unsigned long get_col() const;
        void set_row( const unsigned long & );
        void set_col( const unsigned long & );

    public:
        void print() const;

    friend std::ostream & operator<<( std::ostream &, const Parsed_Object & );

}; // class Parsed_Object
