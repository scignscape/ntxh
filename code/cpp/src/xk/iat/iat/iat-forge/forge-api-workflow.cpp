
#include "forge-api-workflow.h"

#include "forge-runtime.h"

#include "global-types.h"

#include <QProcessEnvironment>
#include <QFile>
#include <QWizardPage>
#include <QVariant>

#include <QDebug>


Forge_API_Workflow::Forge_API_Workflow(Forge_Runtime* forge_runtime)
  :  forge_runtime_(forge_runtime), last_wzstep_index_((u4)-1),
     call_index_({-1, {0, nullptr}}),
     wzcall_index_(-1)//{-1, {0, nullptr}})
{
 forge_runtime_->set_cb([this](){ next_call(); });
 forge_runtime_->set_wzcb([this](QWizardPage* page){ next_wzcall(page); });
 forge_runtime_->set_register_cb([this](QWizardPage* page){ register_wzpage_step(page); });
}


void Forge_API_Workflow::register_wzpage_step(QWizardPage* page)
{
 if(page)
   page->setProperty("call-index", (u4) call_index_.first);

 else
 {
  wzsteps_[last_wzstep_index_] = {page, call_index_.first};
 }
 //wzsteps_[call_index_.first] = {page, last_wzstep_index_};
 last_wzstep_index_ = call_index_.first;
}

void Forge_API_Workflow::next_wzcall(QWizardPage* page)
{
 u4 page_call_index = -1;
 if(page)
 {
  page_call_index = page->property("call-index").toInt();
 }

 if(wzsteps_.contains(page_call_index))
 {
  QPair<fn0or1, QString> pr = calls_[wzsteps_[page_call_index].second];
  if(pr.second.isEmpty())
    (forge_runtime_->*pr.first.f0)();
  else
    (forge_runtime_->*pr.first.f1)(pr.second);
 }

// ++wzcall_index_;//.first;
// forge_runtime_->next_wzcall(page);
// if(!page)
// {
//  QPair<fn0or1, QString> pr = calls_[wzcall_index_];
//  if(pr.second.isEmpty())
//    (forge_runtime_->*pr.first.f0)();
//  else
//    (forge_runtime_->*pr.first.f1)(pr.second);
// }

 //QWizard* qwz =
 //page->wizard();
 //run_calls();


}


void Forge_API_Workflow::next_call()
{
 ++call_index_.first;
 run_calls();
}

int& Forge_API_Workflow::run_calls(std::function<int()> cb)
{
 call_index_.first = 0;
 call_index_.second.second = cb;
 run_calls();
 qDebug() << "run calls finished ...";
 return call_index_.second.first;
}

void Forge_API_Workflow::run_calls()
{
 if(call_index_.first == calls_.size())
 {
  call_index_.second.first = call_index_.second.second(); return;
 }

 QPair<fn0or1, QString> pr = calls_[call_index_.first];
 if(pr.second.isEmpty())
   (forge_runtime_->*pr.first.f0)();
 else
   (forge_runtime_->*pr.first.f1)(pr.second);

// for(QPair<fn0or1, QString> pr : calls_)
// {
//  if(pr.second.isEmpty())
//    (forge_runtime_->*pr.first.f0)();
//  else
//    (forge_runtime_->*pr.first.f1)(pr.second);
// }
}

void Forge_API_Workflow::parse_calls_from_file(QString path)
{
 QFile file(path);
 if(file.open(QIODevice::ReadOnly))
 {
  QString text = file.readAll();
  parse_calls(text);
 }
}

void Forge_API_Workflow::parse_calls(QString proc)
{
 s4 index = 0;
 while(index < proc.size())
 {
  s4 i = proc.indexOf(";.", index);
  if(i == -1)
    break;
  QString line = proc.mid(index, i - index).trimmed();
  if(line.startsWith('='))
  {
   QStringList qsl = line.simplified().split(' ');
   QString eq = qsl.takeFirst(); // should be "="
   QString key;
   while(!qsl.isEmpty())
   {
    if(key.isEmpty())
    {
     key = qsl.takeFirst();
     if(key.endsWith(':'))
     {
      key.chop(1);
      key.prepend("set_");
      continue;
     }
     else
     {
      fn0 f_0 = forge_runtime_->find_f0_method(key);
      if(f_0)
        calls_.push_back({fn0or1{.f0 = f_0}, {}});
      key.clear();
      continue;
     }
    }
    else
    {
     QString value = qsl.takeFirst();
     if(value.startsWith("%<") && value.endsWith('>'))
     {
      static auto envs = QProcessEnvironment::systemEnvironment();
      value = value.mid(2, value.size() - 3);
      value = envs.value(value, value);
     }
     fn1 f_1 = forge_runtime_->find_f1_method(key);
     if(f_1)
       calls_.push_back({fn0or1{.f1 = f_1}, value});
     key.clear();
     continue;
    }
   }
  }
  else if(!line.startsWith(".;"))
  {
   s4 j = line.indexOf('$');
   if(j == -1)
   {
    fn0 f_0 = forge_runtime_->find_f0_method(line.simplified());
    if(f_0)
      calls_.push_back({fn0or1{.f0 = f_0}, {}});
   }
   else
   {
    QString fn = line.left(j).simplified();
    fn1 f_1 = forge_runtime_->find_f1_method(fn);
    if(f_1)
      calls_.push_back({fn0or1{.f1 = f_1}, line.mid(j + 1).simplified()});
   }
  }
  index = i + 2;
 }
}
