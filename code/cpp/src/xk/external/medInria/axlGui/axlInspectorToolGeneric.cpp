#include <axlCore/axlAbstractProcess.h>
#include <axlCore/axlAbstractData.h>

#include <axlGui/axlInspectorObjectController.h>
#include <axlGui/axlInspectorObjectManagerTreeItem.h>

#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlInspectorToolGeneric.h"

#include <QtCore>
#include <QtGui>

#include <QObject>

#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>


class axlInspectorToolGenericInputInteger : public QSpinBox
{
    Q_OBJECT

public :
    axlInspectorToolGenericInputInteger(axlAbstractProcess *p,QWidget *parent = 0,int value = 0, QString chan = "") : QSpinBox(parent){
        process = p;
        if(!chan.isEmpty()) // add a check to know whether it is really a number.
            channel = chan.toInt();
        else
            channel = -1;

        this->setParent(parent);

        //default value of the input
        this->setValue(value);

        connect(this, SIGNAL(valueChanged(int)), this, SLOT(addParameterInt(int)));


    }

    ~axlInspectorToolGenericInputInteger(){

        disconnect(this, SIGNAL(valueChanged(int)), this, SLOT(addParameterInt(int)));
    }


public slots :
    void addParameterInt(int value){
        if(channel == -1){
            process->setParameter(value);
        }else{
            process->setParameter(value, channel);
        }

    }

public :
    axlAbstractProcess *process;
    int channel;
};



// Double parameters
class axlInspectorToolGenericInputDouble : public QDoubleSpinBox
{
    Q_OBJECT

public :
    axlInspectorToolGenericInputDouble(axlAbstractProcess *p, QWidget *parent = 0, double value=0.0, QString chan = ""):QDoubleSpinBox(parent){
        process = p;
        if(!chan.isEmpty())// add a check to know whether it is really a number.
            channel = chan.toInt();
        else
            channel = -1;

        this->setParent(parent);
        //default value for this parameter
        this->setValue(value);
        this->setSingleStep(0.10);
        this->setDecimals(5);
        connect(this, SIGNAL(valueChanged(double)), this, SLOT(addParameter(double)));


    }

    virtual ~axlInspectorToolGenericInputDouble(){

        disconnect(this, SIGNAL(valueChanged(double)), this, SLOT(addParameter(double)));
    }

public :
    axlAbstractProcess *process;
    int channel;


public slots :
    void addParameter(double value);

};

void  axlInspectorToolGenericInputDouble::addParameter(double value){
    if(channel == -1){
        process->setParameter(value);
    }else{
        process->setParameter(value, channel);
    }

}

// Data Inputs
class axlInspectorToolGenericInputData : public QComboBox
{
    Q_OBJECT

public :
    axlInspectorToolGenericInputData(axlAbstractProcess *p, axlInspectorObjectController *control, QWidget *parent = 0,QString chan =""):QComboBox(parent)
    {
        process = p;
        controller = control;
        if(!chan.isEmpty())
            channel = chan.toInt();
        else
            channel=-1;


        if(!controller->items().isEmpty()){
            foreach(axlInspectorObjectManagerTreeItem *item, controller->items()){

                this->addItem(item->text(0));
            }
        }

        QString name = this->currentText();
        foreach(axlInspectorObjectManagerTreeItem *item, controller->items()) {
            QString nameList = item->text(0);


            if(nameList == name){
                process->setInput(controller->data(item), channel);
            }


        }


        connect(this, SIGNAL(activated(QString)), this, SLOT(OnFindingInput(const QString&)));
    }

    ~axlInspectorToolGenericInputData()
    {

        disconnect(this, SIGNAL(activated(QString)), this, SLOT(OnFindingInput(const QString&)));
    }

public :
    axlAbstractProcess *process;
    axlInspectorObjectController *controller;
    int channel;


public slots :
    // we search for the right input in the inspector Object Tree, we want to select.
    void OnFindingInput(const QString& name){


        foreach(axlInspectorObjectManagerTreeItem *item, controller->items()) {
            QString nameList = item->text(0);

            if(nameList == name){
                if(channel ==-1)
                    process->setInput(controller->data(item));
                else
                    process->setInput(controller->data(item), channel);

            }
        }
    }
};


