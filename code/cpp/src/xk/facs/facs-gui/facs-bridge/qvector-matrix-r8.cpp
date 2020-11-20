
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

 
#include "qvector-matrix-r8.h"

#include <cstring>

#include <QFile>
#include <QDataStream>
#include <QtGlobal>
#include <QDebug>

#include <limits>


QVector_Matrix_R8::QVector_Matrix_R8(u4 r, u4 c, r8 defaultv)
 : n_rows_(r << 1), n_cols_(c << 1), 
   elems_( (r && c)? new QVector<r8>((r * c) + 1) : nullptr) 
{
 if(elems_)
   (*elems_)[0] = defaultv;
}

void QVector_Matrix_R8::fill(r8 value, r8 default_value)
{
 if(elems_)
 {
  u4 s = elems_->size();
  elems_->resize(total_size() + 1);
  if(value != 0)
  {
   for(u4 i = s; i < elems_->size(); ++i)
   {
    (*elems_)[s] = value;
   }
  }
 }
 else
 {
  elems_ = new QVector<r8>(total_size() + 1, value);
  (*elems_)[0] = default_value;
 } 
}

void QVector_Matrix_R8::get_extrema(QPair<r8, r8>& result)
{
 QVector<QPair<r8, r8>> extrema;
 if(is_rmajor())
   get_row_extrema(extrema);
 else 
   get_column_extrema(extrema);
 
 result = std::accumulate(extrema.begin(), extrema.end(),
   QPair<r8, r8> {std::numeric_limits<r8>::max(), std::numeric_limits<r8>::min()},
   [](QPair<r8, r8> pr1, QPair<r8, r8> pr2) -> QPair<r8, r8>
 {
  return {qMin(pr1.first, pr2.first), qMax(pr2.second, pr2.second)};
 });
}


QVector_Matrix_R8* QVector_Matrix_R8::percentile_breakdown(u4 max)
{
 QPair<r8, r8> extrema;
 get_extrema(extrema);
 
 QVector_Matrix_R8* result = new QVector_Matrix_R8;
 result->set_n_rows(max + 1);
 result->set_n_cols(n_cols());
 result->fill();

  // // for each column, aggregate all entries into percentiles.
   //   Currently not optimized for data access at all ...
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   r8 rr = get_at(r, c);
   r8 _percentile = (rr - extrema.first) / (extrema.second - extrema.first);
   u4 percentile = (_percentile * max) + 1;
   ++(*result)[percentile][c];
  }
 }
 return result;
}

QVector_Matrix_R8* QVector_Matrix_R8::percentile_rescale(u4 max)
{
 QPair<r8, r8> extrema;
 get_extrema(extrema);
 
 QVector_Matrix_R8* result = new_from_dimensions();

  // // for each column, aggregate all entries into percentiles.
   //   Currently not optimized for data access at all ...
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   r8 rr = get_at(r, c);
   r8 _percentile = (rr - extrema.first) / (extrema.second - extrema.first);
   u4 percentile = (_percentile * max) + 1;
   (*result)[r][c] = percentile;
  }
 }
 return result;
}



void QVector_Matrix_R8::merge_row(const QVector<r8>& vec, u4 row)
{
 if(is_diagonal())
 {
  if(row <= n_cols())
    (*this)[row][row] = vec.value(row - 1);
  return;
 }
 if(is_symmetric() || is_skew_symmetric())
 {
  for(u4 c = 1; c <= n_cols(); ++c)
  {
   (*this)[row][c] = vec.value(c - 1);
  }
  return;
 }
 if(is_cmajor())
 {
  //?for(u4 c = 1; c <= n_cols(); ++c)
  for(u4 index = row, i = 0; i < n_cols(); ++i, index += n_rows()) 
  {
   //?u4 index = r + (c - 1) * n_rows();
   (*elems_)[index] = vec.value(i);
  }
  return;
 }

 u4 index = 1 + ((row - 1) * n_cols());
 
 std::copy(vec.begin(), vec.end(), elems_->begin() + index);

// for(u4 i = 0; i < n_cols(); ++i, ++index)
// {
//  (*elems_)[index] = vec[i];
// }
}

void QVector_Matrix_R8::get_column_extrema(QVector<QPair<r8, r8>>& result)
{
 result.resize(n_cols());
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  result[c - 1] = get_extrema_in_column(c);
 }
}

