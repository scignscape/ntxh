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
 * Date:    2004/07/30                       
 *
 * File description:
 * - Reads a volume from the input channel.
 * - Visualizes it using GLUT and OpenGL.
 */

#include "VolumeView.h"

#include <VPL/Image/VolumeFunctions.h>

// OpenGL
#ifdef _MACOSX
#   include <OpenGL/gl.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glut.h>
#endif

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Macro definitions.
 */

//! Macro enables the perspective projection if defined.
//#define ENABLE_PERSPECTIVE


//==============================================================================
/*
 * Global definitions.
 */

//! GLUT window title.
const char GLUT_WINDOW_TITLE[]              = "VPL Volume View";

//! Module description.
const std::string MODULE_DESCRIPTION        = "Module visualizes input volume using GLUT and OpenGL";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS          = "coloring";

//! Additional arguments.
const std::string MODULE_ARGUMENT_COLORING  = "coloring";

//! Default GLUT window position.
const int GLUT_WINDOW_XPOS                  = 100;
const int GLUT_WINDOW_YPOS                  = 100;

//! Default GLUT window size.
int GLUT_WINDOW_XSIZE                       = 512;
int GLUT_WINDOW_YSIZE                       = 512;

//! State of the mouse buttons.
enum EMouseState
{
    MOUSE_NORMAL = 0,
    MOUSE_ROTATION,
    MOUSE_ZOOM
};

//! Type of the volume coloring method.
enum EVolumeColoring
{
    COL_GRAYSCALE = 1,
    COL_PSEUDO,
    COL_SEGMENTED
};

//! Allowed 'coloring' argument values.
const std::string COL_GRAYSCALE_NAME        = "grayscale";
const std::string COL_PSEUDO_NAME           = "pseudo";
const std::string COL_SEGMENTED_NAME        = "segmented";

//! Default 'coloring' argument.
const std::string DEFAULT_COLORING_NAME     = COL_GRAYSCALE_NAME;

//! Maximum voxel value.
const unsigned int PIXEL_MAX                = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Global variables.
 */

//! Current GLUT window size.
int iGlutWindowXSize                        = GLUT_WINDOW_XSIZE;
int iGlutWindowYSize                        = GLUT_WINDOW_YSIZE;

#ifdef ENABLE_PERSPECTIVE

//! Field of view.
GLfloat fGLFoV                              = 70.0f;

#endif // ENABLE_PERSPECTIVE

//! Near and far view frustum planes.
GLfloat fGLNearPlane                        = 1.0f;
GLfloat fGLFarPlane                         = 2048.0f;

//! State of the mouse buttons.
EMouseState eMouseState                     = MOUSE_NORMAL;

//! Coloring method.
EVolumeColoring eColoring;

//! Plane positions.
vpl::tSize pPlanes[3];

//! Texture numbers.
GLuint puGLTextures[3];

//! Size of the used texture part.
GLfloat pfGLTextureXSize[3];
GLfloat pfGLTextureYSize[3];

//! Mouse cursor position.
int iPosX, iPosY, iPosZ;
int iOldX = 0, iOldY = 0, iOldZ = 0;
int iNewX = 0, iNewY = 0, iNewZ = 0;

#ifndef ENABLE_PERSPECTIVE

//! Default volume position in 3D space.
const GLfloat fGLPosition                   = fGLFarPlane * -0.5;

//! Zooming step.
const GLfloat fGLZoomStep                   = 0.01f;

//! Minimal zoom factor.
const GLfloat fGLMinZoom                    = 0.2f;

//! Maximal zoom factor.
const GLfloat fGLMaxZoom                    = 100.f;

//! Zoom factor.
GLfloat fGLZoom                             = 1.0f;

#endif // ENABLE_PERSPECTIVE


//==============================================================================
/*
 * Global functions.
 */

//! Returns maximal volume coordinate.
double getVolumeMaxX(vpl::img::CDensityVolume *pVolume);
double getVolumeMaxY(vpl::img::CDensityVolume *pVolume);
double getVolumeMaxZ(vpl::img::CDensityVolume *pVolume);

