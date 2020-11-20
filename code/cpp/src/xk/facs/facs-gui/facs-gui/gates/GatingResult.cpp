

// // license___here


#include "GatingResult.h"

#include "GateSet.h"

#include "data/Dataset.h"

#include "gate-info.h"

#include <QDebug>



GatingResult::GatingResult(GateSet* gating)
  :  lastGatingCalculationTime_(0), 
     lastUpdateGate_(0), gating_(gating), globalGateRes_(nullptr)
{


}

void GatingResult::dogateRec(Gate* g, Dataset* ds)
{
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
 dogateRec(gRoot, ds);
}

 // //Calculate for one gate
void GatingResult::doOneGate(Gate* g, Dataset* ds, bool approximate)
{
 long gLastModified = g->last_modified(); //g.lastModified
 int n;
 QVector<int>* res = new QVector<int>;
 if(g->parent() == nullptr) //This is the root
 {
  n = ds->getNumObservations();
  globalGateRes_ = new QVector<int>(n);
  res->resize(n);
  for(int i = 0; i < n; ++i)
  {
   classifyobs(g, ds, *res, i);
  }
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
 
void GatingResult::setAcceptedFromGate(Gate* g, QVector<int>* res, long lastMod)
{
 acceptedFromGate_.insert(g, res);
 lastUpdateGate_ = lastMod;
}

QList<Gate*> GatingResult::getIdGates()
{

}

int GatingResult::getTotalCount()
{

}

Gate* GatingResult::getRootGate()
{

}

double GatingResult::getCalcResult(GateMeasure* calc)
{

}

bool GatingResult::gateNeedsUpdate()
{

}

QList<int> GatingResult::getAcceptedFromGate(Gate* g)
{

}

long GatingResult::lastGatingCalculationTime()
{

}

void GatingResult::setLastUpdateTime()
{

}



