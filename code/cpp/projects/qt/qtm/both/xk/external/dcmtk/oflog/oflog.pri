
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include

#?
DEFINES += DCMTK_INSIDE_LOG4CPLUS


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/oflog/appender.h \
  $$SRC_DIR/include/dcmtk/oflog/asyncap.h \
  $$SRC_DIR/include/dcmtk/oflog/clfsap.h \
  $$SRC_DIR/include/dcmtk/oflog/clogger.h \
  $$SRC_DIR/include/dcmtk/oflog/config.h \
  $$SRC_DIR/include/dcmtk/oflog/configrt.h \
  $$SRC_DIR/include/dcmtk/oflog/consap.h \
  $$SRC_DIR/include/dcmtk/oflog/fileap.h \
  $$SRC_DIR/include/dcmtk/oflog/fstreams.h \
  $$SRC_DIR/include/dcmtk/oflog/hierarchy.h \
  $$SRC_DIR/include/dcmtk/oflog/hierlock.h \
  $$SRC_DIR/include/dcmtk/oflog/layout.h \
  $$SRC_DIR/include/dcmtk/oflog/log4judp.h \
  $$SRC_DIR/include/dcmtk/oflog/logger.h \
  $$SRC_DIR/include/dcmtk/oflog/loglevel.h \
  $$SRC_DIR/include/dcmtk/oflog/logmacro.h \
  $$SRC_DIR/include/dcmtk/oflog/mdc.h \
  $$SRC_DIR/include/dcmtk/oflog/ndc.h \
  $$SRC_DIR/include/dcmtk/oflog/ntelogap.h \
  $$SRC_DIR/include/dcmtk/oflog/nullap.h \
  $$SRC_DIR/include/dcmtk/oflog/oflog.h \
  $$SRC_DIR/include/dcmtk/oflog/socketap.h \
  $$SRC_DIR/include/dcmtk/oflog/streams.h \
  $$SRC_DIR/include/dcmtk/oflog/syslogap.h \
  $$SRC_DIR/include/dcmtk/oflog/tchar.h \
  $$SRC_DIR/include/dcmtk/oflog/tracelog.h \
  $$SRC_DIR/include/dcmtk/oflog/tstring.h \
  $$SRC_DIR/include/dcmtk/oflog/version.h \
  $$SRC_DIR/include/dcmtk/oflog/winconap.h \
  $$SRC_DIR/include/dcmtk/oflog/windebap.h \
  $$SRC_DIR/include/dcmtk/oflog/config/defines.h \
  $$SRC_DIR/include/dcmtk/oflog/config/macosx.h \
  $$SRC_DIR/include/dcmtk/oflog/config/win32.h \
  $$SRC_DIR/include/dcmtk/oflog/config/windowsh.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/apndimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/fileinfo.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/lloguser.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/lockfile.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/loglog.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/pointer.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/property.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/queue.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/sleep.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/snprintf.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/sockbuff.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/socket.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/strhelp.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/threadcf.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/timehelp.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/cygwin32.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/env.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/internal.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/socket.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/apndatch.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/factory.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/filter.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logevent.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logfact.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/objreg.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/rootlog.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/syncprim.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/syncpub.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/threads.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncpmsm.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncpthr.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncwin.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/thredimp.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/tls.h \


SOURCES += \
  $$SRC_DIR/apndimpl.cc \
  $$SRC_DIR/appender.cc \
  $$SRC_DIR/asyncap.cc \
  $$SRC_DIR/clfsap.cc \
  $$SRC_DIR/clogger.cc \
  $$SRC_DIR/config.cc \
  $$SRC_DIR/consap.cc \
  $$SRC_DIR/cygwin32.cc \
  $$SRC_DIR/env.cc \
  $$SRC_DIR/factory.cc \
  $$SRC_DIR/fileap.cc \
  $$SRC_DIR/fileinfo.cc \
  $$SRC_DIR/filter.cc \
  $$SRC_DIR/globinit.cc \
  $$SRC_DIR/hierarchy.cc \
  $$SRC_DIR/hierlock.cc \
  $$SRC_DIR/layout.cc \
  $$SRC_DIR/lloguser.cc \
  $$SRC_DIR/lockfile.cc \
  $$SRC_DIR/log4judp.cc \
  $$SRC_DIR/logevent.cc \
  $$SRC_DIR/logger.cc \
  $$SRC_DIR/logimpl.cc \
  $$SRC_DIR/loglevel.cc \
  $$SRC_DIR/loglog.cc \
  $$SRC_DIR/logmacro.cc \
  $$SRC_DIR/mdc.cc \
  $$SRC_DIR/ndc.cc \
  $$SRC_DIR/ntelogap.cc \
  $$SRC_DIR/nullap.cc \
  $$SRC_DIR/objreg.cc \
  $$SRC_DIR/oflog.cc \
  $$SRC_DIR/patlay.cc \
  $$SRC_DIR/pointer.cc \
  $$SRC_DIR/property.cc \
  $$SRC_DIR/queue.cc \
  $$SRC_DIR/rootlog.cc \
  $$SRC_DIR/sleep.cc \
  $$SRC_DIR/snprintf.cc \
  $$SRC_DIR/sockbuff.cc \
  $$SRC_DIR/socket.cc \
  $$SRC_DIR/socketap.cc \
  $$SRC_DIR/strccloc.cc \
  $$SRC_DIR/strcloc.cc \
  $$SRC_DIR/strhelp.cc \
  $$SRC_DIR/striconv.cc \
  $$SRC_DIR/syncprims.cc \
  $$SRC_DIR/syslogap.cc \
  $$SRC_DIR/threads.cc \
  $$SRC_DIR/timehelp.cc \
  $$SRC_DIR/tls.cc \
  $$SRC_DIR/unixsock.cc \
  $$SRC_DIR/version.cc \
  $$SRC_DIR/winconap.cc \
  $$SRC_DIR/windebap.cc \
  $$SRC_DIR/winsock.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

