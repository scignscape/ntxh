// // license___here

#include "MainWindow.h"

#include <QMessageBox>

#include "GatesListWidget.h"
#include "ProfileChannelWidget.h"
#include "ViewsListWidget.h"
#include "DatasetListWidget.h"
#include "panes/CompensationPane.h"
#include "panes/DatasetInfoPane.h"
#include "FacsanaduProject.h"

#include "resource/ImgResource.h"

#include "panes/ViewsPane.h"
#include "panes/GateStatsPane.h"
#include "lengthprofile/ProfilePane.h"

#include "DialogAbout.h"

#include "GraphExportWindow.h"

#include "view/GraphExporter.h"

#include "../data/ExportFcsToCSV.h"
#include "../data/Dataset.h"

#include "QtProgramInfo.h"

#include "cytolib/MemCytoFrame.hpp"


#include <QMenu>
#include <QMimeData>
#include <QFile>
#include <QFileDialog>
#include <QMutex>
#include <QMutexLocker>
#include <QInputDialog>

#include <QApplication>

#include <QDesktopServices>
#include <QDebug>

#include <QProcess>

#include <functional>

#include "facs-bridge/mpf-package.h"

#include "textio.h"


//#ifdef HIDE

struct Facs_IOException {};
struct Facs_RuntimeException {};
struct Facs_Exception {};

//?
GateCalcThread::GateCalcThread(){}
void GateCalcThread::wakeup(){}


std::function<QList<Dataset*>()> do_MainWindow_GateCalcThread_getCurrentDatasets;

QList<Dataset*> _MainWindow_GateCalcThread::getCurrentDatasets()
{
 return do_MainWindow_GateCalcThread_getCurrentDatasets();
 // synchronized (selDatasetsCache)
 // {

//? QMutexLocker lock(&selDatasetsCache_mutex_);
//? QList<Dataset*> d (selDatasetsCache_);
//? return d;
 //? 

// return {};
};


#define connect_this(x, y, z) connect(y, &x, \
   this, &MainWindow::z);

