/* axlFieldDiscreteReader.cpp ---
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

#include "axlFieldDiscreteReader.h"
#include <axlCore/axlReader.h>

#include <axlCore/axlAbstractField.h>
#include "axlFieldDiscrete.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

// /////////////////////////////////////////////////////////////////
// axlFieldDiscreteReader
// /////////////////////////////////////////////////////////////////

axlFieldDiscreteReader::axlFieldDiscreteReader(void):axlAbstractDataReader()
{
    this->setObjectName(this->description());
}

axlFieldDiscreteReader::~axlFieldDiscreteReader(void)
{

}

QString axlFieldDiscreteReader::identifier(void) const
{
    return "axlFieldDiscreteReader";
}

QString axlFieldDiscreteReader::description(void) const
{
    return "axlFieldDiscreteReader";
}

QStringList axlFieldDiscreteReader::handled(void) const
{
    return QStringList() << "axlFieldDiscrete";
}

bool axlFieldDiscreteReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlFieldDiscreteReader", QStringList(), createaxlFieldDiscreteReader);
}

bool axlFieldDiscreteReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "field")
        return false;

    return true;
}

bool axlFieldDiscreteReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}


//read only one special field :axlFieldDiscrete.
axlAbstractData *axlFieldDiscreteReader::read(const QDomNode& node)
{

    QDomElement element = node.toElement();
    axlFieldDiscrete *field = NULL;

    // field type : the type corresponds to the identifier, use factory to initialize field.
    //    QString type = element.attribute("type");
    //    if(!type.isEmpty())
    //    {
    //        field = dynamic_cast<axlFieldDiscrete *>(dtkAbstractDataFactory::instance()->create(type));
    //    }

    ////Count
    QString count = element.attribute("count");
    int countNumb = 0;
    if(!count.isEmpty()){
        countNumb = count.toInt();
        //field->setSize(count.toInt());
    }

    ////Dimension
    QString dimension = element.attribute("dimension");
    axlFieldDiscrete::Kind kind = axlFieldDiscrete::Scalar;
    if(!dimension.isEmpty()){
        int dim = dimension.toInt();
        if(dim == 1){
            //field->setKind(axlFieldDiscrete::Scalar);
            kind = axlFieldDiscrete::Scalar;
        }else if(dim == 3){
            //field->setKind(axlFieldDiscrete::Vector);
            kind = axlFieldDiscrete::Vector;
        }else{
            //field->setKind(axlFieldDiscrete::Tensor);
            kind = axlFieldDiscrete::Tensor;
        }
    }

    ////Support
    QString support = element.attribute("support");
    axlFieldDiscrete::Support supportName = axlFieldDiscrete::Point;
    if(!support.isEmpty()){
        if(support == "point"){
            //field->setSupport(axlFieldDiscrete::Point);
            supportName = axlFieldDiscrete::Point;
        }else if(support == "cell"){
            //field->setSupport(axlFieldDiscrete::Cell);
            supportName = axlFieldDiscrete::Cell;
        }else{
            //field->setSupport(axlFieldDiscrete::Custom);
            supportName = axlFieldDiscrete::Custom;
        }
    }

    ////name
    QString name = element.attribute("name");
    if(name.isEmpty()){
        name = "axlFieldDiscrete";
    }


    field = new axlFieldDiscrete(name,axlFieldDiscrete::Double,kind,supportName, countNumb);
    field->setSize(countNumb);
    field->setKind(kind);
    field->setSupport(supportName);
    field->setType(axlFieldDiscrete::Double);

    ////Values
    double s = 0.0;
    double vx = 0.0;
    double vy = 0.0;
    double vz = 0.0;
    double v1 = 0.0;
    double v2 = 0.0;
    double v3 = 0.0;
    double v4 = 0.0;
    double v5 = 0.0;
    double v6 = 0.0;
    double v7 = 0.0;
    double v8 = 0.0;
    double v9 = 0.0;
    QString *text_fields;
    int size = field->size();
    text_fields = new QString(element.text());

    QTextStream in_fields(text_fields);

    if(field->kind()== axlFieldDiscrete::Scalar)
    {
        for(int i = 0 ; i < size ; i++)
        {
            in_fields.skipWhiteSpace();
            in_fields >> s;
            field->setScalar(i, s);
        }
    }
    else if(field->kind()== axlFieldDiscrete::Vector)
    {
        for(int i = 0 ; i < size ; i++)
        {
            in_fields.skipWhiteSpace();
            in_fields >> vx;
            in_fields.skipWhiteSpace();
            in_fields >> vy;
            in_fields.skipWhiteSpace();
            in_fields >> vz;
            field->setVector(i, vx, vy, vz);
        }
    }else{

        for(int i = 0 ; i < size ; i++)
        {
            in_fields.skipWhiteSpace();
            in_fields >> v1;
            in_fields.skipWhiteSpace();
            in_fields >> v2;
            in_fields.skipWhiteSpace();
            in_fields >> v3;
            in_fields.skipWhiteSpace();
            in_fields >> v4;
            in_fields.skipWhiteSpace();
            in_fields >> v5;
            in_fields.skipWhiteSpace();
            in_fields >> v6;
            in_fields.skipWhiteSpace();
            in_fields >> v7;
            in_fields.skipWhiteSpace();
            in_fields >> v8;
            in_fields.skipWhiteSpace();
            in_fields >> v9;
            field->setTensor(i, v1, v2, v3, v4, v5, v6, v7, v8, v9);
        }
    }

    field->update();
    delete text_fields;
    return field;

}

//dtkAbstractData *axlFieldDiscreteReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
//{
//    if(!axl_reader)
//        return NULL;

//    if(!axl_reader->accept(node))
//        return NULL;

//    axl_reader->dtkAbstractDataReader::read(this->file());

//    if(dtkAbstractData *data = axl_reader->read(node))
//        return data;


//    return NULL;
//}



dtkAbstractDataReader *createaxlFieldDiscreteReader(void)
{
    return new axlFieldDiscreteReader;
}
