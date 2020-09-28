

// // license___here_h


#include "gui/panes/ViewsPane.h"
#include "gui/panes/GateStatsPane.h"
#include "gui/lengthprofile/ProfilePane.h"
#include "gui/panes/CompensationPane.h"
#include "resource/ImgResource.h"

#include "gui/view/GraphExporter.h"

#include "data/Dataset.h"
#include "data/ProfChannel.h"

#include "gates/GateSet.h"
#include "gates/gate-info.h"
#include "gates/measure/GateMeasure.h"
#include "gates/GatingResult.h"

#include "gui/view/tool/ViewToolDrawEllipse.h"
#include "gui/view/tool/ViewToolDrawSelect.h"
#include "gui/view/tool/ViewToolDrawRange.h"
#include "gui/view/tool/ViewToolDrawPoly.h"
#include "gui/view/tool/ViewToolDrawRect.h"

#include <QList>

class QFile; 
class FacsanaduProject;
class Dataset; 
class ViewSettings;

QList<int> GatingResult::getAcceptedFromGate(Gate*)
{
 return {};
}

/*
ViewToolDrawEllipse::ViewToolDrawEllipse(ViewWidget*){}
ViewToolDrawSelect::ViewToolDrawSelect(ViewWidget*){}
ViewToolDrawRange::ViewToolDrawRange(ViewWidget*){}
ViewToolDrawPoly::ViewToolDrawPoly(ViewWidget*){}
ViewToolDrawRect::ViewToolDrawRect(ViewWidget*){}
*/


QList<Gate*> Gate::children() const
{
 return {};
}

void Gate::attachChild(Gate* g)
{
 Q_UNUSED(g)
}

void Gate::setUpdated() {}
void Gate::detachParent() {}

void GateMeasure::detachFromGate() {}
void Gate::attachMeasure(GateMeasure*) {}

GateMeasure::GateMeasure()
{
}

QString GateMeasure::getDesc(FacsanaduProject*)
{
 return {};
}

QList<Gate*> GateSet::getGates()
{
 return {};
}

QList<Gate*> GatingResult::getIdGates()
{
 return {};
}

int GatingResult::getGateIntIDForObs(int)
{
 return 0;
}

double GatingResult::getCalcResult(GateMeasure*)
{
 return 0;
}



/*
void Dataset::computeProfChannel(FacsanaduProject*, ProfChannel*)
{
}

QString Dataset::get_file_source_name()
{
 return {};
}
*/

QSet<QString> GateSet::getGateNames()
{
 return {};
}

QString GateSet::getFreeName()
{
 return {};
}

/*
QList<ChannelInfo*> Dataset::getChannelInfo()
{
 return {};
}
*/

QString ProfChannel::getName()
{
 return "?";
}

/*
QString Dataset::getName()
{
 return "?";
}
*/

//void ImgResource::setWindowIcon(QWidget*){}

void GraphExporter::render(QFile&, FacsanaduProject*, QList<Dataset*>,
  QList<ViewSettings*>, bool, bool, int, int){}

//void ViewsPane::updateViews(){}

//void GateStatsPane::updateStats() {}

//void ProfilePane::updateViews(){}

//void CompensationPane::updateForm(){}

// void ViewsPane::invalidateCache(){}

//?int GateCalcThread::getNumCores(){ return 1; }
//?void GateCalcThread::setNumCores(int){ }









