
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef MOSAIC_MENUBAR__H
#define MOSAIC_MENUBAR__H

#include <QMenuBar>

class QAction;
class QWidgetAction;
class QMainWindow;

class Mosaic_Menubar : public QMenuBar
{
public:

 Mosaic_Menubar(QMainWindow* qmw = nullptr);
 void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
 
 static void add_action_data(QAction* qa, QString key, void* value);
 static void* get_action_data(QAction* qa, QString key);

 QWidgetAction* add_text_separator(QString text = QString(), QWidget* parent = nullptr);
 QWidgetAction* add_text_separator_before(QAction* after, QString text = QString(), QWidget* parent = nullptr);
 QWidgetAction* add_text_separator_before(QMenu* after, QString text = QString(), QWidget* parent = nullptr);
 QPair<QWidgetAction*,QWidgetAction*> add_text_separator_around(QAction* before, QAction* after, QStringList text = {}, QWidget* parent = nullptr);
 QPair<QWidgetAction*,QWidgetAction*> add_text_separator_around(QMenu* before, QMenu* after, QStringList text = {}, QWidget* parent = nullptr);

 void use_default_stylesheet(QString name);
 void add_to_style_sheet(QString sheet);

 static void handle_screenshot(QString path, int target_window_id);
 static void handle_screenshot(int target_window_id);
};


#endif // MOSAIC_MENUBAR__H
