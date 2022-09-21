#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

//namespace Ui {
//class MainWindow;
//}

class Lanternfly_Main_Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Lanternfly_Main_Window(QWidget *parent = 0);
    ~Lanternfly_Main_Window();
    
private slots:
    void on_actionExit_triggered();

//private:
//    Ui::MainWindow *ui;
};

#endif // MAIN_WINDOW_H
