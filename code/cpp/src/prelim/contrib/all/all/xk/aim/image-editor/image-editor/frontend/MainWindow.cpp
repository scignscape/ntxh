
#include "MainWindow.h"

//?#include "ui_MainWindow.h"

#include "backend/CommandPattern/dhax/extend-mod-3-command.h"
#include "backend/CommandPattern/dhax/quantize-3x3-command.h"
#include "backend/CommandPattern/dhax/shear-command.h"
#include "backend/CommandPattern/dhax/heuristic-color-mask-command.h"
#include "backend/CommandPattern/dhax/simple-calculate-command.h"

#include "backend/CommandPattern/contrastCommand.h"
#include "backend/CommandPattern/brightnessCommand.h"
#include "backend/CommandPattern/colorMaskCommand.h"

#include "frontend/color-range-dialog.h"

#include "frontend/run-transforms-dialog.h"


#include "QtColorWidgets/color_dialog.hpp"

#include "styles.h"


#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QList>
#include <QGraphicsView>

#include <QInputDialog>

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

 pixmap_item_ = nullptr; //new QGraphicspixmap_item_(this);
 scene_ = new QGraphicsScene(this);

 graphics_view_->setContextMenuPolicy(Qt::CustomContextMenu);

 set_scene_background_color_action_ = new QAction("Select scene background color", this);

 open_action_ = new QAction("Open File", this);
 save_action_ = new QAction("Save File", this);
 save_as_action_ = new QAction("Save As ...", this);
 grayscale_action_ = new QAction("Grayscale", this);
 blur_action_ = new QAction("Blur", this);
 sharpen_action_ = new QAction("Sharpen", this);
 emboss_action_ = new QAction("Emboss", this);
 edge_detect_action_ = new QAction("Edge Detect", this);
 heuristic_mask_action_ = new QAction("Heuristic Mask", this);

 extend_mod_3_action_ = new QAction("Extend Mod 3 Action", this);
 quantize_3x3_action_ = new QAction("Quantize 3x3", this);
 quantize_9x9_action_ = new QAction("Quantize 9x9", this);
 quantize_27x27_action_ = new QAction("Quantize 27x27", this);

 xshear_action_ = new QAction("Horizontal Shear Transform", this);
 yshear_action_ = new QAction("Vertical Shear Transform", this);
 xskew_action_ = new QAction("Horizontal Skew Transform", this);
 yskew_action_ = new QAction("Vertical Skew Transform", this);
 rotate_action_ = new QAction("Rotate", this);
 contrast_action_ = new QAction("Contrast", this);
 brightness_action_ = new QAction("Brightness", this);
 color_mask_action_ = new QAction("Color Mask", this);
 skew_shear_action_ = new QAction("Skew/Shear", this); 
 heuristic_color_mask_action_ = new QAction("Heuristic Color Mask", this);
 calculate_action_ = new QAction("Calculate (1D/2D)", this);

 connect(undo_action_, &QAction::triggered, this, &MainWindow::on_actionUndo_triggered);
 connect(redo_action_, &QAction::triggered, this, &MainWindow::on_actionRedo_triggered);

 connect(set_scene_background_color_action_, &QAction::triggered, this, &MainWindow::handle_set_scene_background_color);

 connect(open_action_, &QAction::triggered, this, &MainWindow::on_actionOpen_triggered);
 connect(save_as_action_, &QAction::triggered, this, &MainWindow::on_actionSave_as_triggered);

 connect(zoom_inc_action_, &QAction::triggered, this, &MainWindow::on_actionZoomInc_triggered);
 connect(zoom_dec_action_, &QAction::triggered, this, &MainWindow::on_actionZoomDec_triggered);
 connect(zoom_adapt_action_, &QAction::triggered, this, &MainWindow::on_actionZoom_Adapt_triggered);
 connect(grayscale_action_, &QAction::triggered, this, &MainWindow::on_actionGrayscale_triggered);
 connect(contrast_action_, &QAction::triggered, this, &MainWindow::on_actionContrast_triggered);
 connect(brightness_action_, &QAction::triggered, this, &MainWindow::on_actionBrightness_triggered);
 connect(color_mask_action_, &QAction::triggered, this, &MainWindow::on_actionColormask_triggered);

 connect(blur_action_, &QAction::triggered, this, &MainWindow::on_actionBlur_triggered);
 connect(sharpen_action_, &QAction::triggered, this, &MainWindow::on_actionSharpen_triggered);
 connect(emboss_action_, &QAction::triggered, this, &MainWindow::on_actionEmboss_triggered);
 connect(heuristic_mask_action_, &QAction::triggered, this, &MainWindow::handle_heuristic_mask);

 connect(heuristic_color_mask_action_, &QAction::triggered, this, QOverload<>::of(&MainWindow::handle_heuristic_color_mask));

 connect(extend_mod_3_action_, &QAction::triggered, this, &MainWindow::handle_extend_mod_3);
 connect(quantize_3x3_action_, &QAction::triggered, this, &MainWindow::handle_quantize_3x3);
 connect(quantize_9x9_action_, &QAction::triggered, this, &MainWindow::handle_quantize_9x9);
 connect(quantize_27x27_action_, &QAction::triggered, this, &MainWindow::handle_quantize_27x27);

 connect(calculate_action_, &QAction::triggered, this, &MainWindow::handle_calculate_action);

 connect(xshear_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::XShear);});
 connect(yshear_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::YShear);});
 connect(xskew_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::XSkew);});
 connect(yskew_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::YSkew);});
 connect(rotate_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::Rotate);});
 connect(skew_shear_action_, &QAction::triggered, this, [this]{handle_shear_transform(Skew_Shear_Rotate::Generic);});

 connect(edge_detect_action_, &QAction::triggered, this, &MainWindow::on_actionEdge_detect_triggered);

 connect(graphics_view_, &QGraphicsView::customContextMenuRequested, [this](const QPoint& pos)
 {
  QMenu* menu = new QMenu(this);
  menu->addAction(set_scene_background_color_action_);
  menu->addAction(open_action_);
  menu->addAction(save_as_action_);
  menu->addAction(grayscale_action_);
  menu->addAction(contrast_action_);
  menu->addAction(brightness_action_);
  menu->addAction(color_mask_action_);
  menu->addAction(blur_action_);
  menu->addAction(sharpen_action_);
  menu->addAction(emboss_action_);
  menu->addAction(edge_detect_action_);
  menu->addAction(heuristic_mask_action_);
  menu->addAction(extend_mod_3_action_);
  menu->addAction(quantize_3x3_action_);
  menu->addAction(quantize_9x9_action_);
  menu->addAction(quantize_27x27_action_);
  menu->addAction(xshear_action_);
  menu->addAction(yshear_action_);
  menu->addAction(xskew_action_);
  menu->addAction(yskew_action_);
  menu->addAction(rotate_action_);
  menu->addAction(skew_shear_action_);
  menu->addAction(heuristic_color_mask_action_);
  menu->addAction(calculate_action_);

  menu->popup(graphics_view_->mapToGlobal(pos));
 });


 //active_image_ = nullptr;
 //command_manager_ command_manager_;


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


