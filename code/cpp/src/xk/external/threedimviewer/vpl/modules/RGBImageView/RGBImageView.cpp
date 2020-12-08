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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/13                       
 *
 * File description:
 * - Reads RGB image from the input channel and draws it using GLUT and OpenGL.
 */

#include "RGBImageView.h"

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
 * Global constants.
 */

//! GLUT window title
const char GLUT_WINDOW_TITLE[]              = "VPL Image View";

//! Module description
const std::string MODULE_DESCRIPTION        = "Module draws input RGB image using GLUT and OpenGL";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS          = "";

//! Additional arguments

//! Default GLUT window position
const int GLUT_WINDOW_XPOS                  = 100;
const int GLUT_WINDOW_YPOS                  = 100;

//! Default GLUT window size
int GLUT_WINDOW_XSIZE                       = 512;
int GLUT_WINDOW_YSIZE                       = 512;

// Maximum pixel value
//const unsigned int PIXEL_MAX                = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Global variables.
 */

//! Current GLUT window size
int iGlutWindowXSize                        = GLUT_WINDOW_XSIZE;
int iGlutWindowYSize                        = GLUT_WINDOW_YSIZE;

//! Texture numbers
GLuint uGLTexture;

//! Size of the used texture part
GLfloat fGLTextureXSize;
GLfloat fGLTextureYSize;


//==============================================================================
/*
 * Global functions.
 */

//! Texture creation
void createTexture(vpl::img::CRGBImage& RGBImage);


//==============================================================================
/*
 * GLUT functions.
 */

//! Callback functions
void onInit();
void onResize(int iWidth, int iHeight);
void onDisplay(void);
void onKeyboard(unsigned char ucKey, int iX, int iY);


//==============================================================================
/*
 * Implementation of the class CRGBImageView.
 */
CRGBImageView *CRGBImageView::m_pView = NULL;


CRGBImageView::CRGBImageView(const std::string& sDescription)
    : vpl::mod::CView(sDescription)
{
    VPL_ASSERT(m_pView == NULL);
    m_pView = this;

    allowArguments(MODULE_ARGUMENTS);
}


CRGBImageView::~CRGBImageView()
{
}


