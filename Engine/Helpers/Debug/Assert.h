#ifndef HELPERS_DEBUG_ASSERT
#define HELPERS_DEBUG_ASSERT

#if ASSERTIONS_ENABLED
#include <iostream>
#include <signal.h>

inline void reportAssertionFailure(const char *msg1, const char * msg2, const char* file, int line)
{
    std::cerr << "Assertion Failure: " << msg1 << ", " << msg2 << " at " << file << ", line " << line << std::endl;
}
#define debugBreak() raise(SIGTRAP);
#define ASSERT_MSG(expr, msg) \
    if(expr) {}\
    else {\
    reportAssertionFailure(#expr, #msg,__FILE__,__LINE__);\
    debugBreak();\
    }
#define ASSERT(expr) ASSERT_MSG(expr, "")
#else
#define ASSERT(expr) //Nothing to do
#define ASSERT_MSG(expr,msg) //Nothing to do

#endif

#endif