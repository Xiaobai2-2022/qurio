//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

enum Parsed_Lex_Type {

    DELIMITER,
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    SYMBOL,
    STRING,

}; // enum Parsed_Lex_Type

enum QURIO_Keyword {

    // control structures
    KEY_CONTROL_BREAK,                      // break
    KEY_CONTROL_CASE,                       // case
    KEY_CONTROL_CONTINUE,                   // continue
    KEY_CONTROL_DO,                         // do
    KEY_CONTROL_ELSE,                       // else
    KEY_CONTROL_IF,                         // if
    KEY_CONTROL_FOR,                        // for
    KEY_CONTROL_SWITCH,                     // switch
    KEY_CONTROL_WHILE,                      // while

    // datatypes
    KEY_DATATYPE_ANY,                       // any
    KEY_DATATYPE_BOOLEAN,                   // boolean
    KEY_DATATYPE_CHARACTER,                 // char
    KEY_DATATYPE_DOUBLE_FLOAT,              // double
    KEY_DATATYPE_FLOAT,                     // float
    KEY_DATATYPE_INTEGER,                   // int
    KEY_DATATYPE_LONG_INTEGER,              // long
    KEY_DATATYPE_UNSIGNED_DOUBLE_FLOAT,     // unsigned double
    KEY_DATATYPE_UNSIGNED_FLOAT,            // unsigned float
    KEY_DATATYPE_UNSIGNED_INTEGER,          // unsigned int
    KEY_DATATYPE_UNSIGNED_LONG_INTEGER,     // unsigned long

}; // enum QURIO_Keyword

enum QURIO_Delimiter {

    DELIMITER_LBRACE,                       // {
    DELIMITER_RBRACE,                       // }
    DELIMITER_LSQRBR,                       // [
    DELIMITER_RSQRBR,                       // ]
    DELIMITER_LPAREN,                       // (
    DELIMITER_RPAREN,                       // )

    DELIMITER_COMMA,                        // ,
    DELIMITER_SEMICOLON,                    // ;

}; // enum QURIO_Delimiter

enum QURIO_Symbol {

    SYMBOL_ARTH_ADDITION,                   // +
    SYMBOL_ARTH_SUBTRACTION,                // -
    SYMBOL_ARTH_MULTIPLICATION,             // *
    SYMBOL_ARTH_DIVISION,                   // /
    SYMBOL_ARTH_MODULUS,                    // %
    SYMBOL_ARTH_POWER,                      // **

    SYMBOL_PLUS_PLUS,                       // ++
    SYMBOL_MINUS_MINUS,                     // --

    SYMBOL_ASSIGNMENT,                      // =

    SYMBOL_COMP_LESSER,                     // <
    SYMBOL_COMP_LESSEREQ,                   // <=
    SYMBOL_COMP_EQUAL,                      // ==
    SYMBOL_COMP_NOTEQUAL,                   // !=
    SYMBOL_COMP_GREATEREQ,                  // >=
    SYMBOL_COMP_GREATER,                    // >

    SYMBOL_LOGICAL_AND,                     // &&
    SYMBOL_LOGICAL_OR,                      // ||
    SYMBOL_LOGICAL_NOT,                     // !

    SYMBOL_BITWISE_AND,                     // &
    SYMBOL_BITWISE_OR,                      // |
    SYMBOL_BITWISE_XOR,                     // ^
    SYMBOL_BITWISE_NOT,                     // ~

    SYMBOL_BITWISE_LSHIFT,                  // <<
    SYMBOL_BITWISE_RSHIFT,                  // >>

    SYMBOL_ASSN_ADDITION,                   // +=
    SYMBOL_ASSN_SUBTRACTION,                // -=
    SYMBOL_ASSN_MULTIPLICATION,             // *=
    SYMBOL_ASSN_DIVISION,                   // /=
    SYMBOL_ASSN_MODULUS,                    // %=
    SYMBOL_ASSN_POWER,                      // **=

    SYMBOL_ASSN_BITWISE_AND,                // &=
    SYMBOL_ASSN_BITWISE_OR,                 // |=
    SYMBOL_ASSN_BITWISE_XOR,                // ^=
    SYMBOL_ASSN_BITWISE_NOT,                // ~=
    SYMBOL_ASSN_BITWISE_LSHIFT,             // <<=
    SYMBOL_ASSN_BITWISE_RSHIFT,             // >>=

    SYMBOL_TERNARY_COND,                    // ?
    SYMBOL_TERNARY_OR,                      // :

    SYMBOL_ACCESS,                          // .
    SYMBOL_ACCESS_PTR,                      // ->

}; // enum QURIO_Symbol
