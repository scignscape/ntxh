// Version: $Id: 497885b8f33d8c1af83843fa4f1eb0ed0b1714eb $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include "dtkComposerNodeLeaf.h"

#include <QtCore>
#include <QtWidgets>

template <typename T> class dtkCorePluginFactory;

// ///////////////////////////////////////////////////////////////////
// dtkComposerNodeObject definition
// ///////////////////////////////////////////////////////////////////

template <typename T> class dtkComposerNodeObject : public dtkComposerNodeLeafObject
{
public:
             dtkComposerNodeObject(void);
    virtual ~dtkComposerNodeObject(void);

public:
    void setFactory(const dtkCorePluginFactory<T>& factory);

public:
    bool createObject(const QString& implementation);

public:
    QVariant variant(void) const;

public:
    T *object(void) const;

public:
    QStringList implementations(void) const;

    QString currentImplementation(void) const;

    bool implementationHasChanged(const QString& implementation) const;

    QWidget *editor(void);

protected:
    QString m_implementation;
    T *m_object;
    QHash<QString, T *> m_objects;
    const dtkCorePluginFactory<T> *m_factory;
};

// ///////////////////////////////////////////////////////////////////

#include "dtkComposerNodeObject.tpp"

//
// dtkComposerNodeObject.h ends here
