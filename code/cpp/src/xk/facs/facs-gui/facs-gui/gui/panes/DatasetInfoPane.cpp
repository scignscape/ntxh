
// // license___here

#include "DatasetInfoPane.h"

#include "MainWindow.h"

#include "../data/Dataset.h"

#include "cytolib/MemCytoFrame.hpp"

#include <QHeaderView>

#include <QVBoxLayout>

#include <QDebug>

// package facsanadu.gui.panes;



// // Pane showing metadata about a dataset

DatasetInfoPane::DatasetInfoPane(MainWindow* mw)
{
 tableMatrix_ = new QTableWidget();
 updating_ = false;
 
 mw_ = mw; 

 updateForm();
 
 QVBoxLayout* lay = new QVBoxLayout();
 lay->addWidget(tableMatrix_);
 // lay.addStretch();
 lay->setMargin(0);
 setLayout(lay);
 updateForm();
}

void DatasetInfoPane::test(Dataset* ds)
{
 updating_ = true;

 tableMatrix_->clear();
 tableMatrix_->verticalHeader()->hide();

 //Columns
 QStringList header; // = new LinkedList<String>();
 header.push_back("Key");
 header.push_back("Value");
 tableMatrix_->setColumnCount(2);
 tableMatrix_->setHorizontalHeaderLabels(header);


 // QStringList keyw({"c1", "c2", "c3", "c4"}); //=new ArrayList<String>(metaKeyName.keySet());
 
 //QMap<QString, QString> metaKeyName;


 cytolib::MemCytoFrame* cyto_frame = ds->cyto_frame();
 QMap<QString, QString>& qmap = cyto_frame->header_qmap(); 

 tableMatrix_->setRowCount(qmap.size());


 {
  QTableWidgetItem* qtwi = new QTableWidgetItem("# observations");
  qtwi->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);  
  tableMatrix_->setItem(0, 0, qtwi);

  QTableWidgetItem* qtwi1 = new QTableWidgetItem(QString::number(ds->getNumObservations()));
  qtwi1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
  tableMatrix_->setItem(0, 1, qtwi1);
 }


 int i = 1;

 QMapIterator<QString, QString> it(qmap);

 while(it.hasNext())
 {
  it.next();
  QTableWidgetItem* qtwi = new QTableWidgetItem(it.key());
  qtwi->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);  
  tableMatrix_->setItem(i, 0, qtwi);

  QTableWidgetItem* qtwi1 = new QTableWidgetItem(it.value());
  qtwi1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
  tableMatrix_->setItem(i, 1, qtwi1);

  ++i;
 }

 tableMatrix_->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
 tableMatrix_->horizontalHeader()->setStretchLastSection(true); 
 tableMatrix_->resizeColumnsToContents();
  
 //tableMatrix_->itemChanged.connect(this,"dataChanged(QTableWidgetItem)");
 updating_ = false;
}

 
void DatasetInfoPane::updateForm()
{
#ifdef HIDE
 updating_ = true;
 
 tableMatrix_->clear();
 tableMatrix_->verticalHeader()->hide();
 
 //Columns
 QStringList header; // = new LinkedList<String>();
 header.push_back("Key");
 header.push_back("Value");
 tableMatrix_->setColumnCount(2);
 tableMatrix_->setHorizontalHeaderLabels(header);
 
 if(mw_->getSelectedDatasets().size() == 1)
 {
  Dataset* ds = mw_->getSelectedDatasets().first();

 //  TreeMap<String, String> metaKeyName=new TreeMap<String, String>(ds.metaKeyName);
  QMap<QString, QString> metaKeyName;

  metaKeyName.insert("# observations", QString::number(ds->getNumObservations() ) );
  
  
  QStringList keyw(metaKeyName.keys()); //=new ArrayList<String>(metaKeyName.keySet());

  tableMatrix_->setRowCount(keyw.size());

  for(int i = 0; i < keyw.size(); ++i)
  {
   QTableWidgetItem* it = new QTableWidgetItem(keyw.value(i));
   //it->setFlags(new ItemFlags(ItemFlag.ItemIsSelectable, ItemFlag.ItemIsEnabled));
   it->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);  
   tableMatrix_->setItem(i, 0, it);

   QTableWidgetItem* it1 = new QTableWidgetItem(metaKeyName.value(keyw.value(i)));
   it1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
   tableMatrix_->setItem(i, 1, it1);
  }
 }
 else
 {
  tableMatrix_->setRowCount(0);
 }
 
 tableMatrix_->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
 tableMatrix_->horizontalHeader()->setStretchLastSection(true); 
 tableMatrix_->resizeColumnsToContents();
  
 //tableMatrix_->itemChanged.connect(this,"dataChanged(QTableWidgetItem)");
 updating_ = false;
#endif //def HIDE
}
 
 
void DatasetInfoPane::dataChanged(QTableWidgetItem* it)
{
 Q_UNUSED(it)
 if(!updating_)
 {
 }
}


