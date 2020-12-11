// ***************** DO NOT EDIT ***********************************
// This is a generated file.
// It will be replaced next time you rebuild.
/*=========================================================================

   Program: paraview
   Module:  paraview_main.cxx

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#include <QApplication>
#include <QLocale>
#include <QStyleFactory>
#include <QSurfaceFormat>

#include "pqparaviewInitializer.h"
#include "vtkPVConfig.h"
// See Applications/ParaView/CMakeLists.txt for why this is necessary.

//?#define _paraview_client_PLUGINS_TARGET 1

#define _paraview_client_PLUGINS_TARGET 0


#if _paraview_client_PLUGINS_TARGET
#include "paraview_plugins.h"
#endif

#include <vtksys/SystemTools.hxx>
#include <QVTKRenderWindowAdapter.h>

#include <clocale>
#include <cstdlib>

int main(int argc, char* argv[])
{
  QApplication::setStyle(QStyleFactory::create("plastique"));

//?
//  // When playing tests, disable all effects.
//  if (vtksys::SystemTools::HasEnv("DART_TEST_FROM_DART") ||
//      vtksys::SystemTools::HasEnv("DASHBOARD_TEST_FROM_CTEST"))
//  {
//    QApplication::setDesktopSettingsAware(false);
//    QApplication::setEffectEnabled(Qt::UI_AnimateMenu, false);
//    QApplication::setEffectEnabled(Qt::UI_FadeMenu, false);
//    QApplication::setEffectEnabled(Qt::UI_AnimateCombo, false);
//    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, false);
//    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, false);
//  }

  QApplication::setApplicationName("ParaView");
  QApplication::setApplicationVersion("5.7.0");
  QApplication::setOrganizationName("ParaView");

  // supports HDPI
  QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

#if _paraview_client_PLUGINS_TARGET
  paraview_plugins_initialize();
#endif

  // always request a non-stereo format; when using quadbuffer stereo, we
  // request stereo capable format for the individual `QVTKOpenGLWindow`
  // instance.
//?  QSurfaceFormat::setDefaultFormat(QVTKRenderWindowAdapter::defaultFormat(/*supports_stereo=*/false));

  QApplication qtapp(argc, argv);
  // QApplication docs suggest resetting to "C" after the QApplication is
  // initialized.
  setlocale(LC_NUMERIC, "C");

  // However, this is needed to address BUG #17225, #17226.
  QLocale::setDefault(QLocale::c());

  using InitializerT = pqparaviewInitializer;

  InitializerT pvInitializer;
  InitializerT::Status status = pvInitializer.Initialize(argc, argv);
  switch (status)
  {
    case InitializerT::ExitSuccess:
      return EXIT_SUCCESS;
    case InitializerT::ExitFailure:
      return EXIT_FAILURE;
    case InitializerT::RunApplication:
      return qtapp.exec();
  }
}
