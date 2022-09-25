
//          Copyright Nathaniel Christen 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef TILE_SERVER_SELECT_DIALOG__H
#define TILE_SERVER_SELECT_DIALOG__H

#include <QObject>

#include <QMetaType>

#include <QList>

#include <QPoint>

#include <QDialog>
#include <QTableWidget>

#include <functional>

class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QFrame;
class QHBoxLayout;
class QVBoxLayout;
class QSlider;
class QPlainTextEdit;
class QBoxLayout;
class QButtonGroup;
class QGroupBox;
class QScrollArea;
class QGridLayout;
class QMediaPlayer;
class QProcess;
class QTcpServer;

class ScignStage_Clickable_Label;

class XPDF_Bridge;

class QFormLayout;

class QComboBox;

class Tile_Server_Select_Dialog : public QDialog
{

 Q_OBJECT

 QDialogButtonBox* button_box_;
 QPushButton* button_ok_;
 QPushButton* button_cancel_;
 QPushButton* button_proceed_;


 //?QHBoxLayout* middle_layout_;
 QVBoxLayout* main_layout_;

 QFormLayout* form_layout_;

 QComboBox* server_name_combo_box_;
 QLineEdit* api_key_;
 QComboBox* overlay_combo_box_;
 QComboBox* local_server_combo_box_;

 //QLabel* sentence_label_;

public:



 Tile_Server_Select_Dialog(QWidget* parent = nullptr);

 ~Tile_Server_Select_Dialog();

Q_SIGNALS:
 void canceled(QDialog*);
 void accepted(QDialog*);
 void take_screenshot_requested();

public Q_SLOTS:


 void accept();
 void cancel();


};

//_QSNS(ScignStage)


#endif  // TILE_SERVER_SELECT_DIALOG__H

