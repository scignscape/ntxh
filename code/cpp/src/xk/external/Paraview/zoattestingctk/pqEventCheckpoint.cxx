// Qt includes
#include <QDebug>

// QtTesting includes
#include "pqEventCheckpoint.h"
// ----------------------------------------------------------------------------
pqEventCheckpoint::pqEventCheckpoint(pqTestUtility* util,
                               QObject* parents)
  : pqEventComment(util,parents)
{
  this->TestUtility = util;
}

// ----------------------------------------------------------------------------
pqEventCheckpoint::~pqEventCheckpoint()
{
  this->TestUtility = 0;
}
// ----------------------------------------------------------------------------
void pqEventCheckpoint::recordCheckpoint(const QString& arguments)
  {
   this->recordCheckpoint(QString("checkpoint"), arguments);
  }

void pqEventCheckpoint::recordCheckpoint(const QString& command,
                                   const QString& arguments,
                                   QObject* object)
{
  if (arguments.isEmpty())
    {
    qCritical() << "The checkpoint is empty ! No checkpoint has been added !";
    return;
    }

  emit this->recordCheckpoint(object, command, arguments);
}
