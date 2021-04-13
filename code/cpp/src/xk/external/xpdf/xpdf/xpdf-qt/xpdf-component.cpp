//  BASED ON (with small modifications) code Copyright 2015 Glyph & Cog, LLC

//  This specific file and project
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <aconf.h>

#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "parseargs.h"
#include "GString.h"
#include "GList.h"
#include "GlobalParams.h"
#include "XpdfViewer.h"
#include "xpdf-component.h"
#include "gmempp.h"

#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <QNetworkAccessManager>
#include <QNetworkReply>

//------------------------------------------------------------------------
// command line options
//------------------------------------------------------------------------

static GBool reverseVideoArg = gFalse;
static char paperColorArg[256] = "";
static char matteColorArg[256] = "";
static char fsMatteColorArg[256] = "";
static char initialZoomArg[256] = "";
static char antialiasArg[16] = "";
static char vectorAntialiasArg[16] = "";
static char textEncArg[128] = "";
static char passwordArg[33] = "";
static GBool fullScreen = gFalse;
static char cfgFileArg[256] = "";
static GBool printCommandsArg = gFalse;
static GBool printVersionArg = gFalse;
static GBool printHelpArg = gFalse;

static ArgDesc argDesc[] = {
 {"-rv",           argFlag,   &reverseVideoArg,   0,                          "reverse video"},
 {"-papercolor",   argString, paperColorArg,      sizeof(paperColorArg),      "color of paper background"},
 {"-mattecolor",   argString, matteColorArg,      sizeof(matteColorArg),      "color of matte background"},
 {"-fsmattecolor", argString, fsMatteColorArg,    sizeof(fsMatteColorArg),    "color of matte background in full-screen mode"},
 {"-z",            argString, initialZoomArg,     sizeof(initialZoomArg),     "initial zoom level (percent, 'page', 'width')"},
 {"-aa",           argString, antialiasArg,       sizeof(antialiasArg),       "enable font anti-aliasing: yes, no"},
 {"-aaVector",     argString, vectorAntialiasArg, sizeof(vectorAntialiasArg), "enable vector anti-aliasing: yes, no"},
 {"-enc",          argString, textEncArg,         sizeof(textEncArg),         "output text encoding name"},
 {"-pw",           argString, passwordArg,        sizeof(passwordArg),        "password (for encrypted files)"},
 {"-fullscreen",   argFlag,   &fullScreen,        0,                          "run in full-screen (presentation) mode"},
 {"-cmd",          argFlag,   &printCommandsArg,  0,                          "print commands as they're executed"},
 {"-cfg",          argString, cfgFileArg,         sizeof(cfgFileArg),         "configuration file to use in place of .xpdfrc"},
 {"-v",            argFlag,   &printVersionArg,   0,                          "print copyright and version info"},
 {"-h",            argFlag,   &printHelpArg,      0,                          "print usage information"},
 {"-help",         argFlag,   &printHelpArg,      0,                          "print usage information"},
 {"--help",        argFlag,   &printHelpArg,      0,                          "print usage information"},
 {"-?",            argFlag,   &printHelpArg,      0,                          "print usage information"},
 {NULL}
};

void xpdf_component_main(int argc, char *argv[], Xpdf_Component** _xpc,
  QPoint dlg_point, QDialog* origin_dlg, QString origin_msg)
{
 Xpdf_Component* xpc = new Xpdf_Component(argc, argv, dlg_point,
   origin_dlg, origin_msg);
 if(_xpc)
   *_xpc = xpc;
}

//------------------------------------------------------------------------
// Xpdf_Component
//------------------------------------------------------------------------