MainWindow::MainWindow()
  //?: mpf_package_(nullptr)
{ 
 tabwidget_ = new QTabWidget();
 menubar_ = new QMenuBar();

 project_ = new FacsanaduProject();

 gatesw_ = new GatesListWidget(this);
 pc_ = new ProfileChannelWidget(this);
 viewsw_ = new ViewsListWidget(this);
 datasetsw_ = new DatasetListWidget(this);

 paneCompensation_ = new CompensationPane(this);
 paneMetadata_ = new DatasetInfoPane(this);

 calcthread_ = new _MainWindow_GateCalcThread(project_);

 connect( (_MainWindow_GateCalcThread*) calcthread_,
   &_MainWindow_GateCalcThread::callbackDoneCalc_signal, 
   [this](Dataset*)
  {
   updateall();
  });
 
 do_MainWindow_GateCalcThread_getCurrentDatasets = [this]()
  {
   QMutexLocker lock(&this->selDatasetsCache_mutex_);
   QList<Dataset*> d (this->selDatasetsCache_);
   return d;
  };

// paneViews_;
// paneStats_;
// paneProfile_;
 
//? currentProjectFile_ = ; //nullptr;

 lastDirectory_ = QDir(".");
 
 isUpdating_ = false;

 setMenuBar(menubar_);

 ImgResource::setWindowIcon(this);
 
 paneViews_ = new ViewsPane(this);
 paneStats_ = new GateStatsPane(this);
 paneProfile_ = new ProfilePane(this);
 pc_->set_paneProfile(paneProfile_);
 
 QMenu* mFile = menubar_->addMenu(tr("File"));
 mFile->addAction(tr("New project"), this, SLOT(actionNewProject()) );
 mFile->addAction(tr("Open project"), this, SLOT(actionOpenProject()) );
 mFile->addAction(tr("Save project"), this, SLOT(actionSaveProject()) );
 mFile->addAction(tr("Save project as"), this, SLOT(actionSaveProjectAs()) );

 mFile->addAction( tr("Save view"), this, SLOT(action_save_view()) );
 mFile->addAction( tr("Load view"), this, SLOT(action_load_view()) );
 mFile->addAction( tr("Angelscript"), this, SLOT(action_angelscript()) );

 mFile->addSeparator();
 mFile->addAction(tr("Exit"), this, "close()");

 
 QMenu* mExport = menubar_->addMenu(tr("Export"));
 mExport->addAction(tr("Graphs"), this, SLOT(actionExportGraphs()));
 mExport->addAction(tr("Statistics"), this, SLOT(actionExportStatistics()));
 mExport->addAction(tr("Dataset as CSV"), this, SLOT(actionExportCSV()));

 QMenu* mSettings = menubar_->addMenu(tr("Settings"));
 mSettings->addAction(tr("Set number of CPU cores"), this, SLOT(actionSetNumCores()));
 menubar_->addSeparator();
 
 QMenu* mHelp = menubar_->addMenu(tr("Help"));
 mHelp->addAction(tr("About"), this, SLOT(actionAbout()) );
 mHelp->addAction(tr("Website"), this, SLOT(actionWebsite()) );

 //? datasetsw.selectionChanged.connect(this,"actionDsChanged()");
 
 connect_this(DatasetListWidget ::selectionChanged ,datasetsw_ ,actionDsChanged) 

 QVBoxLayout* layLeft = new QVBoxLayout();

//? 
 layLeft->addWidget(datasetsw_);
//?
 layLeft->addWidget(viewsw_);

 layLeft->addWidget(gatesw_);

//? layLeft->addWidget(gatesw_);
//? layLeft->addWidget(pc_);


//? layLeft->addLayout(datasetsw_);
//? layLeft->addLayout(viewsw_);
//? layLeft->addLayout(gatesw_);
//? layLeft->addLayout(pc_);



//? 
 viewsw_->actionNewView();

 
 /// Load all files from directory
/*
 try
 {
  File getfrom=new File("/home/mahogny/javaproj/quickfacs/test4");
  if(getfrom.exists())
  for(File path:getfrom.listFiles())
   if(path.getName().endsWith(".fcs") || path.getName().endsWith(".dat"))
   loadFile(path);
  }
 catch (IOException e)
  {
  e.printStackTrace();
  }
 //loadFile(new File("/ztuff/ztufffromvenus/ztuff/customer/jin/rpt-5/rp5-larva-PMT530-day8-2010-09-11.txt"));
 */

 tabwidget_->addTab(paneViews_, tr("Graphs"));
 tabwidget_->addTab(paneStats_, tr("Statistics"));
 tabwidget_->addTab(paneProfile_, tr("Length profiles"));
 tabwidget_->addTab(paneCompensation_, tr("Compensation"));
 tabwidget_->addTab(paneMetadata_, tr("Dataset info"));

 QHBoxLayout* lay = new QHBoxLayout();

// QPushButton* b1 = new QPushButton("XXX", this);
// QPushButton* b2 = new QPushButton("yyy", this);

// layLeft->addWidget(b2);

// lay->addWidget(b1);

 lay->addLayout(layLeft);
 lay->addWidget(tabwidget_);
 
 QWidget* cent = new QWidget();
 cent->setLayout(lay);
 setCentralWidget(cent);

 //paneMetadata_->test();
 
 updateall();
 setAcceptDrops(true);
 adjustSize();
 resize(1000, size().height());
 show();

#ifdef FCS_QPROCESS_TEMP_FILE

 QString tmp_file_contents;
 KA::TextIO::load_file(FCS_QPROCESS_TEMP_FILE, tmp_file_contents);
 qDebug() << "FCS_QPROCESS_TEMP_FILE: " << tmp_file_contents;

 if(!tmp_file_contents.isEmpty())
 {
  QString tf = FCS_QPROCESS_TEMP_FILE;
  KA::TextIO::save_file(tf, "");
  KA::TextIO::save_file(tf + ".bak.txt", tmp_file_contents);
  load_selected_file(tmp_file_contents.trimmed());
 }

#endif // def FCS_QPROCESS_TEMP_FILE
}


