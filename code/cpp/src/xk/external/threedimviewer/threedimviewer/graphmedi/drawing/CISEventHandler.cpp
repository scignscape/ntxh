///////////////////////////////////////////////////////////////////////////////
// $Id: CISEventHandler.cpp
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

#include <drawing/CISEventHandler.h>
#include <coremedi/app/Signals.h>

using namespace osgGA;

//=============================================================================
// Constructor
CISEventHandler::CISEventHandler( OSGCanvas * canvas, scene::CSceneBase * scene )
    : CSceneGeometryDrawEH( canvas, scene )
    , m_handlingMode( data::CDrawingOptions::DRAW_NOTHING )
    , m_handlerType( data::CDrawingOptions::HANDLER_UNKNOWN )
    , m_lineColor( osg::Vec4( 1.0, 0.0, 0.0, 1.0 ) )
    , m_lineWidth( 1.0 )
    , bDrawing( false )
    , m_nPointsReported( 0 )
{
    m_conAppModeChanged = APP_MODE.getModeChangedSignal().connect( this, &CISEventHandler::OnModeChanged );

    // Load current settings
    data::CObjectPtr< data::CDrawingOptions > ptrOptions( APP_STORAGE.getEntry(data::Storage::DrawingOptions::Id) );

    m_lineWidth = ptrOptions->getWidth();
    m_lineColor = ptrOptions->getColor();
    m_handlingMode = ptrOptions->getDrawingMode();

    // Enable coloring
    data::CGeneralObjectObserver<CISEventHandler>::connect(ptrOptions.getEntryPtr(), data::CGeneralObjectObserver<CISEventHandler>::tObserverHandler(this, &CISEventHandler::sigDrawingOptionsChanged));
}

///////////////////////////////////////////////////////////////////////////////
// Destructor
CISEventHandler::~CISEventHandler()
{
    APP_MODE.getModeChangedSignal().disconnect( m_conAppModeChanged );
}

///////////////////////////////////////////////////////////////////////////////
//
osg::Vec3 CISEventHandler::RecomputeToVolume( const osg::Vec3 & point )
{
    data::CCoordinatesConv CoordConv = VPL_SIGNAL(SigGetActiveConvObject).invoke2();
    osg::Vec3 p;
    p.x() = osg::Vec3::value_type( CoordConv.fromSceneXd( point.x() ) );
    p.y() = osg::Vec3::value_type( CoordConv.fromSceneYd( point.y() ) );
    p.z() = osg::Vec3::value_type( CoordConv.fromSceneZd( point.z() ) );

    return p;
}

