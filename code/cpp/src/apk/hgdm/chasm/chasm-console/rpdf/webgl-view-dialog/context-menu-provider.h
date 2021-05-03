
#ifndef CONTEXT_MENU_PROVIDER__H
#define CONTEXT_MENU_PROVIDER__H


#include <QVector>
#include <QMap>
#include <QString>

#include "accessors.h"

#include "global-types.h"

#include "./dev/consoles/fns/s0/a3/run-s0_3_re8.cpp"

#include "chasm-lib/chasm/chasm-runtime.h"

class Chasm_Call_Package;
class Chasm_Type_Object;

class Chasm_Runtime;

class Context_Menu_Provider
{
 QVector<QMap<QString, QString>> url_patterns_;

 QMap<QString, QString> procedure_name_resolutions_;

 Chasm_Runtime* chasm_runtime_;

 QMap<QString, QPair<u4, minimal_fn_s0_re8_type>> registered_procedures_;

public:

 Context_Menu_Provider();

 ACCESSORS__RGET(MACRO_PASTE(QVector<QMap<QString, QString>>) ,url_patterns)

 struct Action_Info
 {
  //Chasm_Call_Package* ccp;
  QVector<Chasm_Typed_Value_Representation> reps;
  QString option_label;
  QString action_procedure;
 };

 void check_url(QString procedure, QString arguments,
   QVector<Action_Info>& info);

 void check_url_patterns(QString url, QVector<Context_Menu_Provider::Action_Info>& info);

 void run_callback(Action_Info ai);

};


#endif
