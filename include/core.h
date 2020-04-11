#ifndef __cmake_introduction_core_h__
#define __cmake_introduction_core_h__

#include "matrix.h"
#include "vector.h"

/** @brief Namespace for core components 
 * 
 * Detailed description here.
 */
namespace core
{

/** Solve the linear system given by the (dense) matrix A and the right-hand side.
    The solution will be written to rhs and the matrix contains the LU factorization.*/
int solve_linear_system(Matrix<double>& A, Vector<double>& rhs);

}

#endif