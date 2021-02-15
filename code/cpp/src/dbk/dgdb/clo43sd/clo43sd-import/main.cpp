
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>


#include <QCoreApplication>

#include <QFileInfo>
#include <QDir>


#include "clo43sd-data/clo-file.h"
#include "clo43sd-data/clo-species.h"
#include "clo43sd-data/clo-database.h"

#include "dgdb-white/dw-instance.h"
#include "dgdb-white/dw-record.h"

#include "dgdb-white/dw-stage-value.h"
#include "dgdb-white/stage/dw-stage-queue.h"

#include "dgdb-white/dw-frame.h"
#include "dgdb-white/dw-dominion.h"


#include "dgdb-white/wdb-manager.h"
#include "dgdb-white/dw-manager.h"

#include "dgdb-white/dgenvironment.h"

#include "dgdb-white/wdb-instance.h"
#include "dgdb-white/types/dw-type-system.h"
#include "dgdb-white/types/dw-type.h"

#include "withs.h"

#include "global-types.h"

extern "C" {
#include "whitedb/_whitedb.h"
}

//
#include "ntxh-parser/ntxh-document.h"

#include "kans.h"

/*
void create(WCM_Database& wcmd)
{
 wcmd.create_new_column("@Info");
 wcmd.create_new_singleton_column("Default@Info");

 wcmd.create_new_column("@Species");
 wcmd.create_new_column("Default@Species");
 wcmd.create_new_column("Species::Abbreviation");

 wcmd.create_new_column("@CLO_File");
 wcmd.create_new_column("Default@CLO_File");
 wcmd.create_new_column("Species::Abbreviation@CLO_File");

 wcmd.save();

}
*/

class CLO_Database;
class CLO_Species;

USING_KANS(DGDB)

int main(int argc, char *argv[])
{
 DW_Instance* dw = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/clo43sd/import");

 // // local_scratch_mode has no persistence at all.
  //   Scratch mode resents the database whenever it is 
  //   opened by DigammaDB, but keeps the database in memory 
  //   in between (so e.g. it can be examined via the wgdb utility). 
 //dw->Config.flags.local_scratch_mode = true;

 dw->Config.flags.scratch_mode = true;
 dw->Config.flags.avoid_record_pointers = true;

 DW_Manager& dwm = *dw->new_manager(); 

 DW_Record tagged;

 dwm.with_check_create() << [dw, &tagged]()
 {
  tagged = dw->new_tag_record("Default@Info");
 };

 if(tagged.id() == 0)
   tagged = dw->find_tag_record("Default@Info");

 // // write species to database
 {
  NTXH_Document doc(DEFAULT_NTXH_FOLDER "/clo43sd/species.ntxh");
  doc.parse();
  CLO_Database cld; //(nullptr);
  cld.set_external_root_folder(CLO43SD_ROOT_FOLDER);
  QVector<CLO_Species*>& species = cld.species_vec();
  QVector<NTXH_Graph::hypernode_type*>& hns = doc.top_level_hypernodes();

//  QMap<u4, QString> icm;
//  icm[0] = "Species::Abbreviation";

  for(NTXH_Graph::hypernode_type* hn : hns)
  {
   doc.graph()->get_sfsr(hn, {{1,3}}, [&species]
     (QVector<QPair<QString, void*>>& prs)
   {
    CLO_Species* s = new CLO_Species;
    s->set_abbreviation(prs[0].first);
    s->set_instances(prs[1].first.toUInt());
    s->set_name(prs[2].first);
    species.push_back(s);
   });
  }

  cld.check_species_folders();
  for(CLO_Species* s : species)
  {
   dw->with_new_free_form_record(3) << [s](DW_Instance& dwi,
     DW_Instance::Free_Form_Value** vals)
   {
    void* white = dwi.wdb_instance()->white();
    vals[1]->wg_encoded = wg_encode_str(white, (char*) s->abbreviation().toStdString().c_str(), nullptr);
    vals[2]->qvariant = s->instances();
    vals[3]->qvariant = s->name();
   };
  }

  auto process_files = [dw](QFileInfo& qfi, CLO_File::Kinds k)
  {
   QString bn = qfi.baseName();
   CLO_File species_file(k);
   species_file.set_abbreviation(bn.left(4));
   bn.remove(0, 4);
   species_file.set_tail(bn);

   dw->with_new_free_form_record(3) << [&species_file](DW_Instance& dwi,
     DW_Instance::Free_Form_Value** vals)
   {
    void* white = dwi.wdb_instance()->white();
    vals[1]->qvariant = (u1) species_file.kind();
    vals[2]->wg_encoded = wg_encode_str(white, (char*)
      species_file.abbreviation().toStdString().c_str(), nullptr);
    vals[3]->qvariant = species_file.tail();
   };
  };

  with_files(QDir(CLO43SD_ROOT_FOLDER "/logmelspec")).filter({"*.npy"}) <<
    [process_files](QFileInfo& qfi)
  {
   process_files(qfi, CLO_File::Kinds::NPY_Logmelspec);
  };

  with_files(QDir(CLO43SD_ROOT_FOLDER "/mfcc")).filter({"*.npy"}) <<
    [process_files](QFileInfo& qfi)
  {
   process_files(qfi, CLO_File::Kinds::NPY_MFCC);
  };

  dw->update_tagged_record(tagged, QVariant(species.size()));
 }


 return 0;

}


