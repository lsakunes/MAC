cmake_minimum_required(VERSION 3.23)
project(MAC VERSION 1.0 LANGUAGES CXX CUDA)

# not necessary rn I think
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CUDAToolkit REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
find_package(OpenCV REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE ALL_SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.cu")
# file(GLOB_RECURSE ALL_HEADERS "${SRC_DIR}/*.hpp" "${SRC_DIR}/*.cuh")
set(MAIN_FILE "${SRC_DIR}/main.cpp")
set(LIB_SOURCES ${ALL_SOURCES})
list(REMOVE_ITEM LIB_SOURCES ${MAIN_FILE})
add_executable(${PROJECT_NAME} ${MAIN_FILE})

set(CMAKE_CUDA_ARCHITECTURES native)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${MAIN_FILE}
    ${LIB_SOURCES}
)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE 
    Eigen3::Eigen
    ${OpenCV_LIBS}
    CUDA::cudart
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})