//! Returns volume size.
double getVolumeXSize(vpl::img::CDensityVolume *pVolume);
double getVolumeYSize(vpl::img::CDensityVolume *pVolume);
double getVolumeZSize(vpl::img::CDensityVolume *pVolume);

//! Texture creation.
void createTexture(vpl::img::EPlane Plane,
                   EVolumeColoring Coloring,
                   vpl::img::CDImage *pImage
                   );

//! Display a given volume plane.
void displayPlane(vpl::img::EPlane Plane);


//==============================================================================
/*
 * GLUT functions.
 */

//! Callback functions
void onInit();
void onResize(int width, int height);
void onDisplay(void);
void onKeyboard(unsigned char key, int x, int y);
void onSpecialKeyboard(int key, int x, int y);
void onMouseButton(int iButton, int iState, int x, int y);
void onMouseMotion(int x, int y);


//==============================================================================
/*
 * Implementation of the class CVolumeView.
 */
CVolumeView *CVolumeView::m_pView = NULL;


CVolumeView::CVolumeView(const std::string& sDescription)
    : vpl::mod::CView(sDescription)
{
    VPL_ASSERT(m_pView == NULL);
    m_pView = this;

    allowArguments(MODULE_ARGUMENTS);
}


CVolumeView::~CVolumeView()
{
}


bool CVolumeView::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input channel
    if( getNumOfInputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input channels" << std::endl);
        return false;
    }

    // Type of slice coloring
    std::string sColoringName = DEFAULT_COLORING_NAME;
    m_Arguments.value(MODULE_ARGUMENT_COLORING, sColoringName);
    if( sColoringName == COL_GRAYSCALE_NAME )
    {
        eColoring = COL_GRAYSCALE;
    }
    else if( sColoringName == COL_PSEUDO_NAME )
    {
        eColoring = COL_PSEUDO;
    }
    else if( sColoringName == COL_SEGMENTED_NAME )
    {
        eColoring = COL_SEGMENTED;
    }
    else
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'coloring' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeView::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // Input channel
    vpl::mod::CChannel *pIChannel = getInput(0);

    // Wait while channel is not closed
    while( pIChannel->isConnected() )
    {
        // Wait for data
        if( pIChannel->wait(1000) )
        {
            // Read volume from the input channel
            if( !readInput(pIChannel, &m_Volume) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_INFO("Wait timeout");
            return false;
        }
    }

    // Initialize GLUT library
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(GLUT_WINDOW_TITLE);
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyboard);
    glutSpecialFunc(onSpecialKeyboard);
    glutMouseFunc(onMouseButton);
    glutMotionFunc(onMouseMotion);

    // Initialize module
    onInit();

    // Run GLUT event processing loop
    glutMainLoop();

    return false;
}


void CVolumeView::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeView::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-coloring Type]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -coloring Selects the coloring method. Allowed types are grayscale," << std::endl;
    Stream << "            pseudo and segmented. Pseudo shows a given volume colored" << std::endl;
    Stream << "            instead of grayscale. In case the voxel value represents" << std::endl;
    Stream << "            volume segment, the segmented type shows it." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: none" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes view application.
 */
int main(int argc, char *argv[])
{
    // Creation of a view module using smart pointer
    CVolumeViewPtr spView(new CVolumeView(MODULE_DESCRIPTION));

    // Initialize GLUT library
    glutInit(&argc, argv);

    // Initialize and run the view
    if( spView->init(argc, argv) )
    {
        spView->run();
    }

    // Console application finished
    return 0;
}


//==============================================================================
/*
 * Implementation of the global functions.
 */

// Returns maximal volume coordinate
double getVolumeMaxX(vpl::img::CDensityVolume *pVolume)
{
    return (pVolume->getXSize() - 1) * pVolume->getDX();
}


double getVolumeMaxY(vpl::img::CDensityVolume *pVolume)
{
    return (pVolume->getYSize() - 1) * pVolume->getDY();
}


double getVolumeMaxZ(vpl::img::CDensityVolume *pVolume)
{
    return (pVolume->getZSize() - 1) * pVolume->getDZ();
}


// Returns volume size
double getVolumeXSize(vpl::img::CDensityVolume *pVolume)
{
    return pVolume->getXSize() * pVolume->getDX();
}


