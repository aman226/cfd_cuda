cmake_minimum_required(VERSION 3.10)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
message(FATAL_ERROR “In-source build detected!”)
endif()

project(aero_cfd VERSION 0.1 LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LIB_DIRECTORY lib)


file(GLOB libs RELATIVE ${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY} ${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY}/*)
foreach(library ${libs})
  if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY}/${library})
    add_subdirectory(${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY}/${library})
    list(APPEND EXTRA_LIBS ${library})
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY}/${library}/include")    
  endif()
endforeach()

find_package(matplotlib_cpp)

# add the executable
add_executable(cfd_main src/cfd_main.cpp)
target_include_directories(cfd_main PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include ${EXTRA_INCLUDES})
configure_file(include/cfd_main_version.h.in cfd_main_version.h)
target_link_libraries(cfd_main PUBLIC ${EXTRA_LIBS} Python3::Python Python3::Module Python3::NumPy)

