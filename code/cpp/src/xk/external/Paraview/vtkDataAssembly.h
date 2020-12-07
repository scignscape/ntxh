/*=========================================================================
  
   Program:   Visualization Toolkit
   Module:    vtkDataAssembly.h
  
   Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
   All rights reserved.
   See Copyright.txt or http://www.kitware.com/Copyright.htm for details.
  
      This software is distributed WITHOUT ANY WARRANTY; without even
      the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
      PURPOSE.  See the above copyright notice for more information.
  
 =========================================================================*/
 #ifndef vtkDataAssembly_h
 #define vtkDataAssembly_h
  
 #include "vtkCommonDataModelModule.h" // for export macros
 #include "vtkObject.h"
  
 #include <map>    // for std::map
 #include <memory> // for std::unique_ptr
 #include <string> // for std::string
 #include <vector> // for std::vector
  
 class vtkDataAssemblyVisitor;
  
 class VTKCOMMONDATAMODEL_EXPORT vtkDataAssembly : public vtkObject
 {
 public:
   static vtkDataAssembly* New();
   vtkTypeMacro(vtkDataAssembly, vtkObject);
   void PrintSelf(ostream& os, vtkIndent indent) override;
  
   void Initialize();
  
  
   bool InitializeFromXML(const char* xmlcontents);
  
  
   std::string SerializeToXML(vtkIndent indent) const;
  
   static int GetRootNode() { return 0; }
  
  
   void SetRootNodeName(const char* name) { this->SetNodeName(this->GetRootNode(), name); }
   const char* GetRootNodeName() const { return this->GetNodeName(this->GetRootNode()); }
  
   int AddNode(const char* name, int parent = 0);
  
   std::vector<int> AddNodes(const std::vector<std::string>& names, int parent = 0);
  
   bool RemoveNode(int id);
  
  
   void SetNodeName(int id, const char* name);
   const char* GetNodeName(int id) const;
  
   std::string GetNodePath(int id) const;
  
   bool AddDataSetIndex(int id, unsigned int dataset_index);
  
   bool AddDataSetIndices(int id, const std::vector<unsigned int>& dataset_indices);
  
   bool RemoveDataSetIndex(int id, unsigned int dataset_index);
  
   bool RemoveAllDataSetIndices(int id, bool traverse_subtree = true);
  
   enum TraversalOrder
   {
     DepthFirst = 0,
     BreadthFirst
   };
  
   int FindFirstNodeWithName(
     const char* name, int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   std::vector<int> FindNodesWithName(
     const char* name, int sort_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   std::vector<int> GetChildNodes(int parent, bool traverse_subtree = true,
     int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   int GetNumberOfChildren(int parent) const;
  
   int GetChild(int parent, int index) const;
  
   int GetChildIndex(int parent, int child) const;
  
   int GetParent(int id) const;
  
  
   void Visit(vtkDataAssemblyVisitor* visitor,
     int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const
   {
     this->Visit(0, visitor, traversal_order);
   }
   void Visit(int id, vtkDataAssemblyVisitor* visitor,
     int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   std::vector<unsigned int> GetDataSetIndices(int id, bool traverse_subtree = true,
     int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   std::vector<int> SelectNodes(const std::vector<std::string>& path_queries,
     int traversal_order = vtkDataAssembly::TraversalOrder::DepthFirst) const;
  
   bool RemapDataSetIndices(
     const std::map<unsigned int, unsigned int>& mapping, bool remove_unmapped);
  
   void SubsetCopy(vtkDataAssembly* other, const std::vector<int>& selected_branches);
  
   void DeepCopy(vtkDataAssembly* other);
  
 protected:
   vtkDataAssembly();
   ~vtkDataAssembly() override;
  
 private:
   vtkDataAssembly(const vtkDataAssembly&) = delete;
   void operator=(const vtkDataAssembly&) = delete;
  
   class vtkInternals;
   std::unique_ptr<vtkInternals> Internals;
 };
  
 #endif
