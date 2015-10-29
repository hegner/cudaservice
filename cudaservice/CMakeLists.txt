## add include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CUDA_FOUND)

  CUDA_ADD_EXECUTABLE(cudaMatOpsBasic src/cudaMatOps_basic.cu)
  CUDA_ADD_EXECUTABLE(cudaMatOpsConcurrent src/cudaMatOps_concurrent.cu)

  #---------- HEMI -----------
  CUDA_ADD_EXECUTABLE(cudaMatOpsHEMI src/cudaMatOps_hemi.cu)

  #---------- UMA -----------
  CUDA_ADD_EXECUTABLE(cudaMatOpsUMA src/cudaMatOps_uma.cu)

  #---------- PortableLayer + UMA -----------
  CUDA_ADD_EXECUTABLE(cudaMatOpsPUMA src/cudaMatOps_PortableUma.cu)

  #---------- Streams Concurrency Exp -----------
  CUDA_ADD_EXECUTABLE(streamConcurrency src/stream_ops_concurrent.cu)

  #---------- Runtime portability -----------
  CUDA_ADD_EXECUTABLE(runtimePortable src/cuda_runtimePortable+uma.cu)
  CUDA_ADD_EXECUTABLE(runtimePortableDynamicPol src/cuda_runtimePortable_dynamicPol.cu)

endif(CUDA_FOUND)

#--- install headers -----------------------------------------------------------
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cudaservice DESTINATION include)

#--- add tests -----------------------------------------------------------------
add_subdirectory(test)
