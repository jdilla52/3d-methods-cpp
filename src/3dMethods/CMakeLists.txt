add_library(3dMethods STATIC
        pca.cpp
        )
target_link_libraries(3dMethods PRIVATE Eigen3::Eigen)

#target_link_libraries(lambdaRunner
#        Eigen
#        )
target_include_directories(3dMethods PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_BINARY_DIR}" "${PROJECT_BINARY_DIR}")
target_include_directories(3dMethods PUBLIC src/lambdaRunner)

