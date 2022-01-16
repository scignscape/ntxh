
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

//?

#include "dhax-application-controller.h"

#include "dhax-application-state.h"


#include <QColorDialog>

//#include "dhax-main-window.h"

//#include "image-viewer/dhax-display-image-data.h"
//#include "subwindows/zoom-and-navigate-frame.h"

//
#include "image-viewer/dhax-image-viewer.h"

#include "dhax-graphics-frame.h"

#include "dhax-graphics-scene.h"

#include "pleneviews/shape-select-frame.h"

//#include "image-viewer/dhax-image-scene-item.h"

//#include "main-window/dhax-main-window-receiver.h"
//#include "main-window/dhax-main-window-data.h"

#include "network/dhax-udp-controller.h"

#include "integration/meshlab/dhax-meshlab-integration-data.h"
#include "integration/freecad/dhax-freecad-integration-data.h"

#include "integration/meshlab/dhax-meshlab-integration-controller.h"
#include "integration/freecad/dhax-freecad-integration-controller.h"

#include "integration/dhax-integration-controller.h"

#include "main-window/dhax-main-window.h"
#include "main-window/dhax-main-window-controller.h"
#include "main-window/dhax-main-window-data.h"

#include "application/dhax-application-receiver.h"

#include <QMessageBox>
#include <QDesktopServices>


#include "textio.h"

USING_KANS(TextIO)


#include "dgi-opencv/dgi-image.h"
#include "dgi-opencv/dgi-demo-frame.h"


// //  this has to be included after dgi-image.h ...
 //    (because of "_flags" macro conflict ...)
#include "dhax-data/ann/dhax-annotation-instance.h"
#include "image-viewer/dhax-image-scene-item.h"


#include "dhax-forge-controller.h"

USING_KANS(DGI)

#include <QMenuBar>

#include <QImageReader>
#include <QImageWriter>


#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>

#include <QInputDialog>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QPlainTextEdit>

#include "QtColorWidgets/color_dialog.hpp"


class Special_Input_Dialog : public QInputDialog
{
 u4* autogen_index_;

 // // these are only used if the dialog
  //   also has a multiline input field ....
 QString* short_text_;
 QLineEdit* short_text_input_field_;
 QWidget* input_widget_;

public:

 Special_Input_Dialog(u4* autogen_index,
   QWidget* parent = nullptr, QString* short_text = nullptr);

 void customMenuRequested(QPoint pos);

 static QString get_text(u4* autogen_index, QWidget *parent,
   const QString &title, const QString &label, QString* short_text = nullptr,
   QLineEdit::EchoMode echo = QLineEdit::Normal,
   const QString &text = QString(), bool *ok = nullptr,
                 Qt::WindowFlags flags = Qt::WindowFlags(),
                 Qt::InputMethodHints inputMethodHints = Qt::ImhNone);

};

// //  Note: this is all for mixing a QLineEdit and QTextEdit
 //    in the input dialog.  Obviously depending on internal
 //    Qt implementation details and might be better as a
 //    hand-rolled dialog box (except it's good to keep the
 //    interface similar to QInputDilog as much as possible ...)

#include "private/qdialog_p.h"

class QPlainTextEdit;
class QSpinBox;
class QDoubleSpinBox;
class QInputDialogListView;

// //  All we need here is the d->mainLayout which is VBox ...
class QInputDialogPrivate : public QDialogPrivate
{
 Q_DECLARE_PUBLIC(QInputDialog)

public:
    QInputDialogPrivate();

    void ensureLayout();
    void ensureLineEdit();
    void ensurePlainTextEdit();
    void ensureComboBox();
    void ensureListView();
    void ensureIntSpinBox();
    void ensureDoubleSpinBox();
    void ensureEnabledConnection(QAbstractSpinBox *spinBox);
    void setInputWidget(QWidget *widget);
    void chooseRightTextInputWidget();
    void setComboBoxText(const QString &text);
    void setListViewText(const QString &text);
    QString listViewText() const;
    void ensureLayout() const { const_cast<QInputDialogPrivate *>(this)->ensureLayout(); }
    bool useComboBoxOrListView() const { return comboBox && comboBox->count() > 0; }
    void _q_textChanged(const QString &text);
    void _q_plainTextEditTextChanged();
    void _q_currentRowChanged(const QModelIndex &newIndex, const QModelIndex &oldIndex);

