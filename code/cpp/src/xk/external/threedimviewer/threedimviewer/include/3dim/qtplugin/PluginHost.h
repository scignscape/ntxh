////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////

#ifndef PluginHost_H
#define PluginHost_H


///////////////////////////////////////////////////////////////////////////////
// Global definitions

//! Macro declares name of the host application.
#if defined(PLUGIN_EASYDENT_3DIM)
#   define PLUGIN_HOST_3DIM "EasyDent"
#elif defined(PLUGIN_VIEWER_3DIM)
#   define PLUGIN_HOST_3DIM "3DimViewer"
#elif defined(PLUGIN_DENTALVIEWER_3DIM)
#   define PLUGIN_HOST_3DIM "DentalViewer"
#else
#   error Cannot compile the plugin, host application is not declared!
#endif


#endif // PluginHost_H
