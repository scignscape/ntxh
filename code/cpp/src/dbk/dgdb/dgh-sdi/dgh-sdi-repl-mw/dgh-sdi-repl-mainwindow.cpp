
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dgh-sdi-repl-mainwindow.h"

USING_KANS(DGH)

DGH_SDI_REPL_MainWindow::DGH_SDI_REPL_MainWindow()
{
// main_layout_ = new QVBoxLayout;

 main_text_edit_ = new QTextEdit(this);

 main_splitter_ = new QSplitter(Qt::Vertical, this);


 main_splitter_->addWidget(main_text_edit_);

 main_notebook_ = new QTabWidget(this);
 cmd_log_text_edit_ = new QTextEdit(this);
 http_log_text_edit_ = new QTextEdit(this);

 main_console_ = QImplConsole::getInstance(this);

 main_console_->set_cb([this](const QString& cmd, int* response, QString data)
 {
  qDebug() << "cmd = " << cmd;
  u2 cmd_code = command_list_.value(cmd);
  if(cmd_code)
  {
   run_command(cmd_code);
  }
 });

 main_notebook_->addTab(main_console_, "REPL");
 main_notebook_->addTab(cmd_log_text_edit_, "CMD Logs");
 main_notebook_->addTab(http_log_text_edit_, "HTTP Logs");

 main_splitter_->addWidget(main_notebook_);

// main_layout_->addWidget(main_splitter_);

// main_layout_->addWidget(button_box_);

// setLayout(main_layout_);

 setCentralWidget(main_splitter_);

 setMinimumWidth(600);

 init_command_list();

}

void DGH_SDI_REPL_MainWindow::init_command_list()
{
 command_list_ = {
  {"gt-compile-file", 1},
  {"gt-compile-folder", 2},
  {"gt-compile-manuscript", 3}
 };
}

void DGH_SDI_REPL_MainWindow::run_command(u2 cmd_code)
{
 switch(cmd_code)
 {
 case 1: qDebug() << "file"; break;
 case 2: qDebug() << "fld"; break;
 case 3: qDebug() << "man"; break;


 }
}




