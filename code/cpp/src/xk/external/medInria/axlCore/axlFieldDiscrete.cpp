/* axlFieldDiscrete.cpp ---
 *
 * Author: Thibaud Kloczko
 * Copyright (C) 2008 - Thibaud Kloczko, Inria.
 * Created: Wed Jul 28 11:22:28 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Oct 25 09:55:32 2011 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 355
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */
#include <sstream>

#include "axlFieldDiscrete.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class axlFieldDiscretePrivate
{
public:

    QVector<int> arrayInt;
    QVector<float> arrayFloat;
    QVector<double> arrayDouble;

    int size;
};

// /////////////////////////////////////////////////////////////////
// axlFieldDiscrete implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldDiscrete::axlFieldDiscrete() : axlAbstractFieldDiscrete(),  d(new axlFieldDiscretePrivate)
{
    this->setObjectName(this->identifier());
    d->size = 0;
}

/*!
 *
 */
axlFieldDiscrete::axlFieldDiscrete(QString name, Type type, Kind kind, Support support, int size) :  axlAbstractFieldDiscrete(name, type, kind, support, size),  d(new axlFieldDiscretePrivate)
{
    this->setType(type);
    this->setKind(kind);
    this->setObjectName(name);
    d->size = size;
    this->setSupport(support);
}

//! Destroys the discrete field.
/*!
 *
 */
axlFieldDiscrete::~axlFieldDiscrete(void)
{
    delete d;

    d = NULL;
}

bool axlFieldDiscrete::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataType("axlFieldDiscrete", createaxlFieldDiscrete);
}

//!
/*!
 *  Set a scalar element \a v1 at \a index location in the scalar data array.
 */
void axlFieldDiscrete::setScalar(int index, double v1)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Setting scalar value on non scalar field.";
        return;
    }

    if(this->type() == Int){
        if(d->arrayInt.size() >= index+1 ){
            d->arrayInt.replace(index, v1);
        }else if(d->arrayInt.size() == index){
            d->arrayInt.push_back(v1);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
        }
    }else if(this->type() == Float){
        if(d->arrayFloat.size() >= index+1 ){
            d->arrayFloat.replace(index, v1);
        }else if(d->arrayFloat.size() == index){
            d->arrayFloat.push_back(v1);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
        }
    }else if(this->type() == Double){
        if(d->arrayDouble.size() >= index+1 ){
            d->arrayDouble.replace(index, v1);
        }else if(d->arrayDouble.size() == index){
            d->arrayDouble.push_back(v1);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
        }
    }else{
        qDebug() << Q_FUNC_INFO << "This type doesn't exists";
    }
}

//!
/*!
 *  Set a vector element (\a v1, \a v2, \a v3) at \a index location in the vector data array.
 */
void axlFieldDiscrete::setVector(int index, double v1, double v2, double v3)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Setting vector value on non vector field.";
        return;
    }

