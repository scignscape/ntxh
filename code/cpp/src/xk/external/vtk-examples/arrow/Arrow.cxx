#include <vtkActor.h>
#include <vtkArrowSource.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>


#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkInteractionStyle);


int main(int argc, char * argv [])
{

 vtkSmartPointer<vtkNamedColors> colors =
   vtkSmartPointer<vtkNamedColors>::New();

 // Create an arrow.
 vtkSmartPointer<vtkArrowSource> arrowSource =
   vtkSmartPointer<vtkArrowSource>::New();
 //arrowSource->SetShaftRadius(1.0);
 //arrowSource->SetTipLength(1.0);
 arrowSource->Update();

 // Create a mapper and actor
 vtkSmartPointer<vtkPolyDataMapper> mapper =
   vtkSmartPointer<vtkPolyDataMapper>::New();
 mapper->SetInputConnection(arrowSource->GetOutputPort());
 vtkSmartPointer<vtkActor> actor =
   vtkSmartPointer<vtkActor>::New();
 actor->SetMapper(mapper);
 
 // Visualize
 vtkSmartPointer<vtkRenderer> renderer =
   vtkSmartPointer<vtkRenderer>::New();
 vtkSmartPointer<vtkRenderWindow> renderWindow =
   vtkSmartPointer<vtkRenderWindow>::New();
 renderWindow->SetWindowName("Arrow");
 renderWindow->AddRenderer(renderer);
 vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
   vtkSmartPointer<vtkRenderWindowInteractor>::New();
 renderWindowInteractor->SetRenderWindow(renderWindow);
 
 renderer->AddActor(actor);
 renderer->SetBackground(colors->GetColor3d("MidnightBlue").GetData());
 
 renderWindow->Render();
 renderWindowInteractor->Start();
 
  return EXIT_SUCCESS;
}
