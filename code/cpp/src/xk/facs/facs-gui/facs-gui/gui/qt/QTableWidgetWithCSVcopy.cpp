
// // license___here

#include "QTableWidgetWithCSVcopy.h"


// package facsanadu.gui.qt;


QTableWidgetWithCSVcopy::QTableWidgetWithCSVcopy(QWidget* parent)
 :  QTableWidget(parent)
{

}

void QTableWidgetWithCSVcopy::keyPressEvent(QKeyEvent* event) 
{
 Q_UNUSED(event)
/*
 if(event.matches(StandardKey.Copy) )
   copy();
 else
   super.keyPressEvent(event);
*/
}

QString QTableWidgetWithCSVcopy::allToCSV()
{
 return {};
/*
  TreeSet<Integer> whichcol=new TreeSet<Integer>();
  TreeSet<Integer> whichrow=new TreeSet<Integer>();
  for(int i=0;i<columnCount();i++)
   whichcol.add(i);
  for(int i=0;i<rowCount();i++)
   whichrow.add(i);
  return toCSV(whichcol, whichrow);
*/
}
 
void QTableWidgetWithCSVcopy::copy(QSet<int> whichcol, QSet<int> whichrow)
{
 Q_UNUSED(whichcol)
 Q_UNUSED(whichrow)
 /*
  String s=toCSV(whichcol, whichrow);
  QApplication.clipboard().setText(s);
*/
}

 
 /**
  * Export selection to CSV
  */
QString QTableWidgetWithCSVcopy::toCSV(QSet<int> whichcol, QSet<int> whichrow)
{
 Q_UNUSED(whichcol)
 Q_UNUSED(whichrow)
 return {};
 /*
  StringBuilder sb=new StringBuilder();
 
  boolean fst=true;
  for(int i:whichcol)
   {
   if(!fst)
    sb.append("\t");
   fst=false;
   sb.append(horizontalHeaderItem(i).text());
   }
  sb.append("\n");

  for(int currow:whichrow)
   {
   fst=true;
   for(int curcol:whichcol)
    {
    if(!fst)
     sb.append("\t");
    fst=false;
    QTableWidgetItem item=item(currow,curcol);
    if(item.data(Qt.ItemDataRole.UserRole)!=null)
     sb.append(item.data(Qt.ItemDataRole.UserRole).toString());
    else
     sb.append(item.text());
    }
   sb.append("\n");
   }
  sb.append("\n");
  return sb.toString();
*/
}

 
 /**
  * Export everything to CSV. Can return null if no
  */
QString QTableWidgetWithCSVcopy::selectionToCSV()
{
 return {};
 /*
  LinkedList<QModelIndex> indexes=new LinkedList<QModelIndex>(selectionModel().selectedIndexes());
  if(indexes.size()>0)
   {
   TreeSet<Integer> whichcol=new TreeSet<Integer>();
   TreeSet<Integer> whichrow=new TreeSet<Integer>();
   for(QModelIndex in:indexes)
    {
    whichcol.add(in.column());
    whichrow.add(in.row());
    }
   return toCSV(whichcol, whichrow);
   }
  else
   return null;
*/
}
 
void QTableWidgetWithCSVcopy::copyAll()
{
 /*
  String s=allToCSV();
  if(s!=null)
   QApplication.clipboard().setText(s);
*/
}
 
void QTableWidgetWithCSVcopy::copy()
{
 /*
  String s=selectionToCSV();
  if(s!=null)
   QApplication.clipboard().setText(s);
 */
}


