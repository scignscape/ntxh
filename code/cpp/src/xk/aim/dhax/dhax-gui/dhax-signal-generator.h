
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

// template<typename A1, typename A2, typename A3>
// void self_connect(A1 a1, A2 a2, A3 a3)
// {
//  connect(this, a1, a2, a3);
// }

 template<typename F, typename R, typename L>
 void self_connect_(F f, R r, L l)
 {
  connect(this, f, r, l);
 }

 USE_SELF_CONNECT(normal)
// USE_SELF_CONNECT(lambda)

 //void hold(QObject* obj);
 void emit_take_screenshot_requested();

Q_SIGNALS:

 void take_screenshot_requested();
};

#endif // DHAX_SIGNAL_GENERATOR__H
