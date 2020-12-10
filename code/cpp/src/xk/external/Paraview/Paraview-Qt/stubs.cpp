
#include "vtkDataAssembly.h"

#include "vtkDataAssemblyVisitor.h"

#include "vtkCSVExporter.h"

#include "vtkSMSettingsProxy.h"


void vtkSMSettingsProxy::AddLink(char const*, vtkSMProxy*, char const*, bool)
{

}

#include "vtkSMDataTypeDomain.h"

const std::vector<std::string>& vtkSMDataTypeDomain::GetDataTypeChildren(unsigned int idx)
{
  return {};//? this->DTInternals->DataTypes[idx].childAllowedTypes;
}

#include "pqPythonManager.h"
void pqPythonManager::addMacro(const QString& fileName)
{

}

#include "pqPythonEventSourceImage.h"
pqPythonEventSourceImage::~pqPythonEventSourceImage()
{

}

#include "pqOpenVRHidingDecorator.h"
pqOpenVRHidingDecorator::~pqOpenVRHidingDecorator()
{

}

#include "pqSignalAdaptorSILModel.h"
pqSignalAdaptorSILModel::~pqSignalAdaptorSILModel()
{

}


#include "vtkSMTrace.h"

vtkSMTrace::TraceItemArgs&
vtkSMTrace::TraceItemArgs::arg(char const*, std::vector<int, std::allocator<int> > const&)
{

}

#include "vtkScalarsToColorsItem.h"
void vtkScalarsToColorsItem::SetHistogramTable(vtkTable*)
{

}

#include "vtkSMTrace.h"
std::string vtkSMTrace::StopTrace()
{

}

#include "vtkSMExtractsController.h"
vtkSMExtractsController* vtkSMExtractsController::New()
{
 return nullptr;
}

#include "vtkControlPointsItem.h"
vtkPlot*  vtkControlPointsItem::GetAddPointItem()
{
 return nullptr;
}


//vtkSMTooltipSelectionPipeline::GetTooltipInfo(std::string s)
//{

//}

#include "vtkSMTooltipSelectionPipeline.h"
bool vtkSMTooltipSelectionPipeline::GetTooltipInfo(
  int association, double pos[2], std::string& tooltipText)
{
 return false;
}

#include "vtkSMTransferFunctionPresets.h"
void vtkSMTransferFunctionPresets::ReloadPresets()
{

}

#include "vtkSMCoreUtilities.h"
std::string vtkSMCoreUtilities::SanitizeName(char const*)
{

}


#include "vtkSMRenderViewProxy.h"
bool vtkSMRenderViewProxy::SelectSurfacePoints(int const*, vtkCollection*, vtkCollection*, bool, int, bool, char const*)
{
 return false;
}

#include "vtkSMExtractsController.h"
vtkSMProxy* vtkSMExtractsController::CreateExtractor(vtkSMProxy*, char const*, char const*) const
{
 return nullptr;
}

bool vtkSMRenderViewProxy::SelectPolygonCells(vtkIntArray*, vtkCollection*, vtkCollection*, bool, int, bool)
{
 return false;
}

#include "vtkSMSettingsProxy.h"
const char* vtkSMSettingsProxy::GetSourcePropertyName(vtkSMProxy* target, const char* targetPropertyName)
{
 return nullptr;
}


#include "vtkSMExtractsController.h"
bool vtkSMExtractsController::CanExtract(vtkSMProxy*, std::vector<vtkSMProxy*, std::allocator<vtkSMProxy*> > const&) const
{
 return false;
}

#include "vtkSMRenderViewProxy.h"
bool vtkSMRenderViewProxy::SelectPolygonPoints(vtkIntArray*, vtkCollection*, vtkCollection*, bool, int, bool)
{
 return false;
}

bool vtkSMRenderViewProxy::SelectSurfaceCells(int const*, vtkCollection*, vtkCollection*, bool, int, bool, char const*)
{
 return false;
}

#include "vtkRangeHandlesItem.h"
void vtkRangeHandlesItem::SetColorTransferFunction(vtkColorTransferFunction*)
{

}

vtkRangeHandlesItem* vtkRangeHandlesItem::New()
{
 return nullptr;
}


QList<QVariant> pqSignalAdaptorSILModel::values() const
{
 return {};
}

vtkDataAssemblyVisitor::vtkDataAssemblyVisitor()
{

}


std::vector<int> vtkDataAssembly::SelectNodes(const std::vector<std::string>& path_queries,
  int traversal_order) const
{
 return {};
}


int vtkDataAssembly::GetNumberOfChildren(int) const
{
 return 0;
}

int vtkDataAssembly::GetChild(int, int) const
{
 return 0;
}

const char* vtkDataAssembly::GetNodeName(int) const
{
 return nullptr;
}


int vtkDataAssembly::GetParent(int) const
{
 return 0;
}

void vtkDataAssembly::Visit(int, vtkDataAssemblyVisitor*, int) const
{
}

vtkDataAssemblyVisitor::~vtkDataAssemblyVisitor()
{

}

void vtkDataAssemblyVisitor::PrintSelf(std::ostream&, vtkIndent)
{

}


