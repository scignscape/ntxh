
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef QVECTOR_MATRIX_R8__H
#define QVECTOR_MATRIX_R8__H

#include <QtGlobal>
#include <QVector>
#include <QByteArray>
 
#include "accessors.h"

#include "global-types.h"


class QVector_Matrix_R8
{
 u4 n_rows_;
 u4 n_cols_;

 QVector<r8>* elems_;

 struct _one_opbracket
 {
  QVector_Matrix_R8& _this;
  u4 row;
  r8& operator[](u4 c);
  r8 operator()(u4 c);
  r8 operator()(u4 c, r8 defaultv);
 };

 enum class special_mode {
  Sym, Skew, Diag
 };

 enum class special_mode_x {
  N_A, Sym, Skew, Diag, ED, Sym_ED, Skew_ED, Diag_ED, 
 };

 enum class special_mode_for_raw_data {
  Normal, ED, CM, ED_CM 
 };

 struct _from_raw_data_special 
 {
  QVector_Matrix_R8& _this;
  special_mode_for_raw_data mfrd;

  _from_raw_data_special cmajor()
  {
   return ( (mfrd == special_mode_for_raw_data::ED)
       || (mfrd == special_mode_for_raw_data::ED_CM) )
     ? _from_raw_data_special{_this, special_mode_for_raw_data::ED_CM} 
     : _from_raw_data_special{_this, special_mode_for_raw_data::CM}; 
  }

  void cmajor(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void _diagonal(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void _symmetric(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void _skew_symmetric(const QByteArray& qba, 
    QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);

  void diagonal(const QByteArray& qba, QVector<u4> dims = {0, 0}, r8 defaultv = 0)
  {
   _diagonal(qba, {dims.value(0), dims.value(1, dims.value(0))}, defaultv); 
  }

  void symmetric(const QByteArray& qba, QVector<u4> dims = {0, 0}, r8 defaultv = 0)
  {
   _symmetric(qba, {dims.value(0), dims.value(1, dims.value(0))}, defaultv); 
  }

  void skew_symmetric(const QByteArray& qba, 
    QVector<u4> dims = {0, 0}, r8 defaultv = 0)
  {
   _skew_symmetric(qba, {dims.value(0), dims.value(1, dims.value(0))}, defaultv); 
  }

 };

 template<special_mode>
 const r8& _at(u4 r, u4 c);

 template<special_mode>
 r8* _get(u4 r, u4 c);

 template<special_mode>
 r8* _fetch(u4 r, u4 c);

 template<special_mode>
 r8 _value(u4 r, u4 c);

 template<special_mode>
 r8 _value(u4 r, u4 c, r8 defaultv);

 template<special_mode>
 u4 _total_size();

 template<special_mode>
 u4 _get_index(u4 r, u4 c);

 u4 _get_normal_index(u4 r, u4 c);

 u4 get_sym_index(u4 r, u4 c);

 void default_init(u4 len);

 static r8* _defaultv();

 void _to_raw_data(QByteArray& qba, u4 offset, u4 count);

 void _from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv,
   u4 total_size = 0);

 void _from_raw_data_with_encoded_default(const QByteArray& qba, 
   QPair<u4, u4> dims, u4 total_size = 0);

 void _from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, 
   r8 defaultv, special_mode_x smx);

public:

 QVector_Matrix_R8(u4 r = 0, u4 c = 0, r8 defaultv = 0);

 ACCESSORS__DECLARE(u4 ,n_rows)
 ACCESSORS__DECLARE(u4 ,n_cols)

 QVector_Matrix_R8* new_from_dimensions();

 QVector_Matrix_R8* percentile_breakdown(u4 max = 100);
 QVector_Matrix_R8* percentile_rescale(u4 max = 100);

 void fill(r8 value, r8 default_value);
 void fill(r8 value = 0)
 {
  fill(value, value);
 }

 void get_row(u4 r, QVector<r8>& row);

 template<typename T>
 void _show(T& tt, u1 digits = 8)
 {
  for(u4 r = 1; r <= n_rows(); ++r) 
  {
   for(u4 c = 1; c <= n_cols(); ++c) 
   {
    tt << QString("%1").arg(value(r, c), -digits);
   }
   tt << '\n'; 
  }
 }

 template<typename T>
 void show(T& tt, u1 digits = 8)
 {
  _show(tt, digits); 
 }

