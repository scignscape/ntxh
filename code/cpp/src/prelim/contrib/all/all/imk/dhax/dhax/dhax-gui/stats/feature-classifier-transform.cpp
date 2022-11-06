
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "feature-classifier-transform.h"


#include "ntxh-parser/ntxh-document.h"

#include "read-kv-text.h"


#include <QFileInfo>


Feature_Classifier_Transform::Feature_Classifier_Transform()
  :  rotation_(0),
     horizontal_skew_(0),
     horizontal_shear_(0),
     horizontal_shear_centered_(0),
     vertical_skew_(0),
     vertical_shear_(0),
     vertical_shear_centered_(0),
     box_sizes_({0,0})
{

}

void Feature_Classifier_Transform::init_from_kv_text(QString kv_text)
{
 QMap<QString, QStringList> kv_tokens;

 read_kv_text(kv_text, kv_tokens);

 horizontal_skew_ = kv_tokens.value("hskew").value(0).toDouble();
 horizontal_shear_ = kv_tokens.value("hshear").value(0).toDouble();
 horizontal_shear_centered_ = kv_tokens.value("hshearc").value(0).toDouble();

 vertical_skew_ = kv_tokens.value("vskew").value(0).toDouble();
 vertical_shear_ = kv_tokens.value("vshear").value(0).toDouble();
 vertical_shear_centered_ = kv_tokens.value("vshearc").value(0).toDouble();

 //box_size_
}


void Feature_Classifier_Transform::init_from_ntxh(QString ntxh_file)
{
 NTXH_Document doc(ntxh_file);

 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 NTXH_Graph& g = *doc.graph();
 const QVector<hypernode_type*>& v = g.hypernodes();

 for(hypernode_type* h : v)
 {
  QString ty = h->type_descriptor().first;
  if(ty == "Feature_Classifier_Transforms")
  {
   g.get_sfsr(h, {{1, 7}}, [this](QVector<QPair<QString, void*>>& prs)
   {
    rotation_ = prs[0].first.toDouble();
    QString skew_shear = prs[1].first;
    if(!skew_shear.isEmpty())
      init_from_kv_text(skew_shear);
    foreground_color_ = QColor(prs[2].first.toInt(), prs[3].first.toInt(), prs[4].first.toInt());
    box_sizes_.width = prs[5].first.toInt();
    if(prs[6].first.isEmpty())
      box_sizes_.height = box_sizes_.width;
    else
      box_sizes_.height = prs[5].first.toInt();
   });
  }
 }

}





