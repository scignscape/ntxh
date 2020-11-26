

// // license___here


#include "GatingResult.h"

#include "GateSet.h"

#include "data/Dataset.h"

#include "gate-info.h"

#include <QDebug>
#include <QDateTime>



GatingResult::GatingResult(GateSet* gating)
  :  lastGatingCalculationTime_(0), 
     lastUpdateGate_(0), gating_(gating), globalGateRes_(nullptr)
{


}

void GatingResult::dogateRec(Gate* g, Dataset* ds)
{
 qDebug() << "1 gate = " << g;
 doOneGate(g, ds, true);
 for(Gate* child : g->children() )
 {
  dogateRec(child, ds);
 }
}

void GatingResult::classifyobs(Gate* g, Dataset* ds, QVector<int>& passedGateRes, int id)
{
 QVector<double> row;
 ds->getAsFloatCompensated(id, row);
 if(g->classify(row))
 {
  passedGateRes.push_back(id); //addUnchecked(id);
  (*globalGateRes_)[id] = g->int_id(); //?.setUnchecked(id, g->getIntID());
 }
}

void GatingResult::setUpdated(Gate* g)
{
 lastUpdateGate_ = g->last_modified();
}

int GatingResult::getGateIntIDForObs(int obs)
{
 if(globalGateRes_)
   return globalGateRes_->value(obs);

 return 0;
}
 
 // // Perform gating for all gates
void GatingResult::perform(GateSet* gating, Dataset* ds)
{
 gating_ = gating;
 Gate* gRoot = gating_->getRootGate();
 if(gRoot)
 {
  qDebug() << "Got root gate: " << gRoot->name();
  dogateRec(gRoot, ds);
 }
 else
 {
  qDebug() << "No root gate";
 }
}

 // //Calculate for one gate
void GatingResult::doOneGate(Gate* g, Dataset* ds, bool approximate)
{
 qDebug() << "gate = " << g;
 qDebug() << "gate parent = " << g->parent();

 quint64 gLastModified = g->last_modified(); //g.lastModified
 int n;
 QVector<int>* res = new QVector<int>;

 if(!g)
 {
  qDebug() << "Null gate"; 
  return;
 }

 qDebug() << "parent? = " << g->parent();

 if(g->parent() == nullptr) //This is the root
 {
  n = ds->getNumObservations();
  globalGateRes_ = new QVector<int>(n);

   // //  may allocate more space than needed because events 
    //    might be gated out ...
  res->reserve(n);

//  qDebug() << "n = " << n;   
    // for testing ...
 // n = 50;
//  qDebug() << "n = " << n;


  for(int i = 0; i < n; ++i)
  {
   classifyobs(g, ds, *res, i);
  }

  qDebug() << "After classify, accepted: " << res->size(); 
 }
 else
 {
  QVector<int>* arr = acceptedFromGate_.value(g->parent());
  if(!arr)
  {
   qDebug() << "Parent gate not calculated"; 
   return;
  }   //throw new RuntimeException("Parent gate not calculated "+g);
  n = arr->size();
  res->resize(n);
  //Do observations from parent
  for(int i = 0; i < n; ++i)
  {
   classifyobs(g, ds, *res, arr->value(i));
  }
 }
		
 setAcceptedFromGate(g, res, gLastModified);
 lastUpdateGate_ = gLastModified;

  //System.out.println("Calculated gate "+g+" for ds "+ds);
		//TODO separate these out
 //for(GateMeasure calc:g.getMeasures())
 //{
  //? gatecalc.put(calc,calc.calc(ds, g, this));
 //}
}
 
void GatingResult::setAcceptedFromGate(Gate* g, QVector<int>* res, quint64 lastMod)
{
 acceptedFromGate_.insert(g, res);
 lastUpdateGate_ = lastMod;
}

QList<Gate*> GatingResult::getIdGates()
{
 return gating_->getIdGates();
}

int GatingResult::getTotalCount()
{
 Gate* root = getRootGate();
 if(root)
 {
  QVector<int>* acc = acceptedFromGate_.value(root);
  if(acc)
    return acc->size();
 }
 qDebug() << "No root gate array yet";
 return 0;
}

Gate* GatingResult::getRootGate()
{
 return gating_->getRootGate();
}

double GatingResult::getCalcResult(GateMeasure* calc)
{
 return gatecalc_.value(calc);
}

bool GatingResult::gateNeedsUpdate()
{
 Gate* g = getRootGate();
 return g->last_modified() > lastUpdateGate_;
}

QVector<int>* GatingResult::getAcceptedFromGate(Gate* g)
{
 return acceptedFromGate_.value(g);
}

void GatingResult::setLastUpdateTime()
{
 lastGatingCalculationTime_ = QDateTime::currentMSecsSinceEpoch();
}



