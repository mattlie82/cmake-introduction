# We introduce new variables containing a lists of the sources files needed for compilation

  set(LIB_SOURCES core.cxx)
  set(EXE_SOURCES main.cxx)

# Here we take care that the compiler knows where to find our header files

  include_directories(${CMAKE_SOURCE_DIR}/include)
  include_directories(${CMAKE_BINARY_DIR}/include)

# the second line is due to the automatically generated header file config.header
# which resides in the build directory.

# We create a new library whose target name (accessible in cmake) is set to core.
# The filename of the library will be libcore.a (on UNIX systems)

  add_library(core ${LIB_SOURCES})

# We have to link the LAPACK library against our created library to use LAPACKs functions, etc.

  target_link_libraries(core ${LAPACK_LIBRARIES})

# Since we want to use C++11 we have to explicitly add the flags to the call of the compiler.

  set_target_properties(core PROPERTIES COMPILE_FLAGS ${MY_CXX_FLAGS})


# Next we create an executable called run.
  
  add_executable(run ${EXE_SOURCES})

# Also here we have to use the C++11 flags.

  set_target_properties(run PROPERTIES COMPILE_FLAGS ${MY_CXX_FLAGS})

# we link it against the core library.
  
  target_link_libraries(run core)

# We install the core library into the lib subdirectory
# (after calling ake install).

  install(TARGETS core DESTINATION lib)

# the executable is installed into bin.

  install(TARGETS run DESTINATION bin)
