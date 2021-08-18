#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

#include <QTimer>

#define window_size_x 670
#define window_size_y 540
#define max_window_size_x 1050 //da capire la risoluzione del pc
#define max_window_size_y 680 //da capire la risoluzione del pc
#define max_resize 10
#define min_resize 0
#define default_resize 5
#define version 1.7


// // instead of \t ...

#define TAB_DIVIDER '|'
#define TAB_DIVIDER_STR "|"


#include "iat-model/axfi/axfi-annotation.h"

#include "zoom-and-navigate-frame.h"


class Special_Input_Dialog : public QInputDialog
{
 int* autogen_index_;

public:

 Special_Input_Dialog(int* autogen_index, QWidget* parent = nullptr);

 void customMenuRequested(QPoint pos);

 static QString get_text(int* autogen_index, QWidget *parent, const QString &title, const QString &label,
                 QLineEdit::EchoMode echo = QLineEdit::Normal,
                 const QString &text = QString(), bool *ok = nullptr,
                 Qt::WindowFlags flags = Qt::WindowFlags(),
                 Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

};


QString Special_Input_Dialog::get_text(int* autogen_index, QWidget *parent, const QString &title, const QString &label,
                              QLineEdit::EchoMode mode, const QString &text, bool *ok,
                              Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
//?    QAutoPointer<QInputDialog> dialog(new QInputDialog(parent, flags));
 Special_Input_Dialog* dialog = new Special_Input_Dialog(autogen_index, parent); //, flags);
    dialog->setWindowTitle(title);
    dialog->setLabelText(label);
    dialog->setTextValue(text);
    dialog->setTextEchoMode(mode);
    dialog->setInputMethodHints(inputMethodHints);

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;
    if (ret) {
        return dialog->textValue();
    } else {
        return QString();
    }
}

Special_Input_Dialog::Special_Input_Dialog(int* autogen_index, QWidget* parent)
  :  autogen_index_(autogen_index), QInputDialog(parent)
{
 setContextMenuPolicy(Qt::CustomContextMenu);
 connect(this, &Special_Input_Dialog::customContextMenuRequested,
   [this](QPoint pos)
 {
  qDebug() << "pos: " << pos;

  QMenu* menu = new QMenu(this);//

  menu->addAction("Autogenerate", [this]
  {
   this->setTextValue(QString("auto_%1").arg(++*this->autogen_index_));
  });

  menu->popup(mapToGlobal(pos));
 });
}


//Questa classe √® quella principale
//Da qui gestisce tutte le altre classi e tutti i dati in loro contenuti
//Gestisce in particolar modo la gui e tutte le operazione ad essa commesse

using namespace std;

#include "iat-model/axfi/axfi-annotation-group.h"

void MainWindow::check_init_axfi_annotation_group()
{
 if(!axfi_annotation_group_)
   axfi_annotation_group_ = new AXFI_Annotation_Group();
}


void MainWindow::init_display_scene_item(DisplayImage_Scene_Item* si)
{
 display_scene_item_ = si;

 display_scene_item_->setGeometry(0,0,0,0);
 display_scene_item_->setObjectName(QString::fromUtf8("ImageDisplayWidget"));

 connect(display_scene_item_,SIGNAL(onLineDraw(QList<DisplayImage::shape>)),this,SLOT(onDrawLine(QList<DisplayImage::shape>)));
 connect(display_scene_item_,SIGNAL(setTuple(QString)),this,SLOT(getTuple(QString)));


}


//costruttore
MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent) //??, ui(new Ui::MainWindow)
{
   //?menuBar->setGeometry(QRect(0, 0, 739, 22));
 file_menu_ = menuBar()->addMenu("File"); // new QMenu(menubar_);
 help_menu_ = menuBar()->addMenu("Help"); // new QMenu(menubar_);
 tools_menu_ = menuBar()->addMenu("Tools"); // new QMenu(menubar_);

   //?menuFile->setObjectName(QString::fromUtf8("menuFile"));
//? help_menu_ = new QMenu(menubar_);

   //?menuHelp->setObjectName(QString::fromUtf8("menuHelp"));

//? tools_menu_ = new QMenu(menubar_);
  //? menuTools->setObjectName(QString::fromUtf8("menuTools"));

 menuBar()->addAction(file_menu_->menuAction());
 menuBar()->addAction(tools_menu_->menuAction());
 menuBar()->addAction(help_menu_->menuAction());

// menubar_->addMenu(file_menu_);
// menubar_->addMenu(help_menu_);
// menubar_->addMenu(tools_menu_);


 actionAnnotate_Single_Image = new QAction("Load Image", this);
 actionLoad_annotations = new QAction("Load Notes", this);
 actionQuit = new QAction("Quit", this);
 actionInstructions = new QAction("Instructions", this);
 actionOptions = new QAction("Options", this);

 file_menu_->addAction(actionAnnotate_Single_Image);
//? file_menu_->addAction(actionAnnotate_Multiple_Image);
 file_menu_->addSeparator();
 file_menu_->addAction(actionLoad_annotations);
 file_menu_->addSeparator();
 file_menu_->addAction(actionQuit);
 help_menu_->addAction(actionInstructions);
 tools_menu_->addAction(actionOptions);
//?? tools_menu_->addAction(actionCreate_List);

 connect(actionAnnotate_Single_Image,SIGNAL(triggered()), this, SLOT(on_actionAnnotate_Single_Image_triggered()));
 connect(actionOptions,SIGNAL(triggered()), this, SLOT(on_actionOptions_triggered()));
 connect(actionQuit,SIGNAL(triggered()), this, SLOT(on_actionQuit_triggered()));

 autogen_index_ = 0;
 axfi_annotation_group_ = nullptr;

 main_frame_ = new QFrame(this);

 shape_select_frame_ = new Shape_Select_Frame(main_frame_);
 zoom_frame_ = new Zoom_and_Navigate_Frame(main_frame_);

 connect(zoom_frame_, SIGNAL(zoom_factor_changed(r8)), this, SLOT(handle_zoom_factor_changed(r8)));

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::image_top_left_button_clicked, [this](bool)
 {
  display_image_->recenter_scroll_top_left();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::center_image_button_clicked, [this](bool)
 {
  display_image_->recenter_scroll_center();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::pan_mode_changed, [this](bool mode)
 {
  if(mode)
    display_image_data_->set_pan_mode();
  else
    display_image_data_->unset_pan_mode();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::multi_draw_set, [this]()
 {
  display_image_data_->set_multi_draw();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::multi_draw_unset, [this]()
 {
  display_image_data_->unset_multi_draw();
 });

 top_layout_ = new QHBoxLayout;

 top_layout_->setContentsMargins(0,0,0,0);

 shape_select_frame_->setContentsMargins(0,0,0,0);

 top_layout_->addWidget(shape_select_frame_);

 top_layout_->addStretch(1);

 QSizePolicy spr(QSizePolicy::Preferred, QSizePolicy::Preferred);
 spr.setHorizontalStretch(30);
 zoom_frame_->setSizePolicy(spr);

 zoom_frame_->setContentsMargins(0,0,0,0);

 top_layout_->addWidget(zoom_frame_);

// top_layout_->addStretch(1);


 main_layout_ = new QVBoxLayout;

 main_layout_->addLayout(top_layout_);

 display_image_ = new DisplayImage(main_frame_);

 display_image_->setMinimumHeight(300);

 display_image_->set_main_window(this);

 display_scene_item_ = nullptr;
// display_scene_item_ = new DisplayImage_Scene_Item;//(main_frame_);

 main_layout_->addWidget(display_image_);

 display_image_data_ = display_image_->display_image_data();

// display_scene_item_ = display_image_->image_scene_item();

// display_scene_item_-> load_image("/home/nlevisrael/gits/annot/ctg-temp/pics/testdia.png");

 //?? ui->setupUi(this);


// connect(display_scene_item_,SIGNAL(onLineDraw(QList<DisplayImage::shape>)),this,SLOT(onDrawLine(QList<DisplayImage::shape>)));
// connect(display_scene_item_,SIGNAL(setTuple(QString)),this,SLOT(getTuple(QString)));


 connect(&optionsDialog_,SIGNAL(ColorsThickness(int,int,int,int,int,int,int,int,int,int,int)),
         this,SLOT(getColorsThickness(int,int,int,int,int,int,int,int,int,int,int)));


// connect(ui->_Shape_Select_Frame,
 connect(shape_select_frame_,
   &Shape_Select_Frame::shape_selection_changed, [this](QString sel)
 {
  if(sel == "Rectangle")
    setup_shape_rectangle();
  else if(sel == "Polygon")
    setup_shape_polygon();
  else if(sel == "Ellipse")
    setup_shape_ellipse();
 });

 main_frame_->setLayout(main_layout_);

 setCentralWidget(main_frame_);

 set_initial_gui();

 // assume a rectangle to begin with ...
 setup_shape_rectangle();

 show();
}

//distruttore
MainWindow::~MainWindow()
{
 //??  delete ui; //distruge in particola modo l'interfaccia
}

//metodo che setter√  l'interfaccia grafica all'avvio
void MainWindow::set_initial_gui()
{
 //qui viene disattivata tutta la gui e viene ben definita l-istanza display

 //?? ui->actionCreate_List->setDisabled(true);

// ui->Square->setDisabled(true);
// ui->Ellipse->setDisabled(true);
// ui->Polygon->setDisabled(true);

// ui->ClearSelected->setDisabled(true);
// ui->ClearLast->setDisabled(true);
// ui->ClearAll->setDisabled(true);
// ui->_Shape_Select_Frame->set_clear_selected_btn_disabled();
// ui->_Shape_Select_Frame->set_clear_last_btn_disabled();
// ui->_Shape_Select_Frame->set_clear_all_btn_disabled();

 shape_select_frame_->set_clear_selected_btn_disabled();
 shape_select_frame_->set_clear_last_btn_disabled();
 shape_select_frame_->set_clear_all_btn_disabled();


// ui->ObjectListView->setDisabled(true);
// ui->InstanceListView->setDisabled(true);
// ui->NumberListView->setDisabled(true);
// ui->EndProject->setDisabled(true);
// ui->LoadNext->setDisabled(true);
// ui->LoadPrevious->setDisabled(true);
// ui->Save->setDisabled(true);

// //ui->Highlight->setDisabled(true);
// ui->_Shape_Select_Frame->set_highlight_ckb_disabled();


// ui->ResizeSlider->setDisabled(true);
// ui->ResizeSlider->setMinimum(min_resize);
// ui->ResizeSlider->setMaximum(max_resize);
// ui->ResizeSlider->setValue(default_resize);
 ctrlIsPressed_ = false;
 shiftIsPressed_ = false;

 sizew_ = window_size_x;
 sizeh_ = window_size_y;

//? display_->setParent(ui->scrollContents);
 //?ui->scrollContents->resize(0,0);qgraphicsview position visibile top left


 QString title = "Image Annotation Tool (v." + QString::number(version) + ")";
 QMainWindow::setMinimumSize(sizew_, sizeh_);
 QMainWindow::setWindowTitle(title);
}


void MainWindow::handle_zoom_factor_changed(r8 factor)
{
// qDebug() << "factor: " << factor;

 display_image_->reset_scale(factor);
}


//metodo che esegue il backUp dei dati
void MainWindow::makeBackUp()
{
 backUpHere_.workspace=workspace_;
 backUpHere_.image_filename_path = image_filename_path_;
 backUpHere_.list_filename_path = list_filename_path_;
 backUpHere_.txt_filename_path = txt_filename_path_;
 backUpHere_.project_filename_path = project_filename_path_;
 backUpHere_.ShapeID = shapeID_;
 backUpHere_.mapObjectInstance = mapObjectInstance_;
 backUpHere_.mapInstanceNumber = mapInstanceNumber_;
 backUpHere_.background = background_;
 backUpHere_.scaledEdits = scaledEdits_;
 backUpHere_.sizeh = sizeh_;
 backUpHere_.sizew = sizew_;
 backUpHere_.resize_factor = resize_factor_;
 backUpHere_.title = QMainWindow::windowTitle();
}

//metodo legato al comando Options
void MainWindow::on_actionOptions_triggered()
{
 if(optionsDialog_.exec()>0)
 {

 } //viene eseguito il programma options
}

//metodo attivato dal signal colorsThickness presente in Options
void MainWindow::getColorsThickness(int radius, int thickness, int myRed, int myGreen, int MyBlue, int sqRed, int sqGreen, int sqBlue, int shapeRed, int shapeGreen, int shapeBlue)
{
 //quando viene attivato il compito di MainWindow e quello di fare da tramite e cambiare i colori in display con il metodo pubblico setClororThickness
 display_image_data_->setColorsThickness(radius, thickness, myRed, myGreen, MyBlue, sqRed, sqGreen, sqBlue, shapeRed, shapeGreen, shapeBlue);
}

//metodo legato al comando Create List (WIP)
void MainWindow::on_actionCreate_List_triggered(){
 if(listToolDialog_.exec()>0)
 {}
}

//metodo legato al comando Annotate Single Image
void MainWindow::on_actionAnnotate_Single_Image_triggered()
{
 //all-inizio viene chiesto all-untente se vuole salvare il lavoro svolto fino al quel momento (se necessario)
 QMessageBox::StandardButton reply = QMessageBox::No;

 if(false) //?  ui->Save->isEnabled())
 { //il tasto save √® il pi√π adatto falg di controllo
  reply = QMessageBox::question(this,"Question","Do you want to save before annotate a new image?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
 }

 if(reply != QMessageBox::Cancel)
 {
  if(reply==QMessageBox::Yes)
    on_Save_clicked();
  makeBackUp(); //si esegue un backup in quanto l-utente potrebbe interrompere il processo e rendere necessario un ripristino dei dati
  if(workspace_.isEmpty())
    workspace_=qApp->applicationDirPath();

  // // set it temporarily
  QString ws =  ROOT_FOLDER "/../pics";

  QString filters = "Images (*.jpg *.png *.bmp)";
  QFileDialog qdialog;

  image_filename_path_ = qdialog.getOpenFileName(this, "Open Image", ws, filters);

  display_image_data_->setNameSelected(true);

  if(!image_filename_path_.isNull())
  { //se √® stata scelta l-immagine
   if(!project_filename_path_.isEmpty() && imageSequence_.indexOf(image_filename_path_) != -1)
   {
    //questo codice viene attivato solo se si st√  lavorando in un progetto e per questo project_filename_path √® il miglior flag
    //qui dentro si entra se l-utente st√  caricando un-immagine gi√  annotata durante il progetto
    //quindi per avere tutte le annotazioni precedenti si esce dal contesto e si passa a caricare
    //il file di annotazione tramite load_annotation
    txt_filename_path_ = pwizard_.projectpath + "/" + pwizard_.projectName+"/";
    QString imageName = image_filename_path_;
    int pos;
    for(pos=imageName.size(); imageName[pos]!='/'; --pos);
    imageName.remove(0, pos+1);
    imageName.remove(imageName.size()-4, 4);
    imageName += ".txt";
    txt_filename_path_ += imageName;
    load_annotation(); //load_annotation per lavorare richiede un txt_filename_path che qui viene creato
   }
   else
   {
    load_image(); //viene invocato load_image che passer√  a processare l-immagine scelta
    //viene chiesto se si vuole caricare una nuova lista in caso affermativo viene invocasto load_List

//    QMessageBox::StandardButton reply = QMessageBox::Yes;
//    if(!list_filename_path_.isEmpty())
//      reply=QMessageBox::question(this,"Question!","Do you want to load a new list?",QMessageBox::Yes|QMessageBox::No);

//    if(reply==QMessageBox::Yes)
//    {
//     QFileDialog qdialog;
//     // //                    list_filename_path=qdialog.getOpenFileName(this,"Open List",qApp->applicationDirPath(),"*.lst");
//     list_filename_path_ = qdialog.getOpenFileName(this,
//       "Open List", ROOT_FOLDER "..", "*.lst");
//    }

    list_filename_path_ = ROOT_FOLDER "../default.lst";

    if(!list_filename_path_.isEmpty())
    {
     load_list();
     defaultView();
    }
    else doBackUp(); //in caso di interruzione viene cancellato tutte ed eseguito il ripristino dei dati
   }
  }
  else doBackUp(); //in caso di interruzione viene cancellato tutte ed eseguito il ripristino dei dati
 }
}

//metodo legato al comando Annotate Multiple Image
void MainWindow::on_actionAnnotate_Multiple_Image_triggered()
{
 //viene chiesto se si vuole salvare
 QMessageBox::StandardButton reply = QMessageBox::No;
 if(true) //?  (ui->Save->isEnabled())
 {
  reply = QMessageBox::question(this,"Question","Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
 }
 if(reply!=QMessageBox::Cancel)
 {
  if(reply==QMessageBox::Yes) on_Save_clicked();
  makeBackUp(); //viene eseguito un backup
  if(pwizard_.exec() > 0)
  {
   //viene eseguito il wizard che chieder√  di dare un nome al progetto
   //e di specificare dove si vuole creare la cartella con quel nome
   QDir dir(pwizard_.projectpath);
   dir.mkdir(pwizard_.projectName);
   project_filename_path_ = pwizard_.projectpath; //attiviamo il flag
   on_actionAnnotate_Single_Image_triggered();

//?
//   ui->LoadNext->setDisabled(false);
//   ui->EndProject->setDisabled(false);
//   ui->actionAnnotate_Single_Image->setDisabled(true);
//   ui->actionAnnotate_Multiple_Image->setDisabled(true);
//   ui->actionLoad_annotations->setDisabled(true);
  }
  else doBackUp(); //in caso di interruzioni
 }
}

//metodo legato al comando Load Annotation
void MainWindow::on_actionLoad_annotations_triggered()
{
 //viene chiesto se si vuole salvare
 QMessageBox::StandardButton reply = QMessageBox::No;
 if(true) //? (ui->Save->isEnabled())
 {
  reply = QMessageBox::question(this,"Question","Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
 }
 if(reply!=QMessageBox::Cancel){
  if(reply==QMessageBox::Yes) on_Save_clicked();
  makeBackUp(); //si esegue un backup
  if(workspace_.isEmpty())
    workspace_ = qApp->applicationDirPath();
  QFileDialog qdialog;
  txt_filename_path_ = qdialog.getOpenFileName(this,"Load Annotation", workspace_, "*.txt");
  if(!txt_filename_path_.isNull())
  {
   if(!load_annotation())
     doBackUp(); //ripristino in caso di interruzioni
  }
  else
    doBackUp(); //si esegue il ripristino in caso di interruzioni
 }
}

//metodo legato al comando Instructions
void MainWindow::on_actionInstructions_triggered(){
 QMessageBox::information(this,"Instructions",
                          QString("Select 'Annotate Single Image' to start annotating a single image.\n")+
                          QString("Select 'Annotate Multiple Image' to start annotating a sequence of images.\n")+
                          QString("When you are annotating multiple images, use 'Load Next' and 'Load Previous' to navigate and 'End Project' to terminate.\n")+
                          QString("Select 'Load Annotations' to open a previously annotated image.\n\n")+
                          QString("Select the 'Shape' of the annotation and select the 'Object' and the 'Instance' before edit.\n")+
                          QString("Use Left-button to make the annotation.\n")+
                          QString("Hold down the Right-button inside the annotation or over its reference squares to move them.\n")+
                          QString("'Highlight' lights the reference Squares when passing over them.\n\n")+
                          QString("Shortcuts:\nAnnotate Single Image\t\tCtrl+N\nAnnotate Multiple\t\tCtrl+M\nLoad Annotation\t\tCtrl+L\n")+
                          QString("Quit\t\t\tCtrl+Q\nOptions\t\t\tCtrl+O\nInstructions\t\t\tCtrl+I\nSquare\t\t\tCtrl+Shift+S\nEllipse\t\t\tCtrl+Shift+E\nPolygon\t\t\tCtrl+Shift+P\n")+
                          QString("Highlight\t\t\tCtrl+Shift+H\nClear Selected\t\t\tCanc\nClear Last\t\t\tCtrl+Canc\nClear All\t\t\tCtrl+Shift+Canc\n")+
                          QString("Terminate Project\t\tCtrl+T\nLoad Next\t\t\tCtrl+PagUp\nLoad Previous\t\t\tCtrl+PagDown\nSave\t\t\tCtrl+S\n")+
                          QString("Zoom in\t\t\tCtrl+Plus\nZoom out\t\t\tCtrl+Minus\n"));
}

//metodo che prepara la finestra a stampare la nuova immagine
void MainWindow::load_image()
{
 cleanWindow(); //si esegue una pulizia dei dati e della finestra
 QFileInfo qfile(image_filename_path_);
 workspace_ = qfile.absolutePath();
 QString title="Image Annotation Tool (v."+QString::number(version)+") - ";
 if(project_filename_path_.isNull())
   title += image_filename_path_;//"/home/nlevisrael/gits/annot/ctg-temp/pics/testdia.png"
 else title+=pwizard_.projectpath + "/" + pwizard_.projectName;
 QMainWindow::setWindowTitle(title);

//? display_->clear_image(); //si pulisce anche display

 display_image_->load_image(image_filename_path_);

// display_->update();
// display_->repaint();


 QTimer::singleShot(0, [this]
 {
  display_image_->recenter_scroll_top_left();
 });

 //?? ui->ResizeSlider->setValue(default_resize);

//? resizeMethod(default_resize); //questo √® il metodo che processa l-immagne
}

//metodo che processa la lista scelta dall'utente e la carica
void MainWindow::load_list()
{
 QFile file(list_filename_path_);
 if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
 //una volta che la lista √® stata caricata si procede alla lettura ed a popolare le mappe
 QStringList objectList;
 while(!file.atEnd())
 {
  QString line = file.readLine();
  line.toStdString();
  int i;
  QString object;

  for(i=0; line[i]!='\t'; ++i)
  {
   if(i >= line.size())
     break;

   object.append(line[i]);
  }

  QString instance;

  for(i=i+1; (line[i]!='\n'&&i<line.size()); ++i)
  {
   if(i >= line.size())
     break;

   instance.append(line[i]);
  }

  bool findObject=false;
  for(int j=0;j<objectList.size();++j)
    if(object==objectList.at(j))
      findObject=true;
  bool findInstance=false;
  if(findObject)
  {
   QList<QString> correlatedInstance = mapObjectInstance_.values(object);
   for(int j=0; j<correlatedInstance.size(); ++j) if(instance == correlatedInstance.at(j)) findInstance=true;
  }
  if(!findObject)
  {
   objectList<<object;
   mapObjectInstance_.insert(object,instance);
  }
  if(findObject && !findInstance)
    mapObjectInstance_.insert(object,instance);
 }
 //?? ui->ObjectListView->addItems(objectList); //dalla lettura si prendono i valori da caricare nella prima colonna
 file.close();
 //?? ui->Save->setDisabled(false); //il save viene abilitato
}

//metodo che processa il file di annotazione scelto dall'utente
bool MainWindow::load_annotation()
{
 //questo metodo √® stato reso booleano perch√® pu√≤ fallire per vari motivi
 cleanWindow();
 if(project_filename_path_.isEmpty())
 { //modifica di comportamento
  QFileInfo qfile(txt_filename_path_);
  workspace_ = qfile.absolutePath();
 }
 else
 {
  QFileInfo qfile(image_filename_path_);
  workspace_ = qfile.absolutePath();
 }
 QString title = "Image Annotation Tool (v." + QString::number(version) + ") - ";
 if(project_filename_path_.isEmpty())
   title += workspace_;
 else
   title += pwizard_.projectpath + "/" + pwizard_.projectName;
 QMainWindow::setWindowTitle(title);
 QFile file(txt_filename_path_);

 if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   return false;

 QString line = file.readLine();

 if(!(line=="133518122014\n"))
   return false;
 //questo √® il "magic number" per scongiurare il fatto che l-utente carichi un file non coerente con il contesto

 line=file.readLine();

 if(project_filename_path_.isEmpty())
 {
  //modifica di comportamento
  if(line.at(1) == ':')
    image_filename_path_ = line;
  else
  {
   image_filename_path_ = txt_filename_path_;
   image_filename_path_.remove(image_filename_path_.size() - 4, 4);
   int pos;
   for(pos=line.size(); line[pos] != '.'; --pos);
   line.remove(0,pos);
   image_filename_path_ += line;
  }
 }
 else
   image_filename_path_=line;

 image_filename_path_.remove(image_filename_path_.size()-1, 1);

 //viene creato image_filename_path che avr√  il compito di indicare a resizeMethod quale immagine caricare
 QList<DisplayImage_Data::shape> outEdits;
 QStringList objectList;

 //qui il file viene processato
 while(!file.atEnd())
 {
  //fino a qui vengono lette object ed instance
  line = file.readLine();

  AXFI_Annotation* axa = new AXFI_Annotation;
  axa->from_compact_string(line);


  // // split the line on tabs ...
//?  QStringList parts = line.split(TAB_DIVIDER_STR);



//?  int sz = parts.size();

  //?line.toStdString();

//?  int i;
  DisplayImage_Data::shape another;

  QString object;
//?
//  for(i=0; line[i] != '\t'; ++i)
//    object.append(line[i]);
//  object = axa->scoped_identifiers().value(0);
//?  object = parts.value(0);

//?  i = line.indexOf('\t', i) + 1;

  QString instance;
//?
//  for(i = i + 1; line[i] != '\t'
//      && line[i] != '\n'
//      && i < line.size(); ++i)
//    instance.append(line[i]);
//  instance = axa->scoped_identifiers().value(1);
//?  instance = parts.value(1);

  object = axa->scoped_identifiers().value(0);
  instance = axa->scoped_identifiers().value(1);


  bool findObject=false;

  for(int j=0; j<objectList.size(); ++j)
    if(object == objectList.at(j))
      findObject=true;

  bool findInstance=false;

  if(findObject)
  {
   QList<QString> correlatedInstance = mapObjectInstance_.values(object);
   for(int j=0; j<correlatedInstance.size(); ++j)
     if(instance == correlatedInstance.at(j))
       findInstance=true;
  }

  //se la linea non √® finita
//  i = line.indexOf('\t', i) + 1;

//?  if( ( i + 1 ) >= line.size() )
  int sz = axa->scoped_identifiers().size();
  if(sz <= 2)
  {
   //+1 per sicurezza
   //viene letto il nome della shape

   if(!findObject)
   {
    objectList << object;
    mapObjectInstance_.insert(object,instance);
   }
   if(findObject && !findInstance)
     mapObjectInstance_.insert(object,instance);
  }

  //si procede a popolare le mappe
  else
  {
   QString number;

//?   number = parts.value(2);

   number = axa->scoped_identifiers().value(2);

//?
//   for( i = i + 1; line[i] != '\t'; ++i)
//     number.append(line[i]);

   if(!findObject)
   {
    objectList << object;
    mapObjectInstance_.insert(object, instance);
    mapInstanceNumber_.insert(object + ":" + instance, number);
   }
   if(findObject && !findInstance)
   {
    mapObjectInstance_.insert(object, instance);
    mapInstanceNumber_.insert(object + ":" + instance, number);
   }
   if(findObject&&findInstance)
     mapInstanceNumber_.insert(object + ":" + instance, number);

   another.id = object + ":" + instance + ":" + number;

   //si legge il tipo di shape e si procede a copiare i punti

   QString type;
//?
//   for(i=i+1; line[i]!=':'; ++i)
//     type.append(line[i]);
   //type = parts.value(3);
   type = axa->shape_designation();

   //type.chop(1); // remove trailing colon ...

   if(type=="Rectangle")
     another.form=square;
   if(type=="Ellipse")
     another.form=ellipse;
   if(type=="Polygon")
     another.form=polygon;


//   QString sh = parts.value(4);
   int s = 0;

//   i += 2; //salta : e \t
//   while(i<line.size())

//   while(s < sh.size())
//   {
//    QString x;
//    QString y;
//    for(s = s; sh[s] != ','; ++s)
//      x.append(sh[s]);
//    int rx=x.toInt();

//    for(s = s+1; sh[s] != ':' && s < sh.size(); ++s)
//      y.append(sh[s]);

//    int ry = y.toInt();
//    ++s;
//    another.shapePoints << QPoint(rx, ry);
//   }

   QVector<QPoint> points;
   axa->locations_to_qpoints(points);
   another.shapePoints = points.toList();

   outEdits << another;
   scaledEdits_ << another; //qui viene caricata la shape ottenuta

  }

 }
 //viene popolata la prima colonna della gui
 //?? ui->ObjectListView->addItems(objectList);
 file.close();

 //?? ui->ResizeSlider->setValue(default_resize);

 //se l-immagine non viene trovata
 if(!resizeMethod(default_resize))
 {
  //si procede a cercarla nella cartella dove si trova il file txt
  QString path = txt_filename_path_;
  path.remove(path.size()-4,4);
  int pos;
  for(pos = image_filename_path_.size(); image_filename_path_[pos] != '.'; --pos);
  image_filename_path_.remove(0,pos);
  image_filename_path_ = path + image_filename_path_;
  if(!resizeMethod(default_resize))
    return false;
 }

 if(!outEdits.isEmpty())
 {
  display_image_data_->setEdits(outEdits);
  display_image_data_->resizeEdits(default_resize);

  shape_select_frame_->set_clear_all_btn_enabled();
  shape_select_frame_->set_clear_last_btn_enabled();

  //?? ui->_Shape_Select_Frame->set_clear_all_btn_enabled();
  //?? ui->_Shape_Select_Frame->set_clear_last_btn_enabled();

//  ui->ClearAll->setDisabled(false);
//  ui->ClearLast->setDisabled(false);
 }
 defaultView();
 return true;
}

//metodo che esegue il ripristino dei dati
void MainWindow::doBackUp()
{
 //?? ui->ObjectListView->clear();
 //?? ui->InstanceListView->clear();
 //?? ui->NumberListView->clear();
 workspace_ = backUpHere_.workspace;
 image_filename_path_ = backUpHere_.image_filename_path;
 list_filename_path_ = backUpHere_.list_filename_path;
 txt_filename_path_ = backUpHere_.txt_filename_path;
 project_filename_path_ = backUpHere_.project_filename_path;
 mapObjectInstance_ = backUpHere_.mapObjectInstance;
 mapInstanceNumber_ = backUpHere_.mapInstanceNumber;
 background_ = backUpHere_.background;
 scaledEdits_ = backUpHere_.scaledEdits;
 sizeh_ = backUpHere_.sizeh;
 sizew_ = backUpHere_.sizew;
 resize_factor_ = backUpHere_.resize_factor;
 QStringList objects;
 QList<QString> uniqueKeys = mapObjectInstance_.uniqueKeys();
 for(int i=0; i<uniqueKeys.size(); ++i){
  objects<<uniqueKeys.at(i);
 }
 //?? ui->ObjectListView->addItems(objects);
 //?? ui->ResizeSlider->setValue(resize_factor_);
 resizeMethod(resize_factor_);
 display_image_data_->setEdits(scaledEdits_);
 if(!scaledEdits_.isEmpty())
   display_image_data_->resizeEdits(resize_factor_);
 QMainWindow::setWindowTitle(backUpHere_.title);
}

//metodo che resetta il programma preparandolo ad un nuovo processo
void MainWindow::cleanWindow()
{
 //?? ui->ObjectListView->clear();
 //?? ui->InstanceListView->clear();
 //?? ui->NumberListView->clear();
 scaledEdits_.clear();
 mapObjectInstance_.clear();
 mapInstanceNumber_.clear();
 display_image_data_->setNameSelected(false);
 display_image_data_->setShapeSelected("");
 display_image_data_->clear_image();
}

//metodo che porta il programma ad una situazione standard
void MainWindow::defaultView()
{
// ui->Square->setDisabled(false);
// ui->Ellipse->setDisabled(false);
// ui->Polygon->setDisabled(false);
 //?? ui->ResizeSlider->setDisabled(false);
 //ui->Highlight->setDisabled(false);

 //?? ui->_Shape_Select_Frame->set_highlight_ckb_enabled();
 shape_select_frame_->set_highlight_ckb_enabled();

 //?? ui->ObjectListView->setDisabled(false);
 //?? ui->InstanceListView->setDisabled(false);
 //?? ui->NumberListView->setDisabled(false);
}

//metodo legato allo slider che gestisce lo zoom
void MainWindow::on_ResizeSlider_sliderMoved(int position)
{
 if(!scaledEdits_.isEmpty())
 {
  display_image_data_->setEdits(scaledEdits_);
  display_image_data_->resizeEdits(position);
 }
 resizeMethod(position);
}

//metodo che processa l'immagine, fa il resize se necessario e la stampa
bool MainWindow::resizeMethod(int value)
{
 //booleano, cos- si pu√≤ intervenire in caso di errore
 //la formula per le nuove dimensioni √® cos√¨ composta:
 //190 √® la massima percentuale di zoom a cui si pu√≤ arrivare, 10 √® la minima
 //lo zoom attuale si ottiene quindi facendo 190 meno 18 moltiplicato per il valore dello slider, resize, che gestisce lo zoom nell'interfaccia
 //lo slider varia tra 0 e quindi 190% di zoom fino a 10, ovvero il 10% di zoom
 //trovato il valore si fa una proprozione per trovare il nuovo valore

 if(background_.load(image_filename_path_))
 {
  resize_factor_ = value;
  sizew_ = background_.size().width()/(100.0/(190-resize_factor_*18));
  sizeh_ = background_.size().height()/(100.0/(190-resize_factor_*18));
  QImage scaled=background_.scaled(sizew_,sizeh_,Qt::KeepAspectRatio, Qt::FastTransformation);
  display_image_->resize(sizew_, sizeh_);
  display_image_data_->setView(scaled);
  //?? ui->scrollContents->resize(sizew_, sizeh_);
  return true;
 }

 return false;
}

//metodo attivato dal signal setTuple presente in DisplayImage
void MainWindow::getTuple(QString shapeID)
{
 //quando riceve l-id, cerca l-object nella prima colonna e simula il click
 //cerca l-instance nella seconda colonna e simula il click
 //cerca il number nella terza colonna e simula il click
 this->shapeID_ = shapeID;
 shapeID.toStdString();
 int i;
 QString object;
 for(i=0; shapeID[i]!=':';++i)
   object.append(shapeID[i]);
 QString instance;
 for(i=i+1; shapeID[i]!=':';++i)
   instance.append(shapeID[i]);
 QString number;
 for(i=i+1; i<shapeID.size();++i)
   number.append(shapeID[i]);
 int j=0;
 do
 {
  //?? ui->ObjectListView->setCurrentRow(j);
  j++;
 } while(false); //?? ui->ObjectListView->currentItem()->text()!=object);
 on_ObjectListView_clicked();
 j=0;
 do
 {
  //? ui->InstanceListView->setCurrentRow(j);
  j++;
 } while(false); //?? ui->InstanceListView->currentItem()->text()!=instance);
 on_InstanceListView_clicked();
 j=0;
 do
 {
  //?? ui->NumberListView->setCurrentRow(j);
  j++;
 } while(false); //?ui->NumberListView->currentItem()->text()!=number);
 on_NumberListView_clicked();

 shape_select_frame_->set_clear_selected_btn_enabled();
 //? ui->_Shape_Select_Frame->set_clear_selected_btn_enabled();
 //ui->ClearSelected->setDisabled(false);
}

//metodo legato alla prima colonna
void MainWindow::on_ObjectListView_clicked()
{
 //quando un valore viene selezionato il metodo provvede a far comparire nella seconda colonna i valori subordinati
 display_image_data_->setNameSelected(false);
 display_image_data_->setShapeSelected("");

 //?? ui->_Shape_Select_Frame->set_clear_selected_btn_enabled();
 shape_select_frame_->set_clear_selected_btn_enabled();

// ui->ClearSelected->setDisabled(true);
 //?? ui->InstanceListView->clear();
 //?? ui->NumberListView->clear();
 QList<QString> instances;
//? QList<QString> correlatedInstance = mapObjectInstance_.values(ui->ObjectListView->currentItem()->text());
 //per evitare l-inversione della lista rispetto al file originale

//?
// for(int i=correlatedInstance.size()-1;i>=0;--i) instances<<correlatedInstance.at(i);
// ui->InstanceListView->addItems(instances);
}

//metodo legato alla seconda colonna
void MainWindow::on_InstanceListView_clicked()
{
 //quando un valore viene selezionato il metodo provvede a far comparire nella terza colonna i valori subordinati
 display_image_data_->setNameSelected(true);
 display_image_data_->setShapeSelected("");

//?? ui->_Shape_Select_Frame->set_clear_selected_btn_disabled();
 shape_select_frame_->set_clear_selected_btn_disabled();

// ui->ClearSelected->setDisabled(true);
//?? ui->NumberListView->clear();
 QList<QString> numbers;

 QString objectText;
//? {
//  QListWidgetItem* qlwi = ui->ObjectListView->currentItem();
//  if(qlwi)
//    objectText = qlwi ->text();
//  else
    objectText = "<?>";
// }
 QString instanceText;
//?
// {
//  QListWidgetItem* qlwi = ui->InstanceListView->currentItem();
//  if(qlwi)
//    objectText = qlwi ->text();
//  else
//
 objectText = "<?>";
// }


 numbers << mapInstanceNumber_.values(objectText + ":" + instanceText);
 for(int i=0;i<numbers.size()/2;++i)
   numbers.swap(i,numbers.size()-(i+1));

//?
// if(ui->NumberListView)
//   ui->NumberListView->addItems(numbers);
}

//metodo legato alla terza colonnna
void MainWindow::on_NumberListView_clicked()
{

 QString object;
//? {
//  QListWidgetItem* qlwi = ui->ObjectListView->currentItem();
//  if(qlwi)
//    object = qlwi->text();
//  else
//    object = "<?>";
// }

 QString instance;
//?
// {
//  QListWidgetItem* qlwi =  ui->InstanceListView->currentItem();
//  if(qlwi)
//    object = qlwi->text();
//  else
//    object = "<?>";
// }

 QString number;
//?
// {
//  QListWidgetItem* qlwi =  ui->NumberListView->currentItem();
//  if(qlwi)
//    object = qlwi->text();
//  else
//    object = "<?>";
// }

 //quando un valore viene selezionato il metodo provvede a mandare un segnale a display colorando diversamente la relativa shape
 display_image_data_->setShapeSelected(object + ":" + instance + ":" + number);
 shapeID_ = object + ":" + instance + ":" + number;

//?? ui->_Shape_Select_Frame->set_clear_selected_btn_enabled();
 shape_select_frame_->set_clear_selected_btn_enabled();

 //ui->ClearSelected->setDisabled(false);
}

////metodo legato al bottone circolare con a fianco il testo Square
//void MainWindow::on_Square_clicked(){
// display.reset();
// display.enableSquareDraw(); //informa display che deve mostrare shape di forma rettangolare
//}
void MainWindow::setup_shape_rectangle()
{
 display_image_data_->reset();
 display_image_data_->enableSquareDraw(); //informa display che deve mostrare shape di forma rettangolare
}


////metodo legato al bottone circolare con a fianco il testo Ellipse
//void MainWindow::on_Ellipse_clicked(){
// display.reset();
// display.enableEllipseDraw(); //informa display che deve mostrare shape di forma circolare
//}
void MainWindow::setup_shape_ellipse()
{
 display_image_data_->reset();
 display_image_data_->enableEllipseDraw(); //informa display che deve mostrare shape di forma circolare
}


////metodo legato al bottone circolare con a fianco il testo Polygon
//void MainWindow::on_Polygon_clicked()
//{
// display.reset();
// display.enablePolygonDraw(); //informa display che deve mostrare shape di forma pligonale
//}

//metodo legato al bottone circolare con a fianco il testo Polygon
void MainWindow::setup_shape_polygon()
{
 display_image_data_->reset();
 display_image_data_->enablePolygonDraw(); //informa display che deve mostrare shape di forma pligonale
}


////metodo legato al bottone quadrato con a fianco il testo Highlight
//void MainWindow::on_Highlight_clicked(bool checked){
// display.enableHighlight(checked); //informa display che deve mostrare il bordo grigio intorno al quadratino
//}

void MainWindow::setup_highlight(bool checked)
{
 display_image_data_->enableHighlight(checked);
}

//metodo attivato dal signal onLineDraw presente in DisplayImage
void MainWindow::onDrawLine(QList<DisplayImage_Data::shape> edits)
{
 //questo metodo viene invocato per nature diverse
 //ma riesce a capire se si st√  aggiunggendo una shape o se ne sta modificando/spostando una gi√  presente

 for(int i=0; i < edits.size(); ++i)
 {
  AXFI_Annotation* axa = new AXFI_Annotation;

  DisplayImage_Data::shape e = edits.at(i);

  DisplayImage_Data::shape another;

  if(e.form == DisplayImage::square)
    axa->set_shape_designation("Rectangle");
  else if(e.form == DisplayImage::ellipse)
    axa->set_shape_designation("Ellipse");
  else if(e.form == DisplayImage::polygon)
    axa->set_shape_designation("Polygon");

  if(edits.at(i).id.isEmpty())
  {
   //se √® vero allora √® stata aggiunta una nuova shape

   QString object;
//?   {
//    QListWidgetItem* qlwi = ui->ObjectListView->currentItem();
//    if(qlwi)
//      object = qlwi->text();
//    else
//
   object = "<?>";
//   }
   axa->add_scoped_identifier(object);

   QString instance;
//?   {
//    QListWidgetItem* qlwi =  ui->InstanceListView->currentItem();
//    if(qlwi)
//      instance = qlwi->text();
//    else
//
   instance = "<?>";
//   }
   axa->add_scoped_identifier(instance);


   QString number;
   bool ok;
   do
   {
    number = Special_Input_Dialog::get_text(&autogen_index_, this, "Need a Shape Name",
      "Enter text here providing a Shape Name",
      QLineEdit::Normal, QString(), &ok, 0);

    if(ok)
    {
     if(!number.isEmpty())
     {
      QList<QString> numbers = mapInstanceNumber_.values(object + ":" + instance);

      for(int j=0; j < numbers.size(); ++j)
      {
       if(number == numbers.at(j))
       {
        ok=false;
        break;
       }
      }
     }
     else
       ok = false;
    }
    else
      ok = true;
   }
   while(!ok);

   if(!number.isEmpty())
   {
    axa->add_scoped_identifier(number);

    another.id = object + ":" + instance + ":" + number;
    another.form = edits.at(i).form;
    for(int j=0; j < edits.at(i).shapePoints.size(); ++j)
    {
     QPoint scaled_point = coordinate_scaling(edits.at(i).shapePoints.at(j));
     another.shapePoints << scaled_point;

     axa->absorb_shape_point(scaled_point);

    }

    another.axfi_annotation = axa;

    scaledEdits_ << another;

    check_init_axfi_annotation_group();
    axfi_annotation_group_->add_annotation(axa);

    mapInstanceNumber_.insert(object + ":" + instance, number);
    on_InstanceListView_clicked();
    //?? ui->NumberListView->setCurrentRow(ui->NumberListView->count() - 1);
    on_NumberListView_clicked();
    //?? ui->Save->setDisabled(false);
   }
  }

  if(shapeID_ != "" && shapeID_ == edits.at(i).id)
  {
   //tramite l-id so quale shape √® stata modificata e quindi sostituirla con quella nuova
   another.id = edits.at(i).id;
   another.form = edits.at(i).form;
   for(int j=0; j < edits.at(i).shapePoints.size(); ++j)
   {
    QPoint new_current_point = coordinate_scaling(edits.at(i).shapePoints.at(j));
    another.shapePoints << new_current_point;
   }
   scaledEdits_.replace(i, another);
   //?? ui->Save->setDisabled(false);
  }

 }
 display_image_data_->setEdits(scaledEdits_);
 display_image_data_->resizeEdits(resize_factor_);

 if(scaledEdits_.size() > 1)
 {
  //?? ui->_Shape_Select_Frame->set_clear_last_btn_enabled();
  //?? ui->_Shape_Select_Frame->set_clear_all_btn_enabled();

  shape_select_frame_->set_clear_last_btn_enabled();
  shape_select_frame_->set_clear_all_btn_enabled();

//  ui->ClearLast->setDisabled(false);
//  ui->ClearAll->setDisabled(false);
 }

}

//metodo che calcola il resize dei punti apparteneti alle shape
QPoint MainWindow::coordinate_scaling(QPoint init_point)
{
 QPoint new_point;
 new_point.rx() = init_point.rx()*(100.0/(190 - resize_factor_ * 18));
 new_point.ry() = init_point.ry()*(100.0/(190 - resize_factor_ * 18));
 return new_point;
}

void MainWindow::handle_clear_selected()
{
 _handle_clear_selected();
}

void MainWindow::handle_clear_last()
{
 _handle_clear_last();
}

void MainWindow::handle_clear_all()
{
 _handle_clear_all();
}

//void MainWindow::on_ClearSelected_clicked()
//{
// _handle_clear_selected();
//}

//void MainWindow::on_ClearAll_clicked()
//{
// _handle_clear_all();
//}

//void MainWindow::on_ClearLast_clicked()
//{
// _handle_clear_last();
//}



//metodo legato al bottone rettangolare con il nome Clear Selected
void MainWindow::_handle_clear_selected()
{
 //toglier√  tutti i dati relativi alla shape selezionata
 QString temp=shapeID_;
 if(scaledEdits_.size()>1)
 {
  for(int i=0; i < scaledEdits_.size(); ++i)
    if(scaledEdits_.at(i).id == shapeID_)
      scaledEdits_.removeAt(i);
  display_image_data_->setEdits(scaledEdits_);
  display_image_data_->resizeEdits(resize_factor_);
  display_image_data_->reset();
 }
 else
 {
  scaledEdits_.clear();
  display_image_data_->clear_image();
 }
 int i;
 QString object;

 for(i=0; temp[i] != ':'; ++i)
   object.append(temp[i]);

 QString instance;

 for(i = i+1; temp[i] != ':'; ++i)
   instance.append(temp[i]);

 QString number;

 for(i=i+1;i<temp.size();++i)
   number.append(temp[i]);

 mapInstanceNumber_.remove(object + ":" + instance, number);
 shapeID_.clear();

//? ui->_Shape_Select_Frame->set_clear_selected_btn_disabled();
 shape_select_frame_->set_clear_selected_btn_disabled();


// ui->ClearSelected->setDisabled(true);
 if(scaledEdits_.isEmpty())
 {
  shape_select_frame_->set_clear_last_btn_disabled();
  shape_select_frame_->set_clear_all_btn_disabled();


  //?? ui->_Shape_Select_Frame->set_clear_last_btn_disabled();
  //?? ui->_Shape_Select_Frame->set_clear_all_btn_disabled();

//  ui->ClearLast->setDisabled(true);
//  ui->ClearAll->setDisabled(true);
 }
 //?? ui->Save->setDisabled(false);

//??
// if(ui->InstanceListView->isItemSelected(ui->InstanceListView->currentItem())&&ui->InstanceListView->currentItem()->text()==instance)
//   on_InstanceListView_clicked();
}

//metodo legato al bottone rettangolare con il nome Clear Last
void MainWindow::_handle_clear_last()
{
 //toglier√  tutti i dati relativi all-ultima shape disegnata
 display_image_data_->clearLastEdits();
 QString temp = scaledEdits_.last().id;
 int i;
 QString object;
 for(i=0; temp[i] != ':'; ++i)
   object.append(temp[i]);
 QString instance;
 for(i=i+1; temp[i] != ':'; ++i)
   instance.append(temp[i]);
 QString number;
 for(i=i+1;i<temp.size();++i) number.append(temp[i]);
 mapInstanceNumber_.remove(object + ":" + instance, number);
 scaledEdits_.removeLast();
 display_image_data_->reset();

 if(scaledEdits_.isEmpty())
 {
  //?? ui->_Shape_Select_Frame->set_clear_last_btn_disabled();
  //?? ui->_Shape_Select_Frame->set_clear_all_btn_disabled();

  shape_select_frame_->set_clear_last_btn_disabled();
  shape_select_frame_->set_clear_all_btn_disabled();


//  ui->ClearLast->setDisabled(true);
//  ui->ClearAll->setDisabled(true);
 }
 //?? ui->Save->setDisabled(false);

//?? if(ui->InstanceListView->isItemSelected(ui->InstanceListView->currentItem())&&ui->InstanceListView->currentItem()->text()==instance)
 //??  on_InstanceListView_clicked();
}

//metodo legato al bottone rettangolare con il nome Clear All
void MainWindow::_handle_clear_all()
{
 //pulir√  l-immagine da tutte le shape cancellando i relativi dati
 display_image_data_->clear_image();
 if(!scaledEdits_.isEmpty())
   scaledEdits_.clear();

 if(scaledEdits_.isEmpty())
 {
  //?? ui->_Shape_Select_Frame->set_clear_selected_btn_disabled();
  //?? ui->_Shape_Select_Frame->set_clear_selected_btn_disabled();

  shape_select_frame_->set_clear_last_btn_disabled();
  shape_select_frame_->set_clear_all_btn_disabled();


//  ui->ClearLast->setDisabled(true);
//  ui->ClearAll->setDisabled(true);
 }
 //?? ui->NumberListView->clear();
 mapInstanceNumber_.clear();
 //?? ui->Save->setDisabled(false);
}

//metodo legato al bottone rettangolare con il nome End Project
void MainWindow::on_EndProject_clicked()
{
 //quando premuto, interrompre il progetto cancellando il valore nel flag project_filename_path
 QMessageBox::StandardButton reply = QMessageBox::No;

// if(ui->Save->isEnabled())
// {
//  reply = QMessageBox::question(this, "Question", "Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
// }

 if(reply!=QMessageBox::Cancel)
 {
  if(reply==QMessageBox::Yes)
    on_Save_clicked();
  project_filename_path_.clear();
  //?? ui->actionAnnotate_Single_Image->setDisabled(false);
  //?? ui->actionAnnotate_Multiple_Image->setDisabled(false);
  //?? ui->actionLoad_annotations->setDisabled(false);
  cleanWindow();
  set_initial_gui();
 }
}

//metodo legato al bottone rettangolare con il nome Load Next
void MainWindow::on_LoadNext_clicked()
{
 //permette all-utente di navigare tra le immagini annotate fino a quel momento
 //dopo aver caricato l-ultima, se ripremuto avvier√  il processo per annotare una nuova immagine
 //attiva e disattiva il tasto load_previous
 QMessageBox::StandardButton reply = QMessageBox::No;

//?
// if(ui->Save->isEnabled())
// {
//
 reply = QMessageBox::question(this,"Question","Do you want to save before?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
// }
 if(reply!=QMessageBox::Cancel)
 {
  if(reply==QMessageBox::Yes)
  {
   on_Save_clicked();
   if(imageSequence_.indexOf(image_filename_path_) == -1)
     imageSequence_.append(image_filename_path_);
  }
  if(imageSequence_.indexOf(image_filename_path_) == imageSequence_.size()-1)
    on_actionAnnotate_Single_Image_triggered();
  else
  {
   QString imageName = image_filename_path_ = imageSequence_.at(imageSequence_.indexOf(image_filename_path_) + 1);
   int pos;
   for(pos=imageName.size(); imageName[pos]!='/'; --pos);
   imageName.remove(0,pos+1);
   imageName.remove(imageName.size()-4,4);
   imageName += ".txt";
   txt_filename_path_ = project_filename_path_ + "/" + pwizard_.projectName+"/"+imageName;
   load_annotation();
  }
//??
//  if(imageSequence_.indexOf(image_filename_path_) == 0)
//    ui->LoadPrevious->setDisabled(true);
//  else
//    ui->LoadPrevious->setDisabled(false);
 }
}

//metodo legato al bottone rettangolare con il nome Load Previous
void MainWindow::on_LoadPrevious_clicked(){
 //permette all-utente di navigare tra le immagini annotate fino a quel momento
 //dopo aver caricato la prima il bottone si disattiva
 QMessageBox::StandardButton reply = QMessageBox::No;
 if(true) //?? (ui->Save->isEnabled())
 {
  reply = QMessageBox::question(this,"Question","Do you want to save before?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
 }
 if(reply!=QMessageBox::Cancel)
 {
  if(reply==QMessageBox::Yes)
  {
   on_Save_clicked();
   if(imageSequence_.indexOf(image_filename_path_)==-1)
     imageSequence_.append(image_filename_path_);
  }
  QString imageName = image_filename_path_ = imageSequence_.at(imageSequence_.indexOf(image_filename_path_)-1);
  int pos;
  for(pos=imageName.size(); imageName[pos]!='/'; --pos);
  imageName.remove(0,pos+1);
  imageName.remove(imageName.size()-4,4);
  imageName+=".txt";
  txt_filename_path_ = project_filename_path_ + "/" + pwizard_.projectName + "/" + imageName;
  load_annotation();

//??
//  if(imageSequence_.indexOf(image_filename_path_) - 1 < 0)
//    ui->LoadPrevious->setDisabled(true);
 }
}

//metodo legato al bottone rettangolare con il nome Save
void MainWindow::on_Save_clicked()
{
 _handle_save();
}

void MainWindow::_handle_save()
{
 //metodo che salva su file tutte le annotazioni eseguite in scala 1:1
 QString filename;
 if(project_filename_path_.isEmpty())
 {
  filename=image_filename_path_;
  filename.remove(image_filename_path_.size()-4, 4);
  filename += ".txt";
 }
 else
 {
  filename = project_filename_path_ + "/" + pwizard_.projectName + "/";
  QString imageName = image_filename_path_;
  int pos;
  for(pos = imageName.size(); imageName[pos] != '/'; --pos);
    imageName.remove(0,pos+1);
  QString saveName = imageName;
  imageName.remove(imageName.size()-4,4);
  imageName += ".txt";
  filename += imageName;
  QFile::copy(image_filename_path_, project_filename_path_ + "/" + pwizard_.projectName + "/" + saveName);

  if(imageSequence_.indexOf(image_filename_path_)==-1)
    imageSequence_.append(image_filename_path_);
 }
 QFile file(filename);
 if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
   return;
 QTextStream ofs(&file);
 ofs << "133518122014\n";
 QString imageName = image_filename_path_;
 if(project_filename_path_.isEmpty())
 {
  int pos;
  for(pos=imageName.size(); imageName[pos]!='/'; --pos);
  imageName.remove(0,pos+1);
 }
 ofs << imageName << "\n";
 if(!scaledEdits_.isEmpty())
 {
  for(int i = 0; i < scaledEdits_.size(); ++i)
  {
   AXFI_Annotation* axa = scaledEdits_.at(i).axfi_annotation;
   QString cs = axa->to_compact_string();

//   QString temp = scaledEdits_.at(i).id;
//   temp.toStdString();
//   for(int j = 0; j < temp.size(); ++j)
//     if(temp[j] == ':')
//       temp[j] = TAB_DIVIDER;
//   temp[temp.size()] = TAB_DIVIDER;
//   ofs << temp;
//   if(scaledEdits_.at(i).form == square) ofs << "Square:" TAB_DIVIDER_STR;
//   if(scaledEdits_.at(i).form == ellipse) ofs << "Ellipse:" TAB_DIVIDER_STR;
//   if(scaledEdits_.at(i).form == polygon) ofs << "Polygon:" TAB_DIVIDER_STR;



//   for(int j = 0; j < scaledEdits_.at(i).shapePoints.size()-1; ++j)
//   {
//    QPoint point = scaledEdits_.at(i).shapePoints.at(j);
//    ofs<<point.rx() << "," << point.ry() << ":";
//   }
//   QPoint point = scaledEdits_.at(i).shapePoints.at(scaledEdits_.at(i).shapePoints.size() - 1);
//   ofs<<point.rx()<<","<<point.ry()<<"\n";

   ofs << cs << '\n';

  }
 }
 QList<QString> uniqueKeys = mapInstanceNumber_.uniqueKeys();


//??
// for(int i=0; i<ui->ObjectListView->count(); ++i)
// {
//  QList<QString> correlatedItems = mapObjectInstance_.values(ui->ObjectListView->item(i)->text());
//  for(int j = correlatedItems.size()-1 ; j>=0; --j)
//  {
//   bool find=false;
//   for(int k=0; k<uniqueKeys.size(); ++k)
//     if(ui->ObjectListView->item(i)->text() + ":" + correlatedItems.at(j) == uniqueKeys.at(k))
//       find=true;
//   if(!find)
//     ofs << ui->ObjectListView->item(i)->text() + TAB_DIVIDER_STR + correlatedItems.at(j) + "\n";
//  }
// }


 file.close();

//?? ui->Save->setDisabled(true);
}

//metodo legato al comando Quit
void MainWindow::on_actionQuit_triggered()
{
 close();
}

//metodo per la gestione della chiusura della finestra
void MainWindow::closeEvent(QCloseEvent *event)
{

 //??


// QMessageBox::StandardButton reply = QMessageBox::No;

// if(ui->Save->isEnabled())
// {
//  reply = QMessageBox::question(this,"Question","Do you want to save before quit?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
// }

// if(reply!=QMessageBox::Cancel){
//  if(reply==QMessageBox::Yes) on_Save_clicked();
//  event->accept();
// }


}

//metodo per la gestione del resize della finestra
void MainWindow::resizeEvent(QResizeEvent *event)
{
 QSize temp=event->size();
 //?? ui->scrollArea->resize(temp.rwidth()-20,temp.rheight()-250);
}

//metodo per la gestione della pressione di determinati tasti mentre √® attiva la finestra
void MainWindow::keyPressEvent(QKeyEvent *event)
{
#ifdef HIDE
 if(event->key() == Qt::Key_Control)
   ctrlIsPressed_ = true;
 if(ctrlIsPressed_ && event->key() == Qt::Key_Shift)
   shiftIsPressed_ = true;

 if(ui->_Shape_Select_Frame->clear_selected_btn_is_enabled()
     // ClearSelected->isEnabled()
    && !ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_Cancel)
      _handle_clear_selected();
      //on_ClearSelected_clicked();

 if(ui->actionAnnotate_Single_Image->isEnabled() && ctrlIsPressed_ && event->key()==Qt::Key_N)
   on_actionAnnotate_Single_Image_triggered();
 if(ui->actionAnnotate_Multiple_Image->isEnabled() && ctrlIsPressed_ && event->key()==Qt::Key_M)
   on_actionAnnotate_Multiple_Image_triggered();
 if(ui->actionLoad_annotations->isEnabled() && ctrlIsPressed_ && event->key()==Qt::Key_L)
   on_actionLoad_annotations_triggered();

 if(ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_Q)
   on_actionQuit_triggered();
 if(ctrlIsPressed_ && event->key() == Qt::Key_O)
   on_actionOptions_triggered();
 if(ctrlIsPressed_ && event->key() == Qt::Key_I)
   on_actionInstructions_triggered();

 if(ui->_Shape_Select_Frame->clear_last_btn_is_enabled()
    //    ui->ClearLast->isEnabled()
   && ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_Cancel)
     _handle_clear_last();
       //on_ClearLast_clicked();

 if(ui->Save->isEnabled() && ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_S)
   on_Save_clicked();
 if(ui->ResizeSlider->isEnabled() && resize_factor_ > 0 && ctrlIsPressed_ &&
     !shiftIsPressed_ && event->key()==Qt::Key_Plus){
  ui->ResizeSlider->setValue(resize_factor_ -= 1);
  on_ResizeSlider_sliderMoved(resize_factor_);
 }
 if(ui->ResizeSlider->isEnabled() && resize_factor_ < 10 && ctrlIsPressed_
    && !shiftIsPressed_ &&event->key()==Qt::Key_Minus){
  ui->ResizeSlider->setValue(resize_factor_ += 1);
  on_ResizeSlider_sliderMoved(resize_factor_);
 }

 if(ui->EndProject->isEnabled() && ctrlIsPressed_ && !shiftIsPressed_ && event->key() == Qt::Key_T)
   on_EndProject_clicked();
 if(ui->LoadNext->isEnabled() && ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_PageUp)
    on_LoadNext_clicked();
 if(ui->LoadPrevious->isEnabled() && ctrlIsPressed_ && !shiftIsPressed_ && event->key()==Qt::Key_PageDown)
    on_LoadPrevious_clicked();


// //   have to set these eventually ...
// if(ui->Square->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_S) ui->Square->click();
// if(ui->Ellipse->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_E) ui->Ellipse->click();
// if(ui->Polygon->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_P) ui->Polygon->click();
// if(ui->Highlight->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_H) ui->Highlight->click();
// if(ui->ClearAll->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_Cancel) on_ClearAll_clicked();

#endif // def HIDE
}

//metodo per la gestione del rilascio di determinati tasti mentre √® attiva la finestra
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
 if(event->key()==Qt::Key_Escape)
   display_image_data_->reset(); //esc
 if(event->key()==Qt::Key_Control)
   ctrlIsPressed_ = false; //ctrl
 if(event->key()==Qt::Key_Shift)
   shiftIsPressed_ = false; //shift
}

//metodo per la gestione del movimento della rotella mentre √® attiva la finestra
void MainWindow::wheelEvent(QWheelEvent *event)
{
//?
// if(ctrlIsPressed_ && ui->ResizeSlider->isEnabled()){
//  if(event->delta() > 0 && resize_factor_ > 0)
//  {
//   ui->ResizeSlider->setValue(resize_factor_ -= 1);
//   on_ResizeSlider_sliderMoved(resize_factor_);
//  }
//  if(event->delta()<0 && resize_factor_ < 10)
//  {
//   ui->ResizeSlider->setValue(resize_factor_ += 1);
//   on_ResizeSlider_sliderMoved(resize_factor_);
//  }
// }
}

//tentare di adattare a questa tipologia
//QAction openAct(tr("&Open"),this);
//openAct.setShortcut(tr("Ctrl+N"));
//connect(&openAct,SIGNAL(triggered()), this, SLOT(on_actionAnnotate_Single_Image_triggered()));
//#include <QShortcutEvent>
//#include <QShortcut>
/*QShortcut *image = new QShortcut(QKeySequence("Ctrl+N"), this);
(*image).setAutoRepeat(true);
QObject::connect(image, SIGNAL(activated()), this, SLOT(on_actionAnnotate_Single_Image_triggered()));
QShortcut *multiple = new QShortcut(QKeySequence("Ctrl+M"), this);
(*multiple).setAutoRepeat(true);
QObject::connect(multiple, SIGNAL(activated()), this, SLOT(on_actionAnnotate_Multiple_Image_triggered()));
*/