    mutable QLabel *label;
    mutable QDialogButtonBox *buttonBox;
    mutable QLineEdit *lineEdit;
    mutable QPlainTextEdit *plainTextEdit;
    mutable QSpinBox *intSpinBox;
    mutable QDoubleSpinBox *doubleSpinBox;
    mutable QComboBox *comboBox;
    mutable QInputDialogListView *listView;
    mutable QWidget *inputWidget;
    mutable QVBoxLayout *mainLayout;
    QInputDialog::InputDialogOptions opts;
    QString textValue;
    QPointer<QObject> receiverToDisconnectOnClose;
    QByteArray memberToDisconnectOnClose;
};


QString Special_Input_Dialog::get_text(u4* autogen_index, QWidget *parent,
  const QString &title, const QString &label, QString* short_text,
  QLineEdit::EchoMode mode, const QString &text, bool *ok,
  Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
 Special_Input_Dialog* dialog = new Special_Input_Dialog(autogen_index,
   parent, short_text); //, flags);

 dialog->setWindowTitle(title);
 dialog->setLabelText(label);
 dialog->setTextValue(text);
 dialog->setTextEchoMode(mode);
 dialog->setInputMethodHints(inputMethodHints);

 if(dialog->short_text_)
 {
  // //  setOptions causes ensureLayout(), so we're good for that ...
  dialog->setOptions(QInputDialog::UsePlainTextEditForTextInput);

  QInputDialogPrivate* d = reinterpret_cast<QInputDialogPrivate*>(dialog->QInputDialog::d_ptr.data());

  dialog->input_widget_ = qobject_cast<QWidget*>(d->plainTextEdit);

  dialog->short_text_input_field_ = new QLineEdit(dialog);
  d->mainLayout->insertWidget(1, dialog->short_text_input_field_);

  connect(dialog->short_text_input_field_, &QLineEdit::textChanged,
    [dialog](const QString& text)
  {
   *dialog->short_text_ = text;
  });

  QLabel* comment = new QLabel("Enter Comment Text:", dialog);
  d->mainLayout->insertWidget(2, comment);

 }

 const int ret = dialog->exec();
 if (ok)
   *ok = !!ret;
 if (ret)
 {
  return dialog->textValue();
 }
 else
 {
  return QString();
 }
}

#include "rpdf/bim-select-dialog.h"

Special_Input_Dialog::Special_Input_Dialog(u4* autogen_index,
  QWidget* parent, QString* short_text)
    :  QInputDialog(parent), autogen_index_(autogen_index),
      short_text_(short_text),  short_text_input_field_(nullptr),
      input_widget_(nullptr)
{
 setContextMenuPolicy(Qt::CustomContextMenu);

 connect(this, &Special_Input_Dialog::customContextMenuRequested,
   [this](QPoint pos)
 {
  qDebug() << "pos: " << pos;

  QMenu* menu = new QMenu(this);//

  menu->addAction("Autogenerate", [this]
  {
   QString text = QString("auto_%1").arg(++*this->autogen_index_);
   if(short_text_input_field_)
     short_text_input_field_->setText(text);
   else
     setTextValue(text);
  });

  menu->addAction("Open IFC Dialog", [this]
  {
   BIM_Select_Dialog* bsd = new BIM_Select_Dialog(this);
   connect(bsd, &BIM_Select_Dialog::text_chosen, [this](QString text)
   {
    QPlainTextEdit* qpte = qobject_cast<QPlainTextEdit*>(input_widget_);
    //QTextCursor text_cursor = QTextCursor(qpte->document());
    qpte->textCursor().insertText(text);
    //text_cursor.insertText(text);

   });
   bsd->show();

  });


  menu->popup(mapToGlobal(pos));
 });
}
// // //   end Special_Input_Dialog