//Data Outputs
class axlInspectorToolGenericOutputData : public QLabel
{

public :
    axlInspectorToolGenericOutputData(QString channel, QString label)
    {
        this->setText("Output:" + channel + " "+label);
    }

    ~axlInspectorToolGenericOutputData(){

    }

};


class axlInspectorToolGenericInputString : public QComboBox
{
    Q_OBJECT

public :
    axlInspectorToolGenericInputString(axlAbstractProcess *p,QWidget *parent = 0, QStringList list = QStringList(), QString chan = "") : QComboBox(parent){
        process = p;
        if(!chan.isEmpty()) // add a check to know whether it is really a number.
            channel = chan.toInt();
        else
            channel = -1;

        this->setParent(parent);

        //fill the QCombox with possible values. By default display first value in the list.
        this->addItems(list);

        connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(addParameter(int)));


    }

    ~axlInspectorToolGenericInputString(){

        disconnect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(addParameter(int)));
    }


public slots :
    void addParameter(int currentIndex){
        if(channel == -1){
            process->setParameter(currentIndex);
        }else{
            process->setParameter(currentIndex, channel);
        }

    }

public :
    axlAbstractProcess *process;
    int channel;
};


class axlInspectorToolGenericInputDataList : public QWidget
{
    Q_OBJECT

public :
    axlInspectorToolGenericInputDataList(axlAbstractProcess *p,axlInspectorObjectController *control,QWidget *parent = 0, QString chan = "") : QWidget(parent){
        process = p;
        controller = control;

        if(chan.isEmpty())
            channel = chan.toInt();
        else
            channel = -1;

        QList<axlAbstractData *>dataList;

        //select all data written selected or editable in the object inspector.
        foreach(axlInspectorObjectManagerTreeItem *item, controller->items())
        {
            if( (item->text(2) == "Selected" || item->text(2) == "Editable"))
            {
                dataList << dynamic_cast<axlAbstractData *>(controller->data(item));
            }
        }


        //setInput
        if(channel == -1){
            foreach (axlAbstractData *data, dataList) {
                process->setInput(data);
            }

        }else{
            foreach (axlAbstractData *data, dataList) {
                process->setInput(data, channel);
            }
        }

    }

    ~axlInspectorToolGenericInputDataList(){
    }

public :
    axlAbstractProcess *process;
    axlInspectorObjectController *controller;
    int channel;
};



class axlInspectorToolGenericPrivate
{
public:
    void setup(void);

public:
    axlAbstractProcess *process;

public:
    axlInspectorObjectController *controller;

public:
    axlInspectorToolGeneric *q;

public:
    QFormLayout *layout;
    QPushButton *button;

public :
    bool emitData;
};

axlInspectorToolGeneric::axlInspectorToolGeneric(QString implementation,axlInspectorObjectController*control, QWidget *parent) : QFrame(parent), d(new axlInspectorToolGenericPrivate)
{
    d->emitData = false;
    d->q = this;
    d->process = qobject_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(implementation));
    if(d->process){
        d->process->setParent(this);
        connect(d->process, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)), this, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)));
        d->controller = control;
        d->setup();

        d->button = new QPushButton("Run", this);
        d->layout->addWidget(d->button);
        //connect(d->button, SIGNAL(clicked()), d->process, SLOT(update()));
        connect(d->button, SIGNAL(clicked()),this, SLOT(runDataInserted()));
    }else{
        dtkWarn() << "no process available";
    }
    this->setAttribute(Qt::WA_DeleteOnClose);
}



axlInspectorToolGeneric::~axlInspectorToolGeneric(void)
{

    disconnect(d->button, SIGNAL(clicked()), d->process, SLOT(update()));

    disconnect(d->process, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)), this, SIGNAL(dataSetFieldsChanged(QList<axlAbstractData *>, QString)));
    delete d->process;
    delete d;
}



void axlInspectorToolGeneric::runDataInserted(void){
    //QString implementation = d->process->identifier();
    //d->process = NULL;
    //d->process = qobject_cast<axlAbstractProcess *>(dtkAbstractProcessFactory::instance()->create(implementation));
    //d->setup();
    if(d->process->update()){
        if(d->emitData){
            if(d->process->output()){
                emit dataInserted(dynamic_cast<axlAbstractData *>(d->process->output()));
            }
        }
    }
}