double getVolumeYSize(vpl::img::CDensityVolume *pVolume)
{
    return pVolume->getYSize() * pVolume->getDY();
}


double getVolumeZSize(vpl::img::CDensityVolume *pVolume)
{
    return pVolume->getZSize() * pVolume->getDZ();
}


// Creation of an OpenGL RGBA texture
void createTexture(vpl::img::EPlane Plane,
                   EVolumeColoring Coloring,
                   vpl::img::CDImage *pImage
                   )
{
    // Set texture image parameters
    glBindTexture(GL_TEXTURE_2D, puGLTextures[Plane]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Image size
    vpl::tSize XSize = pImage->getXSize();
    vpl::tSize YSize = pImage->getYSize();

    // Texture dimensions
    vpl::tSize TexXSize = 2, TexYSize = 2;
    while( TexXSize < XSize || TexYSize < YSize )
    {
        TexXSize *= 2;
        TexYSize *= 2;
    }

    // Allowed maximal texture dimension
    int iMaxTexDim;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &iMaxTexDim);

    // Modify the image dimension
    if( (int)TexXSize > iMaxTexDim )
    {
        XSize = TexXSize = iMaxTexDim;
        YSize = TexYSize = iMaxTexDim;
    }

    // Used texture size
    pfGLTextureXSize[Plane] = (GLfloat)XSize / (GLfloat)TexXSize;
    pfGLTextureYSize[Plane] = (GLfloat)YSize / (GLfloat)TexYSize;

    // Allocate texture RGB data
    unsigned char *pucRGBTexture = new unsigned char[TexYSize * TexXSize * 3];
    memset(pucRGBTexture, 0, TexYSize * TexXSize * 3);

    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    // Create required texture
    switch( Coloring )
    {
        // Segmented RGB texture
        case COL_SEGMENTED: {
            // Number of segments
            double dMin = vpl::img::getMin<double>(*spVolume);
            double dMax = vpl::img::getMax<double>(*spVolume);
            double dSegments = dMax - dMin + 1.0;
            double dConst = PIXEL_MAX / dSegments;

            // Convert image pixels
            for( vpl::tSize j = 0; j < YSize; ++j )
            {
                for( vpl::tSize i = 0; i < XSize; ++i )
                {
                    double dTemp = (pImage->at(i, j) - dMin) * dConst;
                    pImage->set(i, j, (vpl::img::CDImage::tPixel)dTemp);
                }
            }
        }

        // Pseudo color RGB texture
        case COL_PSEUDO: {
            // Pseudo coloring of grayscale image
            double dConst = 6.0 / (double)PIXEL_MAX;
            for( vpl::tSize j = 0; j < YSize; ++j )
            {
                unsigned char *p = &pucRGBTexture[j * TexXSize * 3];
                for( vpl::tSize i = 0; i < XSize; ++i )
                {
                    double dSegment = dConst * pImage->at(i, j);
                    if( dSegment <= 1.0 )
                    {
                        *(p++) = (unsigned char)(0);
                        *(p++) = (unsigned char)(255.0 * dSegment);
                        *(p++) = (unsigned char)(0);
                    }
                    else if( dSegment <= 2.0 )
                    {
                        *(p++) = (unsigned char)(0);
                        *(p++) = (unsigned char)(255);
                        *(p++) = (unsigned char)(255.0 * (dSegment - 1.0));
                    }
                    else if( dSegment <= 3.0 )
                    {
                        *(p++) = (unsigned char)(0);
                        *(p++) = (unsigned char)(255.0 - 255.0 * (dSegment - 2.0));
                        *(p++) = (unsigned char)(255);
                    }
                    else if( dSegment <= 4.0 )
                    {
                        *(p++) = (unsigned char)(255.0 * (dSegment - 3.0));
                        *(p++) = (unsigned char)(0);
                        *(p++) = (unsigned char)(255);
                    }
                    else if( dSegment <= 5.0 )
                    {
                        *(p++) = (unsigned char)(255);
                        *(p++) = (unsigned char)(0);
                        *(p++) = (unsigned char)(255.0 - 255.0 * (dSegment - 4.0));
                    }
                    else
                    {
                        *(p++) = (unsigned char)(255);
                        *(p++) = (unsigned char)(255.0 * (dSegment - 5.0));
                        *(p++) = (unsigned char)(255.0 * (dSegment - 5.0));
                    }
                }
            }
        } break;

        // Grayscale texture
        default: {
            for( vpl::tSize j = 0; j < YSize; ++j )
            {
                unsigned char *p = &pucRGBTexture[j * TexXSize * 3];
                for( vpl::tSize i = 0; i < XSize; ++i )
                {
                    unsigned char ucTemp = (unsigned char)pImage->at(i, j);
                    *(p++) = ucTemp;
                    *(p++) = ucTemp;
                    *(p++) = ucTemp;
                }
            }
        } break;
    }

    // Define 2D texture image
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 TexXSize, TexYSize,
                 0, GL_RGB, GL_UNSIGNED_BYTE,
                 pucRGBTexture
                 );

    // Free the memory
    delete[] pucRGBTexture;
}


