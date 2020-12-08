///////////////////////////////////////////////////////////////////////////////
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

/* NOTE from http://developer.qt.nokia.com/doc/qt-4.8/qglwidget.html
Note that under Windows, the QGLContext belonging to a QGLWidget has to be recreated
when the QGLWidget is reparented. This is necessary due to limitations on the Windows
platform. This will most likely cause problems for users that have subclassed and
installed their own QGLContext on a QGLWidget. It is possible to work around this
issue by putting the QGLWidget inside a dummy widget and then reparenting the dummy
widget, instead of the QGLWidget. This will side-step the issue altogether, and is
what we recommend for users that need this kind of functionality.

On Mac OS X, when Qt is built with Cocoa support, a QGLWidget can't have any sibling
widgets placed ontop of itself. This is due to limitations in the Cocoa API and is not
supported by Apple.
*/

#include "render/cvolumerendererwindow.h"

//#include <VPL/Base/Logging.h>

#include <base/Macros.h>
#include <osg/OSGCanvas.h>

#include <data/CAppSettings.h>

#include <osg/CAppMode.h>
#include <osg/CSceneManipulator.h>
#include <osg/OrthoManipulator.h>
#include <osg/CSceneOSG.h>
#include <osg/CScreenshot.h>
#include <osg/Version>

#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

#include <QMouseEvent>
#include <QApplication>

#include <QPinchGesture>
#include <QPanGesture>
#include <QGestureRecognizer>

/////////////////////////////////////////////////////////////////////////////////////////////////////

OSGCanvas::OSGCanvas(QWidget *parent) : QGLOSGWidget(parent, osg::Vec4(0, 0, 0, 0))
{
    // Sets the widget's clear color
    data::CObjectPtr<data::CAppSettings> settings( APP_STORAGE.getEntry(data::Storage::AppSettings::Id) );
    osg::Vec4 color( settings->getClearColor() );
    init(parent,color);

    grabGesture(Qt::GestureType::PinchGesture);
    //grabGesture(Qt::GestureType::PanGesture);
}

OSGCanvas::OSGCanvas(QWidget *parent, const osg::Vec4 &bgColor) : QGLOSGWidget(parent,bgColor)
{
    init(parent,bgColor);
}

void OSGCanvas::init(QWidget *parent, const osg::Vec4 &bgColor)
{
	m_customCursor = NULL;
    m_bRestoreModeOnMouseRelease = false;
	m_bShortcut = false;

    // set correct scene manipulator
    m_view->setCameraManipulator(new osg::CSceneManipulator());
    
    // Sets the widget's clear color
    setBackgroundColor(bgColor);

    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // set mouse tracking so we can extract continously density from a point under cursor
    setMouseTracking(true);

    m_Connection = APP_MODE.getModeChangedSignal().connect(this, &OSGCanvas::setCursorX);
}

OSGCanvas::~OSGCanvas()
{
    makeCurrent();
    APP_MODE.getModeChangedSignal().disconnect(m_Connection);
}

