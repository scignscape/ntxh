/* axlFieldWritersFactory.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#ifndef AXLFIELDWRITERSFACTORY_H
#define AXLFIELDWRITERSFACTORY_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractDataWriter.h>

#include <QtWidgets>

class axlFieldWritersFactory;

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class AXLCORE_EXPORT axlFieldWritersInterface : public QFrame
{
    Q_OBJECT
public:
    axlFieldWritersInterface(QWidget *parent = 0);
    virtual ~axlFieldWritersInterface(void);

    void setActorFactorySingleton(axlFieldWritersFactory *actorFactorySingleton);
    axlFieldWritersFactory *actorFactorySingleton(void);


protected :
    axlFieldWritersFactory *m_actorFactorySingleton ;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlFieldWritersFactoryPrivate;

class AXLCORE_EXPORT axlFieldWritersFactory : public QObject
{
    Q_OBJECT

public:
    typedef dtkAbstractDataWriter *(*axlFieldWritersCreator)(void);

    typedef QHash<QString, axlFieldWritersCreator> axlFieldWritersCreatorHash;

public:
    static axlFieldWritersFactory *instance(void);

    bool registerFieldWriters(const QString& interface_name, axlFieldWritersCreator func);

    dtkAbstractDataWriter *create(const QString& interface_name);
    void initialize(void);

protected:
    static axlFieldWritersFactory *s_instance;

private:
    axlFieldWritersFactory(void);
    ~axlFieldWritersFactory(void);

private:
    axlFieldWritersFactoryPrivate *d;
};

#endif  // AXLFIELDWRITERSFACTORY_H
