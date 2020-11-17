#ifndef IQMOL_LAYER_CLIPPINGPLANE_H
#define IQMOL_LAYER_CLIPPINGPLANE_H
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

#include "GLObjectLayer.h"
#include "ClippingPlaneConfigurator.h"

namespace IQmol {
namespace Layer {

   class ClippingPlane : public GLObject {

      Q_OBJECT
      friend class Configurator::ClippingPlane;

      public:
         ClippingPlane();
         ~ClippingPlane();

         void draw();
         void drawSelected();
         void setEquation();

         qglviewer::Vec normal() const;
         double distance() const;
  
      public Q_SLOTS:
         void setSceneRadius(double const radius) { m_sceneRadius = radius; }

      private:
         double m_sceneRadius;
        
         void drawPrivate();
         void drawArrow(double const length, double const radius = -1.0f,
            int const resolution = 24);

         Configurator::ClippingPlane* m_configurator;
   };

} } // end namespace IQmol::Layer

#endif