// Display a volume plane
void displayPlane(vpl::img::EPlane Plane)
{
    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    switch( Plane )
    {
        case vpl::img::PLANE_XY:
            glEnable(GL_TEXTURE_2D);
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, pPlanes[Plane] * spVolume->getDZ());

            glTexCoord2f(pfGLTextureXSize[Plane], 0.0f);
            glVertex3f(getVolumeMaxX(spVolume), 0.0f, pPlanes[Plane] * spVolume->getDZ());

            glTexCoord2f(pfGLTextureXSize[Plane], pfGLTextureYSize[Plane]);
            glVertex3f(getVolumeMaxX(spVolume), getVolumeMaxY(spVolume), pPlanes[Plane] * spVolume->getDZ());

            glTexCoord2f(0.0f, pfGLTextureYSize[Plane]);
            glVertex3f(0.0f, getVolumeMaxY(spVolume), pPlanes[Plane] * spVolume->getDZ());
            glEnd();
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, pPlanes[Plane] * spVolume->getDZ());
            glVertex3f(getVolumeMaxX(spVolume), 0.0f, pPlanes[Plane] * spVolume->getDZ());
            glVertex3f(getVolumeMaxX(spVolume), getVolumeMaxY(spVolume), pPlanes[Plane] * spVolume->getDZ());
            glVertex3f(0.0f, getVolumeMaxY(spVolume), pPlanes[Plane] * spVolume->getDZ());
            glEnd();
            break;

        case vpl::img::PLANE_XZ:
            glEnable(GL_TEXTURE_2D);
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0.0f, pPlanes[Plane] * spVolume->getDY(), 0.0f);

            glTexCoord2f(pfGLTextureXSize[Plane], 0.0f);
            glVertex3f(getVolumeMaxX(spVolume), pPlanes[Plane] * spVolume->getDY(), 0.0f);

            glTexCoord2f(pfGLTextureXSize[Plane], pfGLTextureYSize[Plane]);
            glVertex3f(getVolumeMaxX(spVolume), pPlanes[Plane] * spVolume->getDY(), getVolumeMaxZ(spVolume));

            glTexCoord2f(0.0f, pfGLTextureYSize[Plane]);
            glVertex3f(0.0f, pPlanes[Plane] * spVolume->getDY(), getVolumeMaxZ(spVolume));
            glEnd();
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, pPlanes[Plane] * spVolume->getDY(), 0.0f);
            glVertex3f(getVolumeMaxX(spVolume), pPlanes[Plane] * spVolume->getDY(), 0.0f);
            glVertex3f(getVolumeMaxX(spVolume), pPlanes[Plane] * spVolume->getDY(), getVolumeMaxZ(spVolume));
            glVertex3f(0.0f, pPlanes[Plane] * spVolume->getDY(), getVolumeMaxZ(spVolume));
            glEnd();
            break;

        case vpl::img::PLANE_YZ:
            glEnable(GL_TEXTURE_2D);
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), 0.0f, 0.0f);

            glTexCoord2f(pfGLTextureXSize[Plane], 0.0f);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), getVolumeMaxY(spVolume), 0.0f);

            glTexCoord2f(pfGLTextureXSize[Plane], pfGLTextureYSize[Plane]);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), getVolumeMaxY(spVolume), getVolumeMaxZ(spVolume));

            glTexCoord2f(0.0f, pfGLTextureYSize[Plane]);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), 0.0f, getVolumeMaxZ(spVolume));
            glEnd();
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), 0.0f, 0.0f);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), getVolumeMaxY(spVolume), 0.0f);
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), getVolumeMaxY(spVolume), getVolumeMaxZ(spVolume));
            glVertex3f(pPlanes[Plane] * spVolume->getDX(), 0.0f, getVolumeMaxZ(spVolume));
            glEnd();
            break;

        default:
            break;
    }
}


