#include "itkQuadEdgeMesh.h"
#include "itkVTKPolyDataReader.h"
#include "itkQuadEdgeMeshBoundaryEdgesMeshFunction.h"

int
main(int argc, char * argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <InputFileName>" << std::endl;
    return EXIT_FAILURE;
  }

  constexpr unsigned int Dimension = 3;
  using CoordType = double;

  using MeshType = itk::QuadEdgeMesh<CoordType, Dimension>;
  using VTKReaderType = itk::VTKPolyDataReader<MeshType>;

  VTKReaderType::Pointer reader = VTKReaderType::New();
  reader->SetFileName(argv[1]);

  try
  {
    reader->Update();
  }
  catch (itk::ExceptionObject & e)
  {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  MeshType::Pointer mesh = reader->GetOutput();

  using BoundaryExtractorType = itk::QuadEdgeMeshBoundaryEdgesMeshFunction<MeshType>;

  BoundaryExtractorType::Pointer extractor = BoundaryExtractorType::New();

  using MeshPointIdentifier = MeshType::PointIdentifier;

  using MeshQEType = MeshType::QEType;
  using MeshIteratorGeom = MeshQEType::IteratorGeom;

  using EdgeListType = MeshType::EdgeListType;
  using EdgeListPointer = MeshType::EdgeListPointerType;
  using EdgeListIterator = EdgeListType::iterator;

  EdgeListPointer list = extractor->Evaluate(*mesh);

  if (list->empty())
  {
    std::cerr << "There is no border on this mesh" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "There are " << list->size() << " borders on this mesh" << std::endl;

  auto                   it = list->begin();
  const EdgeListIterator end = list->end();

  size_t i = 0;
  while (it != end)
  {
    std::cout << i << ": ";

    MeshIteratorGeom       eIt = (*it)->BeginGeomLnext();
    const MeshIteratorGeom eEnd = (*it)->EndGeomLnext();

    MeshPointIdentifier id = MeshType::m_NoPoint;

    while (eIt != eEnd)
    {
      MeshQEType * qe = eIt.Value();

      if (qe->GetOrigin() != id)
      {
        std::cout << qe->GetOrigin();
      }

      id = qe->GetDestination();

      std::cout << " -> " << id;
      ++eIt;
    }

    std::cout << std::endl;

    ++it;
  }

  return EXIT_SUCCESS;
}