void MainWindow::reset_pane_views_current_index_data(int x, int y)
{
 paneViews_->reset_current_index_data(x, y);

 viewsw_->update_view_names();
}


void MainWindow::load_selected_file(QString sf)
{
 qDebug() << "sf: " << sf;

 QFileInfo qfi(sf);
 lastDirectory_ = qfi.absoluteDir();
 QFile qf(sf);
 loadFile(qf);

 paneViews_->reset_index_data();
 paneViews_->reset_current_index_data(0, 1);

/*

//?    File f=new File(sf);
//?    mw.lastDirectory=f.getParentFile();
//?    mw.loadFile(f);
//?

 Dataset* ds = get_last_dataset();

 if(ds)
 {
  paneMetadata_->test(ds);
  cytolib::MemCytoFrame* cyto_frame = ds->cyto_frame();
  QMap<QString, QString>& qmap = cyto_frame->header_qmap(); 
  //n8 num = ds->getNumObservations();
  
  u1 nch = ds->getNumChannels();

  current_column_names_.resize(nch);
  for(u1 c = 1; c <= nch; ++c)
  {
   QString key = QString("$P%1N").arg(c);
   auto it = qmap.find(key);
   if(it != qmap.end())
   {
    current_column_names_[c - 1] = it.value();    
   }
  } 

  ds->set_current_column_names(&current_column_names_);
 }

 paneViews_->test_one_view();

 paneViews_->reset_index_data();reset_current_index_data(
*/

}

void MainWindow::get_pane_views_mpf_data(int& xcol, int& ycol,
  signed int& xsk, signed int& ysk,
  signed int& xsh, signed int& ysh)
{
 paneViews_->get_mpf_data(xcol, ycol, xsk, ysk, xsh, ysh);
}


void MainWindow::update_pane_views(int xcol, int ycol,
  signed int xsk, signed int ysk, signed int* xsh, signed int* ysh)
{
 Dataset* ds = get_last_dataset();
 MPF_Package* mpfp = ds->mpf_package();

 mpfp->columns()[0] = xcol;
 mpfp->columns()[1] = ycol;

 if(xsk != 0)
   mpfp->dimension_skews()[0] = xsk;
 if(ysk != 0)
   mpfp->dimension_skews()[1] = ysk;

 if(xsh)
   mpfp->dimension_shifts()[0] = *xsh;
 if(ysh)
   mpfp->dimension_shifts()[1] = *ysh;

 paneViews_->test_one_view();
 viewsw_->test_update_views(ds, xcol, ycol);

}


FacsanaduProject* MainWindow::getProject()
{
 return project_;
}
 
void MainWindow::updateall()
{
 bool wasUpdating = isUpdating_;
 isUpdating_ = true;
 viewsw_->updateViewsList();
 gatesw_->updateGatesList();
 datasetsw_->updateDatasetList();
 pc_->updateChannelList();
 paneCompensation_->updateForm();
 dogating();
 isUpdating_ = wasUpdating;
 dothelayout();
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
 QMainWindow::resizeEvent(e);
 dothelayout();
}
  
 // // Event: User drags something onto widget
void MainWindow::dragEnterEvent(QDragEnterEvent* event) 
{
 if(event->mimeData()->hasFormat("text/uri-list"))
   event->acceptProposedAction();
}


 // // Event: User drops MIME onto widget
void MainWindow::dropEvent(QDropEvent* event)
{
 try
 {
  for(QUrl url : event->mimeData()->urls())
  {
   QFile qf(url.toLocalFile()); //  * f = new File(url.path());
   QFileInfo qfi(qf);
   lastDirectory_ = qfi.absoluteDir();
   loadFile(qf);
  }
 }
 catch (Facs_IOException e)
 {
  // TO DO ...
  // e->printStackTrace();
 }
}

