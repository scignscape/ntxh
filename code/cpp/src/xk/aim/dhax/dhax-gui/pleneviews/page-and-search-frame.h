
#ifndef PAGE_AND_SEARCH_FRAME__H
#define PAGE_AND_SEARCH_FRAME__H

#include <QFrame>

#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>
#include <QLabel>
#include <QLineEdit>

#include <QTabWidget>

#include "global-types.h"


class Page_and_Search_Frame : public QFrame
{
 Q_OBJECT

 QVBoxLayout* main_layout_;

 QHBoxLayout* page_select_and_navigate_layout_;
 QVBoxLayout* page_select_and_navigate_layout_left_;
 QVBoxLayout* page_select_and_navigate_layout_right_;

 QHBoxLayout* page_select_layout_;
 QCheckBox* page_print_or_pdf_;
 QLabel* page_print_or_pdf_label_;
 QComboBox* page_select_;
 QLabel* page_select_label_;

 QHBoxLayout* page_navigate_layout_;
 QPushButton* page_back_button_;
 QPushButton* page_forward_button_;
 QPushButton* page_first_button_;
 QPushButton* page_last_button_;

 QHBoxLayout* special_navigate_layout_;
 QComboBox* special_select_;
 QPushButton* special_back_button_;
 QPushButton* special_forward_button_;


 QLineEdit* search_line_edit_;

 QHBoxLayout* search_layout_;

 QLabel* search_label_;
 QPushButton* search_up_button_;
 QPushButton* search_down_button_;
 QPushButton* search_from_top_button_;

// QCheckBox* search_case_sensitive_;
// QLabel* search_case_sensitive_label_;

 QPushButton* search_case_sensitive_button_;

public:

 Page_and_Search_Frame(QWidget* parent);

 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)


Q_SIGNALS:

 void page_down_requested();
 void page_up_requested();
 void page_first_requested();
 void page_last_requested();
 void page_select_requested(u4 new_page);

};


#endif
