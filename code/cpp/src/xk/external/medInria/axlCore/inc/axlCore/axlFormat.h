/********************************************************************************
 * axlFormat.h ---
 *********************************************************************************
 * Author: Bernard Mourrain
 * Copyright (C) 2008 - Bernard Mourrain, Inria.
 * Created: Wed Mar 16 12:46:01 2011 (+0100)
 *
 * Comments:
 *
 *
 * Change log:
 *
 *********************************************************************************/
#ifndef AXLFORMAT_H
#define AXLFORMAT_H

#include <QtCore>
#include <QtXml>

inline bool hasChildNode(QDomElement element, const QString& tag)
{
  for(int i = 0; i < element.childNodes().count(); i++)
    if(element.childNodes().at(i).toElement().tagName() == tag)
      return true; 
  return false;
}

#endif //AXLFORMAT_H