DHAX_Application_Controller::DHAX_Application_Controller()
  :  application_main_window_(nullptr),
     main_window_controller_(nullptr),
     application_receiver_(nullptr),
     application_state_(nullptr),
     forge_controller_(nullptr),
    // display_image_data_(nullptr),
//     zoom_frame_(nullptr),
//     image_scene_item_(nullptr),
//     main_window_receiver_(nullptr),
     udp_controller_(nullptr),
     autogen_index_(0)
{

}

#ifdef USE_IFC
extern int ifc_convert_run_main(QApplication* qapp);


void DHAX_Application_Controller::run_ifc_convert()
{
 QApplication* qapp = qApp;
 ifc_convert_run_main(qapp);
}

#endif



DHAX_Forge_Controller* DHAX_Application_Controller::check_init_forge_controller()
{
 if(!forge_controller_)
 {
  forge_controller_ = new DHAX_Forge_Controller;
  forge_controller_->init_ssl();
 }

 return forge_controller_;
}

void DHAX_Application_Controller::load_notes()
{
 DHAX_Image_Scene_Item* dsi = main_window_controller_->image_scene_item();

 if(!dsi)
 {
  QMessageBox::warning(application_main_window_, "Load Image First",
    "Please load an image before attempting to load annotations");
  return;
 }

 //?cleanWindow();

 QString path = main_window_controller_->current_image_file_path();

 QFileInfo qfi(path);
 QString apath = qfi.absoluteFilePath();
 QString file_path = QFileDialog::getOpenFileName(application_main_window_,
   "Select Notes File", apath);

 if(file_path.isEmpty())
   return;

 txt_filename_path_ = file_path;

 QFile file(txt_filename_path_);

 if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
   return;

 QString line = file.readLine();

 if(!(line=="--AXFI--\n"))
   return;

 line = file.readLine();
 QString image_filename_path = line;

 r8 current_resize_factor = 0;

 DHAX_Annotation_Instance* current_annotation_instance = nullptr;

 QString mesh_position;
 QString mesh_file_path;

 QString annotation_start_line;

 while(!file.atEnd())
 {
  line = file.readLine();

  if(line.isEmpty())
    continue;

  if(line.startsWith("%%"))
  {
   annotation_start_line = line;
   continue;
  }
  if(annotation_start_line.isEmpty())
  {
   if(line.startsWith('*'))
     mesh_position = line.mid(1);
   else
     mesh_file_path = line;
   continue;
  }

  if(line.startsWith('%'))
  {
   current_resize_factor = line.mid(1).toDouble();
   continue;
  }

  if(line.startsWith('`'))
  {
   if(current_annotation_instance)
   {
    current_annotation_instance->set_comment(line.mid(1).replace('`', '\n'));
   }
   continue;
  }

  current_annotation_instance = new DHAX_Annotation_Instance;
  current_annotation_instance->from_compact_string(line);

  //? display_scene_item_->add_axfi_annotation(current_annotation, current_resize_factor);

 }

 dsi->add_dhax_annotation(current_annotation_instance, current_resize_factor);
}



QDir DHAX_Application_Controller::get_current_image_dir()
{
 QString path = main_window_controller_->current_image_file_path();

 QFileInfo qfi(path);
 return qfi.absoluteDir();
}

QString DHAX_Application_Controller::get_current_image_folder()
{
 QString path = main_window_controller_->current_image_file_path();

 QFileInfo qfi(path);
 return qfi.absolutePath();
}

QString DHAX_Application_Controller::get_current_image_complete_base_name()
{
 QString path = main_window_controller_->current_image_file_path();

 QFileInfo qfi(path);
 return qfi.completeBaseName();
}

