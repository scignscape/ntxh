
#include "context-menu-provider.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


#include "chasm-lib/chasm/chasm-runtime.h"
#include "chasm-lib/chasm/chasm-call-package.h"

#include "chasm-lib/chasm/chasm-type-object.h"




void launch_web_site(QString place, QVariant pos, u1 flag)
{
 qDebug() << "\n\nPlace = " << place << "\n\n";
}

void launch_virtual_tour(QString place, QVariant pos, u1 flag)
{
 qDebug() << "\n\nv Place = " << place << "\n\n";
}



void test_map_places(Context_Menu_Provider* _this, QString arguments,
  QVector<Pattern_Matcher_Runtime::Action_Info>& info)
{

 static QRegularExpression rx{"[\\s.]+;[\\s.]+"};
 QStringList qsl = arguments.split(rx);

 Chasm_Runtime& csr = *_this->chasm_runtime();

 Chasm_Type_Object* QString_type = csr.get_type_object_by_name("QString");
 Chasm_Type_Object* QVariant_type = csr.get_type_object_by_name("QVariant");
 Chasm_Type_Object* u1_type = csr.get_type_object_by_name("u1");


 info = {
   {{
     {QString_type->with_rep(qsl.first()) },
     {QVariant_type->with_rep("89") },
     {u1_type->with_rep("103") },
    }, "Virtual Tour", "launch_virtual_tour"},
   {{
     {QString_type->with_rep(qsl.first()) },
     {QVariant_type->with_rep("89") },
     {u1_type->with_rep("103") },
    }, "Web Site", "launch_web_site"}
   };

 //info[0].reps.push_back()

//_this->chasm_runtime()->get_type_object_by_name("QString"), "Birmingham"

// info = {{nullptr, "_this" + qsl.first(), ""}, {nullptr, arguments, ""}};


// qDebug() << "arg1 = " << arg1;
// qDebug() << "arg2 = " << arg2;
// qDebug() << "arg3 = " << arg3;
}


Context_Menu_Provider::Context_Menu_Provider(Pattern_Matcher_Runtime* pm_runtime)
  :  pm_runtime_(pm_runtime)
{
 chasm_runtime_ = pm_runtime_->chasm_runtime();

 pm_runtime_->procedure_name_resolutions().insert("test_map_places",
   "test_map_places@70930");

 pm_runtime_->registered_procedures().insert("test_map_places@70930",
   {70930, (minimal_fn_s0_re8_type) &test_map_places});


 pm_runtime_->procedure_name_resolutions().insert("launch_web_site",
   "launch_web_site@70371");

 pm_runtime_->registered_procedures().insert("launch_web_site@70371",
   {70371, (minimal_fn_s0_re8_type) &launch_web_site});


 pm_runtime_->procedure_name_resolutions().insert("launch_virtual_tour",
   "launch_virtual_tour@70371");

 pm_runtime_->registered_procedures().insert("launch_virtual_tour@70371",
   {70371, (minimal_fn_s0_re8_type) &launch_virtual_tour});

}

void Context_Menu_Provider::check_url(
  QString procedure, QString arguments,
  QVector<Pattern_Matcher_Runtime::Action_Info>& info)
{
 {
  auto it = pm_runtime_->procedure_name_resolutions().find(procedure);
  if(it != pm_runtime_->procedure_name_resolutions().end())
    procedure = it.value();
 }

 auto it = pm_runtime_->registered_procedures().find(procedure);

 if(it == pm_runtime_->registered_procedures().end())
   return;

 const QPair<u4, minimal_fn_s0_re8_type>& pr = it.value();


 u4 pcode = pr.first;
 minimal_fn_s0_re8_type proc = pr.second;

 Chasm_Call_Package* ccp = chasm_runtime_->new_call_package();
 ccp->add_new_channel("lambda");

//// QString a1 = qsl.takeFirst();
//// u4 a2 = qsl.takeFirst().toUInt();
//// u1 a3 = qsl.takeFirst().toUInt();

 Context_Menu_Provider* _this = this;

 Chasm_Carrier cc1 = chasm_runtime_->gen_carrier<void*>(&_this);
 Chasm_Carrier cc2 = chasm_runtime_->gen_carrier<QString>(&arguments);
 Chasm_Carrier cc3 = chasm_runtime_->gen_carrier<n8&>(&info);

 ccp->add_carriers({cc1,cc2,cc3});

 chasm_runtime_->evaluate(ccp, pcode, //(minimal_fn_s0_re8_type)
                          proc);
}


void Context_Menu_Provider::run_callback(Pattern_Matcher_Runtime::Action_Info ai)
{
 QString procedure = ai.action_procedure;
 {
  auto it = pm_runtime_->procedure_name_resolutions().find(procedure);
  if(it != pm_runtime_->procedure_name_resolutions().end())
    procedure = it.value();
 }

 auto it = pm_runtime_->registered_procedures().find(procedure);

 if(it == pm_runtime_->registered_procedures().end())
   return;


 const QPair<u4, minimal_fn_s0_re8_type>& pr = it.value();


 u4 pcode = pr.first;
 minimal_fn_s0_re0_type proc = (minimal_fn_s0_re0_type) pr.second;

 Chasm_Call_Package* ccp = chasm_runtime_->new_call_package();
 ccp->add_new_channel("lambda");

 Chasm_Carrier cc1 = chasm_runtime_->gen_carrier(ai.reps[0]);
 Chasm_Carrier cc2 = chasm_runtime_->gen_carrier(ai.reps[1]);
 Chasm_Carrier cc3 = chasm_runtime_->gen_carrier(ai.reps[2]);

 ccp->add_carriers({cc1,cc2,cc3});

 chasm_runtime_->evaluate(ccp, pcode, proc); //proc);
}


