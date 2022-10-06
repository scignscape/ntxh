
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-ssr-integration-controller.h"

#include "application/dhax-application-controller.h"

#include "dhax-ssr-integration-data.h"

#include <QDebug>


DHAX_SSR_Integration_Controller::DHAX_SSR_Integration_Controller()
  :  integration_data_(nullptr), application_controller_(nullptr)
{

}

void DHAX_SSR_Integration_Controller::read_datagram(QString text)
{
 QStringList qsl = text.split('*');
 integration_data_->ssr_file_path_ = qsl.takeFirst();

 if(!qsl.isEmpty())
 {
  QStringList qsl1 =  qsl.takeFirst().split(';');
  integration_data_->ssr_position_data_.resize(qsl1.size());
  std::transform(qsl1.begin(), qsl1.end(), integration_data_->ssr_position_data_.begin(),
    [](QString qs) { return qs.toDouble(); });
 }

 ++*integration_data_->ssr_import_count_;
 application_controller_->load_image(integration_data_->ssr_file_path_);

}
