cmake_minimum_required(VERSION 3.0)
project(Simulator VERSION 1.0.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(sim src/main.cpp)
target_link_libraries(sim PUBLIC ${SDL2_LIBRARIES} -lSDL2_image)

FOREACH(subdir ${SUBDIRS})
  file(GLOB _H "src/${subdir}/*.hpp")
  file(GLOB _C "src/${subdir}/*.cpp")

  add_library(
    ${subdir}
    ${_H}
    ${_C}
  )

  target_include_directories(${subdir} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
  target_link_libraries(sim PRIVATE ${subdir})

ENDFOREACH()
