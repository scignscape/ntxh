
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef QMT_CLIENT_LAYER__H
#define QMT_CLIENT_LAYER__H

//#include "qmt-accessors.h"

#include "global-types.h"

#include <QString>
#include <QList>

#include <QPoint>

#include <QMap>

#include <functional>

#include <QVariant>

//class QMT_Server_Response;

#include "qmt/qmt-client-layer-base.h"


class QMT_Client_Layer : public QMT_Client_Layer_Base
{
public:

 void add_d0_mark(r8 latitude, r8 longitude, QStringList text = {}) Q_DECL_OVERRIDE;
 void add_d0_mark(QList<r8> coords, QStringList text = {}) Q_DECL_OVERRIDE;
 void add_d0_marks(const QVector<QPair<QList<r8>, QStringList>>& coords_and_texts) Q_DECL_OVERRIDE;

 QMT_Client_Layer();

};



#endif // QMT_GIS_UTILS__H
