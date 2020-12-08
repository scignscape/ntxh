#===============================================================================
# Medical Data Segmentation Toolkit (MDSTk)
# Copyright (c) 2010 by PGMed@FIT
#
# Authors: Miroslav Svub, svub@fit.vutbr.cz
#          Michal Spanel, spanel@fit.vutbr.cz
# Section: libSystem
# Date:    2010/01/31
#
# $Id: CMakeLists.txt 2119 2012-02-20 11:34:40Z spanel $
#
# Description:
# - Configuration file for the CMake build system.

#MDSTk_LIBRARY( Eigen )
#MDSTk_LIBRARY_SOURCE( ... )
#MDSTk_LIBRARY_BUILD()
#MDSTk_LIBRARY_INSTALL()

# All header files of the Eigen library
MDSTk_LIBRARY_INCLUDE_DIR( ${MDSTk_SOURCE_DIR}/include/Eigen )

MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Array )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Core )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Dense )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Eigen )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Eigen2Support )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Eigenvalues )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Geometry )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Householder )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Cholesky )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/CholmodSupport )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/IterativeLinearSolvers )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Jacobi )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/LeastSquares )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/LU )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/OrderingMethods )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/PARDISOSupport )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/QR )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/QtAlignedMalloc )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/Sparse )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/SparseCore )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/SparseCholesky )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/StdDeque )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/StdList )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/StdVector )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/SuperLUSupport )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/SVD )
MDSTk_LIBRARY_HEADER( ${MDSTk_SOURCE_DIR}/include/Eigen/UmfPackSupport )

# Install header files only
foreach( HEADER ${MDSTk_LIBRARY_HEADERS} )
  file( RELATIVE_PATH FILE ${MDSTk_SOURCE_DIR}/include ${HEADER} )
  get_filename_component( DIR ${FILE} PATH )
  install( FILES ${HEADER} DESTINATION include/${DIR} )
endforeach( HEADER )