#ifdef HIDE
 wcmd.with_check_create() << [&wcmd]()
 {
  wcmd.create_new_column("@Info");
  wcmd.create_new_singleton_column("Default@Info");

  wcmd.create_new_column("@Species");
  wcmd.create_new_column("Default@Species");
  wcmd.create_new_column("Species::Abbreviation");

  wcmd.create_new_column("@CLO_File");
  wcmd.create_new_column("Default@CLO_File");
  wcmd.create_new_column("Species::Abbreviation@CLO_File");

  wcmd.save();
 };

 wcmd.set_creation_datetime();

 // // init info hypernode
 {
  WCM_Hypernode whn;

  wcmd.with_new_hyponode_array(2) << [&wcmd, &whn](WCM_Hyponode** whos)
  {
   whos[0]->set_qt_encoding(wcmd.datetimes_qvariantmap());
   whos[1]->set_qt_encoding(CLO43SD_ROOT_FOLDER ""_q);
   whn.add_hyponodes(whos)[2];
   whn.add_to_database(wcmd, "@Info", "Default@Info");
  };
 }

 // // write species to database
 {
  NTXH_Document doc(DEFAULT_NTXH_FOLDER "/clo43sd/species.ntxh");
  doc.parse();
  CLO_Database cld(nullptr);
  cld.set_external_root_folder(CLO43SD_ROOT_FOLDER);
  QVector<CLO_Species*>& species = cld.species_vec();
  QVector<NTXH_Graph::hypernode_type*>& hns = doc.top_level_hypernodes();
  QMap<u4, QString> icm;
  icm[0] = "Species::Abbreviation";
  for(NTXH_Graph::hypernode_type* hn : hns)
  {
   doc.graph()->get_sfsr(hn, {{1,3}}, [&species]
     (QVector<QPair<QString, void*>>& prs)
   {
    CLO_Species* s = new CLO_Species;
    s->set_abbreviation(prs[0].first);
    s->set_instances(prs[1].first.toUInt());
    s->set_name(prs[2].first);
    species.push_back(s);
   });
  }
  cld.check_species_folders();
  for(CLO_Species* s : species)
  {
   WCM_Hypernode whn;
   wcmd.with_new_hyponode_array(3) << [&wcmd, &whn, &icm, s](WCM_Hyponode** whos)
   {
    whos[0]->set_wgdb_encoding({wcmd.wdb().encode_string(s->abbreviation())});
    whos[1]->set_qt_encoding(s->instances());
    whos[2]->set_qt_encoding(s->name());
    whn.add_hyponodes(whos)[3];
    whn.set_indexed_column_map(&icm);
    whn.add_to_database(wcmd, "@Species", "Default@Species");
   };
   wcmd.save();
  }
 }

 // // write all files' paths to database
 {
  QMap<u4, QString> ficm;
  ficm[1] = "Species::Abbreviation@CLO_File";

  //
  auto process_files = [&wcmd, &ficm](QFileInfo& qfi, CLO_File::Kinds k)
  {
   QString bn = qfi.baseName();
   CLO_File species_file(k);
   species_file.set_abbreviation(bn.left(4));
   bn.remove(0, 4);
   species_file.set_tail(bn);
   wcmd.with_new_hyponode_array(3) << [&species_file, &wcmd, &ficm]
     (WCM_WhiteDB& wdb, WCM_Hyponode** whos)
   {
    WCM_Hypernode whn;
    whos[0]->set_qt_encoding((u1)species_file.kind());
    whos[1]->set_wgdb_encoding({wdb.encode_string(species_file.abbreviation())});
    whos[2]->set_qt_encoding(species_file.tail());
    whn.add_hyponodes(whos)[3];
    whn.set_indexed_column_map(&ficm);
    whn.add_to_database(wcmd, "@CLO_File", "Default@CLO_File");
   };
  };

  with_files(QDir(CLO43SD_ROOT_FOLDER "/logmelspec")).filter({"*.npy"}) <<
    [process_files](QFileInfo& qfi)
  {
   process_files(qfi, CLO_File::Kinds::NPY_Logmelspec);
  };

  with_files(QDir(CLO43SD_ROOT_FOLDER "/mfcc")).filter({"*.npy"}) <<
    [process_files](QFileInfo& qfi)
  {
   process_files(qfi, CLO_File::Kinds::NPY_MFCC);
  };
 }

 return 0;
}

#endif //def HIDE

