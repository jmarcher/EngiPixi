#ifndef ENGIPIXI_LOGGER_H
#define ENGIPIXI_LOGGER_H
#ifdef __DEBUG

#include <iostream>

// Used for log entries will be disabled on release, so can be used
// without any problems
#define LOG(x) std::cout << "Log: "<< x << " (on " __FILE__ ":" << __LINE__<< ")" << std::endl
#define LOG_IF(x,condition) ([x](){if(condition){LOG(x);}})()

#else
#define LOG(x)
#define LOG_IF(x,c)

#endif
#endif //ENGIPIXI_LOGGER_H
