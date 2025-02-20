//
// Created by xiaobai2-2025 on 2/18/25.
//

#pragma once

#include "debug_level.h"

// Base case
void inline log_args(std::ostream & os) {
    os << std::endl;
}

void inline print_args() {
    std::cout << std::endl;
}

template <typename T, typename ... Args>
void log_args( std::ostream & os, T first, Args... args ) {
    os << first << " ";
    log_args( os, args... );
}

template <typename T, typename ... Args>
void print_args( T first, Args... args ) {
    log_args( std::cout, first, args... );
    std::cout << "\033[0m";
}

#define PRINT_DEBUG( ... )

#define PRINT_WARN( ... )

#define PRINT_ERROR( ... )

#define PRINT_INFO( ... )

#ifdef DEBUG

#undef PRINT_DEBUG

#define PRINT_DEBUG( ... ) \
std::cout << "\033[36m[DEBUG]:\t"; \
print_args( __VA_ARGS__ );

#define DEV

#endif

#ifdef DEV

#undef PRINT_WARN

#define PRINT_WARN( ... ) \
std::cout << "\033[33m[WARNING]:\t"; \
print_args( __VA_ARGS__ );

#define PROD

#endif

#ifdef PROD

#undef PRINT_ERROR
#undef PRINT_INFO

#define PRINT_ERROR( ... ) \
std::cout << "\033[31m[ERROR]:\t"; \
print_args( __VA_ARGS__ );

#define PRINT_INFO( ... ) \
std::cout << "\033[32m[INFO]:\t\t"; \
print_args( __VA_ARGS__ );

#endif

#ifdef LOGGER

#define LOG( os, ... ) \
log_args( os, __VA_ARGS__ );

#define LOG_INFO( os, ... ) \
os << "[INFO]:\t\t"; \
LOG( os, __VA_ARGS__ );

#define LOG_ERROR( os, ... ) \
os << "[ERROR]:\t"; \
LOG( os, __VA_ARGS__ );

#define LOG_WARN( os, ... ) \
os << "[WARNING]:\t"; \
LOG( os, __VA_ARGS__ );

#define LOG_DEBUG( os, ... ) \
os << "[DEBUG]:\t"; \
LOG( os, __VA_ARGS__ );

#endif
