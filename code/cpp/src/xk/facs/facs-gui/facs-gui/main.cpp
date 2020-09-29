

// // license___here_h


//?
#include "gui/MainWindow.h"

#include <QDebug>
#include <QApplication>

//#ifdef HIDE
#include "cytolib/MemCytoFrame.hpp"

#include "facs-bridge/qvector-matrix-r8.h"

int test()
{
 cytolib::FCS_READ_HEADER_PARAM hp;
 cytolib::FCS_READ_DATA_PARAM dp;
 cytolib::FCS_READ_PARAM rp;


// test_cyto();

 //
 QString file_name = DEMO_FCS_FOLDER "/Live_cells.fcs"; // "/home/nlevisrael/hypergr/pgvm/ar/extra/facs/Live_cells.fcs";

 cytolib::MemCytoFrame mcf(file_name.toStdString(), rp);

 mcf.read_fcs();

 QVector_Matrix_R8* qvm = mcf.data_to_qvmatrix();

 r8 test = (*qvm)[2][3];

 qDebug() << "R: " << qvm->n_rows();
 qDebug() << "C: " << qvm->n_cols();

 qDebug() << "T: " << test;

 qvm->save_to_file(file_name + ".txt");

 qDebug() << "OK ...";



 return 0;
}
//#endif

int main(int argc, char* argv[])
{
 QApplication app(argc, argv);

 MainWindow mw;
 
 return app.exec();
}


