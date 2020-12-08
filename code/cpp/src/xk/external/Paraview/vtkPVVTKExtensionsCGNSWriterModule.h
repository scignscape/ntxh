 #ifndef VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT_H
 #define VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT_H
 
 #ifdef VTKPVVTKEXTENSIONSCGNSWRITER_STATIC_DEFINE
 #  define VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT
 #  define VTKPVVTKEXTENSIONSCGNSWRITER_NO_EXPORT
 #else
 #  ifndef VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT
 #    ifdef VTKExtensionsCGNSWriter_EXPORTS
         /* We are building this library */
 #      define VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT __attribute__((visibility("default")))
 #    else
         /* We are using this library */
 #      define VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT __attribute__((visibility("default")))
 #    endif
 #  endif
 
 #  ifndef VTKPVVTKEXTENSIONSCGNSWRITER_NO_EXPORT
 #    define VTKPVVTKEXTENSIONSCGNSWRITER_NO_EXPORT __attribute__((visibility("hidden")))
 #  endif
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED
 #  define VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED __attribute__ ((__deprecated__))
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED_EXPORT
 #  define VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED_EXPORT VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED
 #endif
 
 #ifndef VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED_NO_EXPORT
 #  define VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED_NO_EXPORT VTKPVVTKEXTENSIONSCGNSWRITER_NO_EXPORT VTKPVVTKEXTENSIONSCGNSWRITER_DEPRECATED
 #endif
 
 #if 0 /* DEFINE_NO_DEPRECATED */
 #  ifndef VTKPVVTKEXTENSIONSCGNSWRITER_NO_DEPRECATED
 #    define VTKPVVTKEXTENSIONSCGNSWRITER_NO_DEPRECATED
 #  endif
 #endif
 
 #endif /* VTKPVVTKEXTENSIONSCGNSWRITER_EXPORT_H */
