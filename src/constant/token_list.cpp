//
// Created by xiaobai2-2025 on 2/23/25.
//

#include "token_list.h"

std::unordered_set< char > Token_List::symbol_list = {

    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')',
    '-',
    '+',
    '=',
    '[',
    ']',
    '{',
    '}',
    '\\',
    '|',
    ';',
    ':',
    '\'',
    '\"',
    ',',
    '.',
    '<',
    '>',
    '/',
    '?',
    '`',
    '~',

};

std::unordered_map< char, QURIO_Delimiter > Token_List::delimiter_list = {

    { '{', DELIMITER_LBRACE },
    { '}', DELIMITER_RBRACE },
    { '[', DELIMITER_LSQRBR },
    { ']', DELIMITER_RSQRBR },
    { '(', DELIMITER_LPAREN },
    { ')', DELIMITER_RPAREN },

    { ',', DELIMITER_COMMA },
    { ';', DELIMITER_SEMICOLON },

};

std::unordered_map< std::string, QURIO_Operator > Token_List::operator_list = {

    { "+", OPERATOR_ARTH_ADDITION },
    { "-", OPERATOR_ARTH_SUBTRACTION },
    { "*", OPERATOR_ARTH_MULTIPLICATION },
    { "/", OPERATOR_ARTH_DIVISION },
    { "%", OPERATOR_ARTH_MODULUS },
    { "**", OPERATOR_ARTH_POWER },

    { "<", OPERATOR_COMP_LESSER },
    { "<=", OPERATOR_COMP_LESSEREQ },
    { "==", OPERATOR_COMP_EQUAL },
    { "!=", OPERATOR_COMP_NOTEQUAL },
    { ">=", OPERATOR_COMP_GREATEREQ },
    { ">", OPERATOR_COMP_GREATER },

    { "&&", OPERATOR_LOGICAL_AND },
    { "||", OPERATOR_LOGICAL_OR },
    { "!", OPERATOR_LOGICAL_NOT },

    { "&", OPERATOR_BITWISE_AND },
    { "|", OPERATOR_BITWISE_OR },
    { "^", OPERATOR_BITWISE_XOR },
    { "~", OPERATOR_BITWISE_NOT },

    { "<<", OPERATOR_BITWISE_LSHIFT },
    { ">>", OPERATOR_BITWISE_RSHIFT },

    { "=", OPERATOR_ASSIGNMENT },

    { "+=", OPERATOR_ASSN_ADDITION },
    { "-=", OPERATOR_ASSN_SUBTRACTION },
    { "*=", OPERATOR_ASSN_MULTIPLICATION },
    { "/=", OPERATOR_ASSN_DIVISION },
    { "%=", OPERATOR_ASSN_MODULUS },
    { "**=", OPERATOR_ASSN_POWER },

    { "&=", OPERATOR_ASSN_BITWISE_AND },
    { "|=", OPERATOR_ASSN_BITWISE_OR },
    { "^=", OPERATOR_ASSN_BITWISE_XOR },
    { "~=", OPERATOR_ASSN_BITWISE_NOT },
    { "<<=",  OPERATOR_ASSN_BITWISE_LSHIFT },
    { ">>=", OPERATOR_ASSN_BITWISE_RSHIFT },

    { "++", OPERATOR_PLUS_PLUS },
    { "--", OPERATOR_MINUS_MINUS },

    { "?", OPERATOR_TERNARY_COND },
    { ":", OPERATOR_TERNARY_OR },

    { ".", OPERATOR_ACCESS },
    { "->", OPERATOR_ACCESS_PTR },

    { "\\", OPERATOR_ESCAPE },

    { "//", OPERATOR_COMMENT },
    { "/*", OPERATOR_COMMENT_LONG_OPENING },

    { "@", OPERATOR_AT },

    {"#", OPERATOR_HASH },

    { "$", OPERATOR_REGISTER },

    {"`", OPERATOR_BACKTICK },

};

std::unordered_map< std::string, QURIO_Keyword > Token_List::keyword_list = {

    { "break", KEY_CONTROL_BREAK },
    { "case", KEY_CONTROL_CASE },
    { "continue", KEY_CONTROL_CONTINUE },
    { "do", KEY_CONTROL_DO },
    { "else", KEY_CONTROL_ELSE },
    { "if", KEY_CONTROL_IF },
    { "for", KEY_CONTROL_FOR },
    { "switch", KEY_CONTROL_SWITCH },
    { "while", KEY_CONTROL_WHILE },
    { "return", KEY_CONTROL_RETURN },

    { "any", KEY_DATATYPE_ANY },
    { "boolean", KEY_DATATYPE_BOOLEAN },
    { "char", KEY_DATATYPE_CHARACTER },
    { "double", KEY_DATATYPE_DOUBLE_FLOAT },
    { "float", KEY_DATATYPE_FLOAT },
    { "int", KEY_DATATYPE_INTEGER },
    { "long", KEY_DATATYPE_LONG_INTEGER },
    { "unsigned", KEY_DATATYPE_UNSIGNED },
    { "void", KEY_DATATYPE_VOID},
    { "string", KEY_DATATYPE_STRING },

};

std::unordered_map< QURIO_Keyword, QURIO_BUILT_IN_Type > Token_List::keyword_to_built_in_type = {

    { KEY_DATATYPE_VOID, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_BOOLEAN, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_CHARACTER, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_DOUBLE_FLOAT, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_FLOAT, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_INTEGER, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_LONG_INTEGER, KEY_BUILT_IN_TYPE_VOID },
    { KEY_DATATYPE_STRING, KEY_BUILT_IN_TYPE_VOID },

};

std::unordered_set< std::string > Token_List::user_defined_type = {};
