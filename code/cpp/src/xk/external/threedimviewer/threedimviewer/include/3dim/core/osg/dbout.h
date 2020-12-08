///////////////////////////////////////////////////////////////////////////////
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

#ifndef DBOUT_H_INCLUDED
#define DBOUT_H_INCLUDED

#ifdef _MSC_VER

#include <windows.h>
#include <iostream>
#include <sstream>

//! Trace macro used to output debug information to the visual studio output window.
#define DBOUT( s )            \
    {                             \
    std::wostringstream os_;    \
    os_ << s << std::endl;                   \
    OutputDebugString( os_.str().c_str() );  \
    }

#define DBOUT_VEC(msg, v) DBOUT((msg) << (v)[0] << ", " << (v)[1] << ", " << (v)[2])
#define DBOUT_MTX(msg, m) \
        { \
        DBOUT(msg); \
        DBOUT(m(0, 0) << "\t" << m(0, 1) << "\t" << m(0, 2) << "\t" << m(0, 3)); \
        DBOUT(m(1, 0) << "\t" << m(1, 1) << "\t" << m(1, 2) << "\t" << m(1, 3)); \
        DBOUT(m(2, 0) << "\t" << m(2, 1) << "\t" << m(2, 2) << "\t" << m(2, 3)); \
        DBOUT(m(3, 0) << "\t" << m(3, 1) << "\t" << m(3, 2) << "\t" << m(3, 3)); \
        }
#else

#define DBOUT( s )
#define DBOUT_VEC( msg, v )
#define DBOUT_MTX( msg, m )

#endif

//DBOUT_H_INCLUDED
#endif 

