//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/20                          \n
 *
 * $Id: mdsSliceView.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * File description:
 * - Reads an image slice from the input channel.
 * - Draws the slice using GLUT and OpenGL.
 */

#include "mdsSliceView.h"

// OpenGL
#include <GL/gl.h>
#include <GL/glut.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! GLUT window title
const char GLUT_WINDOW_TITLE[]              = "MDSTk Slice View Window";

//! Module description
const std::string MODULE_DESCRIPTION        = "Module draws an input slice using GLUT and OpenGL";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS          = "coloring:alpha";

//! Additional arguments
const std::string MODULE_ARGUMENT_COLORING  = "coloring";
const std::string MODULE_ARGUMENT_ALPHA     = "alpha";

//! Default GLUT window position
const int GLUT_WINDOW_XPOS                  = 100;
const int GLUT_WINDOW_YPOS                  = 100;

//! Default GLUT window size
int GLUT_WINDOW_XSIZE                       = 512;
int GLUT_WINDOW_YSIZE                       = 512;

//! Type of the slice coloring method
enum ESliceColoring
{
    COL_GRAYSCALE = 1,
    COL_PSEUDO,
    COL_SEGMENTED
};

//! Allowed 'coloring' argument values
const std::string COL_GRAYSCALE_NAME        = "grayscale";
const std::string COL_PSEUDO_NAME            = "pseudo";
const std::string COL_SEGMENTED_NAME        = "segmented";

//! Default color argument
const std::string DEFAULT_COLORING_NAME        = COL_GRAYSCALE_NAME;

//! Default alpha argument value
const unsigned int DEFAULT_ALPHA            = 128;

//! Maximum pixel value
const unsigned int PIXEL_MAX                = mds::img::CPixelTraits<mds::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Global variables.
 */

//! Current GLUT window size
int iGlutWindowXSize                        = GLUT_WINDOW_XSIZE;
int iGlutWindowYSize                        = GLUT_WINDOW_YSIZE;

//! Texture numbers
GLuint puGLTextures[CSliceView::MAX_CHANNELS];

//! Size of the used texture part
GLfloat pfGLTextureXSize[CSliceView::MAX_CHANNELS];
GLfloat pfGLTextureYSize[CSliceView::MAX_CHANNELS];

//! Texture/polygon color alpha component
GLfloat pfGLTextureAlpha[CSliceView::MAX_CHANNELS];

//! Coloring method
ESliceColoring eColoring;

//! Alpha
unsigned int uAlpha;

//! The number of input channels
int iChannels;


//==============================================================================
/*
 * Global functions.
 */

//! Texture creation
void createTexture(int iNumber,
                   ESliceColoring Coloring,
                   mds::img::CSlice *pSlice
                   );


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
 * Implementation of the class CSliceView.
 */
CSliceView *CSliceView::m_pView = NULL;


CSliceView::CSliceView(const std::string& sDescription)
    : mds::mod::CView(sDescription)
{
    MDS_ASSERT(m_pView == NULL);
    m_pView = this;

    allowArguments(MODULE_ARGUMENTS);
}


CSliceView::~CSliceView()
{
}


bool CSliceView::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // The number of input channels
    iChannels = getNumOfInputs();

    // Test of existence of input channel
    if( iChannels < 1 || iChannels > CSliceView::MAX_CHANNELS )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input channels" << std::endl);
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
        MDS_CERR('<' << m_sFilename << "> Bad 'coloring' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Alpha channel
    uAlpha = DEFAULT_ALPHA;
    m_Arguments.value(MODULE_ARGUMENT_ALPHA, uAlpha);
    if( uAlpha > 0xff )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'alpha' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceView::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // Read the data from all input slices
    bool bSliceRead = false;
    for( int i = 0; i < iChannels; ++i )
    {
        // Input channel
        mds::mod::CChannel *pIChannel = getInput(i);

        // Wait while channel is not closed
        while( pIChannel->isConnected() )
        {
            // Wait for data
            if( pIChannel->wait(1000) )
            {
                // Read the slice from input channel
                if( readInput(pIChannel, m_pSlices + i) )
                {
                    bSliceRead = true;
                    break;
                }
                else
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
                    return false;
                }
            }
            else
            {
                MDS_LOG_NOTE("Wait timeout");
            }
        }
    }

    // Draw the read slices
    if( bSliceRead )
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


