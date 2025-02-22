//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <fstream>
#include <vector>

#include "token.h"

class Qurio_Lexer {

    private:
        static void get_token_helper( std::fstream &, char &, std::vector< Token * > & );

    public:
        static void tokenizer( const std::string &, std::vector< Token * > & );

};
