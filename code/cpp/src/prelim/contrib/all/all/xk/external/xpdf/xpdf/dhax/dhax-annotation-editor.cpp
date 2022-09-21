
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-annotation-editor.h"

#include "textio.h"

USING_KANS(TextIO)

#include <QInputDialog>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QPlainTextEdit>


#include <QVBoxLayout>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>

#include <QMessageBox>

#include "pdf-comment-dialog.h"

struct pcd_vars {
  int index;
  QVector<DHAX_Annotation_Editor::Edit_Data*> edits;
  DHAX_Annotation_Editor::Edit_Data* edit;
  std::map<QPair<int, int>, QPair<int, QPair<int, int>>>* map;
};


void DHAX_Annotation_Editor::run_tikz_margins(QMenu* m,
  const QPoint& qp, u2 page, QPair<r8, r8> pos)
{
 std::map<QPair<int, int>, QPair<int, QPair<int, int>>> map;// = nullptr;

 int chnum = file_name_.mid(file_name_.size() - 5, 1).toInt();
 qDebug() << "chnum = " << chnum;

 QString tikz_key = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/key.txt";

 tikz_key.replace('#', QString::number(chnum));
 setup_map(map, tikz_key);

 QString dir_path = AR_ROOT_DIR "/../dev/dhax-edits/ch#/pages";
 dir_path.replace('#', QString::number(chnum));
 //return xpdf_main(argc, argv);

 QString tikz_path = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/pages";
 tikz_path.replace('#', QString::number(chnum));

 QVector<DHAX_Annotation_Editor::Edit_Data*> edits;

 get_all_edits(dir_path, edits);

 int current_page = 0;

 QString tikz_margin_path = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/tikz-margin/page-includes/page-include-%1.tex";
 tikz_margin_path.replace('#', QString::number(chnum));

 QFile current_file;

 QTextStream qts;

 for(DHAX_Annotation_Editor::Edit_Data* ed : edits)
 {
  QPair<int,int> testpr = {ed->page - 1, ed->line};

  map_range<QPair<int, int>> target = find_range(map, testpr);

  interpretation in = interpret(target, testpr);
  int target_page = in.target_page;

  if(target_page != current_page)
  {
   if(current_file.isOpen())
   {
    qts.flush();
    current_file.close();
   }
   current_file.setFileName(tikz_margin_path.arg(target_page));
   if(!current_file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
    qDebug() << "problem opening file: " << current_file.fileName();
    return;
   }
   current_page = target_page;
   qts.setDevice(&current_file);
   qts << "%page" << current_page << "\n";
  }

  QString comment = ed->comment;
  if(comment == "RIC and w-t")
    comment = "RICWT";
  if(comment == "Restore CAPS")
    comment = "CAPS";
  if(comment == "Restore Caps")
    comment = "CAPS";

  int target_line = in.target_line;
  QString annot_cmd = target_line > 45? "\\rannot" : "\\lannot";
  QString annot_line = QString("%1{%2}{%3}{%4}{%5}{}\n").arg(annot_cmd).arg(target_line)
    .arg(comment).arg(ed->edit).arg(ed->first_edit);
  annot_line.replace("->", "$\\rightarrow$");
  qts << annot_line;
 }

 current_file.close();

 //DHAX_Annotation_Editor::Edit_Data* ed = pv.edits.at(pv.index);

}


void DHAX_Annotation_Editor::run_pcds(QMenu* m,
  const QPoint& qp, u2 page, QPair<r8, r8> pos)
{
 std::map<QPair<int, int>, QPair<int, QPair<int, int>>>* map = nullptr;

 int chnum = file_name_.mid(file_name_.size() - 5, 1).toInt();
 qDebug() << "chnum = " << chnum;

 QString tikz_key = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/key.txt";

 tikz_key.replace('#', QString::number(chnum));

 if(current_pcd_vars_)
 {
  map = ((pcd_vars*) current_pcd_vars_)->map;
  delete (pcd_vars*) current_pcd_vars_;
  current_pcd_vars_ = new pcd_vars {0, {}, nullptr, map};
 }
 else
 {
  map = new std::map<QPair<int, int>, QPair<int, QPair<int, int>>>;
  setup_map(*map, tikz_key);
  current_pcd_vars_ = new pcd_vars {0, {}, nullptr, map};
 }


 QString dir_path = AR_ROOT_DIR "/../dev/dhax-edits/ch#/pages";
 dir_path.replace('#', QString::number(chnum));
 //return xpdf_main(argc, argv);

 QString tikz_path = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/pages";
 tikz_path.replace('#', QString::number(chnum));

 QString pcd_path = AR_ROOT_DIR "/../dev/dhax-tikz/ch#/pcd.txt";
 pcd_path.replace('#', QString::number(chnum));

 //QVector<DHAX_Annotation_Editor::Edit_Data*> edits;


 //int index = 0;

 pcd_vars& pv = *(pcd_vars*)current_pcd_vars_;

 get_all_edits(dir_path, pv.edits);

 DHAX_Annotation_Editor::Edit_Data* ed = pv.edits.at(pv.index);
 pv.edit = ed;

 PDF_Comment_Dialog* pcd = new PDF_Comment_Dialog(map, ed, pv.index + 1);

 pcd->connect(pcd, &PDF_Comment_Dialog::search_requested,
    [pcd_path, &pv, this](u2 tsp, u2 tsl, QString text)
 {
  target_search_page_ = tsp;
  target_search_line_ = tsl;


  //qDebug() << "text = " << text;
  if(search_cb_)
    search_cb_(text);
 });

 pcd->connect(pcd, &PDF_Comment_Dialog::ok_next_requested,
    [pcd_path, &pv](PDF_Comment_Dialog* pcd)
 {
  register_new_pcd(pcd_path, *pcd->current_data());
  ++pv.index;
  if(pv.index == pv.edits.size())
    pcd->close();
  DHAX_Annotation_Editor::Edit_Data* ed = pv.edits.at(pv.index);
  pv.edit = ed;
  pcd->update_edit_data(ed, pv.index + 1);
 });

 pcd->connect(pcd, &PDF_Comment_Dialog::forward_requested,
    [pcd_path, &pv](PDF_Comment_Dialog* pcd)
 {
  ++pv.index;
  if(pv.index == pv.edits.size())
    pcd->close();
  DHAX_Annotation_Editor::Edit_Data* ed = pv.edits.at(pv.index);
  pv.edit = ed;
  pcd->update_edit_data(ed, pv.index + 1);
 });

 pcd->connect(pcd, &PDF_Comment_Dialog::backward_requested,
    [pcd_path, &pv](PDF_Comment_Dialog* pcd)
 {
  if(pv.index == 0)
    return;
  --pv.index;
  DHAX_Annotation_Editor::Edit_Data* ed = pv.edits.at(pv.index);
  pv.edit = ed;
  pcd->update_edit_data(ed, pv.index + 1);
 });

 pcd->connect(pcd, &PDF_Comment_Dialog::cancel_requested,
    [](PDF_Comment_Dialog* pcd)
 {
  pcd->close();
//  qapp.closeAllWindows();
//  qapp.quit();
  //qapp.exit();
 });


 pcd->connect(pcd, &PDF_Comment_Dialog::apply_requested,
    [pcd_path](PDF_Comment_Dialog* pcd)
 {
  register_new_pcd(pcd_path, *pcd->current_data());
 });


// pcd->connect(pcd, &QDialog::finished,
//    [&qapp](PDF_Comment_Dialog* pcd)
// {
//  pcd->close();
//  qapp.exit();
// });

// pcd->exec();
  pcd->show();
}





