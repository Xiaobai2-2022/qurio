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

#define SYNTAX_ERROR_MISSING "Syntax error, missing token"
#define SYNTAX_ERROR_UNEXPECTED "Syntax error, unexpected token"

#define COMPILE_TIME_ERROR( row, col )\
    ("Compile Time Error At " + std::to_string( row ) \
    + ", " + std::to_string( col ) + ".")


