
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "chasm-runtime-bridge.h"

#include "chasm/chasm-runtime.h"

#include <QString>
#include <QVariant>
#include <QByteArray>

#include <QUrl>

#include <QPoint>

Chasm_Runtime_Bridge::Chasm_Runtime_Bridge(Chasm_Runtime* csr)
  :  csr_(csr)
{

}
