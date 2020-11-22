

// // license___here_h


#ifndef GatingResult__H
#define GatingResult__H


#include "accessors.h"

#include <QList>
#include <QMap>
#include <QVector>


// package facsanadu.gates;

class Gate;
class Dataset;
class GateSet;
class GateMeasure;


// original author Johan Henriksson

class GatingResult
{
 QMap<Gate*, QVector<int>* > acceptedFromGate_; //=new HashMap<Gate, QList<int>>();
 QMap<GateMeasure*, double> gatecalc_;//=new HashMap<GateMeasure, Double>();
 QVector<int>* globalGateRes_; //=new QList<int>();

 /**
  * Do gating for a gate with a parent
  */
 void dogateRec(Gate* g, Dataset* ds);
 
 void classifyobs(Gate* g, Dataset* ds, QVector<int>& passedGateRes, int id); 
 quint64 lastGatingCalculationTime_; // =0;
 GateSet* gating_; //=new GateSet();

 quint64 lastUpdateGate_;

 
public:

 ACCESSORS(quint64 ,lastUpdateGate)
 ACCESSORS(quint64 ,lastGatingCalculationTime)

  //=0;
 GatingResult(GateSet* gating);

 void setUpdated(Gate* g);


 int getGateIntIDForObs(int obs);
 
 // // Perform gating for all gates
 void perform(GateSet* gating, Dataset* ds);

 // //Calculate for one gate
 void doOneGate(Gate* g, Dataset* ds, bool approximate);
 
 /**
  * Set accepted result from a gate
  */
 void setAcceptedFromGate(Gate* g, QVector<int>* res, quint64 lastMod);
 
 QList<Gate*> getIdGates();

 int getTotalCount();

 Gate* getRootGate();

 double getCalcResult(GateMeasure* calc);

 /**
  * Check if this gate needs any updating.
  * Done by having a time last computed vs a time for when last modified
  */
 bool gateNeedsUpdate();

 QVector<int>* getAcceptedFromGate(Gate* g);

 //long lastGatingCalculationTime();

 void setLastUpdateTime();

};


#endif // GatingResult__H


