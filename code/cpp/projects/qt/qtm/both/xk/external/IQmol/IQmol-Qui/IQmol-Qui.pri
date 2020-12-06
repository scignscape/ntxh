
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += opengl xml sql


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/openbabel.pri)


INCLUDEPATH += $$SRC_GROUP_DIR/openbabel/include/
INCLUDEPATH += $$SRC_GROUP_DIR/openbabel/include-config/


UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Process/Process
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser



HEADERS += \
  $$SRC_DIR/Qui/AdcTab.h \
  $$SRC_DIR/Qui/AimdTab.h \
  $$SRC_DIR/Qui/AttenuationParameterTab.h \
  $$SRC_DIR/Qui/AuxiliaryBasisTab.h \
  $$SRC_DIR/Qui/CisTab.h \
  $$SRC_DIR/Qui/EomTab.h \
  $$SRC_DIR/Qui/FrequenciesTab.h \
  $$SRC_DIR/Qui/GeometryConstraint.h \
  $$SRC_DIR/Qui/InputDialog.h \
  $$SRC_DIR/Qui/OptionDatabaseForm.h \
  $$SRC_DIR/Qui/OptionEditors.h \
  $$SRC_DIR/Qui/PrimaryBasisTab.h \
  $$SRC_DIR/Qui/PropertiesTab.h \
  $$SRC_DIR/Qui/QtNode.h \
  $$SRC_DIR/Qui/QuiMolecule.h \
  $$SRC_DIR/Qui/ReactionPathTab.h \
  $$SRC_DIR/Qui/TransitionStateTab.h \
  $$SRC_DIR/Qui/FreezingStringTab.h \


SOURCES += \
  $$SRC_DIR/Qui/Actions.C \
  $$SRC_DIR/Qui/ExternalChargesSection.C \
  $$SRC_DIR/Qui/GeometryConstraint.C \
  $$SRC_DIR/Qui/InputDialog.C \
  $$SRC_DIR/Qui/InputDialogLogic.C \
  $$SRC_DIR/Qui/KeyValueSection.C \
  $$SRC_DIR/Qui/KeywordSection.C \
  $$SRC_DIR/Qui/LJParametersSection.C \
  $$SRC_DIR/Qui/MoleculeSection.C \
  $$SRC_DIR/Qui/Option.C \
  $$SRC_DIR/Qui/OptionDatabase.C \
  $$SRC_DIR/Qui/OptionDatabaseForm.C \
  $$SRC_DIR/Qui/OptionEditors.C \
  $$SRC_DIR/Qui/OptSection.C \
  $$SRC_DIR/Qui/PcmSection.C \
  $$SRC_DIR/Qui/Qui.C \
  $$SRC_DIR/Qui/QuiJob.C \
  $$SRC_DIR/Qui/QuiMolecule.C \
  $$SRC_DIR/Qui/ReadInput.C \
  $$SRC_DIR/Qui/RemSection.C \


FORMS += \
  $$SRC_DIR/Qui/AdcTab.ui \
  $$SRC_DIR/Qui/AimdTab.ui \
  $$SRC_DIR/Qui/AttenuationParameterTab.ui \
  $$SRC_DIR/Qui/AuxiliaryBasisTab.ui \
  $$SRC_DIR/Qui/CisTab.ui \
  $$SRC_DIR/Qui/EomTab.ui \
  $$SRC_DIR/Qui/FreezingStringTab.ui \
  $$SRC_DIR/Qui/FrequenciesTab.ui \
  $$SRC_DIR/Qui/GeometryConstraintDialog.ui \
  $$SRC_DIR/Qui/OptionDatabaseForm.ui \
  $$SRC_DIR/Qui/OptionListEditor.ui \
  $$SRC_DIR/Qui/OptionNumberEditor.ui \
  $$SRC_DIR/Qui/PrimaryBasisTab.ui \
  $$SRC_DIR/Qui/PropertiesTab.ui \
  $$SRC_DIR/Qui/QuiMainWindow.ui \
  $$SRC_DIR/Qui/ReactionPathTab.ui \
  $$SRC_DIR/Qui/TransitionStateTab.ui \




