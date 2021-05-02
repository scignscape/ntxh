
#ifndef CONTEXT_MENU_PROVIDER__H
#define CONTEXT_MENU_PROVIDER__H


#include <QVector>
#include <QMap>
#include <QString>

#include "accessors.h"

#include "global-types.h"

class Chasm_Call_Package;


class Context_Menu_Provider
{
 QVector<QMap<QString, QString>> url_patterns_;


public:

 Context_Menu_Provider();

 ACCESSORS__RGET(MACRO_PASTE(QVector<QMap<QString, QString>>) ,url_patterns)

 struct Action_Info
 {
  Chasm_Call_Package* ccp;
  QString option_label;
  QString action_procedure;
 };

 void check_url(QString procedure, QString arguments,
   QVector<Action_Info>& info);

 void check_url_patterns(QString url, QVector<Context_Menu_Provider::Action_Info>& info);

 void run_callback(Action_Info& ai);

};


#endif
