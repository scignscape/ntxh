#ifndef AXLINSPECTORTOOLGENERIC_H
#define AXLINSPECTORTOOLGENERIC_H

#include <QObject>
#include <QtGui>

#include "axlGuiExport.h"

//? added
#include <QFrame>


class axlInspectorToolGenericPrivate;
class axlInspectorObjectController;
class axlAbstractData;

class AXLGUI_EXPORT axlInspectorToolGeneric : public QFrame
{
    Q_OBJECT

public:
    axlInspectorToolGeneric(QString implementation, axlInspectorObjectController *control, QWidget *parent=0);
    virtual ~axlInspectorToolGeneric(void);

signals:
    void dataSetFieldsChanged(QList<axlAbstractData *> dataSet, QString fieldName);
    void dataInserted(axlAbstractData *data);

public slots :
    void runDataInserted(void);

private:
    axlInspectorToolGenericPrivate *d;

};

#endif // AXLINSPECTORTOOLGENERIC_H