//#ifdef HIDE_THREAD

void _MainWindow_GateCalcThread::callbackDoneCalc(Dataset* dataset)
{
 emit callbackDoneCalc_signal(dataset);
}
 

//GateCalcThread MainWindow::calcthread = new GateCalcThread;
//{
//};

//#endif // def HIDE_THREAD
 
void MainWindow::action_angelscript()
{
 Dataset* ds = get_last_dataset();
 
 //qDebug() << "ds path: " << ds->file_source_name();

 QString path = QString("%1/%2.mpf.txt")
   .arg(FCS_MPF_FOLDER).arg(ds->file_source_name());

/*
 QString asfile = QString("%1/t2.as")
   .arg(AS_ROOT_DIR);

 QFileInfo qfi(ANGELSCRIPT_FILE);

 qDebug() << "as ... " << ANGELSCRIPT_FILE << "-f" << asfile << "-m" 
   << path << qfi.absolutePath();
 QFileInfo qfi(FCS_QPROCESS_PATH);
 QString wd = qfi.absolutePath();
 QString fn = qfi.fileName();
 fn.prepend("/_");
 fn.prepend(wd);
 QString text;
 KA::TextIO::load_file(FCS_QPROCESS_PATH, text);
 text.replace("@TARGETS_DESTDIR", TARGETS_DESTDIR);
 KA::TextIO::save_file(fn, text);

 QStringList args {fn};
*/

// QString program = ANGELSCRIPT_SHELL_TMPL; // QString("%1/facs-bridge-hgdm-console").arg(TARGETS_DESTDIR);

 QString base = ANGELSCRIPT_SHELL_BASE;
 QString tmpl = base + ".tmpl";
 QString text;
 KA::TextIO::load_file(tmpl, text);
 text.replace("@TARGETS_DESTDIR", TARGETS_DESTDIR);
 text.replace("@f", base);
 text.replace("@m", path);
 KA::TextIO::save_file(tmpl + ".sh", text);


 qDebug() << "program = " << "/bin/sh";
 qDebug() << "arguments = " << QStringList{tmpl + ".sh"};

 QProcess proc; 

 proc.setProgram("/bin/sh");
 proc.setArguments({tmpl + ".sh"});

 //proc.setArguments({"-f", asfile, "-m", path}); //, qfi.absolutePath());
 //proc.setWorkingDirectory(qfi.absolutePath());
 proc.start();

 proc.waitForFinished();

 QString resp = qPrintable(proc.readAllStandardError());

// QByteArray qba = proc.readAllStandardOutput();
 qDebug() << "\nProcess Output\n\n==============\n";

 qDebug() << resp;

 QString det = qPrintable(proc.readAllStandardOutput());


 //QMessageBox::information(this, "AngelScript Response", resp);

 QMessageBox qmb;

 qmb.setWindowTitle("AngelScript Response");
 qmb.setText(resp);
 qmb.setDetailedText(det.prepend("AngelScript Source\n---------------------------\n"));

 qmb.setInformativeText("(Click \"Show Details\" to view code)");

 qmb.addButton("Ok", QMessageBox::YesRole);

 auto buttons = qmb.buttons();
 auto it = std::find_if(buttons.begin(), buttons.end(), [&](QAbstractButton* btn){
    return qmb.buttonRole(btn) == QMessageBox::ActionRole;
 });
 if(it != buttons.end())
 {
  qDebug() << "Found " << (*it)->text();
  (*it)->setText("Show Code ...");
  qDebug() << "Found " << (*it)->text();
 }

 qmb.setIcon(QMessageBox::Information);

 //QAbstractButton* yes = qmb.addButton(QString("More (PDF) ..."), QMessageBox::YesRole);

 qmb.exec();

 proc.close();
}