//=============================================================================
// Handle events
bool CISEventHandler::handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa, osg::Object *, osg::NodeVisitor *)
{
    bool rv(false);

    if( ea.getEventType() == osgGA::GUIEventAdapter::RELEASE )
    {
        rv = false;
    }

    const float x = ea.getX();
    const float y = ea.getY();
    if (x<ea.getXmin() || x>ea.getXmax() || y<ea.getYmin() || y>ea.getYmax())
        return false;

    // Test application mode
    if( UseHandler() && m_handlingMode != data::CDrawingOptions::DRAW_NOTHING )
    {
        CMousePoint point;
        point.m_modKeyMask = ea.getModKeyMask();
        point.m_buttonMask = ea.getButtonMask();
        point.m_buttonEvent = ea.getButton();

        if (point.m_buttonMask == osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON || osgGA::GUIEventAdapter::SCROLL == ea.getEventType())
        {
            if ((data::CDrawingOptions::DRAW_STROKE == m_handlingMode || data::CDrawingOptions::DRAW_POINT == m_handlingMode) && osgGA::GUIEventAdapter::SCROLL == ea.getEventType())
            {
                VPL_SIGNAL(SigScrollPerformed).invoke((ea.getScrollingMotion() == osgGA::GUIEventAdapter::SCROLL_UP) ? 1 : -1);
            }

            return false;
        }

        switch ( ea.getEventType() )
        {
        case osgGA::GUIEventAdapter::PUSH :
            // Try to get intersection
            if( ! GetIntersection( point, ea, aa ) )
                return false;

            m_buttonMask = point.m_buttonMask;
            m_nPointsReported = 0;

            m_drawLine = !(data::CDrawingOptions::DRAW_STROKE==m_handlingMode && APP_MODE.isContinuousDrawingEnabled());
            m_lastUpdateTime = m_timer.tick();

            // Call callback
            OnMousePush( point );

            if (APP_MODE.isContinuousDrawingEnabled() && m_handlingMode == data::CDrawingOptions::DRAW_STROKE)
            {
                VPL_SIGNAL(SigDrawingInProgress).invoke(true);
            }

            return true;

        case osgGA::GUIEventAdapter::DRAG :
            // Try to get intersection
            if( ! GetIntersection( point, ea, aa ) )
                return false;

            m_lastUpdateTime = m_timer.tick();

            // Call callback
            m_buttonMask = point.m_buttonMask;
            OnMouseDrag( point );

            if (bDrawing && data::CDrawingOptions::DRAW_STROKE == m_handlingMode && APP_MODE.isContinuousDrawingEnabled())
            {
                // Get array
                osg::ref_ptr<osg::Vec3Array> points = m_line->GetVertices();
                size_t pointsSize = points->size();
                if ((int)pointsSize - m_nPointsReported > 0)
                {
                    osg::ref_ptr< osg::Vec3Array > volumePoints = new osg::Vec3Array;
                    osg::ref_ptr< osg::Vec3Array > buffer = new osg::Vec3Array;

                    for (size_t i = m_nPointsReported; i < pointsSize; ++i)
                    {
                        volumePoints->push_back(RecomputeToVolume(points->at(i)));
                    }

                    m_nPointsReported = pointsSize - 1;

                    if (!VPL_SIGNAL(SigIsRegionColoringEnabled).invoke2())
                    {
                        VPL_SIGNAL(SigEnableRegionColoring).invoke(true);
                    }

                    if (!VPL_SIGNAL(SigIsMultiClassRegionColoringEnabled).invoke2())
                    {
                        VPL_SIGNAL(SigEnableMultiClassRegionColoring).invoke(true);
                    }

                    // Remove duplicities
                    m_lineOptimizer.Optimize( volumePoints, buffer );
                    // Send data
                    APP_MODE.invokeDrawingDone( buffer.get(), m_handlerType, m_buttonMask );
                }
            }

            return true;

        case osgGA::GUIEventAdapter::RELEASE :
            // Try to get intersection
            rv = GetIntersection( point, ea, aa );

            if( bDrawing )
            {
                // Call callback
                OnMouseRelease( point, false );

                rv = true;
            }

            stopDraw( point );

            // Remove line
            ClearLines();

            m_nPointsReported = 0;

            VPL_SIGNAL(SigDrawingInProgress).invoke(false);

            return rv;

        case osgGA::GUIEventAdapter::FRAME:
            if (bDrawing && data::CDrawingOptions::DRAW_STROKE==m_handlingMode && APP_MODE.isContinuousDrawingEnabled())
            {
                double diff(m_timer.delta_m(m_lastUpdateTime, m_timer.tick()));
                if (diff>250)
                {
                    // Get array
                    osg::ref_ptr<osg::Vec3Array> points = m_line->GetVertices();
                    if (((int)points->size())-m_nPointsReported>8)
                    {
                        osg::ref_ptr< osg::Vec3Array > volumePoints = new osg::Vec3Array;
                        osg::ref_ptr< osg::Vec3Array > buffer = new osg::Vec3Array;
                        osg::Vec3Array::iterator i;
                        for( i = points->begin()+m_nPointsReported; i != points->end(); ++i )
                            volumePoints->push_back( RecomputeToVolume( *i ) );
                        m_nPointsReported = points->size()-1;
                        if (!VPL_SIGNAL(SigIsRegionColoringEnabled).invoke2())
                            VPL_SIGNAL( SigEnableRegionColoring ).invoke( true );
                        if (!VPL_SIGNAL(SigIsMultiClassRegionColoringEnabled).invoke2())
                            VPL_SIGNAL(SigEnableMultiClassRegionColoring).invoke(true);
                        // Remove duplicities
                        m_lineOptimizer.Optimize( volumePoints, buffer );
                        // Send data
                        APP_MODE.invokeDrawingDone( buffer.get(), m_handlerType, m_buttonMask );
                    }
                }
            }
            break;
        } // switch

        return true;
    } // if mode ==

    return false;
}

//=============================================================================
// Handle mouse down
void CISEventHandler::OnMousePush(const osgGA::CMousePoint &point)
{
    if( bDrawing )
    {
        stopDraw( point );        
    }

    // Start drawing now
    initDraw( point );
}

