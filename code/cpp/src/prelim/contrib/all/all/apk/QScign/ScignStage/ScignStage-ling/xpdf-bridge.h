
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef XPDF_BRIDGE__H
#define XPDF_BRIDGE__H

// //  Note:  the MOC doesn't seem to follow the MACRO-based
 //    include here, but the XPDF_Bridge class is structured
 //    so this doesn't seem to matter (no functionality
 //    affected by USING_XPDF is involved in the MOC generated code ...
#include "defines.h"

#include <QObject>
#include <QPoint>
#include <QDialog>

#include "qsns.h"

class Xpdf_Component;

class XPDF_Bridge : public QObject
{
 Q_OBJECT

#ifdef USING_XPDF
 Xpdf_Component* xpdf_component_;
 int argc_;
 char** argv_;

public:

 XPDF_Bridge(int argc, char** argv);

 void init(QPoint dlg_point = QPoint(),
   QDialog* origin_dlg = nullptr, QString origin_msg = {});
 bool is_ready();
 void take_message(QString msg);

#else

public:

 void take_message(QString) {}
 bool is_ready(){ return false; }
 void init(QPoint dlg_point = QPoint(),
   QDialog* origin_dlg = nullptr, QString origin_msg = {}){}
#endif //  USING_XPDF

Q_SIGNALS:

 void xpdf_is_ready();


};


#endif  //XPDF_BRIDGE__H