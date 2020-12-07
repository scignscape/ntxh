#ifndef __pqEventCheckpoint_h
#define __pqEventCheckpoint_h

// Qt includes
#include <QObject>
#include <QString>
// QtTesting includes
#include "pqTestUtility.h"
#include "QtTestingExport.h"
#include "pqEventComment.h"


/// pqEventCheckpoint is responsible for adding checkpoint
 class pqEventCheckpoint : public pqEventComment
 {
  Q_OBJECT
  public:
  pqEventCheckpoint(pqTestUtility* testUtility, QObject* p =0);
  
  ~pqEventCheckpoint();
  /// Call this function to add an event checkpoint, which will display a message,during the playback in the log.
  void recordCheckpoint(const QString& arguments);
  signals:
  /// All functions should emit this signal whenever they wish to add a checkpoint
  void recordCheckpoint(QObject* widget, const QString& type, const QString& arguments);

  protected:
  void recordCheckpoint(const QString& command,
                     const QString& arguments,
                     QObject* = 0);

  pqTestUtility* TestUtility;
 };
#endif
