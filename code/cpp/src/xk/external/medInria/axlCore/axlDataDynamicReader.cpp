/* axlDataDynamicReader.cpp ---
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

#include "axlDataDynamicReader.h"
#include "axlReader.h"

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlInteger.h>
#include <axlCore/axlDouble.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractProcess.h>

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcess>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <axlCore/axlAbstractDataReader.h>
#include <axlCore/axlFieldReadersFactory.h>

//#include <axlGui/axlInspectorToolFactory.h>

// /////////////////////////////////////////////////////////////////
// axlDataDynamicReader
// /////////////////////////////////////////////////////////////////

axlDataDynamicReader::axlDataDynamicReader(void)
{
    this->setObjectName(this->description());
}

axlDataDynamicReader::~axlDataDynamicReader(void)
{

}

QString axlDataDynamicReader::identifier(void) const
{
    return "axlDataDynamicReader";
}

QString axlDataDynamicReader::description(void) const
{
    return "axlDataDynamicReader";
}

QStringList axlDataDynamicReader::handled(void) const
{
    return QStringList() << "axlDataDynamic";
}

bool axlDataDynamicReader::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataReaderType("axlDataDynamicReader", QStringList(), createaxlDataDynamicReader);
}

bool axlDataDynamicReader::accept(const QDomNode& node)
{
    QDomElement element = node.toElement();

    if(element.tagName() != "process")
        return false;

    return true;
}

bool axlDataDynamicReader::reject(const QDomNode& node)
{
    return !this->accept(node);
}

axlAbstractData *axlDataDynamicReader::read(const QDomNode& node)
{


    QDomElement element = node.toElement();
    QString typeElement = element.attribute("status");


    //    if(typeElement == "dynamic")
    axlDataDynamic *currentData = new axlDataDynamic();

    QString status = element.attribute("status");
    if(!status.isEmpty()){
        if(status == "static"){
            currentData->setType(axlDataDynamic::Static);
        }
    }

    QString name = element.attribute("name");
    if(!name.isEmpty())
    {
        currentData->setObjectName(name);
    }

    QString color = element.attribute("color");
    if(!color.isEmpty())
    {
        QStringList colorList = color.split(" ");
        if(colorList.size() == 3) // rgb components
            currentData->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));

    }

    QString size = element.attribute("size");
    if(!size.isEmpty())
    {
        currentData->setSize(size.toDouble());
    }

    //Read Process
    QString processName = element.attribute("type");
    if(!processName.isEmpty())
    {        
        currentData->setProcess(processName);

    }
    //    //return the name of the data
    //    QString name_data = element.attribute("name");
    //    currentData->setObjectName(name_data);
    //    return currentData;

    /* }else{

        axlAbstractData *currentData = new axlAbstractData();
        return currentData;
    }*/


    //if there are some field, read them thanks to the factory.
    QDomNodeList nodeListField = element.elementsByTagName("field");
    if(!nodeListField.isEmpty()){
        for(int i =0; i < nodeListField.size(); i++){
            QDomElement fieldElement = nodeListField.at(i).toElement();
            QString fieldType = fieldElement.attribute("type");
            if(!fieldType.isEmpty()){
                axlAbstractDataReader *field_reader = dynamic_cast<axlAbstractDataReader *>(axlFieldReadersFactory::instance()->create(fieldType));
                axlAbstractField * fieldToAdd = dynamic_cast<axlAbstractField *>(field_reader->read(fieldElement));
                if(fieldToAdd){
                    currentData->addField(fieldToAdd);
                }
            }
        }
    }
    return currentData;


}

/**
 * @brief Construct an axlAbstractData from a node and a list of data.
 * @param data : axlDataDynamic object to be constructed.
 * @param node : node of the xml tree.
 * @param list : list of data already constructed.
 * @return the axlAbstractData constructed from the node and the object list.
 *
 ** The node should be of the form
 * @code
 * <process type="process_name" status="process_status">
 *   <input  .../> ...
 *   <parameter  .../> ...
 *   <output .../> ...
 * </process>
 * @endcode
 * where
 * - \c process_name is the identifier of the process to be called.
 * - \c process_status is either
 *   - \c dynamic for a dynamic data,
 *   - \c static  for a static data.
 * - \c <input  ... />... corresponds to the list (possibly empty) of inputs of the process.
 * - \c <parameter  ... />... corresponds to the list (possibly empty) of parameters of the process.
 * - \c <output ... />... corresponds to the list (possibly empty) of outputs of the process.
 *
 * The process will read its input, will setup its parameters and will compute outputs that will be stored in the
 * objects described in  the \c output list.
 *
 * The \c input, \c parameter, \c output items have the following tags:
 *  - \c type="type_of_object" which can be
 *     - \c data for an axlAbstractData object specified by the tag \c name="...",
 *     - \c double for a double value specified by the tag \c value="...",
 *     - \c int for a int value specified by the tag \c value="...".
 *  - \c name="name_of_an_object" to specify the name of the data to be used or to be computed.
 *  - \c channel="an_integer" to specify which input or parameter channel is used.
 *
 * Here is an example of an input assigned to be the axlPoint data named \c axlPoint1 on channel \c 2:
 * @code
 *   <input type="data" name="axlPoint1" channel="2" />
 * @endcode
 * The \c output items can have \c color and \c shader attributes to describe their rendering. Here
 * is an example of an output which will be named \c"surface0" and will appear in red:
 * @code
 *   <output name="surface0" color="255 0 0" />
 * @endcode
 *
 */
