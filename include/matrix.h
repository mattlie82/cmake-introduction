#ifndef __cmake_introduction_matrix_h__
#define __cmake_introduction_matrix_h__

#include <memory>
#include <cassert>
#include <iomanip>
#include <cstddef>
#include <cmath>

namespace core
{

/**
 @brief A dense quadratic matrix of arbitrary size.
 
 The template is typically a double.
*/
template<typename Scalar>
class Matrix
{
public:
  /// @brief constructor of an @a _size by @a _size matrix
  /// @param _size number of rows/columns of square matrix.
  Matrix(int _size)
  : size(_size)
  {
    values = new Scalar [size*size]();
  }
  
  /// @brief destructor, delete memory created during construction
  virtual ~Matrix()
  {
    if (values != nullptr)
      delete[] values;
  }

  /// @brief access and change individual elements 
  /// @details The parameters @a i and @a j must be within \f$[1,\_size]\f$,
  /// otherwise the program terminates with an error.
  Scalar& operator()(int i, int j)
  { 
    assert((1 <= i) && (i <= size));
    assert((1 <= j) && (j <= size));
    return *(values + size*(i - 1) + j - 1); }

  /// @brief access individual elements 
  /// @warning no checks are done for @a i and @a j.
  Scalar operator()(int i, int j) const
  { return *(values + size*(i - 1) + j - 1); }

  /// @brief get the number of rows/columns
  int get_size () const
  { return size; }

  /// @brief get the array of elements of the matrix
  /// @note be careful with this. Do not delete it!
  /// @note use saver const version, if possible
  Scalar* get_values()
  { return values; }

  /// @brief get the array of elements of the matrix
  const Scalar* get_values() const
  { return values; }

  /** @brief print the matrix in some nice form
   * 
   * @param[in,out] os stream to which the matrix is written
   * 
   * @todo more documentation, please!
   */
  template <typename OUTPUT_STREAM>
  void print_formatted (OUTPUT_STREAM       &os,
                        const unsigned int  precision   = 3,
                        const bool          scientific  = true,
                        const unsigned int  width_      = 0,
                        const char         *zero_string = "*",
                        const double        denominator = 1.,
                        const double        threshold   = 0.) const
  {
    unsigned int width = width_;
    os << "(" << size << "x" << size <<") Matrix" << std::endl;
    // set output format, but store old
    // state
    std::ios::fmtflags old_flags = os.flags();
    unsigned int old_precision   = os.precision (precision);

    if (scientific) {
        os.setf (std::ios::scientific, std::ios::floatfield);
        if (!width)
          width = precision+7;
    }
    else {
        os.setf (std::ios::fixed, std::ios::floatfield);
        if (!width)
          width = precision+2;
    }

    for (int i1 = 1 ; i1 <= size; i1++) {
      for (int i2 = 1; i2 <= size; i2++) {
        if (std::fabs((*this)(i1,i2)) > threshold)
          os << std::setw(width)
             << (*this)(i1,i2) * Scalar(denominator) << ' ';
        else
          os << std::setw(width) << zero_string << ' ';
      }
      if (i1 != size) os << std::endl;
    }
    
    os << std::endl;
    // reset output format
    os.flags (old_flags);
    os.precision(old_precision);
  }

private:
  int     size; ///< the number of rows/columns
  Scalar* values; ///< the entries of the matrix (row-wise)
};

}

#endif