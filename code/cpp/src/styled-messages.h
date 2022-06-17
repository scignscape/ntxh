
#include "styles.h"

#include <QMessageBox>

void QMessageBox_init_question(QMessageBox& msg, QString title, QString text)
{
 msg.setIcon(QMessageBox::Question);
 msg.setWindowTitle(title);
 msg.setText(text);
 msg.addButton(QMessageBox::Yes);
 msg.addButton(QMessageBox::No);


 msg.button(QMessageBox::Yes)->setObjectName("Yes");
 msg.button(QMessageBox::No)->setObjectName("No");

 msg.setStyleSheet(qmessagebox_button_style_sheet());
}

int QMessageBox_exec_question(QString title, QString text)
{
 QMessageBox msg;
 QMessageBox_init_question(msg, title, text);
 return msg.exec();
}


void QMessageBox_init_information(QMessageBox& msg, QString title, QString text)
{
 msg.setIcon(QMessageBox::Information);
 msg.setWindowTitle(title);
 msg.setText(text);
 msg.addButton(QMessageBox::Ok);

// msg = QMessageBox(QMessageBox::Question, header, text,
//   QMessageBox::Ok);

 msg.button(QMessageBox::Ok)->setObjectName("Ok");

 msg.setStyleSheet(qmessagebox_button_style_sheet());

 //msg.exec();
}

void QMessageBox_exec_information(QString title, QString text)
{
 QMessageBox msg;
 QMessageBox_init_information(msg, title, text);
 msg.exec();
}