 template<typename T>
 void show(T tt, u1 digits = 8)
 {
  _show(tt, digits); 
 }

 r8 get_minimum_in_column(u4 c);
 r8 get_maximum_in_column(u4 c);

 void get_extrema(QPair<r8, r8>& result);

 void get_column_extrema(QVector<QPair<r8, r8>>& result);
 void get_row_extrema(QVector<QPair<r8, r8>>& result);
 void get_column_maxima(QVector<r8>& result);
 void get_row_maxima(QVector<r8>& result);
 void get_column_minima(QVector<r8>& result);
 void get_row_minima(QVector<r8>& result);

 QPair<r8, r8> get_extrema_in_column(u4 c)
 {
  return {get_minimum_in_column(c), get_maximum_in_column(c)};
 }

 QPair<r8, r8> get_extrema_in_row(u4 r)
 {
  return {get_minimum_in_row(r), get_maximum_in_row(r)};
 }

 r8 get_minimum_in_row(u4 r);
 r8 get_maximum_in_row(u4 r);

 void symmetric(u4 n_rows);
 void skew_symmetric(u4 n_rows);
 void diagonal(u4 n_rows);
 void diagonal(u4 n_rows, u4 n_cols);
 void diagonal();
 void rmajor();
 void cmajor();

 void save_to_file(QString path);
 void load_from_file(QString path);

 void save_to_datastream(QDataStream& qds);
 void load_from_datastream(QDataStream& qds);



 u4 covers(u4 r, u4 c);
 u4 get_index(u4 r, u4 c);

 u4 operator %(QPair<u4, u4> pos)
 {
  return covers(pos.first, pos.second);
 }

 bool is_diagonal()
 {
  return (n_cols_ & 1) && (n_cols_ > 1); 
 }

 bool is_cmajor()
 {
  return (n_rows_ & 1) && !is_diagonal();
 }

 bool is_cmajor_not_symmetric()
 {
  return (n_rows_ & 1) && 
    ( ((n_cols_ & 1) == 0) && (n_cols_ > 1) );
 }

 bool is_rmajor()
 {
  return (n_rows_ & 1) == 0;
 }

 u4 get_diagonal_length()
 {
  if(n_rows_ & 1)
    return n_cols();
  return n_rows();
 }


 bool is_symmetric()
 {
  return n_cols_ == 0; 
 }

 bool is_skew_symmetric()
 {
  return n_cols_ == 1; 
 }

 bool is_symmetric_or_skew_symmetric()
 {
  return (n_cols_ == 1) || (n_cols_ == 0); 
 }

 static constexpr u4 value_byte_size() { return 8; }

 _one_opbracket operator[](u4 r);

 void to_raw_data(QByteArray& qba);
 void to_raw_data_with_encoded_default(QByteArray& qba);

 void from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv = 0);
 void from_raw_data(const QByteArray& qba, r8 defaultv = 0);
 void from_raw_data_with_encoded_default(const QByteArray& qba);
 void from_raw_data_with_encoded_default(const QByteArray& qba, QPair<u4, u4> dims);

 void fill_diagonal(r8 val = 1);

 _from_raw_data_special from_raw_data()
 {
  return {*this, special_mode_for_raw_data::Normal};
 }

 void multiply(const QVector<r8>& vec, QVector<r8>& result);
 void merge_row(const QVector<r8>& vec, u4 row);

 void patterned_fill_row(u4 row)
 {
  QVector<r8> vec = QVector<r8>(n_cols());
  u4 uu = 1;
  for(r8& rr: vec)
  {
   rr = (10 * row) + uu;
   ++uu;
  }
  merge_row(vec, row);
 }

 void patterned_fill()
 {
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   patterned_fill_row(r);
  }
 }

 const r8& at(u4 r, u4 c);
 r8* get(u4 r, u4 c);
 r8* fetch(u4 r, u4 c);
 r8 value(u4 r, u4 c);
 r8 value(u4 r, u4 c, r8 defaultv);

 r8 get_value(u4 r, u4 c);
 r8 get_at(u4 r, u4 c);

 r8 get_at_index(u4 pos);

 u4 total_size();

 void resize(u4 r, u4 c);
 void resize(u4 total);
 void resize()
 {
  resize(n_rows_, n_cols_);
 }

};



//  data=double matrix

// n_cols
// n_elem
// n_rows

// vec_state
// mem_state
// mem_local


#endif // QVECTOR_MATRIX_R8__H

