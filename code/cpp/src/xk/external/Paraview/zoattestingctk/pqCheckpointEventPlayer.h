#ifndef __pqCheckpointEventPlayer_h
#define __pqCheckpointEventPlayer_h

// QtTesting includes
#include "pqTestUtility.h"
#include "pqWidgetEventPlayer.h"


/// This class is a checkpoint class.
/// Do no action on Object.
/// Emit checkpoint wrote in the xml, which can be catch to do test.

class pqCheckpointEventPlayer: public pqWidgetEventPlayer 
{
  Q_OBJECT

public:
  pqCheckpointEventPlayer(pqTestUtility* testUtility, QObject* p =0);
  ~pqCheckpointEventPlayer();

  bool playEvent(QObject* Object, const QString &Command, const QString &Arguments, bool &Error);

signals:
  void checkpoint(const QString&);


private:
  pqTestUtility* TestUtility;
};

#endif // __pqCheckpointEventPlayer_h