//=============================================================================
// Handle mouse drag
void CISEventHandler::OnMouseDrag(const osgGA::CMousePoint &point)
{
    // TEST if drawing has already started
    if( !bDrawing )
    {
        // Start drawing now
        initDraw( point );
    }

    osg::Vec3Array * arr = dynamic_cast<osg::Vec3Array *>( m_line->GetVertices() );

    // recompute point to the volume space
    //osg::Vec3 vPoint = RecomputeToVolume( point.m_point );

    switch( m_handlingMode )
    {
    case data::CDrawingOptions::DRAW_POINT:
    case data::CDrawingOptions::DRAW_LINE:
	case data::CDrawingOptions::DRAW_LINE2:
        // Move second point to the new position
        arr->asVector()[ 0 ] = point.m_point;
        break;

    case data::CDrawingOptions::DRAW_STROKE:
        m_line->AddPoint( point.m_point );
        break;

    case data::CDrawingOptions::DRAW_LASO:
        m_line->AddPoint( point.m_point );
        arr->asVector()[ 0 ] = point.m_point;
        break;

    default:
        break;

    }
}

//=============================================================================
// Handle mouse release
void CISEventHandler::OnMouseRelease(const osgGA::CMousePoint &point, bool bUsePoint)
{
    // Just invoke signal

    // Get array
    osg::ref_ptr<osg::Vec3Array> points = m_line->GetVertices();

    osg::ref_ptr< osg::Vec3Array > volumePoints = new osg::Vec3Array;
    osg::ref_ptr< osg::Vec3Array > buffer = new osg::Vec3Array;

    osg::Vec3Array::iterator i;
    for( i = points->begin()+m_nPointsReported; i != points->end(); ++i )
    {
        volumePoints->push_back( RecomputeToVolume( *i ) );
    }

    VPL_SIGNAL( SigEnableRegionColoring ).invoke( true );
    VPL_SIGNAL(SigEnableMultiClassRegionColoring).invoke(true);

    // Remove duplicities
    points->clear();
    m_lineOptimizer.Optimize( volumePoints, buffer );

    // Send data
    APP_MODE.invokeDrawingDone( buffer.get(), m_handlerType, m_buttonMask );
}


///////////////////////////////////////////////////////////////////////////////
// On app mode changed signal response
void CISEventHandler::OnModeChanged(scene::CAppMode::tMode mode)
{
    if( mode != scene::CAppMode::COMMAND_DRAW_GEOMETRY )
    {
        // Is the mouse button still pressed?
        if( bDrawing )
        {
            // Simulate button release...
            osgGA::CMousePoint Point;
            OnMouseRelease(Point, false);

            stopDraw(Point);
        }

        ClearLines();
        m_nPointsReported = 0;

        // Unconnect all signals
        //APP_MODE.getDrawingDoneSignal().disconnectAll();
    }
}

//! General objectChanged method
void CISEventHandler::objectChanged(data::CStorageEntry *pEntry, const data::CChangedEntries &changes)
{ }

///////////////////////////////////////////////////////////////////////////////
// Update from storage - set drawing options
void CISEventHandler::sigDrawingOptionsChanged(data::CStorageEntry *pEntry, const data::CChangedEntries &changes)
{
    data::CDrawingOptions *options = pEntry->getDataPtr<data::CObjectHolder<data::CDrawingOptions> >()->getObjectPtr();
    m_lineWidth = options->getWidth();
    m_lineColor = options->getColor();
    m_handlingMode = options->getDrawingMode();
}



