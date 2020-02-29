#ifndef HELPERS_DEBUG_ASSERT
#define HELPERS_DEBUG_ASSERT

#if ASSERTIONS_ENABLED

#include <iostream>

inline void reportAssertionFailure(const char *expresion, const char *msg2, const char *file, int line) {
    std::cerr << "Assertion Failure: " << expresion << ", " << msg2 << " at " << file << ", line " << line << std::endl;
}

#if defined(__linux__) || defined(__APPLE__)

#include <signal.h>

#define debugBreak() raise(SIGTRAP);
#elif __WINDOWS__
#if __WIN32__
#define debugBreak() asm("{int 3}")
#else
#define debugBreak() asm("{int $03}")
#endif
#endif
#define ASSERT_MSG(expr, msg)    [&](){                          \
    if(expr) {                                                   \
    } else {                                                     \
        reportAssertionFailure(#expr, #msg, __FILE__, __LINE__); \
        debugBreak();                                            \
    }}()

#define ASSERT(expr) ASSERT_MSG(expr, "")

#else
// Define empty Asserts
#define ASSERT(expr)          // Nothing to do
#define ASSERT_MSG(expr, msg) // Nothing to do
#define LOG(x) // Nothing to do

#endif

#endif