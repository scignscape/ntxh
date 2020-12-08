#ifndef VTKPVVTKEXTENSIONSPOINTS_EXPORT_H
 #define VTKPVVTKEXTENSIONSPOINTS_EXPORT_H
 
 #ifdef VTKPVVTKEXTENSIONSPOINTS_STATIC_DEFINE
 #  define VTKPVVTKEXTENSIONSPOINTS_EXPORT
 #  define VTKPVVTKEXTENSIONSPOINTS_NO_EXPORT
 #else
 #  ifndef VTKPVVTKEXTENSIONSPOINTS_EXPORT
 #    ifdef VTKExtensionsPoints_EXPORTS
         /* We are building this library */
 #      define VTKPVVTKEXTENSIONSPOINTS_EXPORT __attribute__((visibility("default")))
 #    else
         /* We are using this library */
 #      define VTKPVVTKEXTENSIONSPOINTS_EXPORT __attribute__((visibility("default")))
 #    endif
 #  endif
 
 #  ifndef VTKPVVTKEXTENSIONSPOINTS_NO_EXPORT
 #    define VTKPVVTKEXTENSIONSPOINTS_NO_EXPORT __attribute__((visibility("hidden")))
 #  endif
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSPOINTS_DEPRECATED
 #  define VTKPVVTKEXTENSIONSPOINTS_DEPRECATED __attribute__ ((__deprecated__))
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSPOINTS_DEPRECATED_EXPORT
 #  define VTKPVVTKEXTENSIONSPOINTS_DEPRECATED_EXPORT VTKPVVTKEXTENSIONSPOINTS_EXPORT VTKPVVTKEXTENSIONSPOINTS_DEPRECATED
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSPOINTS_DEPRECATED_NO_EXPORT
 #  define VTKPVVTKEXTENSIONSPOINTS_DEPRECATED_NO_EXPORT VTKPVVTKEXTENSIONSPOINTS_NO_EXPORT VTKPVVTKEXTENSIONSPOINTS_DEPRECATED
 #endif
 
 #if 0 /* DEFINE_NO_DEPRECATED */
 #  ifndef VTKPVVTKEXTENSIONSPOINTS_NO_DEPRECATED
 #    define VTKPVVTKEXTENSIONSPOINTS_NO_DEPRECATED
 #  endif
 #endif
 
 #endif /* VTKPVVTKEXTENSIONSPOINTS_EXPORT_H */
