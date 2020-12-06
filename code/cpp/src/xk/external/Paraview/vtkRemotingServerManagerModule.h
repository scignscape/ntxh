#ifndef VTKREMOTINGSERVERMANAGER_EXPORT_H
 #define VTKREMOTINGSERVERMANAGER_EXPORT_H
 
 #ifdef VTKREMOTINGSERVERMANAGER_STATIC_DEFINE
 #  define VTKREMOTINGSERVERMANAGER_EXPORT
 #  define VTKREMOTINGSERVERMANAGER_NO_EXPORT
 #else
 #  ifndef VTKREMOTINGSERVERMANAGER_EXPORT
 #    ifdef RemotingServerManager_EXPORTS
         /* We are building this library */
 #      define VTKREMOTINGSERVERMANAGER_EXPORT __attribute__((visibility("default")))
 #    else
         /* We are using this library */
 #      define VTKREMOTINGSERVERMANAGER_EXPORT __attribute__((visibility("default")))
 #    endif
 #  endif
 
 #  ifndef VTKREMOTINGSERVERMANAGER_NO_EXPORT
 #    define VTKREMOTINGSERVERMANAGER_NO_EXPORT __attribute__((visibility("hidden")))
 #  endif
 #endif
 
 #ifndef VTKREMOTINGSERVERMANAGER_DEPRECATED
 #  define VTKREMOTINGSERVERMANAGER_DEPRECATED __attribute__ ((__deprecated__))
 #endif
 
 #ifndef VTKREMOTINGSERVERMANAGER_DEPRECATED_EXPORT
 #  define VTKREMOTINGSERVERMANAGER_DEPRECATED_EXPORT VTKREMOTINGSERVERMANAGER_EXPORT VTKREMOTINGSERVERMANAGER_DEPRECATED
 #endif
 
 #ifndef VTKREMOTINGSERVERMANAGER_DEPRECATED_NO_EXPORT
 #  define VTKREMOTINGSERVERMANAGER_DEPRECATED_NO_EXPORT VTKREMOTINGSERVERMANAGER_NO_EXPORT VTKREMOTINGSERVERMANAGER_DEPRECATED
 #endif
 
 #if 0 /* DEFINE_NO_DEPRECATED */
 #  ifndef VTKREMOTINGSERVERMANAGER_NO_DEPRECATED
 #    define VTKREMOTINGSERVERMANAGER_NO_DEPRECATED
 #  endif
 #endif
 
 /* AutoInit implementations. */
 #ifdef vtkRemotingServerManager_AUTOINIT_INCLUDE
 #include vtkRemotingServerManager_AUTOINIT_INCLUDE
 #endif
 #ifdef vtkRemotingServerManager_AUTOINIT
 #include "vtkAutoInit.h"
 VTK_MODULE_AUTOINIT(vtkRemotingServerManager)
 #endif
 
 #endif /* VTKREMOTINGSERVERMANAGER_EXPORT_H */
