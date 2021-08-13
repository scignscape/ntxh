#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QWidget>
#include <QtGui>

namespace Ui {
class Options;
}

class Options : public QDialog{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

signals:
    void ColorsThickness(int,int,int,int,int,int,int,int,int,int,int);

private slots:
    void on_Default_clicked();
    void on_spinLineThickness_valueChanged(int arg);
    void on_spinSquareDimension_valueChanged(int arg);
    void on_RedLineColor_valueChanged();
    void on_GreenLineColor_valueChanged();
    void on_BlueLineColor_valueChanged();
    void on_RedSquareColor_valueChanged();
    void on_GreenSquareColor_valueChanged();
    void on_BlueSquareColor_valueChanged();
    void on_RedSelectedColor_valueChanged();
    void on_GreenSelectedColor_valueChanged();
    void on_BlueSelectedColor_valueChanged();
    void on_Save_clicked();
    void on_Cancel_clicked();

private:
    Ui::Options *ui;
    int radius;
    int thickness;
    int myRed;
    int myGreen;
    int myBlue;
    int sqRed;
    int sqGreen;
    int sqBlue;
    int shapeRed;
    int shapeGreen;
    int shapeBlue;
    void updateDisplay();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // OPTIONS_H