bool CRGBImageView::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input channel
    if( getNumOfInputs() < 1 || getNumOfInputs() > 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CRGBImageView::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // Input channel
    vpl::mod::CChannel *pIChannel = getInput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new RGB image
    vpl::img::CRGBImagePtr spImage;

    // Wait for data
    bool bImageRead = false;
    if( pIChannel->wait(1000) )
    {
        // Read the slice from input channel
        if( readInput(pIChannel, m_spRGBImage.get()) )
        {
            bImageRead = true;
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            return false;
        }
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Draw the read slices
    if( bImageRead )
    {
        // Initilialize the GLUT library
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow(GLUT_WINDOW_TITLE);
        glutDisplayFunc(onDisplay);
        glutReshapeFunc(onResize);
        glutKeyboardFunc(onKeyboard);

        // Initalize module
        onInit();

        // Run GLUT event processing loop
        glutMainLoop();
    }

    // Do not continue
    return false;
}


void CRGBImageView::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CRGBImageView::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Input: MDSTk RGB image" << std::endl;
    Stream << "Output: none" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes view application.
 */
int main(int argc, char *argv[])
{
    // Creation of a view module using smart pointer
    CRGBImageViewPtr spView(new CRGBImageView(MODULE_DESCRIPTION));

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
 * GLUT functions implementation.
 */

// Creation of a GL RGB texture
void createTexture(vpl::img::CRGBImage *pRGBImage)
{
    // Set texture image parameters
    glBindTexture(GL_TEXTURE_2D, uGLTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Image size
    vpl::tSize XSize = pRGBImage->getXSize();
    vpl::tSize YSize = pRGBImage->getYSize();

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
    if( TexXSize > iMaxTexDim )
    {
        XSize = TexXSize = iMaxTexDim;
        YSize = TexYSize = iMaxTexDim;
    }

    // Used texture size
    fGLTextureXSize = (GLfloat)XSize / (GLfloat)TexXSize;
    fGLTextureYSize = (GLfloat)YSize / (GLfloat)TexYSize;

    // Allocate texture RGBA data
    unsigned char *pucRGBTexture = new unsigned char[TexXSize * TexYSize * 3];
    memset(pucRGBTexture, 0, TexXSize * TexYSize * 3);

    // Create required texture
    for( vpl::tSize j = 0; j < YSize; ++j )
    {
        unsigned char *p = &pucRGBTexture[j * TexXSize * 3];
        for( vpl::tSize i = 0; i < XSize; ++i )
        {
            vpl::img::tRGBPixel Value = pRGBImage->at(i,j);
            *(p++) = Value.r();
            *(p++) = Value.g();
            *(p++) = Value.b();
        }
    }

    // Define 2D texture image
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 TexXSize,
                 TexYSize,
                 0, GL_RGB, GL_UNSIGNED_BYTE,
                 pucRGBTexture
                 );

    // Free the memory
    delete[] pucRGBTexture;
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
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Generate texture names
    glGenTextures(1, &uGLTexture);

    // RGBImage size
    int XSize = (int)CRGBImageView::getViewPtr()->getRGBImage()->getXSize();
    int YSize = (int)CRGBImageView::getViewPtr()->getRGBImage()->getYSize();

    // Modify glut window size to keep image dimensions ratio
    if( XSize > YSize )
    {
        GLUT_WINDOW_YSIZE = GLUT_WINDOW_XSIZE * YSize / XSize;
    }
    else
    {
        GLUT_WINDOW_XSIZE = GLUT_WINDOW_YSIZE * XSize / YSize;
    }

    // Create the background polygon texture
    createTexture(CRGBImageView::getViewPtr()->getRGBImage());

    // Initialize glut window
    glutPositionWindow(GLUT_WINDOW_XPOS, GLUT_WINDOW_YPOS);
    glutReshapeWindow(GLUT_WINDOW_XSIZE, GLUT_WINDOW_YSIZE);
}


// Sets coordinate system depending on the window size
void onResize(int iWidth, int iHeight)
{
    iGlutWindowXSize = iWidth;
    iGlutWindowYSize = iHeight;

    // Set the viewport
    glViewport(0, 0, iWidth, iHeight);

    // Projection matrix modification
    glMatrixMode(GL_PROJECTION);

    // Clear the projection matrix
    glLoadIdentity();

    // Map abstract coordinates to the window coordinates
    glOrtho(0, iWidth, 0, iHeight, -1, 1);

    // Invert y-axis
    glScalef(1, -1, 1);

    // Translate the origin to the top left corner
    glTranslatef(0, -iHeight, 0);
}


// Displays the window
void onDisplay(void)
{
    // Clear the color buffer and z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Enable textures
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);

    // Draw the polygon
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, uGLTexture);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3i(0, 0, 0);

        glTexCoord2f(fGLTextureXSize, 0.0f);
        glVertex3i(iGlutWindowXSize, 0, 0);

        glTexCoord2f(fGLTextureXSize, fGLTextureYSize);
        glVertex3i(iGlutWindowXSize, iGlutWindowYSize, 0);

        glTexCoord2f(0.0f, fGLTextureYSize);
        glVertex3i(0, iGlutWindowYSize, 0);
    glEnd();

    // Disable textures
    glDisable(GL_TEXTURE_2D);

    // Draw changes
    glFlush();
    glutSwapBuffers();
}


// Called on ASCII key pressed
void onKeyboard(unsigned char ucKey, int, int)
{
    // Translate to lower case
    ucKey = (ucKey > 'A' && ucKey <= 'Z') ? ucKey + 'a' - 'A' : ucKey;

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

        // Help
        case 'h':
            VPL_LOG_ERROR("Keyboard Shortcuts:" << std::endl);
            VPL_LOG_ERROR(" h  Shows this help." << std::endl);
            VPL_LOG_ERROR(" f  Switches to the fullscreen mode." << std::endl);
            VPL_LOG_ERROR(" w  Switches back to the window." << std::endl);
            VPL_LOG_ERROR(" c  Exits the program." << std::endl);
            break;
    }
}