void MainWindow::action_save_view()
{
 MPF_Package* mpfp = paneViews_->view_to_mpf();
 
 Dataset* ds = get_last_dataset();
 
 //qDebug() << "ds path: " << ds->file_source_name();

 QString path = QString("%1/%2.mpf.txt")
   .arg(FCS_MPF_FOLDER).arg(ds->file_source_name());

 mpfp->save_to_file(path);
 //paneViews_ viewspane ViewWidget 
}

void MainWindow::action_load_view()
{ 
 Dataset* ds = get_last_dataset();
 
 //qDebug() << "ds path: " << ds->file_source_name();

 QString path = QString("%1/%2.mpf.txt")
   .arg(FCS_MPF_FOLDER).arg(ds->file_source_name());

 MPF_Package* mpfp = new MPF_Package;

 mpfp->load_from_file(path);

 paneViews_->load_view_from_mpf(mpfp); 

 //?viewsw_->updateViewsList();
 //?paneViews_->updateViews();

}



// // Action: New project
void MainWindow::actionNewProject()
{
 project_ = new FacsanaduProject();
 updateall();
}
 
// // Open a project
void MainWindow::actionOpenProject()
{
 QFileDialog dia; // = new QFileDialog();
 dia.setFileMode(QFileDialog::ExistingFile);
 dia.setDirectory(lastDirectory_.absolutePath());
 dia.setNameFilter(tr("Project files") + " (*.facsanadu)");
 if(dia.exec())
 {
  QFile qf( dia.selectedFiles().value(0) );
  QFileInfo qfi(qf);
  lastDirectory_ = qfi.absoluteDir();
  try
  {
   // //  do we want to use XML? ...
   // project_ = FacsanaduXML::importXML(f);
   currentProjectFile_ = qfi.absoluteFilePath();
  }
  catch (Facs_IOException e)
  {
   //QTutil.showNotice(this, e.getMessage());
   //e.printStackTrace();
  }
  updateall();
 } 
}
  
// // Action: Save project
void MainWindow::actionSaveProject()
{
 if( currentProjectFile_.isEmpty() )
   actionSaveProjectAs();

 else 
 {
  try
  {
   // // xml?
    // FacsanaduXML.exportToFile(project, currentProjectFile);
  }
  catch (Facs_IOException e)
  {
   // QTutil.showNotice(this, e.getMessage());
   // e.printStackTrace();
  }
 }
}
 
// // Action: Save as... file
void MainWindow::actionSaveProjectAs()
{
 QFileDialog dia; // = new QFileDialog();
 dia.setFileMode(QFileDialog::AnyFile);
 dia.setAcceptMode(QFileDialog::AcceptSave);
 dia.setDirectory(lastDirectory_.absolutePath());
 dia.setDefaultSuffix("facsanadu");
 dia.setNameFilter(tr("Project files")+" (*.facsanadu)");

 if( dia.exec() )
 {
  QFile qf(dia.selectedFiles().value(0));
  QFileInfo qfi(qf);
  lastDirectory_ = qfi.absoluteDir();
  currentProjectFile_ = qfi.absoluteFilePath();
  actionSaveProject();
 }
}
  
// // Action: Export graphs
void MainWindow::actionExportGraphs()
{
 LinkedList<Dataset*> listds = getSelectedDatasets();
 LinkedList<ViewSettings*> listviews = getSelectedViews();
 
 GraphExportWindow w; // = new GraphExportWindow();
 w.exec();
 if( w.wasOk() )
 {
  QFileDialog dia; //= new QFileDialog();
  dia.setFileMode(QFileDialog::AnyFile);
  dia.setNameFilter( tr("Image files)") + " (*.png)" );
  dia.setAcceptMode(QFileDialog::AcceptSave);
  dia.setDefaultSuffix("png");

  if( dia.exec() )
  {
   try
   {
    QFile qf(dia.selectedFiles().value(0));
    GraphExporter::render(qf, project_, listds, listviews, w.splitByDataset(), w.splitByView(), w.getWidth(), w.getHeight());
   }
   catch (Facs_RuntimeException e)
   {
    // QTutil.showNotice(this, e.getMessage());
    // e.printStackTrace();
   }
  } 
 }
}
 
