//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include "token.h"

class Token_Identifier final : public Token {

private:
    std::string _value;

public:
    Token_Identifier( const unsigned long &, const unsigned long &,
        const std::string & ) noexcept;
    ~Token_Identifier() noexcept override = default;

public:
    [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Identifier & ) noexcept;

}; // class Token_Identifier <- Concrete