void QVector_Matrix_R8::get_row_extrema(QVector<QPair<r8, r8>>& result)
{
 result.resize(n_rows());
 for(u4 r = 1; r <= n_rows(); ++r)
 {
  result[r - 1] = get_extrema_in_row(r);
 }
}

void QVector_Matrix_R8::get_column_minima(QVector<r8>& result)
{
 result.resize(n_cols());
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  result[c - 1] = get_minimum_in_column(c);
 }
}

void QVector_Matrix_R8::get_row_minima(QVector<r8>& result)
{
 result.resize(n_rows());
 for(u4 r = 1; r <= n_rows(); ++r)
 {
  result[r - 1] = get_minimum_in_column(r);
 }
}

void QVector_Matrix_R8::get_column_maxima(QVector<r8>& result)
{
 result.resize(n_cols());
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  result[c - 1] = get_maximum_in_column(c);
 }
}

void QVector_Matrix_R8::get_row_maxima(QVector<r8>& result)
{
 result.resize(n_rows());
 for(u4 r = 1; r <= n_rows(); ++r)
 {
  result[r - 1] = get_maximum_in_column(r);
 }
}


void QVector_Matrix_R8::multiply(const QVector<r8>& vec, QVector<r8>& result)
{
 result.resize(vec.size());
 u4 r = 1;
 std::transform(vec.begin(), vec.end(), result.begin(), [&r, &vec, this](r8) -> r8
 {
  r8 result = 0;
  for(u4 c = 1; c <= (u4) vec.size(); ++c)
  {
   result += get_at(r, c);
  }
  ++r;
  return result;
 });
}


void QVector_Matrix_R8::retire()
{
 delete elems_;
 elems_ = nullptr;
}

void QVector_Matrix_R8::reset_no_retire(const QVector_Matrix_R8& rhs)
{
 n_rows_ = rhs.n_rows_;
 n_cols_ = rhs.n_cols_;
 elems_ = rhs.elems_;
}

void QVector_Matrix_R8::reset(const QVector_Matrix_R8& rhs)
{
 delete elems_;
 n_rows_ = rhs.n_rows_;
 n_cols_ = rhs.n_cols_;
 elems_ = rhs.elems_;
}



void QVector_Matrix_R8::fill_diagonal(r8 diag_value, r8 other_value, r8 default_value)
{
 fill(other_value, default_value);
 u4 qm = qMin(n_rows(), n_cols());
 for(u4 u = 1; u <= qm; ++u)
 {
  (*this)[u][u] = diag_value;
 }
}

void QVector_Matrix_R8::fill_diagonal_only(r8 val)
{
 u4 len = qMin(n_rows(), n_cols());
 u4 elen = 1 + (len * len);
 if(!elems_)
   elems_ = new QVector<r8>(elen);
 else if((u4) elems_->size() < elen)
   elems_->resize(elen);

 for(u4 i = 1; i <= len; ++i)
 {
  r8* rr = get(i, i);
  if(rr)
    *rr = val;
  else
    qDebug() << "Unexpected condition at " << __FILE__ << ", line " << __LINE__;  
 }
}

r8 QVector_Matrix_R8::get_minimum_in_column(u4 c)
{
 if(is_diagonal())
   return qMin(get_at(c, c), 0.);

 r8 result = 0;
 if(is_symmetric_or_skew_symmetric())
 {
  // just brute force ...
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   r8 rr = get_at(r, c);
   if(rr < result)
     result = rr;
  }
 }

 else if(is_cmajor())
 {
  u4 index = (n_rows() * (c - 1)) + 1;
  for(u4 i = 0; i < n_rows(); ++i, ++index)
  {
   r8 rr = get_at_index(index);
   if(rr < result)
     result = rr; 

   // just brute force ...
   //r8 rr = get_at(i + 1, c);
   //if(rr < result)
   //  result = rr;

  }  
 }

 else
 {
  u4 nc = n_cols();
  u4 nr = n_rows();
  u4 index = c;
  for(u4 r = 0; r < nr; ++r, index += nc)
  {
   r8 rr = get_at_index(index);
   if(rr < result)
     result = rr; 
  }  
 }
 return result;
}

r8 QVector_Matrix_R8::get_maximum_in_column(u4 c)
{
 if(is_diagonal())
   return qMax(get_at(c, c), 0.);

 r8 result = 0;
 if(is_symmetric_or_skew_symmetric())
 {
  // just brute force ...
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   r8 rr = get_at(r, c);
   if(rr > result)
     result = rr;
  }
 }

 else if(is_cmajor())
 {
  u4 index = (n_rows() * (c - 1)) + 1;
  for(u4 i = 0; i < n_rows(); ++i, ++index)
  {
   r8 rr = get_at_index(index);
   if(rr > result)
     result = rr; 
  }  
 }

 else
 {
  u4 nc = n_cols();
  u4 nr = n_rows();
  u4 index = c;
  for(u4 r = 0; r < nr; ++r, index += nc)
  {
   r8 rr = get_at_index(index);
   if(rr > result)
     result = rr; 
  }  
 }
 return result;
}


r8 QVector_Matrix_R8::get_minimum_in_row(u4 r)
{
 if(is_diagonal())
   return qMin(get_at(r, r), 0.);

 r8 result = 0;
 if(is_symmetric_or_skew_symmetric())
 {
  // just brute force ...
  for(u4 c = 1; c <= n_cols(); ++c)
  {
   r8 rr = get_at(r, c);
   if(rr < result)
     result = rr;
  }
 }

 else if(is_cmajor())
 {
  u4 nc = n_cols();
  u4 nr = n_rows();
  u4 index = r;
  for(u4 c = 0; c < nc; ++c, index += nr)
  {
   r8 rr = get_at_index(index);
   if(rr < result)
     result = rr; 
  }  
 }

 else
 {
  u4 index = (n_cols() * (r - 1)) + 1;
  for(u4 i = 0; i < n_cols(); ++i, ++index)
  {
   r8 rr = get_at_index(index);
   if(rr < result)
     result = rr; 
  }  
 }
 return result;
}

r8 QVector_Matrix_R8::get_maximum_in_row(u4 r)
{
 if(is_diagonal())
   return qMin(get_at(r, r), 0.);

 r8 result = 0;
 if(is_symmetric_or_skew_symmetric())
 {
  // just brute force ...
  for(u4 c = 1; c <= n_cols(); ++c)
  {
   r8 rr = get_at(r, c);
   if(rr > result)
     result = rr;
  }
 }

 else if(is_cmajor())
 {
  u4 nc = n_cols();
  u4 nr = n_rows();
  u4 index = r;
  for(u4 c = 0; c < nc; ++c, index += nr)
  {
   r8 rr = get_at_index(index);
   if(rr > result)
     result = rr; 
  }  
 }

 else
 {
  u4 index = (n_cols() * (r - 1)) + 1;
  for(u4 i = 0; i < n_cols(); ++i, ++index)
  {
   r8 rr = get_at_index(index);
   if(rr > result)
     result = rr; 
  }  
 }
 return result;
}


void QVector_Matrix_R8::get_row(u4 r, QVector<r8>& row)
{
 row.resize(n_cols());
 if(is_diagonal())
 {
  row.fill(0);
  if(r <= n_cols())
    row[r - 1] = at(r, r);
  return;
 }
 if(is_symmetric() || is_skew_symmetric())
 {
  for(u4 c = 1; c <= n_cols(); ++c)
  {
   row[c - 1] = get_at(r, c);
  }
  return;
 }
 if(is_cmajor())
 {
  //for(u4 c = 1; c <= n_cols(); ++c)
  for(u4 index = r, i = 0; i < n_cols(); ++i, index += n_rows()) 
  {
   //u4 index = r + (c - 1) * n_rows();
   row[i] = elems_->value(index);
  }
  return;
 }

 u4 index = 1 + ((r - 1) * n_cols());

 std::copy(elems_->begin() + index, elems_->begin() + index + n_cols(), row.begin());


// for(u4 i = 0; i < n_cols(); ++i, ++index)
// {
//  row[i] = elems_->value(index);
// }
}

QVector_Matrix_R8* QVector_Matrix_R8::new_from_dimensions()
{
 return new QVector_Matrix_R8(n_rows(), n_cols());
}

void QVector_Matrix_R8::save_to_datastream(QDataStream& qds)
{
 qds << n_rows_ << n_cols_ << *elems_;
}

void QVector_Matrix_R8::load_from_datastream(QDataStream& qds)
{
 elems_ = new QVector<r8>;
 qds >> n_rows_ >> n_cols_ >> *elems_;
}

void QVector_Matrix_R8::save_to_file(QString path)
{
 QFile qf(path);
 if(!qf.open( QIODevice::WriteOnly ))
   return;
 QDataStream qds(&qf);
 qds << n_rows_ << n_cols_ << *elems_;
 qf.close();
}