void MainWindow::show_alpha_codes(QVector<QColor> colors, QString save_path)
{
 QImage& qim = active_image_->getQImage();

 Image::show_alpha_codes(colors, qim);
 pixmap_item_->setPixmap(QPixmap::fromImage(qim));

 if(!save_path.isEmpty())
   qim.save(save_path);
}


void MainWindow::handle_set_scene_background_color()
{
// QBrush br(QColor("gray"));
// scene_->setBackgroundBrush(br);

// graphics_view_->setBackgroundBrush(br);
// central_widget_->setStyleSheet("background-color:red;");

 color_widgets::ColorDialog dlg(this);
 dlg.setColor(QColor("gray"));
 dlg.exec();
 QColor c = dlg.selected_color();

 if(!c.isValid())
   return;

 if(c == scene_->backgroundBrush().color())
   return;

 central_widget_->setStyleSheet(QString("background-color:%1;").arg(c.name()));

}


void MainWindow::open_image_file(QString path)
{
 active_image_.reset(new Image(path));

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
  //            active_image_.reset();
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

void MainWindow::reset_scene_rectangle()
{
 if(active_image_)
   scene_->setSceneRect(0, 0, active_image_->getW(), active_image_->getH());
}

void MainWindow::on_actionOpen_triggered()
{
 QString imagePath = QFileDialog::getOpenFileName(this,
   tr("Open Image"), default_image_folder_, tr("Image Files (*.png *.jpg *.bmp)"));

 if(!imagePath.isEmpty())
 {
  open_image_file(imagePath);
  //reset_scene_rectangle();
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
 if(active_image_)
 {
  // active_image_->getFilename(),

  QString filename = QFileDialog::getSaveFileName(this, "Enter or Select File Name",
                                                  default_image_folder_,
                                                  tr("Images (*.jpg *.png *.bmp)"));

  if(!filename.isEmpty())
  {
   if(active_image_->save(filename)) {
    active_image_->setPath(filename);
    updateStatusBar();

    pending_save_modifications_ = false;
    save_action_->setEnabled(false);
   }
   else{
    QMessageBox::critical(this, APP_NAME,
                          "The path is not valid. Please check the image format.",
                          QMessageBox::Ok);
   }
  }
 }
}

void MainWindow::fit_image_in_view()
{
 graphics_view_->fitInView(pixmap_item_, Qt::KeepAspectRatio);
}

void MainWindow::adjust_window_size(QSize& sz)
{
 sz.setWidth(qMin(400, sz.width()));
 if(active_image_)
   sz.setHeight(active_image_->get_inverse_aspect_ratio() * (sz.width() + 100));
 else
   sz.setHeight(qMin(300, sz.width()));
}

void MainWindow::on_actionZoom_Adapt_triggered()
{
 if(active_image_)
   fit_image_in_view();
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
 if(active_image_ && !command_manager_.isUndoStackEmpty()) {
     command_manager_.undo();
     active_image_->updateBuffer();
     pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));
     updateStatusBar();
     scene_->setSceneRect(0, 0, active_image_->getW(), active_image_->getH());
     on_actionZoom_Adapt_triggered();

     //?pendingSaveModifications = true;
     redo_action_->setEnabled(true);
     //?pendingSaveModifications = true;
     //?save_action_->setEnabled(true);

     if(command_manager_.isUndoStackEmpty())
        undo_action_->setEnabled(false);

 }
}

