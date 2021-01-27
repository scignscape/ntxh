
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "language-sample.h"

//? #include "ngml-sdi/ngml-sdi-sentence.h"

#include "qh-package/qh-pack-builder.h"
#include "qh-package/qh-pack-reader.h"


#include <QRegularExpression>
#include <QDataStream>


USING_KANS(DSM)


Language_Sample::Language_Sample(u2 id)
  :  id_(id)
{

}


void Language_Sample::check_alternate_text(QString text)
{
 if(text == "(!)")
 {
  QString txt = text_;
  txt.replace(QRegularExpression(QStringLiteral("\\(.*\\)")),{});
  text = txt.simplified();
 }

 alternate_text_ = text;
}


QString Language_Sample::archival_or_text()
{
 return alternate_text_.isEmpty()? text_ : alternate_text_;
}

void Language_Sample::parse_classification(QString text)
{
 s4 index = text.indexOf(';');
 if(index == -1)
   set_issue(text);
 else
 {
  QString q1 = text.mid(0, index);
  QString q2 = text.mid(index + 1);
  set_issue(q1);
  set_example_form(q2);
 }
}


void Language_Sample::supply_pack(Qh_Pack_Builder& qpb)
{
 // // need node data for the string ...
 qpb.init_node_data();

 QByteArray qba; supply_opaque(qba);

 qpb.add_sv(text_)
   .add_sv(latex_label_)
   .add_sv(issue_)
   .add_sv(page_)
   .add_sv(qba);
}

void Language_Sample::absorb_pack(Qh_Pack_Builder& qpb)
{
 Qh_Pack_Reader qpr(qpb.pack_code(), qpb.data(), qpb.node_data());

 text_ = qpr.read_value().toString();
 latex_label_ = qpr.read_value().toString();
 issue_ = qpr.read_value().toString();
 page_ = qpr.read_value().toUInt();
 QByteArray qba = qpr.read_value().toByteArray();
 absorb_opaque(qba);

}

void Language_Sample::supply_opaque(QByteArray& qba)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << example_form_ << external_label_ << external_source_
   << pre_ << post_ << page_string_;
}

void Language_Sample::absorb_opaque(const QByteArray& qba)
{
 QDataStream qds(qba);
 qds >> example_form_ >> external_label_ >> external_source_
   >> pre_ >> post_ >> page_string_;
}




