
#include "main-window-dialog.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QScrollArea>
#include <QSizeGrip>

#include "MainWindow.h"

#include "styles.h"


//heap is managed by parent Widget (no leak), implementation with smart ptr is not suitable in this case.
//objects are used over the scope of this class.


Main_Window_Dialog::Main_Window_Dialog(QWidget* parent)
 :  QDialog(parent)
{
 main_layout_ = new QVBoxLayout;

 main_window_ = new MainWindow(this);

 main_window_->setWindowFlags(Qt::Widget);

//? QScrollArea* scroll_area_ = new QScrollArea(this);

// main_window_->setMinimumWidth(300);
// main_window_->setMinimumHeight(300);

// scroll_area_->setWidget(main_window_);
// main_layout_->addWidget(scroll_area_);

 main_layout_->addWidget(main_window_);

//  QSizeGrip* sizeGrip = new QSizeGrip(main_window_->centralWidget());
//  main_layout_->addWidget(sizeGrip);


 //scroll_area_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 // main_layout_->addWidget(main_window_);
 // button_box_ = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
 //                               Qt::Horizontal, this);

 button_box_ = new QDialogButtonBox(this);

 button_ok_ = new QPushButton("OK");
 //? button_proceed_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_ok_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());

 //?button_ok_->setEnabled(false);
 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 //?button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);


 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(close()));

 main_layout_->addWidget(button_box_);

//    connect(buttonBox, &QDialogButtonBox::accepted,
//            this, &InputDialog::accept);

//    connect(buttonBox, &QDialogButtonBox::rejected,
//            this, &InputDialog::reject);

 //main_window_->show();
    setLayout(main_layout_);
}

void Main_Window_Dialog::load_predefined_transforms(QVector<Command_or_String> cmds)
{
 main_window_->load_predefined_transforms(cmds);
}

void Main_Window_Dialog::run_predefined_transforms()
{
 main_window_->run_predefined_transforms();
}

void Main_Window_Dialog::run_quantize_27x27()
{
 main_window_->run_quantize_27x27();
}

void Main_Window_Dialog::set_default_image_file(QString f)
{
 main_window_->open_image_file(f);
 main_window_->reset_scene_rectangle();
}

void Main_Window_Dialog::set_window_dimensions(const QSize& size)
{
 QSize sz = size;
 main_window_->adjust_window_size(sz);

 resize(sz);
 main_window_->fit_image_in_view();
 //connect(main_window_, MainWindow::)
 //main_window_->on_actionZoom_Adapt_triggered();
}

void Main_Window_Dialog::set_default_image_folder(QString f)
{
 main_window_->set_default_image_folder(f);
}


Image& Main_Window_Dialog::get_active_image()
{
 return main_window_->get_active_image();
}


void Main_Window_Dialog::resizeEvent(QResizeEvent* rev)
{
 //? main_window_->resize(size().width() - 40, size().height() - 140);
}
