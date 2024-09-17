/***************************************************************************//**
 * Enable debugging.
 ******************************************************************************/
#ifndef DEBUG_H
#define DEBUG_H

#define LOG_LEVEL_DEBUG   0
#define LOG_LEVEL_INFO    1
#define LOG_LEVEL_WARN    2
#define LOG_LEVEL_ERROR   3

#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif

/***************************************************************************//**
 * Print log function for debugging.
 ******************************************************************************/
#define NUMARGS(...)  (sizeof((const char*[]){__VA_ARGS__}) / sizeof(const char*))
#define PRINT_LOG(msg) printf(msg)
#define PRINT_MULTI_ARG(msg, log_level, ...) \
{\
  if(!NUMARGS(__VA_ARGS__)) printf(msg); \
  else { \
      printf(msg, __VA_ARGS__); \
  } \
}

#endif
