
#include "MainWindow.h"

//?#include "ui_MainWindow.h"

#include "backend/CommandPattern/dhax/extend-mod-3-command.h"


#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QList>
#include <QGraphicsView>

#include <QMenu>

#include <QToolBar>

#include <QSizeGrip>


#include "InputDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
//    ui(new Ui::MainWindow),
    pending_save_modifications_(false)
{
 //QIcon redo_icon (":/icons/resources/redo.png");
 //  redo_icon.addFile(QString::fromUtf8(":/icons/resources/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
 //actionRedo->setIcon(icon2);

 undo_action_ = new QAction(QIcon(":/icons/resources/undo.png"), "Undo", this);
 redo_action_ = new QAction(QIcon(":/icons/resources/redo.png"), "Redo", this);
 zoom_inc_action_ = new QAction(QIcon(":/icons/resources/zoom-in.png"), "Inc", this);
 zoom_dec_action_ = new QAction(QIcon(":/icons/resources/zoom-out.png"), "Dec", this);
 zoom_adapt_action_ = new QAction(QIcon(":/icons/resources/zoom-adapt.png"), "Adapt", this);

 tool_bar_ = new QToolBar(this);

 //? tool_bar_->setObjectName(QString::fromUtf8("toolBar"));

 tool_bar_->setMovable(false);
 tool_bar_->setFloatable(false);
 addToolBar(Qt::TopToolBarArea, tool_bar_);

 tool_bar_->addAction(undo_action_);
 tool_bar_->addAction(redo_action_);
 tool_bar_->addSeparator();
 tool_bar_->addAction(zoom_inc_action_);
 tool_bar_->addAction(zoom_dec_action_);
 tool_bar_->addAction(zoom_adapt_action_);
 tool_bar_->addSeparator();



 central_widget_ = new QWidget(this);
 main_layout_ = new QVBoxLayout;
 graphics_view_ = new QGraphicsView(central_widget_);

 central_widget_->setWindowFlags(Qt::SubWindow);
 graphics_view_->setWindowFlags(Qt::SubWindow);

 main_layout_->addWidget(graphics_view_);

 central_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 graphics_view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

// QSizeGrip* sizeGrip = new QSizeGrip(central_widget_);
// main_layout_->addWidget(sizeGrip);

 central_widget_->setLayout(main_layout_);

 pixmap_item_ = nullptr; //new QGraphicsPixmapItem(this);
 scene_ = new QGraphicsScene(this);

 graphics_view_->setContextMenuPolicy(Qt::CustomContextMenu);

 open_action_ = new QAction("Open File", this);
 grayscale_action_ = new QAction("Grayscale", this);
 blur_action_ = new QAction("Blur", this);
 sharpen_action_ = new QAction("Sharpen", this);
 emboss_action_ = new QAction("Emboss", this);
 edge_detect_action_ = new QAction("Edge Detect", this);
 heuristic_mask_action_ = new QAction("Heuristic Masl", this);

 extend_mod_3_action_ = new QAction("Extend Mod 3 Action", this);



 connect(open_action_, &QAction::triggered, this, &MainWindow::on_actionOpen_triggered);
 connect(zoom_inc_action_, &QAction::triggered, this, &MainWindow::on_actionZoomInc_triggered);
 connect(zoom_dec_action_, &QAction::triggered, this, &MainWindow::on_actionZoomDec_triggered);
 connect(zoom_adapt_action_, &QAction::triggered, this, &MainWindow::on_actionZoom_Adapt_triggered);
 connect(grayscale_action_, &QAction::triggered, this, &MainWindow::on_actionGrayscale_triggered);

 connect(blur_action_, &QAction::triggered, this, &MainWindow::on_actionBlur_triggered);
 connect(sharpen_action_, &QAction::triggered, this, &MainWindow::on_actionSharpen_triggered);
 connect(emboss_action_, &QAction::triggered, this, &MainWindow::on_actionEmboss_triggered);
 connect(heuristic_mask_action_, &QAction::triggered, this, &MainWindow::handle_heuristic_mask);

 connect(extend_mod_3_action_, &QAction::triggered, this, &MainWindow::handle_extend_mod_3);

 connect(edge_detect_action_, &QAction::triggered, this, &MainWindow::on_actionEdge_detect_triggered);

 connect(graphics_view_, &QGraphicsView::customContextMenuRequested, [this](const QPoint& pos)
 {
  QMenu* menu = new QMenu(this);
  menu->addAction(open_action_);
  menu->addAction(grayscale_action_);
  menu->addAction(blur_action_);
  menu->addAction(sharpen_action_);
  menu->addAction(emboss_action_);
  menu->addAction(edge_detect_action_);
  menu->addAction(heuristic_mask_action_);
  menu->addAction(extend_mod_3_action_);



  menu->popup(graphics_view_->mapToGlobal(pos));
 });


 //active_image_ = nullptr;
 //CommandManager command_manager_;


//    ui->setupUi(this);
//    ui->graphicsView->hide();
//    ui->statusbar->hide();

//    //disable action not used before Image upload
//    ui->actionSave->setEnabled(false);
//    ui->actionSave_as->setEnabled(false);

//    ui->actionRedo->setEnabled(false);
//    ui->actionUndo->setEnabled(false);
//    ui->actionZoomInc->setEnabled(false);
//    ui->actionZoomDec->setEnabled(false);
//    ui->actionZoom_Adapt->setEnabled(false);
//    ui->menuEdit->setEnabled(false);
//    ui->menuFilters->setEnabled(false);

//    ui->statusbar->addPermanentWidget(&imageName);
//    ui->statusbar->addPermanentWidget(&imageSize);

  active_image_.reset();

    //geometric zoom list
    zoom_list_ << 1.0 << 1.5 << 2.2 << 3.3 << 4.7 << 6.8;
    zoom_list_ << 10 << 15 << 22 << 33 << 47 << 68;
    zoom_list_ << 100 << 150 << 220 << 330 << 470 << 680;
    zoom_list_ << 1000 << 1500 << 2200 << 3300 << 4700 << 6800;

    setCentralWidget(central_widget_);
}


