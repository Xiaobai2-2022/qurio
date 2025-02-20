//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

enum Parsed_Lex_Type {

    DELIMITER,
    IDENTIFIER,
    KEYWORD,
    NUMBER,

}; // enum Parsed_Lex_Type

enum QURIO_Keywords {

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
    KEY_DATATYPE_NUMBER,                    // num
    KEY_DATATYPE_SHORT_INTEGER,             // short

}; // enum QURIO_Keywords

enum QURIO_Delimiters {

    DELIMITER_LBRACE,                       // {
    DELIMITER_RBRACE,                       // }
    DELIMITER_LSQRBR,                       // [
    DELIMITER_RSQRBR,                       // ]
    DELIMITER_LPAREN,                       // (
    DELIMITER_RPAREN,                       // )

    DELIMITER_SEMICOLON,                    // ;

}; // enum QURIO_Delimiters