// GLUT and texture initialization
void onInit()
{
    // Set clear color
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Enable z-buffer
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Enable antialiasing
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);

    // Enable the polygon filling
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    // Turn the culling off
    glDisable(GL_CULL_FACE);

    // Set global texture image parameters
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Make performace hints
#ifdef ENABLE_PERSPECTIVE
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
#endif // ENABLE_PERSPECTIVE

    // Set the line width
    glLineWidth(1.1f);

    // Generate texture names
    glGenTextures(3, puGLTextures);

    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    // Initialize the plane positions
    pPlanes[vpl::img::PLANE_XY] = (spVolume->getZSize() - 1) / 2;
    pPlanes[vpl::img::PLANE_XZ] = (spVolume->getYSize() - 1) / 2;
    pPlanes[vpl::img::PLANE_YZ] = (spVolume->getXSize() - 1) / 2;

    // Create the textures
    vpl::img::CDImagePtr spPlane;
    spPlane->resize(spVolume->getXSize(), spVolume->getYSize());
    spVolume->getPlaneXY(pPlanes[vpl::img::PLANE_XY], *spPlane);
    createTexture(vpl::img::PLANE_XY, eColoring, spPlane);

    spPlane->resize(spVolume->getXSize(), spVolume->getZSize());
    spVolume->getPlaneXZ(pPlanes[vpl::img::PLANE_XZ], *spPlane);
    createTexture(vpl::img::PLANE_XZ, eColoring, spPlane);

    spPlane->resize(spVolume->getYSize(), spVolume->getZSize());
    spVolume->getPlaneYZ(pPlanes[vpl::img::PLANE_YZ], *spPlane);
    createTexture(vpl::img::PLANE_YZ, eColoring, spPlane);

    // Initialize glut window
    glutPositionWindow(GLUT_WINDOW_XPOS, GLUT_WINDOW_YPOS);
    glutReshapeWindow(GLUT_WINDOW_XSIZE, GLUT_WINDOW_YSIZE);

    // Initial zoom
#ifdef ENABLE_PERSPECTIVE
    iOldZ = iNewZ = (int)(getVolumeYSize(spVolume) * -1.2);
#else
    fGLZoom = GLUT_WINDOW_YSIZE / getVolumeYSize(spVolume) * 0.6;
#endif // ENABLE_PERSPECTIVE
}


// Sets coordinate system depending on the window size
void onResize(int iWidth, int iHeight)
{
    // Current window size
    iGlutWindowXSize = iWidth;
    iGlutWindowYSize = iHeight;

    // Set the viewport
    glViewport(0, 0, iWidth, iHeight);

    // Projection matrix modification
    glMatrixMode(GL_PROJECTION);

    // Clear the projection matrix
    glLoadIdentity();

#ifdef ENABLE_PERSPECTIVE
    // Perspective projection
    gluPerspective(fGLFoV, (GLfloat)iWidth / (GLfloat)iHeight, fGLNearPlane, fGLFarPlane);
#else
    // Map abstract coordinates to the window coordinates
    glOrtho(0, iWidth, 0, iHeight, fGLNearPlane, fGLFarPlane);

    // Translate the origin
    glTranslatef(iWidth / 2, iHeight / 2, 0);
#endif // ENABLE_PERSPECTIVE
}


