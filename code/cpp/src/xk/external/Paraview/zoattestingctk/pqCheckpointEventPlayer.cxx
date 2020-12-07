
#include "pqCheckpointEventPlayer.h"

// ----------------------------------------------------------------------------
pqCheckpointEventPlayer::pqCheckpointEventPlayer(pqTestUtility* testUtility,
                                           QObject* parent)
  :pqWidgetEventPlayer(parent)
{
  this->TestUtility = testUtility;
}

// ----------------------------------------------------------------------------
pqCheckpointEventPlayer::~pqCheckpointEventPlayer()
{
  this->TestUtility = 0;
}

// ----------------------------------------------------------------------------
bool pqCheckpointEventPlayer::playEvent(QObject* Object,
                                     const QString &Command,
                                     const QString &Arguments,
                                     bool &Error)
{
  if (!Command.startsWith("checkpoint"))
    {
    return false;
    }

  if (!Arguments.isEmpty())
    {
    emit this->checkpoint(Arguments);
    }
  return true;
}
