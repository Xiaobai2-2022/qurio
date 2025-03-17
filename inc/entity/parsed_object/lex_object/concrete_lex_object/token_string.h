//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include "token.h"

class Token_String final : public Token {

private:
    std::string _value;

public:
    Token_String( const unsigned long &, const unsigned long &,
        const Parsed_Lex_Type &, const std::string &, std::string ) noexcept;
    ~Token_String() noexcept override = default;

public:
    [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_String & ) noexcept;

}; // class Token_String <- Concrete
