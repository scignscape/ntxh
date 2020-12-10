/*=========================================================================
  
   Program:   Visualization Toolkit
   Module:    vtkDataAssemblyVisitor.h
  
   Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
   All rights reserved.
   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
  
      This software is distributed WITHOUT ANY WARRANTY; without even
      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
      PURPOSE.  See the above copyright notice for more information.
  
 =========================================================================*/
 #ifndef vtkDataAssemblyVisitor_h
 #define vtkDataAssemblyVisitor_h
  
 #include "vtkCommonDataModelModule.h" // for export macros
 #include "vtkObject.h"
 #include <memory> // for std::unique_ptr
 #include <vector> // for std::vector
  
 class vtkDataAssembly;
  
 class VTKCOMMONDATAMODEL_EXPORT vtkDataAssemblyVisitor : public vtkObject
 {
 public:
   vtkTypeMacro(vtkDataAssemblyVisitor, vtkObject);
   void PrintSelf(ostream& os, vtkIndent indent) override;
  
 protected:
   vtkDataAssemblyVisitor();
   ~vtkDataAssemblyVisitor() override;
  
   const vtkDataAssembly* GetAssembly() const { return this->Assembly; }
  
   int GetTraversalOrder() const { return this->TraversalOrder; }
  
   virtual void Visit(int nodeid) = 0;
  
   virtual bool GetTraverseSubtree(int vtkNotUsed(nodeid)) { return true; }
  
  
   virtual void BeginSubTree(int vtkNotUsed(nodeid)) {}
   virtual void EndSubTree(int vtkNotUsed(nodeid)) {}
  
  
   const char* GetCurrentNodeName() const;
   std::vector<unsigned int> GetCurrentDataSetIndices() const;
  
 private:
   vtkDataAssemblyVisitor(const vtkDataAssemblyVisitor&) = delete;
   void operator=(const vtkDataAssemblyVisitor&) = delete;
  
 // //? have to hack this ...
//   class vtkInternals;
//   std::unique_ptr<vtkInternals> Internals;

   class vtkInternals {};
   std::unique_ptr<vtkInternals> Internals;


   const vtkDataAssembly* Assembly;
   int TraversalOrder;
   friend class vtkDataAssembly;
 };
  
 #endif

