//
// Created by xiaobai2-2025 on 3/7/25.
//

#pragma once

#include "token.h"

class Token_Protocol final : public Token {

    private:
        QURIO_Protocol _value;

    public:
        Token_Protocol( const unsigned long &, const unsigned long &,
            const QURIO_Protocol &, std::string ) noexcept;
        ~Token_Protocol() noexcept override = default;

    public:
        [[nodiscard]] std::any get_value() const noexcept override;

    public:
        void set_protocol( const QURIO_Protocol &,  std::string ) noexcept;

    friend std::ostream & operator<<( std::ostream &, const Token_Protocol & ) noexcept;

};