void pqPythonEventSourceImage::run()
{

}

//void pqPythonEventSource::start()
//{

//}

void pqPythonEventSourceImage::doComparison()
{

}

void qInitResources_pqCore()
{

}

void qInitResources_pqComponents()
{

}

void qInitResources_QtWidgets()
{

}

//void pqPythonEventSource::doComparison()
//{

//}

#include "QVTKOpenGLStereoWidget.h"
QVTKOpenGLStereoWidget::QVTKOpenGLStereoWidget(QWidget*, QFlags<Qt::WindowType>)
{

}


QVTKOpenGLStereoWidget::~QVTKOpenGLStereoWidget()
{

}

void QVTKOpenGLStereoWidget::paintEvent(QPaintEvent*)
{

}

void QVTKOpenGLStereoWidget::resizeEvent(QResizeEvent*)
{

}

//pqPythonEventSourceImage::
//{

//}

//pqPythonEventSource::~pqPythonEventSource()
//{

//}

void pqSignalAdaptorSILModel::setValues(QList<QVariant> const&)
{

}

int vtkDataAssembly::GetChildIndex(int, int) const
{
 return 0;
}

std::string vtkDataAssembly::GetNodePath(int) const
{
 return {};
}


#include "vtkStringList.h"
int vtkStringList::GetNumberOfStrings()
{
 return 0;
}

#include "vtkSMPVRepresentationProxy.h"
int vtkSMPVRepresentationProxy::IsScalarBarStickyVisible(vtkSMProxy*)
{
 return false;
}

#include "vtkSMExtractsController.h"
bool vtkSMExtractsController::IsExtractorEnabled(vtkSMProxy*)
{
 return false;
}

#include "vtkSMTransferFunctionPresets.h"
std::string vtkSMTransferFunctionPresets::GetPresetName(unsigned int)
{
 return {};
}

#include "vtkSMTransferFunctionPresets.h"
std::string vtkSMTransferFunctionPresets::AddUniquePreset(
  const Json::Value& preset, const char* prefix /*=nullptr*/)
{

}


#include "vtkSMSettingsProxy.h"
void vtkSMSettingsProxy::RemoveLink(char const*, vtkSMProxy*, char const*)
{

}


#include "vtkSMExtractsController.h"
vtkSMProxy* vtkSMExtractsController::GetInputForExtractor(vtkSMProxy*) const
{

}


void vtkSMExtractsController::SetExtractorEnabled(vtkSMProxy*, bool)
{

}



#include "vtkSMTrace.h"
std::string vtkSMTrace::GetCurrentTrace()
{

}

vtkSMTrace::TraceItemArgs& vtkSMTrace::TraceItemArgs::arg(char const*, std::vector<double, std::allocator<double> > const&)
{
 static vtkSMTrace::TraceItemArgs the_args;
 return the_args;
}


#include "vtkSMSaveAnimationExtractsProxy.h"
bool vtkSMSaveAnimationExtractsProxy::SaveExtracts()
{
 return false;
}


#include "vtkSMDataTypeDomain.h"
const char* vtkSMDataTypeDomain::GetDataTypeName(unsigned int)
{
 return nullptr;
}

#include "vtkSMDataAssemblyDomain.h"
vtkDataAssembly* vtkSMDataAssemblyDomain::GetDataAssembly()
{
 return nullptr;
}


#include "vtkPVLogInformation.h"
vtkPVLogInformation* vtkPVLogInformation::New()
{
 return nullptr;
}


#include "vtkObjectBase.h"
vtkIdType vtkObjectBase::GetNumberOfGenerationsFromBaseType(char const*)
{
 return 0;
}



bool pqOpenVRHidingDecorator::canShowWidget(bool) const
{
 return false;
}


vtkSMTransferFunctionPresets* vtkSMTransferFunctionPresets::GetInstance()
{
 return nullptr;
}



#include "vtkSMTooltipSelectionPipeline.h"
bool vtkSMTooltipSelectionPipeline::GetTooltipInfo(int association, std::string& tooltipText)
{
 return false;
}

#include "vtkSMDataTypeDomain.h"
const char* vtkSMDataTypeDomain::GetDataTypeChildMatchTypeAsString(unsigned int)
{
 return nullptr;
}


bool vtkSMDataTypeDomain::DataTypeHasChildren(unsigned int)
{
 return false;
}


#include "vtkSMTransferFunctionPresets.h"
bool vtkSMTransferFunctionPresets::SetPreset(char const*, vtkJson::Value const&)
{

}


#include "vtkVtkJSSceneGraphSerializer.h"
vtkJson::Value& vtkJson::Value::operator=(vtkJson::Value const&)
{
 static vtkJson::Value the_value {};
 return the_value;
}



//vtkDataAssemblyVisitor::vtkDataAssemblyVisitor()
//{

//}

//vtkCSVExporter::GetOutputString
std::string vtkCSVExporter::GetOutputString()
{
  return this->OutputString;
}

std::vector<int> vtkDataAssembly::GetChildNodes(int, bool, int) const
{

}

void qInitResources_pqApplicationComponents()
{

}
