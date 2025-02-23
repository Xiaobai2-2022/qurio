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
    '=',
    '[',
    ']',
    '{',
    '}',
    '\\',
    '|',
    ';',
    ':',
    '\"',
    // '\'',    // Skipped due to this is allowed in number
    ',',
    // '.',     // Skipped due to this is allowed in number
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