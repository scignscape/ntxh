
// // license___here

#include "CompensationPane.h"

#include "../qt/QTableWidgetWithCSVcopy.h"

#include "../data/Compensation.h"

#include "FacsanaduProject.h"
#include "MainWindow.h"

#include <QVBoxLayout>

#include <QHeaderView>


// package facsanadu.gui.panes;


// //

CompensationPane::CompensationPane(MainWindow* mw)
{
 mw_= mw;  

 tableMatrix_ = new QTableWidgetWithCSVcopy(this);
  
 QVBoxLayout* lay = new QVBoxLayout();
 lay->addWidget(tableMatrix_);
  //lay.addStretch();
 lay->setMargin(0);
 setLayout(lay);
 updateForm();
}
 
void CompensationPane::updateForm()
{
 updating_ = true;
 tableMatrix_->clear();
  
 tableMatrix_->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
 tableMatrix_->horizontalHeader()->setStretchLastSection(true);  

 Compensation* comp = mw_->project()->compensation();
  
// LinkedList<String> header = new LinkedList<String>();
// LinkedList<String> headerFrom=new LinkedList<String>();

 QStringList header;
 QStringList headerFrom;

 for(QString s : comp->cnames() )
 {
  header.push_back(s);
  headerFrom.push_back(tr("To: ") + s);
 }
  
  //ROW is TO. COL is FROM
  
 tableMatrix_->setColumnCount(comp->getSize());
 tableMatrix_->setRowCount(comp->getSize());
 tableMatrix_->setHorizontalHeaderLabels(header);
 tableMatrix_->setVerticalHeaderLabels(headerFrom);
  
 for(int row=0; row < comp->getSize(); row++)
 {
  for(int col=0; col< comp->getSize(); col++)
  {
   QTableWidgetItem* it = new QTableWidgetItem( 
     QString::number( comp->get(row,col) ) );

//   it.setFlags(new ItemFlags(ItemFlag.ItemIsSelectable, ItemFlag.ItemIsEnabled,  ItemFlag.ItemIsEditable));
   it->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable);

   tableMatrix_->setItem(row, col, it);
  }
 }
  //? tableMatrix_->itemChanged.connect(this,"dataChanged(QTableWidgetItem)");
 updating_ = false;
}
 
 
void CompensationPane::dataChanged(QTableWidgetItem* it)
{
 Q_UNUSED(it)
 if(!updating_)
 {
//  Compensation comp=mw.project.compensation;
//  comp.set(it.row(),it.column(),Double.parseDouble(it.text()));
//  mw.handleEvent(new EventCompensationChanged());
 }
}


