
INCLUDEPATH+=$$SRC_DIR/analysis

HEADERS += \
    $$SRC_DIR/analysis/analysis.h \
    $$SRC_DIR/analysis/analysisrunner.h \
    $$SRC_DIR/analysis/basicstatsanalysis.h \
    $$SRC_DIR/analysis/perbasequalityanalysis.h \
    $$SRC_DIR/analysis/persequencequalityanalysis.h \
    $$SRC_DIR/analysis/perbasecontentanalysis.h \
    $$SRC_DIR/analysis/overrepresentedseqsanalysis.h \
    $$SRC_DIR/analysis/perbasencontentanalysis.h \
    $$SRC_DIR/analysis/persequencegccontent.h \
    $$SRC_DIR/analysis/lengthdistributionanalysis.h

SOURCES += \
    $$SRC_DIR/analysis/analysis.cpp \
    $$SRC_DIR/analysis/analysisrunner.cpp \
    $$SRC_DIR/analysis/basicstatsanalysis.cpp \
    $$SRC_DIR/analysis/perbasequalityanalysis.cpp \
    $$SRC_DIR/analysis/persequencequalityanalysis.cpp \
    $$SRC_DIR/analysis/perbasecontentanalysis.cpp \
    $$SRC_DIR/analysis/overrepresentedseqsanalysis.cpp \
    $$SRC_DIR/analysis/perbasencontentanalysis.cpp \
    $$SRC_DIR/analysis/persequencegccontent.cpp \
    $$SRC_DIR/analysis/lengthdistributionanalysis.cpp
