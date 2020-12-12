#ifndef VTKRENDERINGPARALLEL_EXPORT_H
 #define VTKRENDERINGPARALLEL_EXPORT_H
 
 #ifdef VTKRENDERINGPARALLEL_STATIC_DEFINE
 #  define VTKRENDERINGPARALLEL_EXPORT
 #  define VTKRENDERINGPARALLEL_NO_EXPORT
 #else
 #  ifndef VTKRENDERINGPARALLEL_EXPORT
 #    ifdef RenderingParallel_EXPORTS
         /* We are building this library */
 #      define VTKRENDERINGPARALLEL_EXPORT __attribute__((visibility("default")))
 #    else
         /* We are using this library */
 #      define VTKRENDERINGPARALLEL_EXPORT __attribute__((visibility("default")))
 #    endif
 #  endif
 
 #  ifndef VTKRENDERINGPARALLEL_NO_EXPORT
 #    define VTKRENDERINGPARALLEL_NO_EXPORT __attribute__((visibility("hidden")))
 #  endif
 #endif
 
 #ifndef VTKRENDERINGPARALLEL_DEPRECATED
 #  define VTKRENDERINGPARALLEL_DEPRECATED __attribute__ ((__deprecated__))
 #endif
 
 #ifndef VTKRENDERINGPARALLEL_DEPRECATED_EXPORT
 #  define VTKRENDERINGPARALLEL_DEPRECATED_EXPORT VTKRENDERINGPARALLEL_EXPORT VTKRENDERINGPARALLEL_DEPRECATED
 #endif
 
 #ifndef VTKRENDERINGPARALLEL_DEPRECATED_NO_EXPORT
 #  define VTKRENDERINGPARALLEL_DEPRECATED_NO_EXPORT VTKRENDERINGPARALLEL_NO_EXPORT VTKRENDERINGPARALLEL_DEPRECATED
 #endif
 
 #if 0 /* DEFINE_NO_DEPRECATED */
 #  ifndef VTKRENDERINGPARALLEL_NO_DEPRECATED
 #    define VTKRENDERINGPARALLEL_NO_DEPRECATED
 #  endif
 #endif
 
 #endif /* VTKRENDERINGPARALLEL_EXPORT_H */