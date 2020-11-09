#ifndef axlViewDefault_H
#define axlViewDefault_H

#include "axlAbstractActor.h"
#include "axlCoreExport.h"

#include <axlCore/axlAbstractView.h>
#include <dtkCoreSupport/dtkAbstractData.h>

class axlViewDefaultPrivate;

class AXLCORE_EXPORT axlViewDefault : public axlAbstractView
{
    Q_OBJECT

public:
    axlViewDefault(void);
    ~axlViewDefault(void);

    QWidget *widget(void);


private:
    axlViewDefaultPrivate *d;
};

#endif // axlViewDefault_H