void MainWindow::on_actionRedo_triggered()
{
 if(active_image_ && !command_manager_.isRedoStackEmpty()) {
     command_manager_.redo();
     active_image_->updateBuffer();
     pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));
     updateStatusBar();
     scene_->setSceneRect(0, 0, active_image_->getW(), active_image_->getH());
     on_actionZoom_Adapt_triggered();

     //pendingSaveModifications = true;
     undo_action_->setEnabled(true);
     //pendingSaveModifications = true;
     //save_action_->setEnabled(true);

     if(command_manager_.isRedoStackEmpty())
       redo_action_->setEnabled(false);
 }

}


void MainWindow::handle_shear_transform(Skew_Shear_Rotate ssr)
{
 if(active_image_)
 {
  bool okd;
  r8 xshear = 0, yshear = 0, xrotate = 0, yrotate = 0,
     xshear_c = 0, yshear_c = 0, rotate = 0;

//  QInputDialog ind;

  this->setStyleSheet(basic_button_style_sheet_());

  switch (ssr)
  {
  case Skew_Shear_Rotate::N_A: return;
  case Skew_Shear_Rotate::XSkew:
   xrotate = QInputDialog::getDouble(this, "Enter Skew Factor", "Amount:", 20, -180, 180, 1, &okd, Qt::WindowFlags(), 1);
   break;
  case Skew_Shear_Rotate::XShear:
   xshear = QInputDialog::getDouble(this, "Enter Shear Factor", "Amount:", 0.2, -255, 255, 3, &okd, Qt::WindowFlags(), 0.01);
   break;
  case Skew_Shear_Rotate::YSkew:
   yrotate = QInputDialog::getDouble(this, "Enter Skew Factor", "Amount:", 20, -180, 180, 1, &okd, Qt::WindowFlags(), 1);
   break;
  case Skew_Shear_Rotate::YShear:
   yshear = QInputDialog::getDouble(this, "Enter Shear Factor", "Amount:", 0.2, -255, 255, 3, &okd, Qt::WindowFlags(), 0.01);
   break;
  case Skew_Shear_Rotate::Rotate:
   rotate = QInputDialog::getDouble(this, "Enter Rotation", "Amount:", 20, -180, 180, 1, &okd, Qt::WindowFlags(), 1);
   break;
  case Skew_Shear_Rotate::Generic:
   {
    QList<QString> fields = {"Horizontal Skew", "Horizontal Shear",
       "Horizontal Shear (centered)",
       "Vertical Skew", "Vertical Shear",
       "Vertical Shear (centered)", "Co-Rotate",
       "Rotate"};

    QVector<InputDialog::Input_Field> infields;

    InputDialog::_infield(20, 1, -180, 180).index_into(infields);
    InputDialog::_infield(0.2, 0.01, {-255, 255}, -1).index_into(infields);
    InputDialog::_infield(0, 0.01, {-255, 255}, -1).index_into(infields);
    InputDialog::_infield(0, 1, -180, 180).index_into(infields);
    InputDialog::_infield(0, 0.01, {-255, 255}, -1).index_into(infields);
    InputDialog::_infield(0, 0.01, {-255, 255}, -1).index_into(infields);
    InputDialog::_infield(0, 1, -180, 180).index_into(infields);
    InputDialog::_infield(0, 1, -180, 180).index_into(infields);

    QList<QPair<int, double>> values = InputDialog::getFields(this, fields, infields, &okd);
//    QList<int> values = InputDialog::getFields(this,
//                                               fields,
//                                               0, 255, 1, &ok);
    if(okd)
    {
     xrotate = values[0].first + values[6].first; //QInputDialog::getDouble(this, "Enter Rotation", "Amount:", 20, -180, 180, 1, &okd, Qt::WindowFlags(), 1);
     yrotate = values[3].first + values[6].first;
     xshear = values[1].second;
     xshear_c = values[2].second;
     yshear = values[4].second;
     yshear_c = values[5].second;
     rotate = values[7].first;
     break;
    }
   }
  }

  //= QInputDialog::getDouble(this, "Enter Shear Factor", "Amouny:", 1.1, -255, 255, 3, &okd, Qt::WindowFlags(), 0.1);

  if(okd)
  {
   std::shared_ptr<ICommand> c1(new Shear_Command(*active_image_, xshear, xshear_c,
      yshear, yshear_c, xrotate, yrotate, rotate));
   command_manager_.execute(c1);
   qDebug() << "shear_transform";
   active_image_->updateBuffer();
   pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

   pending_save_modifications_ = true;
  }

 }
}

