//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include "parsed_lex_object.h"

class Parsed_Lex_Keyword final : public Parsed_Lex_Object {

    private:
        QURIO_Keywords _value;

    public:
        Parsed_Lex_Keyword( const unsigned long &, const unsigned long &,
            const Parsed_Lex_Type &, const QURIO_Keywords & );
        ~Parsed_Lex_Keyword() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;
        void set_value( const std::any & ) override;

    friend std::ostream & operator<<( std::ostream &, const Parsed_Lex_Keyword & ) noexcept;

}; // class Parsed_Lex_Keyword <- Concrete
