
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += network  widgets  


include($$ROOT_DIR/../preferred/sysr.pri)

#include($$ROOT_DIR/../preferred/boost.pri)
#include($$ROOT_DIR/../preferred/openbabel.pri)

include($$ROOT_DIR/../preferred/libssh2.pri)


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser



INCLUDEPATH += $$SRC_GROUP_DIR/OpenMesh-Core


HEADERS += \


SOURCES += \
  $$SRC_DIR/Network/Connection.C \
  $$SRC_DIR/Network/HttpConnection.C \
  $$SRC_DIR/Network/HttpReply.C \
  $$SRC_DIR/Network/LocalConnection.C \
  $$SRC_DIR/Network/LocalReply.C \
  $$SRC_DIR/Network/Network.C \
  $$SRC_DIR/Network/SshConnection.C \
  $$SRC_DIR/Network/SshReply.C \



