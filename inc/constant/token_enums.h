//
// Created by xiaobai2-2025 on 2/19/25.
//

#pragma once

enum Parsed_Lex_Type {

    ERROR_TYPE,

    DELIMITER,
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    OPERATOR,
    STRING,
    CHAR,

    PROTOCOL,

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
    KEY_CONTROL_RETURN,                     // return

    // datatypes
    KEY_DATATYPE_ANY,                       // any
    KEY_DATATYPE_BOOLEAN,                   // boolean
    KEY_DATATYPE_CHARACTER,                 // char
    KEY_DATATYPE_DOUBLE_FLOAT,              // double
    KEY_DATATYPE_FLOAT,                     // float
    KEY_DATATYPE_INTEGER,                   // int
    KEY_DATATYPE_LONG_INTEGER,              // long
    KEY_DATATYPE_UNSIGNED,                  // unsigned

    KEY_DATATYPE_VOID,                      // void
    KEY_DATATYPE_STRING,                    // string

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

enum QURIO_Operator {

    OPERATOR_ARTH_ADDITION,                     // +
    OPERATOR_ARTH_SUBTRACTION,                  // -
    OPERATOR_ARTH_MULTIPLICATION,               // *
    OPERATOR_ARTH_DIVISION,                     // /
    OPERATOR_ARTH_MODULUS,                      // %
    OPERATOR_ARTH_POWER,                        // **

    OPERATOR_PLUS_PLUS,                         // ++
    OPERATOR_MINUS_MINUS,                       // --

    OPERATOR_ASSIGNMENT,                        // =

    OPERATOR_COMP_LESSER,                       // <
    OPERATOR_COMP_LESSEREQ,                     // <=
    OPERATOR_COMP_EQUAL,                        // ==
    OPERATOR_COMP_NOTEQUAL,                     // !=
    OPERATOR_COMP_GREATEREQ,                    // >=
    OPERATOR_COMP_GREATER,                      // >

    OPERATOR_LOGICAL_AND,                       // &&
    OPERATOR_LOGICAL_OR,                        // ||
    OPERATOR_LOGICAL_NOT,                       // !

    OPERATOR_BITWISE_AND,                       // &
    OPERATOR_BITWISE_OR,                        // |
    OPERATOR_BITWISE_XOR,                       // ^
    OPERATOR_BITWISE_NOT,                       // ~

    OPERATOR_BITWISE_LSHIFT,                    // <<
    OPERATOR_BITWISE_RSHIFT,                    // >>

    OPERATOR_ASSN_ADDITION,                     // +=
    OPERATOR_ASSN_SUBTRACTION,                  // -=
    OPERATOR_ASSN_MULTIPLICATION,               // *=
    OPERATOR_ASSN_DIVISION,                     // /=
    OPERATOR_ASSN_MODULUS,                      // %=
    OPERATOR_ASSN_POWER,                        // **=

    OPERATOR_ASSN_BITWISE_AND,                  // &=
    OPERATOR_ASSN_BITWISE_OR,                   // |=
    OPERATOR_ASSN_BITWISE_XOR,                  // ^=
    OPERATOR_ASSN_BITWISE_NOT,                  // ~=
    OPERATOR_ASSN_BITWISE_LSHIFT,               // <<=
    OPERATOR_ASSN_BITWISE_RSHIFT,               // >>=

    OPERATOR_TERNARY_COND,                      // ?
    OPERATOR_TERNARY_OR,                        // :

    OPERATOR_ACCESS,                            // .
    OPERATOR_ACCESS_PTR,                        // ->

    OPERATOR_ESCAPE,                            // \

    OPERATOR_COMMENT,                           // //
    OPERATOR_COMMENT_LONG_OPENING,              // /*
    // OPERATOR_COMMENT_LONG_CLOSING,              // */

    OPERATOR_AT,                                // @
    OPERATOR_HASH,                              // #
    OPERATOR_REGISTER,                          // $
    OPERATOR_BACKTICK,                          // `

}; // enum QURIO_Symbol

enum QURIO_Protocol {

    // No operation
    NOP,

    // Program
    PROGRAM,

    // Scope
    SCOPE,

    // Function
    FUNCTION,
    RETURN_TYPE,
    FUNCTION_NAME,
    ARGUMENT,

    // Expression
    EXPRS,
    EXPR,
    EXPR_INLINE,

    CONDITIONS,

    // if else
    IF,
    ELSE,

    // while
    WHILE,

    // do while
    DO,

    // for
    FOR,
    PRE_OPERATION,
    POST_OPERATION,

    // switch case
    SWITCH,
    SWITCH_IDENTIFIER,
    CASE,
    CASE_VALUE,
    DEFAULT,

}; // enum QURIO_Protocol
