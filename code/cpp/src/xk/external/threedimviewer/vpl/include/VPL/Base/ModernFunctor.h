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

#ifndef VPL_BASE_MODERN_FUNCTOR_H
#define VPL_BASE_MODERN_FUNCTOR_H

#include <functional>

namespace vpl
{
namespace base
{

//! \brief Single parameter template class to allow "R (Ts...)" syntax.
template <typename>
class Functor;

//! \brief Modern functor.
template <typename R, typename... Ts>
class Functor<R (Ts...)>
{
public:
	using Function = std::function<R (Ts...)>;

    //! \brief Default constructor.
    Functor();
	
	//! \brief Copy constructor.
    //! \param[in] arg Argument.
    Functor(const Functor& arg);
	
	//! \brief Constructor creates functor encapsulating any function.
    //! \param[in] func Function.
    explicit Functor(Function func);

	//! \brief Constructor creates functor encapsulating pointer to a member function.
    //! \param[in] object Instance.
    //! \param[in] func Member function.
	template <typename T>
    explicit Functor(T& object, R (T::*func)(Ts...));

	//! \brief Constructor creates functor encapsulating pointer to a member function.
    //! \param[in] object Const instance.
    //! \param[in] func Const member function.
	template <typename T>
    explicit Functor(const T& object, R (T::*func)(Ts...) const);

    //! \brief Assignment operator.
    //! \param[in] rhs Right-hand side.
    //! \return Reference to this.
    Functor& operator =(const Functor& rhs);

    //! \brief Function operator.
    //! \param[in] args Arguments.
    //! \return The return type.
    R operator ()(Ts... args);

    //! \brief Return the functor implementation.
    //! \return Functor implementation.
    const Function& getImpl() const;

private:
    //! \brief Handler.
    Function m_function;
};

//! \brief Wrapper for the class #Functor to maintain compatibility
//!        with code using vpl::base::CFunctor.
template <typename R, typename... Ts>
class FunctorWrapper : public Functor<R (Ts...)>
{
public:
    //! \brief Default constructor.
    FunctorWrapper();
	
	//! \brief Copy constructor.
    //! \param[in] arg Argument.
    FunctorWrapper(const FunctorWrapper& arg);
	
	//! \brief Constructor creates functor encapsulating any function.
    //! \param[in] func Function.
    explicit FunctorWrapper(typename Functor<R (Ts...)>::Function func);

	//! \brief Constructor creates functor encapsulating pointer to a member function.
    //! \param[in] object Instance.
    //! \param[in] func Member function.
	template <typename T>
    explicit FunctorWrapper(T& object, R (T::*func)(Ts...));

	//! \brief Constructor creates functor encapsulating pointer to a const member function.
    //! \param[in] object Const instance.
    //! \param[in] func Const member function.
	template <typename T>
    explicit FunctorWrapper(const T& object, R (T::*func)(Ts...) const);

    //! \brief Assignment operator.
    //! \param[in] rhs Right-hand side.
    //! \return Reference to this.
    FunctorWrapper& operator =(const FunctorWrapper& rhs);
};

}// namespace base
}// namespace vpl

#include "ModernFunctor.hxx"

#endif
