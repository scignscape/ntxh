
#ifndef DHAX_SIGNAL_GENERATOR__H
#define DHAX_SIGNAL_GENERATOR__H

#include <QObject>

#include <QVariant>

#include "accessors.h"
#include "global-types.h"



class DHAX_Signal_Generator : public QObject
{
 Q_OBJECT

 //QObject* held_object_;

public:

 DHAX_Signal_Generator();


 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)


 //void hold(QObject* obj);
 void emit_take_screenshot_requested();

Q_SIGNALS:

 void take_screenshot_requested();
};

#endif // DHAX_SIGNAL_GENERATOR__H