/******************************************************************************
    CLASS CISSceneXYEH - event handler for XY scene
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor
CISSceneXYEH::CISSceneXYEH( OSGCanvas * canvas, scene::CSceneOSG * scene )
: CISEventHandler( canvas, scene )
{
    m_handlerType = data::CDrawingOptions::HANDLER_XY;

    // Add drawables
    AddNode( scene->getSliceXY()->getSliceGeode() );

    // Enable drawing
    SetDraw();
}

/******************************************************************************
    CLASS CISSceneXZEH - event handler for XZ scene
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor
CISSceneXZEH::CISSceneXZEH( OSGCanvas * canvas, scene::CSceneOSG * scene )
: CISEventHandler( canvas, scene )
{
    m_handlerType = data::CDrawingOptions::HANDLER_XZ;

    // Add drawables
    AddNode( scene->getSliceXZ()->getSliceGeode() );

    // Enable drawing
    SetDraw();
}

/******************************************************************************
    CLASS CISSceneYZEH - event handler for YZ scene
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor
CISSceneYZEH::CISSceneYZEH( OSGCanvas * canvas, scene::CSceneOSG * scene )
: CISEventHandler( canvas, scene )
{
    m_handlerType = data::CDrawingOptions::HANDLER_YZ;

    // Add drawables
    AddNode( scene->getSliceYZ()->getSliceGeode() );

    // Enable drawing
    SetDraw();
}

/******************************************************************************
    CLASS CISScene3DEH - event handler for 3D scene
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
// Constructor
CISScene3DEH::CISScene3DEH( OSGCanvas * canvas, scene::CScene3DBase * scene )
    : CISEventHandler( canvas, scene )
{
    m_handlerType = data::CDrawingOptions::HANDLER_3D;

    // Add drawables
    AddNode( scene->getSliceXY()->getSliceGeode() );
    AddNode( scene->getSliceXZ()->getSliceGeode() );
    AddNode( scene->getSliceYZ()->getSliceGeode() );

    // Enable drawing
    SetDraw();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Start drawing. 
//!
//!\param   point   The point. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CISEventHandler::initDraw(const CMousePoint &point)
{
    bDrawing = true;

    // Create new line
    m_line = new osg::CLineGeode( m_lineFlags );

    //m_line->SetWidth( m_lineWidth );
    m_line->SetColor( m_lineColor );

    // recompute point to the volume space
    //osg::Vec3 vPoint = RecomputeToVolume( point.m_point );

    if( m_handlingMode != data::CDrawingOptions::DRAW_POINT )
    {
        m_line->SetMode( osg::PrimitiveSet::LINE_STRIP );
        m_line->AddPoint( point.m_point );
        m_line->AddPoint( point.m_point );
    }
    else
    {
        m_line->SetMode( osg::PrimitiveSet::POINTS );
        m_line->AddPoint( point.m_point );
    }


    // If should be drawn, draw it...
    if( m_drawLine && ( m_linesNode.get() != NULL ) )
        m_linesNode->addChild( m_line.get() );

    // Store line
    m_linesVector.push_back( m_line.get() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Stop drawing. 
//!
//!\param   point   The point. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CISEventHandler::stopDraw(const CMousePoint &point)
{
    bDrawing = false;
}


//=============================================================================
// Constructor
CISWindowEH::CISWindowEH(OSGCanvas *canvas, scene::CSceneBase *scene)
    : CSceneWindowDrawEH(canvas, scene)
    , m_handlingMode(data::CDrawingOptions::DRAW_NOTHING)
    , m_handlerType(data::CDrawingOptions::HANDLER_WINDOW)
    , m_lineColor(osg::Vec4(1.0, 0.0, 0.0, 1.0))
    , m_lineWidth(1.0)
    , bDrawing(false)
    , m_pointsWindow(NULL)
	, m_pointsScene(NULL)
    , m_pointDistanceLimit(1.0)
{
    m_conAppModeChanged = APP_MODE.getModeChangedSignal().connect(this, &CISWindowEH::OnModeChanged);

    // Load current settings
    data::CObjectPtr<data::CDrawingOptions> ptrOptions(APP_STORAGE.getEntry(data::Storage::DrawingOptions::Id));

    m_lineWidth = ptrOptions->getWidth();
    m_lineColor = ptrOptions->getColor();
    m_handlingMode = ptrOptions->getDrawingMode();

    data::CGeneralObjectObserver<CISWindowEH>::connect(ptrOptions.getEntryPtr(), data::CGeneralObjectObserver<CISWindowEH>::tObserverHandler(this, &CISWindowEH::sigDrawingOptionsChanged));
}

///////////////////////////////////////////////////////////////////////////////
// Destructor
CISWindowEH::~CISWindowEH()
{
    APP_MODE.getModeChangedSignal().disconnect(m_conAppModeChanged);
}

//=============================================================================
// Handle events
bool CISWindowEH::handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa, osg::Object *, osg::NodeVisitor *)
{
    bool rv(false);

    if (ea.getEventType() == osgGA::GUIEventAdapter::RELEASE)
    {
        rv = false;
    }
	
    // Test application mode
    if ((UseHandler()) && (m_handlingMode != data::CDrawingOptions::DRAW_NOTHING))
    {
        CMousePoint point;
        point.m_modKeyMask = ea.getModKeyMask();
        point.m_buttonMask = ea.getButtonMask();
        point.m_buttonEvent = ea.getButton();

        if (point.m_buttonMask == osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON || osgGA::GUIEventAdapter::SCROLL==ea.getEventType())
            return false;

        switch (ea.getEventType())
        {
        case osgGA::GUIEventAdapter::PUSH:
            // Try to get intersection
            if (!GetIntersection(point, ea, aa))
            {
                return false;
            }

            m_buttonMask = point.m_buttonMask;

			// Call callback
            OnMousePush(point);

            return true;

        case osgGA::GUIEventAdapter::DRAG:
            // Try to get intersection
            if (!GetIntersection(point, ea, aa))
            {
                return false;
            }

            // Call callback
            m_buttonMask = point.m_buttonMask;
            OnMouseDrag(point);

            return true;

        case osgGA::GUIEventAdapter::RELEASE:
            // Try to get intersection
            rv = GetIntersection(point, ea, aa);

            if (bDrawing)
            {
                // Call callback
                OnMouseRelease(point, false);

                rv = true;
            }

            stopDraw(point);

            // Remove line
            ClearLines();

            return rv;

        } // switch

        return true;
    } // if mode ==

    return false;
}

//=============================================================================
// Handle mouse down
void CISWindowEH::OnMousePush(const osgGA::CMousePoint &point)
{
    if (bDrawing)
    {
        stopDraw(point);
    }

    // Start drawing now
    initDraw(point);
}

//=============================================================================
// Handle mouse drag
void CISWindowEH::OnMouseDrag(const osgGA::CMousePoint &point)
{
    // TEST if drawing has already started
    if (!bDrawing)
    {
        // Start drawing now
        initDraw(point);
    }

    osg::Vec3Array *arr = dynamic_cast<osg::Vec3Array *>(m_line->GetVertices());

    osg::Vec3 pointWindow = osg::Vec3(point.m_pointWindow, 0.0f);
    osg::Vec3 pointScene = point.m_point;
    
    if ((pointWindow - m_pointsWindow->back()).length() < m_pointDistanceLimit)
    {
        return;
    }

    switch (m_handlingMode)
    {
    case data::CDrawingOptions::DRAW_LASO:
        m_line->AddPoint(pointScene);
        m_pointsWindow->push_back(pointWindow);
        arr->asVector()[0] = pointScene;
        break;

    case data::CDrawingOptions::DRAW_LINE:
	case data::CDrawingOptions::DRAW_LINE2:
        {
            osg::Vec3 originWindow = m_pointsWindow->front();
            osg::Vec3 originScene = arr->front();
            m_pointsWindow->clear();
            m_pointsWindow->push_back(originWindow);
            m_pointsWindow->push_back(pointWindow);
			m_pointsScene->clear();
			m_pointsScene->push_back(originScene);
			m_pointsScene->push_back(pointScene);
            m_line->clear();
            m_line->AddPoint(originScene);
            m_line->AddPoint(pointScene);
            m_line->getLineVertices()->dirty();
            break;
        }

    case data::CDrawingOptions::DRAW_ARROW:
    {
        osg::Vec3 originWindow = m_pointsWindow->front();
        osg::Vec3 originScene = arr->front();
        m_pointsWindow->clear();
        m_line->clear();

        //extract inverse rotation of scene... hmm.. this almost works..
        osg::Matrix view = m_canvas->getView()->getCamera()->getViewMatrix();
        osg::Matrix proj = m_canvas->getView()->getCamera()->getProjectionMatrix();

        auto view2 = osg::Matrix::inverse(view);
        auto proj2 = osg::Matrix::inverse(proj);
    
        float width = m_canvas->width();
        float height = m_canvas->height();


        osg::Vec3 arrowDirection = originWindow - pointWindow;
        float arrow_length = arrowDirection.length();

        float arrow_side_length = arrow_length / 5.0f;

        arrowDirection.normalize();

        osg::Vec3 left_point, right_point;

        osg::Matrix rotation_right = osg::Matrix::rotate(osg::DegreesToRadians(35.0f), osg::Vec3(0.0f, 0.0f, 1.0f));
        osg::Matrix rotation_left = osg::Matrix::rotate(osg::DegreesToRadians(-35.0f), osg::Vec3(0.0f, 0.0f, 1.0f));

        right_point = arrowDirection * rotation_right;
        right_point *= arrow_side_length;
        right_point += pointWindow;

        left_point = arrowDirection * rotation_left;
        left_point *= arrow_side_length;
        left_point += pointWindow;


        std::vector<osg::Vec3> arrow_path;

        arrow_path.push_back(originWindow);
        arrow_path.push_back(pointWindow);

        arrow_path.push_back(right_point);
        arrow_path.push_back(pointWindow);
        arrow_path.push_back(left_point);

        for (size_t i = 0; i < arrow_path.size(); ++i){
            osg::Vec3 point = arrow_path.at(i);

            m_pointsWindow->push_back(point);

            //normalize to (-1, 1)
            float x = (point.x() - width / 2.0f) / (width / 2.0f);
            float y = (point.y() - height / 2.0f) / (height / 2.0f);
            point.set(x, y, 0.0f);


            //transform to scene
            point = (point * proj2) * view2;

            m_line->AddPoint(point);

        }

        m_line->getLineVertices()->dirty();   
        break;
    }
	case data::CDrawingOptions::DRAW_STROKE:
	{
		m_line->AddPoint(point.m_point);
		m_pointsWindow->push_back(pointWindow);
		break;
	}

    default:
        break;
    }
}

//=============================================================================
// Handle mouse release
void CISWindowEH::OnMouseRelease(const osgGA::CMousePoint &point, bool bUsePoint)
{
    // Get array
    osg::ref_ptr<osg::Vec3Array> buffer = new osg::Vec3Array;

    switch (m_handlingMode)
    {
    case data::CDrawingOptions::DRAW_LASO:
        m_pointsWindow->push_back(m_pointsWindow->front());
        break;
	case data::CDrawingOptions::DRAW_LINE2:
		VPL_SIGNAL(SigSendLineSceneCoordinates).invoke(m_pointsScene.get());
		break;

    default:
        break;
    }

    // Remove duplicities
    m_lineOptimizer.Optimize(m_pointsWindow, buffer);

    // Send data
    APP_MODE.invokeDrawingDone(buffer.get(), m_handlerType, m_buttonMask);
}


///////////////////////////////////////////////////////////////////////////////
// On app mode changed signal response
void CISWindowEH::OnModeChanged(scene::CAppMode::tMode mode)
{
    if (mode != scene::CAppMode::COMMAND_DRAW_WINDOW)
    {
        // Is the mouse button still pressed?
        if (bDrawing)
        {
            // Simulate button release...
            osgGA::CMousePoint Point;
            OnMouseRelease(Point, false);

            stopDraw(Point);
        }

        ClearLines();
    }
}

//! General objectChanged method
void CISWindowEH::objectChanged(data::CStorageEntry *pEntry, const data::CChangedEntries &changes)
{ }

///////////////////////////////////////////////////////////////////////////////
// Update from storage - set drawing options
void CISWindowEH::sigDrawingOptionsChanged(data::CStorageEntry *pEntry, const data::CChangedEntries &changes)
{
    data::CDrawingOptions *options = pEntry->getDataPtr<data::CObjectHolder<data::CDrawingOptions> >()->getObjectPtr();
    m_lineWidth = options->getWidth();
    m_lineColor = options->getColor();
    m_handlingMode = options->getDrawingMode();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Start drawing. 
//!
//!\param   point   The point. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CISWindowEH::initDraw(const CMousePoint &point)
{
    m_pointsWindow = new osg::Vec3Array;
	m_pointsScene = new osg::Vec3Array;
    bDrawing = true;

    // Create new line
    m_line = new osg::CLineGeode( m_lineFlags );

    //m_line->SetWidth(m_lineWidth);
    m_line->SetColor(m_lineColor);

    // recompute point to the volume space
    //osg::Vec3 vPoint = point.m_point;

    m_line->SetMode( osg::PrimitiveSet::LINE_STRIP );
    m_line->AddPoint( point.m_point );
    m_line->AddPoint( point.m_point );
    m_pointsWindow->push_back(osg::Vec3(point.m_pointWindow, 0.0f));
    m_pointsWindow->push_back(osg::Vec3(point.m_pointWindow, 0.0f));

    // If should be drawn, draw it...
    if ((m_drawLine) && (m_linesNode.get() != NULL))
    {
        m_linesNode->addChild(m_line.get());
    }

    // Store line
    m_linesVector.push_back(m_line.get());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   ! Stop drawing. 
//!
//!\param   point   The point. 
////////////////////////////////////////////////////////////////////////////////////////////////////
void CISWindowEH::stopDraw(const CMousePoint &point)
{
    bDrawing = false;
}
