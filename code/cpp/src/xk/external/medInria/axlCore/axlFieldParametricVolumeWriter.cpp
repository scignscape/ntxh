/* axlFieldParametricVolumeWriter.cpp ---
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

#include "axlFieldParametricVolumeWriter.h"

#include <axlCore/axlFieldParametricVolume.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricVolumeWriter::axlFieldParametricVolumeWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricVolumeWriter::~axlFieldParametricVolumeWriter(void)
{

}

QString axlFieldParametricVolumeWriter::identifier(void) const
{
    return "axlFieldParametricVolumeWriter";
}

QString axlFieldParametricVolumeWriter::description(void) const
{
    return "axlFieldParametricVolumeWriter";
}

QStringList axlFieldParametricVolumeWriter::handled(void) const
{
    return QStringList() <<  "axlFieldParametricVolume";
}

bool axlFieldParametricVolumeWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricVolumeWriter", QStringList(), createaxlFieldParametricVolumeWriter);
}

bool axlFieldParametricVolumeWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricVolume *spatialField = dynamic_cast<axlFieldParametricVolume *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricVolumeWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricVolumeWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricVolume *field = dynamic_cast<axlFieldParametricVolume *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    ////Field Type
    if(field->type() == axlFieldParametricVolume::Int){
        fieldElement.setAttribute("valueType", "int");
    }else if(field->type() == axlFieldParametricVolume::Float){
        fieldElement.setAttribute("valueType", "float");
    }else{
        fieldElement.setAttribute("valueType", "double");
    }


    ////Field Support
    if(field->support() == axlFieldParametricVolume::Point){
        fieldElement.setAttribute("support", "point");
    }else if(field->support() == axlFieldParametricVolume::Cell){
        fieldElement.setAttribute("support", "cell");
    }else{
        fieldElement.setAttribute("support", "custom");
    }

    ////Field Kind
    if(field->kind() == axlFieldParametricVolume::Scalar){
        fieldElement.setAttribute("kind", "scalar");
    }else if(field->kind() == axlFieldParametricVolume::Vector){
        fieldElement.setAttribute("kind", "vector");
    }else{
        fieldElement.setAttribute("kind", "tensor");
    }

    ////Parametric Function
    axlAbstractDataWriter *function_writer = dynamic_cast<axlAbstractDataWriter *>(dtkAbstractDataFactory::instance()->writer(field->getFunction()->identifier()+"Writer"));
    qDebug() << Q_FUNC_INFO << field->getFunction()->identifier();
    if(function_writer){
        qDebug() << Q_FUNC_INFO << "writer found for function";
        QDomElement functionElement = function_writer->write(doc, field->getFunction());
        fieldElement.appendChild(functionElement);
    }


    return fieldElement;
}



QDomElement axlFieldParametricVolumeWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricVolumeWriter(void)
{
    return new axlFieldParametricVolumeWriter;
}