void axlInspectorToolGenericPrivate::setup(void)
{
    this->layout = new QFormLayout(q);

    if(!this->process) {
        this->layout->addRow(new QLabel("Invalid process", q));
    } else {
        this->layout->addRow(new QLabel(this->process->identifier(), q));
    }

    QString form = this->process->form();

    if(form.isEmpty()){
        // Default behavior will send to the process all selected data from the inspector
        QList<dtkAbstractData*> dataSet;
        int numberOfDataSelected =0;

        foreach(axlInspectorObjectManagerTreeItem *item, this->controller->items())
        {
            if(item->text(2) == "Selected")
            {
                dataSet.push_back (this->controller->data(item));
                numberOfDataSelected++;
            }
        }

        // We don't care if the process implement really virtual functions called below.
        if(dataSet.size() == 0)
            qDebug() <<  " No input data selected for : "<< process->identifier();

        else if(dataSet.size() == 1)
            process->setInput(dataSet.first());
        else // (dataSet.size() > 1)
        {
            for (int i = 0 ; i < dataSet.size() ; i++)
                process->setInput(dataSet[i], i);
        }


        //this->layout->addRow(new QLabel("No form description found", q));

    } else {

        QStringList lines = form.split("\n");
        foreach(QString line, lines) {

            QStringList tokens = line.simplified().split(QRegExp("\\s"));
            int l=tokens.at(0).size();

            if(tokens.first().startsWith("INPUT")) {

                Q_ASSERT(tokens.count() >3);

                QString type = tokens.at(1);
                QString label = tokens.at(2);

                if(l > 6){

                    QString channel = tokens.at(0).right(l-6);

                    if(type == "int"){
                        int value = tokens.last().toInt();
                        this->layout->addRow(label, new axlInspectorToolGenericInputInteger(this->process,this->q, value, channel));
                    }

                    if(type == "double"){
                        double value = tokens.last().toDouble();
                        this->layout->addRow(label, new axlInspectorToolGenericInputDouble(this->process,this->q, value, channel));
                    }

                    if(type == "data")
                        this->layout->addRow(label, new axlInspectorToolGenericInputData(this->process, this->controller, this->q, channel));


                    if(type == "dataList")
                        this->layout->addRow(label, new axlInspectorToolGenericInputDataList(this->process, this->controller, this->q,channel));
                }else{

                    if(type == "int"){
                        int value = tokens.last().toInt();
                        this->layout->addRow(label, new axlInspectorToolGenericInputInteger(this->process,this->q,value));
                    }

                    if(type == "double"){
                        double value = tokens.last().toDouble();
                        this->layout->addRow(label, new axlInspectorToolGenericInputDouble(this->process,this->q,value));
                    }

                    if(type == "data")
                        this->layout->addRow(label, new axlInspectorToolGenericInputData(this->process, this->controller,this->q));


                    if(type == "dataList")
                        this->layout->addRow(label, new axlInspectorToolGenericInputDataList(this->process, this->controller,this->q));

                }

            }

            if(tokens.first().startsWith("PARAMETER")) {



                if(l > 9) {

                    QString channel = tokens.at(0).right(l-10);
                    QString type = tokens.at(1);
                    QString label = tokens.at(2);
                    //qDebug()<<"parameter"<<channel;

                    if(type == "int"){
                        int value = tokens.last().toInt();
                        this->layout->addRow(label, new axlInspectorToolGenericInputInteger(this->process, this->q,value, channel));
                    }

                    if(type == "double"){
                        double value = tokens.last().toDouble();
                        this->layout->addRow(label, new axlInspectorToolGenericInputDouble(this->process, this->q,value, channel));
                    }

                }
            }


            if(tokens.first().startsWith("OUTPUT")){

                Q_ASSERT(tokens.count() > 2);
                emitData = true;
                QString channel = "";
                if(l>7)
                    channel = tokens.at(0).right(l-8);
                QString label = tokens.at(2);
                this->layout->addRow(new axlInspectorToolGenericOutputData(channel, label));
            }
        }
    }
}

#include "axlInspectorToolGeneric.moc"
