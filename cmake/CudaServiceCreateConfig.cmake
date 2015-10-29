include(CMakePackageConfigHelpers)
configure_file(cmake/CudaServiceConfig.cmake.in "${PROJECT_BINARY_DIR}/CudaServiceConfig.cmake" @ONLY)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/CudaServiceConfigVersion.cmake
                                 VERSION ${CudaService_VERSION}
                                 COMPATIBILITY SameMajorVersion )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CudaServiceConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CudaServiceConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake )
