
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "pdf-comment-dialog.h"


#include <QApplication>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QScrollArea>
#include <QFileDialog>
#include <QTabWidget>
#include <QSplitter>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QGroupBox>

#include <QGraphicsRectItem>
#include <QRubberBand>

#include <QPlainTextEdit>
#include <QTextStream>

#include <QTableWidget>

#include <QMessageBox>

#include <QMenu>

#include <QHeaderView>
#include <QClipboard>

#include <QListWidget>


#include "styles.h"

#include "qsns.h"

#include <QDebug>
#include <QDirIterator>

#include "textio.h"

USING_KANS(TextIO)



void register_new_pcd(QString pcd_path, PDF_Comment_Data& pcd)
{
 QFile pcdfile(pcd_path);
 if (!pcdfile.open(QIODevice::Append | QIODevice::Text))
   return;

 QString indices = QString("%1 %2").arg(pcd.self_index).arg(pcd.edit_index);

 QString pdf_coords = QString(R"(%pdfx
{%1}
%pdfy
{%2}
%pdfx_offset
{%3}
%pdfy_offset
{%4}
)").arg(pcd.pdfx).arg(pcd.pdfy).arg(pcd.pdfx_offset).arg(pcd.pdfy_offset);

 QTextStream outstream(&pcdfile);
 outstream << QString(R"(
%@ %9
%page
{%1}
%line
{%2}
%comment
{%
%3
}%
%nl
{%4}
%nr
{%5}
%n1l
{%6}
%n1r
{%7}
%8
)").arg(pcd.page).arg(pcd.line).arg(pcd.text).arg(pcd.node_left)
   .arg(pcd.node_right).arg(pcd.node1_left).arg(pcd.node1_right)
   .arg(pdf_coords).arg(indices);


 pcdfile.close();
}


void init_pcds(QString pcd_path, QVector<PDF_Comment_Data*>& pcds)
{
 PDF_Comment_Data* pcd = nullptr;
 int* current_int = nullptr;
 double* current_double = nullptr;
 QString* current_string = nullptr;
 load_file(pcd_path, [&pcds, &pcd, &current_int, &current_double, &current_string](QString& line) -> int
 {
  if(line.isEmpty())
    return 0;
  if(current_string)
  {
   if(current_string->isEmpty() && line.startsWith("{%"))
   {
    return 0;
   }

   if(line.startsWith("}%"))
   {
    current_string = nullptr;
    return 0;
   }
   current_string->append(line);
   return 0;
  }
  if(line.startsWith("{"))
  {
   int index = line.indexOf("}");
   if(index == -1)
     return 0;
   QString mid = line.mid(1, index);
   if(current_int)
     *current_int = mid.toInt();
   else if(current_double)
     *current_double = mid.toDouble();

   return 0;
  }
  if(line.startsWith("%@"))
  {
   pcd = new PDF_Comment_Data {0,0,0,0,0,0,0,0,0,0,0,0,{}};
   pcds.push_back(pcd);
   current_int = nullptr;
   current_double = nullptr;
   QStringList qsl = line.mid(3).simplified().split(' ');
   pcd->self_index = qsl.value(0).toInt();
   pcd->edit_index = qsl.value(0).toInt();
   return 0;
  }
  if(line.startsWith("%comment"))
  {
   current_int = nullptr;
   current_double = nullptr;
   current_string = &pcd->text;
   return 0;
  }
  if(line.startsWith("%page"))
  {
   current_int = &pcd->page;
   current_double = nullptr;
   return 0;
  }
  if(line.startsWith("%line"))
  {
   current_int = &pcd->line;
   current_double = nullptr;
   return 0;
  }
  if(line.startsWith("%pdfx_offset"))
  {
   current_int = nullptr;
   current_double = &pcd->pdfx_offset;
   return 0;
  }
  if(line.startsWith("%pdfx"))
  {
   current_int = nullptr;
   current_double = &pcd->pdfx;
   return 0;
  }
  if(line.startsWith("%pdfy_offset"))
  {
   current_int = nullptr;
   current_double = &pcd->pdfy_offset;
   return 0;
  }
  if(line.startsWith("%pdfy"))
  {
   current_int = nullptr;
   current_double = &pcd->pdfy;
   return 0;
  }
  if(line.startsWith("%nl"))
  {
   current_int = nullptr;
   current_double = &pcd->node_left;
   return 0;
  }
  if(line.startsWith("%nr"))
  {
   current_int = nullptr;
   current_double = &pcd->node_right;
   return 0;
  }
  if(line.startsWith("%n1l"))
  {
   current_int = nullptr;
   current_double = &pcd->node1_left;
   return 0;
  }
  if(line.startsWith("%n1r"))
  {
   current_int = nullptr;
   current_double = &pcd->node1_right;
   return 0;
  }

  return 0;

 });
}