// //
void MainWindow::actionExportStatistics()
{
 paneStats_->actionExportCSV();
}
 
void MainWindow::actionExportCSV()
{
 try
 {
  LinkedList<Dataset*> dsList = datasetsw_->getSelectedDatasets();

  if(dsList.isEmpty())
  {
   // QTutil.printError(this, tr("No datasets selected"));
  }
  else if(dsList.size()==1)
  {
   QFileDialog dia; // =new QFileDialog();
   dia.setFileMode(QFileDialog::AnyFile);
   dia.setNameFilter(tr("CSV files (*.csv)"));
   dia.setAcceptMode(QFileDialog::AcceptSave);
   dia.setDefaultSuffix("csv"); 
 
   if( dia.exec() )
   {
    try
    {
     QFile qf(dia.selectedFiles().value(0));
     ExportFcsToCSV::save(dsList.value(0), 
      qf);
     /*
      PrintWriter fw=new PrintWriter();
      fw.println(tableStats.allToCSV());
      fw.close();
     */
    }
    catch (Facs_IOException e)
    {
//     QTutil.showNotice(this, e.getMessage());
//     e.printStackTrace();
    }
   } 
  }
  else
  {
   QFileDialog dia; // =new QFileDialog();
   dia.setFileMode(QFileDialog::DirectoryOnly);
   //dia.setNameFilter(tr("CSV files (*.csv)"));
   dia.setAcceptMode(QFileDialog::AcceptSave);
   //dia.setDefaultSuffix("csv"); 

   if( dia.exec() )
   {
    try
    {
     for(Dataset* oneDataset : dsList)
     {
      QFile parent(dia.selectedFiles().value(0));
       // //  why do we need parent?
      QFile qf(oneDataset->getName() + ".csv", &parent);
      ExportFcsToCSV::save(oneDataset, qf); ////parent, 
        //qf));
     }
    }
    catch (Facs_IOException e)
    {
//     QTutil.showNotice(this, e.getMessage());
//     e.printStackTrace();
    }
   } 
  }
 }
 catch (Facs_Exception e)
 {
//  QTutil.printError(this, tr("Failed to save file: ")+e.getMessage());
//  e.printStackTrace();
 }
}
 
// // Load one file
void MainWindow::loadFile(QFile& path) // throws IOException
{
 project_->set_main_window(this);
 project_->addDataset(path);
 EventDatasetsChanged evd; // EventDatasetsChanged();
 handleEvent(evd);
}

 

// // Get selected views
LinkedList<ViewSettings*> MainWindow::getSelectedViews()
{
 return viewsw_->getSelectedViews();
}

Dataset* MainWindow::get_last_dataset()
{
 if(project_->datasets().isEmpty())
   return nullptr;
 return project_->datasets().first();
}

// // Get selected datasets
LinkedList<Dataset*> MainWindow::getSelectedDatasets()
{
 return datasetsw_->getSelectedDatasets();
}


void MainWindow::actionDsChanged()
{
 //Update list of selected datasets, in a thread neutral list

 // synchronized (mutex) //selDatasetsCache_)
 {
  QMutexLocker lock(&selDatasetsCache_mutex_);
  selDatasetsCache_.clear();
  selDatasetsCache_.append(datasetsw_->getSelectedDatasets());
 }

 //Better to send a signal here instead?
 paneViews_->invalidateCache();
 dogating();
 dothelayout();
 paneMetadata_->updateForm();
}

// // Get selected gates
LinkedList<Gate*> MainWindow::getSelectedGates()
{
 return gatesw_->getSelectedGates();
}

// // Update gating results
void MainWindow::dogating()
{
 //For speed, only do selected ones
 //

 Dataset* ds = get_last_dataset();

 if(!ds)
   return;

 QList<Dataset*> dss;
 dss.push_back(ds);

 project_->performGating(dss);

 //?project_->performGating(getSelectedDatasets());
 calcthread_->wakeup();
}
 
 /**
  * Entry point
  */
