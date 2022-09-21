
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dataset-info.h"

#include "dataset.h"


#include "language-sample.h"
#include "language-sample-group.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"

#include <QDataStream>


USING_KANS(DSM)


Dataset_Info::Dataset_Info(Dataset* ds)
  :  ds_(ds)
{
 number_of_samples_ = ds->samples()->size();
 number_of_groups_ = ds->groups()->size();
}

Dataset_Info::Dataset_Info()
  :  ds_(nullptr), number_of_samples_(0), number_of_groups_(0)
{

}


void Dataset_Info::supply_pack(Qh_Pack_Builder& qpb)
{
 // // need node data for the string ...
 qpb.init_node_data();

 QByteArray qba; supply_opaque(qba);

 qpb.add_sv(ds_->samples_file())
   .add_sv(ds_->pdf_file())
   .add_sv(number_of_samples_)
   .add_sv(number_of_groups_)
   .add_sv(qba);
}

void Dataset_Info::absorb_pack(Qh_Pack_Builder& qpb)
{
 if(!ds_)
   ds_ = new Dataset;

 Qh_Pack_Reader qpr(qpb.pack_code(), qpb.data(), qpb.node_data());

 ds_->set_samples_file( qpr.read_value().toString() );
 ds_->set_pdf_file( qpr.read_value().toString() );
 number_of_samples_ = qpr.read_value().toUInt();
 number_of_groups_ = qpr.read_value().toUInt();
 QByteArray qba = qpr.read_value().toByteArray();
 absorb_opaque(qba);

 //ds_->set_samples_file(samples_fi)

}

void Dataset_Info::supply_opaque(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << ds_->merge_file() << ds_->ppc_file()
   << ds_->issues() << ds_->forms() << ds_->issue_codes();
}

void Dataset_Info::absorb_opaque(const QByteArray& qba)
{
 QDataStream qds(qba);
 QString merge_file_;
 QString ppc_file_;

 qds >> merge_file_ >> ppc_file_ >> ds_->issues()
   >> ds_->forms() >> ds_->issue_codes();

 ds_->set_merge_file(merge_file_);
 ds_->set_ppc_file(ppc_file_);
}