void MainWindow::run_internal_command(QString fn)
{
 if(fn == "quantize_27x27")
   run_quantize_27x27();
}


void MainWindow::run_predefined_transforms(QString file_path_pattern,
  QVector<QColor> colors, u1 overlay_cut)
{
 Run_Transforms_Dialog* rtd = new Run_Transforms_Dialog(active_image_->getQImage(),
   file_path_pattern, predefined_transforms_.size(), overlay_cut, this);

 current_pixmap_ = QPixmap::fromImage(active_image_->getQImage());

 rtd->set_feature_points_colors(colors);

 if(!file_path_pattern.isEmpty())
   rtd->save_step_image_prelim();

 rtd->show();

 auto unshow_features = [this]
 {
  pixmap_item_->setPixmap(current_pixmap_);
 };
 connect(rtd, &Run_Transforms_Dialog::unshow_features_requested, unshow_features);

 auto show_features = [this, rtd]
 {
  pixmap_item_->setPixmap(rtd->get_pixmap_with_overlays());
 };
 connect(rtd, &Run_Transforms_Dialog::show_features_requested, show_features);

 connect(rtd, &Run_Transforms_Dialog::next_step_requested, [this, rtd, file_path_pattern,
   unshow_features, show_features](u1 count, bool _show_features)
 {
  Command_or_String cmd_or_s = predefined_transforms_[count - 1];
  if(cmd_or_s.fn.isEmpty())
  {
   command_manager_.execute(cmd_or_s.cmd);
  }
  else
  {
   run_internal_command(cmd_or_s.fn);
  }

  active_image_->updateBuffer();
  if(!file_path_pattern.isEmpty())
    rtd->save_step_image();

  current_pixmap_ = QPixmap::fromImage(active_image_->getQImage());
  if(_show_features)
    show_features();
  else
    unshow_features();
  //pixmap_item_->setPixmap(current_pixmap_);
 });

// QImage overlay_cut_image;
// for(Command_or_String cmd_or_s : predefined_transforms_)
// {
//  ++count;
// }

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

void MainWindow::handle_quantize_9x9()
{
 if(active_image_)
 {
  Quantize_3x3_Command* cmd = new Quantize_3x3_Command(*active_image_);
  std::shared_ptr<ICommand> c1(cmd);
  command_manager_.execute(c1);
  qDebug() << "quantize 9x9";

  //secondary_pixel_buffer_ = cmd->sample_compress_pixel_buffer();

  std::vector<Pixel> compressed_1 = cmd->sample_compress_pixel_buffer();
  u2 compressed_w_1 = cmd->sample_compress_width();
  u2 compressed_h_1 = cmd->sample_compress_height();
  std::vector<Pixel> compressed_2;
  Extend_Mod_3_Command::proceed(compressed_w_1, compressed_h_1, compressed_1, compressed_w_1, compressed_h_1);

  u2 compressed_w_2;
  u2 compressed_h_2;
  Quantize_3x3_Command::reset_sample_compress_pixel_buffer(compressed_2, compressed_w_1, compressed_h_1,
    compressed_w_2, compressed_h_2);

  Quantize_3x3_Command::proceed(compressed_w_1, compressed_h_1, compressed_1, compressed_2);
  std::vector<Pixel> undo_1;

  Quantize_3x3_Command::re_extend(compressed_1, undo_1,
    compressed_w_1, compressed_h_1);

  active_image_->getPixelBuffer() = undo_1;
  active_image_->setW(compressed_w_1 * 3);
  active_image_->setH(compressed_h_1 * 3);

  active_image_->updateBuffer();
  pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

  pending_save_modifications_ = true;

 }

}


void MainWindow::handle_calculate_action()
{
 if(active_image_)
 {
  bool ok;
  QList<QString> fields = {"1D Length Threshold", "2D Minor Threshold", "2D Major Threshold"};
  QList<int> input = InputDialog::getFields(this,
                                            fields,
                                            0, 255, 1, &ok, 3);

  qDebug() << input;
  Simple_Calculate_Command* cmd = new Simple_Calculate_Command(*active_image_,
    QColor(), QColor("black"), QColor("white"), 27, input);
  std::shared_ptr<ICommand> c1(cmd);
  command_manager_.execute(c1);
  qDebug() << "simple calculate";

  active_image_->updateBuffer();
  pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));
  pending_save_modifications_ = true;

 }
}


