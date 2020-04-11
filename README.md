[![CircleCI](https://circleci.com/gh/mattlie82/cmake-introduction.svg?style=svg)](https://circleci.com/gh/mattlie82/cmake-introduction)
# Introduction
CMake is a convenient tool to manage the build process of software in a portable way. CMake can locate compilers, executables, files, and libraries, set up complicated library hierarchies, and help you to install your project. It also has integrated testing capabilities e.g. to automatically test whether new features of your project have broken older parts of the code.

CMake is used to control the software compilation process using simple platform and compiler independent configuration files. These files are always called `CMakeLists.txt` and you usually have one per subdirectory. They are input text files that contain the project parameters and
describe the flow control of the build process in simple CMake language. Speaking of which, the CMakeLists language is full-fledged programming language with variables, loops, conditional statements, function declarations etc.

CMake generates native makefiles and workspaces that can be used in the compiler environment of your choice: Visual C++, Kdevelop3, Eclipse, XCode, makefiles (Unix, NMake, Borland, Watcom, MinGW, MSYS, Cygwin), Code::Blocks, etc. (call `cmake --help` to see a list of available generators for your system).

## Additional ressources
You can find more information at these locations:
- [CMake website](https://cmake.org/cmake-tutorial/) (Excerpt from the book "Mastering CMake")
- [CMake reference documentation](https://cmake.org/documentation/)
- [Jürgen Fuhrmann's CMake introduction](https://www.wias-berlin.de/people/fuhrmann/2014-10-30-cmake.html)
- [Introduction to CMake by Derek Molloy](http://derekmolloy.ie/hello-world-introductions-to-cmake/)
- [CMake examples at vtk.org](http://www.vtk.org/Wiki/CMake/Examples)

Interesting projects that use CMake:
- [deali.II library](https://github.com/dealii/dealii)
- [DOLFIN backend of FEniCS](https://github.com/FEniCS/dolfin)
- [pdelib2](https://wias)
## Using this example
This project contains a brief introduction to CMake by means of a simple example.
We assume that you are working on the command line and use a UNIX-type system.

1. Check that CMake is installed on your system, e.g. by running 'cmake --version' on the command line. If it fails, CMake is either not installed or not in your path. You can install CMake via the package manager of your system or download it directly from the [CMake website](https://cmake.org/download/).

2. Next, clone this repository with Mercurial (`hg clone https://repos.wias-berlin.de/cmake-introduction`) or download the content directly from [here](https://repos.wias-berlin.de/cmake-introduction/archive/tip.zip). 

3. Change into the directory of the project and create a new build directory where everyhing is generated (out-of-source build), e.g. `mkdir <BUILD_DIR>`. Change in to the build directory, i.e. `cd <BUILD_DIR>`.

4. Run `cmake ..` (the two dots tell CMake to look for the top-level `CMakelists.txt` in the parent directory). CMake now checks whether you have a working C++ and C compiler and tries to locate the LAPACK library. 

5. If the last step was succesfull run `make` to start the compilation of the project.

6. Use `make doc` to build the documentation of the project. It can be found in the build directory in `<BUILD_DIR>/documentation/html/index.html`

7. Run `make install` to install the compiled library, executable, and header files to the system. You can set the variable `CMAKE_INSTALL_PREFIX` to a specific location when calling CMake in Step 4, e.g. `cmake -DCMAKE_INSTALL_PREFIX=<PATH TO DIRECTORY> ..`. Otherwise the default directory is `/usr/local/*`.

8. To uninstall everything, call `make uninstall`.