void _margin_adjust(int& gap, int low, int high)
{
 // // adjust based on line 30 being unused ...
 if( (low < 30) && (high > 30) )
   gap -= 2;
}

double get_dcut(map_range<QPair<int, int>>& r, int source_page, int source_line)
{
 int gap, source_gap = 0;
 // how many delta lines from lower to upper?
 if( r.lower_key.first == r.upper_key.first )
 {
  // same page
  source_gap = source_line - r.lower_key.second;
  _margin_adjust(source_gap, r.lower_key.second, source_line);
  gap = r.upper_key.second - r.lower_key.second;
  _margin_adjust(gap, r.lower_key.second, r.upper_key.second);
  return ((double) source_gap)/((double) gap);
  //return ((double) gap)/60;
 }
 // different pages.  Which page is the source on?
 if(source_page == r.lower_key.first)
 {
  // first page
  source_gap = source_line - r.lower_key.second;
  _margin_adjust(source_gap, r.lower_key.second, source_line);
  gap = (60 + r.upper_key.second) - r.lower_key.second;
  _margin_adjust(gap, r.lower_key.second, r.upper_key.second);
  return ((double) source_gap)/((double) gap);
 }
 // second page
 source_gap = source_line + (61 - r.lower_key.second);
 _margin_adjust(source_gap, r.lower_key.second, source_line);
 gap = r.upper_key.second + (61 - r.upper_key.second);
 _margin_adjust(gap, r.lower_key.second, r.upper_key.second);
 return ((double) source_gap)/((double) gap);
}

int get_pcut(map_range<QPair<int, int>>& r)
{
 int gap = 0;
 // how many delta lines from lower to upper?
 if( r.lower_value.first == r.upper_value.first )
 {
  // same page
  gap = r.upper_value.second - r.lower_value.second;
 }
 else
   gap = 90 - r.lower_value.second;
 return gap;
}

interpretation interpret(map_range<QPair<int, int>>& r, QPair<int, int> sourcepr)
{
 interpretation result;
 if(r.lower_count % 2)  // c %* 1
 {
  // Left hand side
  result.target_page = r.lower_value.first;

  double dcut = get_dcut(r, sourcepr.first, sourcepr.second);
  int pcut = get_pcut(r);

  qDebug() << "dcut = " << dcut;
  qDebug() << "pcut = " << pcut;

  result.target_line = dcut * pcut;
 }
 else
 {
  // Right hand side";
  result.target_page = r.lower_value.first;

  double dcut = get_dcut(r, sourcepr.first, sourcepr.second);
  int pcut = get_pcut(r);

  qDebug() << "dcut = " << dcut;
  qDebug() << "pcut = " << pcut;

  result.target_line = 45 + dcut * pcut;
 }

 return result;
}

map_range<QPair<int, int>> find_range(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>& map,
  QPair<int, int> pr)
{
 auto exact_it = map.find(pr);
 if(exact_it != map.end())
 {
  return {exact_it->second.first, 0, pr, exact_it->second.second,{0,0},{0,0}};
 }
 auto it = map.lower_bound(pr);
 if(it != map.end())
 {
  if(it == map.begin())
    return {0, it->second.first, {0,0},{0,0},it->first,it->second.second};
  auto it_1 = it;
  --it_1;
  return {it_1->second.first, it->second.first, it_1->first,it_1->second.second,it->first,it->second.second};
 }
 return {0, 0, {0,0},{0,0},{0,0},{0,0}};
}

void test_map(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>& map,
  QPair<int, int> testpr)
{
 map_range<QPair<int, int>> target = find_range(map, testpr);

 interpretation in = interpret(target, testpr);

 qDebug() << "test  = " << testpr;

 qDebug() << "in.target_page = " << in.target_page;
 qDebug() << "in.target_line = " << in.target_line;

}

void setup_map(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>& map,
  QString tikz_key)
{
 QString lines = load_file(tikz_key);
 QStringList qsl = lines.split('\n');
 int count = 0;
 for(QString qs : qsl)
 {
  ++count;
  if(qs.isEmpty())
    continue;
  qs.replace('.', " 0");
  QStringList qsl1 = qs.simplified().split(' ');
  QPair<int, int> key = {qsl1[2].toInt(), qsl1[3].toInt()};
  QPair<int, int> val = {qsl1[0].toInt(), qsl1[1].toInt()};
  map[key] = {count, val};
 }
}


void get_all_edits(QString dir_path, //?QString tikz_path,
  QVector<DHAX_Annotation_Editor::Edit_Data*>& result)
{

 QDirIterator qdi(dir_path);
 while (qdi.hasNext())
 {
  QString path = qdi.next();
  QFileInfo qfi(path);
  QString bn = qfi.baseName();
  if(bn.isEmpty())
   continue;
  QChar first = bn.at(0);
  if(first.isDigit())
  {
   QString text = load_file(path);
   int i = text.indexOf("%%DATA");
   if(i == -1)
     continue;
   QByteArray qba = QByteArray::fromBase64(text.midRef(i + 7).toLatin1());
   DHAX_Annotation_Editor::Edit_Data* ed = DHAX_Annotation_Editor::read_edit_data(qba);
   result.push_back(ed);
  }
 }

 std::sort(result.begin(), result.end(), [](const DHAX_Annotation_Editor::Edit_Data* lhs,
   const DHAX_Annotation_Editor::Edit_Data* rhs)
 {
  if(lhs->page < rhs->page)
    return true;

  if(lhs->page > rhs->page)
    return false;

  if(lhs->line < rhs->line)
    return true;

  if(lhs->line > rhs->line)
    return false;

  return false;
//  if(lhs-> < rhs->line)
//    return true;

//  if(lhs->line > rhs->line)
//    return false;

 });

}




void add_labeled_item(QWidget* parent, QWidget* widget, QString label,
  QGridLayout& layout, int row, int column, Qt::Alignment lal = {}, Qt::Alignment al = {})
{
 layout.addWidget(new QLabel(label, parent), row, column - 1, lal);
 layout.addWidget(widget, row, column, al);
}


PDF_Comment_Dialog::PDF_Comment_Dialog(std::map<QPair<int, int>, QPair<int, QPair<int, int>>>* map,
  DHAX_Annotation_Editor::Edit_Data* dhax_edit_data,
  int edit_data_index,
  QWidget* parent)
  :  QDialog(parent), map_(map),
     dhax_edit_data_(dhax_edit_data), edit_data_index_(edit_data_index)
{
 current_data_ = new PDF_Comment_Data{0,0,0,0,0,0,0,0,0,0,0,0,{}};

 button_box_ = new QDialogButtonBox(this);

 button_ok_ = new QPushButton("OK/Next");
 button_proceed_ = new QPushButton("Apply");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 button_proceed_->setDefault(false);
 button_proceed_->setAutoDefault(false);

 //button_ok_->setEnabled(false);

// button_box_->addButton(button_backward_, QDialogButtonBox::HelpRole);
// button_box_->addButton(button_forward_, QDialogButtonBox::HelpRole);

 //button_box_->a

 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);

 button_ok_->setStyleSheet(basic_button_style_sheet_());
 button_proceed_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());

 connect(button_proceed_, SIGNAL(clicked()), this, SLOT(proceed()));
 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(cancel()));



 main_notebook_ = new QTabWidget(this);
 main_frame_ = new QFrame(this);

 text_layout_ = new QGridLayout;

 first_line_edit_ = new QLineEdit("", this);
 search_line_edit_ = new QLineEdit("", this);
 correction_line_edit_ = new QLineEdit("", this);
 original_line_edit_ = new QLineEdit("", this);
 comment_line_edit_ = new QLineEdit("", this);

 guess_line_edit_ = new QLineEdit("", this);
 guess_sc_line_edit_ = new QLineEdit("", this);


 page_line_edit_ = new QLineEdit("", this);
 line_line_edit_ = new QLineEdit("", this);
 page_line_edit_->setMaximumWidth(35);
 line_line_edit_->setMaximumWidth(35);

 signed int row = -1;

 add_labeled_item(this, first_line_edit_, "First Edit:", *text_layout_, ++row, 1);
 add_labeled_item(this, search_line_edit_, "Search Text:", *text_layout_, ++row, 1);
 add_labeled_item(this, correction_line_edit_, "Correction:", *text_layout_, ++row, 1);
 add_labeled_item(this, original_line_edit_, "Original:", *text_layout_, ++row, 1);
 add_labeled_item(this, comment_line_edit_, "Comment:", *text_layout_, ++row, 1);

 add_labeled_item(this, page_line_edit_, "Page:", *text_layout_, ++row, 1);
 add_labeled_item(this, line_line_edit_, "Line:", *text_layout_, ++row, 1);

 edit_index_line_edit_ = new QLineEdit(QString::number(edit_data_index_), this);
 edit_index_line_edit_->setMaximumWidth(35);

 add_labeled_item(this, edit_index_line_edit_, "Edit Index:", *text_layout_, ++row, 1);

 add_labeled_item(this, guess_line_edit_, "Guess:", *text_layout_, ++row, 1);
 add_labeled_item(this, guess_sc_line_edit_, "Guess (short):", *text_layout_, ++row, 1);

 scratch_text_edit_ = new QTextEdit(this);

 QGroupBox* scratch_text_edit_box = new QGroupBox(tr("Scratch/Clipboard Text"));
 QHBoxLayout* l = new QHBoxLayout;
 l->addWidget(scratch_text_edit_);
 scratch_text_edit_box->setLayout(l);
 text_layout_->addWidget(scratch_text_edit_box, ++row, 0, 1, 2);

 QPalette p = scratch_text_edit_->palette(); // define pallete for textEdit..
 p.setColor(QPalette::Base, QColor("pink")); // set color "Red" for textedit base
 //p.setColor(QPalette::Text, color); // set text color which is selected from color pallete
 scratch_text_edit_->setPalette(p);

 main_frame_->setLayout(text_layout_);

 main_notebook_->addTab(main_frame_, "Main");
