//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/09/01                          \n
 *
 * $Id: mdsHasOptions.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Base class that encapsulates object-specific options (binary flags).
 */

#ifndef CHasOptions_H
#define CHasOptions_H

#include "mdsSetup.h"
#include "mdsBaseExport.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Base class that encapsulates object-specific options (binary flags).
 */
class MDS_BASE_EXPORT CHasOptions
{
public:
    //! Default constructor.
    CHasOptions(int Flags = 0) : m_Options(Flags) {}

    //! Copy constructor.
    CHasOptions(const CHasOptions& Flags) : m_Options(Flags.m_Options) {}

    //! Assignment operator.
    CHasOptions& operator =(const CHasOptions& Flags)
    {
        m_Options = Flags.m_Options;
        return *this;
    }

    //! Sets complete flags.
    CHasOptions& setOptions(int Flags)
    {
        m_Options = Flags;
        return *this;
    }

    //! Returns all flags.
    int getOptions() const { return m_Options; }

    //! Adds a given flag using bitwise OR operation.
    CHasOptions& addOption(int Flag)
    {
        m_Options |= Flag;
        return *this;
    }

    //! Adds a given flag using bitwise OR operation.
    CHasOptions& setOption(int Flag)
    {
        m_Options |= Flag;
        return *this;
    }

    //! Removes a given flag.
    CHasOptions& clearOption(int Flag)
    {
        m_Options &= ~Flag;
        return *this;
    }

    //! Checks if a single flag is set.
    //! - Returns zero on false.
    int checkOption(int Flag) const { return (m_Options & Flag); }

    //! Checks if all specified flags are set.
    bool checkAllOptions(int Flags) const { return ((m_Options & Flags) == Flags); }

    //! Checks if any of specified flags is set.
    bool checkAnyOption(int Flags) const { return ((m_Options & Flags) != 0); }

protected:
    //! Optional flags.
    int m_Options;
};


} // namespace base
} // namespace mds

#endif // CHasOptions_H
