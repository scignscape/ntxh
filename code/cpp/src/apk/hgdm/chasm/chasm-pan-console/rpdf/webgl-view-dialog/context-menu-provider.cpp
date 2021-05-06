
#include "context-menu-provider.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


#include "chasm-lib/chasm/chasm-runtime.h"
#include "chasm-lib/chasm/chasm-call-package.h"

#include "chasm-lib/chasm/chasm-type-object.h"

#include "signal-generator.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QTimer>
#include <QPixmap>
#include <QFile>

//#include <smart



void launch_web_site(QString place, QVariant pos, n8 winid)
{
 qDebug() << "\n\nPlace = " << place << "\n\n";


 qDebug() << "\n\nwinid = " << winid << "\n\n";



 QScreen* screen = QGuiApplication::primaryScreen();
 if (!screen)
   return;
 QApplication::beep();

 QTimer::singleShot(10000, [=]
 {
  QPixmap pixmap = screen->grabWindow(winid);
  QString path = SCREENSHOTS_FOLDER "/chasm.png";
  qDebug() << "Saving to path: " << path;

  QFile file(path);
  if(file.open(QIODevice::WriteOnly))
  {
   pixmap.save(&file, "PNG");
  }
 });

}

void launch_virtual_tour(const QPoint& pos, QVariant url, Context_Menu_Provider* _this)
{
 // qDebug() << "\n\nv Place = " << place << "\n\n";

 qDebug() << "\n\nv url = " << url << "\n\n";

 _this->signal_generator()->emit_new_dialog_requested(pos, url.value<QUrl>());

}



void test_map_places(Context_Menu_Provider* _this, QString arguments,
  QVector<Pattern_Matcher_Runtime::Action_Info>& info)
{

 static QRegularExpression rx{"[\\s.]+;[\\s.]+"};
 QStringList qsl = arguments.split(rx);

 Chasm_Runtime& csr = *_this->chasm_runtime();

 Chasm_Type_Object* QString_type = csr.get_type_object_by_name("QString");
 Chasm_Type_Object* QVariant_type = csr.get_type_object_by_name("QVariant");
 Chasm_Type_Object* ref_type = csr.get_type_object_by_name("n8&");
 Chasm_Type_Object* n8_type = csr.get_type_object_by_name("n8");
 Chasm_Type_Object* pVoid_type = csr.get_type_object_by_name("void*");

 Chasm_Type_Object* ref_type_shared = csr.get_type_object_by_name("n8&!");

 QString url = ROOT_FOLDER "/../testdia/matterport/new-alexander.html";

 //QSharedDataPointer<QPoint> qp = QSharedDataPointer<QPoint>(new QPoint(qsl[3].toUInt(), qsl[4].toUInt()) );

 QPoint* _pos = new QPoint(qsl[3].toUInt(), qsl[4].toUInt());

// std::shared_ptr<QPoint> spos(_pos);
// QPoint& pos = *_pos;

 info = {
   {{
     {ref_type_shared->make_instance(_pos) },
     {QVariant_type->with_rep("url:file:///" + url) },
     {pVoid_type->with_instance(_this) },
    }, "Virtual Tour", "launch_virtual_tour"},
   {{
     {QString_type->with_rep(qsl.first()) },
     {QVariant_type->with_rep("89") },
     {n8_type->with_rep(qsl.last()) },
    }, "Web Site", "launch_web_site"},
   //};
   {{ {}
    }, "View GIS data", "viwe_gis_data"}
   }
   ;

 //info[0].reps.push_back()

//_this->chasm_runtime()->get_type_object_by_name("QString"), "Birmingham"

// info = {{nullptr, "_this" + qsl.first(), ""}, {nullptr, arguments, ""}};


// qDebug() << "arg1 = " << arg1;
// qDebug() << "arg2 = " << arg2;
// qDebug() << "arg3 = " << arg3;
}


Context_Menu_Provider::Context_Menu_Provider(Pattern_Matcher_Runtime* pm_runtime,
  Signal_Generator* signal_generator)
  :  pm_runtime_(pm_runtime), signal_generator_(signal_generator)
{
 chasm_runtime_ = pm_runtime_->chasm_runtime();

 pm_runtime_->procedure_name_resolutions().insert("test_map_places",
   "test_map_places@70930");

 pm_runtime_->registered_procedures().insert("test_map_places@70930",
   {70930, (minimal_fn_s0_re0_type) &test_map_places});


 pm_runtime_->procedure_name_resolutions().insert("launch_web_site",
   "launch_web_site@70378");

 pm_runtime_->registered_procedures().insert("launch_web_site@70378",
   {70378, (minimal_fn_s0_re0_type) &launch_web_site});


 pm_runtime_->procedure_name_resolutions().insert("launch_virtual_tour",
   "launch_virtual_tour@70079");

 pm_runtime_->registered_procedures().insert("launch_virtual_tour@70079",
   {70079, (minimal_fn_s0_re0_type) &launch_virtual_tour});

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

 const QPair<u4, minimal_fn_s0_re0_type>& pr = it.value();


 u4 pcode = pr.first;
 minimal_fn_s0_re0_type proc = pr.second;

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

 chasm_runtime_->evaluate(ccp, pcode, //(minimal_fn_s0_re0_type)
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


 const QPair<u4, minimal_fn_s0_re0_type>& pr = it.value();


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


