cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_STANDARD 17)
project(3dMethods LANGUAGES CXX)

set(LAMBDA_CONFIG_HEADER ${CMAKE_BINARY_DIR}/runner_config.h)
message("Generating ${LAMBDA_CONFIG_HEADER}...")
configure_file(src/3dMethods/runner_config.h.in ${LAMBDA_CONFIG_HEADER} )

# third party
add_subdirectory(thirdparty)

# library
add_subdirectory(src/3dMethods)
target_include_directories(3dMethods PUBLIC src)

set(BUILD_TESTING OFF)
set(EIGEN_BUILD_PKGCONFIG OFF)
set( OFF)
add_subdirectory(test)

# tests
if($ENV{TEST_3DMETHODS})
    message("Generating tests")
    add_subdirectory(test)
elseif(${TEST_3DMETHODS})
    message("Generating tests")
    add_subdirectory(test)
else()
    message("Building without tests")
endif()