void QVector_Matrix_R8::load_from_file(QString path)
{
 QFile qf(path);
 if(!qf.open( QIODevice::ReadOnly ))
   return;
 QDataStream qds(&qf);
 elems_ = new QVector<r8>;
 qds >> n_rows_ >> n_cols_ >> *elems_;
 qf.close();
}


u4 QVector_Matrix_R8::n_rows() const
{
 return n_rows_ >> 1;
}

void QVector_Matrix_R8::set_n_rows(u4 n_rows)
{
 n_rows_ = n_rows << 1;
}

u4 QVector_Matrix_R8::n_cols() const
{
 if(n_cols_ <= 1)
   return n_rows();
 return n_cols_ >> 1;
}

void QVector_Matrix_R8::set_n_cols(u4 n_cols)
{
 n_cols_ = n_cols << 1;
}

template<>
u4 QVector_Matrix_R8::_total_size<QVector_Matrix_R8::special_mode::Sym>()
{
 u4 n = n_rows();
 return (n * (n + 1)) / 2;
}

template<>
u4 QVector_Matrix_R8::_total_size<QVector_Matrix_R8::special_mode::Skew>()
{
 return _total_size<QVector_Matrix_R8::special_mode::Sym>();
}

template<>
u4 QVector_Matrix_R8::_total_size<QVector_Matrix_R8::special_mode::Diag>()
{
 return get_diagonal_length();
}


u4 QVector_Matrix_R8::total_size()
{
 if(is_symmetric())
   return _total_size<QVector_Matrix_R8::special_mode::Sym>();
 if(is_skew_symmetric())
   return _total_size<QVector_Matrix_R8::special_mode::Skew>();
 if(is_diagonal())
   return _total_size<QVector_Matrix_R8::special_mode::Diag>();

 return n_rows() * n_cols();
}

u4 QVector_Matrix_R8::get_sym_index(u4 r, u4 c)
{
 // // assumes r, c are in bounds
 u4 result = 0;

 if(is_cmajor())
 {
  if(c < r)
    // //  treat them as if they're flipped
    result = ( (r * (r - 1)) / 2 ) + c;
  else 
    result = ( (c * (c - 1)) / 2 ) + r;
 }
 else
 {
  if(c < r)
    // //  treat them as if they're flipped
    result = ( (c - 1)*n_cols() ) - ( (c - 2)*(c - 1) )/2 + (r - (c - 1));
  else
    result = ( (r - 1)*n_cols() ) - ( (r - 2)*(r - 1) )/2 + (c - (r - 1)) ;
 }
 return result;

}

template<>
u4 QVector_Matrix_R8::_get_index<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{
 if(r > n_rows())
   return 0;
 if(c > n_rows())
   return 0;

 return get_sym_index(r, c);
}

template<>
u4 QVector_Matrix_R8::_get_index<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{
 return _get_index<QVector_Matrix_R8::special_mode::Sym>(r, c);
}

template<>
u4 QVector_Matrix_R8::_get_index<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{
 if(r > n_rows())
   return 0;
 if(c > n_cols())
   return 0;
 return r;
}

u4 QVector_Matrix_R8::_get_normal_index(u4 r, u4 c)
{
 if(is_cmajor())
   return ((c - 1) * n_rows()) + r;
 return ((r - 1) * n_cols()) + c;
}

u4 QVector_Matrix_R8::get_index(u4 r, u4 c)
{
 if(is_symmetric())
   return _get_index<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _get_index<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _get_index<QVector_Matrix_R8::special_mode::Diag>(r, c);

 return _get_normal_index(r, c);
}


u4 QVector_Matrix_R8::covers(u4 r, u4 c)
{
 u4 pos = get_index(r, c);
 if(pos == 0)
   return 0;
 return (total_size() + 1) - pos;
}


void QVector_Matrix_R8::symmetric(u4 n_rows)
{
 u4 cm = n_rows_ & 1;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = 0;

 default_init( ( n_rows * (n_rows + 1) )/2 );
}

void QVector_Matrix_R8::skew_symmetric(u4 n_rows)
{
 u4 cm = n_rows_ & 1;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = 1;

 default_init( ( n_rows * (n_rows + 1) )/2 );
}

void QVector_Matrix_R8::diagonal(u4 n_rows)
{
 diagonal(n_rows, n_rows);
}

