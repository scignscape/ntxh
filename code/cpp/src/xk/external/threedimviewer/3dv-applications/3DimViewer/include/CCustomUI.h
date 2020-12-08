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

#ifndef CCUSTOMUI_H
#define CCUSTOMUI_H

//! Includes
#include <configure.h>

#include <QSplitter>
#include <QSlider>
#include <QMouseEvent>
#include <QStyle>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QStyleOptionSlider>
#include <QDockWidget>
#include <QMainWindow>
#include <QCloseEvent>

#include <VPL/Module/Signal.h>
#include <data/CStorageEntry.h>

class OSGCanvas;
class QToolButton;
class CCustomDockWidget;

/////////////////////////////////////////////////////
// Event filter for tabs - hide dockwidget on tab middle button click

class TabBarMouseFunctionalityEx : public QObject
 {
     Q_OBJECT
 protected:
     bool eventFilter(QObject *obj, QEvent *event);
 };

///////////////////////////////////////////////////////////////////////////////
// Custom splitter for synchronization of multiple splitters

//! Special splitter that makes moveSplitter method public
//! It's because we have more nested splitters and need to synchronize them
class CSyncedSplitter : public QSplitter
{
    Q_OBJECT
protected:
    bool m_bIgnoreMove;
public:
    CSyncedSplitter(Qt::Orientation o) : QSplitter(o) { m_bIgnoreMove=false; }
    void setIgnoreMove(bool bIgnore) { m_bIgnoreMove = bIgnore; }
    bool ignoreMove() { return m_bIgnoreMove; }
    void moveSplitter ( int pos, int index ) { QSplitter::moveSplitter(pos,index);}
};

///////////////////////////////////////////////////////////////////////////////
// Custom slider with opacity and reset on double click

class CSliderEx : public QSlider
{
    Q_OBJECT
protected:
    //! Button opacity
    float m_opacity;
public:
    //! Constructor which sets up an opacity effect
    CSliderEx(Qt::Orientation orientation, QWidget* pParent = NULL, float opacity=0.3) :
        QSlider(orientation, pParent),
        m_opacity(opacity)
    {
    #ifndef __APPLE__ // no transparency on apple
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
        effect->setOpacity(m_opacity);
        setGraphicsEffect(effect);
    #endif         
    }

protected:
    //! On mouse enter change to fully opaque
    void enterEvent(QEvent *event)
    {
        // TODO: use QPropertyAnimation for smoother transition?
        QGraphicsEffect * pEffect = graphicsEffect();
        if (NULL!=pEffect)
        {
            QGraphicsOpacityEffect* pOpacity=dynamic_cast<QGraphicsOpacityEffect*>(pEffect);
            if (pOpacity)
            {
                //pOpacity->setOpacity(1);
                fadeToOpacity(this,pOpacity,1,100);
            }
        }
        QSlider::enterEvent(event);
    }
    //! On mouse leave change to partially opaque
    void leaveEvent(QEvent *event)
    {
        QGraphicsEffect * pEffect = graphicsEffect();
        if (NULL!=pEffect)
        {
            QGraphicsOpacityEffect* pOpacity=dynamic_cast<QGraphicsOpacityEffect*>(pEffect);
            if (pOpacity)
            {
                fadeToOpacity(this,pOpacity,m_opacity,500);
                //pOpacity->setOpacity(m_opacity);
            }
        }
        QSlider::leaveEvent(event);
    }
    //! Reset on mouse double click on slider handle
    void mouseDoubleClickEvent(QMouseEvent *event)
    {
        QStyleOptionSlider opt;
        initStyleOption(&opt);
        QRect rcHandle = this->style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
        if (rcHandle.contains(event->pos()))
        {
            int average=(minimum()+maximum())/2;
            setValue(average);
        }
        else
            QSlider::mouseDoubleClickEvent(event);
    }
    void fadeToOpacity(QWidget *pParent, QGraphicsOpacityEffect* pOpacity, float opacity, int duration)
    {
        QPropertyAnimation* anim = new QPropertyAnimation(pParent);
        anim->setTargetObject(pOpacity);
        anim->setPropertyName("opacity");
        anim->setDuration(duration);
        anim->setStartValue(pOpacity->opacity());
        anim->setEndValue(opacity);
        anim->setEasingCurve(QEasingCurve::OutQuad);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
    }
};

