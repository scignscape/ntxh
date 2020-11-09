
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += network #gui  #opengl sql network xml testlib svg

 # should we just use ordinary QObject instead?
QT += core-private



include($$ROOT_DIR/../preferred/sysr.pri)

#? include($$ROOT_DIR/../preferred/gui.pri)





#? PRIVATE_HEADERS += \

HEADERS +=  \
  $$SRC_DIR/qjsonrpcservice_p.h \
  $$SRC_DIR/qjsonrpcsocket_p.h \
  $$SRC_DIR/qjsonrpcabstractserver_p.h \
  $$SRC_DIR/qjsonrpcservicereply_p.h


#? INSTALL_HEADERS += \

HEADERS +=  \
  $$SRC_DIR/qjsonrpcmessage.h \
  $$SRC_DIR/qjsonrpcservice.h \
  $$SRC_DIR/qjsonrpcsocket.h \
  $$SRC_DIR/qjsonrpcabstractserver.h \
  $$SRC_DIR/qjsonrpclocalserver.h \
  $$SRC_DIR/qjsonrpctcpserver.h \
  $$SRC_DIR/qjsonrpc_export.h \
  $$SRC_DIR/qjsonrpcservicereply.h \
  $$SRC_DIR/qjsonrpchttpclient.h


SOURCES += \
  $$SRC_DIR/qjsonrpcmessage.cpp \
  $$SRC_DIR/qjsonrpcservice.cpp \
  $$SRC_DIR/qjsonrpcsocket.cpp \
  $$SRC_DIR/qjsonrpcabstractserver.cpp \
  $$SRC_DIR/qjsonrpclocalserver.cpp \
  $$SRC_DIR/qjsonrpctcpserver.cpp \
  $$SRC_DIR/qjsonrpcservicereply.cpp \
  $$SRC_DIR/qjsonrpchttpclient.cpp