void MainWindow::resizeEvent(QResizeEvent* rev)
{
 //central_widget_->resize(size());
}


MainWindow::~MainWindow()
{
 //   delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
 QString imagePath = QFileDialog::getOpenFileName(this,
   tr("Open Image"), default_image_folder_, tr("Image Files (*.png *.jpg *.bmp)"));

 if(!imagePath.isEmpty())
 {
  active_image_.reset(new Image(imagePath));

  if(active_image_->isValid())
  {
   qDebug() << active_image_->getFilename();

   scene_->clear();
   pixmap_item_ = scene_->addPixmap(QPixmap::fromImage(active_image_->getQImage()));
   scene_->setSceneRect(0, 0, active_image_->getW(), active_image_->getH());
   graphics_view_->setScene(scene_);

   graphics_view_->show();

   updateStatusBar();
   //ui->statusbar->show();
   graphics_view_->fitInView(pixmap_item_, Qt::KeepAspectRatio);

   //            ui->actionRedo->setEnabled(false);
   //            ui->actionUndo->setEnabled(false);
   //            ui->actionSave->setEnabled(false);
   //            ui->actionSave_as->setEnabled(true);
   //            ui->actionZoomInc->setEnabled(true);
   //            ui->actionZoomDec->setEnabled(true);
   //            ui->actionZoom_Adapt->setEnabled(true);
   //            ui->menuEdit->setEnabled(true);
   //            ui->menuFilters->setEnabled(true);
   pending_save_modifications_ = false;
  }
  else
  {
   //            activeImage.reset();
   //            scene.clear();
   //            ui->graphicsView->hide();
   //            ui->statusbar->hide();

   //            ui->actionSave->setEnabled(false);
   //            ui->actionSave_as->setEnabled(false);
   //            ui->actionRedo->setEnabled(false);
   //            ui->actionUndo->setEnabled(false);
   //            ui->actionZoomInc->setEnabled(false);
   //            ui->actionZoomDec->setEnabled(false);
   //            ui->actionZoom_Adapt->setEnabled(false);
   //            ui->menuEdit->setEnabled(false);
   //            ui->menuFilters->setEnabled(false);

   QMessageBox::critical(this, APP_NAME,
                         "The image is not Valid.",
                         QMessageBox::Ok);
  }
 }

}

void MainWindow::zoomUpdate(bool increment)
{
 if(active_image_)
 {
  double zoom = graphics_view_->transform().m11() * 100;

  if (increment)
  {
   for (double z: zoom_list_)
   {
    if ((z - z / 10) > zoom)
    {
     zoom = z;
     break;
    }
   }
  }
  else
  {
   for (int i = zoom_list_.count() - 1; i > 0; i--)
   {
    double zoomIt = zoom_list_[i];
    if ((zoomIt + zoomIt / 10) < zoom)
    {
     zoom = zoomIt;
     break;
    }
    //qDebug() << "inside zoom out " << zoom;
   }
  }
  graphics_view_->setTransform(QTransform::fromScale(zoom / 100, zoom / 100));
 }

}

