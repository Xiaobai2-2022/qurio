//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include "token.h"

class Token_Keyword final : public Token {

    private:
        QURIO_Keyword _value;

    public:
        Token_Keyword( const unsigned long &, const unsigned long &,
            const QURIO_Keyword &, std::string ) noexcept;
        ~Token_Keyword() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Keyword & ) noexcept;

}; // class Token_Keyword <- Concrete
