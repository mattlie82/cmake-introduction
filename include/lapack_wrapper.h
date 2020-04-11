#ifndef __cmake_introduction_lapack_wrapper_h__
#define __cmake_introduction_lapack_wrapper_h__

#include "config.h"

extern "C"
{
  /// @brief Function provided by LAPACK to solve a (dense) linear system
  /// @see http://www.netlib.org/lapack/explore-html/d8/d72/dgesv_8f.html
  void dgesv_(int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO );
}

namespace core
{

// if the variable CMAKE_INTRODUCTION_WITH_LAPACK is defined in the generated header file config.h
// the following code will be used in the compilation.
#ifdef CMAKE_INTRODUCTION_WITH_LAPACK

/// @brief Wrapper function around around dgesv_
void dgesv_wrap(int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO )
{ 
  dgesv_(N, NRHS, A, LDA, IPIV, B, LDB, INFO);
}

// if the variable is not set, the subsequent lines of code will be used.
#else

/// @brief Wrapper function around around dgesv_
void dgesv_wrap(int* N, int* NRHS, double* A, int* LDA, int* IPIV, double* B, int* LDB, int* INFO )
{ 
  std::cerr << "Project 'cmake_introduction was not configured with LAPACK support.'" << std::endl;
}

#endif
}
#endif