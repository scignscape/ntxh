
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "hgdm-angel-runtime-context.h"

#include "mpf-package-hgdm.h"

#include "hQVariant.h"

#include <QDebug>


HGDM_Angel_Runtime_Context::HGDM_Angel_Runtime_Context()
  :  ref_count_(0)
{
}


HGDM_Angel_Runtime_Context* HGDM_Angel_Runtime_Context::selto_ss(const std::string& ss)
{
 pkg_->selto(QString::fromStdString(ss));
 return this;
 //qDebug() << "init 1";
}

hQVariant* HGDM_Angel_Runtime_Context::read_hqv()
{
 hQVariant* result = new hQVariant(pkg_->read());
 return result;
}

HGDM_Angel_Runtime_Context* HGDM_Angel_Runtime_Context::pval()
{
 pkg_->pval();
 return this;
}



HGDM_Angel_Runtime_Context* HGDM_Angel_Runtime_Context::init2()
{
 qDebug() << "init 2";
 return this;
}

HGDM_Angel_Runtime_Context* HGDM_Angel_Runtime_Context::init3()
{
 qDebug() << "init 3";
 return this;
}


void HGDM_Angel_Runtime_Context::add_ref()
{
 // Increase the reference counter
 ++ref_count_;
}
 
void HGDM_Angel_Runtime_Context::release()
{
 // Decrease ref count and delete if it reaches 0
 if( --ref_count_ == 0 )
   delete this;
}


