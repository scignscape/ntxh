LIB = Process
CONFIG += lib
include(../common.pri)

INCLUDEPATH += ../Util ../Yaml ../Data  ../Parser ../Network ../Layer ../Configurator

SOURCES = \
   $$PWD/Job.C \
   $$PWD/JobInfo.C \
   $$PWD/JobMonitor.C \
   $$PWD/QChemJobInfo.C \
   $$PWD/QueueOptionsDialog.C \
   $$PWD/QueueResources.C \
   $$PWD/QueueResourcesDialog.C \
   $$PWD/QueueResourcesList.C \
   $$PWD/Server.C \
   $$PWD/ServerConfiguration.C \
   $$PWD/ServerConfigurationDialog.C \
   $$PWD/ServerConfigurationListDialog.C \
   $$PWD/ServerRegistry.C \
   $$PWD/SshFileDialog.C \
   $$PWD/SystemDependent.C \

HEADERS = \
   $$PWD/Job.h \
   $$PWD/JobInfo.h \
   $$PWD/JobMonitor.h \
   $$PWD/QChemJobInfo.h \
   $$PWD/QueueOptionsDialog.h \
   $$PWD/QueueResources.h \
   $$PWD/QueueResourcesDialog.h \
   $$PWD/QueueResourcesList.h \
   $$PWD/Server.h \
   $$PWD/ServerConfiguration.h \
   $$PWD/ServerConfigurationDialog.h \
   $$PWD/ServerConfigurationListDialog.h \
   $$PWD/ServerRegistry.h \
   $$PWD/SshFileDialog.h \
   $$PWD/SystemDependent.h \

FORMS = \
   $$PWD/JobMonitor.ui \
   $$PWD/QueueOptionsDialog.ui \
   $$PWD/QueueResourcesDialog.ui \
   $$PWD/ServerConfigurationDialog.ui \
   $$PWD/ServerConfigurationListDialog.ui \
   $$PWD/SshFileDialog.ui \

win32:SOURCES += $$PWD/getpids.C
