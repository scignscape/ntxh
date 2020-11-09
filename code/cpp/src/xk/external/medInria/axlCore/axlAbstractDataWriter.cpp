/* axlAbstractDataWriter.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008-2011 - Meriadeg Perrinel, Inria.
 * Created: Wed Sep 21 10:38:57 2011 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 10:53:56 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 6
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractDataWriter.h"

#include <axlCore/axlMesh.h>
#include <dtkCoreSupport/dtkAbstractData.h>

#include <QtGui>

axlAbstractDataWriter::axlAbstractDataWriter(void) : dtkAbstractDataWriter()
{

}

axlAbstractDataWriter::~axlAbstractDataWriter(void)
{

}

void axlAbstractDataWriter::setName  (QDomElement& e, axlAbstractData *data)
{
  if (data->name().length()>0)
    e.setAttribute("name", data->name());
}

void axlAbstractDataWriter::setSize  (QDomElement& e, axlAbstractData *data)
{
  if (data->size()>0)
    e.setAttribute("size", QString::number(data->size()));
}

void axlAbstractDataWriter::setColor (QDomElement& e, axlAbstractData *data)
{
  QColor qcolor = data->color();
  QString color ;
  QTextStream(&color) << QString::number(qcolor.red())   << " "
		      << QString::number(qcolor.green()) << " "
                      << QString::number(qcolor.blue())  << " "
                      << QString::number(data->opacity());
  e.setAttribute("color", color);
}

void axlAbstractDataWriter::setShader (QDomElement& e, axlAbstractData *data)
{
  QString shader = data->shader();
  if(shader.length()>0) {
    QFileInfo shaderFileInfo(shader);
    e.setAttribute("shader", shaderFileInfo.fileName());
  }
}
