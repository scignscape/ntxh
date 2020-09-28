
// // license___here_h


#ifndef QTableWidgetWithCSVcopy__H
#define QTableWidgetWithCSVcopy__H

#include <QString>

#include <QTableWidget>
#include <QSet>

// package facsanadu.gui.qt;


// //Much of code inspired from stack overflow

class QTableWidgetWithCSVcopy : public QTableWidget
{

protected: 

 void keyPressEvent(QKeyEvent* event);

public:

 QTableWidgetWithCSVcopy(QWidget* parent = nullptr);

 QString allToCSV();
// void copy(TreeSet<Integer> whichcol, TreeSet<Integer> whichrow);

 void copy(QSet<int> whichcol, QSet<int> whichrow);
 
 /**
  * Export selection to CSV
  */
 QString toCSV(QSet<int>  whichcol, QSet<int>  whichrow);

 /**
  * Export everything to CSV. Can return null if no
  */
 QString selectionToCSV();
 
 void copyAll();

 void copy();
};

#endif // __H
 



