#ifndef IQMOL_LAYER_GLOBJECT_H
#define IQMOL_LAYER_GLOBJECT_H
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
#include "QGLViewer/vec.h"
#include "QGLViewer/frame.h"
#include "QGLViewer/quaternion.h"
#include <QList>


namespace IQmol {

class ManipulatedFrameSetConstraint;
class PovRayGen;
class ClippingPlane;

namespace Layer {

   /// Abstract base class for any item that can be draw on the GL canvas.
   /// Derived classes must implement a draw() function and, where the
   /// appearance depends on the camera orientation, draw(cameraPosition) 
   /// should also be implemented.  An example of this is when double Bonds 
   /// are drawn (see BondLayer.h).
   ///
   /// GLObjects can also be selected and have transparency.  Transparency is
   /// implemented at this level to allow alpha sorting of all GLObjects to
   /// determine their draw order.
   class GLObject : public Base {

      Q_OBJECT

      friend class IQmol::ManipulatedFrameSetConstraint;

      public: 
         /// Note the constructor does not allow a QObject parent.  This
         /// means the destruction of GLObjects must be taken care of 
         /// explicitly and not through the Qt mechanism.
         explicit GLObject(QString const& text = QString()) : Base(text), m_alpha(1.0),
            m_clip(false)
         { 
            setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
          }

         virtual ~GLObject() {  }

		 /// This is the key function for GLObjects and must be implemented
		 /// for the object to be able to be drawn on the GL canvas. 
         virtual void draw() 
         {
            glPushMatrix();
            glMultMatrixd(m_frame.matrix());
            glCallList(m_callList);
            glPopMatrix();
         }

		 /// Reimplement this for complex objects that require simplified
		 /// drawing when moving to maintain interactive frame rates.
         virtual void drawFast() 
         {
            glPushMatrix();
            glMultMatrixd(m_frame.matrix());
            glCallList(m_fastCallList);
            glPopMatrix();
         } 

         /// Reimplement this for objects that should appear different when 
         /// selected.  This is called after the object has been drawn and
         /// in most cases this function just needs to draw a transparent 
         /// 'halo' around the object.
         virtual void drawSelected() {
            glPushMatrix();
            glMultMatrixd(m_frame.matrix());
            glCallList(m_selectedCallList);
            glPopMatrix();
         }

         virtual void select()   { setProperty(Selected);   }
         virtual void deselect() { unsetProperty(Selected); }
         bool isSelected() const { return hasProperty(Selected); }

         virtual void povray(PovRayGen&) { }

         virtual void setAlpha(double alpha) { m_alpha = alpha; }
         virtual double getAlpha() const { return m_alpha; }

         qglviewer::Frame getFrame() const { return m_frame; }

         qglviewer::Vec getPosition() { return m_frame.position(); }
         qglviewer::Quaternion getOrientation() { return m_frame.orientation(); }
         qglviewer::Vec getTranslation() { return m_frame.translation(); }
         qglviewer::Quaternion getRotation() { return m_frame.rotation(); }


		 /// Basic implmentation of an alpha sort so transparent objects can be
		 /// drawn last so that they are not eclipsed.
         static bool AlphaSort(GLObject* a, GLObject* b) 
         { 
            return (a->getAlpha() > b->getAlpha()); 
         }

         /// This should be called just before a draw of the whole scene.
         static void SetCameraPosition(qglviewer::Vec const& position) 
         { 
            s_cameraPosition = position; 
         }

         /// This should be called just before a draw of the whole scene.
         static void SetCameraDirection(qglviewer::Vec const& direction) 
         { 
            s_cameraDirection = direction; 
         }

         /// This should be called just before a draw of the whole scene.
         static void SetCameraPivot(qglviewer::Vec const& pivot) 
         { 
            s_cameraPivot = pivot; 
         }


      public Q_SLOTS:
         virtual void setReferenceFrame(qglviewer::Frame* frame) { 
            m_frame.setReferenceFrame(frame); 
         }

         virtual void setFrame(qglviewer::Frame const& frame) {
            m_frame = frame;
         }

         virtual void setPosition(qglviewer::Vec const& position) {
            m_frame.setPosition(position); 
         }

         virtual void setOrientation(qglviewer::Quaternion const& orient) {
            m_frame.setOrientation(orient); 
         }

         virtual void setTranslation(qglviewer::Vec const& translation) {
            m_frame.setTranslation(translation); 
         }

         virtual void setRotation(qglviewer::Quaternion const& rotation) {
            m_frame.setRotation(rotation); 
         }



      protected:
         static qglviewer::Vec s_cameraPosition;
         static qglviewer::Vec s_cameraDirection;
         static qglviewer::Vec s_cameraPivot;
         qglviewer::Frame m_frame;
         double m_alpha;   
         GLuint m_callList;
         GLuint m_fastCallList;
         GLuint m_selectedCallList;
         bool   m_clip;
   };

} // end namespace Layer

typedef QList<Layer::GLObject*> GLObjectList;

} // end namespace IQmol

#endif