void QVector_Matrix_R8::default_init(u4 len)
{
 // // len should already reflect zeroth ...

 if(elems_)
 {
  if( (u4) elems_->size() < len)
    elems_->resize(len);
  else if( (u4) elems_->size() > len)
  {
   elems_->resize(len);
   elems_->squeeze();
  }
 }
 else
   elems_ = new QVector<r8>(len);
}

void QVector_Matrix_R8::diagonal(u4 n_rows, u4 n_cols)
{
 u4 cm = n_cols_ < n_rows ? 1 : 0;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = n_cols << 1;
 n_cols_ |= 1;

 u4 len = cm? n_cols + 1 : n_rows + 1;
 default_init(len);
}

void QVector_Matrix_R8::diagonal()
{
 diagonal(n_rows());
}

void QVector_Matrix_R8::rmajor()
{
 if(n_rows_ & 1)
   n_rows_ ^= 1;
}

void QVector_Matrix_R8::cmajor()
{
 n_rows_ |= 1;
}


void QVector_Matrix_R8::_to_raw_data(QByteArray& qba, u4 offset, u4 count)
{
 if(!elems_)
   return;
 if(elems_->size() <= 1)
   return;
// if(ts < count)
//   count = ts;

 const r8* rr = elems_->constData();
 rr += offset;
 qba = QByteArray( (const char*) rr, count * value_byte_size());
}

void QVector_Matrix_R8::to_raw_data(QByteArray& qba)
{
 if(!elems_)
   return;
 u4 ts = total_size();
 if(ts == 0)
   return;
 _to_raw_data(qba, 1, ts);
}

void QVector_Matrix_R8::_from_raw_data_with_encoded_default(
  const QByteArray& qba, QPair<u4, u4> dims, u4 total_size)
{
 u4 ts = total_size? total_size + 1 : (dims.first * dims.second) + 1;

 default_init(ts);
/*
 if(elems_)
 {
  if((u4) elems_->size() < ts)
    elems_->resize(ts);
  else if((u4) elems_->size() > ts)
  {
   elems_->resize(ts);
   elems_->squeeze();
  }
 }
 else 
   elems_ = new QVector<r8>(ts);
*/

 r8* d = elems_->data();
 memcpy(d, qba.constData(), ts * value_byte_size()); 
}

void QVector_Matrix_R8::_from_raw_data(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv, u4 total_size)
{
 u4 ts = total_size? total_size : dims.first * dims.second;
 default_init(ts + 1);

/*
 if(elems_)
 {
  if((u4) elems_->size() < ts + 1)
    elems_->resize(ts + 1);
  else if((u4) elems_->size() > ts + 1)
  {
   elems_->resize(ts + 1);
   elems_->squeeze();
  }
 }
 else 
   elems_ = new QVector<r8>(ts + 1);
*/

 r8* d = elems_->data();
 *d = defaultv;
 memcpy(d + 1, qba.constData(), ts * value_byte_size());
}

void QVector_Matrix_R8::_from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, 
  r8 defaultv, special_mode_x smx)
{
 switch(smx)
 {
 case special_mode_x::N_A:
  set_n_rows(dims.first);
  set_n_cols(dims.second);
  _from_raw_data(qba, dims, defaultv);
  break;
 case special_mode_x::Sym:
  set_n_rows(dims.first);
  n_cols_ = 0;
  _from_raw_data(qba, dims, defaultv,
    ( dims.first * (dims.first + 1) )/2 );
  break;
 case special_mode_x::Skew:
  set_n_rows(dims.first);
  n_cols_ = 1;
  _from_raw_data(qba, dims, defaultv,
    ( dims.first * (dims.first + 1) )/2 );
  break;
 case special_mode_x::Diag:
  set_n_rows(dims.first);
  set_n_cols(dims.second);
  n_cols_ |= 1;
  if(dims.second < dims.first)
  {
   n_rows_ |= 1;
   _from_raw_data(qba, dims, defaultv, dims.second);
  }
  else
    _from_raw_data(qba, dims, defaultv, dims.first);
  break;

 case special_mode_x::ED:
  set_n_rows(dims.first);
  set_n_cols(dims.second);
  _from_raw_data_with_encoded_default(qba, dims, defaultv);
  break;
 case special_mode_x::Sym_ED:
  set_n_rows(dims.first);
  n_cols_ = 0;
  _from_raw_data_with_encoded_default(qba, dims,
    ( dims.first * (dims.first + 1) )/2 );
  break;
 case special_mode_x::Skew_ED:
  set_n_rows(dims.first);
  n_cols_ = 1;
  _from_raw_data_with_encoded_default(qba, dims,
    ( dims.first * (dims.first + 1) )/2 );
  break;
 case special_mode_x::Diag_ED:
  set_n_rows(dims.first);
  set_n_cols(dims.second);
  n_cols_ |= 1;
  if(dims.second < dims.first)
  {
   n_rows_ |= 1;
   _from_raw_data_with_encoded_default(qba, dims, dims.second);
  }
  else
    _from_raw_data_with_encoded_default(qba, dims, dims.first);
  break;
 }
}

 // // utility for the _from_raw_data's
