//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

#include <iostream>

#include "debug_level.h"
#include "util/log.h"

class Parsed_Object {

    private:
        unsigned long _row;
        unsigned long _col;

    public:
        Parsed_Object( const unsigned long &, const unsigned long & ) noexcept;
        virtual ~Parsed_Object() noexcept = default;

    public:
        unsigned long get_row() const noexcept;
        unsigned long get_col() const noexcept;
        void set_row( const unsigned long & ) noexcept;
        void set_col( const unsigned long & ) noexcept;

    friend std::ostream & operator<<( std::ostream &, const Parsed_Object & ) noexcept;

}; // class Parsed_Object <- Abstract
