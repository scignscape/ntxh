

// // license___here_h


#ifndef GATE_INFO__H
#define GATE_INFO__H

#include "accessors.h"

#include <QString>

#include <QColor>
#include <QObject>


class GateMeasure; 

// //  just a minimal wrapper to bridge Facsanadu and cytoLib ...
class Gate : public QObject
{
 Q_OBJECT

 QString name_;
 void* oc_gate_;
 long last_modified_;

 Gate* parent_;

 int int_id_;

 static int new_id()
 {
  static int result = 0;
  return ++result;
 }

public:

 Gate(QString name)
  : name_(name), oc_gate_(nullptr), 
    last_modified_(0), 
    parent_(nullptr),
    int_id_(new_id())
 {
 }

 ACCESSORS(long ,last_modified)
 ACCESSORS(Gate* ,parent)
 ACCESSORS(int ,int_id)



 Gate(const Gate&);
 
 Gate()
 {
 }

 virtual bool classify(QVector<double>& obs) = 0;

 QList<GateMeasure*> getMeasures() const
 {
  return {};
 }

 QList<Gate*> children() const;

 void attachChild(Gate* g); 

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

 void setUpdated();
 void detachParent();
                   
 QColor color() const
 {
  return QColor();
 }

 void attachMeasure(GateMeasure* calc);

};

class GateRoot : Gate
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