// public static void main(String[] args)
// {
// QApplication.initialize(QtProgramInfo.programName, args);
// QCoreApplication.setApplicationName(QtProgramInfo.programName);
// new MainWindow();
// QTutil.execStaticQApplication(); 
// }

// // Event bus
void MainWindow::handleEvent(FacsanaduEvent* event)
{
 FacsanaduEvent::Description d = event->get_description();

 switch(d)
 // if(event instanceof EventGatesChanged)
 {
 case FacsanaduEvent::Description::EventGatesChanged:
/*
  gatesw_->updateGatesList();
  paneViews_->invalidateCache();
  dogating();
  dothelayout();
*/
  break;

  //else if(event instanceof EventViewsChanged) 
 case FacsanaduEvent::Description::EventViewsChanged:

  qDebug() << "FacsanaduEvent::Description::EventViewsChanged ...";
  dogating();
  dothelayout();


  //?  viewsw_->updateViewsList(); //just added. problem?
/*
  paneViews_->invalidateCache();
  dogating();
  dothelayout();
*/
  break;

 //else if(event instanceof EventCompensationChanged)
 case FacsanaduEvent::Description::EventCompensationChanged:
/*
  project_->updateCompensation();
  dogating();
  dothelayout();
*/
  break;
 
  //else if(event instanceof EventGatesMoved)
 case FacsanaduEvent::Description::EventGatesMoved:
//?  dothelayout();
  break;

  //else if(event instanceof EventDatasetsChanged)
 case FacsanaduEvent::Description::EventDatasetsChanged:
  qDebug() << "EDC ...";

  //? here? ...
  paneCompensation_->updateForm();

  datasetsw_->updateDatasetList();
  paneViews_->invalidateCache();
  dogating();

  //Dataset* ds = get_last_dataset();
  paneMetadata_->test(get_last_dataset());
  //?paneMetadata_->updateForm();

  //? here?
  viewsw_->updateViewsList();
  paneViews_->updateViews();



  break;
  //else if(event instanceof EventSetViewTool)
  //{
  //?paneViews.setTool(((EventSetViewTool) event).choice);
  //}
 default:
  throw new Facs_RuntimeException; // ...  ("!!!");
  break;
 }
}

void MainWindow::dothelayout()
{
 if(!isUpdating_)
 {
  paneViews_->updateViews();
  paneStats_->updateStats();
  paneProfile_->updateViews();
  QApplication::processEvents();
  //or flush?
 }
}

// // Add a gate with a suggested parent
void MainWindow::addGate(Gate* suggestParent, Gate* g)
{
 gatesw_->addGate(suggestParent, g);
}

// // Get currently selected measures
LinkedList<GateMeasure*> MainWindow::getSelectedMeasures()
{
 return gatesw_->getSelectedMeasures();
}
 
// // Show About-information
void MainWindow::actionAbout()
{
 (new DialogAbout())->exec();
}

 
// // Open up website
void MainWindow::actionWebsite()
{
 QDesktopServices::openUrl(QUrl("http://www.facsanadu.org"));
}

 
// // Set number of CPU cores
void MainWindow::actionSetNumCores()
{
//?
// int th = QInputDialog::getInt(this, QtProgramInfo::programName, 
//   tr("Number of cores: "), calcthread_->getNumCores());

// if( (th >= 1) && (th <= 128) )
//   calcthread_->setNumCores(th);

}


void MainWindow::recalcProfChan(ProfChannel* chChanged)
{
 // TODO Auto-generated method stub
 project_->recalcProfChan(chChanged);
 dothelayout();
 //handleEvent(new EventViewsChanged()); //maybe too light
}

// // Ensure proper exit
// @Override
void MainWindow::closeEvent(QCloseEvent* arg)
{
 QMainWindow::closeEvent(arg);
 exit(0);
}

#ifdef HIDE

#endif //def HIDE

