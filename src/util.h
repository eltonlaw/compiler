#ifndef util_h
#define util_h

enum bool {false, true};

#define LOGGING_LEVEL 1
#define LOGGER_COUT stderr /* [stdout, stderr] */

#ifdef LOGGING_LEVEL
 #if LOGGING_LEVEL > 0
   #define LOGGER_DEBUG(fmt, args...) fprintf(LOGGER_COUT, "DEBUG: %s:%d:%s(): " fmt, \
           __FILE__, __LINE__, __func__, ##args)
 #else
  #define LOGGER_DEBUG(fmt, args...)
 #endif

 #if LOGGING_LEVEL > 1
   #define LOGGER_INFO(fmt, args...) fprintf(LOGGER_COUT, "INFO: %s:%d:%s(): " fmt, \
           __FILE__, __LINE__, __func__, ##args)
 #else
  #define LOGGER_INFO(fmt, args...)
 #endif

 #if LOGGING_LEVEL > 2
   #define LOGGER_WARNING(fmt, args...) fprintf(LOGGER_COUT, "WARNING: %s:%d:%s(): " fmt, \
           __FILE__, __LINE__, __func__, ##args)
 #else
  #define LOGGER_WARNING(fmt, args...)
 #endif

 #if LOGGING_LEVEL > 3
   #define LOGGER_ERROR(fmt, args...) fprintf(LOGGER_COUT, "ERROR: %s:%d:%s(): " fmt, \
           __FILE__, __LINE__, __func__, ##args)
 #else
  #define LOGGER_ERROR(fmt, args...)
 #endif

 #if LOGGING_LEVEL > 4
   #define LOGGER_CRITICAL(fmt, args...) fprintf(LOGGER_COUT, "CRITICAL: %s:%d:%s(): " fmt, \
           __FILE__, __LINE__, __func__, ##args)
 #else
  #define LOGGER_CRITICAL(fmt, args...)
 #endif

#endif /* #ifdef LOGGING_LEVEL */
#endif /* #ifndef util_h */
