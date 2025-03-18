//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <log.h>

#define LEXER_DEBUG(...) \
    PRINT_DEBUG( "[Lexer]\t\t", __VA_ARGS__ )
#define LEXER_WARN(...) \
    PRINT_WARN( "[Lexer]\t\t", __VA_ARGS__ )
#define LEXER_ERROR(...) \
    PRINT_ERROR( "[Lexer]\t\t", __VA_ARGS__ )
#define LEXER_INFO(...) \
    PRINT_INFO( "[Lexer]\t\t", __VA_ARGS__ )

#define LEXER_BEGIN "Starting Lexer"
#define LEXER_END "Lexer Terminated"
#define LEXER_OPEN_FILE "Attempting to open file:"
#define LEXER_FILE_OPEN "File opened successfully"
#define LEXER_START_SCAN "Starting to read file"
#define LEXER_END_SCAN "File read terminated successfully"

#define LEXER_NO_FILE "Tokenizer Failed to open file:"
#define LEXER_FILE_READ_FAIL "File read terminated unexpectedly"

#define LEXER_THROW "\tException thrown here:"
#define LEXER_RETHROW "\tException rethrown here:"
#define LEXER_ERROR_CAUGHT "\tException caught here:"
