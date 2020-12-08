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

#ifndef VPL_LogFilters_H
#define VPL_LogFilters_H

#include "SharedPtr.h"
#include <VPL/Base/LogRecord.h>
#include <vector>

namespace vpl
{
namespace base
{

/**
 * Log filter class is used to filter log records - it evaluates, if given log record should be processed (or not).
 * Filter is called only if it is enabled (enable method). Filter response can be:
 * accepted - record is accepted and no further testing is needed
 * rejected - record is rejected and no further testing is needed
 * neutral - (small acceptance) - record is not rejected and if no other opinion (from the another filter), it should be accepted
**/
class CLogFilter
	: public CObject
{
public:
	enum EFilterResponse
	{
		accepted, rejected, neutral
	};

	VPL_SHAREDPTR(CLogFilter);

public:
	//! Constructor
	CLogFilter(const std::string & str_id, EFilterResponse acceptResponse, EFilterResponse rejectResponse = rejected) 
		: m_acceptResponse(acceptResponse), m_rejectResponse(rejectResponse), m_strId(str_id), m_bEnabled(true) {}

	//! Test log record by filter
	virtual EFilterResponse operator()(const CLogRecord &record) = 0;

	//! Get filter name
	const std::string &getName() const {return m_strId;}

	//! Enable/disable filter
	void enable(bool bEnabled) {m_bEnabled = bEnabled;}

protected:
	//! Protected copy constructor.
	CLogFilter(const CLogFilter&);

	//! Protected assignment operator.
	void operator=(const CLogFilter&);

protected:
	//! Acceptation response
	EFilterResponse m_acceptResponse;

	//! Rejection response
	EFilterResponse m_rejectResponse;

	//! String id
	std::string m_strId;

	//! Is filter enabled
	bool m_bEnabled;
};

//! Log filter shared ptr
typedef CLogFilter::tSmartPtr     CLogFilterPtr;


/**
 * Filter log records by given level threshold. 
**/
class CLogFilterByLevel : public CLogFilter
{
public:
	VPL_SHAREDPTR(CLogFilterByLevel);

public:
	//! Constructor
	CLogFilterByLevel(int level, const std::string & str_id = "", EFilterResponse acceptResponse = neutral, EFilterResponse rejectResponse = rejected)
		: CLogFilter(str_id, acceptResponse, rejectResponse), m_level(level) {}

	//! Set testing threshold
	void setLevel(int level) { m_level = level; }

	//! Test only level by filter
	virtual EFilterResponse operator()(size_t level) 
		{if(!m_bEnabled) return neutral; if(level < m_level) return m_rejectResponse; return m_acceptResponse; }

	//! Test log record by filter
	virtual EFilterResponse operator()(const CLogRecord &record) 
		{if(!m_bEnabled) return neutral; if(record.getLevel() < m_level) return m_rejectResponse; return m_acceptResponse; }

protected:
	//! Protected copy constructor.
	CLogFilterByLevel(const CLogFilterByLevel&);

	//! Protected assignment operator.
	void operator=(const CLogFilterByLevel&);

protected:
	//! Testing threshold
	size_t m_level;

};

//! Log filter shared ptr
typedef CLogFilterByLevel::tSmartPtr     CLogFilterByLevelPtr;

/**
 * Log filter by type. 
**/
class CLogFilterByType : public CLogFilter
{
public:
	VPL_SHAREDPTR(CLogFilterByType);

public:
	//! Constructor
	CLogFilterByType(int mask, const std::string & str_id = "", EFilterResponse acceptResponse = neutral, EFilterResponse rejectResponse = rejected)
		: CLogFilter(str_id, acceptResponse, rejectResponse), m_mask(mask) {}

	//! Set testing mask
	void setMask(int mask) {m_mask = mask;}

	//! Test log record by filter
	virtual EFilterResponse operator()(const CLogRecord &record) 
	{if(!m_bEnabled) return neutral; if((record.getLevel() & m_mask) == 0 ) return m_rejectResponse; return m_acceptResponse; }

protected:
	//! Protected copy constructor.
	CLogFilterByType(const CLogFilterByType&);

	//! Protected assignment operator.
	void operator=(const CLogFilterByType&);

protected:
	//! Testing mask
	int m_mask;
};

//! Log filter shared ptr
typedef CLogFilterByType::tSmartPtr     CLogFilterByTypePtr;

/**
 * Filter pool. 
 *
 * Pool associates multiple filters. Filtering logic is - if no filter rejects record, use it. 
**/
class CLogFilterPool
	: public CLogFilter
{
protected:
	//! Filters vector type
	typedef std::vector<CLogFilterPtr> tFilterPtrVec;

public:
	VPL_SHAREDPTR(CLogFilterPool);

	//! Constructor
	CLogFilterPool(bool enabled = true, const std::string & str_id = "") 
		: CLogFilter(str_id, accepted, rejected), m_poolEnabled(enabled) {} // Response settings doesn't matter - internal filters return value is used or neutral is returned

	//! Add filter
	virtual bool addFilter(CLogFilter *filter, bool replace = true);

    //! Gets first filter by name
    virtual CLogFilter * getFilter(const std::string & name);

	//! Enable/disable filter
	virtual void enableFilter(const std::string &name, bool bEnable);

	//! Enable/disable all filters - set all filters status
	virtual void enableFilters(bool bEnable);

	//! Set pool filtering enabled/disabled
	virtual void enablePool(bool bEnable) {m_poolEnabled = bEnable;}

	//! Remove filter
	virtual void removeFilter(const std::string &name);

	//! Remove all filters
	virtual void removeAllFilters();

	//! Use filters on record and get response
	CLogFilter::EFilterResponse filter(const CLogRecord &rec);

	//! Use filters on record and get response
	virtual EFilterResponse operator()(const CLogRecord &record) {return filter(record);}

protected:
	//! Find filter by string id
	tFilterPtrVec::iterator findByStrId(const std::string &str_id);

	//! Protected copy constructor.
	CLogFilterPool(const CLogFilterPool&);

	//! Protected assignment operator.
	void operator=(const CLogFilterPool&);

protected:
	//! Filters
	tFilterPtrVec m_filters;

	//! Is pool filtering ability enabled?
	bool m_poolEnabled;
};

typedef CLogFilterPool::tSmartPtr CLogFilterPoolPtr;


} // namespace base
} // namespace vpl

#endif // VPL_LogFilters_H