//! Centers and scales the scene.
void OSGCanvas::centerAndScale()
{
    QGLOSGWidget::centerAndScale();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Center and scale. 
//!
//!\param   box The box. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void OSGCanvas::centerAndScale( const osg::BoundingBox & box )
{
    // Try to get camera manipulator
    osg::CSceneManipulator * sm( dynamic_cast< osg::CSceneManipulator * >( m_view->getCameraManipulator() ) );

    if( sm != 0 )
    {
        sm->storeBB( box );
        sm->useStoredBox( true );

        m_view->getCameraManipulator()->home(0.0);
        Refresh(false);
    }
}

void OSGCanvas::restoreMouseMode(bool bForce)
{
    if (bForce || APP_MODE.isTempMode())
    {
        APP_MODE.restore();
        if (0!=(APP_MODE.get() & scene::CAppMode::COMMAND_MODE))
            APP_MODE.setDefault();		
        APP_MODE.enableHighlight(true);
		m_bShortcut = false;
    }
    m_bRestoreModeOnMouseRelease = false;
}

bool OSGCanvas::gestureEvent(QGestureEvent* event)
{
    QGesture *gesture = event->gesture(Qt::GestureType::PinchGesture);
    QPinchGesture *pinch = dynamic_cast<QPinchGesture *>(gesture);
    if (pinch != NULL)
    {
        double scale = pinch->totalScaleFactor();
        osg::Vec2 centerPoint = osg::Vec2(-pinch->centerPoint().x(), pinch->centerPoint().y());
        double rotationAngle = pinch->totalRotationAngle();

        if (pinch->scaleFactor() == pinch->lastScaleFactor())
        {
            m_lastScale = pinch->totalScaleFactor();
        }
        if (pinch->centerPoint() == pinch->lastCenterPoint())
        {
            m_lastCenter = osg::Vec2(-pinch->centerPoint().x(), pinch->centerPoint().y());
        }
        if (pinch->rotationAngle() == pinch->lastRotationAngle())
        {
            m_lastRotation = pinch->totalRotationAngle();
        }

        osg::CSceneManipulator *sceneManipulator = dynamic_cast<osg::CSceneManipulator *>(this->getView()->getCameraManipulator());
        osgGA::OrthoManipulator *orthoManipulator = dynamic_cast<osgGA::OrthoManipulator *>(this->getView()->getCameraManipulator());

        if ((sceneManipulator == NULL) && (orthoManipulator == NULL))
        {
            return false;
        }

        // ignore regular mouse input while gesture is used
        if (pinch->state() == Qt::GestureState::GestureStarted)
        {
            if (orthoManipulator != NULL)
            {
                orthoManipulator->setEnabled(false);
            }
            if (sceneManipulator != NULL)
            {
                sceneManipulator->setEnabled(false);
            }
        }
        else if (pinch->state() == Qt::GestureState::GestureFinished)
        {
            if (orthoManipulator != NULL)
            {
                orthoManipulator->setEnabled(true);
            }
            if (sceneManipulator != NULL)
            {
                sceneManipulator->setEnabled(true);
            }
        }

        // resolve zoom
        if (m_lastScale != scale)
        {
            if (orthoManipulator != NULL)
            {
                orthoManipulator->zoomGesture(m_lastScale / scale);
            }
            if (sceneManipulator != NULL)
            {
                sceneManipulator->zoom(m_lastScale / scale);
            }
            m_lastScale = scale;
        }
        // resolve move
        /*if (m_lastCenter != centerPoint)
        {
            if ((scale / m_lastScale < 1.05) && (m_lastScale / scale < 1.05)) // handle this only when scale has not changed too much
            {
                if (orthoManipulator != NULL)
                {
                    orthoManipulator->panGesture(centerPoint - m_lastCenter);
                }
                if (sceneManipulator != NULL)
                {
                    sceneManipulator->pan(centerPoint - m_lastCenter);
                }
                m_lastCenter = centerPoint;
            }
        }
        // resolve rotation
        if (m_lastRotation != rotationAngle)
        {
            if (sceneManipulator != NULL)
            {
                sceneManipulator->rotate(rotationAngle - m_lastRotation);
            }
            m_lastRotation = rotationAngle;
        }*/

        return true;
    }

    return false;
}

void OSGCanvas::keyPressEvent( QKeyEvent* event )
{
	m_bShortcut = false;
    switch (event->key())
    {
    case Qt::Key_Control: 
        restoreMouseMode();
        APP_MODE.storeAndSet( scene::CAppMode::MODE_SLICE_MOVE ); 
        break;
    case Qt::Key_Alt:
        restoreMouseMode();
        APP_MODE.storeAndSet( scene::CAppMode::MODE_DENSITY_WINDOW );         
        break;
    case Qt::Key_Shift:
        if (scene::CAppMode::DEFAULT_MODE != APP_MODE.getCustomShiftMode())
        {
            restoreMouseMode();
            APP_MODE.storeAndSet(APP_MODE.getCustomShiftMode());
        }
        else
        {
            if (APP_MODE.areDrawingHandlers())
            {
                restoreMouseMode();
                data::CObjectPtr< data::CDrawingOptions > spOptions(APP_STORAGE.getEntry(data::Storage::DrawingOptions::Id));
                data::CDrawingOptions::EDrawingMode mode = spOptions->getDrawingMode();
                if (mode != data::CDrawingOptions::DRAW_NOTHING)
                {
                    if (dynamic_cast<CVolumeRendererWindow *>(this) != NULL)
                    {
                        //if (NULL!=dynamic_cast<scene::CScene3D*>(m_view->getSceneData()))
                        APP_MODE.storeAndSet(scene::CAppMode::COMMAND_DRAW_WINDOW); // surface culling
                    }
                    else
                    {
                        APP_MODE.storeAndSet(scene::CAppMode::COMMAND_DRAW_GEOMETRY);
                    }
                }
            }
        }
        break;
    case Qt::Key_Escape:
        restoreMouseMode();
        return;
    default:
        QGLOSGWidget::keyPressEvent(event);
    }
}

bool OSGCanvas::canPostponeMouseModeRestore()
{
    scene::CAppMode::tMode mode = APP_MODE.get();
    if (scene::CAppMode::COMMAND_DRAW_WINDOW==mode ||
        scene::CAppMode::COMMAND_DRAW_GEOMETRY == mode)
        return true;
    return false;
}

void OSGCanvas::keyReleaseEvent( QKeyEvent* event )
{
    if (APP_MODE.isTempMode())
    {
        if (canPostponeMouseModeRestore() && Qt::NoButton!=QApplication::mouseButtons())
        {
            m_bRestoreModeOnMouseRelease = true;
        }
        else
        {
			if (!m_bShortcut)
				restoreMouseMode();
            //APP_MODE.restore(); // does nothing when there is no stored mode
            //m_bRestoreModeOnMouseRelease = false;
        }
    }          
    QGLOSGWidget::keyReleaseEvent(event);
}

void OSGCanvas::wheelEvent ( QWheelEvent * event )
{
    event->accept();
    int delta = event->delta();
    osgGA::GUIEventAdapter::ScrollingMotion motion = delta > 0 ?   osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN;
    getEventQueue()->mouseScroll( motion );
    Refresh(false);
}



void OSGCanvas::mousePressEvent ( QMouseEvent * event )
{
    QGLOSGWidget::mousePressEvent(event);
}

void OSGCanvas::mouseReleaseEvent ( QMouseEvent * event )
{
	m_bShortcut = false;
    QGLOSGWidget::mouseReleaseEvent(event);
    if (APP_MODE.isTempMode() && m_bRestoreModeOnMouseRelease)
    {
        APP_MODE.restore(); // does nothing when there is no stored mode
        m_bRestoreModeOnMouseRelease = false;
    }    
}

void OSGCanvas::mouseMoveEvent ( QMouseEvent * event )
{
	m_bShortcut = false;
    QGLOSGWidget::mouseMoveEvent(event);
    if (Qt::NoButton!=event->buttons())
        Refresh(false);
}

void OSGCanvas::enterEvent ( QEvent * event )
{
    QGLOSGWidget::enterEvent(event);
    if (!hasFocus())
        setFocus(Qt::MouseFocusReason);
	APP_MODE.getWindowEnterLeaveSignal().invoke(this,false);
    // call refresh so the osg items can receive the information too
    Refresh(false);
}

void OSGCanvas::leaveEvent ( QEvent * event )
{
	APP_MODE.getWindowEnterLeaveSignal().invoke(this,true);
    QGLOSGWidget::leaveEvent(event);
    // call refresh so the osg items can receive the information too
    Refresh(false);
}

bool OSGCanvas::event(QEvent *event)
{
	if (QEvent::ShortcutOverride == event->type()) // when this event comes and keyPress does not, a shortcut was used - we check this in keyRelease
	{
		//QKeyEvent *ke = dynamic_cast<QKeyEvent*>(event);
		//qDebug() << ke->key() << " " << ke->modifiers();
		m_bShortcut = true;
	}

    if (event->type() == QEvent::Gesture)
    {
        return gestureEvent(dynamic_cast<QGestureEvent *>(event));
    }

    return QGLOSGWidget::event( event );
}

void OSGCanvas::focusInEvent ( QFocusEvent * event ) 
{
    QGLOSGWidget::focusInEvent(event);
}

void OSGCanvas::focusOutEvent ( QFocusEvent * event ) 
{
    // shortcut can cause temporary mode switch and after that launch a modal dialog 
    // that will "steal" keyrelease, therefore we detect focus out and reset
    // mouse mode when it seems appropriate
    if (APP_MODE.isTempMode()) 
    {
        if (Qt::NoButton==QApplication::mouseButtons() && m_bShortcut) // no mouse button pressed and possibly a shortcut
        {
            Qt::KeyboardModifiers keyMod = QApplication::keyboardModifiers ();
			bool isSHIFT = keyMod.testFlag(Qt::ShiftModifier);
			bool isCTRL = keyMod.testFlag(Qt::ControlModifier); 
            if (isSHIFT || isCTRL) // modifier key pressed?
                restoreMouseMode(); // undo mouse mode change!
        }
    }  
    QGLOSGWidget::focusOutEvent(event);
}

void OSGCanvas::setCursorX(int appmode)
{
    switch(appmode)
    {
    case scene::CAppMode::MODE_TRACKBALL:
        setCursor(Qt::ArrowCursor);
        break;
    case scene::CAppMode::MODE_SLICE_MOVE:
        setCursor(Qt::PointingHandCursor);
        break;
    case scene::CAppMode::MODE_DENSITY_WINDOW:
        setCursor(Qt::SizeAllCursor);
        break;
    case scene::CAppMode::COMMAND_SCENE_ZOOM:
        {
            // TODO: add better magnifier cursor
            QCursor magCursor(QPixmap(":/svg/svg/magnifier_small.svg"));
            setCursor(magCursor);
        }
        break;
    case scene::CAppMode::COMMAND_SCENE_HIT:
    case scene::CAppMode::COMMAND_ADD_IMPLANT:
    case scene::CAppMode::COMMAND_REMOVE_IMPLANT:
    case scene::CAppMode::COMMAND_REPLACE_IMPLANT:
    case scene::CAppMode::COMMAND_IMPLANT_INFO:
    case scene::CAppMode::COMMAND_DENSITY_MEASURE:
    case scene::CAppMode::COMMAND_DISTANCE_MEASURE:
    case scene::CAppMode::COMMAND_DRAW_WINDOW:
    case scene::CAppMode::COMMAND_LANDMARK_ANNOTATION:
        setCursor(Qt::CrossCursor); // cross instead of pencil
        break;
    case scene::CAppMode::COMMAND_DRAW_GEOMETRY:
		if(NULL!=m_customCursor)
			setCursor(*m_customCursor);
		else
			setCursor(Qt::CrossCursor); // cross instead of pencil
        break;
    default:
        setCursor(QCursor());
        break;
    }
}

////////////////////////////////////////////////////////////
//