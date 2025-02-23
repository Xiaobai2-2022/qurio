//
// Created by xiaobai2-2025 on 2/20/25.
//

#pragma once

#include "token.h"

class Token_Number final : public Token {

    private:
        std::string _value;

    public:
        Token_Number( const unsigned long &, const unsigned long &,
            const std::string & );
        ~Token_Number() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;
        // void set_value( const std::any & ) override;

        friend std::ostream & operator<<( std::ostream &, const Token_Number & ) noexcept;

}; // class Token_Number <- Concrete
