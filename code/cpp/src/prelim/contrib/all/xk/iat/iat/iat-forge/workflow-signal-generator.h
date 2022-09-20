
#ifndef WORKFLOW_SIGNAL_GENERATOR__H
#define WORKFLOW_SIGNAL_GENERATOR__H

#include <QObject>

#include <QVariant>

#include "accessors.h"
#include "global-types.h"


class Workflow_Signal_Generator : public QObject
{
 Q_OBJECT

 QObject* held_object_;

public:

 Workflow_Signal_Generator();

 void hold(QObject* obj);
 void emit_held_object_released();

Q_SIGNALS:

 void input_value_changed(QString,QVariant);
 void held_object_released(QObject*);

};

#endif // WORKFLOW_SIGNAL_GENERATOR__H
