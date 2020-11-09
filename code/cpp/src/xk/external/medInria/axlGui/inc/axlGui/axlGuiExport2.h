
#ifndef AXLGUI_EXPORT_H
#define AXLGUI_EXPORT_H

#ifdef AXLGUI_STATIC_DEFINE
#  define AXLGUI_EXPORT
#  define AXLGUI_NO_EXPORT
#else
#  ifndef AXLGUI_EXPORT
#    ifdef axlGui_EXPORTS
        /* We are building this library */
#      define AXLGUI_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define AXLGUI_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef AXLGUI_NO_EXPORT
#    define AXLGUI_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef AXLGUI_DEPRECATED
#  define AXLGUI_DEPRECATED __attribute__ ((__deprecated__))
#  define AXLGUI_DEPRECATED_EXPORT AXLGUI_EXPORT __attribute__ ((__deprecated__))
#  define AXLGUI_DEPRECATED_NO_EXPORT AXLGUI_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define AXLGUI_NO_DEPRECATED
#endif

#endif
