cmake_minimum_required(VERSION 3.2) 

#project(projectName
# [VERSION major[.minor[.patch[.tweak]]]] [LANGUAGES languageName ...]
#)
project(leet_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # it fixes targetconditionals.h file not found on mac 10.15...
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#################
# Catch Library #
#################

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

macro(catch_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
	target_link_libraries(${TESTNAME} PRIVATE ${CONAN_LIBS})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

include(CTest)

#catch_add_test(catch-main catch.cpp)
#catch_add_test(catch-test factorial.cpp)
# add_subdirectory(env_test)
#add_subdirectory(eopi)
#add_subdirectory(system_programming)
#add_subdirectory(leet)
add_subdirectory(basics)
#add_subdirectory(ccc)
add_subdirectory(dahua_ds)
add_subdirectory(poco)
