
#ifndef MAIN_WINDOW_DIALOG__H
#define MAIN_WINDOW_DIALOG__H

#include <QPushButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>


class MainWindow;

class Main_Window_Dialog : public QDialog
{
 Q_OBJECT


 QVBoxLayout* main_layout_;
 MainWindow* main_window_;

 QDialogButtonBox* button_box_;
// QPushButton* button_ok_;
//// QPushButton* button_cancel_;
//// QPushButton* button_proceed_;
// QPushButton* button_close_;

protected:

 void resizeEvent(QResizeEvent* rev) Q_DECL_OVERRIDE;


public:

 Main_Window_Dialog(QWidget* parent = nullptr);

 void set_default_image_folder(QString f);
 void set_default_image_file(QString f);

};

#endif // MAIN_WINDOW_DIALOG__H
