//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include "token.h"

class Token_Error final : public Token {

private:
    std::string _value;

public:
    Token_Error( const unsigned long &, const unsigned long &,
        const std::string &, std::string ) noexcept;
    ~Token_Error() noexcept override = default;

public:
    [[nodiscard]] std::any get_value() const noexcept override;

    friend std::ostream & operator<<( std::ostream &, const Token_Error & ) noexcept;

}; // class Token_Error <- Concrete
