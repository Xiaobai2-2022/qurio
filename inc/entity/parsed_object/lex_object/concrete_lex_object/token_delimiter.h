//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include "token.h"

class Token_Delimiter final : public Token {

    private:
        QURIO_Delimiter _value;

    public:
        Token_Delimiter( const unsigned long &, const unsigned long &,
            const QURIO_Delimiter & ) noexcept;
        ~Token_Delimiter() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Delimiter & ) noexcept;

}; // class Token_Delimiter <- Concrete
