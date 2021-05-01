
#ifndef CONTEXT_MENU_PROVIDER__H
#define CONTEXT_MENU_PROVIDER__H


#include <QVector>
#include <QMap>
#include <QString>

#include "accessors.h"

class Context_Menu_Provider
{
 QVector<QMap<QString, QString>> url_patterns_;


public:

 Context_Menu_Provider();

 ACCESSORS__RGET(MACRO_PASTE(QVector<QMap<QString, QString>>) ,url_patterns)

};


#endif
