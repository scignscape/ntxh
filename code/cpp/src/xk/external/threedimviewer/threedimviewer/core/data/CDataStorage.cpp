﻿///////////////////////////////////////////////////////////////////////////////
// $Id$
//
// 3DimViewer
// Lightweight 3D DICOM viewer.
//
// Copyright 2008-2016 3Dim Laboratory s.r.o.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include <data/CDataStorage.h>
#include <data/CStorageEntry.h>

#include <VPL/Base/Logging.h>
#include <VPL/System/Sleep.h>

#define STORAGE_ENTRY_CLASS_FLAGS		16

//#define DEBUG_OUTPUT_INITIALIZATION

namespace data
{

///////////////////////////////////////////////////////////////////////////////
//

CDataStorage::CDataStorage() : m_pFactory(NULL), m_bCanInvalidate(true)
{
    for( int i = 0; i <= Storage::MAX_ID; ++i )
    {
        m_Storage.push_back(CStorageEntry::tSmartPtr(new CStorageEntry));
    }
}

///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::invalidate(CStorageEntry *pEntry, int Flags)
{
    if( !pEntry )
    {
        return;
    }

	if( !m_bCanInvalidate )
	{
		fakeInvalidate( pEntry, Flags);
		return;
	}

//    tLock Lock(*this);

    // Make the entry dirty
    pEntry->makeDirty(pEntry->getId(), Flags);

    // Invalidate all dependent entries
    CEntryDeps Invalidated;
    invalidateDeps(pEntry, Invalidated, Flags);

    // Should all dependent entries be updated now?
    if( Flags & Storage::FORCE_UPDATE )
    {
        Invalidated.forEach(SUpdateDeps(m_Storage));
    }

    // Notify observers of the root entry about the change
    pEntry->notify();

    // Notify observers of dependent 
    Invalidated.forEach(SNotifyDeps(m_Storage));

    if( Flags & Storage::FORCE_UPDATE )
    {
        pEntry->clearDirty();
    }
}


///////////////////////////////////////////////////////////////////////////////
//

CPtrWrapper<CStorageEntry> CDataStorage::getEntry(int Id, int Flags)
{
    if( !checkId(Id) )
    {
		VPL_LOG_INFO("CDataStorage::getEntry(): checkId failed, Id = " << Id);
        throw Storage::CUnknowEntry();
    }

    // Get pointer to the entry
    CStorageEntry *pEntry = m_Storage[Id].get();
    assert(NULL!=pEntry);

    // Is the entry initialized?
    if( pEntry->getId() != Id )
    {
         tLock Lock(*this);
         
         // Check the entry again
         if( pEntry->getId() != Id )
         {
#ifdef DEBUG_OUTPUT_INITIALIZATION
  #ifdef _WIN32
             // output storage entry id
             {
                 std::stringstream ss;
                 ss << "Initializing storage entry " << Id << " ";
                 std::string str = ss.str();
                 OutputDebugStringA(str.c_str());
             }
  #endif
#endif
             // Set the entry Id
             pEntry->setId(Id);
             
             // Create and initialize the data
             if( Flags & Storage::CREATE )
             {
                 // Create entry data
                 CStorableData *pData = getFactory().create(Id);
                 pData->init();
                 pEntry->setDataPtr(pData);
                 
                 // Update the entry data immediately
                 try {
                     pEntry->update();
                 }
                 catch( const vpl::base::CException& Exception )
                 {
                     VPL_LOG_INFO("CDataStorage::getEntry(): " << Exception.what() << ", Id = " << pEntry->getId());
                 }
             }

#ifdef DEBUG_OUTPUT_INITIALIZATION
  #ifdef _WIN32
             // output class name
             if (NULL!=pEntry->getStorableDataPtr())
             {
                 std::stringstream ss;
                 ss << " " << typeid(*pEntry->getStorableDataPtr()).name();
                 std::string str = ss.str();
                 OutputDebugStringA(str.c_str());
             }
             else
                 OutputDebugStringA(" null data");             

             // output thread id
             if(0){
                 std::stringstream ss;
                 ss << " thread " << GetCurrentThreadId();
                 std::string str = ss.str();
                 OutputDebugStringA(str.c_str());
             }
             OutputDebugStringA("\n");
  #endif
#endif
             
             // Update reverse dependencies
             createReverseDeps(Id, getFactory().getDeps(Id));
         }
    }

    // Return the found entry
    return CPtrWrapper<CStorageEntry>(pEntry, Flags);
}


///////////////////////////////////////////////////////////////////////////////
//

bool CDataStorage::isEntryValid(int Id)
{
    if( !checkId(Id) )
    {
        return false;
    }

    // Get pointer to the entry
    CStorageEntry *pEntry = m_Storage[Id].get();

    // Is the entry initialized?
    return (pEntry && pEntry->getId() == Id && pEntry->getStorableDataPtr());
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::createReverseDeps(int Id, const CEntryDeps& Deps)
{
    Deps.forEach(SBuildDeps(m_Storage, Id));
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::invalidateDeps(CStorageEntry *pRoot, CEntryDeps& List, int Flags)
{
    CEntryDeps Deps;
    pRoot->getDeps(Deps);

    CEntryDeps::tDeps::iterator itEnd = Deps.getImpl().end();
    for( CEntryDeps::tDeps::iterator it = Deps.getImpl().begin(); it != itEnd; ++it )
    {
        CStorageEntry *pEntry = m_Storage[*it].get();

        // Evaluate the dependency
        if( pEntry->checkDependency(pRoot) )
        {
            // Add entry to the output list
            List.insert(*it);

            // Make the entry dirty
            pEntry->makeDirty(pRoot->getId(), Flags);

            // Invalidate all child nodes
			const int depsInvalidateFlags = Flags & (-1 - ((1 << STORAGE_ENTRY_CLASS_FLAGS) - 1) ); // clear class specific flags, because they were valid for pRoot, but not for pEntry
            invalidateDeps(pEntry, List, depsInvalidateFlags);
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::connect(int Id, CEntryObserver *pObserver)
{
    if( !checkId(Id) )
    {
        return;
    }

    // Register the observer
    m_Storage[Id]->connect(pObserver);
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::disconnect(int Id, CEntryObserver *pObserver)
{
    if( !checkId(Id) )
    {
        return;
    }

    // Register the observer
    m_Storage[Id]->disconnect(pObserver);
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::block(int Id, CEntryObserver *pObserver)
{
    if( !checkId(Id) )
    {
        return;
    }

    m_Storage[Id]->block(pObserver);
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::unblock(int Id, CEntryObserver *pObserver)
{
    if( !checkId(Id) )
    {
        return;
    }

    m_Storage[Id]->unblock(pObserver);
}


///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::reset()
{
    tLock Lock(*this);

    tStorage::iterator it, itEnd = m_Storage.end();

    // drop all pending changes, because "old" changes can break flag checking
    for (it = m_Storage.begin(); it != itEnd; ++it)
    {
        CStorageEntry *pEntry = it->get();
        if (pEntry->getId() == Storage::UNKNOWN)
            continue;
        if (pEntry->isDirty())
        {
            // Clear the dirty flag and actualize the version number
            pEntry->clearDirty();
        }        
    }

    // Invalidated dependent entries
    CEntryDeps Invalidated;

    // First reset all root entries    
    for( it = m_Storage.begin(); it != itEnd; ++it )
    {
        CStorageEntry *pEntry = it->get();
        if( pEntry->getId() == Storage::UNKNOWN )
        {
            continue;
        }
        
        // If this is a root entry then invalidate it...
        if( getFactory().getDeps(pEntry->getId()).isEmpty() )
        {
            // Initialize the data
            pEntry->init();

            // Make the entry dirty
            pEntry->makeDirty( pEntry->getId(), Storage::STORAGE_RESET );

            // Invalidate all child entries
            Invalidated.insert( pEntry->getId() );
            invalidateDeps( pEntry, Invalidated, Storage::STORAGE_RESET );
        }
    }

    // Check if all the entries were reset
    /*for( it = m_Storage.begin(); it != itEnd; ++it )
    {
        CStorageEntry *pEntry = it->get();
        if( pEntry->getId() == Storage::UNKNOWN )
        {
            continue;
        }

        if( !Invalidated.contains(pEntry->getId()) )
        {
            // Initialize the data
            pEntry->init();

            // Make the entry dirty
            pEntry->makeDirty( pEntry->getId(), Storage::STORAGE_RESET );

            // Invalidate the entry
            Invalidated.insert( pEntry->getId() );
            invalidateDeps( pEntry, Invalidated, Storage::STORAGE_RESET );
        }
    }*/

    // Notify observers of all entries
    Invalidated.forEach( SNotifyDeps(m_Storage) );

    /* update all dirty entries - we perform storage reset and deserialization without updates in between,
       that causes that objects receive sequence of changes including the change with STORAGE_RESET and some objects
       therefore reset themselves after deserialization which is of course bad  */
    for (it = m_Storage.begin(); it != itEnd; ++it)
    {
        CStorageEntry *pEntry = it->get();
        if (pEntry->getId() == Storage::UNKNOWN)
        {
            continue;
        }
        if (pEntry->isDirty())
        {
            pEntry->update();
            pEntry->notify();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::doPostponedInvalidation(bool bForceUpdate)
{
	CStorageEntry *pEntry;

    tInvalidatedOrderVec invalidationOrder = m_invalidationOrder;
    tInvalidatedEntriesMap invalidatedEntries = m_invalidatedEntries;
    tInvalidatedEntriesMap invalidatedDeps = m_invalidatedDeps;
    m_invalidationOrder.clear();
    m_invalidatedEntries.clear();
    m_invalidatedDeps.clear();

	// Invalidate really invalidated entries 
	{
		tInvalidatedOrderVec::iterator it, itEnd( invalidationOrder.end() );
		for( it = invalidationOrder.begin(); it != itEnd; ++it )
		{
			pEntry = m_Storage[*it].get();

			if( !pEntry )
			{
				// Something wrong has happen
				continue;
			}

			// Copy changes, make the entry dirty
            pEntry->addChanges(invalidatedEntries[*it]);

			// Should all dependent entries be updated now?
			if( bForceUpdate )
			{
				pEntry->update();
			}

			pEntry->notify();
		}
	}

	// Invalidate deps
	//*
	// For all "invalidated" entries
	{
        tInvalidatedEntriesMap::iterator it, itEnd(invalidatedDeps.end());
        for (it = invalidatedDeps.begin(); it != itEnd; ++it)
		{
			pEntry = m_Storage[it->first].get();

			if( !pEntry )
			{
				// Something wrong has happen
				continue;;
			}

			// Copy changes, make the entry dirty
			pEntry->addChanges( it->second );

			// Should all dependent entries be updated now?
			if( bForceUpdate )
			{
				pEntry->update();
			}

			pEntry->notify();
		}
    }
	//*/
}

///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::unlockInvalidation()
{
    tLock Lock(*this);

    m_bCanInvalidate = true;
	doPostponedInvalidation(false);
}

///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::fakeInvalidate( CStorageEntry *pEntry, int Flags /*= 0*/ )
{
    if( !pEntry )
    {
        return;
    }

    tLock Lock(*this);

    // Make the entry dirty - store info
	int id = pEntry->getId();

	// If entry is not yet in the invalidation order
	if( m_invalidatedEntries.find( id ) == m_invalidatedEntries.end() )
	{
		m_invalidationOrder.push_back(id);
	}

	m_invalidatedEntries[id].insert(id, Flags);

	// Invalidate all dependent entries	
	fakeInvaldateDeps(pEntry, Flags);
}

///////////////////////////////////////////////////////////////////////////////
//

void CDataStorage::fakeInvaldateDeps( CStorageEntry *pRoot, int Flags /*= 0*/ )
{
	CEntryDeps Deps;
	pRoot->getDeps(Deps);

	CEntryDeps::tDeps::iterator itEnd = Deps.getImpl().end();
	for( CEntryDeps::tDeps::iterator it = Deps.getImpl().begin(); it != itEnd; ++it )
	{
		CStorageEntry *pEntry = m_Storage[*it].get();

		// Evaluate the dependency
		if( pEntry && pEntry->checkDependency(pRoot) )
		{
            tLock Lock(*this);

			// Make the entry dirty and increase the version counter
			m_invalidatedDeps[pEntry->getId()].insert( pRoot->getId(), Flags );

			// "Invalidate all child nodes
			const int depsInvalidateFlags = Flags & (-1 - ((1 << STORAGE_ENTRY_CLASS_FLAGS) - 1) ); // clear class specific flags
			fakeInvaldateDeps(pEntry, depsInvalidateFlags);
		}
	}
}

void CDataStorage::lockInvalidation()
{
	if( m_bCanInvalidate ) 
	{
        tLock Lock(*this);

    	if( m_bCanInvalidate ) 
	    {
		    m_invalidatedDeps.clear();
		    m_invalidatedEntries.clear(); 
			m_invalidationOrder.clear();
		    m_bCanInvalidate = false;
        }
	}
}


} // namespace data
