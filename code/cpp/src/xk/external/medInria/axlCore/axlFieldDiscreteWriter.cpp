/* axlFieldDiscreteWriter.cpp ---
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

#include "axlFieldDiscreteWriter.h"

#include "axlFieldDiscrete.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldDiscreteWriter
// /////////////////////////////////////////////////////////////////

axlFieldDiscreteWriter::axlFieldDiscreteWriter(void):axlAbstractDataWriter()
{
    this->setObjectName(this->description());
}

axlFieldDiscreteWriter::~axlFieldDiscreteWriter(void)
{

}

QString axlFieldDiscreteWriter::identifier(void) const
{
    return "axlFieldDiscreteWriter";
}

QString axlFieldDiscreteWriter::description(void) const
{
    return "axlFieldDiscreteWriter";
}

QStringList axlFieldDiscreteWriter::handled(void) const
{
    return QStringList() << "axlAbstractField" << "axlAbstractFieldDiscrete" << "axlFieldDiscrete";
}

bool axlFieldDiscreteWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlFieldDiscreteWriter", QStringList(), createaxlFieldDiscreteWriter);
}

bool axlFieldDiscreteWriter::accept(dtkAbstractData *data)
{
    axlFieldDiscrete *spatialField = dynamic_cast<axlFieldDiscrete *>(data);
    if(spatialField)
        return true;

    return false;
}

bool axlFieldDiscreteWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlFieldDiscreteWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlFieldDiscrete *field = dynamic_cast<axlFieldDiscrete *>(data);

    QDomElement fieldElement = doc->createElement("field");

    /////Type
    fieldElement.setAttribute("type", field->identifier());

    ////Count
    fieldElement.setAttribute("count", QString::number(field->size()));

    ////Dimension
    if(field->kind() == axlFieldDiscrete::Scalar){
        fieldElement.setAttribute("dimension", QString::number(1));
    }else if(field->kind() == axlFieldDiscrete::Vector){
        fieldElement.setAttribute("dimension", QString::number(3));
    }else{
        fieldElement.setAttribute("dimension", QString::number(9));
    }

    ////Support
    if(field->support() == axlFieldDiscrete::Point){
        fieldElement.setAttribute("support", "point");
    }else if(field->support() == axlFieldDiscrete::Cell){
        fieldElement.setAttribute("support", "cell");
    }else{
        fieldElement.setAttribute("support", "custom");
    }

    ////Values
    QString fieldsText;
    if(field->kind() == axlFieldDiscrete::Scalar)
        for(int i = 0 ; i < field->size(); i++)
            QTextStream(&fieldsText) << "\n  " << QString::number(field->scalar(i));
    else if(field->kind() == axlFieldDiscrete::Vector)
        for(int i = 0 ; i < field->size(); i++)
            QTextStream(&fieldsText) << "\n  " << QString::number((field->vector(i))[0]) << " "<< QString::number((field->vector(i))[1]) << " "<< QString::number((field->vector(i))[2]);
    else if(field->kind() == axlFieldDiscrete::Tensor)
        for(int i = 0 ; i < field->size(); i++)
            QTextStream(&fieldsText) << "\n  " << QString::number((field->tensor(i))[0]) << " "<< QString::number((field->tensor(i))[1]) << " "<< QString::number((field->tensor(i))[2])<< " "<< QString::number((field->tensor(i))[3])<< " "<< QString::number((field->tensor(i))[4])<< " "<< QString::number((field->tensor(i))[5])<< " "<< QString::number((field->tensor(i))[6])<< " "<< QString::number((field->tensor(i))[7])<< " "<< QString::number((field->tensor(i))[8]);



    QTextStream(&fieldsText)<< "\n"; // for easy read of the file
    QDomText fieldsDomText = doc->createTextNode(fieldsText);
    fieldElement.appendChild(fieldsDomText);

    return fieldElement;
}



QDomElement axlFieldDiscreteWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlFieldDiscreteWriter(void)
{
    return new axlFieldDiscreteWriter;
}