void DHAX_Application_Controller::handle_change_image_margins(QVector<u1> values,
  u1 context)
{
 DHAX_Application_State::Image_Margins& im = application_state_->image_margins();

 DHAX_Graphics_Frame::Change_Image_Margins cim = (DHAX_Graphics_Frame::Change_Image_Margins) context;

 switch(cim)
 {
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical:
  im.top = im.bottom = values.value(0); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical2:
  im.top = values.value(0); im.bottom = values.value(1); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Horizontal:
  im.left = im.right = values.value(0); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Horizontal2:
  im.left = values.value(0); im.right = values.value(1); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal:
  im.top = im.bottom = im.left = im.right = values.value(0);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal2:
  im.top = im.bottom = values.value(0);
  im.left = im.right = values.value(1);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal4:
  im.top = values.value(0); im.bottom = values.value(1);
  im.left = values.value(3); im.right = values.value(4);
  break;

 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_Percent:
  im.percent.top = im.percent.bottom = values.value(0); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical2_Percent:
  im.percent.top = values.value(0); im.percent.bottom = values.value(1); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Horizontal_Percent:
  im.percent.left = im.percent.right = values.value(0); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Horizontal2_Percent:
  im.percent.left = values.value(0); im.percent.right = values.value(1); break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal_Percent:
  im.percent.top = im.percent.bottom = im.percent.left = im.percent.right = values.value(0);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal2_Percent:
  im.percent.top = im.percent.bottom = values.value(0);
  im.percent.left = im.percent.right = values.value(1);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Vertical_and_Horizontal4_Percent:
  im.percent.top = values.value(0); im.percent.bottom = values.value(1);
  im.percent.left = values.value(3); im.percent.right = values.value(4);
  break;

 case DHAX_Graphics_Frame::Change_Image_Margins::Image_Border1:
  im.border.top = im.border.bottom = im.border.left = im.border.right = values.value(0);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Image_Border2:
  im.border.top = im.border.bottom = values.value(0);
  im.border.left = im.border.right = values.value(1);
  break;
 case DHAX_Graphics_Frame::Change_Image_Margins::Image_Border4:
  im.border.top = values.value(0); im.border.bottom = values.value(1);
  im.border.left = values.value(3); im.border.right = values.value(4);
  break;
 }
}

QColor DHAX_Application_Controller::handle_change_color(QString application_role)
{
 color_widgets::ColorDialog dlg;

 dlg.exec();

 QColor c = dlg.color();

 if(!c.isValid())
   return {};

 QColor& ref = graphics_frame_->application_color(application_role);
   //(*graphics_frame_->application_colors())[application_role];

 if(c == ref)
   return {};

 ref = c;

 return c;
}

void DHAX_Application_Controller::handle_change_scene_background_color()
{
 QColor c = handle_change_color("scene-background-color");
 if(c.isValid())
 {
  graphics_frame_->shape_select_frame()->update_scene_color_button_color(c);
  graphics_frame_->graphics_scene()->set_background_color(c);
 }
}

void DHAX_Application_Controller::handle_change_image_border_color()
{
 QColor c = handle_change_color("image-background-center-rectangle-color");
 if(c.isValid())
   graphics_frame_->shape_select_frame()->update_border_color_button_color(c);
}


void DHAX_Application_Controller::handle_image_path_show_folder()
{
 QString f = get_current_image_folder();
 QString path = QString::fromLatin1("file://%1").arg(f);
 QDesktopServices::openUrl(QUrl::fromLocalFile(f));
}


