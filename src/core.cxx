#include "config.h"
#include <iostream>
#include "core.h"
#include "lapack_wrapper.h"

namespace core
{
/* implementation of solve_linear_system declared in core.h */
int solve_linear_system(Matrix<double>& matrix, Vector<double>& rhs)
{
  std::cout << "Solving linear system" << std::endl;
  int info;

  int* ipiv = new int[matrix.get_size()]; 

  int size = matrix.get_size();
  int one  = 1;

  dgesv_wrap(&size, 
             &one, 
             matrix.get_values(), 
             &size, 
             ipiv, 
             rhs.get_values(), 
             &size, 
             &info);
  
  delete[] ipiv;
  return info;
}

}