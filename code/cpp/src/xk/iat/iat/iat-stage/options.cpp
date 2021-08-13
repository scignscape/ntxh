#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent):QDialog(parent),ui(new Ui::Options){
    ui->setupUi(this);
    on_Default_clicked();
}

Options::~Options(){
    delete ui;
}

void Options::on_Default_clicked(){
    QDialog::setWindowTitle("Options");
    int min=0;
    int max=255;
    ui->spinLineThickness->setValue(3);
    ui->spinSquareDimension->setValue(6);
    ui->RedLineColor->setMinimum(min);
    ui->RedLineColor->setMaximum(max);
    ui->RedLineColor->setValue(max);
    ui->RedSquareColor->setMinimum(min);
    ui->RedSquareColor->setMaximum(max);
    ui->RedSquareColor->setValue(max);
    ui->RedSelectedColor->setMinimum(min);
    ui->RedSelectedColor->setMaximum(max);
    ui->RedSelectedColor->setValue(min);
    ui->GreenLineColor->setMinimum(min);
    ui->GreenLineColor->setMaximum(max);
    ui->GreenLineColor->setValue(min);
    ui->GreenSquareColor->setMinimum(min);
    ui->GreenSquareColor->setMaximum(max);
    ui->GreenSquareColor->setValue(max);
    ui->GreenSelectedColor->setMinimum(min);
    ui->GreenSelectedColor->setMaximum(max);
    ui->GreenSelectedColor->setValue(max);
    ui->BlueLineColor->setMinimum(min);
    ui->BlueLineColor->setMaximum(max);
    ui->BlueLineColor->setValue(min);
    ui->BlueSquareColor->setMinimum(min);
    ui->BlueSquareColor->setMaximum(max);
    ui->BlueSquareColor->setValue(max);
    ui->BlueSelectedColor->setMinimum(min);
    ui->BlueSelectedColor->setMaximum(max);
    ui->BlueSelectedColor->setValue(min);
}

void Options::on_spinLineThickness_valueChanged(int arg){
    if(arg<=15) update();
    else ui->spinLineThickness->setValue(15);
}

void Options::on_spinSquareDimension_valueChanged(int arg){
    if(arg<=20) update();
    else ui->spinSquareDimension->setValue(20);
}

void Options::on_RedLineColor_valueChanged(){
    update();
}

void Options::on_GreenLineColor_valueChanged(){
    update();
}

void Options::on_BlueLineColor_valueChanged(){
    update();
}

void Options::on_RedSquareColor_valueChanged(){
    update();
}

void Options::on_GreenSquareColor_valueChanged(){
    update();
}

void Options::on_BlueSquareColor_valueChanged(){
    update();
}

void Options::on_RedSelectedColor_valueChanged(){
    update();
}

void Options::on_GreenSelectedColor_valueChanged(){
    update();
}

void Options::on_BlueSelectedColor_valueChanged(){
    update();
}

void Options::on_Save_clicked(){
    radius=ui->spinSquareDimension->value();
    thickness=ui->spinLineThickness->value();
    myRed=ui->RedLineColor->value();
    myGreen=ui->GreenLineColor->value();
    myBlue=ui->BlueLineColor->value();
    sqRed=ui->RedSquareColor->value();
    sqGreen=ui->GreenSquareColor->value();
    sqBlue=ui->BlueSquareColor->value();
    shapeRed=ui->RedSelectedColor->value();
    shapeGreen=ui->GreenSelectedColor->value();
    shapeBlue=ui->BlueSelectedColor->value();
    updateDisplay();
    QDialog::accept();
}

void Options::on_Cancel_clicked(){
    ui->spinSquareDimension->setValue(radius);
    ui->spinLineThickness->setValue(thickness);
    ui->RedLineColor->setValue(myRed);
    ui->GreenLineColor->setValue(myGreen);
    ui->BlueLineColor->setValue(myBlue);
    ui->RedSquareColor->setValue(sqRed);
    ui->GreenSquareColor->setValue(sqGreen);
    ui->BlueSquareColor->setValue(sqBlue);
    ui->RedSelectedColor->setValue(shapeRed);
    ui->GreenSelectedColor->setValue(shapeGreen);
    ui->BlueSelectedColor->setValue(shapeBlue);
    QDialog::accept();
}

void Options::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPen myPen(QColor(ui->RedLineColor->value(),ui->GreenLineColor->value(),ui->BlueLineColor->value()), ui->spinLineThickness->value(), Qt::SolidLine);
    myPen.setCapStyle(Qt::RoundCap);
    painter.setPen(myPen);
    painter.setBrush(QBrush(QColor(ui->RedLineColor->value(),ui->GreenLineColor->value(),ui->BlueLineColor->value()),Qt::Dense6Pattern));
    QRect ellipseMy(25,210,100,75);
    painter.drawEllipse(ellipseMy);
    QRect rect1(25-ui->spinSquareDimension->value(),210-ui->spinSquareDimension->value(),ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect1, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect2(25-ui->spinSquareDimension->value()+100,210-ui->spinSquareDimension->value(),ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect2, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect3(25-ui->spinSquareDimension->value(),210-ui->spinSquareDimension->value()+75,ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect3, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect4(25-ui->spinSquareDimension->value()+100,210-ui->spinSquareDimension->value()+75,ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect4, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));

    QPen shapePen(QColor(ui->RedSelectedColor->value(),ui->GreenSelectedColor->value(),ui->BlueSelectedColor->value()), ui->spinLineThickness->value(), Qt::SolidLine);
    shapePen.setCapStyle(Qt::RoundCap);
    painter.setPen(shapePen);
    painter.setBrush(QBrush(QColor(ui->RedSelectedColor->value(),ui->GreenSelectedColor->value(),ui->BlueSelectedColor->value()),Qt::Dense6Pattern));
    QRect ellipseShape(175,210,100,75);
    painter.drawEllipse(ellipseShape);
    QRect rect5(175-ui->spinSquareDimension->value(),210-ui->spinSquareDimension->value(),ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect5, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect6(175-ui->spinSquareDimension->value()+100,210-ui->spinSquareDimension->value(),ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect6, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect7(175-ui->spinSquareDimension->value(),210-ui->spinSquareDimension->value()+75,ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect7, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
    QRect rect8(175-ui->spinSquareDimension->value()+100,210-ui->spinSquareDimension->value()+75,ui->spinSquareDimension->value()*2,ui->spinSquareDimension->value()*2);
    painter.fillRect(rect8, QColor(ui->RedSquareColor->value(),ui->GreenSquareColor->value(),ui->BlueSquareColor->value()));
}


void Options::updateDisplay(){
    ColorsThickness(ui->spinSquareDimension->value(),
                    ui->spinLineThickness->value(),
                    ui->RedLineColor->value(),
                    ui->GreenLineColor->value(),
                    ui->BlueLineColor->value(),
                    ui->RedSquareColor->value(),
                    ui->GreenSquareColor->value(),
                    ui->BlueSquareColor->value(),
                    ui->RedSelectedColor->value(),
                    ui->GreenSelectedColor->value(),
                    ui->BlueSelectedColor->value());
}
