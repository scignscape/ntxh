
// // license___here

#include "GateStatsPane.h"

#include "MainWindow.h"

#include "FacsanaduProject.h"

#include "../qt/QTableWidgetWithCSVcopy.h"

#include "../qt/QTutil.h"

#include "../gates/gate-info.h"
#include "../gates/measure/GateMeasure.h"
#include "../gates/GatingResult.h"
#include "../data/Dataset.h"

#include <QHeaderView>

// package facsanadu.gui.panes;

// //
GateStatsPane::GateStatsPane(MainWindow* mw)
 : mw_(mw) 
{
 cbShowParent_ = new QCheckBox(tr("Show % of parent"));
 cbShowTotal_ = new QCheckBox(tr("Show % of total"));
 bCopyCSV_ = new QPushButton(tr("Export to clipboard"));

 tableStats_ = new QTableWidgetWithCSVcopy();

 cbShowParent_->setChecked(true);
 cbShowTotal_->setChecked(false);

//? cbShowParent_->stateChanged.connect(this,"updateStats()");
//? cbShowTotal_->stateChanged.connect(this,"updateStats()");
//? bCopyCSV_->clicked.connect(this,"actionCopyToClipboard()");

 QVBoxLayout* lay = new QVBoxLayout();
 lay->addWidget(tableStats_);

 lay->addLayout(QTutil::layoutHorizontal({cbShowParent_, cbShowTotal_, bCopyCSV_}));

 lay->setMargin(0);
 setLayout(lay);
}


void GateStatsPane::updateStats()
{
 tableStats_->clear();

 tableStats_->verticalHeader()->hide();
 tableStats_->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
 tableStats_->horizontalHeader()->setStretchLastSection(true);

 QList<Gate*> listGates = mw_->getSelectedGates();
 QList<GateMeasure*> listCalc = mw_->getSelectedMeasures();
 QList<Dataset*> listDatasets = mw_->getSelectedDatasets();

 int perGateNumStat = 0;

 if(cbShowParent_->isChecked())
   perGateNumStat++;

 if(cbShowTotal_->isChecked()) 
   perGateNumStat++;

 tableStats_->setColumnCount(listGates.size()*perGateNumStat + listCalc.size() + 1);
 QStringList header; // = new LinkedList<String>();
 header.push_back(tr("Dataset"));

 for(Gate* g : listGates)
 {
  if(cbShowParent_->isChecked())
    header.push_back(g->name() + " (parent)");
  if(cbShowTotal_->isChecked())
    header.push_back(g->name() + " (total)");
 }

 for(GateMeasure* calc : listCalc)
 {
  header.push_back(calc->gate()->name() + "/" + calc->getDesc(mw_->project() ));
 }

 tableStats_->setHorizontalHeaderLabels(header);
 tableStats_->setRowCount(listDatasets.size());

 for(int row = 0; row < listDatasets.size(); ++row)
 {
  Dataset* dataset = listDatasets.value(row);
  GatingResult* gr = mw_->project()->getGatingResult(dataset);

  int curcol=1;

  for(int igate = 0; igate < listGates.size(); igate++)
  {
//?   Gate* gate=listGates.value(igate);
/*
   IntArray arr=gr.getAcceptedFromGate(gate);

   if(arr == nullptr)
     arr=new IntArray(); 

   //Compute percent of parent
   Gate gparent=gate.parent;
   if(gparent == nullptr)
     gparent=gr.getRootGate();
   IntArray arrParent=gr.getAcceptedFromGate(gparent);
   double percParent;
   if(arrParent!=null)
     percParent=arr.size()/(double)arrParent.size();
   else
     percParent=-1; //Cannot be calculated yes

   //Compute percent of total
   double percTotal=arr.size()/(double)gr.getTotalCount(); 

   if(cbShowParent_->isChecked())
   {
    QTableWidgetItem it=QTutil.createReadOnlyItem(formatPerc(percParent));
    it.setData(Qt.ItemDataRole.UserRole, percParent);
    tableStats->setItem(row, curcol, it);
    curcol++;
   }
   if(cbShowTotal_->isChecked())
   {
    QTableWidgetItem it=QTutil.createReadOnlyItem(formatPerc(percTotal));
    it.setData(Qt.ItemDataRole.UserRole, percTotal);
    tableStats->setItem(row, curcol, it);
    curcol++;
   }
*/
  }

  for(int i=0; i < listCalc.size(); i++)
  {
   GateMeasure* calc = listCalc.at(i);

   double v = gr->getCalcResult(calc);

   QTableWidgetItem* it = QTutil::createReadOnlyItem(v != 0 ? QString::number(v)
     : tr("N/A"));
   it->setData(Qt::UserRole, v);
//   tableStats->setItem(row, curcol, it);
   curcol++;
  }

  QTableWidgetItem* it = QTutil::createReadOnlyItem(dataset->get_file_source_name());
  tableStats_->setItem(row, 0, it);
 }
}

QString GateStatsPane::formatPerc(double d)
{
/*
 NumberFormat nf=NumberFormat.getInstance();
 if(d>5)
   nf.setMaximumFractionDigits(1);
 else
   nf.setMaximumFractionDigits(3);
 return nf.format(d*100)+"%";
*/
 return QString::number(d);
}


// // Copy all of table to clipboard
void GateStatsPane::actionCopyToClipboard()
{
 tableStats_->copyAll();
}



 // // Export everything to CSV
void GateStatsPane::actionExportCSV()
{
/*
 QFileDialog dia = new QFileDialog();
 dia.setFileMode(FileMode.AnyFile);
 dia.setNameFilter(tr("CSV files (*.csv)"));
 dia.setAcceptMode(AcceptMode.AcceptSave);
 dia.setDefaultSuffix("csv");

 if(dia.exec()!=0)
 {
  try
  {
   PrintWriter fw=new PrintWriter(new File(dia.selectedFiles().get(0)));
   fw.println(tableStats->allToCSV());
   fw.close();
  }
  catch (IOException e)
  {
   QTutil.showNotice(this, e.getMessage());
   e.printStackTrace();
  }
 }
*/
}