void MainWindow::run_quantize_27x27()
{
 Quantize_3x3_Command* cmd = new Quantize_3x3_Command(*active_image_);

 cmd->ICommand::force_redo(quantize_27x27_action_);

 std::shared_ptr<ICommand> c1(cmd);
 command_manager_.execute(c1);
 qDebug() << "quantize 27x27";

 //secondary_pixel_buffer_ = cmd->sample_compress_pixel_buffer();

 std::vector<Pixel> compressed_1 = cmd->sample_compress_pixel_buffer();
 u2 compressed_w_1 = cmd->sample_compress_width();
 u2 compressed_h_1 = cmd->sample_compress_height();
 std::vector<Pixel> compressed_2;

 Extend_Mod_3_Command::proceed(compressed_w_1, compressed_h_1, compressed_1, compressed_w_1, compressed_h_1);

 u2 compressed_w_2;
 u2 compressed_h_2;
 Quantize_3x3_Command::reset_sample_compress_pixel_buffer(compressed_2, compressed_w_1, compressed_h_1,
   compressed_w_2, compressed_h_2);

 Quantize_3x3_Command::proceed(compressed_w_1, compressed_h_1, compressed_1, compressed_2);


 Extend_Mod_3_Command::proceed(compressed_w_2, compressed_h_2, compressed_2, compressed_w_2, compressed_h_2);

 std::vector<Pixel> compressed_3;

 u2 compressed_w_3;
 u2 compressed_h_3;
 Quantize_3x3_Command::reset_sample_compress_pixel_buffer(compressed_3, compressed_w_2, compressed_h_2,
   compressed_w_3, compressed_h_3);

 Quantize_3x3_Command::proceed(compressed_w_2, compressed_h_2, compressed_2, compressed_3);

//  std::vector<Pixel> undo_3;
 std::vector<Pixel> undo_2;
 std::vector<Pixel> undo_1;

//  Quantize_3x3_Command::re_extend(compressed_3, undo_3,
//    compressed_w_3, compressed_h_3);

 active_image_->init_reduction(compressed_3, compressed_w_3, compressed_h_3);

 Quantize_3x3_Command::re_extend(compressed_2, undo_2,
   compressed_w_2, compressed_h_2);

 Quantize_3x3_Command::re_extend(undo_2, undo_1,
   compressed_w_2 * 3, compressed_h_2 * 3);

 active_image_->getPixelBuffer() = undo_1;
 active_image_->setW(compressed_w_2 * 9);
 active_image_->setH(compressed_h_2 * 9);



 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

 pending_save_modifications_ = true;
}


