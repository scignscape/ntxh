//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)		\n
 * Copyright (c) 2003-2008 by Michal Spanel			\n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz		\n
 * Date:     2008/02/20								\n
 *
 * $Id: mdsFunctor.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * File description:
 * - Functors encapsulating pointer to functions and etc.
 */

#ifndef MDS_Functor_H
#define MDS_Functor_H

#include "mdsTemplates.h"
#include "mdsTypeTraits.h"
#include "mdsScopedPtr.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Base class for all functors.
 * - Allowed are up to four arguments.
 */
template <typename R,
          typename P1 = tNull, typename P2 = tNull,
          typename P3 = tNull, typename P4 = tNull
          >
struct CFunctorBase
{
	//! Number of functor parameters.
	enum { NUM_OF_PARAMS = 4 };
	
	//! Type of the functor result.
	typedef R tResult;
	
	//! Types of functor parameters.
	typedef typename CTypeTraits<P1>::tParameter tParam1;
	typedef typename CTypeTraits<P2>::tParameter tParam2;
	typedef typename CTypeTraits<P3>::tParameter tParam3;
	typedef typename CTypeTraits<P4>::tParameter tParam4;

	//! Virtual function operator.
	virtual R operator()(tParam1, tParam2, tParam3, tParam4) = 0;

    //! Creates a new copy of the functor object.
    virtual CFunctorBase *clone() const = 0;

    //! Virtual destructor
    virtual ~CFunctorBase() {}
};


//! Partial specialization for functor with three parameters.
template <typename R, typename P1, typename P2, typename P3>
struct CFunctorBase<R, P1, P2, P3, tNull>
{
	enum { NUM_OF_PARAMS = 3 };

	typedef R tResult;
	typedef typename CTypeTraits<P1>::tParameter tParam1;
	typedef typename CTypeTraits<P2>::tParameter tParam2;
	typedef typename CTypeTraits<P3>::tParameter tParam3;
	typedef tNull tParam4;

	virtual R operator()(tParam1, tParam2, tParam3) = 0;
    virtual CFunctorBase *clone() const = 0;
    virtual ~CFunctorBase() {}
};


//! Partial specialization for functor with two parameters.
template <typename R, typename P1, typename P2>
struct CFunctorBase<R, P1, P2, tNull, tNull>
{
	enum { NUM_OF_PARAMS = 2 };

	typedef R tResult;
	typedef typename CTypeTraits<P1>::tParameter tParam1;
	typedef typename CTypeTraits<P2>::tParameter tParam2;
	typedef tNull tParam3;
	typedef tNull tParam4;

	virtual R operator()(tParam1, tParam2) = 0;
    virtual CFunctorBase *clone() const = 0;
    virtual ~CFunctorBase() {}
};


//! Partial specialization for functor with one parameter.
template <typename R, typename P1>
struct CFunctorBase<R, P1, tNull, tNull, tNull>
{
	enum { NUM_OF_PARAMS = 1 };

	typedef R tResult;
	typedef typename CTypeTraits<P1>::tParameter tParam1;
	typedef tNull tParam2;
	typedef tNull tParam3;
	typedef tNull tParam4;

	virtual R operator()(tParam1) = 0;
    virtual CFunctorBase *clone() const = 0;
    virtual ~CFunctorBase() {}
};


//! Partial specialization for functor with no parameters.
template <typename R>
struct CFunctorBase<R, tNull, tNull, tNull, tNull>
{
	enum { NUM_OF_PARAMS = 0 };

	typedef R tResult;
	typedef tNull tParam1;
	typedef tNull tParam2;
	typedef tNull tParam3;
	typedef tNull tParam4;

	virtual R operator()() = 0;
    virtual CFunctorBase *clone() const = 0;
    virtual ~CFunctorBase() {}
};


//==============================================================================
/*!
 * Wraps pointers to functions.
 * - Parameter T is a parent functor.
 * - Parameter F is a function type.
 */
template <class T, typename F>
class CFuncHandler : public T::tBase
{
public:
	//! Base types.
	typedef typename T::tBase tBase;
	typedef typename tBase::tResult tResult;
	typedef typename tBase::tParam1 tParam1;
	typedef typename tBase::tParam2 tParam2;
	typedef typename tBase::tParam3 tParam3;
	typedef typename tBase::tParam4 tParam4;

public:
	//! Constructor.
	CFuncHandler(F Func) : m_Func(Func) {}

