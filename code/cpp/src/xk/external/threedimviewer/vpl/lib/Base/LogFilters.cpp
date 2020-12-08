//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <VPL/Base/LogFilters.h>
#include <algorithm>

/**
 * Adds a filter to 'replace'.
 *
 * \param [in,out]	filter	If non-null, the filter.
 * \param	replace		  	true to replace.
 *
 * \return	true if it succeeds, false if it fails.
**/
bool vpl::base::CLogFilterPool::addFilter( CLogFilter *filter, bool replace /*= true*/ )
{
	if(filter == 0)
		return false;

	if(replace)
	{
		// try to find first filter with the same name
		tFilterPtrVec::iterator found(findByStrId(filter->getName()));

		// Replace if found
		if(found != m_filters.end())
		{
			*found = filter;
			return true;
		}

		// not found - continue to the classic push back
	}

	m_filters.push_back(filter);
	return true;
}

/**
 * Gets filter by name (first of its name).
 *
 * \param	name	The name.
**/
vpl::base::CLogFilter * vpl::base::CLogFilterPool::getFilter(const std::string & name)
{
    // try to find first filter with the given name
    tFilterPtrVec::iterator found(findByStrId(name));

    // Set filter status
    if (found != m_filters.end())
    {
        return *found;
    }
    else
    {
        return nullptr;
    }
}

/**
 * Enables the filter.
 *
 * \param	name	The name.
**/
void vpl::base::CLogFilterPool::enableFilter( const std::string &name, bool bEnable )
{
	// try to find first filter with the given name
	tFilterPtrVec::iterator found(findByStrId(name));

	// Set filter status
	if(found != m_filters.end())
		(*found)->enable(bEnable);
}

/**
 * Enables the filters - set all stored filters enabled status.
 *
 * \param	bEnable	true to enable, false to disable.
**/
void vpl::base::CLogFilterPool::enableFilters( bool bEnable )
{
	tFilterPtrVec::iterator it(m_filters.begin()), itEnd(m_filters.end());
	for(; it != itEnd; ++it)
		(*it)->enable(bEnable);
}

/**
 * Removes the filter described by name.
 *
 * \param	name	The name.
**/
void vpl::base::CLogFilterPool::removeFilter( const std::string &name )
{
	// try to find first filter with the given name
	tFilterPtrVec::iterator found(findByStrId(name));

	if(found != m_filters.end())
		m_filters.erase(found);
}

/**
 * Removes all filters.
**/
void vpl::base::CLogFilterPool::removeAllFilters()
{
	m_filters.clear();
}

/**
 * Filters given log record.
 *
 * \param	rec	The record.
 *
 * \return	Accepted, rejected, neutral.
**/
vpl::base::CLogFilter::EFilterResponse vpl::base::CLogFilterPool::filter( const CLogRecord &rec )
{
	// If not enabled, do nothing
	if(!m_poolEnabled)
		return CLogFilter::neutral;

	// Iterate filters and find "hard answer" - rejected or accepted
	tFilterPtrVec::iterator it(m_filters.begin()), itEnd(m_filters.end());
	for(; it != itEnd; ++it)
	{
		CLogFilter::EFilterResponse response((*it)->operator()(rec));
		
		if(response != CLogFilter::neutral)
			return response;
	}

	// Only neutral responses - return neutral
	return CLogFilter::neutral;
}

/**
 * Searches for the first filter of the given name.
 *
 * \param	str_id	string identifier of the filter.
 *
 * \return	The iterator to the filter found by string identifier.
**/
vpl::base::CLogFilterPool::tFilterPtrVec::iterator 
	vpl::base::CLogFilterPool::findByStrId( const std::string &str_id )
{
	std::string id(str_id);
	return std::find_if(m_filters.begin(), m_filters.end(), [&id](const CLogFilter *filter){return filter->getName() == id;});
}
