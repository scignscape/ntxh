/*=========================================================================
  
   Program:   Visualization Toolkit
   Module:    QVTKOpenGLStereoWidget.h
  
   Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
   All rights reserved.
   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
  
      This software is distributed WITHOUT ANY WARRANTY; without even
      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
      PURPOSE.  See the above copyright notice for more information.
  
 =========================================================================*/
 #ifndef QVTKOpenGLStereoWidget_h
 #define QVTKOpenGLStereoWidget_h
  
 #include "vtkGUISupportQtModule.h" // For export macro
 #include <QWidget>
  
 #include "QVTKOpenGLWindow.h" // needed for ivar
 #include <QPointer>           // needed for ivar
  
 #include "vtkDeprecation.h" // For VTK_DEPRECATED_IN_9_0_0
  
 // Forward Qt class declarations
 class QSurfaceFormat;
 class QOpenGLContext;
  
 // class QVTKInteractor;
 class QVTKInteractorAdapter;
 class QVTKOpenGLWindow;
 class vtkGenericOpenGLRenderWindow;
 class vtkRenderWindow;
 class vtkRenderWindowInteractor;
  
 class VTKGUISUPPORTQT_EXPORT QVTKOpenGLStereoWidget : public QWidget
 {
   Q_OBJECT
   typedef QWidget Superclass;
  
 public:
   QVTKOpenGLStereoWidget(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
   QVTKOpenGLStereoWidget(
     QOpenGLContext* shareContext, QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
   QVTKOpenGLStereoWidget(vtkGenericOpenGLRenderWindow* w, QWidget* parent = nullptr,
     Qt::WindowFlags f = Qt::WindowFlags());
   QVTKOpenGLStereoWidget(vtkGenericOpenGLRenderWindow* w, QOpenGLContext* shareContext,
     QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
   ~QVTKOpenGLStereoWidget() override;
  
  
   void setRenderWindow(vtkGenericOpenGLRenderWindow* win)
   {
     this->VTKOpenGLWindow->setRenderWindow(win);
   }
   void setRenderWindow(vtkRenderWindow* win) { this->VTKOpenGLWindow->setRenderWindow(win); }
  
   vtkRenderWindow* renderWindow() const { return this->VTKOpenGLWindow->renderWindow(); }
  
   QVTKInteractor* interactor() const { return this->VTKOpenGLWindow->interactor(); }
  
   static QSurfaceFormat defaultFormat(bool stereo_capable = false)
   {
     return QVTKOpenGLWindow::defaultFormat(stereo_capable);
   }
  
   void setEnableHiDPI(bool enable) { this->VTKOpenGLWindow->setEnableHiDPI(enable); }
   bool enableHiDPI() const { return this->VTKOpenGLWindow->enableHiDPI(); }
  
  
   void setUnscaledDPI(int dpi) { this->VTKOpenGLWindow->setUnscaledDPI(dpi); }
   int unscaledDPI() const { return this->VTKOpenGLWindow->unscaledDPI(); }
  
  
   void setCustomDevicePixelRatio(double cdpr)
   {
     //?this->VTKOpenGLWindow->setCustomDevicePixelRatio(cdpr);
   };
   double customDevicePixelRatio() const
   {
    //? return this->VTKOpenGLWindow->customDevicePixelRatio();
   };
   double effectiveDevicePixelRatio() const
   {
     //? return this->VTKOpenGLWindow->effectiveDevicePixelRatio();
   };
  
  
   void setDefaultCursor(const QCursor& cursor) { this->VTKOpenGLWindow->setDefaultCursor(cursor); }
   const QCursor& defaultCursor() const { return this->VTKOpenGLWindow->defaultCursor(); }
  
   bool isValid() { return this->VTKOpenGLWindow->isValid(); }
  
   QImage grabFramebuffer();
  
   QVTKOpenGLWindow* embeddedOpenGLWindow() const { return this->VTKOpenGLWindow; }
  
   void setFormat(const QSurfaceFormat& fmt) { this->VTKOpenGLWindow->setFormat(fmt); }
  
   QSurfaceFormat format() const { return this->VTKOpenGLWindow->format(); }
  
  
   VTK_DEPRECATED_IN_9_0_0("Use QVTKOpenGLStereoWidget::setRenderWindow")
   void SetRenderWindow(vtkGenericOpenGLRenderWindow* win);
   VTK_DEPRECATED_IN_9_0_0("Use QVTKOpenGLStereoWidget::setRenderWindow")
   void SetRenderWindow(vtkRenderWindow* win);
  
  
   VTK_DEPRECATED_IN_9_0_0("Use QVTKOpenGLStereoWidget::renderWindow")
   vtkRenderWindow* GetRenderWindow();
   VTK_DEPRECATED_IN_9_0_0("Removed in 9.0.0 (internal)")
   QVTKInteractor* GetInteractor();
  
   VTK_DEPRECATED_IN_9_0_0("Removed in 9.0.0 (internal)")
   QVTKInteractorAdapter* GetInteractorAdapter();
  
   VTK_DEPRECATED_IN_9_0_0("Use QWidget::setCursor")
   void setQVTKCursor(const QCursor& cursor);
  
   VTK_DEPRECATED_IN_9_0_0("Use QWidget::setDefaultCursor")
   void setDefaultQVTKCursor(const QCursor& cursor);
  
 protected:
   void resizeEvent(QResizeEvent* evt) override;
   void paintEvent(QPaintEvent* evt) override;
  
 private:
   QPointer<QVTKOpenGLWindow> VTKOpenGLWindow;
 };
  
 #endif
