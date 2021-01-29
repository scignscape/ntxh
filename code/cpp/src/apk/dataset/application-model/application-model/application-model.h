
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef APPLICATION_MODEL__H
#define APPLICATION_MODEL__H

#include <QObject>

#include <QMap>



class QDialog;

class ScignStage_Ling_Dialog;

class Application_Model : public QObject
{
 Q_OBJECT

 QMap<QString, QDialog*> graphics_;

 ScignStage_Ling_Dialog* ling_dialog_;

 QString root_folder_;

public:


 Q_INVOKABLE void launch_lexpair_dialog(ScignStage_Ling_Dialog* dlg, QString s);
 Q_INVOKABLE void expand_sample(ScignStage_Ling_Dialog* dlg, int index);
 Q_INVOKABLE void launch_xpdf(ScignStage_Ling_Dialog* dlg, QString f, int page);


 Application_Model(ScignStage_Ling_Dialog* ling_dialog, QString root_folder);
 ~Application_Model();

};

#endif  // APPLICATION_MODEL__H
