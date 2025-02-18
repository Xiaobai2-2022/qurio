//
// Created by xiaobai2-2025 on 2/18/25.
//

#ifndef LOG_H
#define LOG_H

// Base case
void inline print_args() {
    std::cout << "\033[0m" << std::endl;
}

template <typename T, typename ... Args>
void print_args(T first, Args... args) {
    std::cout << first << " ";
    print_args(args...);
}

#ifdef DEBUG

#define LOG_DEBUG( ... ) \
std::cout << "\033[36m[DEBUG]:\t"; \
print_args(__VA_ARGS__);

#define LOG_WARN( ... ) \
std::cout << "\033[31m[WARNING]:\t"; \
print_args(__VA_ARGS__);

#define LOG_ERROR( ... ) \
std::cout << "\033[33m[ERROR]:\t"; \
print_args(__VA_ARGS__);

#define LOG_INFO( ... ) \
std::cout << "\033[32m[INFO]:\t\t"; \
print_args(__VA_ARGS__);

#endif

#ifdef DEV

#define LOG_DEBUG( ... )

#define LOG_WARN( ... ) \
std::cout << "\033[31m[WARNING]:\t"; \
print_args(__VA_ARGS__);

#define LOG_ERROR( ... ) \
std::cout << "\033[33m[ERROR]:\t"; \
print_args(__VA_ARGS__);

#define LOG_INFO( ... ) \
std::cout << "\033[32m[INFO]:\t\t"; \
print_args(__VA_ARGS__);

#endif


#ifdef PROD

#define LOG_DEBUG( ... )

#define LOG_WARN( ... )

#define LOG_ERROR( ... ) \
std::cout << "\033[33m[ERROR]:\t"; \
print_args(__VA_ARGS__);

#define LOG_INFO( ... ) \
std::cout << "\033[32m[INFO]:\t\t"; \
print_args(__VA_ARGS__);

#endif

#endif // LOG_H
