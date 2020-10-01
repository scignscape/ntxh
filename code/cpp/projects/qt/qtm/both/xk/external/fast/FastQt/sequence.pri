INCLUDEPATH+=$$SRC_DIR/sequence

HEADERS += \
    $$SRC_DIR/sequence/sequence.h \
    $$SRC_DIR/sequence/abstractsequencereader.h \
    $$SRC_DIR/sequence/fastqreader.h \
    $$SRC_DIR/sequence/phredencoding.h \
    $$SRC_DIR/sequence/bamreader.h

SOURCES += \
    $$SRC_DIR/sequence/abstractsequencereader.cpp \
    $$SRC_DIR/sequence/fastqreader.cpp \
    $$SRC_DIR/sequence/phredencoding.cpp \
    $$SRC_DIR/sequence/sequence.cpp \
    $$SRC_DIR/sequence/bamreader.cpp