void DHAX_Application_Controller::handle_save_requested()
{
 QString path = main_window_controller_->current_image_file_path();
 QString cbn = get_current_image_complete_base_name();

 QDir qd = get_current_image_dir();
 QString apath = qd.absoluteFilePath(cbn + ".notes.txt");

 QString file_path = QFileDialog::getSaveFileName(application_main_window_, "Select File Name", apath);
 if(file_path.isEmpty())
   return;

 QFile file(file_path);
 if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

 QTextStream ofs(&file);
 ofs << "--AXFI--\n";
 QString imageName = path;
 ofs << imageName << "\n";

 if(DHAX_Meshlab_Integration_Data* mid = application_main_window_->main_window_data()->meshlab_integration())
 {
  //?
  // if(!mid.mesh_position().isEmpty())
  //   ofs << '*' << mesh_position_ << '\n';

   if(!mid->mesh_file_path().isEmpty())
     ofs << mid->mesh_file_path() << '\n';
 }


 ofs << "%%\n";

 r8 current_resize_factor = 0;

 DHAX_Image_Scene_Item* dsi = main_window_controller_->image_scene_item();

 for(const QPair<DHAX_Annotation_Instance*, r8>& pr : dsi->saved_dhax_annotations())
 {
  if(pr.second != current_resize_factor)
  {
   current_resize_factor = pr.second;
   ofs << "%" << current_resize_factor << "\n";
  }
  DHAX_Annotation_Instance* dai = pr.first;
  QString compact = dai->to_compact_string();
  ofs << compact << '\n';
  QString comment = dai->comment();
  if(!comment.isEmpty())
  {
   comment.replace('\n', '`');
   ofs << '`' << comment << '\n';
  }
 }
}


void DHAX_Application_Controller::convert_notation_to_curve()
{
 DHAX_Drawn_Shape* dds = main_window_controller_->display_image_data()->current_drawn_shape();
 if(!dds)
   return;

 //DHAX_Drawn_Shape* cdds =
 dds->set_shape_kind(DHAX_Drawn_Shape::Shape_Kinds::Curve);

 const QPoint& p1 = dds->points()[0];
 const QPoint& p2 = dds->points()[1];

 QPoint p3 = (p1 + p2) / 2;

 dds->add_extra_point(p3);

 DHAX_Image_Viewer& image_viewer = *main_window_controller_->image_viewer();

 image_viewer.draw_circle(p1, 6, Qt::yellow, Qt::black, 1);
 image_viewer.draw_circle(p2, 6, Qt::yellow, Qt::black, 3);
 image_viewer.draw_circle(p3, 6, Qt::red, Qt::black, 2);

 main_window_controller_->display_image_data()->set_active_curve(dds);

 image_viewer.cancel_notation();

 image_viewer.update();

 //display_image_data_->set_active_curve(cdds);




 //qDebug() << "points = " << cdds->points();


}


void DHAX_Application_Controller::init_image_scene_item(DHAX_Image_Scene_Item* si)
{
 si->self_connect(SIGNAL(save_notation_requested(bool)),
   application_receiver_, SLOT(handle_save_notation(bool)));

 si->self_connect(SIGNAL(convert_notation_requested()),
   application_receiver_, SLOT(handle_convert_notation()));

// si->self_connect(SIGNAL(save_notation_requested(bool)),
//   application_receiver_, SLOT(handle_save_notation(bool)));

// si->self_connect(SIGNAL(convert_notation_requested()),
//   application_receiver_, SLOT(handle_convert_notation()));

// si->self_connect(&DHAX_Image_Scene_Item::convert_notation,
//   application_receiver_, SLOT(handle_convert_notation()));


 si->self_connect(SIGNAL(polyline_save_notation_requested(bool)),
   application_receiver_, SLOT(handle_polyline_save_notation(bool)));

// si->self_connect(SIGNAL(polyline_save_notation_with_comment_requested()),
//   application_receiver_, SLOT(handle_polyline_save_notation_with_comment()));

//?
// si->self_connect(&DHAX_Image_Scene_Item::polygon_save_notation,
//   application_receiver_, &DHAX_Application_Receiver::handle_polygon_save_notation);



 si->self_connect(SIGNAL(polygon_complete_and_save_notation_requested()),
   application_receiver_, SLOT(handle_polygon_complete_and_save_notation()));

 si->self_connect(SIGNAL(polygon_complete_and_save_notation_with_comment_requested()),
   application_receiver_, SLOT(handle_polygon_complete_and_save_notation_with_comment()));

 si->self_connect(SIGNAL(meshlab_reset_requested()),
   application_receiver_,
   SLOT(handle_meshlab_reset()));


 si->self_connect(SIGNAL(freecad_reset_requested()),
   application_receiver_,
   SLOT(handle_freecad_reset()));


 //init_image_scene_item
}