r8 _estimate_line(r8 height, r8 top)
{
 if(top < height)
   return 1;
 return ((top - height)/16) + 1;
}


r8 DHAX_Annotation_Editor::estimate_line(r8 height)
{
 return _estimate_line(height, column_first_line_crossing_.y());
}




class Special_Input_Dialog : public QInputDialog
{
 QPair<const QPoint*, const QPoint*> pos_;
 QPair<r8, r8> page_pos_;

 // // these are only used if the dialog
  //   also has a multiline input field ....
 QString* short_text_;
 QLineEdit* short_text_input_field_;
 QWidget* input_widget_;

public:

 Special_Input_Dialog(QPair<r8, r8> page_pos, QPair<const QPoint*, const QPoint*> pos,
   QWidget* parent = nullptr, QString* short_text = nullptr);

 bool pos_suggests_2nd_column()
 {
  return page_pos_.first >= pos_.first->x();
 }

 void customMenuRequested(QPoint pos);

 std::function<void (QString)> _handle_full_insert;
 std::function<void ()> _mark_reject;
 std::function<void ()> _mark_disagree;

 static QString get_text(
   QPair<r8, r8> page_pos,
   QPair<const QPoint*, const QPoint*> pos, QWidget *parent,
   const QString &title, const QString &label, QString* short_text = nullptr,
   QLineEdit::EchoMode echo = QLineEdit::Normal,
   const QString &text = QString(), bool *ok = nullptr,
   QPair<u1, u1>* radio = nullptr, QPair<u2[2], s2[4]>* line_page = nullptr,
   QStringList* versions = nullptr,
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

    mutable QLabel* label;
    mutable QDialogButtonBox *buttonBox;
    mutable QLineEdit *lineEdit;
    mutable QPlainTextEdit *plainTextEdit;
    mutable QSpinBox *intSpinBox;
    mutable QDoubleSpinBox *doubleSpinBox;
    mutable QComboBox *comboBox;
    mutable QInputDialogListView *listView;
    mutable QWidget *inputWidget;
    mutable QVBoxLayout* mainLayout;
    QInputDialog::InputDialogOptions opts;
    QString textValue;
    QPointer<QObject> receiverToDisconnectOnClose;
    QByteArray memberToDisconnectOnClose;
};

void _line_number_add_30(QLineEdit& qle)
{
 int num = qle.text().toUInt();
 if(num > 0)
 {
  qle.setText(QString::number(num + 30));
 }
}

void _line_number_subtract_30(QLineEdit& qle)
{
 int num = qle.text().toUInt();
 if(num > 0)
 {
  qle.setText(QString::number(num - 30));
 }
}

QString _get_ch(u1 index)
{
 static QStringList results {
  "No Visible Change",
  "Punctuation Change",
  "Hyphenation Change",
  "Spelling Change",
  "Word Change",
  "Multi-Word Change",
  "Deleted Text",
  "Added Text",
  "Non-Textual Change",
  "Capitalization Change",
  "Other Change",
 };

 return results.value(index - 1);
}


QString _get_ada(u1 index)
{
 static QStringList results {
  "Reject",
  "Disagree",
  "Prefer No Change",
  "Acquiesce",
  "Accept",
  "Approve",
 };
 return results.value(index - 1);
}


QString Special_Input_Dialog::get_text(QPair<r8, r8> page_pos,
  QPair<const QPoint*, const QPoint*> pos, QWidget *parent,
  const QString &title, const QString &label, QString* short_text,
  QLineEdit::EchoMode mode, const QString &text, bool *ok,
  QPair<u1, u1>* radio, QPair<u2[2], s2[4]>* line_page, QStringList* versions,
  Qt::WindowFlags flags, Qt::InputMethodHints inputMethodHints)
{
 Special_Input_Dialog* dialog = new Special_Input_Dialog(page_pos, pos,
   parent, short_text); //, flags);

 dialog->setWindowTitle(title);
 dialog->setLabelText(label);
 dialog->setTextValue(text);
 dialog->setTextEchoMode(mode);
 dialog->setInputMethodHints(inputMethodHints);

 QInputDialogPrivate* d = reinterpret_cast<QInputDialogPrivate*>(dialog->QInputDialog::d_ptr.data());

 if(dialog->short_text_)
 {
  // //  setOptions causes ensureLayout(), so we're good for that ...
  dialog->setOptions(QInputDialog::UsePlainTextEditForTextInput);


  dialog->input_widget_ = qobject_cast<QWidget*>(d->plainTextEdit);

  dialog->short_text_input_field_ = new QLineEdit(dialog);
  d->mainLayout->insertWidget(1, dialog->short_text_input_field_);

  connect(dialog->short_text_input_field_, &QLineEdit::textChanged,
    [dialog](const QString& text)
  {
   *dialog->short_text_ = text;
   qDebug() << "New : " << text;
  });
 }

 QButtonGroup* radios = nullptr;
 QButtonGroup* ada = nullptr;

 u1 insert_pos = 2;

 QCheckBox* copy_reject = nullptr;
 QCheckBox* copy_accept = nullptr;
 QPushButton* versions_reset = nullptr;
 QPushButton* text_reset = nullptr;

 QLineEdit* line_number = nullptr;
 QLineEdit* page_number = nullptr;
 QLineEdit* paragraph_number = nullptr;

 QLineEdit* xpar_numbers[3] = {nullptr};


 if(radio)
 {
  text_reset = new QPushButton("Reset");

  connect(text_reset, &QPushButton::clicked,
    [dialog]
  {
   dialog->short_text_input_field_->clear();
   //orig->setText({});
//   orig->clear();
//   first_edit->clear();
  });


  radios = new QButtonGroup;

  u1 ch_index = 0;

  QRadioButton* nch = new QRadioButton(_get_ch(++ch_index)); //"No Visible Change");
  QRadioButton* pch = new QRadioButton(_get_ch(++ch_index)); //"Punctuation Change");
  QRadioButton* hch = new QRadioButton(_get_ch(++ch_index)); //"Hyphenation Change");
  QRadioButton* sch = new QRadioButton(_get_ch(++ch_index)); //"Spelling Change");
  QRadioButton* wch = new QRadioButton(_get_ch(++ch_index)); //"Word Change");
  QRadioButton* mch = new QRadioButton(_get_ch(++ch_index)); //"Multi-Word Change");

  QRadioButton* dtx = new QRadioButton(_get_ch(++ch_index)); //"Deleted Text");
  QRadioButton* atx = new QRadioButton(_get_ch(++ch_index)); //"Added Text");
  QRadioButton* ntx = new QRadioButton(_get_ch(++ch_index)); //"Non-Textual Change (figures, etc.)");

  QRadioButton* cch = new QRadioButton(_get_ch(++ch_index)); //"Capitalization Change");
  QRadioButton* och = new QRadioButton(_get_ch(++ch_index)); //"Other Change");


  dialog->_handle_full_insert = [pch, cch](QString cue)
  {
   if(cue == "Punctuation Change")
     pch->setChecked(true);
   else if(cue == "Capitalization Change")
     cch->setChecked(true);
  };


  QGridLayout* radios_layout = new QGridLayout;
  radios_layout->addWidget(nch, 0, 0);
  radios_layout->addWidget(text_reset, 0, 2, Qt::AlignRight);

  radios_layout->addWidget(pch, 1, 0);
  radios_layout->addWidget(hch, 1, 1);
  radios_layout->addWidget(sch, 2, 0);
  radios_layout->addWidget(wch, 2, 1);
  radios_layout->addWidget(mch, 2, 2);
  radios_layout->addWidget(dtx, 3, 0);
  radios_layout->addWidget(atx, 3, 1);
  radios_layout->addWidget(ntx, 3, 2);
  radios_layout->addWidget(cch, 4, 0);
  radios_layout->addWidget(och, 4, 1);

  radios->addButton(nch);
  radios->addButton(pch);
  radios->addButton(hch);
  radios->addButton(sch);
  radios->addButton(wch);
  radios->addButton(mch);
  radios->addButton(dtx);
  radios->addButton(ntx);
  radios->addButton(atx);
  radios->addButton(cch);
  radios->addButton(och);

  d->mainLayout->insertLayout(insert_pos, radios_layout);
  ++insert_pos;
 }

 QRadioButton* cleft = nullptr;//new QRadioButton("Left");
 QRadioButton* cright = nullptr;//new QRadioButton("Right");

 if(line_page)
 {
  QHBoxLayout* line_page_layout = new QHBoxLayout;
  line_number = new QLineEdit;

  line_number->setToolTip("Line Number (estimated by default from mouse position)");
  line_number->setText(QString::number((u1)_estimate_line(page_pos.second, pos.first->y())));
  line_number->setMaximumWidth(50);


  QPushButton* line_up = new QPushButton("+");
  line_up->setMaximumWidth(15);
  QPushButton* line_down = new QPushButton("-");
  line_down->setMaximumWidth(15);
  QPushButton* line_1 = new QPushButton("1");
  line_1->setMaximumWidth(15);

  static auto dec_not_zero = [](int i)
  {
   return (i > 1)? i - 1: i;
  };

  connect(line_up, &QPushButton::clicked, [line_number]
  {
   line_number->setText(QString::number(line_number->text().toInt() + 1));
  });

  connect(line_down, &QPushButton::clicked, [line_number]
  {
   line_number->setText(QString::number(dec_not_zero(line_number->text().toInt())));
  });

  connect(line_1, &QPushButton::clicked, [line_number]
  {
   line_number->setText(QString::number(1));
  });


  page_number = new QLineEdit;
  page_number->setText(QString::number(line_page->first[1]));
  page_number->setMaximumWidth(50);

  QPushButton* page_up = new QPushButton("+");
  page_up->setMaximumWidth(15);
  QPushButton* page_down = new QPushButton("-");
  page_down->setMaximumWidth(15);

  connect(page_up, &QPushButton::clicked, [page_number]
  {
   page_number->setText(QString::number(page_number->text().toInt() + 1));
  });

  connect(page_down, &QPushButton::clicked, [page_number]
  {
//   static auto dec_not_zero = [](int i)
//   {
//    return (i > 1)? i - 1: i;
//   };
   page_number->setText(QString::number(dec_not_zero(page_number->text().toInt())));
  });

  // -1 = prev  -2 =  n/a  -3 = same

  paragraph_number = new QLineEdit;
  paragraph_number->setPlaceholderText("P");
  if(line_page->second[0] > 0)
    paragraph_number->setText(QString::number(line_page->second[0]));
  paragraph_number->setToolTip("\"p\" = continued from previous page");
  paragraph_number->setMaximumWidth(50);


  line_page_layout->addWidget(new QLabel("Line:"));
  line_page_layout->addWidget(line_number);

  line_page_layout->addWidget(line_up);
  line_page_layout->addWidget(line_down);

  line_page_layout->addWidget(new QLabel("Page:"));
  line_page_layout->addWidget(page_number);

  line_page_layout->addWidget(page_up);
  line_page_layout->addWidget(page_down);

  line_page_layout->addStretch();

  //  xpar_numbers[0]  =  p in orig
  xpar_numbers[0] = new QLineEdit;
  xpar_numbers[0]->setPlaceholderText("P");
  if(line_page->second[1] > 0)
    xpar_numbers[0]->setText(QString::number(line_page->second[1]));
  else if(line_page->second[1] == -1)
    xpar_numbers[0]->setPlaceholderText("Prev");
  else if(line_page->second[1] == -3)
    xpar_numbers[0]->setPlaceholderText("same");

  xpar_numbers[0]->setToolTip("Paragraph number in original text");
  xpar_numbers[0]->setMaximumWidth(50);

  line_page_layout->addWidget(new QLabel("Paragraph (original text):"));
  line_page_layout->addWidget(xpar_numbers[0]);

  d->mainLayout->insertLayout(insert_pos, line_page_layout);
  ++insert_pos;

  QHBoxLayout* xpar_layout = new QHBoxLayout;

  xpar_layout->addWidget(new QLabel("Paragraph:"));
  xpar_layout->addWidget(paragraph_number);

  QPushButton* par_up = new QPushButton("+");
  par_up->setMaximumWidth(15);
  QPushButton* par_down = new QPushButton("-");
  par_down->setMaximumWidth(15);

  xpar_layout->addWidget(par_up);
  xpar_layout->addWidget(par_down);

  xpar_layout->addStretch();


  //  xpar_numbers[2]  =  p in orig (c2)
  xpar_numbers[2] = new QLineEdit;
  if(line_page->second[3] > 0)
    xpar_numbers[2]->setText(QString::number(line_page->second[3]));
  else if(line_page->second[3] == -1)
    xpar_numbers[2]->setPlaceholderText("Prev");
  else if(line_page->second[3] == -2)
    xpar_numbers[2]->setPlaceholderText("N/A");
  else if(line_page->second[3] == -3)
    xpar_numbers[2]->setPlaceholderText("same");
  else
    xpar_numbers[2]->setPlaceholderText("N/A");

  xpar_numbers[2]->setToolTip("Paragraph number in original text (column 2)");
  xpar_numbers[2]->setMaximumWidth(50);

  xpar_layout->addWidget(new QLabel("Paragraph (original, column 2):"));
  xpar_layout->addWidget(xpar_numbers[2]);


  cleft = new QRadioButton("Left");
  cright = new QRadioButton("Right");

  QButtonGroup* left_or_right = new QButtonGroup;
  left_or_right->addButton(cleft);
  left_or_right->addButton(cright);

  connect(left_or_right, &QButtonGroup::idPressed,
          [left_or_right, line_number](s4 id)
  {
   if(id != left_or_right->checkedId())
   {
    if(id == -3)
      _line_number_add_30(*line_number);
    else if(id == -2)
     _line_number_subtract_30(*line_number);
   }
//   qDebug() << "id = " << id;
//   qDebug() << "cid = " << left_or_right->checkedId();

   //if(id == -2)
  });

//  if(line_page->second[2] == -2)
//    cleft->setChecked(true);
//  else
//    cright->setChecked(true);

  if(dialog->pos_suggests_2nd_column())
  {
   _line_number_add_30(*line_number);
   cright->setChecked(true);
  }
  else
    cleft->setChecked(true);

  // //  xpar_numbers[1] = column 2
  xpar_numbers[1] = new QLineEdit;
  if(line_page->second[2] > 0)
    xpar_numbers[1]->setText(QString::number(line_page->second[2]));
  else if(line_page->second[2] == -1)
  {
   // //  check issue about reverting to -2 when switching
    //    from right column to left on same page ...
   if(cright->isChecked())
     xpar_numbers[1]->setPlaceholderText("Prev");
   else
     xpar_numbers[1]->setPlaceholderText("N/A");
  }
  else if(line_page->second[2] == -2)
  {
   if(cright->isChecked())
     xpar_numbers[1]->setPlaceholderText("Prev");
   else
     xpar_numbers[1]->setPlaceholderText("N/A");
  }
  else
    xpar_numbers[1]->setPlaceholderText("N/A");

  xpar_numbers[1]->setToolTip("Paragraph number starting from top of right column");
  xpar_numbers[1]->setMaximumWidth(50);

  QHBoxLayout* xpar_layout1 = new QHBoxLayout;

  xpar_layout1->addWidget(new QLabel("Column:"));
  xpar_layout1->addWidget(cleft);
  xpar_layout1->addWidget(cright);
  //xpar_layout1->addStretch();
  xpar_layout1->addWidget(new QLabel("Paragraph (column 2):"));

  QPushButton* par2_up = new QPushButton("+");
  par2_up->setMaximumWidth(15);
  QPushButton* par2_down = new QPushButton("-");
  par2_down->setMaximumWidth(15);

  static auto _par_up = [](QLineEdit& qle)
  {
   int i = qle.text().toInt();
   if(i <= 0)
     i = 1;
   else
     ++i;
   qle.setText(QString::number(i));
  };

  static auto _par_down = [](QLineEdit& qle)
  {
   int i = qle.text().toInt();
   if(i > 1)
   {
    qle.setText(QString::number(i - 1));
   }
   else
     qle.setText("Prev");
  };

  connect(par_up, &QPushButton::clicked, [paragraph_number, xpar_numbers, cright]()
  {
   _par_up(*paragraph_number);
   if(cright->isChecked())
     _par_up(*xpar_numbers[1]);
  });

  connect(par_down, &QPushButton::clicked, [paragraph_number, xpar_numbers, cright]()
  {
   _par_down(*paragraph_number);
   if(cright->isChecked())
     _par_down(*xpar_numbers[1]);
  });

  connect(par2_up, &QPushButton::clicked, [xpar_numbers, cright]()
  {
   if(cright->isChecked())
     _par_up(*xpar_numbers[1]);
  });

  connect(par2_down, &QPushButton::clicked, [xpar_numbers, cright]()
  {
   if(cright->isChecked())
     _par_down(*xpar_numbers[1]);
  });


  xpar_layout1->addWidget(xpar_numbers[1]);
  xpar_layout1->addWidget(par2_up);
  xpar_layout1->addWidget(par2_down);
  xpar_layout1->addStretch();


  d->mainLayout->insertLayout(insert_pos, xpar_layout);
  ++insert_pos;
  d->mainLayout->insertLayout(insert_pos, xpar_layout1);
  ++insert_pos;
 }



 QHBoxLayout* copy_layout = new QHBoxLayout;
 if(versions)
 {
  copy_reject = new QCheckBox("Copy Reject");
  copy_accept = new QCheckBox("Copy Accept");
  copy_reject->setChecked(true);
  versions_reset = new QPushButton("Reset");
  copy_layout->addStretch();
  copy_layout->addWidget(copy_reject);
  copy_layout->addWidget(copy_accept);
  copy_layout->addWidget(versions_reset);
  d->mainLayout->insertLayout(insert_pos, copy_layout);
  ++insert_pos;
 }

// if(line_page)
// {
//  QHBoxLayout* line_page_layout = new QHBoxLayout;
//  line_number = new QLineEdit;
//  line_number->setPlaceholderText("Line");
//  line_number->setMaximumWidth(50);

//  page_number = new QLineEdit;
//  page_number->setText(QString::number(line_page->second.first));
//  page_number->setMaximumWidth(50);

//  paragraph_number = new QLineEdit;
//  paragraph_number->setPlaceholderText("P");
//  paragraph_number->setToolTip("\"p\" = continued from previous page");
//  paragraph_number->setMaximumWidth(50);


//  line_page_layout->addWidget(new QLabel("Line:"));
//  line_page_layout->addWidget(line_number);
//  line_page_layout->addStretch();
//  line_page_layout->addWidget(new QLabel("Page:"));
//  line_page_layout->addWidget(page_number);
//  line_page_layout->addStretch();
//  line_page_layout->addWidget(new QLabel("Paragraph:"));
//  line_page_layout->addWidget(paragraph_number);

//  d->mainLayout->insertLayout(insert_pos, line_page_layout);
//  ++insert_pos;
// }


 if(radio)
 {
  ada = new QButtonGroup;

  u1 ada_index = 0;

  QRadioButton* ada1 = new QRadioButton(_get_ada(++ada_index)); //"Reject");
  QRadioButton* ada2 = new QRadioButton(_get_ada(++ada_index)); //"Disagree");
  QRadioButton* ada3 = new QRadioButton(_get_ada(++ada_index)); //"Prefer No Change");
  QRadioButton* ada4 = new QRadioButton(_get_ada(++ada_index)); //"Acquiesce");
  QRadioButton* ada5 = new QRadioButton(_get_ada(++ada_index)); //"Accept");
  QRadioButton* ada6 = new QRadioButton(_get_ada(++ada_index)); //"Approve");

  dialog->_mark_reject = [ada1]()
  {
   ada1->setChecked(true);
  };

  dialog->_mark_disagree = [ada2]()
  {
   ada2->setChecked(true);
  };

  QHBoxLayout* ada_layout = new QHBoxLayout;
  ada_layout->addWidget(ada1);
  ada_layout->addWidget(ada2);
  ada_layout->addWidget(ada3);
  ada_layout->addWidget(ada4);
  ada_layout->addWidget(ada5);
  ada_layout->addWidget(ada6);
  ada_layout->addStretch();

  ada->addButton(ada1);
  ada->addButton(ada2);
  ada->addButton(ada3);
  ada->addButton(ada4);
  ada->addButton(ada5);
  ada->addButton(ada6);

  d->mainLayout->insertLayout(insert_pos, ada_layout);
  ++insert_pos;
 }



 QLineEdit* orig = nullptr;
 QLineEdit* first_edit = nullptr;

 if(versions)
 {
  QHBoxLayout* versions_layout = new QHBoxLayout;
  orig = new QLineEdit;
  orig->setPlaceholderText("Original");

  first_edit = new QLineEdit;
  first_edit->setPlaceholderText("First Edit");

  versions_layout->addWidget(new QLabel("Original:"));
  versions_layout->addWidget(orig);
  versions_layout->addWidget(new QLabel("First Edit:"));
  versions_layout->addWidget(first_edit);

  d->mainLayout->insertLayout(insert_pos, versions_layout);
  ++insert_pos;

  connect(versions_reset, &QPushButton::clicked,
    [orig, first_edit]
  {
   //orig->setText({});
   orig->clear();
   first_edit->clear();
  });


  connect(copy_reject, &QCheckBox::stateChanged, [orig, dialog](int state)
  {
   if(state == 0)
   {
    orig->clear();
   }
   if(state == 2)
   {
    QString st = dialog->short_text_input_field_->text();
    if(orig->text().isEmpty() && !st.isEmpty())
    {
     orig->setText(st);
    }
    else if(st.isEmpty() && !orig->text().isEmpty())
    {
     dialog->short_text_input_field_->setText(orig->text());
    }
   }
  });


  connect(copy_accept, &QCheckBox::stateChanged, [first_edit, dialog](int state)
  {
   if(state == 0)
   {
    first_edit->clear();
   }
   if(state == 2)
   {
    QString st = dialog->short_text_input_field_->text();
    if(first_edit->text().isEmpty() && !st.isEmpty())
    {
     first_edit->setText(st);
    }
    else if(st.isEmpty() && !first_edit->text().isEmpty())
    {
     dialog->short_text_input_field_->setText(first_edit->text());
    }
   }
  });
 }


 if(dialog->short_text_)
 {
  if(versions)
  {
   if(copy_reject && copy_accept)
   {
    connect(dialog->short_text_input_field_, &QLineEdit::textChanged,
      [copy_reject, copy_accept, orig, first_edit](const QString& text)
    {
     if(copy_reject->isChecked())
     {
      orig->setText(text);
     }
     if(copy_accept->isChecked())
     {
      first_edit->setText(text);
     }
    });
   }
  }

  QLabel* comment = new QLabel("Enter Comment Text:", dialog);
  d->mainLayout->insertWidget(insert_pos, comment);
 }

 const int ret = dialog->exec();
 if (ok)
   *ok = !!ret;
 if(radio)
 {
  *radio = {-1 - radios->checkedId(), -1 - ada->checkedId()};
 }
 if(line_page)
 {
//  u2 _line_page [2] = {(u2)line_number->text().toUInt(),
//                       (u2)page_number->text().toUInt()};

//  s2 _paragraphs [4] = {(paragraph_number->text().isEmpty() || paragraph_number->text().toLower().startsWith('p'))?
//                       (s2)-1 : (s2) paragraph_number->text().toInt(), -2, -2, -2};

  static auto par_to_num = [cright](const QLineEdit& qle, bool cols, bool orig) -> s2
  {
   // //  cols = maybe 2nd column   orig = orig par
   //s1 _default
   QString text = qle.text().toLower();
   if(text.isEmpty())
   {
    if(cols)
    {
     if(cright && cright->isChecked())
     {
      if(orig)
        return -3; // same
      return -1; // prev page
     }
     return -2; // n/a
    }
    if(orig)
      return -3; //
    return -1;
    // return cols? -2 : cright? -1 : -2;
   }
   if(cols && text.startsWith('n'))
     return -2;
   if(orig && text.startsWith('s'))
     return -3;
   if(text.startsWith('p'))
     return -1;
   return (s2) text.toInt();
  };

  line_page->first[0] = (u2)line_number->text().toUInt();
  line_page->first[1] = (u2)page_number->text().toUInt();

  //(paragraph_number->text().isEmpty() || paragraph_number->text().toLower().startsWith('p'))?
  //                      (s2)-1 : (s2) paragraph_number->text().toInt();
  line_page->second[0] = par_to_num(*paragraph_number, false, false);//xpar_numbers[0]
  line_page->second[1] = par_to_num(*xpar_numbers[0], false, true);//;
  line_page->second[2] = par_to_num(*xpar_numbers[1], true, false);
  line_page->second[3] = par_to_num(*xpar_numbers[2], true, true);

 }
 if(versions)
 {
  versions->push_back(orig->text());
  versions->push_back(first_edit->text());
 }
 if (ret)
 {
  return dialog->textValue();
 }
 else
 {
  return QString();
 }
}

//#include "rpdf/bim-select-dialog.h"

Special_Input_Dialog::Special_Input_Dialog(QPair<r8, r8> page_pos, QPair<const QPoint*,const QPoint*> pos,
  QWidget* parent, QString* short_text)
    :  QInputDialog(parent), page_pos_(page_pos), pos_(pos),
      short_text_(short_text),  short_text_input_field_(nullptr),
      input_widget_(nullptr)
{


 setContextMenuPolicy(Qt::CustomContextMenu);

 connect(this, &Special_Input_Dialog::customContextMenuRequested,
   [this](QPoint pos)
 {
  qDebug() << "pos: " << pos;

  QMenu* menu = new QMenu(this);//

  auto _add_text = [this](QString text)
  {
   QPlainTextEdit* qpte = qobject_cast<QPlainTextEdit*>(input_widget_);
       //QTextCursor text_cursor = QTextCursor(qpte->document());
   qpte->textCursor().insertText(text);
  };

  auto _menu_add_text = [menu, _add_text](QString text)
  {
   menu->addAction(QString("Insert \"%1\"").arg(text), [_add_text, text]
   {
    _add_text(text);
   });
  };

  menu->addSection("Text Inserts");

  _menu_add_text("Remove Inserted Comma");
  _menu_add_text("Remove Inserted Comma and replace 'which' with 'that'");
  _menu_add_text("Restore Capitalization");
  _menu_add_text("Replace Inserted Comma with Semi-Colon");
  _menu_add_text("Replace Inserted Comma with Colon");
  _menu_add_text("Remove Inserted Comma and Restore Em-Dash");

  menu->addSeparator();
  menu->addSection("Full Inserts");

  QString full_insert_text = "Remove Inserted Comma";
  menu->addAction(full_insert_text, [this, _add_text, full_insert_text]
  {
   _add_text(full_insert_text);
   _handle_full_insert("Punctuation Change");
   _mark_reject();
  });

  full_insert_text = "Remove Inserted Comma and Replace 'which' with 'that'";
  menu->addAction(full_insert_text, [this, _add_text, full_insert_text]
  {
   _add_text(full_insert_text);
   _handle_full_insert("Punctuation Change");
   _mark_disagree();
  });

  full_insert_text = "Restore Capitalization";
  menu->addAction(full_insert_text, [this, _add_text, full_insert_text]
  {
   _add_text(full_insert_text);
   _handle_full_insert("Punctuation Change");
   _mark_reject();
  });


//  menu->addAction("Autogenerate", [this]
//  {
//   QString text = QString("auto_%1").arg(++*this->autogen_index_);
//   if(short_text_input_field_)
//     short_text_input_field_->setText(text);
//   else
//     setTextValue(text);
//  });

//  menu->addAction("Open IFC Dialog", [this]
//  {
//   BIM_Select_Dialog* bsd = new BIM_Select_Dialog(this);
//   connect(bsd, &BIM_Select_Dialog::text_chosen, [this](QString text)
//   {
//    QPlainTextEdit* qpte = qobject_cast<QPlainTextEdit*>(input_widget_);
//    //QTextCursor text_cursor = QTextCursor(qpte->document());
//    qpte->textCursor().insertText(text);
//    //text_cursor.insertText(text);

//   });
//   bsd->show();

//  });


//  menu->popup(mapToGlobal(pos));
// });
  menu->popup(mapToGlobal(pos));
 });
}
// // //   end Special_Input_Dialog



void DHAX_Annotation_Editor::check_file_specific_path()
{
 QFileInfo qfi(file_name_);

 file_specific_path_ = full_path_;
 file_specific_path_.replace("@@", qfi.baseName());

 qDebug() << "File specific path = " << file_specific_path_;

 QDir qd(file_specific_path_);
 if(!qd.exists())
 {
  qd.mkpath(".");
 }

}


DHAX_Annotation_Editor::DHAX_Annotation_Editor()
  :
     target_search_page_(0), target_search_line_(0),
     search_cb_(nullptr), last_paragraph_{-1,-1,-2,-2}, last_page_(0),
     column_first_line_crossing_(222, 535), current_pcd_vars_(nullptr)  // //  this default works for now ...
{
 full_path_ = AR_ROOT_DIR "/../dev/dhax-edits/@@/pages";
 file_specific_path_ = full_path_;
}

QString _same_or_nonzero(s1 num)
{
 if(num == 0)
   return "same";

 return QString::number(num);
}

// -1 = prev  -2 =  n/a  -3 = same

QString _parse_par(s1 num)
{
 if(num == -3)
   return "(Same)";

 if(num == -2)
   return "N/A";

 if(num == -1)
   return "Previous Page (continued)";

 if(num == 0)
   return "";

 return QString::number(num);
}



void DHAX_Annotation_Editor::edit_data_to_short_string(Edit_Data& ed, QString& result)
{
 result = QString(R"(
kind of edit: %1
agree/disagree: %2
line: %3
page: %4
---------
paragraph: %5
paragraph (2nd column): %6)")
  .arg(_get_ch(ed.kind))
  .arg(_get_ada(ed.agree_disagree)).arg(ed.line)
  .arg(ed.page).arg(_parse_par(ed.paragraph))
  .arg(_parse_par(ed.paragraph_2nd_column))
  .arg(_same_or_nonzero(ed.offset_paragraph_original))
  .arg(_same_or_nonzero(ed.offset_paragraph_original_2nd_column))
  ;

result += QString(R"(
-------------
original: %1
current text: %2
changed text: %3
-------------

 === COMMENT ===

%4
)").arg(ed.original).arg(ed.first_edit).arg(ed.edit).arg(ed.comment)
   ;
}



void DHAX_Annotation_Editor::edit_data_to_string(Edit_Data& ed, QString& result)
{
 result = QString(R"(
version: %1
kind: %2
agree_disagree: %3
line: %4
page: %5
paragraph: %6
paragraph_2nd_column: %7
paragraph_original: %8
paragraph_original_2nd_column: %9)")
  .arg(ed.file_version).arg(ed.kind)
  .arg(ed.agree_disagree).arg(ed.line)
  .arg(ed.page).arg(ed.paragraph)
  .arg(ed.paragraph_2nd_column)
  .arg(_same_or_nonzero(ed.offset_paragraph_original))
  .arg(_same_or_nonzero(ed.offset_paragraph_original_2nd_column))
  ;

result += QString(R"(
x_pos: %1
y_pos: %2
x_point: %3
y_point: %4
edit: %5
original: %6
first_edit: %7
comment.
%8
.

%%DATA
)").arg(ed.x_pos).arg(ed.y_pos)
   .arg(ed.x_point).arg(ed.y_point)
   .arg(ed.edit).arg(ed.original)
   .arg(ed.first_edit).arg(ed.comment)
   ;

 QByteArray qba;
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << ed;
 result += qba.toBase64();
}


void DHAX_Annotation_Editor::update_test_edit_file(Edit_Data* ed)
{
 QDir qd(file_specific_path_);

 QString file_path = qd.absoluteFilePath("_test");

 QString text;
 edit_data_to_string(*ed, text);

 save_file(file_path, text);
}

void DHAX_Annotation_Editor::update_short_edit_file(QString file_path, QString append_path, Edit_Data* ed)
{
 QString text;
 edit_data_to_short_string(*ed, text);
 save_file(file_path, text);

 static QString div = "\n\n   >>>  %1  <<<\n";
 QFileInfo qfi(file_path);
 append_to_file(append_path, div.arg(qfi.fileName()), text);
}


void DHAX_Annotation_Editor::update_edit_file(QString file_path, QString append_path, Edit_Data* ed)
{
 u2 v = 0;
 QString vtos;
 QDir qd(file_specific_path_);
 while(vtos = file_path + QString::number(++v), qd.exists(vtos))
 {
  qDebug() << vtos << " already exists ...";
 }
 ed->file_version = v;
 QString text;
 edit_data_to_string(*ed, text);

 save_file(vtos, text);

 static QString div = "\n\n   >>>  %1  <<<\n";
 QFileInfo qfi(vtos);
 append_to_file(append_path, div.arg(qfi.fileName()), text);

 last_saved_file_path_ = vtos;
}


void DHAX_Annotation_Editor::update_edit_file(u2 page, u2 line, u1 index, Edit_Data* ed)
{
 QDir qd(file_specific_path_);
 QString path = qd.absoluteFilePath(QString("%1-%2-%3_").arg(page).arg(line).arg(index));
 QString append_path = qd.absoluteFilePath("_all");
 update_edit_file(path, append_path, ed);
 QString ppath = qd.absoluteFilePath(QString("p%1-l%2-i%3_v%4")
   .arg(page).arg(line).arg(index).arg(ed->file_version));
 QString sappend_path = qd.absoluteFilePath("_sall");
 update_short_edit_file(ppath, sappend_path, ed);
}

void DHAX_Annotation_Editor::update_edit_file(u2 page, u2 line)
{
 QVector<u2> pl = edit_map_.value({page, line});
 if(!pl.size())
   return;
 Edit_Data* ed = edits_.value(pl.last() - 1);
 if(!ed)
   return;
 update_edit_file(page, line, pl.size(), ed);
}

void DHAX_Annotation_Editor::context_menu
  (QMenu* m, const QPoint& qp, u2 page, QPair<r8, r8> pos)
{
 //QMenu* menu = new QMenu(nullptr);//


 m->addAction("Run PCDs", [this, m, qp, page, pos]()
 {
  run_pcds(m, qp, page, pos);
 });

 m->addAction("Run tikz/margins", [this, m, qp, page, pos]()
 {
  run_tikz_margins(m, qp, page, pos);
 });


 m->addAction("Edit", [this, m, qp, page, pos]()
 {
  show_editor_dialog(m, qp, page, pos);
 });

 m->addAction("Mark Column Position and First Line", [this, pos, qp]()//, m, qp, page, pos]()
 {
  qDebug() << "pos = " << pos << " and qp = " << qp;
  column_first_line_crossing_ = QPoint(pos.first, pos.second); // qp;
 });

 m->addAction("Mark Column Position", [this, qp]()//, m, qp, page, pos]()
 {
  column_first_line_crossing_.setX(qp.x());
  //show_editor_dialog(m, qp, page, pos);
 });

 m->addAction("Mark First Line", [this, qp]()//, m, qp, page, pos]()
 {
  column_first_line_crossing_.setY(qp.y());

  qDebug() << "Set first line at " << qp.y();
  //show_editor_dialog(m, qp, page, pos);
 });

 m->addAction("Show height and line", [this, pos, qp]()//, m, qp, page, pos]()
 {
  qDebug() << "pos = " << pos << " and qp = " << qp;

  QMessageBox::information(nullptr, "Height/Line Info",
    QString("Height = %1, Top = %2, Line estimate = %3").arg(pos.second)
    .arg(column_first_line_crossing_.y())
    .arg(estimate_line(pos.second)));


  //column_first_line_crossing_.setY(qp.y());
  //show_editor_dialog(m, qp, page, pos);
 });

 m->popup(qp); //mapToGlobal(pos));
}


void DHAX_Annotation_Editor::show_editor_dialog(QMenu* m,
  const QPoint& qp, u2 page, QPair<r8, r8> pos)
{
 if(last_page_ != page)
 {
  last_page_ = page;
  last_paragraph_[0][0] = last_paragraph_[1][0] = -1;
  last_paragraph_[0][1] = last_paragraph_[1][1] = -2;
 }
 QString edit;
 bool ok = false;
 QPair<u1, u1> radio;// = {0, 0};

 QPair<u2[2], s2[4]> line_page;// = {{0, page}, {last_paragraph_, -2, -2, -2}};// = {0, 0};
 line_page.first[0] = 0;
 line_page.first[1] = page;

 for(int i = 0; i < 4; ++i)
   line_page.second[i] = last_paragraph_[i&1][i>>1];

 //std::pair<u2[2], s2[4]> line_page {{0, page}, {last_paragraph_, -2, -2, -2}};// = {0, 0};
 QStringList versions;

 QString dlg_result = Special_Input_Dialog::get_text(
   pos, {&column_first_line_crossing_, &qp},
   nullptr, //application_main_window_,
   "Enter correction or comment",
   "Enter corrected text here (use extended box for comments/explanations)",
   &edit, QLineEdit::Normal, QString(), &ok, &radio, &line_page, &versions, 0);

 if(!ok)
   return;

 for(int i = 0; i < 4; ++i)
   last_paragraph_[i&1][i>>1] = line_page.second[i];

// qDebug() << "radio = " << radio;

// qDebug() << "comment = " << comment;

// qDebug() << "line_page = " << line_page;

// qDebug() << "dr = " << dlg_result;

// qDebug() << "versions = " << versions;

// qDebug() << "qp = " << qp;

// qDebug() << "pos = " << pos;

// u2 file_version;
// u1 kind;
// u1 agree_disagree;
// u2 line;
// u2 page;
// s2 paragraph;
// s2 paragraph_2nd_column;
// s1 offset_paragraph_original;
// s1 offset_paragraph_original_2nd_column;
// QString edit;
// QString original;
// QString first_edit;
// QString comment;
// r8 x_pos;
// r8 y_pos;

 Edit_Data* ed  = new Edit_Data{
   0,  // // file_version
   radio.first, // // kind
   radio.second, // // agree_disagree
   line_page.first[0], // // line
   line_page.first[1], // // page
   line_page.second[0], // // paragraph
   line_page.second[2], // // paragraph 2nd column
   (s1)(line_page.second[1] - line_page.second[0]), // // paragraph orig
   (s1)(line_page.second[3] - line_page.second[2]), // // paragraph orig 2
   edit, // // edit
   versions.value(0), // // original
   versions.value(1), // // first edit
   dlg_result, // // comment
   pos.first, pos.second, qp.x(), qp.y()};

 edits_.push_back(ed);

 edit_map_[{line_page.first[1], line_page.first[0]}].push_back(edits_.size());

 update_edit_file(line_page.first[1], line_page.first[0]);
}

DHAX_Annotation_Editor::Edit_Data* DHAX_Annotation_Editor::read_edit_data(const QByteArray& qba)
{
 Edit_Data* result = new Edit_Data;
 QDataStream qds(qba);
 qds >> *result;
 return result;
}


DHAX_Annotation_Editor::Edit_Data* DHAX_Annotation_Editor::read_edit_data(QString file_path)
{
 QString text = load_file(file_path);
 s4 index = text.indexOf("\n%%DATA");
 QByteArray qba = QByteArray::fromBase64(text.mid(index + 7).toLatin1());
 Edit_Data* result = new Edit_Data;
 QDataStream qds(qba);
 qds >> *result;
 return result;


// Edit_Data* result = new Edit_Data;
// QStringList qsl = text.split('\n');
// bool comments_flag =
}

DHAX_Annotation_Editor::Edit_Data* DHAX_Annotation_Editor::read_edit_data()
{
 if(last_saved_file_path_.isEmpty())
   return nullptr;

 return read_edit_data(last_saved_file_path_);
}


