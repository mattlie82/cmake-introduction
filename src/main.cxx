#include "config.h"
#include <iostream>
#include "core.h"




/**
  Example program solving a simple linear system.
*/
int main (int argc, char* argv[])
{
#ifndef NDEBUG
  std::cout << "Hello from 'cmake_introduction' version " 
            << CMAKE_INTRODUCTION_VERSION << std::endl;
  std::cout << "build type: " << configure_time_constants::build_type << "\n";
  std::cout << "hg revision: " << configure_time_constants::hg_revision << "\n";
  std::cout << "hg branch: " << configure_time_constants::hg_branch << "\n";
  if(configure_time_constants::hg_local_changes){
    std::cout << "There are changes in your local copy of the repository!\n";
  }
#endif
  // init matrix and right-hand side  
  core::Matrix<double> matrix(10);
  core::Vector<double> rhs(10);

  // set matrix and right-hand side
  for (int i = 1; i <= 10; i++){
    rhs(i)      = 1.0;
    matrix(i,i) = i;
  }
#ifndef NDEBUG
  // print matrix
  matrix.print_formatted(std::cout);
  
  std::cout << std::endl;
  // print rhs
  rhs.print_formatted(std::cout);
  std::cout << std::endl;
#endif

  // solve linear system with LAPACK
  core::solve_linear_system(matrix, rhs);

  // print solution to stdout
  std::cout << "Solution:" <<std::endl;
  rhs.print_formatted(std::cout);

  return 0;
}
