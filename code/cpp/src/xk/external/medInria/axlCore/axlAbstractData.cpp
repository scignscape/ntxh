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

#include "axlAbstractData.h"
#include "axlAbstractField.h"
#include "axlMesh.h"
#include "axlDataDynamic.h"
#include <dtkCoreSupport/dtkGlobal.h>

#include <QtCore>
#include <QtGui>

class axlAbstractDataPrivate
{
public:
    QColor color;
    double opacity;
    double size;
    QString shader;
    bool editable;
    bool updateView = 1;

public:
    QList<axlAbstractField *> fields;
    axlMesh *mesh;
};

axlAbstractData::axlAbstractData(axlAbstractData *parent) : dtkAbstractData(parent), d(new axlAbstractDataPrivate)
{
    setColor(Qt::gray);
    setOpacity(1.0);
    setSize(0.005);
    setShader("");
    setEditable(true);
    d->mesh = NULL;
}

axlAbstractData::axlAbstractData(const axlAbstractData &data): dtkAbstractData(), d(new axlAbstractDataPrivate){
    d->color = data.color();
    d->opacity = data.opacity();
    d->size = data.size();
    d->shader = data.shader();
    //const bool edit = data.editable();
    //setEditable(edit);
    //setMesh(data.mesh());
    setEditable(true);
    d->mesh = NULL;
}

axlAbstractData::~axlAbstractData(void)
{
    delete d;
    d = NULL;
}

const QColor& axlAbstractData::color(void) const
{
    return d->color;
}

void axlAbstractData::setColor(const QColor& color)
{
    d->color = color;
}

void axlAbstractData::setColor(double r, double g, double b)
{
    d->color.setRgbF(r,g,b);
}

const double& axlAbstractData::opacity(void) const
{
    return d->opacity;
}

void axlAbstractData::setOpacity(const double& opacity)
{
    d->opacity = opacity;
}

const double& axlAbstractData::size(void) const
{
    return d->size;
}

void axlAbstractData::setSize(const double& size)
{
    d->size = size;
}

const bool& axlAbstractData::updateView(void)
{
    return d->updateView;
}

void axlAbstractData::setUpdateView(bool updateView)
{
    d->updateView = updateView;
}

const QString& axlAbstractData::shader(void) const
{
    return d->shader;
}

const bool& axlAbstractData::editable(void)
{
    return d->editable;
}

void axlAbstractData::setShader(const QString& shader)
{
    d->shader = shader;
}

void axlAbstractData::setEditable(bool edit)
{
    d->editable = edit;
}


//! Return the mesh of that object is computed.
/*!
 *
 */
axlMesh *axlAbstractData::mesh(void){
    return d->mesh;
}


//! Set a corresponding mesh for that object.
/*!
 *
 */
void axlAbstractData::setMesh(axlMesh* mesh) {
    d->mesh = mesh;
}


//! Add a field to the field list of the object
/*!
 *
 */
void axlAbstractData::addField(axlAbstractField *field)
{
    d->fields.append(field);
    field->setParent(this);
}


//! Check if a field with the same name is already applied on the object.
/*!
 *
 */
bool axlAbstractData::updateFieldList(QString nameField){

    bool fieldWithSameNameExit = false;
    foreach(axlAbstractField *field, this->fields() )
        if(field->name() == nameField)
            fieldWithSameNameExit = true;

    return fieldWithSameNameExit;
}


//! Check if a field with the same name is already applied on the object.
//! Modify nameField if it's the case. Field names must be unique!
/*!
 *
 */
QString axlAbstractData::changeFieldName(QString nameField){

    int size = this->fields().size();
    int numberOccurence = 0;
    QString identity = nameField;
    for(int indice = 0;indice < size; indice++){
        if(this->fields().at(indice)->objectName() == nameField){
            nameField.clear();
            nameField = identity;
            nameField.append(QString::number(numberOccurence));
            numberOccurence++;
        }
    }

    return nameField;
}

QList<axlAbstractField *> axlAbstractData::fields(void)
{
    return d->fields;
}

void axlAbstractData::touchField(void)
{
    emit modifiedField();
}

void axlAbstractData::touchGeometry(void)
{
    emit modifiedGeometry();
}

void axlAbstractData::touchProperty(void)
{
    emit modifiedProperty();
}

void axlAbstractData::touchStructure(void)
{
    emit modifiedStructure();
}

//! Convert an axlAbstractData into a QVariantList that specifies all properties of the axlAbstractData.
/*!
 *
 */
QVariantList axlAbstractData::convertDataToQVariant(void) const
{
    QVariantList list;

    return list;
}

//! Modify properties and geometry variables of the axlAbstractData. Return 1 if the modification was sucessfully made. Otherwise return 0.
/*!
 *
 */
int axlAbstractData::convertQVariantToData(const QVariantList& data){
    return 0;
}

// /////////////////////////////////////////////////////////////////
// axlAbstractData documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractData
 *
 *  \brief Class axlAbstractData defines an API for all type of axel data.
 *
 *  Every axel data must inherite from this abstract class.
 */
