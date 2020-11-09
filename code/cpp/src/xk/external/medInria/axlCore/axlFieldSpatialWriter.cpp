/* axlFieldSpatialWriter.cpp ---
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

#include "axlFieldSpatialWriter.h"

#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractFieldDiscrete.h>
#include <axlCore/axlAbstractFieldSpatial.h>
#include <axlCore/axlAbstractFieldParametric.h>

#include <dtkCoreSupport/dtkAbstractData.h>

#include <axlCore/axlAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialWriter
// /////////////////////////////////////////////////////////////////

axlFieldSpatialWriter::axlFieldSpatialWriter(void)
{
    this->setObjectName(this->description());
}

axlFieldSpatialWriter::~axlFieldSpatialWriter(void)
{

}

QString axlFieldSpatialWriter::identifier(void) const
{
    return "axlFieldSpatialWriter";
}

QString axlFieldSpatialWriter::description(void) const
{
    return "axlFieldSpatialWriter";
}

QStringList axlFieldSpatialWriter::handled(void) const
{
    return QStringList() << "axlAbstractField";
}

bool axlFieldSpatialWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldSpatialWriter", QStringList(), createaxlFieldSpatialWriter);
}

bool axlFieldSpatialWriter::accept(dtkAbstractData *data)
{
    axlAbstractField *spatialField = dynamic_cast<axlAbstractField *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldSpatialWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldSpatialWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlAbstractField *field = dynamic_cast<axlAbstractField *>(data);

    QDomElement fieldElement = doc->createElement("field");
    //Three kind of field : discrete, spatial and parametric.
    if(dynamic_cast<axlAbstractFieldSpatial *>(field))
        fieldElement.setAttribute("type", "spatial");
    else if(dynamic_cast<axlAbstractFieldParametric *>(field))
        fieldElement.setAttribute("type", "parametric");
    else
        fieldElement.setAttribute("type", "discrete");

    /////Name
    fieldElement.setAttribute("name", field->name());



    //Support
    int fieldSupport= field->support();
    if(fieldSupport == 1)
        fieldElement.setAttribute("support", "point");
    else if (fieldSupport == 2)
        fieldElement.setAttribute("support", "cell");
    else
        fieldElement.setAttribute("support", "custom");

    //Kind
    int fieldKind= field->kind();
    if(fieldKind == 1)
        fieldElement.setAttribute("kind", "scalar");
    else if (fieldKind == 2)
        fieldElement.setAttribute("kind", "vector");
    else
        fieldElement.setAttribute("kind", "tensor");

    //Type
    int fieldType= field->type();
    if(fieldType == 1)
        fieldElement.setAttribute("type", "int");
    else if (fieldType == 2)
        fieldElement.setAttribute("type", "float");
    else
        fieldElement.setAttribute("type", "double");


    //not necessary to write field value except if it is of type field discrete
    int size = field->size();
    QString fieldsText;
    if(axlAbstractFieldDiscrete *fieldD = dynamic_cast<axlAbstractFieldDiscrete *>(field) ){

        if(fieldKind == 1)
            for(int i = 0 ; i < size; i++)
                QTextStream(&fieldsText) << "\n" << QString::number(fieldD->scalar(i));
        else if(fieldKind == 2)
            for(int i = 0 ; i < size; i++)
                QTextStream(&fieldsText) << "\n" << QString::number((fieldD->vector(i))[0]) << " "<< QString::number((fieldD->vector(i))[1]) << " "<< QString::number((fieldD->vector(i))[2]);

    }
    QDomText fieldsDomText = doc->createTextNode(fieldsText);
    fieldElement.appendChild(fieldsDomText);

    //precise the object name on which the field is applied. (its parent )
    fieldElement.setAttribute("parent", dynamic_cast<axlAbstractData *>(field->parent())->name());

    //if parametric field , we need to know the fonction
    //problem : the BSpline function is not inserted in the object manager.
    if(axlAbstractFieldParametric *paramField = dynamic_cast<axlAbstractFieldParametric *>(field)){
        //fieldElement.setAttribute("fonctionBSpline", paramField->getFunctionBSpline()->objectName());

        //TO DO
    }

    //if the field has some parameters.
    // TO DO
    int res = dynamic_cast<QMetaObject *>(field)->indexOfMethod("setParameter");
    fieldElement.setAttribute("res",QString::number(res));
    if(res == -1)
        qDebug()<< "no parameter values to write";
    else{
        //we must know the number of parameters.
        int arg_count = 0;
    }

    return fieldElement;
}



QDomElement axlFieldSpatialWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldSpatialWriter(void)
{
    return new axlFieldSpatialWriter;
}


