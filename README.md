# CudaService

## Building the project

    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=<installdir>  <path to sources>
    make -j<number of cores on your machine>
    make install

## Building the documentation

The documentation of the project is based on doxygen. Invoking

    make doc
    make install

installs the documentation into installdir/doxygen.

## Creating a package with CPack

A cpack based package can be created by invoking

    make package

## Running the tests

To run the tests of the project, first build it and then invoke

    make test

## Inclusion into other projects

If you want to build your own project against CudaService, CMake may be the best option for you. Just add its location to _CMAKE_PREFIX_PATH_ and call _find_package(CudaService)_ within your CMakeLists.txt.
