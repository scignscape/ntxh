
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef PDF_COMMENT_DIALOG__H
#define PDF_COMMENT_DIALOG__H


#include <QString>
#include <QMainWindow>

#include <QTextEdit>

#include <QLabel>
#include <QPushButton>

#include <QDialog>

#include <QApplication>

#include <QComboBox>

#include "accessors.h"

#include "flags.h"

#include "qsns.h"

#include <QEvent>
#include <QMouseEvent>

#include <QTabWidget>

#include <QFrame>

#include "dhax-annotation-editor.h"


class QPushButton;
class QTextEdit;
class QPlainTextEdit;
class QLineEdit;
class QTabWidget;
class QDialogButtonBox;
class QVBoxLayout;
class QHBoxLayout;
class QCheckBox;
class QFormLayout;
class QSplitter;
class QGridLayout;
class QListWidget;
class QTableWidget;
class QScrollArea;
class QGroupBox;
class QTableWidgetItem;
class QGraphicsRectItem;
class QRubberBand;

class QImplConsole;

struct PDF_Comment_Data {
 int edit_index;
 int self_index;

 int page;
 int line;
 double node_left;
 double node_right;
 double node1_left;
 double node1_right;

 double pdfx;
 double pdfy;
 double pdfx_offset;
 double pdfy_offset;

 QString text;
};

class PDF_Comment_Dialog : public QDialog
{
 Q_OBJECT

 DHAX_Annotation_Editor::Edit_Data* dhax_edit_data_;
 int edit_data_index_;

 QLineEdit* first_line_edit_;
 QLineEdit* search_line_edit_;
 QLineEdit* original_line_edit_;
 QLineEdit* correction_line_edit_;
 QLineEdit* comment_line_edit_;
 QLineEdit* guess_line_edit_;
 QLineEdit* guess_sc_line_edit_;

 QString guess_text_;
 QString guess_sc_text_;

 void make_guess();
 void accept_guess();

 QLineEdit* page_line_edit_;
 QLineEdit* line_line_edit_;
 QLineEdit* edit_index_line_edit_;

 QLineEdit* proof_page_line_edit_;
 QLineEdit* proof_line_line_edit_;
 QHBoxLayout* proof_page_layout_;
 QHBoxLayout* proof_line_layout_;

 QHBoxLayout* text_buttons_layout_;
 QHBoxLayout* pdfxy_layout_;


 QLineEdit* node_left_line_edit_;
 QLineEdit* node_right_line_edit_;
 QLineEdit* node1_left_line_edit_;
 QLineEdit* node1_right_line_edit_;

 QPushButton* infer_comment_text_button_;
 QPushButton* copy_comment_text_button_;
 QPushButton* request_search_button_;
 QPushButton* copy_correction_button_;
 QPushButton* copy_both_button_;


 QLineEdit* pdfx_line_edit_;
 QLineEdit* pdfy_line_edit_;
 QLineEdit* pdfx_offset_line_edit_;
 QLineEdit* pdfy_offset_line_edit_;

 QTextEdit* scratch_text_edit_;
 QTextEdit* pdf_comment_text_edit_;

 QSplitter* main_splitter_;

 QTabWidget* main_notebook_;
 QFrame* main_frame_;

// QTextEdit* cmd_log_text_edit_;
// QTextEdit* http_log_text_edit_;

 QDialogButtonBox* button_box_;
 QPushButton* button_ok_;
 QPushButton* button_cancel_;
 QPushButton* button_proceed_;

 QPushButton* button_forward_;
 QPushButton* button_backward_;

 QGridLayout* text_layout_;
 QVBoxLayout* main_layout_;

 std::map<QPair<int, int>, QPair<int, QPair<int, int>>>* map_;

 PDF_Comment_Data* current_data_;

public:

 PDF_Comment_Dialog(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>* map,
   DHAX_Annotation_Editor::Edit_Data* dhax_edit_data,
   int edit_data_index, QWidget* parent = nullptr);

 ACCESSORS(PDF_Comment_Data* ,current_data)

 //void init_from_edit_data(DHAX_Annotation_Editor::Edit_Data* ed);

 void init_from_edit_data();

 void update_edit_data(DHAX_Annotation_Editor::Edit_Data* ed,
   int edit_data_index);

 void init_current_data();

// QString get_current_text();

 //~QConsole_Dialog();

Q_SIGNALS:
// void canceled(QDialog*);
// void accepted(QDialog*);

 void forward_requested(PDF_Comment_Dialog*);
 void backward_requested(PDF_Comment_Dialog*);

 void apply_requested(PDF_Comment_Dialog*);
 void ok_next_requested(PDF_Comment_Dialog*);
 void cancel_requested(PDF_Comment_Dialog*);

 void search_requested(u2, u2, QString text);


public Q_SLOTS:
 void accept();
 void cancel();

 void proceed();


};




template<typename T>
struct map_range {
 int lower_count;
 int upper_count;
 T lower_key;
 T lower_value;
 T upper_key;
 T upper_value;
};

struct interpretation {
 int target_page;
 int target_line;
};


interpretation interpret(map_range<QPair<int, int>>& r, QPair<int, int> sourcepr);

map_range<QPair<int, int>> find_range(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>& map,
  QPair<int, int> pr);

void setup_map(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>& map,
  QString tikz_key);


void get_all_edits(QString dir_path, //?QString tikz_path,
  QVector<DHAX_Annotation_Editor::Edit_Data*>& result);

void register_new_pcd(QString pcd_path, PDF_Comment_Data& pcd);
void init_pcds(QString pcd_path, QVector<PDF_Comment_Data*>& pcds);

#endif //  PDF_COMMENT_DIALOG__H


