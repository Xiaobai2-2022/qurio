//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include "parsed_lex_object.h"

class Parsed_Lex_Number final : public Parsed_Lex_Object {

    private:
        std::string _value;

    public:
        Parsed_Lex_Number( const unsigned long &, const unsigned long &,
            const Parsed_Lex_Type &, const std::string & );
        ~Parsed_Lex_Number() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;
        void set_value( const std::any & ) override;

        friend std::ostream & operator<<( std::ostream &, const Parsed_Lex_Number & ) noexcept;

}; // class Parsed_Lex_Number <- Concrete
