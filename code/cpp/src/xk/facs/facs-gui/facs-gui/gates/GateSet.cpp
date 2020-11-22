

// // license___here_h


#include "GateSet.h"

#include "gate-info.h"

class Gate;

// // A set of gates
GateSet::GateSet()
 :  rootgate_(new GateRoot)
{
 rootgate_->set_name("root");
}

void GateSet::getGatesRecursively(Gate* parent, LinkedList<Gate*> list)
{
 list.push_back(parent);
 for(Gate* g : parent->children())
 {
  getGatesRecursively(g, list);
 }
}

void GateSet::getIdGates(Gate* g, QList<Gate*> list)
{
 while(list.size() <= g->int_id())
   list.push_back(nullptr);
  //Set this particular gate in the list
 list.replace(g->int_id(), g);
		//Recurse to child gates
 for(Gate* child : g->children())
 {
  getIdGates(child, list);
 }
}

//Gate* GateSet::getRootGate()
//{
// return rootgate_;
//}

void GateSet::addNewGate(Gate* g)
{
 rootgate_->attachChild(g);
}
 // {rootgate.attachChild(g);}

QList<Gate*> GateSet::getGates()
{
 QList<Gate*> result;// = new QList<Gate*>();
 getGatesRecursively(rootgate_, result);
 return result;
}

QSet<QString> GateSet::getGateNames()
{
 QSet<QString> prevnames; //=new HashSet<String>();
 for(Gate* otherGate : getGates())
   prevnames.insert(otherGate->name());
 return prevnames;
}

 // // Get a free name for a gate
QString GateSet::getFreeName()
{
 QSet<QString> prevnames = getGateNames();
 int i=0;
 while(prevnames.contains(QString("gate %1").arg(i)))
   ++i;
 return QString("gate %1").arg(i);
}

Gate* GateSet::getGate(QString name)
{
 return getGate(name, getRootGate());
}

Gate* GateSet::getGate(QString name, Gate* parent)
{
 if(parent->name() == name)
   return parent;

 for(Gate* g : parent->children())
 {
  Gate* got = getGate(name, g);
  if(got)
    return got;
 }

 return nullptr;
}


QList<Gate*> GateSet::getIdGates()
{
 QList<Gate*> result;// = new QList<Gate*>();
 getIdGates(getRootGate(), result);
 return result;
}


