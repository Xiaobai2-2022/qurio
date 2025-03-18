//
// Created by xiaobai2-2025 on 3/10/25.
//

#pragma once

#include <string>

#include "log.h"

#define PARSER_DEBUG(...) \
    PRINT_DEBUG( "[Parser]\t", __VA_ARGS__ )
#define PARSER_WARN(...) \
    PRINT_WARN( "[Parser]\t", __VA_ARGS__ )
#define PARSER_ERROR(...) \
    PRINT_ERROR( "[Parser]\t", __VA_ARGS__ )
#define PARSER_INFO(...) \
    PRINT_INFO( "[Parser]\t", __VA_ARGS__ )

#define PARSER_BEGIN "Starting Parser"
#define PARSER_END "Parser Terminated"

#define TREE_GEN "Parser Tree Generated"

#define SCAN_TYPE "Reading a type at"
#define SCAN_IDENTIFIER "Reading an identifier at"

#define SYNTAX_ERROR_MISSING "Syntax error, missing token"
#define SYNTAX_ERROR_UNEXPECTED( token, row, col )\
    ("Syntax error, unexpected token: \"" + token + "\" at { "\
    + std::to_string( row ) + ", " + std::to_string( col ) + " }.")
#define SYNTAX_ERROR_REDEFINE( token, row, col, org_row, org_col )\
    ("Syntax error, redefined identifier: \"" + token + "\" at { "\
    + std::to_string( row ) + ", " + std::to_string( col ) + " }, first defined at { "\
    + std::to_string( org_row ) + ", " + std::to_string( org_col ) + " }")