// main_splitter_->addWidget(first_text_edit_);
// main_splitter_->addWidget(main_text_edit_);


 main_layout_ = new QVBoxLayout;


 //first_text_edit_->setLa

 main_splitter_ = new QSplitter(Qt::Vertical, this);
 main_splitter_->addWidget(main_notebook_);

 pdf_comment_text_edit_ = new QTextEdit(this);
 main_splitter_->addWidget(pdf_comment_text_edit_);


 main_layout_->addWidget(main_splitter_);

 proof_page_line_edit_ = new QLineEdit("", this);
 proof_line_line_edit_ = new QLineEdit("", this);
 proof_page_line_edit_->setMaximumWidth(35);
 proof_line_line_edit_->setMaximumWidth(35);



 proof_page_layout_ = new QHBoxLayout;
 proof_line_layout_ = new QHBoxLayout;
 pdfxy_layout_ = new QHBoxLayout;
 text_buttons_layout_ = new QHBoxLayout;

 proof_page_layout_->addWidget(new QLabel("Proof Page", this));
 proof_line_layout_->addWidget(new QLabel("Proof Line", this));

 proof_page_layout_->addWidget(proof_page_line_edit_);
 proof_line_layout_->addWidget(proof_line_line_edit_);

 QPushButton* page_up = new QPushButton("+");
 page_up->setMaximumWidth(15);
 QPushButton* page_down = new QPushButton("-");
 page_down->setMaximumWidth(15);
 proof_page_layout_->addWidget(page_up);
 proof_page_layout_->addWidget(page_down);

 QPushButton* line_up = new QPushButton("+");
 line_up->setMaximumWidth(15);
 QPushButton* line_down = new QPushButton("-");
 line_down->setMaximumWidth(15);
 proof_line_layout_->addWidget(line_up);
 proof_line_layout_->addWidget(line_down);

 proof_page_layout_->addStretch();
 proof_line_layout_->addStretch();

 static auto dec_not_zero = [](int i)
 {
  return (i > 1)? i - 1: i;
 };

 static auto dec_not_zeror = [](double i)
 {
  return (i > 1)? i - 1: i;
 };

 connect(page_up, &QPushButton::clicked, [this]
 {
  proof_page_line_edit_->setText(QString::number(proof_page_line_edit_->text().toInt() + 1));
 });

 connect(page_down, &QPushButton::clicked, [this]
 {
  proof_page_line_edit_->setText(QString::number(dec_not_zero(proof_page_line_edit_->text().toInt())));
 });


 connect(line_up, &QPushButton::clicked, [this]
 {
  proof_line_line_edit_->setText(QString::number(proof_line_line_edit_->text().toInt() + 1));
 });

 connect(line_down, &QPushButton::clicked, [this]
 {
  proof_line_line_edit_->setText(QString::number(dec_not_zero(proof_line_line_edit_->text().toInt())));
 });


 node_left_line_edit_ = new QLineEdit("", this);
 node_left_line_edit_->setMaximumWidth(35);
 node_right_line_edit_ = new QLineEdit("", this);
 node_right_line_edit_->setMaximumWidth(35);
 node1_left_line_edit_ = new QLineEdit("", this);
 node1_left_line_edit_->setMaximumWidth(35);
 node1_right_line_edit_ = new QLineEdit("", this);
 node1_right_line_edit_->setMaximumWidth(35);
 QPushButton* node_left_up = new QPushButton("+");
 node_left_up->setMaximumWidth(15);
 QPushButton* node_left_down = new QPushButton("-");
 node_left_down->setMaximumWidth(15);
 QPushButton* node1_left_up = new QPushButton("+");
 node1_left_up->setMaximumWidth(15);
 QPushButton* node1_left_down = new QPushButton("-");
 node1_left_down->setMaximumWidth(15);
 QPushButton* node_right_up = new QPushButton("+");
 node_right_up->setMaximumWidth(15);
 QPushButton* node_right_down = new QPushButton("-");
 node_right_down->setMaximumWidth(15);
 QPushButton* node1_right_up = new QPushButton("+");
 node1_right_up->setMaximumWidth(15);
 QPushButton* node1_right_down = new QPushButton("-");
 node1_right_down->setMaximumWidth(15);

 proof_page_layout_->addWidget(new QLabel("Node Left:", this));
 proof_page_layout_->addWidget(node_left_line_edit_);
 proof_page_layout_->addWidget(node_left_up);
 proof_page_layout_->addWidget(node_left_down);

 proof_page_layout_->addStretch();

 proof_page_layout_->addWidget(new QLabel("Node1 Left:", this));
 proof_page_layout_->addWidget(node1_left_line_edit_);
 proof_page_layout_->addWidget(node1_left_up);
 proof_page_layout_->addWidget(node1_left_down);


 proof_line_layout_->addWidget(new QLabel("Node Right:", this));
 proof_line_layout_->addWidget(node_right_line_edit_);
 proof_line_layout_->addWidget(node_right_up);
 proof_line_layout_->addWidget(node_right_down);

 proof_line_layout_->addStretch();

 proof_line_layout_->addWidget(new QLabel("Node1 Right:", this));
 proof_line_layout_->addWidget(node1_right_line_edit_);
 proof_line_layout_->addWidget(node1_right_up);
 proof_line_layout_->addWidget(node1_right_down);


 connect(node_left_up, &QPushButton::clicked, [this]
 {
  node_left_line_edit_->setText(QString::number(node_left_line_edit_->text().toDouble() + 1));
 });

 connect(node_left_down, &QPushButton::clicked, [this]
 {
  node_left_line_edit_->setText(QString::number(dec_not_zeror(node_left_line_edit_->text().toDouble())));
 });

 connect(node1_left_up, &QPushButton::clicked, [this]
 {
  node1_left_line_edit_->setText(QString::number(node1_left_line_edit_->text().toDouble() + 1));
 });

 connect(node1_left_down, &QPushButton::clicked, [this]
 {
  node1_left_line_edit_->setText(QString::number(dec_not_zeror(node1_left_line_edit_->text().toDouble())));
 });

 connect(node_right_up, &QPushButton::clicked, [this]
 {
  node_right_line_edit_->setText(QString::number(node_right_line_edit_->text().toDouble() + 1));
 });

 connect(node_right_down, &QPushButton::clicked, [this]
 {
  node_right_line_edit_->setText(QString::number(dec_not_zeror(node_right_line_edit_->text().toDouble())));
 });

 connect(node1_right_up, &QPushButton::clicked, [this]
 {
  node1_right_line_edit_->setText(QString::number(node1_right_line_edit_->text().toDouble() + 1));
 });

 connect(node1_right_down, &QPushButton::clicked, [this]
 {
  node1_right_line_edit_->setText(QString::number(dec_not_zeror(node1_right_line_edit_->text().toDouble())));
 });


 pdfx_line_edit_ = new QLineEdit("", this);
 pdfy_line_edit_ = new QLineEdit("", this);
 pdfx_offset_line_edit_ = new QLineEdit("", this);
 pdfy_offset_line_edit_ = new QLineEdit("", this);
 pdfx_line_edit_->setMaximumWidth(35);
 pdfy_line_edit_->setMaximumWidth(35);
 pdfx_offset_line_edit_->setMaximumWidth(35);
 pdfy_offset_line_edit_->setMaximumWidth(35);

