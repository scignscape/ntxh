/* axlDataDynamic.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C)
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLDATADYNAMIC_H
#define AXLDATADYNAMIC_H

#include "axlCoreExport.h"
#include "axlAbstractDataComposite.h"

#include <dtkCoreSupport/dtkAbstractProcess.h>

#include <QtCore>

class axlDataDynamicPrivate;
class axlAbstractProcess;

class AXLCORE_EXPORT axlDataDynamic : public axlAbstractDataComposite
{
    Q_OBJECT

public:
    enum Type {
        Dynamic = 0x001,
        Static = 0x002
    };

public:
    axlDataDynamic(void);
    virtual ~axlDataDynamic(void);


public :
    axlDataDynamic::Type getType(void);
    void setType(axlDataDynamic::Type type);


public slots:
    void setInput(dtkAbstractData *data, int channel=0);

    void setParameter(int parameter);
    void setParameter(int parameter, int channel);
    void setParameter(double parameter);
    void setParameter(double parameter, int channel);

    int setProcess(QString processName);
    void setProcess(axlAbstractProcess *process);
    int numberOfUpdate(void);

public :
    QList<axlAbstractData *> inputs(void);
    QList<axlAbstractData *> parameters(void);
    axlAbstractProcess *process(void);
    axlAbstractData *outputs(void);
    axlAbstractData *outputs(int channel);
    void clearInputs(void);
    bool isNotInputProcess(dtkAbstractData *data);
    bool isNotOutputProcess(dtkAbstractData *data);

    /*!
     * Convert an axlShape into a QVariantList. Useful for RPC protocol.
     */
    QVariantList convertDataToQVariant(void) const;
    /*!
     * Convert a QVariantList into an axlShape. Useful for RPC protocol.
     */
    int convertQVariantToData(const QVariantList &data);


    /* dtk overload */

public:

    virtual QString description(void) const;
    virtual QString identifier(void) const;

public:
    virtual int numberOfChannels(void);

signals :
    void dataInserted(axlAbstractData *data);

public slots:
    virtual void update(void);
    void onRemoved(void);

private:
    axlDataDynamicPrivate *d;
};

dtkAbstractData *createAxlDataDynamic(void);

#endif// AXLDATADYNAMIC_H
