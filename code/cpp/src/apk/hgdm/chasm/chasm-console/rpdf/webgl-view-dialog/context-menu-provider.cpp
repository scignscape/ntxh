
#include "context-menu-provider.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


#include "chasm-lib/chasm/chasm-runtime.h"
#include "chasm-lib/chasm/chasm-call-package.h"

#include "chasm-lib/chasm/chasm-type-object.h"




void launch_web_site(QString place, QVariant pos, u1 flag)
{
 qDebug() << "Place = " << place;
}

void launch_virtual_tour(QString place, QVariant pos, u1 flag)
{
 qDebug() << "v Place = " << place;
}



void test_map_places(Context_Menu_Provider* _this, QString arguments,
  QVector<Context_Menu_Provider::Action_Info>& info)
{

 static QRegularExpression rx{"[\\s.]+;[\\s.]+"};
 QStringList qsl = arguments.split(rx);

 Chasm_Runtime& csr = *_this->chasm_runtime();

 Chasm_Type_Object* QString_type = csr.get_type_object_by_name("QString");
 Chasm_Type_Object* QVariant_type = csr.get_type_object_by_name("QVariant");
 Chasm_Type_Object* u1_type = csr.get_type_object_by_name("u1");


 info = {{{
     {QString_type->with_rep(qsl.first()) },
     {QVariant_type->with_rep("89") },
     {u1_type->with_rep("103") },

   }, "Virtual Tour", "launch_virtual_tour"},
   {{}, "Web Site", "launch_web_site"}
   };

 //info[0].reps.push_back()

//_this->chasm_runtime()->get_type_object_by_name("QString"), "Birmingham"

// info = {{nullptr, "_this" + qsl.first(), ""}, {nullptr, arguments, ""}};


// qDebug() << "arg1 = " << arg1;
// qDebug() << "arg2 = " << arg2;
// qDebug() << "arg3 = " << arg3;
}


Context_Menu_Provider::Context_Menu_Provider()
{
 chasm_runtime_ = new Chasm_Runtime;
 chasm_runtime_->init_no_file_session();

 Chasm_Call_Package* ccp = chasm_runtime_->new_call_package();
 ccp->add_new_channel("lambda");

// QString a1 = "place";
// QVariant a2 = QVariant::fromValue(77);
// u1 a3 = 78;

// Chasm_Carrier cc1 = chasm_runtime_->gen_carrier<QString>(&a1);
// Chasm_Carrier cc2 = chasm_runtime_->gen_carrier<QVariant>(&a2);
// Chasm_Carrier cc3 = chasm_runtime_->gen_carrier<u1>(&a3);

// ccp->add_carriers({cc1,cc2,cc3});

// chasm_runtime_->evaluate(ccp, 70371,  &launch_virtual_tour); //proc);



 // 76341, (minimal_fn_s0_re6_type) &testqs6n,

 procedure_name_resolutions_.insert("test_map_places",
   "test_map_places@70930");

 registered_procedures_.insert("test_map_places@70930",
   {70930, (minimal_fn_s0_re8_type) &test_map_places});


 procedure_name_resolutions_.insert("launch_web_site",
   "launch_web_site@70371");

 registered_procedures_.insert("launch_web_site@70371",
   {70371, (minimal_fn_s0_re8_type) &launch_web_site});


 procedure_name_resolutions_.insert("launch_virtual_tour",
   "launch_virtual_tour@70371");

 registered_procedures_.insert("launch_virtual_tour@70371",
   {70371, (minimal_fn_s0_re8_type) &launch_virtual_tour});

}

