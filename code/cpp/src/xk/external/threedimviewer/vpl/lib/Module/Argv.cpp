//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/11                       
 * 
 * Description:
 * - Command line arguments parser.
 */

#include <VPL/Module/Argv.h>

#include <VPL/Base/Setup.h>
#include <VPL/Base/Warning.h>

#include <cstdlib>
#include <cctype>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Global definitions.
 */

//! Finite automaton (parser) states.
enum EParserState
{
    ARGV_PARSER_ARGUMENT,
    ARGV_PARSER_VALUE,
    ARGV_PARSER_SVALUE,
    ARGV_PARSER_END
};


//==============================================================================
/*
 * Implementation of the class vpl::mod::CArgv.
 */
CArgv::CArgv(int argc, char *argv[])
{
    // Parse the command line arguments
    if( !parse(argc, argv) )
    {
        VPL_THROW_WARNING("Constructor CArgv::CArgv() failed");
    }
}


CArgv::~CArgv()
{
    clear();
}


bool CArgv::parse(int argc, char *argv[])
{
    // Parser state
    EParserState State = ARGV_PARSER_ARGUMENT;

    // Current argument index, label and value
    std::string sLabel, sValue;
    int i = 1;

    // Read arguments 1, 2, ...
    while( State != ARGV_PARSER_END )
    {
        switch( State )
        {
            // Find out the argument type
            case ARGV_PARSER_ARGUMENT:
                if( i >= argc )
                {
                    State = ARGV_PARSER_END;
                }
                else if( argv[i][0] == '-' && isalpha(argv[i][1]) )
                {
                    sLabel = (char *)&argv[i][1];
                    State = ARGV_PARSER_VALUE;
                    ++i;
                }
                else if( isgraph(argv[i][0]) && argv[i][0] != '-' )
                {
                    State = ARGV_PARSER_SVALUE;
                }
                else
                {
                    return false;
                }
                break;

            // Read labeled argument sValue
            case ARGV_PARSER_VALUE:
                if( i >= argc )
                {
                    if( !exists(sLabel) )
                    {
                        m_LArguments[sLabel] = "";
                    }
                    State = ARGV_PARSER_END;
                }
                else if( isgraph(argv[i][0]) && !exists(sLabel) )
                {
                    if( argv[i][0] == '-' && isalpha(argv[i][1]) )
                    {
                        m_LArguments[sLabel] = "";
                        State = ARGV_PARSER_ARGUMENT;
                    }
                    else
                    {
                        m_LArguments[sLabel] = argv[i];
                        State = ARGV_PARSER_ARGUMENT;
                        ++i;
                    }
                }
                else
                {
                    return false;
                }
                break;

            // Read simple argument sValue
            case ARGV_PARSER_SVALUE:
                sValue = argv[i];
                m_SArguments.push_back(sValue);
                State = ARGV_PARSER_ARGUMENT;
                ++i;
                break;
    
            default:
                return false;
                break;
            }
    }

    // O.K.
    return true;
}


void CArgv::clear()
{
    m_LArguments.clear();
    m_SArguments.clear();
}


bool CArgv::check(const std::string& sArgs) const
{
    // Separated allowed command line arguments
    std::set<std::string> AllowedArgs;

    // Create a set of arguments
    std::string sName;
    for( std::size_t i = 0; i < sArgs.length(); ++i )
    {
        if( sArgs[i] == ':' && sName.length() > 0 )
        {
            AllowedArgs.insert(sName);
            sName.erase();
        }
        else
        {
            sName += sArgs[i];
        }
    }
    if( sName.length() > 0 )
    {
        AllowedArgs.insert(sName);
    }

    // Test if parsed arguments are allowed
    tLArguments::const_iterator it = m_LArguments.begin();
    tLArguments::const_iterator itEnd = m_LArguments.end();
    while( it != itEnd )
    {
        if( AllowedArgs.find(it->first) == AllowedArgs.end() )
        {
            return false;
        }
        ++it;
    }

    // O.K.
    return true;
}


bool CArgv::exists(const std::string& sLabel) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    return i != m_LArguments.end();
}


bool CArgv::value(const std::string& sLabel, std::string& sValue) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    if( i != m_LArguments.end() )
    {
        sValue = i->second;
        return true;
    }
    return false;
}


bool CArgv::value(const std::string& sLabel, char& cValue) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    if( i != m_LArguments.end() )
    {
        cValue = i->second[0];
        return true;
    }
    return false;
}


bool CArgv::value(const std::string& sLabel, unsigned& uValue) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    if( i != m_LArguments.end() )
    {
        uValue = (unsigned int)atol(i->second.c_str());
        return true;
    }
    return false;
}


bool CArgv::value(const std::string& sLabel, int& iValue) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    if( i != m_LArguments.end() )
    {
        iValue = atoi(i->second.c_str());
        return true;
    }
    return false;
}


#ifdef VPL_USE_64BIT_SIZE_TYPE

bool CArgv::value(const std::string& sLabel, tSize& Value) const
{
	tLArguments::const_iterator i = m_LArguments.find(sLabel);
	if (i != m_LArguments.end())
	{
		Value = atoi(i->second.c_str());
		return true;
	}
	return false;
}

#endif // VPL_USE_64BIT_SIZE_TYPE


bool CArgv::value(const std::string& sLabel, double& dValue) const
{
    tLArguments::const_iterator i = m_LArguments.find(sLabel);
    if( i != m_LArguments.end() )
    {
        dValue = atof(i->second.c_str());
        return true;
    }
    return false;
}


bool CArgv::simpleValue(int i, std::string& sValue) const
{
    if( i >= (int)m_SArguments.size() )
    {
        sValue = m_SArguments[i];
        return true;
    }
    return false;
}


} // namespace mod
} // namespace vpl