// node_right_line_edit_ = new QLineEdit("", this);
// node_right_line_edit_->setMaximumWidth(35);

 infer_comment_text_button_ = new QPushButton("Guess OK", this);

 connect(infer_comment_text_button_, &QPushButton::clicked,
   [this]()
 {
  //QString text = "??";
  pdf_comment_text_edit_->insertPlainText(guess_sc_text_);

 });

 auto copy_correction_cb = [this]()
 {
  QClipboard* clipboard = QGuiApplication::clipboard();
  QString text = correction_line_edit_->text().simplified();
  if(text.isEmpty())
    return;
  text.prepend("\n\n........\n\n");
  text.append("\n\n........");
  clipboard->setText(text);
  scratch_text_edit_->setText(text);
 };

 copy_correction_button_ = new QPushButton("Copy Correction", this);
 connect(copy_correction_button_, &QPushButton::clicked, copy_correction_cb);

 auto copy_comment_text_cb = [this]()
 {
  QClipboard* clipboard = QGuiApplication::clipboard();

  if(pdf_comment_text_edit_->toPlainText().isEmpty())
  {
   QString lines = guess_text_;
   lines.replace('^', '\n');
   clipboard->setText(lines);
   scratch_text_edit_->setText(lines);
   //pdf_comment_text_edit_->insertPlainText(lines.prepend("\n\n*****\n\n"));
  }
  else
  {
   scratch_text_edit_->setText(pdf_comment_text_edit_->toPlainText());
   clipboard->setText(pdf_comment_text_edit_->toPlainText());
  }
  //QString text = "??";
 };

 copy_comment_text_button_ = new QPushButton("Copy Guess/Text", this);
 connect(copy_comment_text_button_, &QPushButton::clicked, copy_comment_text_cb);

 copy_both_button_ = new QPushButton("Copy Both", this);
 connect(copy_both_button_, &QPushButton::clicked, [this,
   copy_comment_text_cb, copy_correction_cb]
 {
  copy_correction_cb();
  copy_comment_text_cb();
 });


 request_search_button_ = new QPushButton("Search");
 request_search_button_->setMaximumWidth(60);
 connect(request_search_button_, &QPushButton::clicked,
   [this]()
 {
  Q_EMIT search_requested(proof_page_line_edit_->text().toInt(),
     proof_line_line_edit_->text().toInt(),
     search_line_edit_->text());
  //QString text = "??";
  //pdf_comment_text_edit_->insertPlainText(guess_sc_text_);

 });

 text_buttons_layout_->addWidget(infer_comment_text_button_);
 text_buttons_layout_->addWidget(copy_comment_text_button_);
 text_buttons_layout_->addWidget(request_search_button_);
 text_buttons_layout_->addStretch();
 text_buttons_layout_->addWidget(copy_correction_button_);
 text_buttons_layout_->addWidget(copy_both_button_);
 text_buttons_layout_->addStretch();


 button_forward_ = new QPushButton("->", this);
 button_backward_ = new QPushButton("<-", this);
 button_forward_->setMaximumWidth(30);
 button_backward_->setMaximumWidth(30);

 connect(button_forward_, &QPushButton::clicked, [this]()
 {
  Q_EMIT forward_requested(this);
 });
 //void forward_requested(PDF_Comment_Dialog*);

 connect(button_backward_, &QPushButton::clicked, [this]()
 {
  Q_EMIT backward_requested(this);
 });



 text_buttons_layout_->addWidget(button_backward_);
 text_buttons_layout_->addWidget(button_forward_);

 text_buttons_layout_->addStretch();

 main_layout_->addLayout(text_buttons_layout_);


 pdfxy_layout_->addWidget(new QLabel("PDFX:", this));
 pdfxy_layout_->addWidget(pdfx_line_edit_);
 pdfxy_layout_->addWidget(new QLabel("PDFY:", this));
 pdfxy_layout_->addWidget(pdfy_line_edit_);
 pdfxy_layout_->addStretch();

 pdfxy_layout_->addWidget(new QLabel("PDFX Offset:", this));
 pdfxy_layout_->addWidget(pdfx_offset_line_edit_);
 pdfxy_layout_->addWidget(new QLabel("PDFY Offset:", this));
 pdfxy_layout_->addWidget(pdfy_offset_line_edit_);
 pdfxy_layout_->addStretch();

 QPushButton* pdfx_up = new QPushButton("+");
 pdfx_up->setMaximumWidth(15);
 QPushButton* pdfx_down = new QPushButton("-");
 pdfx_down->setMaximumWidth(15);
 QPushButton* pdfy_up = new QPushButton("+");
 pdfy_up->setMaximumWidth(15);
 QPushButton* pdfy_down = new QPushButton("-");
 pdfy_down->setMaximumWidth(15);
 QPushButton* pdfx_offset_up = new QPushButton("+");
 pdfx_offset_up->setMaximumWidth(15);
 QPushButton* pdfx_offset_down = new QPushButton("-");
 pdfx_offset_down->setMaximumWidth(15);
 QPushButton* pdfy_offset_up = new QPushButton("+");
 pdfy_offset_up->setMaximumWidth(15);
 QPushButton* pdfy_offset_down = new QPushButton("-");
 pdfy_offset_down->setMaximumWidth(15);

 connect(pdfx_up, &QPushButton::clicked, [this]
 {
  pdfx_line_edit_->setText(QString::number(pdfx_line_edit_->text().toDouble() + 1));
 });

 connect(pdfx_down, &QPushButton::clicked, [this]
 {
  pdfx_line_edit_->setText(QString::number(dec_not_zeror(pdfx_line_edit_->text().toDouble())));
 });

 connect(pdfy_up, &QPushButton::clicked, [this]
 {
  pdfy_line_edit_->setText(QString::number(pdfy_line_edit_->text().toDouble() + 1));
 });

 connect(pdfy_down, &QPushButton::clicked, [this]
 {
  pdfy_line_edit_->setText(QString::number(dec_not_zeror(pdfy_line_edit_->text().toDouble())));
 });

 connect(pdfx_offset_up, &QPushButton::clicked, [this]
 {
  pdfx_offset_line_edit_->setText(QString::number(pdfx_offset_line_edit_->text().toDouble() + 1));
 });

 connect(pdfx_offset_down, &QPushButton::clicked, [this]
 {
  pdfx_offset_line_edit_->setText(QString::number(dec_not_zeror(pdfx_offset_line_edit_->text().toDouble())));
 });

 connect(pdfy_offset_up, &QPushButton::clicked, [this]
 {
  pdfy_offset_line_edit_->setText(QString::number(pdfy_offset_line_edit_->text().toDouble() + 1));
 });

 connect(pdfy_offset_down, &QPushButton::clicked, [this]
 {
  pdfy_offset_line_edit_->setText(QString::number(dec_not_zeror(pdfy_offset_line_edit_->text().toDouble())));
 });

 main_layout_->addLayout(pdfxy_layout_);

 main_layout_->addLayout(proof_page_layout_);
 main_layout_->addLayout(proof_line_layout_);


