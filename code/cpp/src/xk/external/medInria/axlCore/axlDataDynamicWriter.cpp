/* axlDataDynamicWriter.cpp ---
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

#include "axlDataDynamicWriter.h"

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractField.h>

#include <dtkCoreSupport/dtkAbstractData.h>

#include <axlCore/axlAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <axlCore/axlFieldWritersFactory.h>

// /////////////////////////////////////////////////////////////////
// axlDataDynamicWriter
// /////////////////////////////////////////////////////////////////

axlDataDynamicWriter::axlDataDynamicWriter(void)
{
    this->setObjectName(this->description());
}

axlDataDynamicWriter::~axlDataDynamicWriter(void)
{

}

QString axlDataDynamicWriter::identifier(void) const
{
    return "axlDataDynamicWriter";
}

QString axlDataDynamicWriter::description(void) const
{
    return "axlDataDynamicWriter";
}

QStringList axlDataDynamicWriter::handled(void) const
{
    return QStringList() << "axlDataDynamic";
}

bool axlDataDynamicWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("axlDataDynamicWriter", QStringList(), createaxlDataDynamicWriter);
}

bool axlDataDynamicWriter::accept(dtkAbstractData *data)
{
    axlDataDynamic *dataDynamic = dynamic_cast<axlDataDynamic *>(data);
    if(dataDynamic)
        return true;

    return false;
}

bool axlDataDynamicWriter::reject(dtkAbstractData *data)
{
    return !this->accept(data);
}

QDomElement axlDataDynamicWriter::write(QDomDocument *doc, dtkAbstractData *data)
{
    axlDataDynamic *dataDynamic = dynamic_cast<axlDataDynamic *>(data);

    /////Name
    //QDomElement dataDynamicElement = doc->createElement("dataDynamic");
    QDomElement dataDynamicElement = doc->createElement("process");
    //dataDynamicElement.setAttribute("name",dataDynamic->name());
    dataDynamicElement.setAttribute("type", dataDynamic->process()->identifier());
    if(dataDynamic->getType() == axlDataDynamic::Static){
        dataDynamicElement.setAttribute("status", "static");
    }else{
        dataDynamicElement.setAttribute("status", "dynamic");
    }
    dataDynamicElement.setAttribute("name", dataDynamic->name());

    /////Size
    //dataDynamicElement.setAttribute("size", QString::number(dataDynamic->size()));

    //    ////Color
    //    QColor qcolor = dataDynamic->color();
    //    QString color ;
    //    QTextStream(&color) << QString::number(qcolor.red()) << " "
    //                        << QString::number(qcolor.green()) << " "
    //                        << QString::number(qcolor.blue())<< " "
    //                        << QString::number(dataDynamic->opacity());
    //    dataDynamicElement.setAttribute("color", color);

    //    ////Shader
    //    QString shader = dataDynamic->shader();
    //    QFileInfo shaderFileInfo(shader);
    //    dataDynamicElement.setAttribute("shader", shaderFileInfo.fileName());

    //Write process name
    //dataDynamicElement.setAttribute("name_process", dataDynamic->process()->identifier());


    //Write inputs
    int channelCountDouble = 0;
    int channelCountData = 0;
    foreach(axlAbstractData *axlvalue, dataDynamic->inputs()){
        QDomElement newInput = doc->createElement("input");
        if(axlDouble *value = dynamic_cast<axlDouble *>(axlvalue)){
            newInput.setAttribute("value", value->value());
            newInput.setAttribute("type","double");
            //newInput.setAttribute("channel", QString::number(channelCountDouble));
            dataDynamicElement.appendChild(newInput);
            channelCountDouble++;

        }else {
            newInput.setAttribute("name", axlvalue->name());
            newInput.setAttribute("type", "data");
            //newInput.setAttribute("channel", QString::number(channelCountData));
            dataDynamicElement.appendChild(newInput);
            channelCountData++;
        }

    }


    //Write outputs
    for(int i = 0; i < dataDynamic->numberOfChannels();i++ ){
        QDomElement newOutput = doc->createElement("output");
        newOutput.setAttribute("name", dataDynamic->outputs(i)->name());

        ///Size
        newOutput.setAttribute("size", QString::number(dataDynamic->outputs()->size()));

        ////Color
        QColor qcolor = dataDynamic->outputs()->color();
        QString color ;
        QTextStream(&color) << QString::number(qcolor.red()) << " "
                            << QString::number(qcolor.green()) << " "
                            << QString::number(qcolor.blue())<< " "
                            << QString::number(dataDynamic->outputs()->opacity());
        newOutput.setAttribute("color", color);

        ////Shader
        QString shader = dataDynamic->outputs()->shader();
        QFileInfo shaderFileInfo(shader);
        newOutput.setAttribute("shader", shaderFileInfo.fileName());


        dataDynamicElement.appendChild(newOutput);

    }


    //Write fields if exist.
    if(!dataDynamic->fields().isEmpty()){
        foreach(axlAbstractField *field, dataDynamic->fields()){
            axlAbstractDataWriter *field_writer = dynamic_cast<axlAbstractDataWriter *>(axlFieldWritersFactory::instance()->create(field->identifier()));
            QDomElement fieldElement = field_writer->write(doc, field);
            dataDynamicElement.appendChild(fieldElement);
        }
    }

    return dataDynamicElement;
}



QDomElement axlDataDynamicWriter::elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data)
{
    QDomElement element;

    if(!axl_writer)
        return element;

    if(!axl_writer->accept(data))
        return element;

    element = axl_writer->write(doc, data);

    return element;
}

dtkAbstractDataWriter *createaxlDataDynamicWriter(void)
{
    return new axlDataDynamicWriter;
}

