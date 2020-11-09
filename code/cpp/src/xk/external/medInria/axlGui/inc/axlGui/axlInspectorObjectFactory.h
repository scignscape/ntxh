/* axlInspectorObjectFactory.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: mar. mars 29 12:29:01 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Fri Oct 28 15:57:20 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 34
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#ifndef AXLINSPECTOROBJECTFACTORY_H
#define AXLINSPECTOROBJECTFACTORY_H

#include "axlGuiExport.h"
#include "axlInspectorUtils.h"

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class dtkAbstractData;

class axlAbstractView;
class axlInspectorObjectController;
class axlInspectorObjectFactory;

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class AXLGUI_EXPORT axlInspectorObjectInterface : public QFrame
{
    Q_OBJECT
public:
    axlInspectorObjectInterface(QWidget *parent = 0);
    virtual ~axlInspectorObjectInterface(void);

    void setObjectFactorySingleton(axlInspectorObjectFactory *objectFactorySingleton);
    axlInspectorObjectFactory *objectFactorySingleton(void);


signals :
    //void dataChanged(dtkAbstractData *data);
    void dataChangedByGeometry(dtkAbstractData *data);
//    void dataChangedByShader(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByShaderFromString(dtkAbstractData *data, QString isophoteShaderXml);
//    void dataChangedByOpacity(dtkAbstractData *data, double opacity);
    void showCurrentPoint(double u, double v, dtkAbstractData *data);
    void hideCurrentPoint(double u, double v, dtkAbstractData *data);
    void moveCurrentPoint(double u, double v, dtkAbstractData *data);
    void tubeFilterRadiusChanged(dtkAbstractData *data, double radius);

    void updateStateColor(dtkAbstractData *data, int i);

    void modifiedProperty(dtkAbstractData *, int);
    void update();

public slots:
    virtual void setData(dtkAbstractData *data);

public:
    void initComboBoxShaderValue(QComboBox *comboBoxShader, QLineEdit *lineEditShader);
    QString filePath(const QString& shader);

protected :
    axlInspectorObjectFactory *m_objectFactorySingleton ;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlInspectorObjectFactoryPrivate;

class AXLGUI_EXPORT axlInspectorObjectFactory : public QObject
{
    Q_OBJECT

public:
    typedef axlInspectorObjectInterface *(*axlInspectorObjectCreator)(void);

    typedef QHash<QString, axlInspectorObjectCreator> axlInspectorObjectCreatorHash;

public:
    static axlInspectorObjectFactory *instance(void);

    bool registerInspectorObject(const QString& interface_name, axlInspectorObjectCreator func);

    axlInspectorObjectInterface *create(const QString& interface_name);

protected:
    static axlInspectorObjectFactory *s_instance;

private:
    axlInspectorObjectFactory(void);
    ~axlInspectorObjectFactory(void);

private:
    axlInspectorObjectFactoryPrivate *d;
};

#endif //AXLINSPECTOROBJECTFACTORY_H