void merge_dims(QVector_Matrix_R8& _this, QPair<u4, u4>& dims)
{
 if(dims.first == 0)
   dims.first = _this.n_rows();
 else
   _this.set_n_rows(dims.first);

 if(dims.second == 0)
   dims.second = _this.n_cols();
 else
   _this.set_n_cols(dims.second);
}

void QVector_Matrix_R8::_from_raw_data_special::cmajor(
  const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv)
{
 merge_dims(_this, dims);
 
 switch(mfrd)
 {
 case special_mode_for_raw_data::CM:
 case special_mode_for_raw_data::Normal:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::N_A);
   _this.cmajor();
   break;
 case special_mode_for_raw_data::ED_CM:
 case special_mode_for_raw_data::ED:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::ED);
   _this.cmajor();
   break;
 }
}

void QVector_Matrix_R8::_from_raw_data_special::_diagonal(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 merge_dims(_this, dims);
 
 switch(mfrd)
 {
 case special_mode_for_raw_data::CM:
 case special_mode_for_raw_data::Normal:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Diag);
   break;
 case special_mode_for_raw_data::ED_CM:
 case special_mode_for_raw_data::ED:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Diag_ED);
   break;
 }
}

void QVector_Matrix_R8::_from_raw_data_special::_symmetric(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 merge_dims(_this, dims);
 
 switch(mfrd)
 {
 case special_mode_for_raw_data::CM:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Sym);
   _this.cmajor();
   break;
 case special_mode_for_raw_data::Normal:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Sym);
   break;
 case special_mode_for_raw_data::ED_CM:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Sym_ED);
   _this.cmajor();
   break;
 case special_mode_for_raw_data::ED:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Sym_ED);
   break;
 }

}

void QVector_Matrix_R8::_from_raw_data_special::_skew_symmetric(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 merge_dims(_this, dims);
 
 switch(mfrd)
 {
 case special_mode_for_raw_data::CM:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Skew);
   _this.cmajor();
   break;
 case special_mode_for_raw_data::Normal:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Skew);
   break;
 case special_mode_for_raw_data::ED_CM:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Skew_ED);
   _this.cmajor();
   break;
 case special_mode_for_raw_data::ED:
   _this._from_raw_data(qba, dims, defaultv, special_mode_x::Skew_ED);
   break;
 }
}

void QVector_Matrix_R8::from_raw_data(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 set_n_rows(dims.first);
 set_n_cols(dims.second);
 _from_raw_data(qba, dims, defaultv);
}

void QVector_Matrix_R8::from_raw_data(const QByteArray& qba, r8 defaultv)
{
 _from_raw_data(qba, {n_rows(), n_cols()}, defaultv);
}

void QVector_Matrix_R8::to_raw_data_with_encoded_default(QByteArray& qba)
{
 if(!elems_)
   return;
 u4 ts = total_size();
 if(ts == 0)
   return;
 _to_raw_data(qba, 0, ts + 1);
}

void QVector_Matrix_R8::from_raw_data_with_encoded_default(const QByteArray& qba)
{
 _from_raw_data_with_encoded_default(qba, {n_rows(), n_cols()});
}

void QVector_Matrix_R8::from_raw_data_with_encoded_default(
  const QByteArray& qba, QPair<u4, u4> dims)
{
 set_n_rows(dims.first);
 set_n_cols(dims.second);
 _from_raw_data_with_encoded_default(qba, dims);
}

QVector_Matrix_R8::_one_opbracket 
 QVector_Matrix_R8::operator[](u4 r)
{
 return {*this, r};
}


r8& QVector_Matrix_R8::_one_opbracket::operator[](u4 c)
{
 return *_this.fetch(row, c);
}

