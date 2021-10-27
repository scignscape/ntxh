
#include "workflow-signal-generator.h"


Workflow_Signal_Generator::Workflow_Signal_Generator()
  :  held_object_(nullptr)
{

}


void Workflow_Signal_Generator::hold(QObject* obj)
{
 held_object_ = obj;
}


void Workflow_Signal_Generator::emit_held_object_released()
{
 Q_EMIT held_object_released(held_object_);
}

