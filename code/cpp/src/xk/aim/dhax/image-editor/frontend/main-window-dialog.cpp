
#include "main-window-dialog.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QScrollArea>
#include <QSizeGrip>

#include "MainWindow.h"


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

 button_box_ = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, this);

 main_layout_->addWidget(button_box_);

//    connect(buttonBox, &QDialogButtonBox::accepted,
//            this, &InputDialog::accept);

//    connect(buttonBox, &QDialogButtonBox::rejected,
//            this, &InputDialog::reject);

 //main_window_->show();
    setLayout(main_layout_);
}


void Main_Window_Dialog::set_default_image_folder(QString f)
{
 main_window_->set_default_image_folder(f);
}


void Main_Window_Dialog::resizeEvent(QResizeEvent* rev)
{
 //?main_window_->resize(size().width() - 40, size().height() - 140);
}