void Context_Menu_Provider::check_url(QString procedure, QString arguments,
  QVector<Action_Info>& info)
{
 {
  auto it = procedure_name_resolutions_.find(procedure);
  if(it != procedure_name_resolutions_.end())
    procedure = it.value();
 }

 auto it = registered_procedures_.find(procedure);

 if(it == registered_procedures_.end())
   return;


 const QPair<u4, minimal_fn_s0_re8_type>& pr = it.value();


 u4 pcode = pr.first;
 minimal_fn_s0_re8_type proc = pr.second;

 Chasm_Call_Package* ccp = chasm_runtime_->new_call_package();
 ccp->add_new_channel("lambda");

// QString a1 = qsl.takeFirst();
// u4 a2 = qsl.takeFirst().toUInt();
// u1 a3 = qsl.takeFirst().toUInt();

 Context_Menu_Provider* _this = this;

 Chasm_Carrier cc1 = chasm_runtime_->gen_carrier<void*>(&_this);
 Chasm_Carrier cc2 = chasm_runtime_->gen_carrier<QString>(&arguments);
 Chasm_Carrier cc3 = chasm_runtime_->gen_carrier<n8&>(&info);

 ccp->add_carriers({cc1,cc2,cc3});

// ccp->add_new_channel("result");
// Chasm_Carrier cc0 = csr->gen_carrier<r8>(csr->Result._r8);
// ccp->add_carrier(cc0);

 chasm_runtime_->evaluate(ccp, pcode, //(minimal_fn_s0_re8_type)
                          proc);


 //info = {{nullptr, procedure, ""}, {nullptr, arguments, ""}};
 // //return nullptr;
}


void Context_Menu_Provider::run_callback(Action_Info ai)
{
 QString procedure = ai.action_procedure;
 {
  auto it = procedure_name_resolutions_.find(procedure);
  if(it != procedure_name_resolutions_.end())
    procedure = it.value();
 }

 auto it = registered_procedures_.find(procedure);

 if(it == registered_procedures_.end())
   return;


 const QPair<u4, minimal_fn_s0_re8_type>& pr = it.value();


 u4 pcode = pr.first;
 minimal_fn_s0_re0_type proc = (minimal_fn_s0_re0_type) pr.second;

 Chasm_Call_Package* ccp = chasm_runtime_->new_call_package();
 ccp->add_new_channel("lambda");

// QString a1 = "place";
// QVariant a2 = QVariant::fromValue(77);
// u1 a3 = 78;

// Chasm_Carrier cc1 = chasm_runtime_->gen_carrier<QString>(&a1);
// Chasm_Carrier cc2 = chasm_runtime_->gen_carrier<QVariant>(&a2);
// Chasm_Carrier cc3 = chasm_runtime_->gen_carrier<u1>(&a3);

// ccp->add_carriers({cc1,cc2,cc3});


 //?  u1 pos = 0;
// for(Chasm_Typed_Value_Representation tvr : ai.reps)
// {
//  Chasm_Carrier cc = chasm_runtime_->gen_carrier(tvr);
//  ccp->add_carrier(cc);
//  //tvr.
//  //tvr.rep;
// }

 Chasm_Carrier cc1 = chasm_runtime_->gen_carrier(ai.reps[0]);

// QVariant a2 = QVariant::fromValue(77);
// Chasm_Carrier cc2 = chasm_runtime_->gen_carrier<QVariant>(&a2);
 Chasm_Carrier cc2 = chasm_runtime_->gen_carrier(ai.reps[1]);
 Chasm_Carrier cc3 = chasm_runtime_->gen_carrier(ai.reps[2]);

 ccp->add_carriers({cc1,cc2,cc3});

 chasm_runtime_->evaluate(ccp, pcode,  &launch_virtual_tour); //proc);
}

void Context_Menu_Provider::check_url_patterns(QString url,
  QVector<Context_Menu_Provider::Action_Info>& info)
{
 if(url_patterns_.isEmpty())
   return;

 if(url.contains("/maps/place"))
   qDebug() << url;


 for(int i = url_patterns_.size() - 1; i >= 0; --i) //const QMap<QString, QString>& m : url_patterns_)
 {
  QMap<QString, QString>& m = url_patterns_[i];
  QString pattern = m.value("pattern");

  if(pattern.isEmpty())
    continue;

  QRegularExpression rx(pattern);

  QRegularExpressionMatch rxm = rx.match(url);

  if(rxm.hasMatch())
  {
   QString proc = m.value("procedure");
   QString arguments = m.value("arguments");
   for(int i = 0; i < 10; ++i)
     arguments.replace(QString("`.%1").arg(i), rxm.captured(i));
   qDebug() << "Proc = " << proc;
   qDebug() << "Arguments = " << arguments;

   QStringList action_procedures;
   QStringList option_labels;

   check_url(proc, arguments, info);

   if(!info.isEmpty())
     break;
   //Q_EMIT url_pattern_match(proc, arguments);
  }
 }
}