//    if(!(d->size%3 == 0) /*|| !(index%3==0)*/){
//        qDebug() << Q_FUNC_INFO << "Error  : cannot be divided by 3";
//        return;
//    }

    if(this->type() == Int){
        if(d->arrayInt.size() >= 3*(index+1)){
            d->arrayInt.replace(index, v1);
            d->arrayInt.replace(index+1, v2);
            d->arrayInt.replace(index+2, v3);
        }else if(d->arrayInt.size() == 3*index){
            d->arrayInt.push_back(v1);
            d->arrayInt.push_back(v2);
            d->arrayInt.push_back(v3);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else if(this->type() == Float){
        if(d->arrayFloat.size() >= 3*(index+1) ){
            d->arrayFloat.replace(index, v1);
            d->arrayFloat.replace(index+1, v2);
            d->arrayFloat.replace(index+2, v3);
        }else if(d->arrayFloat.size() == 3*index){
            d->arrayFloat.push_back(v1);
            d->arrayFloat.push_back(v2);
            d->arrayFloat.push_back(v3);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else if(this->type() == Double){
        if(d->arrayDouble.size() >= 3*(index+1) ){
            d->arrayDouble.replace(index, v1);
            d->arrayDouble.replace(index+1, v2);
            d->arrayDouble.replace(index+2, v3);
        }else if(d->arrayDouble.size() == 3*index){
            d->arrayDouble.push_back(v1);
            d->arrayDouble.push_back(v2);
            d->arrayDouble.push_back(v3);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else{
        qDebug() << Q_FUNC_INFO << "This type doesn't exists";
        return;
    }
}

//!
/*!
 *  Set a tensor element (\a v1, \a v2, \a v3, \a v4, \a v5, \a v6, \a v7, \a v8, \a v9)
 *  at \a index location in the tensor data array.
 */
void axlFieldDiscrete::setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Setting tensor value on non tensor field.";
        return;
    }

    if(!(d->size%9 == 0) /*|| !(index%9 == 0)*/){
        qDebug() << Q_FUNC_INFO << "Error  : cannot be divided by 9";
        return;
    }

    if(this->type() == Int){
        if(d->arrayInt.size() >= 9*(index+1)){
            d->arrayInt.replace(index, v1);
            d->arrayInt.replace(index+1, v2);
            d->arrayInt.replace(index+2, v3);
            d->arrayInt.replace(index+3, v4);
            d->arrayInt.replace(index+4, v5);
            d->arrayInt.replace(index+5, v6);
            d->arrayInt.replace(index+6, v7);
            d->arrayInt.replace(index+7, v8);
            d->arrayInt.replace(index+8, v9);
        }else if(d->arrayInt.size() == 9*index){
            d->arrayInt.push_back(v1);
            d->arrayInt.push_back(v2);
            d->arrayInt.push_back(v3);
            d->arrayInt.push_back(v4);
            d->arrayInt.push_back(v5);
            d->arrayInt.push_back(v6);
            d->arrayInt.push_back(v7);
            d->arrayInt.push_back(v8);
            d->arrayInt.push_back(v9);

        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else if(this->type() == Float){
        if(d->arrayFloat.size() >= 9*(index+1) ){
            d->arrayFloat.replace(index, v1);
            d->arrayFloat.replace(index+1, v2);
            d->arrayFloat.replace(index+2, v3);
            d->arrayFloat.replace(index+3, v4);
            d->arrayFloat.replace(index+4, v5);
            d->arrayFloat.replace(index+5, v6);
            d->arrayFloat.replace(index+6, v7);
            d->arrayFloat.replace(index+7, v8);
            d->arrayFloat.replace(index+8, v9);
        }else if(d->arrayFloat.size() == 9*index){
            d->arrayFloat.push_back(v1);
            d->arrayFloat.push_back(v2);
            d->arrayFloat.push_back(v3);
            d->arrayFloat.push_back(v4);
            d->arrayFloat.push_back(v5);
            d->arrayFloat.push_back(v6);
            d->arrayFloat.push_back(v7);
            d->arrayFloat.push_back(v8);
            d->arrayFloat.push_back(v9);
        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else if(this->type() == Double){
        if(d->arrayDouble.size() >= 9*(index+1) ){
            d->arrayDouble.replace(index, v1);
            d->arrayDouble.replace(index+1, v2);
            d->arrayDouble.replace(index+2, v3);
            d->arrayDouble.replace(index+3, v4);
            d->arrayDouble.replace(index+4, v5);
            d->arrayDouble.replace(index+5, v6);
            d->arrayDouble.replace(index+6, v7);
            d->arrayDouble.replace(index+7, v8);
            d->arrayDouble.replace(index+8, v9);
        }else if(d->arrayDouble.size() == 9*index){
            d->arrayDouble.push_back(v1);
            d->arrayDouble.push_back(v2);
            d->arrayDouble.push_back(v3);
            d->arrayDouble.push_back(v4);
            d->arrayDouble.push_back(v5);
            d->arrayDouble.push_back(v6);
            d->arrayDouble.push_back(v7);
            d->arrayDouble.push_back(v8);
            d->arrayDouble.push_back(v9);

        }else{
            qDebug() << Q_FUNC_INFO << "The array vector is not well filled";
            return;
        }
    }else{
        qDebug() << Q_FUNC_INFO << "This type doesn't exists";
        return;
    }
}

int axlFieldDiscrete::size(void)
{
    return d->size;
}

void axlFieldDiscrete::setSize(int size)
{
    d->size = size;

}

//! Returns the value at \a index location of the scalar array.
/*!
 *
 */
double axlFieldDiscrete::scalar(int index)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Getting scalar value on non scalar field.";
        return 0;
    }

    if(this->type() == Int){
        return d->arrayInt.at(index);
    }else if(this->type() == Float){
        return d->arrayFloat.at(index);
    }else if(this->type() == Double){
        return d->arrayDouble.at(index);
    }else{
        qDebug() << "No return value.";
        return 0;
    }
}

//! Returns the value at \a index location of the vector array.
/*!
 *
 */
double *axlFieldDiscrete::vector(int index)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }

    double* result = new double[3];

    if(this->type() == Int){
        result[0] = d->arrayInt.at(index);
        result[1] = d->arrayInt.at(index+1);
        result[2] = d->arrayInt.at(index+2);
        return result;
    }else if(this->type() == Float){
        result[0] = d->arrayFloat.at(index);
        result[1] = d->arrayFloat.at(index+1);
        result[2] = d->arrayFloat.at(index+2);
        return result;
    }else if(this->type() == Double){
        result[0] = d->arrayDouble.at(index);
        result[1] = d->arrayDouble.at(index+1);
        result[2] = d->arrayDouble.at(index+2);
        return result;
    }else{
        qDebug() << "No return value.";
        return NULL;
    }
}

//! Returns the value at \a index location of the tensor array.
/*!
 *
 */
double *axlFieldDiscrete::tensor(int index)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Getting tensor value on non tensor field.";
        return NULL;
    }

    double* result = new double[9];

    if(this->type() == Int){
        result[0] = d->arrayInt.at(index);
        result[1] = d->arrayInt.at(index+1);
        result[2] = d->arrayInt.at(index+2);
        result[3] = d->arrayInt.at(index+3);
        result[4] = d->arrayInt.at(index+4);
        result[5] = d->arrayInt.at(index+5);
        result[6] = d->arrayInt.at(index+6);
        result[7] = d->arrayInt.at(index+7);
        result[8] = d->arrayInt.at(index+8);
        return result;
    }else if(this->type() == Float){
        result[0] = d->arrayFloat.at(index);
        result[1] = d->arrayFloat.at(index+1);
        result[2] = d->arrayFloat.at(index+2);
        result[3] = d->arrayFloat.at(index+3);
        result[4] = d->arrayFloat.at(index+4);
        result[5] = d->arrayFloat.at(index+5);
        result[6] = d->arrayFloat.at(index+6);
        result[7] = d->arrayFloat.at(index+7);
        result[8] = d->arrayFloat.at(index+8);
        return result;
    }else if(this->type() == Double){
        result[0] = d->arrayDouble.at(index);
        result[1] = d->arrayDouble.at(index+1);
        result[2] = d->arrayDouble.at(index+2);
        result[3] = d->arrayDouble.at(index+3);
        result[4] = d->arrayDouble.at(index+4);
        result[5] = d->arrayDouble.at(index+5);
        result[6] = d->arrayDouble.at(index+6);
        result[7] = d->arrayDouble.at(index+7);
        result[8] = d->arrayDouble.at(index+8);
        return result;
    }else{
        qDebug() << "No return value.";
        return NULL;
    }
}

////! Returns the name the field.
///*!
// *
// */
//QString axlFieldDiscrete::name(void)
//{
//    if(d->array)
//        return QString(d->array->GetName());

//    return QString() ;
//}

////! Returns the name the field.
///*!
// *
// */
//void axlFieldDiscrete::setName(QString name)
//{
//    if(d->array)
//        d->array->SetName(name.toAscii().constData());

//}

//! Returns the description of the field.
/*!
 *
 */
QString axlFieldDiscrete::description(void) const
{
    qDebug()<< "axlFieldDiscrete::description";


    QString qstr;

    qstr.append("Name : ");
    qstr.append(this->objectName());

    //    switch(this->type()) {
    //    case axlFieldDiscrete::Int:
    //        qstr.append(";Type : integer");
    //        break;
    //    case axlFieldDiscrete::Float:
    //        qstr.append(";Type : Float");
    //        break;
    //    case axlFieldDiscrete::Double:
    //        qstr.append(";Type : Double");
    //        break;
    //    default:
    //        qDebug() << "Unsupported field type";
    //    }


    //    switch(this->kind()) {
    //    case axlFieldDiscrete::Scalar:
    //        qstr.append(";Kind : Scalar");
    //        break;
    //    case axlFieldDiscrete::Vector:
    //        qstr.append(";Kind : Vector");
    //        break;
    //    case axlFieldDiscrete::Tensor:
    //        qstr.append(";Kind : Tensor");
    //        break;
    //    default:
    //        qDebug() << ";Unsupported field kind";
    //    }

    //    axlAbstractField::Support support; /*;= dynamic_cast<axlAbstractField *>(this)->support();*/
    //    switch(support) {
    //    case axlFieldDiscrete::Point:
    //        qstr.append(";Support : Point");
    //        break;
    //    case axlFieldDiscrete::Cell:
    //        qstr.append(";Support : Cell");
    //        break;
    //    case axlFieldDiscrete::Custom:
    //        qstr.append(";Support : Custom");
    //        break;
    //    default:
    //        qDebug() << ";No support";
    //    }

    // créer un flux de sortie
    std::ostringstream oss;
    // écrire un nombre dans le flux
    // récupérer une chaîne de caractères
    // qstr.append(";Size :"+this ->size());


    qstr.append(";Size : ");
    int s = d->size;
    qstr.append(QString::number(s));

    return qstr;

}

//! Returns the identifier "axlFieldDiscrete".
/*!
 *
 */
QString axlFieldDiscrete::identifier(void) const
{
    return "axlFieldDiscrete";
}

//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldDiscrete::update(void)
{
    //d->array->Modified();

    emit updated();
}

////! Returns a void pointer to the underlying vtkDataArray object.
///*!
// *
// */
//void *axlFieldDiscrete::array(void)
//{
//    if(this->type == Int){
//        return d->arrayInt;
//    }else if(this->type == Float){
//        return d->arrayFloat;
//    }else{
//        return d->arrayDouble;
//    }
//}



// /////////////////////////////////////////////////////////////////
// axlFieldDiscrete documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldDiscrete
 *
 *  \brief Class axlFieldDiscrete defines an API for arrays of numeric data.
 *
 *  This class, based on a wrapping of vtkDataArray class, enables
 *  to deal with different type (int, float or double) and different
 *  kind (scalar, vector, tensor) of data.
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldDiscrete(void)
{
    return new axlFieldDiscrete();
}
