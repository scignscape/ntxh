/* axlAbstractData.h ---
 *
 * Author: Bernard Mourrain
 * Copyright (C) 2011 - Bernard Mourrain, Inria.
 * Created: Tue Nov 11 16:58:59 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTDATA_H
#define AXLABSTRACTDATA_H

#include "axlCoreExport.h"

#include <dtkCoreSupport/dtkAbstractData.h>

#include <QtCore>

class axlAbstractDataPrivate;
class axlAbstractField;
class axlMesh;

class AXLCORE_EXPORT axlAbstractData : public dtkAbstractData
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor )
    Q_PROPERTY(double opacity READ opacity WRITE setOpacity )
    Q_PROPERTY(double size READ size WRITE setSize )
    Q_PROPERTY(QString shader READ shader WRITE setShader )

public:
    axlAbstractData(axlAbstractData* parent = NULL);
    axlAbstractData(const axlAbstractData &data);
    virtual ~axlAbstractData(void);

signals:
    void modifiedGeometry(void);
    void modifiedStructure(void);
    void modifiedField(void);
    void modifiedProperty(void);

public slots:
    void touchGeometry(void);
    void touchProperty(void);
    void touchStructure(void);
    virtual void touchField(void);

public:
    const QColor& color(void) const;
    const double& opacity(void) const;
    const double& size(void) const;
    const QString& shader(void) const;
    const bool &editable(void);
    const bool& updateView(void);

    void setColor(double r, double g, double b);

public slots:
    void setColor(const QColor& color);
    void setOpacity(const double& opacity);
    void setSize(const double& size);
    void setShader(const QString& shader);
    void setEditable(bool edit);

public:
    void addField(axlAbstractField *field);
    bool updateFieldList(QString nameField);
    QString changeFieldName(QString fieldName);
    axlMesh *mesh(void);
    void setMesh(axlMesh* mesh);
    virtual QVariantList convertDataToQVariant(void) const;
    virtual int convertQVariantToData(const QVariantList &data);
    void setUpdateView(bool updateView);

public:
    QList<axlAbstractField *> fields(void);

private:
    axlAbstractDataPrivate *d;
};

Q_DECLARE_METATYPE(axlAbstractData);
#endif
