

// // license___here_h


//?
#include "gui/MainWindow.h"

#include <QDebug>
#include <QApplication>


int main(int argc, char* argv[])
{
 QApplication app(argc, argv);

 MainWindow mw;
 
 qDebug() << "OK,";

 return app.exec();
}