void DHAX_Application_Controller::r8_vector_to_qba(const QVector<r8>& data, QByteArray& qba)
{
 if(data.isEmpty())
   return;
 qba = QByteArray::number(data[0]);

 for(u2 i = 1; i < data.size(); ++i)
 {
  qba += ";" + QByteArray::number(data[i]);
 }
}


void DHAX_Application_Controller::send_freecad_reset()
{
 DHAX_FreeCAD_Integration_Data& fid = *application_main_window_->main_window_data()->freecad_integration();

 if(fid.freecad_position_data().isEmpty())
   return;

 QByteArray qba;

 r8_vector_to_qba(fid.freecad_position_data(), qba);

 udp_controller_->wrap_and_send_datagram(qba);
}

void DHAX_Application_Controller::send_meshlab_reset()
{
 QVector<r8> data(8);

 DHAX_Meshlab_Integration_Data& mid = *application_main_window_->main_window_data()->meshlab_integration();


 data[0] = mid.meshlab_track_info().scalar();
 data[1] = mid.meshlab_track_info().x();
 data[2] = mid.meshlab_track_info().y();
 data[3] = mid.meshlab_track_info().z();

 data[4] = mid.meshlab_scale_info();
 data[5] = mid.meshlab_center_position().x();
 data[6] = mid.meshlab_center_position().y();
 data[7] = mid.meshlab_center_position().z();

 QByteArray qba;
 r8_vector_to_qba(data, qba);

 qba.prepend(mid.meshlab_file_path().toLatin1() + "*");
 qba.prepend(mid.mesh_file_path().toLatin1() + "*");

 udp_controller_->wrap_and_send_datagram(qba);
}


void DHAX_Application_Controller::load_image(QString file_path)
{
 main_window_controller_->load_image(file_path);
}

void DHAX_Application_Controller::init_integration_controllers()
{
 DHAX_Meshlab_Integration_Data* md = new DHAX_Meshlab_Integration_Data;
 application_main_window_->main_window_data()->set_meshlab_integration(md);
 md->init_import_count();

 DHAX_Meshlab_Integration_Controller* meshlab = new DHAX_Meshlab_Integration_Controller;
 integration_controllers_["meshlab"] = meshlab;
 meshlab->set_application_controller(this);
 meshlab->set_integration_data(md);

 DHAX_FreeCAD_Integration_Data* fd = new DHAX_FreeCAD_Integration_Data;
 application_main_window_->main_window_data()->set_freecad_integration(fd);
 fd->init_import_count();

 DHAX_FreeCAD_Integration_Controller* freecad = new DHAX_FreeCAD_Integration_Controller;
 integration_controllers_["freecad"] = freecad;
 freecad->set_application_controller(this);
 freecad->set_integration_data(fd);

 //meshlab->set_integration_data()
}


void DHAX_Application_Controller::init_udp_controller()
{
 //udp_controller_->


}

void DHAX_Application_Controller::handle_complate_and_save_requested(bool with_comment)
{
 main_window_controller_->complete_polygon();
 save_current_notation(with_comment);
}

void DHAX_Application_Controller::handle_polyline_save_requested(bool with_comment)
{
 main_window_controller_->init_polyline();
 save_current_notation(with_comment);
}



