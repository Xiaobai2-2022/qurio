//
// Created by xiaobai2-2025 on 2/21/25.
//

#pragma once

#include <log.h>

#define LEXER_DEBUG(...) \
  PRINT_DEBUG( "[Lexer]\t", __VA_ARGS__ )
#define LEXER_WARN(...) \
  PRINT_WARN( "[Lexer]\t", __VA_ARGS__ )
#define LEXER_ERROR(...) \
  PRINT_ERROR( "[Lexer]\t", __VA_ARGS__ )
#define LEXER_INFO(...) \
  PRINT_INFO( "[Lexer]\t", __VA_ARGS__ )

#define LEXER_BEGIN "\tStarting Lexer"
#define LEXER_END "\tLexer Terminated"
#define LEXER_OPEN_FILE "\tAttempting to open file:"
#define LEXER_FILE_OPEN "\tFile opened successfully"
#define LEXER_START_SCAN "\tStarting to read file"
#define LEXER_END_SCAN "\tFile read terminated successfully"

#define LEXER_NO_FILE "\tTokenizer Failed to open file:"
#define LEXER_FILE_READ_FAIL "\tFile read terminated unexpectedly"

#define LEXER_THROW "\tException thrown here:"
#define LEXER_RETHROW "\tException rethrown here:"
#define LEXER_ERROR_CAUGHT "\tException caught here:"