// Displays the window
void onDisplay(void)
{
    // Clear the color buffer and z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Enable textures
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Model view matrix modification
    glMatrixMode(GL_MODELVIEW);

    // Clear the model view matrix
    glLoadIdentity();

    // Mouse zooming
#ifdef ENABLE_PERSPECTIVE
    glTranslatef(0.0f, 0.0f, iNewZ);
#else
    glTranslatef(0.0f, 0.0f, fGLPosition);
#endif // ENABLE_PERSPECTIVE

    // Mouse rotation
    glRotatef(iNewX, 0.0f, 1.0f, 0.0f);
    glRotatef(iNewY, 1.0f, 0.0f, 0.0f);

    // Invert y-axis
#ifdef ENABLE_PERSPECTIVE
    glScalef(1, -1, 1);
#else
    glScalef(fGLZoom, -fGLZoom, fGLZoom);
#endif // ENABLE_PERSPECTIVE

    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    // Translate to the center
    glTranslatef((GLfloat)(getVolumeXSize(spVolume) * -0.5),
                 (GLfloat)(getVolumeYSize(spVolume) * -0.5),
                 (GLfloat)(getVolumeZSize(spVolume) * -0.5)
                );

    // Draw the pPlanes
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, puGLTextures[vpl::img::PLANE_XY]);
    displayPlane(vpl::img::PLANE_XY);

    glBindTexture(GL_TEXTURE_2D, puGLTextures[vpl::img::PLANE_XZ]);
    displayPlane(vpl::img::PLANE_XZ);

    glBindTexture(GL_TEXTURE_2D, puGLTextures[vpl::img::PLANE_YZ]);
    displayPlane(vpl::img::PLANE_YZ);

    // Draw changes
    glFlush();
    glutSwapBuffers();
}


// Called on ASCII key pressed
void onKeyboard(unsigned char ucKey, int VPL_UNUSED(x), int VPL_UNUSED(y))
{
    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    // Translate to lower case
    if( ucKey > 'A' && ucKey <= 'Z' )
    {
        ucKey += 'a' - 'A';
    }

    switch( ucKey )
    {
        // ESC, ^C and 'c' exits the application
        case 'c':
        case 27:
        case 3:
            exit(0);
            break;

        // Window mode
        case 'w':
            glutReshapeWindow(GLUT_WINDOW_XSIZE, GLUT_WINDOW_YSIZE);
            glutPositionWindow(GLUT_WINDOW_XPOS, GLUT_WINDOW_YPOS);
            break;

        // Fullscreen mode
        case 'f':
            GLUT_WINDOW_XSIZE = iGlutWindowXSize;
            GLUT_WINDOW_YSIZE = iGlutWindowYSize;
            glutFullScreen();
            break;

        // Initialize XY view
        case '1':
            iNewX = iOldX = 0;
            iNewY = iOldY = 0;
            glutPostRedisplay();
            break;

        // Initialize XZ view
        case '2':
            iNewX = iOldX = 0;
            iNewY = iOldY = 90;
            glutPostRedisplay();
            break;

        // Initialize YZ view
        case '3':
            iNewX = iOldX = 90;
            iNewY = iOldY = 0;
            glutPostRedisplay();
            break;

        // XY plane position
        case 'q':
            if( pPlanes[vpl::img::PLANE_XY] < (spVolume->getZSize() - 1) )
            {
                pPlanes[vpl::img::PLANE_XY]++;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getXSize(), spVolume->getYSize()));
                spVolume->getPlaneXY(pPlanes[vpl::img::PLANE_XY], *spPlane);

                createTexture(vpl::img::PLANE_XY, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;

        case 'a':
            if( pPlanes[vpl::img::PLANE_XY] > 0 )
            {
                pPlanes[vpl::img::PLANE_XY]--;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getXSize(), spVolume->getYSize()));
                spVolume->getPlaneXY(pPlanes[vpl::img::PLANE_XY], *spPlane);

                createTexture(vpl::img::PLANE_XY, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;

        // Help
        case 'h':
            VPL_LOG_ERROR("Keyboard Shortcuts:" << std::endl);
            VPL_LOG_ERROR("  h      ... shows this help." << std::endl);
            VPL_LOG_ERROR("  q,a    ... change the XY plane position." << std::endl);
            VPL_LOG_ERROR("  arrows ... change position of the YZ and XZ planes." << std::endl);
            VPL_LOG_ERROR("  1,2,3  ... initialize the eye position." << std::endl);
            VPL_LOG_ERROR("  f      ... switches to the fullscreen mode." << std::endl);
            VPL_LOG_ERROR("  w      ... switches back to the window." << std::endl);
            VPL_LOG_ERROR("  c      ... exits the program." << std::endl);
            break;
    }
}