axlAbstractData *axlDataDynamicReader::readInputs(axlDataDynamic *data, const QDomNode& node, const QList<axlAbstractData *>& list)
{
    dtkWarn() << Q_FUNC_INFO<<list.size();
    QDomElement element = node.toElement();

    QDomNodeList nextChild = element.childNodes();

    QDomNodeList nodelistinput = element.elementsByTagName("input") ;

    // Read inputs
    for (int i = 0; i < nodelistinput.size(); i++) {
        QDomElement childElement = nodelistinput.at(i).toElement();
//        qDebug()<<"-- input"<<i;
        int channel = 0;
        // if(several_inputs) {
            // channel = num_inputs;
        // }
        if (!childElement.attribute("channel").isEmpty()) {
            channel=childElement.attribute("channel").toInt();
            // several_inputs = true;
        }

        QString typeChild = childElement.attribute("type");
//        qDebug()<<"--"<<typeChild;

        if (typeChild == "data") {
            QString nameInput = childElement.attribute("name");


            if (!list.isEmpty()) {
                bool input_found = false;
                for (int j = 0; j < list.size(); j++) {
//                    qDebug()<<"--"<<list.at(j)->name();
                    if (list.at(j)->name() == nameInput) {
                        dynamic_cast<axlDataDynamic *>(data)->setInput(list.at(j), channel); // append the input to the data dynamic

                        input_found=true;

                    } else if (axlDataDynamic *ddata = dynamic_cast<axlDataDynamic *>(list.at(j))) {

                        for (int i = 0; i < ddata->numberOfChannels(); i++) {
                            if(ddata->outputs(i)->name() == nameInput){
                                //                                if(isDynamicData)
                                dynamic_cast<axlDataDynamic *>(data)->setInput(ddata->outputs(i));
                                //                                else
                                //                                    if(several_inputs)
                                //                                        process->setInput(ddata->outputs(i), channel);
                                //                                    else
                                //                                        process->setInput(ddata->outputs(i));
                                input_found=true;
                            }
                        }
                    }
                }

                if(!input_found){
                    dtkWarn()<< "Input" << nameInput << "not found";
                }
            }
        } else if(typeChild == "double"){
            QString valueDouble = childElement.attribute("value");
            axlDouble *value = new axlDouble(valueDouble.toDouble());
            //            if(isDynamicData){
            dynamic_cast<axlDataDynamic *>(data)->setInput(value);
            //            }else{
            //                if(childElement.attribute("channel").isEmpty()){
            //                    process->setParameter(value->value());
            //                }else{
            //                    process->setParameter(value->value(), channel);
            //                }
            //            }
        }
    }

    // Read parameters
    QDomNodeList nodelistparam = element.elementsByTagName("parameter") ;
    bool several_params = (nodelistparam.size()>0);

    int num_params=0;
    for(int i = 0; i< nodelistparam.size();i++){

        QDomElement childElement = nodelistparam.at(i).toElement();
        int channel = 0;
        if(several_params) {
            channel = num_params;
        }
        if (!childElement.attribute("channel").isEmpty()) {
            channel=childElement.attribute("channel").toInt();
            several_params=true;
        }

        QString typeChild = childElement.attribute("type");

        /*if(typeChild == "data") {
            QString nameParam = childElement.attribute("name");
            if(!list.isEmpty()){
                for (int j = 0;j < list.size();j++){
                    if(list.at(j)->name() == nameParam){
                        if(several_params)
                            process->setParameter(list.at(j),channel);
                        else
                            process->setParameter(list.at(j));
                    }
                }
            }
        } else*/ if(typeChild == "double") {
            QString valueDouble = childElement.attribute("value");
            axlDouble *value = new axlDouble(valueDouble.toDouble());
            //            if(isDynamicData){
            dtkWarn() << Q_FUNC_INFO << 2;
            if(several_params)
                dynamic_cast<axlDataDynamic *>(data)->setParameter(valueDouble.toDouble(),channel);
            else
                dynamic_cast<axlDataDynamic *>(data)->setParameter(valueDouble.toDouble());
            dynamic_cast<axlDataDynamic *>(data)->setInput(value);

            //            } else {
            //                if(several_params)
            //                    process->setParameter(value->value(), channel);
            //                else
            //                    process->setParameter(value->value());
            //            }
        } else if(typeChild == "int") {
            QString valueInt = childElement.attribute("value");
            axlInteger *value = new axlInteger(valueInt.toInt());
            //            if(isDynamicData){
            dtkWarn()<<"Set parameter"<<valueInt<<num_params<<several_params;
            if(several_params)
                dynamic_cast<axlDataDynamic *>(data)->setParameter(valueInt.toInt(),channel);
            else
                dynamic_cast<axlDataDynamic *>(data)->setParameter(valueInt.toInt());

            dynamic_cast<axlDataDynamic *>(data)->setInput(value);
            //            } else {
            //                if(several_params)
            //                    process->setParameter(value->value(), channel);
            //                else
            //                    process->setParameter(value->value());
            //            }
            //        }
            num_params++;
        }
    }


    //    if(isDynamicData){

    // Compute the output
    QDomNodeList nodelistoutputs = element.elementsByTagName("output") ;

    QString typeProcess = element.attribute("type");

    dtkWarn() << Q_FUNC_INFO << typeProcess;

    if (!typeProcess.isEmpty()) {
        dynamic_cast<axlDataDynamic *>(data)->update();
        dtkWarn() << Q_FUNC_INFO << "update dynamic data";
        // on attribut le bon nom a chaque output
        //int num_inputs = dynamic_cast<axlDataDynamic *>(data)->inputs().size();

        for(int i = 0; i < dynamic_cast<axlDataDynamic *>(data)->numberOfChannels(); i++){
            //QDomElement childElement = nextChild.at(i+num_inputs).toElement();
            QDomElement childElement = nodelistoutputs.at(i).toElement();

            // QString nameOutput = childElement.attribute("name");
            // qDebug() << nameOutput;
            // dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setObjectName(nameOutput);

            QString color = childElement.attribute("color");
            if (!color.isEmpty()) {
                dtkWarn() << Q_FUNC_INFO << "color";
                QStringList colorList = color.split(" ");
                if (colorList.size() > 2) { // rgb components
                    dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
                    //dynamic_cast<axlDataDynamic *>(data)->setColor(QColor(colorList.at(0).toInt(), colorList.at(1).toInt(), colorList.at(2).toInt()));
                } else if(colorList.size() == 4) {
                    dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setOpacity(colorList.at(3).toFloat());
                    //dynamic_cast<axlDataDynamic *>(data)->setOpacity(colorList.at(3).toFloat());
                }
            }

            QString shader = childElement.attribute("shader");
            QString dirShader;
            if (!shader.isEmpty()) {
                // try to read from axelShader.qrc
                dirShader = ":axlShader/shader/"+shader;
                if (!QFile::exists(dirShader)) {
                    QSettings settings("inria", "dtk");
                    QString defaultPath;
                    settings.beginGroup("shader");
                    dirShader = settings.value("path", defaultPath).toString();
                    //            dirShader = this->file().left(this->file().lastIndexOf("axel-data") + 9); // to Remove later
                    dirShader.append("/"+shader);
                }
                dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setShader(dirShader);
                //dynamic_cast<axlDataDynamic *>(data)->setShader(dirShader);
            }

            QString size = childElement.attribute("size");
            if (!size.isEmpty()) {
                dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setSize(size.toFloat());
                //dynamic_cast<axlDataDynamic *>(data)->setSize(size.toFloat());
            }

            QString nameO = childElement.attribute("name");
            //qDebug() << nameO;

            if (!nameO.isEmpty()) {
                dynamic_cast<axlDataDynamic *>(data)->outputs(i)->setObjectName(nameO);
            }
        }
    }

    return data;
}

axlAbstractData *axlDataDynamicReader::dataByReader(axlAbstractDataReader *axl_reader, const QDomNode& node)
{
    if(!axl_reader)
        return NULL;

    if(!axl_reader->accept(node))
        return NULL;

    axl_reader->dtkAbstractDataReader::read(this->file());

    if(axlAbstractData *data = axl_reader->read(node))
        return data;

    return NULL;
}

dtkAbstractDataReader *createaxlDataDynamicReader(void)
{
    return new axlDataDynamicReader;
}
