//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <fstream>
#include <queue>

#include "token.h"

class Qurio_Lexer {

    public:
        Qurio_Lexer() = delete;

    private:
        static void get_token_helper(
            unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

        static void get_token_delimiter_helper(
            const unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

        static void get_token_number_helper(
            const unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

        static void get_token_operator_helper(
            const unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

        static void get_token_string_helper(
            const unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

        static void get_token_identifier_helper(
            const unsigned long &, unsigned long &,
            std::fstream &, char &, std::queue< Token * > & );

    public:
        static void tokenizer( const std::string &, std::queue< Token * > & );

}; // class Qurio_Lexer <- static