Xpdf_Component::Xpdf_Component(int &argc, char **argv,
  QPoint dlg_point, QDialog* origin_dlg, QString origin_msg)
{
 const char *fileName, *dest;
 GString *color;
 GBool ok;
 int pg, i;

// // skipping this for embedded ...
// setApplicationName("XpdfReader");
// setApplicationVersion(xpdfVersion);

 ok = parseArgs(argDesc, &argc, argv);
 if (!ok || printVersionArg || printHelpArg) {
  fprintf(stderr, "xpdf version %s\n", xpdfVersion);
  fprintf(stderr, "%s\n", xpdfCopyright);
  if (!printVersionArg) {
   printUsage("xpdf", "[<PDF-file> [:<page> | +<dest>]] ...", argDesc);
  }
  ::exit(99);
 }

 //--- set up GlobalParams; handle command line arguments
 globalParams = new GlobalParams(cfgFileArg);
#ifdef _WIN32
 QString dir; // // this is N/A ... = applicationDirPath();
 globalParams->setBaseDir(dir.toLocal8Bit().constData());
 dir += "/t1fonts";
 globalParams->setupBaseFonts(dir.toLocal8Bit().constData());
#else
 globalParams->setupBaseFonts(NULL);
#endif
 if (initialZoomArg[0]) {
  globalParams->setInitialZoom(initialZoomArg);
 }
 reverseVideo = reverseVideoArg;
 if (paperColorArg[0]) {
  paperColor = QColor(paperColorArg);
 } else {
  color = globalParams->getPaperColor();
  paperColor = QColor(color->getCString());
  delete color;
 }
 if (reverseVideo) {
  paperColor = QColor(255 - paperColor.red(),
                      255 - paperColor.green(),
                      255 - paperColor.blue());
 }
 if (matteColorArg[0]) {
  matteColor = QColor(matteColorArg);
 } else {
  color = globalParams->getMatteColor();
  matteColor = QColor(color->getCString());
  delete color;
 }
 if (fsMatteColorArg[0]) {
  fsMatteColor = QColor(fsMatteColorArg);
 } else {
  color = globalParams->getFullScreenMatteColor();
  fsMatteColor = QColor(color->getCString());
  delete color;
 }
 if (antialiasArg[0]) {
  if (!globalParams->setAntialias(antialiasArg)) {
   fprintf(stderr, "Bad '-aa' value on command line\n");
  }
 }
 if (vectorAntialiasArg[0]) {
  if (!globalParams->setVectorAntialias(vectorAntialiasArg)) {
   fprintf(stderr, "Bad '-aaVector' value on command line\n");
  }
 }
 if (textEncArg[0]) {
  globalParams->setTextEncoding(textEncArg);
 }
 if (printCommandsArg) {
  globalParams->setPrintCommands(gTrue);
 }

 errorEventType = QEvent::registerEventType();

 viewers = new GList();

 if(!dlg_point.isNull())
 {
  QMessageBox msg(QMessageBox::Information, "About XPDF",
    "The XPDF Component is based on XPDF Software Copyright 2015 "
    "by Glyph & Cog, Inc.  This version of XPDF has been "
    "customized to work with the current data set.  Please see the "
    "dataset documentation for more information");

  if(!origin_msg.isEmpty())
    msg.setInformativeText(origin_msg);
  msg.exec();
 }

 //newWindow(fullScreen);
 //--- load PDF file(s) requested on the command line
 if (argc >= 2) {
  i = 1;
  while (i < argc) {
   pg = 1;
   dest = "";
   if (i+1 < argc && argv[i+1][0] == ':') {
    fileName = argv[i];
    pg = atoi(argv[i+1] + 1);
    i += 2;
   } else if (i+1 < argc && argv[i+1][0] == '+') {
    fileName = argv[i];
    dest = argv[i+1] + 1;
    i += 2;
   } else {
    fileName = argv[i];
    ++i;
   }
   if (viewers->getLength() > 0) {
    ok = ((XpdfViewer *)viewers->get(0))->openInNewTab(fileName, pg, dest,
                                                       passwordArg,
                                                       gFalse);
   } else {
    ok = openInNewWindow(fileName, pg, dest, passwordArg, fullScreen);
   }
  }
 } else
 {
  state_ = "<ready>";
 }
}

Xpdf_Component::~Xpdf_Component() {
 delete viewers;
 delete globalParams;
}

int Xpdf_Component::getNumViewers() {
 return viewers->getLength();
}

void Xpdf_Component::newWindow(GBool fullScreen) {
 XpdfViewer *viewer = new XpdfViewer(this, fullScreen);
 viewers->append(viewer);
 viewer->show();

 // //  R/Z
 state_ = "<ready>";
}

GBool Xpdf_Component::openInNewWindow(QString fileName, int page, QString dest,
                               QString password, GBool fullScreen) {
 XpdfViewer *viewer;

 viewer = XpdfViewer::create(this, fileName, page, dest, password, fullScreen);
 if (!viewer) {
  return gFalse;
 }
 viewers->append(viewer);
 viewer->tweakSize();

 // //  added for the data set -- is this right?
//? viewer->setWindowFlags(Qt::WindowStaysOnTopHint);

 viewer->show();
 return gTrue;
}

void Xpdf_Component::closeWindowOrQuit(XpdfViewer *viewer) {
 int i;

 viewer->close();
 for (i = 0; i < viewers->getLength(); ++i) {
  if ((XpdfViewer *)viewers->get(i) == viewer) {
   viewers->del(i);
   break;
  }
 }
}

void Xpdf_Component::quit() {
 XpdfViewer *viewer;

 while (viewers->getLength()) {
  viewer = (XpdfViewer *)viewers->del(0);
  viewer->close();
 }
 QApplication::quit();
}
