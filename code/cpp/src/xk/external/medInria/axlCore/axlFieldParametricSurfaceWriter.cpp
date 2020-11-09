/* axlFieldParametricSurfaceWriter.cpp ---
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

#include "axlFieldParametricSurfaceWriter.h"

#include <axlCore/axlFieldParametricSurface.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceWriter
// /////////////////////////////////////////////////////////////////

axlFieldParametricSurfaceWriter::axlFieldParametricSurfaceWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldParametricSurfaceWriter::~axlFieldParametricSurfaceWriter(void)
{

}

QString axlFieldParametricSurfaceWriter::identifier(void) const
{
    return "axlFieldParametricSurfaceWriter";
}

QString axlFieldParametricSurfaceWriter::description(void) const
{
    return "axlFieldParametricSurfaceWriter";
}

QStringList axlFieldParametricSurfaceWriter::handled(void) const
{
    return QStringList() <<  "axlFieldParametricSurface";
}

bool axlFieldParametricSurfaceWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldParametricSurfaceWriter", QStringList(), createaxlFieldParametricSurfaceWriter);
}

bool axlFieldParametricSurfaceWriter::accept(dtkAbstractData *data)
{
    axlFieldParametricSurface *spatialField = dynamic_cast<axlFieldParametricSurface *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldParametricSurfaceWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldParametricSurfaceWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldParametricSurface *field = dynamic_cast<axlFieldParametricSurface *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    ////Field Type
    if(field->type() == axlFieldParametricSurface::Int){
        fieldElement.setAttribute("valueType", "int");
    }else if(field->type() == axlFieldParametricSurface::Float){
        fieldElement.setAttribute("valueType", "float");
    }else{
        fieldElement.setAttribute("valueType", "double");
    }


    ////Field Support
    if(field->support() == axlFieldParametricSurface::Point){
        fieldElement.setAttribute("support", "point");
    }else if(field->support() == axlFieldParametricSurface::Cell){
        fieldElement.setAttribute("support", "cell");
    }else{
        fieldElement.setAttribute("support", "custom");
    }

    ////Field Kind
    if(field->kind() == axlFieldParametricSurface::Scalar){
        fieldElement.setAttribute("kind", "scalar");
    }else if(field->kind() == axlFieldParametricSurface::Vector){
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



QDomElement axlFieldParametricSurfaceWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldParametricSurfaceWriter(void)
{
    return new axlFieldParametricSurfaceWriter;
}

