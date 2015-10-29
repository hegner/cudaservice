cmake_minimum_required(VERSION 2.8.7)

project(CudaService)
set( CudaService_VERSION_MAJOR 0 )
set( CudaService_VERSION_MINOR 1 )
set( CudaService_VERSION_PATCH 0 )
set( CudaService_VERSION "${CudaService_VERSION_MAJOR}.${CudaService_VERSION_MINOR}" )

set(CMAKE_BUILD_TYPE Release)

#--- enable unit testing capabilities ------------------------------------------
include(CTest)

#--- include externals ---------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")
find_package(CUDA REQUIRED)
find_package(Hemi REQUIRED)
include_directories(${HEMI_INCLUDE_DIR})

#--- set special compiler flags ------------------------------------------------
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -O3 -pthread")
list(APPEND CUDA_NVCC_FLAGS
        "--compiler-options -fno-strict-aliasing -lineinfo -Xptxas -dlcm=cg")
list(APPEND CUDA_NVCC_FLAGS 
        "-std=c++11 --default-stream per-thread -gencode arch=compute_35,code=sm_35")

#--- enable CPack --------------------------------------------------------------
include(cmake/CudaServiceCPack.cmake)

#--- target for Doxygen documentation ------------------------------------------
include(cmake/CudaServiceDoxygen.cmake)

#--- add version files ---------------------------------------------------------
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CudaServiceVersion.h
               ${CMAKE_CURRENT_BINARY_DIR}/CudaServiceVersion.h )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CudaServiceVersion.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/cudaservice )

#--- add CMake infrastructure --------------------------------------------------
include(cmake/CudaServiceCreateConfig.cmake)

#--- add license files ---------------------------------------------------------
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
              ${CMAKE_CURRENT_SOURCE_DIR}/NOTICE
        DESTINATION ${CMAKE_INSTALL_PREFIX})

#--- project specific subdirectories -------------------------------------------
add_subdirectory(cudaservice)
