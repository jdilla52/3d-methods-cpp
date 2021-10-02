#include(FetchContent)
#
#FetchContent_Declare(json
#        GIT_REPOSITORY https://github.com/nlohmann/json.git
#        GIT_TAG v3.7.3)

#FetchContent_GetProperties(json)
#if(NOT json_POPULATED)
#    FetchContent_Populate(json)
#    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
#endif()


include(FetchContent)
FetchContent_Declare(
        Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG master
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)
set(EIGEN_BUILD_DOC OFF)
# note: To disable eigen tests,
# you should put this code in a add_subdirectory to avoid to change
# BUILD_TESTING for your own project too since variables are directory
# scoped
set(BUILD_TESTING OFF)
set(EIGEN_BUILD_PKGCONFIG OFF)
set( OFF)
FetchContent_MakeAvailable(Eigen)
if(NOT Eigen_POPULATED)
#    FetchContent_Populate(Eigen)
#    add_subdirectory(${Eigen_SOURCE_DIR} ${Eigen_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
#target_link_libraries(cloud PRIVATE nlohmann_json::nlohmann_json)