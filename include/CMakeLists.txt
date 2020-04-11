# getting information from the repository and write into a file which can be 
# included during compilation.
set(CMAKE_INTRODUCTION_HG_REVISION   "unknown")
set(CMAKE_INTRODUCTION_HG_BRANCH     "unknown")
set(CMAKE_INTRODUCTION_LOCAL_CHANGES "true") # assume true if unknown

# find the mercurial command line tool 
find_package(Hg)

if(HG_FOUND)
  # find the revision number and find out if there are local changes
  execute_process(COMMAND ${HG_EXECUTABLE} id -i
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                  OUTPUT_VARIABLE _info
                  RESULT_VARIABLE _result
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  
  if(${_result} EQUAL 0)
    # there is a '+' at the end of the revision number in case there are local
    # changes
    # remove the + if it exists to get the revision number
    string(REPLACE "+" "" CMAKE_INTRODUCTION_HG_REVISION ${_info})
    # if there are local changes, set the variable correspondingly
    if(${_info} MATCHES "\\+$")
      set(CMAKE_INTRODUCTION_LOCAL_CHANGES "true")
    else()
      set(CMAKE_INTRODUCTION_LOCAL_CHANGES "false")
    endif()
  endif()
  
  # find the branch name
  execute_process(COMMAND ${HG_EXECUTABLE} branch
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                  OUTPUT_VARIABLE _info
                  RESULT_VARIABLE _result
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(${_result} EQUAL 0)
    set(CMAKE_INTRODUCTION_HG_BRANCH ${_info})
  endif()
endif()

# Based on the configuration found by CMake we automatically create a header file
# from the template config.h.in, which resides in the current directory.
# The created file will reside in the respective build directory. Every file
# that is created in such a way should be seperated from the source tree.

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
                 ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# We create a new variable that is a list of all headers.
 
  set(HEADER_FILES core.h lapack_wrapper.h matrix.h vector.h)

# Append the automatically created header file to the list.

  list(APPEND HEADER_FILES ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# After compilation of the project we can use the command make install
# to copy the header files to the system. If a relative path is provided
# it is assumed to be relative to the content of the variable CMAKE_INSTALL_PREFIX
# which an UNIX systems is usually set to '/usr/local'.
  
  install(FILES ${HEADER_FILES} DESTINATION include/cmake_introduction)