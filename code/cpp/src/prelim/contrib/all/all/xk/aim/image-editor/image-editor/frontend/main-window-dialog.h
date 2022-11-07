
#ifndef MAIN_WINDOW_DIALOG__H
#define MAIN_WINDOW_DIALOG__H

#include <QPushButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>


class MainWindow;
class Image;
class ICommand;

struct Command_or_String {
 std::shared_ptr<ICommand> cmd;
 QString fn;

 Command_or_String(std::shared_ptr<ICommand> _cmd)
  :  cmd(_cmd) {}

 Command_or_String(QString str)
  :  cmd(nullptr), fn(str) {}

};

class Main_Window_Dialog : public QDialog
{
 Q_OBJECT

 QDialogButtonBox* button_box_;
 QPushButton* button_ok_;
 QPushButton* button_cancel_;


 QVBoxLayout* main_layout_;
 MainWindow* main_window_;

// QDialogButtonBox* button_box_;
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

 void set_window_dimensions(const QSize& size);

 Image& get_active_image();

 void load_predefined_transforms(QVector<Command_or_String> cmds);
 void run_predefined_transforms();
 void run_quantize_27x27();


};

#endif // MAIN_WINDOW_DIALOG__H
