
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


//?#include "whitedb/_whitedb.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "whitedb/_whitedb.h"
#ifdef __cplusplus
}
#endif



#include <QByteArray>
#include <QDataStream>
#include <QDebug>



//void* wg_attach_database(char* dbasename, gint size){
//  void* shm = wg_attach_memsegment(dbasename, size, size, 1, 0, 0);
//  CHECK_SEGMENT(shm)
//  return shm;
//}


//int main(int argc, char *argv[])
//{
// wg_delete_database("100");

//}

int main2(int argc, char *argv[])
{
  void* db = wg_attach_database("100", 0);

 // void* rec = wg_create_record(db, 10);
  void* rec1 = wg_create_record(db, 3);

 // wg_int enc = wg_encode_int(db, 443);
  wg_int enc1 = wg_encode_str(db, "this is my string", NULL);

 // wg_set_field(db, rec, 7, enc);
  int index = 1;
  int column_code = 1;

  wg_set_field(db, rec1, 0, wg_encode_int(db, column_code));
  wg_set_field(db, rec1, 1, wg_encode_int(db, index));

  wg_set_field(db, rec1, 2, enc1);

  QString str = "ok ...";

  QByteArray qba;

  QDataStream qds(&qba, QIODevice::WriteOnly);

  qds << str;

  qds << index;

  quintptr rec = wg_encode_record(db, rec1);
  qds << rec;

  ++index;

  void* rec2 = wg_create_record(db, 3);
  wg_int enc2 = wg_encode_blob(db, qba.data(), NULL, qba.size());

  //wg_int enc = wg_encode_int(db, 443);

  wg_set_field(db, rec2, 0, wg_encode_int(db, index) );

  wg_set_field(db, rec2, 1, enc2);

  wg_set_field(db, rec2, 2, wg_encode_record(db, rec1) );

  wg_create_index(db, 0, WG_INDEX_TYPE_TTREE, NULL, 0);
  wg_create_index(db, 1, WG_INDEX_TYPE_TTREE, NULL, 0);

  wg_int wgi = wg_get_field(db, rec2, 0);
  char* blob = wg_decode_blob(db, wgi);

  wg_int len = wg_decode_blob_len(db, wgi);

  QByteArray qba2(blob, len);
  QDataStream qds1(&qba2, QIODevice::ReadOnly);

  QString s1;

  qds1 >> s1;
  qDebug() << "STR: " << s1;

 return 0;
}


int main(int argc, char *argv[])
{
  void* db = wg_attach_database("300", 0);

 // void* rec = wg_create_record(db, 10);
  void* rec1 = wg_create_record(db, 3);

 // wg_int enc = wg_encode_int(db, 443);
  wg_int enc1 = wg_encode_str(db, "this is my string", NULL);

 // wg_set_field(db, rec, 7, enc);
  int index = 1;
  int column_code = 1;

  wg_set_field(db, rec1, 0, wg_encode_int(db, column_code));
  wg_set_field(db, rec1, 1, wg_encode_int(db, index));

  wg_set_field(db, rec1, 2, enc1);

  QString str = "ok ...";

  QByteArray qba;

  QDataStream qds(&qba, QIODevice::WriteOnly);

  qds << str;

  qds << index;

  quintptr rec = wg_encode_record(db, rec1);
  qds << rec;

  ++index;

  void* rec2 = wg_create_record(db, 3);
  wg_int enc2 = wg_encode_blob(db, qba.data(), NULL, qba.size());

  //wg_int enc = wg_encode_int(db, 443);

  wg_set_field(db, rec2, 0, wg_encode_int(db, index) );

  wg_set_field(db, rec2, 1, enc2);

  wg_set_field(db, rec2, 2, wg_encode_record(db, rec1) );

  wg_create_index(db, 0, WG_INDEX_TYPE_TTREE, NULL, 0);
  wg_create_index(db, 1, WG_INDEX_TYPE_TTREE, NULL, 0);

  wg_int wgi = wg_get_field(db, rec2, 0);
  char* blob = wg_decode_blob(db, wgi);

  wg_int len = wg_decode_blob_len(db, wgi);

  QByteArray qba2(blob, len);
  QDataStream qds1(&qba2, QIODevice::ReadOnly);

  QString s1;

  qds1 >> s1;
  qDebug() << "STR: " << s1;

 return 0;
}

