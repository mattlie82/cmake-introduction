# building the documentation using doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
                 ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc
                    ${DOXYGEN_EXECUTABLE} 
                    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Generating documentation with Doxygen" VERBATIM)
else()
  add_custom_target(doc 
                    COMMENT "It seems cmake could not find a doxygen "
                            "executable. Therefore no documentation is created!"
                    VERBATIM)
endif(DOXYGEN_FOUND)

