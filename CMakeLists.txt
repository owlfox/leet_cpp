cmake_minimum_required(VERSION 3.21.0)
#Testing purpose
find_program(local_gpp12 "g++-12")
IF(local_gpp12)
    message(STATUS "g++-12:${local_gpp12}")
    set(CMAKE_CXX_COMPILER "${local_gpp12}" CACHE STRING "C++ compiler" FORCE)
ELSE()
    message(WARNING, "g++-12 not found, fallback to hardcoded linuxbrew path..")
    set(CMAKE_CXX_COMPILER "/home/linuxbrew/.linuxbrew/bin/g++-12" CACHE STRING "C++ compiler" FORCE)
ENDIF()
project(LeetWithCatch2 CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "12")
    message(FATAL_ERROR "Insufficient gcc version from ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}")
  endif()
endif()

enable_testing()
add_subdirectory(src)

#Although it is generally recommended to separate test and your source code.
#It is kind of tedious to jump between files, an overkill for the purpose of practicing leet code.
#So I decide to keep catch2 tests and c++ solutions in the same files.
#add_subdirectory(test)