r8 QVector_Matrix_R8::_one_opbracket::operator()(u4 c)
{
 return _this.get_value(row, c);
}

r8 QVector_Matrix_R8::_one_opbracket::operator()(u4 c, r8 defaultv)
{
 return _this.value(row, c, defaultv);
}


r8* QVector_Matrix_R8::_defaultv()
{
 static r8* result = nullptr;
 if(!result)
   result = new r8(0);
 return result; 
}


template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Sym>(
  u4 r, u4 c, r8 defaultv)
{
 if(!elems_)
   return defaultv;
 if(r > n_rows())
   return defaultv;
 if(c > n_rows())
   return defaultv;

 u4 pos = get_sym_index(r, c);
 if(pos >= (u4) elems_->size())
   pos = 0;

/*
 if(is_cmajor())
 {

 }
 else
 {
  if(c < r)
  {
   // //  treat them as if they're flipped
   pos = ( (c - 1)*n_cols() ) - ( (c - 2)*(c - 1) )/2 + r;
   if(pos >= (u4) elems_->size())
     pos = 0;
  }
  else
  {
   pos = ( (r - 1)*n_cols() ) - ( (r - 2)*(r - 1) )/2 + c;
   if(pos >= (u4) elems_->size())
     pos = 0;
  }
 }
*/

 return elems_->value(pos, defaultv);
}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c, r8 defaultv)
{
 if(c < r)
   return -_value<QVector_Matrix_R8::special_mode::Sym>(c, r, defaultv);
 return _value<QVector_Matrix_R8::special_mode::Sym>(r, c, defaultv);
}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c, r8 defaultv)
{
 if(r > n_rows())
   return defaultv;
 if(c > n_cols())
   return defaultv;
 if(r != c)
   return 0;

 if(elems_)
 {
  u4 pos = _get_normal_index(r, c); // ((r - 1) * n_cols()) + c;
  return elems_->value(pos, defaultv);
 }
 return defaultv;
}


