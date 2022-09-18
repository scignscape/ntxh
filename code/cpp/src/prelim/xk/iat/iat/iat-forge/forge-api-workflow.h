
#ifndef FORGE_API_WORKFLOW__H
#define FORGE_API_WORKFLOW__H

#include <QStringList>

#include "accessors.h"
#include "global-types.h"

class QWizardPage;

class Forge_Runtime;

typedef void(Forge_Runtime::*fn0)();
typedef void(Forge_Runtime::*fn1)(QString arg);
union fn0or1
{
 fn0 f0;
 fn1 f1;
};

class Forge_API_Workflow
{
 Forge_Runtime* forge_runtime_;
 QVector<QPair<fn0or1, QString>> calls_;

 QPair<s4, QPair<int, std::function<int()>>> call_index_;
 s4 wzcall_index_;
 //int(*cb_)();

 u4 last_wzstep_index_;
 QMap<u4, QPair<QWizardPage*, u4>> wzsteps_;

 void register_wzpage_step(QWizardPage* page);

 QMap<QString, QString> custom_envs_;

public:

 Forge_API_Workflow(Forge_Runtime* forge_runtime);

 void parse_calls(QString proc);
 void parse_calls_from_file(QString path);

 void run_calls();
 void next_call();
 void next_wzcall(QWizardPage* page);
 int& run_calls(std::function<int()> cb);

 void add_custom_env_value(QString key, QString value);

};

#endif // FORGE_API_WORKFLOW__H