void CSliceView::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceView::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-coloring Type] [-alpha Alpha]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -coloring  Selects the coloring method. Allowed types are grayscale," << std::endl);
    MDS_CERR("             pseudo and segmented. Pseudo shows a given slice colored" << std::endl);
    MDS_CERR("             instead of grayscale. In case the pixel value represents" << std::endl);
    MDS_CERR("             image segment, the segmented type shows it." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -alpha  Adjusts transparency of input slices. Actually, two input" << std::endl);
    MDS_CERR("          input channels are allowed. The one read" << std::endl);
    MDS_CERR("          from the second input channel is used as a background image," << std::endl);
    MDS_CERR("          no coloring is applied. All slices are combined using" << std::endl);
    MDS_CERR("          a simple blending method regarding a given alpha color" << std::endl);
    MDS_CERR("          component. Allowed values are within the range 0..255. If no" << std::endl);
    MDS_CERR("          value is specified the default number " << DEFAULT_ALPHA << " is used." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk slice" << std::endl);
    MDS_CERR("Output: none" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes view application.
 */
int main(int argc, char *argv[])
{
    // Creation of a view module using smart pointer
    CSliceViewPtr spView(new CSliceView(MODULE_DESCRIPTION));

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
void createTexture(int iNumber,
                   ESliceColoring Coloring,
                   mds::img::CSlice *pSlice
                   )
{
    // Set texture image parameters
    glBindTexture(GL_TEXTURE_2D, puGLTextures[iNumber]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Image size
    mds::tSize XSize = pSlice->getXSize();
    mds::tSize YSize = pSlice->getYSize();

    // Texture dimensions
    mds::tSize TexXSize = 2, TexYSize = 2;
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
    pfGLTextureXSize[iNumber] = (GLfloat)XSize / (GLfloat)TexXSize;
    pfGLTextureYSize[iNumber] = (GLfloat)YSize / (GLfloat)TexYSize;

    // Allocate texture RGBA data
    unsigned char *pucRGBTexture = new unsigned char[TexXSize * TexYSize * 3];
    memset(pucRGBTexture, 0, TexXSize * TexYSize * 3);

    // Create required texture
    switch( Coloring )
    {
        // Segmented RGB texture
        case COL_SEGMENTED: {
            // Number of segments
            double dMin = mds::img::getMin<double>(*pSlice);
            double dMax = mds::img::getMax<double>(*pSlice);
            double dSegments = dMax - dMin + 1.0;
            double dConst = PIXEL_MAX / dSegments;

            // Convert slice pixels
            for( mds::tSize j = 0; j < YSize; ++j )
            {
                for( mds::tSize i = 0; i < XSize; i++ )
                {
                    double dTemp = (pSlice->at(i, j) - dMin) * dConst;
                    pSlice->set(i, j, (mds::img::CSlice::tPixel)dTemp);
                }
            }
        }

        // Pseudo color RGB texture
        case COL_PSEUDO: {
            // Pseudo coloring of grayscale image
            double dConst = 6.0 / (double)PIXEL_MAX;
            for( mds::tSize j = 0; j < YSize; ++j )
            {
                unsigned char *p = &pucRGBTexture[j * TexXSize * 3];
                for( mds::tSize i = 0; i < XSize; ++i )
                {
                    double dSegment = dConst * pSlice->at(i, j);
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
            for( mds::tSize j = 0; j < YSize; ++j )
            {
                unsigned char *p = &pucRGBTexture[j * TexXSize * 3];
                for( mds::tSize i = 0; i < XSize; ++i )
                {
                    unsigned char ucTemp = (unsigned char)pSlice->at(i, j);
                    *(p++) = ucTemp;
                    *(p++) = ucTemp;
                    *(p++) = ucTemp;
                }
            }
        } break;
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
    glGenTextures(iChannels, puGLTextures);

    // Slice size
    int XSize = (int)CSliceView::getViewPtr()->getSlice(0)->getXSize();
    int YSize = (int)CSliceView::getViewPtr()->getSlice(0)->getYSize();

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
    if( iChannels > 1 )
    {
        createTexture(iChannels - 1, COL_GRAYSCALE, CSliceView::getViewPtr()->getSlice(iChannels - 1));
    }
    else
    {
        createTexture(iChannels - 1, eColoring, CSliceView::getViewPtr()->getSlice(0));
    }
    pfGLTextureAlpha[iChannels - 1] = 1.0f;

    // Create other textures
    for( int i = 0; i < (iChannels - 1); ++i )
    {
        createTexture(i, eColoring, CSliceView::getViewPtr()->getSlice(i));
        pfGLTextureAlpha[i] = (GLfloat)uAlpha / 255.0f;
    }

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

    // Draw the background polygon (last input slice)
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, puGLTextures[iChannels - 1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3i(0, 0, 0);

    glTexCoord2f(pfGLTextureXSize[iChannels - 1], 0.0f);
    glVertex3i(iGlutWindowXSize, 0, 0);

    glTexCoord2f(pfGLTextureXSize[iChannels - 1], pfGLTextureYSize[iChannels - 1]);
    glVertex3i(iGlutWindowXSize, iGlutWindowYSize, 0);

    glTexCoord2f(0.0f, pfGLTextureYSize[iChannels - 1]);
    glVertex3i(0, iGlutWindowYSize, 0);
    glEnd();

    // Enable the blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    // Enable polygon offset
    glPolygonOffset(-1, -1);
    glEnable(GL_POLYGON_OFFSET_FILL);

    // Draw polygons representing the input slices
    for( int i = 0; i < (iChannels - 1); ++i )
    {
        glColor4f(1.0f, 1.0f, 1.0f, pfGLTextureAlpha[i]);
        glBindTexture(GL_TEXTURE_2D, puGLTextures[i]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3i(0, 0, 0);

        glTexCoord2f(pfGLTextureXSize[i], 0.0f);
        glVertex3i(iGlutWindowXSize, 0, 0);

        glTexCoord2f(pfGLTextureXSize[i], pfGLTextureYSize[i]);
        glVertex3i(iGlutWindowXSize, iGlutWindowYSize, 0);

        glTexCoord2f(0.0f, pfGLTextureYSize[i]);
        glVertex3i(0, iGlutWindowYSize, 0);
        glEnd();
    }

    // Disable polygon offset
    glDisable(GL_POLYGON_OFFSET_FILL);

    // Disable blending
    glDisable(GL_BLEND);

    // Disable textures
    glDisable(GL_TEXTURE_2D);

    // Draw changes
    glFlush();
    glutSwapBuffers();
}


// Called on ASCII key pressed
void onKeyboard(unsigned char ucKey, int MDS_UNUSED(iX), int MDS_UNUSED(iY))
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
            MDS_CERR("Keyboard Shortcuts:" << std::endl);
            MDS_CERR(" h  Shows this help." << std::endl);
            MDS_CERR(" f  Switches to the fullscreen mode." << std::endl);
            MDS_CERR(" w  Switches back to the window." << std::endl);
            MDS_CERR(" c  Exits the program." << std::endl);
            break;
    }
}

