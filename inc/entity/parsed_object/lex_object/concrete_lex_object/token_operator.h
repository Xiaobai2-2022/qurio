//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include "token.h"

class Token_Operator final : public Token {

private:
    QURIO_Operator _value;

public:
    Token_Operator( const unsigned long &, const unsigned long &,
        const QURIO_Operator & ) noexcept;
    ~Token_Operator() noexcept override = default;

public:
    [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Operator & ) noexcept;

}; // class Token_Operator <- Concrete
