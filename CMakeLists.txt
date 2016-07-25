cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(RTMAdapterTest)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   SET(CMAKE_CXX_COMPILER "g++")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

find_package(BasicDataType)


set(_srcs test.c)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${BasicDataType_INCLUDE_DIRS})

add_definitions(${BasicDataType_DEFINITIONS})

link_directories(${BasicDataType_LIBRARY_DIRS})

add_executable(${PROJECT_NAME}Test ${_srcs}
  ${_hdrs})
set_target_properties(${PROJECT_NAME}Test PROPERTIES PREFIX "")
target_link_libraries(${PROJECT_NAME}Test ${BasicDataType_LIBRARIES} )