// main_notebook_ = new QTabWidget(this);
// cmd_log_text_edit_ = new QTextEdit(this);
// http_log_text_edit_ = new QTextEdit(this);

// main_notebook_->addTab(main_console_, "REPL");
// main_notebook_->addTab(cmd_log_text_edit_, "CMD Logs");
// main_notebook_->addTab(http_log_text_edit_, "HTTP Logs");
// main_splitter_->addWidget(main_notebook_);

 main_layout_->addWidget(button_box_);

 setLayout(main_layout_);

 setMinimumWidth(600);


 // //  handle shortcuts


 pdf_comment_text_edit_->setContextMenuPolicy(Qt::CustomContextMenu);

 auto _add_text = [this](QString text)
 {
  pdf_comment_text_edit_->textCursor().insertText(text);
 };

 connect(pdf_comment_text_edit_, &QDialog::customContextMenuRequested,
   [this, _add_text](QPoint pos)
 {
  qDebug() << "pos: " << pos;

  QMenu* menu = new QMenu(this);//


//   QPlainTextEdit* qpte = qobject_cast<QPlainTextEdit*>(input_widget_);
//       //QTextCursor text_cursor = QTextCursor(qpte->document());
//   qpte->textCursor().insertText(text);
//  };

  auto _menu_add_text = [menu, _add_text](QString note, QString text)
  {
   menu->addAction(QString("Insert \"%1\"").arg(note), [_add_text, note, text]
   {
    _add_text(text);
   });
  };

  menu->addSection("Text Inserts");

  _menu_add_text("Change to: (&&/ct/)", "&/ct/ ");
  _menu_add_text("remove comma (&&/rc/)", "&/rc/ ");
  _menu_add_text("restore em-dash (&&/re/)", "&/re/ ");
  _menu_add_text("remove comma and restore em-dash (&&/rcre/)", "&/rcre/ ");
  _menu_add_text("Change to Uppercase: (&&/ctu/)", "&/ctu/ ");
  _menu_add_text("Change to Lowercase: (&&/ctl/)", "&/ctl/ ");


//  _menu_add_text("Remove Inserted Comma and replace 'which' with 'that'");
//  _menu_add_text("Restore Capitalization");
//  _menu_add_text("Replace Inserted Comma with Semi-Colon");
//  _menu_add_text("Replace Inserted Comma with Colon");
//  _menu_add_text("Remove Inserted Comma and Restore Em-Dash");

  menu->addSeparator();

  menu->addAction(QString("Full Change To:"), [this, _add_text]
  {
   QString text = correction_line_edit_->text();
   text.prepend("&/ct/: ");
   _add_text(text);
  });

  menu->addAction(QString("Full Change To Uppercase:"), [this, _add_text]
  {
   QString text = correction_line_edit_->text();
   text.prepend("&/ctu/: ");
   _add_text(text);
  });

  menu->addAction(QString("Full Change To Lowercase:"), [this, _add_text]
  {
   QString text = correction_line_edit_->text();
   text.prepend("&/ctl/: ");
   _add_text(text);
  });

  menu->popup(pdf_comment_text_edit_->mapToGlobal(pos));
 });
 // menu->addSection("Full Inserts");


 // //  finally,

 init_from_edit_data();


}

