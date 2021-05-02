
#include "context-menu-provider.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


Context_Menu_Provider::Context_Menu_Provider()
{

}

void Context_Menu_Provider::run_callback(Action_Info& ai)
{

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


void Context_Menu_Provider::check_url(QString procedure, QString arguments,
  QVector<Action_Info>& info)
{
// info.push_back({procedure, "", nullptr});
// info.push_back({nullptr, procedure, ""});
// info.push_back({nullptr, procedure, ""});

 info = {{nullptr, procedure, ""}, {nullptr, arguments, ""}};
 ////return nullptr;
}

