cmake_minimum_required(VERSION 3.2) 

#project(projectName
# [VERSION major[.minor[.patch[.tweak]]]] [LANGUAGES languageName ...]
#)
project(leet_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # it fixes targetconditionals.h file not found on mac 10.15...
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#################
# Catch Library #
#################

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE ${CMAKE_SOURCE_DIR}/3rdparty/Catch2/single_include)

macro(catch_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE Catch2)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

include(CTest)

# add_subdirectory(env_test)
# add_subdirectory(eopi)
add_subdirectory(leet)