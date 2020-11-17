# CONFIG += debug exceptions rtti
CONFIG += release exceptions rtti
CONFIG += DEPLOY


contains(CONFIG, DEVELOP) {

   #INCLUDEPATH += C:\Qt\5.8\mingw53_32\include
   #INCLUDEPATH += C:\Qt\Tools\mingw530_32\include
   INCLUDEPATH += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\include
   INCLUDEPATH += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\include\c++\i686-w64-mingw32

   # Boost
   BOOST        = D:\Boost\1.58.0
   INCLUDEPATH += $${BOOST}
   LIBS        += $${BOOST}\stage\lib\libboost_serialization-mgw53-mt-1_58.a
   LIBS        += $${BOOST}\stage\lib\libboost_iostreams-mgw53-mt-1_58.a

   # gfortran
   LIBS += C:\MinGW\lib\gcc\mingw32\5.3.0\libgfortran.a
   LIBS += C:\MinGW\lib\gcc\mingw32\5.3.0\libquadmath.a
   LIBS += C:\MinGW\lib\libmingwex.a

   # OpenBabel
   OPENBABEL    = D:\OpenBabel\2.4.1
   INCLUDEPATH += $${OPENBABEL}\include
   INCLUDEPATH += $${OPENBABEL}\build\include
   LIBS        += $${OPENBABEL}\build\src\libopenbabel.a

   # SSH2 / OpenSSL
   INCLUDEPATH += C:\MinGW\msys\1.0\local\include
   LIBS        += C:\MinGW\msys\1.0\local\lib\libssh2.a
   LIBS        += C:\MinGW\msys\1.0\local\lib\libssl.a
   LIBS        += C:\MinGW\msys\1.0\local\lib\libcrypto.a
   LIBS        += C:\MinGW\lib\libgdi32.a
   #LIBS        += -LC:\MinGW\msys\1.0\local\lib
   #LIBS        += -LC:\MinGW\msys\1.0\local\bin
   #LIBS        += -lssh2 -lssl -lcrypto -lgdi32
   
   # QGLViewer
   QGLVIEWER    = D:\QGLViewer\2.6.4\QGLViewer
   #INCLUDEPATH += $${QGLVIEWER}
   LIBS        += $${QGLVIEWER}\libQGLViewer2.a

   #LIBS += -lws2_32 -lOpenGL32 
   LIBS        += C:\MinGW\lib\libws2_32.a
   LIBS        += C:\MinGW\lib\libopengl32.a
   LIBS        += C:\MinGW\lib\libglu32.a
   LIBS        += C:\MinGW\lib\libz.a

   ICON     = D:\IQmol\src\Main\resources\IQmol.ico
   RC_FILE += D:\IQmol\src\Main\resources\windows.rc

   # Qt make recognize .C as C file and use CC as the default compiler
   # Override CFLAGS with CXXFLAGS options
   QMAKE_CFLAGS = $$QMAKE_CXXFLAGS
   QMAKE_CFLAGS += -std=gnu++11 -frtti -fexceptions -mthreads
}


contains(CONFIG, DEPLOY) {
   DEV = C:\Users\agilbert\Development

   #CONFIG += debug exceptions rtti
   CONFIG += release exceptions rtti

   # Boost
   BOOST        = $${DEV}\boost_1_59_0
   INCLUDEPATH += $${BOOST}
   LIBS        += $${BOOST}\stage\lib\libboost_serialization-mgw53-mt-1_59.a
   LIBS        += $${BOOST}\stage\lib\libboost_iostreams-mgw53-mt-1_59.a

   # gfortran
   LIBS += C:\MinGW\lib\gcc\mingw32\4.8.1\libgfortran.a

   # OpenBabel
   OPENBABEL    = $${DEV}\openbabel-2.4.1
   INCLUDEPATH += $${OPENBABEL}\include
   INCLUDEPATH += $${OPENBABEL}\build\include
   LIBS        += $${OPENBABEL}\build\src\libopenbabel.a

   # OpenMesh
   OPENMESH     = $${DEV}\OpenMesh-4.1
   LIBS        += $${OPENMESH}\build\Build\lib\libOpenMeshCored.a
   LIBS        += $${OPENMESH}\build\Build\lib\libOpenMeshToolsd.a

   # SSH2
   INCLUDEPATH += $${DEV}\openssl-1.1.1f\include
   INCLUDEPATH += C:\MinGW\msys\1.0\local\include
   LIBS        += C:\MinGW\msys\1.0\local\lib\libssh2.a
   LIBS        += C:\MinGW\msys\1.0\local\lib\libssl.a
   LIBS        += C:\MinGW\msys\1.0\local\lib\libcrypto.a
   #LIBS        += $${DEV}\openssl-1.1.1f\lib\libssl.a
   #LIBS        += $${DEV}\openssl-1.1.1f\lib\libcrypto.a
   LIBS        += C:\MinGW\lib\libgdi32.a
   
   #LIBS += -lws2_32 -lOpenGL32 
   LIBS        += C:\MinGW\lib\libws2_32.a
   LIBS        += C:\MinGW\lib\libopengl32.a
   LIBS        += C:\MinGW\lib\libglu32.a
   LIBS        += C:\MinGW\lib\libz.a

   ICON     = $${DEV}\IQmol\src\Main\resources\IQmol.ico
   RC_FILE += $${DEV}\IQmol\src\Main\resources\windows.rc

   # Qt make recognize .C as C file and use CC as the default compiler
   # Override CFLAGS with CXXFLAGS options
   QMAKE_CXXFLAGS += -std=gnu++11 -frtti -fexceptions -mthreads
   QMAKE_CFLAGS    = $$QMAKE_CXXFLAGS
}
