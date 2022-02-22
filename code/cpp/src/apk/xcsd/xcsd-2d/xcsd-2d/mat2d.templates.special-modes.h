
#include "mat2d.h"

XCNS_(XCSD)

//template<typename COLL_Type>
//void Mat2d<COLL_Type>::set_n_rows(nx n_rows)
//{
// n_rows_ = n_rows << 1;
//}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Sym::_total_size()
{
 typename COLL_Type::Numeric_Index_type n = _this->n_rows();
 return (n * (n + 1)) / 2;
}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Skew::_total_size()
{
 return _Mat2d_special_mode<COLL_Type>::_Sym(_this)._total_size();
// typename COLL_Type::Numeric_Index_type n = _this->n_rows();
// return (n * (n + 1)) / 2;
}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Diag::_total_size()
{
 return _this->get_diagonal_length();
}


template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Sym::_get_index(nx r, nx c)
{
 if(r > _this->n_rows())
   return 0;
 if(c > _this->n_rows())
   return 0;

 return _this->get_sym_index(r, c);
}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Skew::_get_index(nx r, nx c)
{
 return _Mat2d_special_mode<COLL_Type>::_Sym(_this)._get_index(r, c);
}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
_Mat2d_special_mode<COLL_Type>::_Diag::_get_index(nx r, nx c)
{
 if(r > _this->n_rows())
   return 0;
 if(c > _this->n_cols())
   return 0;
 return r;
}



template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Sym::_fetch(nx r, nx c)
{
 if(_this->elems_)
 {
  _this->elems_->rebound(0, *_this->_defaultv());
//  if(_this->elems_->isEmpty())
//    elems_->push_back(*_defaultv());

  nx pos = 0;
  if( (r <= _this->n_rows()) && (c <= _this->n_rows()) )
  {
   pos = get_sym_index(r, c);
   if(pos >= (u4) _this->elems_->size())
     pos = 0;
  }
  return _this->elems_->fetch(pos); // &(*elems_)[pos];
 }
 //?elems_ = new QVector<r8>(1);
 //?_this->elems_->rebound_first(*_this->_defaultv());
 //(*elems_)[0] = *_defaultv();
 //?return &(*elems_)[0];

}

template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Skew::_fetch(nx r, nx c)
{
 // //  note: have to negate ...
 return _Mat2d_special_mode<COLL_Type>::_Sym(_this)._fetch(r, c);
}

template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Diag::_fetch(nx r, nx c)
{
 nx nix = 0;

 if(r <= _this->n_rows())
 {
  if(c <= _this->n_cols())
  {
   if(r == c)
     nix = r;
  }
 }
 if(_this->elems_)
   return _this->elems_->fetch(nix);

//?
// elems_ = new QVector<r8>(1);
// (*elems_)[0] = *_defaultv();
// return &(*elems_)[0];
}


template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Sym::_get(nx r, nx c)
{
 if(!_this->elems_)
   return nullptr;
 if(r > _this->n_rows())
   return nullptr;
 if(c > _this->n_rows())
   return nullptr;

 nx nix = get_sym_index(r, c);
 if(nix >= (nx) _this->elems_->size())
   nix = 0;

 if(nix == 0)
   return nullptr;

 // //  or get?
 return _this->elems_->fetch(nix);
}

template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Skew::_get(nx r, nx c)
{
 // //  note: have to negate ...
 return *_Mat2d_special_mode<COLL_Type>::_Sym(_this)._get(r, c);
}

template<typename COLL_Type>
typename COLL_Type::Value_type*
_Mat2d_special_mode<COLL_Type>::_Diag::_get(nx r, nx c)
{
 if(!_this->elems_)
   return nullptr;

 if(r > _this->n_rows())
    return nullptr;
 if(c > _this->n_cols())
    return nullptr;
 if(r == c)
    return _this->elems_->fetch(r);

 return nullptr;
}


template<typename COLL_Type>
typename COLL_Type::Value_type&
_Mat2d_special_mode<COLL_Type>::_Sym::_at(nx r, nx c)
{
 return *_Mat2d_special_mode<COLL_Type>::_Sym(_this)._fetch(r, c);
}


template<typename COLL_Type>
typename COLL_Type::Value_type&
_Mat2d_special_mode<COLL_Type>::_Skew::_at(nx r, nx c)
{
 // //  note: have to negate ...
 return *_Mat2d_special_mode<COLL_Type>::_Skew(_this)._fetch(r, c);
}

template<typename COLL_Type>
typename COLL_Type::Value_type&
_Mat2d_special_mode<COLL_Type>::_Diag::_at(nx r, nx c)
{
 return *_Mat2d_special_mode<COLL_Type>::_Diag(_this)._fetch(r, c);
}


//template<>
//typename COLL_Type::Numeric_Index_Type



//Mat2d_special_mode<COLL_Type>::mode<Mat2d<COLL_Type>::special_mode::Sym>::_total_size()
//{
// typename COLL_Type::Numeric_Index_type n = _this.n_rows();
// return (n * (n + 1)) / 2;
//}

//  typename COLL_Type::Numeric_Index_type
//_special_mode<COLL_Type, Mat2d<COLL_Type>::special_mode::Sym>
//::_total_size()
//{
// typename COLL_Type::Numeric_Index_type n = _this.n_rows();
// return (n * (n + 1)) / 2;
//}

_XCNS(XCSD)

//typename COLL_Type::Numeric_Index_type
//_total_size<COLL_Type, Mat2d<COLL_Type>::special_mode::Sym>(Mat2d<COLL_Type>& _this)
//{
// typename COLL_Type::Numeric_Index_type n = _this.n_rows();
// return (n * (n + 1)) / 2;
//}



#ifdef HIDE

template<typename COLL_Type>
template<typename Mat2d<COLL_Type>::special_mode>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_total_size<Mat2d<COLL_Type>::special_mode::Sym>()
{
 nx n = n_rows();
 return (n * (n + 1)) / 2;
}

template<typename COLL_Type>
template<typename Mat2d<COLL_Type>::special_mode>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_total_size<Mat2d<COLL_Type>::special_mode::Skew>()
{
 return _total_size<Mat2d<COLL_Type>::special_mode::Sym>();
}

template<typename COLL_Type>
template<>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_total_size<Mat2d<COLL_Type>::special_mode::Diag>()
{
 return get_diagonal_length();
}

template<typename COLL_Type>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::get_sym_index(nx r, nx c)
{
 // // assumes r, c are in bounds
 nx result = 0;

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

template<typename COLL_Type>
template<>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_get_index<Mat2d<COLL_Type>::special_mode::Sym>(nx r, nx c)
{
 if(r > n_rows())
   return 0;
 if(c > n_rows())
   return 0;

 return get_sym_index(r, c);
}

template<typename COLL_Type>
template<>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_get_index<Mat2d<COLL_Type>::special_mode::Skew>(nx r, nx c)
{
 return _get_index<QVector_Matrix_R8::special_mode::Sym>(r, c);
}

template<typename COLL_Type>
template<>
typename COLL_Type::Numeric_Index_type
Mat2d<COLL_Type>::_get_index<Mat2d<COLL_Type>::special_mode::Diag>(nx r, nx c)
{
 if(r > n_rows())
   return 0;
 if(c > n_cols())
   return 0;
 return r;
}

#endif
