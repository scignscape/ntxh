
#include "mat2d.h"


template<typename COLL_Type>
Mat2d<COLL_Type>::Mat2d(nx r, nx c, nnx layer_size, nnx block_size)
  : n_rows_(r << 1), n_cols_(c << 1), elems_((r && c)?
    new COLL_Type(layer_size, block_size) : nullptr)
{
 if(elems_)
   elems_->declare_size(r * c + 1);

}

template<typename COLL_Type>
void Mat2d<COLL_Type>::set_default_value(val_t defaultv)
{
 elems_->first() = defaultv;
}


//QVector_Matrix_val_t::QVector_Matrix_val_t(nx r, nx c, val_t defaultv)
// : n_rows_(r << 1), n_cols_(c << 1),
//   elems_( (r && c)? new QVector<val_t>((r * c) + 1) : nullptr)
//{
// if(elems_)
//   (*elems_)[0] = defaultv;
//}


template<typename COLL_Type>
void Mat2d<COLL_Type>::fill(val_t value, val_t default_value,
  nnx layer_size, nnx block_size)
{
 if(elems_)
 {
  nx s = elems_->size();
  elems_->resize(total_size() + 1);
  if(value != 0)
  {
   for(nx i = s; i < elems_->size(); ++i)
   {
    elems_->at_index(i) = value;
    //(*elems_)[s] = value;
   }
  }
 }
 else
 {
  elems_ = new COLL_Type(layer_size, block_size);
    //new QVector<val_t>(total_size() + 1, value);
  elems_->first() = default_value;
  auto it = elems_->iterator_at(1);
  elems_->fill(it, value, it._end());
 }
}

template<typename COLL_Type>
void Mat2d<COLL_Type>::get_extrema(QPair<val_t, val_t>& result)
{
 QVector<QPair<val_t, val_t>> extrema;
 if(is_rmajor())
   get_row_extrema(extrema);
 else
   get_column_extrema(extrema);

 result = std::accumulate(extrema.begin(), extrema.end(),
   QPair<val_t, val_t> {std::numeric_limits<val_t>::max(), std::numeric_limits<val_t>::min()},
   [](QPair<val_t, val_t> pr1, QPair<val_t, val_t> pr2) -> QPair<val_t, val_t>
 {
  return {qMin(pr1.first, pr2.first), qMax(pr2.second, pr2.second)};
 });
}

template<typename COLL_Type>
Mat2d<COLL_Type>* Mat2d<COLL_Type>::percentile_breakdown(u1 max)
{
 QPair<val_t, val_t> extrema;
 get_extrema(extrema);

 Mat2d<COLL_Type>* result = new Mat2d<COLL_Type>;
 result->set_n_rows(max + 1);
 result->set_n_cols(n_cols());
 result->fill();

  // // for each column, aggregate all entries into percentiles.
   //   Currently not optimized for data access at all ...
 for(u4 c = 1; c <= n_cols(); ++c)
 {
  for(u4 r = 1; r <= n_rows(); ++r)
  {
   val_t rr = get_at(r, c);
   val_t _percentile = (rr - extrema.first) / (extrema.second - extrema.first);
   u1 percentile = (_percentile * max) + 1;
   //?++(*result)[percentile][c];
  }
 }
 return result;
}

template<typename COLL_Type>
Mat2d<COLL_Type>* Mat2d<COLL_Type>::percentile_rescale(u1 max)
{
 QPair<val_t, val_t> extrema;
 get_extrema(extrema);

 Mat2d<COLL_Type>* result = new_from_dimensions();

  // // for each column, aggregate all entries into percentiles.
   //   Currently not optimized for data access at all ...
 for(nx c = 1; c <= n_cols(); ++c)
 {
  for(nx r = 1; r <= n_rows(); ++r)
  {
   val_t rr = get_at(r, c);
   val_t _percentile = (rr - extrema.first) / (extrema.second - extrema.first);
   u1 percentile = (_percentile * max) + 1;
   //?(*result)[r][c] = percentile;
  }
 }
 return result;
}

template<typename COLL_Type>
void Mat2d<COLL_Type>::merge_row(const QVector<val_t>& vec, nx row)
{
 if(is_diagonal())
 {
  if(row <= n_cols())
    (*this)[row][row] = vec.value(row - 1);
  return;
 }
 if(is_symmetric() || is_skew_symmetric())
 {
  for(nx c = 1; c <= n_cols(); ++c)
  {
   (*this)[row][c] = vec.value(c - 1);
  }
  return;
 }
 if(is_cmajor())
 {
  //?for(u4 c = 1; c <= n_cols(); ++c)
  for(nx index = row, i = 0; i < n_cols(); ++i, index += n_rows())
  {
   //?u4 index = r + (c - 1) * n_rows();
   (*elems_)[index] = vec.value(i);
  }
  return;
 }

 nx index = 1 + ((row - 1) * n_cols());

 //? std::copy(vec.begin(), vec.end(), elems_->begin() + index);

// for(u4 i = 0; i < n_cols(); ++i, ++index)
// {
//  (*elems_)[index] = vec[i];
// }
}