void PDF_Comment_Dialog::init_current_data()
{
 current_data_->edit_index = edit_index_line_edit_->text().toInt(); // edit_data_index_;
 current_data_->self_index = edit_data_index_;

 current_data_->page = proof_page_line_edit_->text().toInt();
 current_data_->line = proof_line_line_edit_->text().toInt();
 current_data_->node_left = node_left_line_edit_->text().toDouble();
 current_data_->node_right = node_right_line_edit_->text().toDouble();
 current_data_->node1_left = node1_left_line_edit_->text().toDouble();
 current_data_->node1_right = node1_right_line_edit_->text().toDouble();

 current_data_->pdfx = pdfx_line_edit_->text().toDouble();
 current_data_->pdfy = pdfy_line_edit_->text().toDouble();
 current_data_->pdfx_offset = pdfx_offset_line_edit_->text().toDouble();
 current_data_->pdfy_offset = pdfy_offset_line_edit_->text().toDouble();

 current_data_->text = pdf_comment_text_edit_->toPlainText();
}

void PDF_Comment_Dialog::update_edit_data(DHAX_Annotation_Editor::Edit_Data* ed,
  int edit_data_index)
{
 *current_data_ = {0,0,0,0,0,0,0,0,0,0,0,0,{}};
 dhax_edit_data_ = ed;
 edit_data_index_ = edit_data_index;
 init_from_edit_data();
 pdf_comment_text_edit_->clear();
}


