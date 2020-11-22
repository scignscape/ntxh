

// // license___here_h


#ifndef GATE_INFO__H
#define GATE_INFO__H

#include "accessors.h"

#include <QString>

#include <QColor>
#include <QDateTime>
#include <QObject>
#include <QList>
#include <QDebug>

#include "measure/GateMeasure.h"


class GateMeasure; 

// //  a wrapper to bridge Facsanadu and cytoLib ...
class Gate : public QObject
{
 Q_OBJECT

 QString name_;
 void* oc_gate_;
 quint64 last_modified_;

 Gate* parent_;

 int int_id_;

 static int new_id()
 {
  static int result = 0;
  return ++result;
 }

 QList<Gate*> children_;
 QList<GateMeasure*> calculations_;
 

public:

 Gate(QString name)
  : name_(name), oc_gate_(nullptr), 
    last_modified_(0), 
    parent_(nullptr),
    int_id_(new_id())
 {
 }

 ACCESSORS(quint64 ,last_modified)
 ACCESSORS(Gate* ,parent)
 ACCESSORS(int ,int_id)
 ACCESSORS__NONCONST_RGET_CONST(QList<Gate*> ,children)

 //?Gate(const Gate&);
 
 Gate() : parent_(nullptr), name_("?")
 {
 }

 virtual bool classify(QVector<double>& obs) = 0;

 QList<GateMeasure*> getMeasures() const
 {
  return calculations_;
 }

 void attachMeasure(GateMeasure* calc)
 {
  calc->set_gate(this);
  calculations_.push_back(calc);
 }

 //QList<Gate*> children() const;

 void attachChild(Gate* g)
 {
  children_.push_back(g);
  g->set_parent(this);
 }

 QString name() const
 {
  return name_;
 }

 virtual QString class_name() const
 {
  return {};
 }

 void set_name(QString name)
 {
  name_ = name;
 }

 void setUpdated()
 {
  quint64 qdt = QDateTime::currentMSecsSinceEpoch();
  Gate* pc = this;
  while(pc->parent())
    pc = pc->parent();
  pc->setUpdatedRecursive(qdt);
 }

 void setUpdatedRecursive(quint64 qdt)
 {
  last_modified_ = qdt;
  for(Gate* g : children_)
  {
   g->setUpdatedRecursive(qdt);
  }
 }

 Gate* getRootGate()
 {
  Gate* g = this;
  while(g->class_name() != "GateRoot")
  {
   g = g->parent();
   if(!g)
   {
    // // this shouldn't happen
    qDebug() << "Gate parent not found!";
    return nullptr;
   }
  }
  return g;
 }

 void detachParent()
 {
  parent_->children().removeOne(this);
  parent_ = nullptr;
 }
                   
 QColor color() const
 {
  return QColor();
 }

};

class GateRoot : public Gate
{
public:

 bool classify(QVector<double>& obs) 
 {
  return true;
 }

 void updateInternal()
 {
  setUpdated();
 }

 QString class_name() const
 {
  return "GateRoot";
 }
};

//Q_DECLARE_METATYPE(Gate)
Q_DECLARE_METATYPE(Gate*)
Q_DECLARE_METATYPE(const Gate*)


class GateColor
{
 QColor qc_;

public:

 GateColor(QColor qc) : qc_(qc) {}

 int r() { return qc_.red(); }
 int g() { return qc_.green(); }
 int b() { return qc_.blue(); }
 

};




#endif // GATE_INFO__H


