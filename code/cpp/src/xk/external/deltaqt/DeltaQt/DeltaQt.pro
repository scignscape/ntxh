#-------------------------------------------------
#
# Project created by QtCreator 2012-01-05T08:23:30
#
#-------------------------------------------------

QT       -= gui

TARGET = DeltaQt
TEMPLATE = lib
CONFIG += staticlib

SOURCES += deltaqt.cpp \
    deltavaluerange.cpp \
    deltaparserprivate.cpp \
    deltaparserphase2.cpp \
    deltaparser.cpp \
    deltaitem.cpp \
    deltadirectives.cpp \
    deltadataset.cpp \
    deltacharactertype.cpp \
    deltacharacter.cpp \
    deltaattribute.cpp \
    delimitedbuffer.cpp \
    annotatedvalue.cpp \
    functions.cpp \
    parselog.cpp \
    deltaimplicitvalue.cpp \
    deltadependentchars.cpp \
    datavalidation.cpp \
    rtfprocessing.cpp

HEADERS += deltaqt.h \
    globals.h \
    deltavaluerange.h \
    deltasymbols.h \
    DeltaQt_global.h \
    deltaparserprivate.h \
    deltaparserphase2.h \
    deltaparser.h \
    deltaitem.h \
    deltadirectives.h \
    deltadataset.h \
    deltacharactertype.h \
    deltacharacter.h \
    deltaattribute.h \
    delimitedbuffer.h \
    annotatedvalue.h \
    functions.h \
    logmsgid.h \
    parselog.h \
    deltaimplicitvalue.h \
    deltadependentchars.h \
    filenameandmeta.h \
    datavalidation.h \
    rtfprocessing.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES +=




























