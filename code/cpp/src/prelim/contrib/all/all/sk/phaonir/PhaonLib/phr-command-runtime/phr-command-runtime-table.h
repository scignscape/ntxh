
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHR_COMMAND_RUNTIME_TABLE__H
#define PHR_COMMAND_RUNTIME_TABLE__H

#include <QtGlobal>


#include <functional>

#include <QMetaProperty>
#include <QVector>

#include <QSet>

#include "kans.h"
#include "accessors.h"

#include "phaon-ir/table/phr-symbol-scope.h"
#include "phaon-ir/channel/phr-channel-group.h"
#include "phaon-ir/table/phr-function-package.h"
#include "phaon-ir/types/phr-universal-class.h"

KANS_(Phaon)

class PHR_Type_System;

class PHR_Command_Runtime_Table : public PHR_Symbol_Scope
{
 QMap<PHR_Channel_Group, PHR_Channel_Group*> group_pointers_;
 PHR_Channel_Group* find_channel_group(const PHR_Channel_Group& channels);

 QMultiMap<QString, QPair<PHR_Channel_Group*, s1_fng_type>> s1_declared_functions_generic_;

 QMultiMap<QString, QString> declared_types_;

 PHR_Type_System& type_system_;

public:

 PHR_Command_Runtime_Table(PHR_Type_System& type_system);

 ACCESSORS__GET(PHR_Type_System& ,type_system)

 PHR_Function_Vector* get_phr_function_vector(QString fn);

 void add_declared_function_package(QString name, PHR_Function phf);

 PHR_Channel_Group* add_s1_declared_function(QString name, const PHR_Channel_Group& channels);

 inline static void strip_hyphens(QString& s)
 {
  s.replace('-', '_');
 }

 template<typename FN_type>
 void add_s1_declared_function(QString name, PHR_Channel_Group* kcg, FN_type fn)
 {
  strip_hyphens(name);
  s1_declared_functions_generic_.insert(name, {kcg, (s1_fng_type)fn});
 }

 s1_fng_type find_s1_declared_function_0(QString name,
   PHR_Channel_Group* kcg, const PHR_Type_Object** pkto);

 template<typename FN_Type>
 void init_phaon_function(const PHR_Channel_Group& g,
    QString name, int head_code, FN_Type pfn)
 {
  PHR_Channel_Group* kcg = find_channel_group(g);

  caon_ptr<PHR_Function_Package> kfp = new PHR_Function_Package(kcg);
  kfp->init_byte_code(head_code);

  PHR_Function phf(pfn);

  phf.augment(kfp);

  add_declared_function_package(name, phf);
 }
};

_KANS(Phaon)

#endif //PHR_COMMAND_RUNTIME_TABLE__H