void MainWindow::handle_quantize_27x27()
{
 if(active_image_)
 {
  run_quantize_27x27();
 }
}

void MainWindow::handle_quantize_3x3()
{
 if(active_image_)
 {
  Quantize_3x3_Command* cmd = new Quantize_3x3_Command(*active_image_);
  std::shared_ptr<ICommand> c1(cmd);
  command_manager_.execute(c1);
  qDebug() << "quantize 3x3";
  active_image_->updateBuffer();
  pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));
  pending_save_modifications_ = true;
 }
}


void MainWindow::handle_heuristic_color_mask(QColor c, u1 offset, QColor background,
  u1 background_opacity, u1 metric_code)
{
 qDebug() << "c = " << c;
 qDebug() << "offset = " << offset;
 background.setAlpha(background_opacity);
 qDebug() << "background = " << background;
 qDebug() << "mc = " << metric_code;

// return;
 Heuristic_Color_Mask_Command* cmd = new Heuristic_Color_Mask_Command(*active_image_, c,
   background, offset, metric_code);
 std::shared_ptr<ICommand> c1(cmd);
 command_manager_.execute(c1);
 qDebug() << "heuristic color mask";
 active_image_->updateBuffer();
 pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));
 pending_save_modifications_ = true;
}

void MainWindow::handle_heuristic_color_mask()
{
 Color_Range_Dialog* dlg = new Color_Range_Dialog(QColor(250, 225, 0), this);

 dlg->show();

 connect(dlg, &Color_Range_Dialog::accepted, [this, dlg]()
 {
  QColor c = dlg->central_color();
  u1 offset = dlg->offset();
  QColor b = dlg->background_color();
  u1 o = dlg->background_opacity();
  u1 metric_code = dlg->get_metric_code();
  handle_heuristic_color_mask(c, offset, b, o, metric_code);
  dlg->close();
 });

 connect(dlg, &Color_Range_Dialog::rejected, [this, dlg]()
 {
  dlg->close();
 });

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
 if(active_image_)
 {
  bool ok = false;
  QList<QString> field = {"Contrast"};
  QList<int> input = InputDialog::getFields(this,
                                            field,
                                            -100, 100, 10, &ok);

  if(ok){
   int inputValue = input[0];
   std::shared_ptr<ICommand>c1(new contrastCommand(*active_image_, inputValue));
   command_manager_.execute(c1);
   active_image_->updateBuffer();
   pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

   pending_save_modifications_ = true;
   //         ui->actionSave->setEnabled(true);
   //         ui->actionUndo->setEnabled(true);
   //         ui->actionRedo->setEnabled(false);
  }
 }
}

void MainWindow::on_actionBrightness_triggered()
{
 if(active_image_)
 {
  bool ok = false;
  QList<QString> field = {"Brightness"};
  QList<int> input = InputDialog::getFields(this,
                                            field,
                                            -100, 100, 10, &ok);

  if(ok)
  {
   int inputValue = input[0];
   std::shared_ptr<ICommand>c1(new brightnessCommand(*active_image_, inputValue));
   command_manager_.execute(c1);
   active_image_->updateBuffer();
   pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

   pending_save_modifications_ = true;
   //         ui->actionSave->setEnabled(true);
   //         ui->actionUndo->setEnabled(true);
   //         ui->actionRedo->setEnabled(false);
  }
 }
}


void MainWindow::on_actionColormask_triggered()
{
 if(active_image_)
 {
  bool ok = false;
  QList<QString> fields = {"Red", "Green", "Blue"};
  QList<int> values = InputDialog::getFields(this,
                                             fields,
                                             0, 255, 1, &ok);

  if(ok)
  {
   int r = values[0];
   int g = values[1];
   int b = values[2];

   std::shared_ptr<ICommand> c1(new colorMaskCommand(*active_image_, r, g, b));
   command_manager_.execute(c1);
   active_image_->updateBuffer();
   pixmap_item_->setPixmap(QPixmap::fromImage(active_image_->getQImage()));

   pending_save_modifications_ = true;
   //         ui->actionSave->setEnabled(true);
   //         ui->actionUndo->setEnabled(true);
   //         ui->actionRedo->setEnabled(false);
  }
 }
}

void MainWindow::on_actionScale_triggered()
{
}
