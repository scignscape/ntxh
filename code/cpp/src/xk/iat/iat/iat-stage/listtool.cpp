#include "listtool.h"
#include "ui_listtool.h"

ListTool::ListTool(QWidget *parent):QDialog(parent),ui(new Ui::ListTool){
    ui->setupUi(this);
}

ListTool::~ListTool(){
    delete ui;
}

void ListTool::on_textObject_textChanged()
{

}

void ListTool::on_textInstance_textChanged()
{

}

void ListTool::on_AddLine_clicked(){
    //QLineEdit *lineEdit = new QLineEdit;
    //QLabel *label = new QLabel;
    //ui->gridLayout->addWidget(lineEdit,count,0);

    //Now you want to access text of all lineEdit you can do it like

    /*int iCount = ui->gridLayout->count(); //Total no of LineEdit added on gridLayout dynamically
    QString str = tr("");
    for(int i = 0; i < iCount; i++)
    {
            QLayoutItem* pLine = ui->gridLayout->itemAt(i);
            QLineEdit* pLineEdit = (QLineEdit*)pLine->widget();
            str = pLineEdit->text();

           //Now do whatever you want to do with the text
    } */
}

void ListTool::on_Save_clicked()
{

}

void ListTool::on_Cancel_clicked()
{

}