	//! Function operators.
	tResult operator()()
	{
		return m_Func();
	}
	tResult operator()(tParam1 p1)
	{
		return m_Func(p1);
	}
	tResult operator()(tParam1 p1, tParam2 p2)
	{ 
		return m_Func(p1, p2);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3)
	{
		return m_Func(p1, p2, p3);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4)
	{
		return m_Func(p1, p2, p3, p4);
	}


    //! Creates a new copy of the functor object.
    tBase *clone() const
    {
        return new CFuncHandler(m_Func);
    }

private:
	//! Pointer to the function or functor.
	F m_Func;
};


//==============================================================================
/*!
 * Wraps pointers to member functions.
 * - Parameter T is a parent functor.
 * - Parameter O is pointer to an object.
 * - M is pointer to the object member function.
 */
template <class T, typename O, typename F>
class CMemFuncHandler : public T::tBase
{
public:
	//! Base types.
	typedef typename T::tBase tBase;
	typedef typename tBase::tResult tResult;
	typedef typename tBase::tParam1 tParam1;
	typedef typename tBase::tParam2 tParam2;
	typedef typename tBase::tParam3 tParam3;
	typedef typename tBase::tParam4 tParam4;

public:
	//! Constructor.
	CMemFuncHandler(const O& pObject, F pMemFunc)
		: m_pObject(pObject)
		, m_pMemFunc(pMemFunc)
	{}

	//! Function operators.
	tResult operator()()
	{
		return ((*m_pObject).*m_pMemFunc)();
	}
	tResult operator()(tParam1 p1)
	{
		return ((*m_pObject).*m_pMemFunc)(p1);
	}
	tResult operator()(tParam1 p1, tParam2 p2)
	{
		return ((*m_pObject).*m_pMemFunc)(p1, p2);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3)
	{
		return ((*m_pObject).*m_pMemFunc)(p1, p2, p3);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4)
	{
		return ((*m_pObject).*m_pMemFunc)(p1, p2, p3, p4);
	}


    //! Creates a new copy of the functor object.
    tBase *clone() const
    {
        return new CMemFuncHandler(m_pObject, m_pMemFunc);
    }

private:
	//! Pointer to the object.
    O m_pObject;
    
    //! Pointer to the member function.
    F m_pMemFunc;
};


//==============================================================================
/*!
 * Generalized functor implementation.
 * - Allowed are up to four arguments.
 */
template <typename R,
          typename P1 = tNull, typename P2 = tNull,
          typename P3 = tNull, typename P4 = tNull
          >
class CFunctor
{
public:
	//! Type definitions.
	typedef CFunctorBase<R, P1, P2, P3, P4> tBase;
	typedef typename tBase::tResult tResult;
	typedef typename tBase::tParam1 tParam1;
	typedef typename tBase::tParam2 tParam2;
	typedef typename tBase::tParam3 tParam3;
	typedef typename tBase::tParam4 tParam4;

    //! Number of parameters
    enum { NUM_OF_PARAMS = tBase::NUM_OF_PARAMS };

public:
    //! Default constructor.
	CFunctor() {}
	
	//! Copy constructor.
	CFunctor(const CFunctor& Functor)
	{
	    if( Functor.m_spImpl.get() )
        {
            m_spImpl = Functor.m_spImpl->clone();
        }
    }
	
	//! Constructor creates functor encapsulating any function.
	template <typename F>
	CFunctor(F Func)
		: m_spImpl(new CFuncHandler<CFunctor, F>(Func))
	{}

	//! Constructor creates functor encapsulating pointer to member function.
	template <class O, typename F>
	CFunctor(const O& pObject, F pMemFunc)
		: m_spImpl(new CMemFuncHandler<CFunctor, O, F>(pObject, pMemFunc))
	{}

    //! Assignment operator.
	CFunctor& operator=(const CFunctor& Functor)
	{
        if( this != &Functor )
        {
    	    if( Functor.m_spImpl.get() )
            {
                m_spImpl = Functor.m_spImpl->clone();
            }
            else
            {
                m_spImpl.destroy();
            }
        }
		return *this;
    }

    //! Function operators.
	tResult operator()()
	{
		return (*m_spImpl)();
	}
	tResult operator()(tParam1 p1)
	{
		return (*m_spImpl)(p1);
	}
	tResult operator()(tParam1 p1, tParam2 p2)
	{
		return (*m_spImpl)(p1, p2);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3)
	{
		return (*m_spImpl)(p1, p2, p3);
	}
	tResult operator()(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4)
	{
		return (*m_spImpl)(p1, p2, p3, p4);
	}

private:
	//! Pointer to the functor implementation.
	mds::base::CScopedPtr<tBase> m_spImpl;
};


} // namespace base
} // namespace mds

#endif  // MDS_Functor_H
