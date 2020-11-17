
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += xml opengl network


include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)
include($$ROOT_DIR/../preferred/libssh2.pri)

UI_DIR = $$SRC_DIR/uis-gen/any-build


INCLUDEPATH += $$SRC_GROUP_DIR  \


INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Util/Util
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Data/Data
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Parser/Parser
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Network/Network
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Layer/Layer
INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Configurator/Configurator

INCLUDEPATH += $$SRC_GROUP_DIR/IQmol-Old/Old \
  $$SRC_GROUP_DIR/IQmol-Old/extras


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk/yaml-cpp/include



HEADERS += \
  $$SRC_DIR/Process/QueueResourcesDialog.h \
  $$SRC_DIR/Process/Job.h \
  $$SRC_DIR/Process/JobMonitor.h \
  $$SRC_DIR/Process/QueueOptionsDialog.h \
  $$SRC_DIR/Process/Server.h \
  $$SRC_DIR/Process/ServerConfigurationDialog.h \
  $$SRC_DIR/Process/ServerConfigurationListDialog.h \
  $$SRC_DIR/Process/SshFileDialog.h \



SOURCES += \
  \# $$SRC_DIR/Process/getpids.C  -- this is windows only ...
  $$SRC_DIR/Process/Job.C \
  $$SRC_DIR/Process/JobInfo.C \
  $$SRC_DIR/Process/JobMonitor.C \
  $$SRC_DIR/Process/QChemJobInfo.C \
  $$SRC_DIR/Process/QueueOptionsDialog.C \
  $$SRC_DIR/Process/QueueResources.C \
  $$SRC_DIR/Process/QueueResourcesDialog.C \
  $$SRC_DIR/Process/QueueResourcesList.C \
  $$SRC_DIR/Process/Server.C \
  $$SRC_DIR/Process/ServerConfiguration.C \
  $$SRC_DIR/Process/ServerConfigurationDialog.C \
  $$SRC_DIR/Process/ServerConfigurationListDialog.C \
  $$SRC_DIR/Process/ServerRegistry.C \
  $$SRC_DIR/Process/SshFileDialog.C \
  $$SRC_DIR/Process/SystemDependent.C \


FORMS += \
  $$SRC_DIR/Process/JobMonitor.ui \
  $$SRC_DIR/Process/QueueOptionsDialog.ui \
  $$SRC_DIR/Process/QueueResourcesDialog.ui \
  $$SRC_DIR/Process/ServerConfigurationDialog.ui \
  $$SRC_DIR/Process/ServerConfigurationListDialog.ui \
  $$SRC_DIR/Process/SshFileDialog.ui \

