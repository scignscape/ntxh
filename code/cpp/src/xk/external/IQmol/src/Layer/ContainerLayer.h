#ifndef IQMOL_LAYER_CONTAINER_H
#define IQMOL_LAYER_CONTAINER_H
/*******************************************************************************

  Copyright (C) 2011-2015 Andrew Gilbert

  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.

  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************/

#include "Layer.h"


namespace IQmol {
namespace Layer {

   /// Template Layer that holds a list of other Layers of a single type. 
   /// Container Layers are unattached when empty, and automatically attach
   /// themselves to the persistent parent when children are added. 
   class Container : public Base {

      Q_OBJECT

      public:
		 Container(Layer::Base* parent, QString const& label);
   };


} } // end namespace IQmol::Layer

#endif