// Called on direction ucKey pressed
void onSpecialKeyboard(int ucKey, int VPL_UNUSED(x), int VPL_UNUSED(y))
{
    // Volume data
    vpl::img::CDensityVolumePtr spVolume(CVolumeView::getViewPtr()->getVolume());

    switch( ucKey )
    {
        // XZ plane position
        case GLUT_KEY_DOWN:
            if( pPlanes[vpl::img::PLANE_XZ] < (spVolume->getYSize() - 1) )
            {
                pPlanes[vpl::img::PLANE_XZ]++;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getXSize(), spVolume->getZSize()));
                spVolume->getPlaneXZ(pPlanes[vpl::img::PLANE_XZ], *spPlane);

                createTexture(vpl::img::PLANE_XZ, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;

        case GLUT_KEY_UP:
            if( pPlanes[vpl::img::PLANE_XZ] > 0 )
            {
                pPlanes[vpl::img::PLANE_XZ]--;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getXSize(), spVolume->getZSize()));
                spVolume->getPlaneXZ(pPlanes[vpl::img::PLANE_XZ], *spPlane);

                createTexture(vpl::img::PLANE_XZ, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;

        // YZ plane position
        case GLUT_KEY_RIGHT:
            if( pPlanes[vpl::img::PLANE_YZ] < (spVolume->getXSize() - 1) )
            {
                pPlanes[vpl::img::PLANE_YZ]++;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getYSize(), spVolume->getZSize()));
                spVolume->getPlaneYZ(pPlanes[vpl::img::PLANE_YZ], *spPlane);

                createTexture(vpl::img::PLANE_YZ, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;

        case GLUT_KEY_LEFT:
            if( pPlanes[vpl::img::PLANE_YZ] > 0 )
            {
                pPlanes[vpl::img::PLANE_YZ]--;

                vpl::img::CDImagePtr spPlane(new vpl::img::CDImage(spVolume->getYSize(), spVolume->getZSize()));
                spVolume->getPlaneYZ(pPlanes[vpl::img::PLANE_YZ], *spPlane);

                createTexture(vpl::img::PLANE_YZ, eColoring, spPlane);
            }
            glutPostRedisplay();
            break;
    }
}


// Called on mouse button action
void onMouseButton(int iButton, int iState, int x, int y)
{
    // Roatation
    if( iButton == GLUT_LEFT_BUTTON )
    {
        if( iState == GLUT_DOWN )
        {
            eMouseState = MOUSE_ROTATION;
            iPosX = x;
            iPosY = y;
        }
        else
        {
            eMouseState = MOUSE_NORMAL;
            iOldX = iNewX;
            iOldY = iNewY;
        }
    }

    // Zoom
    else if( iButton == GLUT_RIGHT_BUTTON )
    {
        if( iState == GLUT_DOWN )
        {
            eMouseState = MOUSE_ZOOM;
            iPosZ = y;
        }
        else
        {
            eMouseState = MOUSE_NORMAL;
            iOldZ = iNewZ;
        }
    }

    // Redraw the scene
    glutPostRedisplay();
}


// Called on mouse motion
void onMouseMotion(int x, int y)
{
    if( eMouseState == MOUSE_ROTATION )
    {
        // Compute the rotation
        iNewX = iOldX + x - iPosX;
        iNewY = iOldY + y - iPosY;
    }

    else if( eMouseState == MOUSE_ZOOM)
    {
#ifdef ENABLE_PERSPECTIVE
        iNewZ = iOldZ + y - iPosZ;
#else
        fGLZoom += (y - iPosZ) * fGLZoomStep;
        if( fGLZoom < fGLMinZoom )
        {
            fGLZoom = fGLMinZoom;
        }
        else if( fGLZoom > fGLMaxZoom )
        {
            fGLZoom = fGLMaxZoom;
        }
        iPosZ = y;
#endif // ENABLE_PERSPECTIVE
    }

    // Redisplay the scene
    glutPostRedisplay();
}