void PDF_Comment_Dialog::make_guess()
{
 guess_text_.clear();
 guess_sc_text_.clear();
 QString comment = dhax_edit_data_->comment;

 if(comment == "Remove Inserted Comma")
 {
  guess_text_ = "remove comma";
  guess_sc_text_ = "&/rc/";
 }


 if(comment == "Restore 'which' instead of 'that'")
 {
  guess_text_ = "remove that and insert: ^^which";
  guess_sc_text_ = "&/rwt/";
 }


 if(comment == "Remove Inserted Comma and Replace 'which' with 'that'")
 {
  guess_text_ = "remove comma.  Also, change which to: ^^that";
  guess_sc_text_ = "&/rcwt/";
 }

 if(comment == "Remove Inserted Comma and replace 'which' with 'that'")
 {
  guess_text_ = "remove comma.  Also, change which to: ^^that";
  guess_sc_text_ = "&/rcwt/";
 }

 if(comment == "Remove Inserted Comma and Restore Em-Dash")
 {
  guess_text_ = "remove comma and replace with: ---";
  guess_sc_text_ = "&/rcen/";
 }

 if(comment.contains("capitalization", Qt::CaseInsensitive))
 {
  guess_text_ = "Convert to Uppercase: ^^" + dhax_edit_data_->edit;
  guess_sc_text_ = "&/uc/: ^^&/$ed/";
 }

 guess_line_edit_->setText(guess_text_);
 guess_sc_line_edit_->setText(guess_sc_text_);
}



void PDF_Comment_Dialog::init_from_edit_data() //DHAX_Annotation_Editor::Edit_Data* ed)
{
 make_guess();

 edit_index_line_edit_->setText(QString::number(edit_data_index_));

 first_line_edit_->setText( dhax_edit_data_->first_edit );
 search_line_edit_->setText( dhax_edit_data_->first_edit );
 correction_line_edit_->setText( dhax_edit_data_->edit );
 comment_line_edit_->setText( dhax_edit_data_->comment );
 original_line_edit_->setText( dhax_edit_data_->original );

 page_line_edit_->setText( QString::number( dhax_edit_data_->page ));
 line_line_edit_->setText( QString::number( dhax_edit_data_->line ));

 QPair<int,int> testpr = {dhax_edit_data_->page - 1, dhax_edit_data_->line};

 map_range<QPair<int, int>> target = find_range(*map_, testpr);

 interpretation in = interpret(target, testpr);
 proof_page_line_edit_->setText(QString::number(in.target_page));
 proof_line_line_edit_->setText(QString::number(in.target_line));

}



void PDF_Comment_Dialog::cancel()
{
 Q_EMIT(cancel_requested(this));
// Q_EMIT(rejected());
// Q_EMIT(canceled(this));
// close();
}

void PDF_Comment_Dialog::proceed()
{
 init_current_data();
 Q_EMIT(apply_requested(this));
}


void PDF_Comment_Dialog::accept()
{
 init_current_data();
 Q_EMIT(ok_next_requested(this));
 //Q_EMIT(accepted(this));
}
