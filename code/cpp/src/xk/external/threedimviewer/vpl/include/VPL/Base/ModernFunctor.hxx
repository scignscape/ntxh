//==============================================================================`
/* This file comes from MDSTk software and was modified for
 *
 * VPL - Voxel Processing Library
 * Changes are Copyright 2018 3Dim Laboratory s.r.o.
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * The original MDSTk legal notice can be found below.
 *
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2008 by PGMed          
 *
 * Authors: Ján Brída brida@t3d.team
 * Date:    2018/05/11 
 *
 * Description:
 * - Simple signals and callback invocation mechanism exploiting C++11 features.
 */

namespace vpl
{
namespace base
{

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Functor<R (Ts...)>::Functor()
{
}
	
//______________________________________________________________________________
template <typename R, typename... Ts>
inline Functor<R (Ts...)>::Functor(const Functor& arg) :
    m_function{arg.m_function}
{
}
	
//______________________________________________________________________________
template <typename R, typename... Ts>
inline Functor<R (Ts...)>::Functor(Function func) :
    m_function{func}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <class T>
inline Functor<R (Ts...)>::Functor(T& object, R (T::*func)(Ts...)) :
    m_function{[object = &object, func = func] (Ts... args) -> R
               { return static_cast<R>((object->*func)(args...)); }}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <class T>
inline Functor<R (Ts...)>::Functor(const T& object, R (T::*func)(Ts...) const) :
    m_function{[object = &object, func = func] (Ts... args) -> R
               { return static_cast<R>((object->*func)(args...)); }}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Functor<R (Ts...)>& Functor<R (Ts...)>::operator =(const Functor& rhs)
{
    if (this != &rhs)
    {
        m_function = rhs.m_function;
    }

    return *this;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline R Functor<R (Ts...)>::operator ()(Ts... args)
{
    return static_cast<R>(m_function(args...));
}

//______________________________________________________________________________
template <typename R, typename... Ts>
const typename Functor<R (Ts...)>::Function& Functor<R (Ts...)>::getImpl() const
{
    return m_function;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline FunctorWrapper<R, Ts...>::FunctorWrapper() :
    Functor<R (Ts...)>{}
{
}
	
//______________________________________________________________________________
template <typename R, typename... Ts>
inline FunctorWrapper<R, Ts...>::FunctorWrapper(const FunctorWrapper& arg) :
    Functor<R (Ts...)>{arg}
{
}
	
//______________________________________________________________________________
template <typename R, typename... Ts>
inline FunctorWrapper<R, Ts...>::FunctorWrapper(typename Functor<R (Ts...)>::Function func) :
    Functor<R (Ts...)>{func}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <class T>
inline FunctorWrapper<R, Ts...>::FunctorWrapper(T& object, R (T::*func)(Ts...)) :
    Functor<R (Ts...)>{object, func}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <class T>
inline FunctorWrapper<R, Ts...>::FunctorWrapper(const T& object, R (T::*func)(Ts...) const) :
    Functor<R (Ts...)>{object, func}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline FunctorWrapper<R, Ts...>& FunctorWrapper<R, Ts...>::operator =(const FunctorWrapper& rhs)
{
    Functor<R (Ts...)>::operator =(rhs);

    return *this;
}

}// namespace base
}// namespace vpl
