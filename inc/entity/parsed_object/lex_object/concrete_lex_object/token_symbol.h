//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include "token.h"

class Token_Symbol final : public Token {

private:
    QURIO_Symbol _value;

public:
    Token_Symbol( const unsigned long &, const unsigned long &,
        const Parsed_Lex_Type &, const QURIO_Symbol & ) noexcept;
    ~Token_Symbol() noexcept override = default;

public:
    [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Symbol & ) noexcept;

}; // class Token_Symbol <- Concrete
