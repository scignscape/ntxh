
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QApplication>
#include <QtDebug>
#include <QMainWindow>
#include <QPushButton>

#include "main-window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Lanternfly_Main_Window w;
    w.show();

    return a.exec();
}
