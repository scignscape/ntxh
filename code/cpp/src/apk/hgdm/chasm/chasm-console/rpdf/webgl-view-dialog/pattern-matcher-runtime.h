
#ifndef PATTERN_MATCHER_RUNTIME__H
#define PATTERN_MATCHER_RUNTIME__H


#include <QVector>
#include <QMap>
#include <QString>

#include "accessors.h"

#include "global-types.h"

#include "./dev/consoles/fns/s0/a3/run-s0_3_re8.cpp"

#include "chasm-lib/chasm/chasm-runtime.h"

#include "url-or-event-pattern.h"

class Chasm_Call_Package;
class Chasm_Type_Object;

class Chasm_Runtime;

class Context_Menu_Provider;

class Pattern_Matcher_Runtime
{
 QVector<URL_Or_Event_Pattern*> url_patterns_;

 Chasm_Runtime* chasm_runtime_;

 QMap<QString, QString> procedure_name_resolutions_;

 QMap<QString, QPair<u4, minimal_fn_s0_re8_type>> registered_procedures_;

 Context_Menu_Provider* context_menu_provider_;

public:

 Pattern_Matcher_Runtime();

 ACCESSORS__RGET(QVector<URL_Or_Event_Pattern*> ,url_patterns)

 ACCESSORS__RGET(MACRO_PASTE(QMap<QString, QString>) ,procedure_name_resolutions)

 ACCESSORS__RGET(MACRO_PASTE(QMap<QString, QPair<u4, minimal_fn_s0_re8_type>>) ,registered_procedures)


 ACCESSORS(Chasm_Runtime* ,chasm_runtime)
 ACCESSORS(Context_Menu_Provider* ,context_menu_provider)


 struct Action_Info
 {
  //Chasm_Call_Package* ccp;
  QVector<Chasm_Typed_Value_Representation> reps;
  QString option_label;
  QString action_procedure;
 };

 URL_Or_Event_Pattern* add_url_pattern(QString context, QString sec, QString pattern,
   QString procedure, QString arguments);

 URL_Or_Event_Pattern* add_url_pattern();

// void check_url(QString procedure, QString arguments,
//   QVector<Action_Info>& info);

 void check_url_patterns(URL_Or_Event_Pattern::Pattern_Contexts context,
   QString url, QVector<Action_Info>& info,
   QString secondary = {});

// void run_callback(Action_Info ai);

};


#endif // PATTERN_MATCHER_RUNTIME__H
