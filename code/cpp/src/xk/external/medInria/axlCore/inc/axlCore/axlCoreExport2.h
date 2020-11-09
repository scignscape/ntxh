
#ifndef AXLCORE_EXPORT_H
#define AXLCORE_EXPORT_H

#ifdef AXLCORE_STATIC_DEFINE
#  define AXLCORE_EXPORT
#  define AXLCORE_NO_EXPORT
#else
#  ifndef AXLCORE_EXPORT
#    ifdef axlCore_EXPORTS
        /* We are building this library */
#      define AXLCORE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define AXLCORE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef AXLCORE_NO_EXPORT
#    define AXLCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef AXLCORE_DEPRECATED
#  define AXLCORE_DEPRECATED __attribute__ ((__deprecated__))
#  define AXLCORE_DEPRECATED_EXPORT AXLCORE_EXPORT __attribute__ ((__deprecated__))
#  define AXLCORE_DEPRECATED_NO_EXPORT AXLCORE_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define AXLCORE_NO_DEPRECATED
#endif

#endif
