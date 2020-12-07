#ifndef VTKREMOTINGEXPORT_EXPORT_H
 #define VTKREMOTINGEXPORT_EXPORT_H
 
 #ifdef VTKREMOTINGEXPORT_STATIC_DEFINE
 #  define VTKREMOTINGEXPORT_EXPORT
 #  define VTKREMOTINGEXPORT_NO_EXPORT
 #else
 #  ifndef VTKREMOTINGEXPORT_EXPORT
 #    ifdef RemotingExport_EXPORTS
         /* We are building this library */
 #      define VTKREMOTINGEXPORT_EXPORT __attribute__((visibility("default")))
 #    else
         /* We are using this library */
 #      define VTKREMOTINGEXPORT_EXPORT __attribute__((visibility("default")))
 #    endif
 #  endif
 
 #  ifndef VTKREMOTINGEXPORT_NO_EXPORT
 #    define VTKREMOTINGEXPORT_NO_EXPORT __attribute__((visibility("hidden")))
 #  endif
 #endif
 
 #ifndef VTKREMOTINGEXPORT_DEPRECATED
 #  define VTKREMOTINGEXPORT_DEPRECATED __attribute__ ((__deprecated__))
 #endif
 
 #ifndef VTKREMOTINGEXPORT_DEPRECATED_EXPORT
 #  define VTKREMOTINGEXPORT_DEPRECATED_EXPORT VTKREMOTINGEXPORT_EXPORT VTKREMOTINGEXPORT_DEPRECATED
 #endif
 
 #ifndef VTKREMOTINGEXPORT_DEPRECATED_NO_EXPORT
 #  define VTKREMOTINGEXPORT_DEPRECATED_NO_EXPORT VTKREMOTINGEXPORT_NO_EXPORT VTKREMOTINGEXPORT_DEPRECATED
 #endif
 
 #if 0 /* DEFINE_NO_DEPRECATED */
 #  ifndef VTKREMOTINGEXPORT_NO_DEPRECATED
 #    define VTKREMOTINGEXPORT_NO_DEPRECATED
 #  endif
 #endif
 
 #endif /* VTKREMOTINGEXPORT_EXPORT_H */