void MainWindow::updateStatusBar()
{
}

void MainWindow::on_actionSave_as_triggered()
{
}


void MainWindow::on_actionZoom_Adapt_triggered()
{
 if(active_image_)
   graphics_view_->fitInView(pixmap_item_, Qt::KeepAspectRatio);
}

void MainWindow::on_actionZoomInc_triggered()
{
 if(active_image_)
   zoomUpdate(true);
}

void MainWindow::on_actionZoomDec_triggered()
{
 if(active_image_)
   zoomUpdate(false);
}

void MainWindow::on_actionRotate_Clockwise_triggered()
{
}

void MainWindow::on_actionRotate_anticlockwise_triggered()
{
}

void MainWindow::on_actionFlip_x_triggered()
{
}

void MainWindow::on_actionFlip_y_triggered()
{
}

void MainWindow::on_actionUndo_triggered()
{
}

void MainWindow::on_actionRedo_triggered()
{
}

void MainWindow::handle_extend_mod_3()
{
 if(active_image_)
 {
  std::shared_ptr<ICommand> c1(new Extend_Mod_3_Command(*active_image_));
  command_manager_.execute(c1);
  qDebug() << "extend mod 3";
  active_image_->updateBuffer();
  pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

  pending_save_modifications_ = true;
 }
}

void MainWindow::handle_heuristic_mask()
{
 if(active_image_)
 {
  QImage& active = active_image_->getQImage();
  QImage new_image = active.createHeuristicMask();
  pixmap_item_->setPixmap(QPixmap::fromImage(new_image));
 }
}

void MainWindow::on_actionGrayscale_triggered()
{
 if(active_image_)
 {
  std::shared_ptr<ICommand> c1(new grayScaleCommand(*active_image_));
  command_manager_.execute(c1);
  qDebug() << "grayscale";
  active_image_->updateBuffer();
  pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

  pending_save_modifications_ = true;
//     ui->actionSave->setEnabled(true);
//     ui->actionUndo->setEnabled(true);
//     ui->actionRedo->setEnabled(false);
 }
}

void MainWindow::on_actionBlur_triggered()
{
 std::shared_ptr<ICommand> c1(new blurCommand(*active_image_));
 command_manager_.execute(c1);
 qDebug() << "blur";
 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

 pending_save_modifications_ = true;
}

void MainWindow::on_actionSharpen_triggered()
{
 std::shared_ptr<ICommand> c1(new sharpenCommand(*active_image_));
 command_manager_.execute(c1);
 qDebug() << "sharpen";
 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

 pending_save_modifications_ = true;
}

void MainWindow::on_actionEmboss_triggered()
{
 std::shared_ptr<ICommand> c1(new embossCommand(*active_image_));
 command_manager_.execute(c1);
 qDebug() << "emboss";
 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

 pending_save_modifications_ = true;
}

void MainWindow::on_actionEdge_detect_triggered()
{
 std::shared_ptr<ICommand> c1(new edgeDetectCommand(*active_image_));
 command_manager_.execute(c1);
 qDebug() << "edge detect";
 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

 pending_save_modifications_ = true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSave_triggered()
{
}

void MainWindow::on_actionAbout_Image_Editor_triggered()
{
    QString title = APP_NAME;
    QString msg = QString("<h2>%1</h2>")
            .arg(title);
    msg += QString("<p>"
        "Uni Project for <i>Programmazione</i> class teached by Marco Bertini.</p>"
        "<p>The Project aims to be a simple image editor with the use of filters and convolution matrixes.</p>"
        "<p>Powered by C++ and Qt5.</p>");
    msg += QString("<p><b>Author: </b> <a href =%1>Jacopo Zecchi</a></p>")
            .arg("https://github.com/Dartypier");
    msg += QString("<p><b>Version: </b>%1")
            .arg(APP_VERSION);
    msg += QString("<p><div>Icons made by <a href=%1 title=%2>Freepik</a> from <a href=%3 title=%4>www.flaticon.com</a></div></p>")
            .arg("https://www.freepik.com")
            .arg("Freepik")
            .arg("https://www.flaticon.com/")
            .arg("Flaticon");

    QMessageBox::about(this, title, msg);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionContrast_triggered()
{
}

void MainWindow::on_actionBrightness_triggered()
{
}

void MainWindow::on_actionColormask_triggered()
{
}

void MainWindow::on_actionScale_triggered()
{
}