void DHAX_Application_Controller::save_current_notation(bool with_comment)
{
 DHAX_Drawn_Shape* dds = main_window_controller_->display_image_data()->current_drawn_shape();
// Display_Drawn_Shape* dds = display_image_data_->current_drawn_shape();

 if(!dds)
   return;

 DHAX_Annotation_Instance* dai = dds->to_dhax_annotation(); //resize_factor_);

 //?zoom_frame_->reset_current_selected_annotation(axa);

 bool ok = false;

 QString* short_text = nullptr;

 QString name;

 if(with_comment)
   short_text = &name;

 QString dlg_result = Special_Input_Dialog::get_text(&autogen_index_,
   application_main_window_, "Need a Shape Name",
   "Enter text here providing a Shape Name (or right-click to autogenerate)",
   short_text, QLineEdit::Normal, QString(), &ok, 0);

//  QString name = Special_Input_Dialog::getMultiLineText(this, "Need a Shape Name",
//    "Enter text here providing a Shape Name (or right-click to autogenerate)");

 if(!with_comment)
   name = dlg_result;

 if(ok)
 {
  dai->add_scoped_identifier(name);

  if(with_comment)
    dai->set_comment(dlg_result);
 }

 //display_scene_item_->add

// check_init_axfi_annotation_group();
// axfi_annotation_group_->add_annotation(axa);

 DHAX_Image_Scene_Item* dsi = main_window_controller_->image_scene_item();
 dsi->add_dhax_annotation(dai, 0);

// display_scene_item_->add_axfi_annotation(axa, resize_factor_);

//? display_image_data_->reset_drawn_shapes();

}

void DHAX_Application_Controller::dispatch_datagram(QByteArray qba)
{
 QByteArray num = qba.left(3);
 int size = num.toInt();
 QByteArray qbam = qba.mid(3, size);
 QString text = QString::fromLatin1(qbam);

 QString origin;

 if(text.startsWith('+'))
 {
  int ix = text.indexOf('+', 1);
  if(ix != -1)
  {
   origin = text.mid(1, ix - 1);
   text = text.mid(ix + 1);
  }
 }

 if(!origin.isEmpty())
 {
  if(DHAX_Integration_Controller* ic = integration_controllers_.value(origin.toLower()))
  {
   ic->read_datagram(text);
  }
 }

// if(true) // // perhaps some origin won't require an outgoing ...
//   check_init_udp_outgoing_socket();

// if(origin.isEmpty() || origin == "MeshLab")
// {
////  read_udp_meshlab(text);
// }
// else if(origin == "FreeCAD")
// {
////  read_udp_freecad(text);
// }

}



void DHAX_Application_Controller::view_contours()
{
 QString image_filename_path = main_window_controller_->current_image_file_path();
 if(image_filename_path.isEmpty())
   return;

 QFileInfo qfi(image_filename_path);

 copy_binary_file_to_folder_with_rename(image_filename_path,
   DEFAULT_DHAX_TEMP_FOLDER, "iat-temp-image" );

 QString ini = DEFAULT_DHAX_TEMP_FOLDER "/iat-temp-image." + qfi.suffix();
 QString thei;
 thei = DEFAULT_DHAX_TEMP_FOLDER "/iat-temp-image-conv." + qfi.suffix();
 QImageReader reader;
 reader.setFileName(ini);

 QImage image = reader.read();
 QImage converted = image.convertToFormat(QImage::Format_RGB888);
 QImageWriter writer;
 writer.setFileName(thei);
 writer.write(converted);

 DGI_Image* dgi = new DGI_Image(thei);

 dgi->load();

 Demo_Transform_Group* dtg = new Demo_Transform_Group(dgi);
 dgi->init_demo_transform_group(*dtg);

 dgi->to_csv(DEFAULT_DGI_TEMP_FOLDER "/iat-temp-image.csv");

 QDialog* dlg = new QDialog(application_main_window_);

 dlg->setWindowTitle("Contour View");

 DGI_Demo_Frame* fr = new DGI_Demo_Frame(*dtg, 200, 800, 300);

 fr->setContextMenuPolicy(Qt::CustomContextMenu);

 fr->connect(fr, &QFrame::customContextMenuRequested,
   [this, fr, dgi](QPoint pos)
 {
  QMenu* menu = new QMenu(fr);
  menu->addAction("View Contour Info", [this, dgi]
  {
   handle_view_contour_info(dgi->saved_csv_path());
  });

  menu->popup(fr->mapToGlobal(pos));
 });

 QVBoxLayout* vbl = new QVBoxLayout;
 vbl->addWidget(fr);

 dlg->setLayout(vbl);
 dlg->show();
}

void DHAX_Application_Controller::handle_view_contour_info(QString path)
{

}