///////////////////////////////////////////////////////////////////////////////
// Custom Dock Widget title implementation

//! Custom QDockWidget title with maximize button
//! supports only QSplitter at the moment
class CCustomDockWidgetTitle : public QWidget
{
    Q_OBJECT
protected:
    bool  m_bMaximized, m_bIconMaximize, m_bPinned, m_bIconPin;
    QToolButton* m_maximizeButton;
    QToolButton* m_closeButton;
    QToolButton* m_screenshotButton;
    QToolButton* m_pinButton;
    QToolButton* m_viewButton;
    QSlider*     m_slider;
    QAction* m_action3D;
    QAction* m_actionXY;
    QAction* m_actionXZ;
    QAction* m_actionYZ;
    QAction* m_actionARB;
    std::vector<QAction*> m_actionList;
    //! Signal connections
    vpl::mod::tSignalConnection m_vrDataRemapChangeConnection;
    vpl::mod::tSignalConnection m_ConnectionData;
    vpl::mod::tSignalConnection m_ConnectionXY, m_ConnectionXZ, m_ConnectionYZ, m_ConnectionARB;
    //! Sizes
    int          m_dockButtonSize;
    int          m_dockTitleHeight;

    int m_viewType;

public:
    // please note that the following values are actually flags!
#define DWT_BUTTONS_NONE        0
#define DWT_BUTTONS_CLOSE       1
#define DWT_BUTTONS_MAXIMIZE    2
#define DWT_BUTTONS_PIN         4
#define DWT_BUTTONS_VIEW        8
#define DWT_SLIDER_VR           16
#define DWT_SLIDER_XY           32
#define DWT_SLIDER_XZ           64
#define DWT_SLIDER_YZ           128
#define DWT_SLIDER_ARB          256

    CCustomDockWidgetTitle(int viewType, int flags = DWT_BUTTONS_MAXIMIZE, QWidget* parent = 0);
    virtual ~CCustomDockWidgetTitle();
    QSize sizeHint() const { return minimumSizeHint(); }
    QSize minimumSizeHint() const;
    void    vrDataRemapChange(float expand, float offset);
    //! Called on volume data change.
    void onNewDensityData(data::CStorageEntry *pEntry);
    //! Called on slice change.
    void onNewSliceXY(data::CStorageEntry *pEntry);
    void onNewSliceXZ(data::CStorageEntry *pEntry);
    void onNewSliceYZ(data::CStorageEntry *pEntry);
    void onNewSliceARB(data::CStorageEntry *pEntry);
    void setPinned(bool pinned);
    void removeActionFromViewButton(int actionIndex);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void createLayout(int flags);
    void createMenuForViewButton();
protected slots:
    void btnCloseClicked();
    void btnMaximizeClicked();
    void btnScreenshotClicked();
    void btnPinClicked();
    void vrValueChanged(int);
    void xySliderChange(int value);
    void xzSliderChange(int value);
    void yzSliderChange(int value);
    void arbSliderChange(int value);
    void show3DView();
    void showXYView();
    void showXZView();
    void showYZView();
    void showARBView();
signals:
    void saveScreenshotOfCanvas(OSGCanvas* pCanvas);
    void copyScreenshotToClipboard(OSGCanvas* pCanvas);
    void saveSlice(OSGCanvas* pCanvas, int mode);
};

class CCustomDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    CCustomDockWidget(int viewType, const QString &title, QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    CCustomDockWidget(int viewType, QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~CCustomDockWidget();

    void setFloating(bool floating);

protected:
    int m_viewType;
};

///////////////////////////////////////////////////////////////////////////////
//! Custom main window for showing floating dock widgets

class CFloatingMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CFloatingMainWindow(int windowType, bool has2DCanvas = true, QWidget* parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~CFloatingMainWindow();

private:
    void closeEvent(QCloseEvent* event);
    void enterEvent(QEvent* event);

protected:
    int m_windowType;
};

#endif // CCUSTOMUI_H
