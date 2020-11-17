LIB = Network
CONFIG += lib
include(../common.pri)

INCLUDEPATH += ../Util

SOURCES = \
   $$PWD/Connection.C \
   $$PWD/HttpConnection.C \
   $$PWD/HttpReply.C \
   $$PWD/LocalConnection.C \
   $$PWD/LocalReply.C \
   $$PWD/Network.C \
   $$PWD/SshConnection.C \
   $$PWD/SshReply.C \

HEADERS = \
   $$PWD/Connection.h \
   $$PWD/HttpConnection.h \
   $$PWD/HttpReply.h \
   $$PWD/LocalConnection.h \
   $$PWD/LocalReply.h \
   $$PWD/Network.h \
   $$PWD/Reply.h \
   $$PWD/SshConnection.h \
   $$PWD/SshReply.h \