r8 QVector_Matrix_R8::value(u4 r, u4 c, r8 defaultv)
{
 if(is_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Sym>(r, c, defaultv);
 if(is_skew_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Skew>(r, c, defaultv);
 if(is_diagonal())
   return _value<QVector_Matrix_R8::special_mode::Diag>(r, c, defaultv);


 if(elems_)
 {
  u4 pos = _get_normal_index(r, c); // ((r - 1) * n_cols()) + c;
  return elems_->value(pos, defaultv);
 }
 return defaultv;
}




template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{
 return _value<QVector_Matrix_R8::special_mode::Sym>(r, c, 0);
}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{
 return _value<QVector_Matrix_R8::special_mode::Skew>(r, c, 0);
}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{
 return _value<QVector_Matrix_R8::special_mode::Diag>(r, c, 0);
}

r8 QVector_Matrix_R8::value(u4 r, u4 c)
{
 if(is_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _value<QVector_Matrix_R8::special_mode::Diag>(r, c);

 return value(r, c, 0);
}

r8 QVector_Matrix_R8::get_at_index(u4 pos)
{
 //?qDebug() << "pos: " << pos;
 if(elems_)
 {
  if(pos < elems_->size())
    return (*elems_)[pos];
  if(elems_->isEmpty())
    return *_defaultv();
  return elems_->first();
 }
 return *_defaultv();
}

template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{
 if(elems_)
 {
  if(elems_->isEmpty())
    elems_->push_back(*_defaultv());

  u4 pos = 0;
  if( (r <= n_rows()) && (c <= n_rows()) )
  {
   pos = get_sym_index(r, c);
   if(pos >= (u4) elems_->size())
     pos = 0;
  }

/*
  if(c < r)
  {
   // //  treat them as if they're flipped
   if(c <= n_rows())
   {
    pos = ( (c - 1)*n_cols() ) - ( (c - 2)*(c - 1) )/2 + r;
    if(pos >= (u4) elems_->size())
      pos = 0;
   }
  }
  else
  {
   if(r <= n_rows())
   {
    pos = ( (r - 1)*n_cols() ) - ( (r - 2)*(r - 1) )/2 + c;
    if(pos >= (u4) elems_->size())
      pos = 0;
   }
  }
*/
  return &(*elems_)[pos];
 }
 elems_ = new QVector<r8>(1);
 (*elems_)[0] = *_defaultv();
 return &(*elems_)[0];
}

template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{
  // //  note: have to negate ...
 return _fetch<QVector_Matrix_R8::special_mode::Sym>(r, c);
}

template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{
 u4 pos = 0;

 if(r <= n_rows())
 {
  if(c <= n_cols())
  {
   if(r == c)
     pos = r;
  }
 }
 if(elems_)
   return &(*elems_)[pos];

 elems_ = new QVector<r8>(1);
 (*elems_)[0] = *_defaultv();
 return &(*elems_)[0];
}

r8* QVector_Matrix_R8::fetch(u4 r, u4 c)
{
 if(is_symmetric())
   return _fetch<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _fetch<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _fetch<QVector_Matrix_R8::special_mode::Diag>(r, c);


 if(elems_)
 { 
  u4 pos = 0;
  if(r <= n_rows())
  {
   if(c <= n_cols())
   {  
    pos = _get_normal_index(r, c); // ((r - 1) * n_cols()) + c;
    if(pos >= (u4) elems_->size())
      pos = 0;
   }
  }
  return &(*elems_)[pos];
 }
 elems_ = new QVector<r8>(1);
 (*elems_)[0] = *_defaultv();
 return &(*elems_)[0];
}


template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{
 return *_fetch<QVector_Matrix_R8::special_mode::Sym>(r, c); 
}

template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{
 return *_fetch<QVector_Matrix_R8::special_mode::Skew>(r, c); 
}

template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{
 return *_fetch<QVector_Matrix_R8::special_mode::Diag>(r, c); 
}

const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(is_symmetric())
   return _at<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _at<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _at<QVector_Matrix_R8::special_mode::Diag>(r, c);

 return *fetch(r, c);
}

 // // keep this?
r8 QVector_Matrix_R8::get_value(u4 r, u4 c)
{
 if(is_skew_symmetric() && (c < r))
   return -at(c, r);
 return at(r, c);
}

r8 QVector_Matrix_R8::get_at(u4 r, u4 c)
{
 if(is_skew_symmetric() && (c < r))
   return -at(c, r);
 return at(r, c);
}


template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{
 if(!elems_)
   return nullptr;
 if(r > n_rows())
   return nullptr;  
 if(c > n_rows())
   return nullptr;  

 u4 pos = get_sym_index(r, c);
 if(pos >= (u4) elems_->size())
   pos = 0;

/*
 if(c < r)
 {
  // //  treat them as if they're flipped
  if(c <= n_rows())
  {
   pos = ( (c - 1)*n_cols() ) - ( (c - 2)*(c - 1) )/2 + r;
   if(pos >= (u4) elems_->size())
     pos = 0;
  }
 }
 else
 {
  if(r <= n_rows())
  {
   pos = ( (r - 1)*n_cols() ) - ( (r - 2)*(r - 1) )/2 + c;
   if(pos >= (u4) elems_->size())
     pos = 0;
  }
 }
*/
 if(pos == 0)
    return nullptr;
 return &(*elems_)[pos];
}

template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{
  // // user has to negate
 return _get<QVector_Matrix_R8::special_mode::Sym>(r, c);
}

template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{
 if(elems_)
 {
  if(r > n_rows())
    return nullptr;
  if(c > n_cols())
    return nullptr;
  if(r == c)
    return &(*elems_)[r];
 }
 return nullptr;
}

r8* QVector_Matrix_R8::get(u4 r, u4 c)
{
 if(is_symmetric())
   return _get<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _get<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _get<QVector_Matrix_R8::special_mode::Diag>(r, c);

 if(elems_)
 {
  if(r > n_rows())
    return nullptr;
  if(c > n_cols())
    return nullptr;

  u4 pos = _get_normal_index(r, c); // ((r - 1) * n_cols()) + c;
  if(pos >= (u4) elems_->size())
    return nullptr; 
  
  return &(*elems_)[pos];
 }
 return nullptr;
}


/*
const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(elems_)
 {
  return elems_->value( ((r - 1) * n_cols()) + c );
 }
 return 0;
}
*/

void QVector_Matrix_R8::resize(u4 r, u4 c)
{
 resize(r * c);
}

void QVector_Matrix_R8::resize(u4 total)
{
 if(elems_)
 {
  elems_->resize(total + 1);
 }
 else
   elems_ = new QVector<r8>(total + 1);
}





//  data=double matrix

// n_cols
// n_elem
// n_rows

// vec_state
// mem_state
// mem_local


