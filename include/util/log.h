//
// Created by xiaobai2-2025 on 2/18/25.
//

#ifndef LOG_H
#define LOG_H

// Base case
void inline print_args(){}

template <typename T, typename ... Args>
void print_args(T first, Args... args) {
    std::cout << first << " ";
    print_args(args...);
}

#if defined(DEBUG)

#define LOG_DEBUG( ... ) \
std::cout << "[DEBUG]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_WARN( ... ) \
std::cout << "[WARNING]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_ERROR( ... ) \
std::cout << "[ERROR]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_INFO( ... ) \
std::cout << "[INFO]:\t\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#elif defined(DEV)

#define LOG_DEBUG( ... )

#define LOG_WARN( ... ) \
std::cout << "[WARNING]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_ERROR( ... ) \
std::cout << "[ERROR]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_INFO( ... ) \
std::cout << "[INFO]:\t\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;


#elif defined(PROD)

#define LOG_DEBUG( ... )

#define LOG_WARN( ... )

#define LOG_ERROR( ... ) \
std::cout << "[ERROR]:\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#define LOG_INFO( ... ) \
std::cout << "[INFO]:\t\t"; \
print_args(__VA_ARGS__); \
std::cout << std::endl;

#endif

#endif // LOG_H
