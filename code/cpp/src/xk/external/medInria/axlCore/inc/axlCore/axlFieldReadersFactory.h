/* axlFieldReadersFactory.h ---
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


#ifndef AXLFIELDREADERSFACTORY_H
#define AXLFIELDREADERSFACTORY_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractDataReader.h>

#include <QtWidgets>

class axlFieldReadersFactory;

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class AXLCORE_EXPORT axlFieldReadersInterface : public QFrame
{
    Q_OBJECT
public:
    axlFieldReadersInterface(QWidget *parent = 0);
    virtual ~axlFieldReadersInterface(void);

    void setActorFactorySingleton(axlFieldReadersFactory *actorFactorySingleton);
    axlFieldReadersFactory *actorFactorySingleton(void);


protected :
    axlFieldReadersFactory *m_actorFactorySingleton ;
};

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class axlFieldReadersFactoryPrivate;

class AXLCORE_EXPORT axlFieldReadersFactory : public QObject
{
    Q_OBJECT

public:
    typedef dtkAbstractDataReader *(*axlFieldReadersCreator)(void);

    typedef QHash<QString, axlFieldReadersCreator> axlFieldReadersCreatorHash;

public:
    static axlFieldReadersFactory *instance(void);

    bool registerFieldReaders(const QString& interface_name, axlFieldReadersCreator func);

    dtkAbstractDataReader *create(const QString& interface_name);
    void initialize(void);

protected:
    static axlFieldReadersFactory *s_instance;

private:
    axlFieldReadersFactory(void);
    ~axlFieldReadersFactory(void);

private:
    axlFieldReadersFactoryPrivate *d;
};

#endif  // AXLFIELDREADERSFACTORY_H
