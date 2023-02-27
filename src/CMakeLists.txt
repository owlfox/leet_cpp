

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        devel #aka main branch
)
FetchContent_MakeAvailable(Catch2)


list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
#catch_discover_tests(unit_tests)



macro(catch_add_test TESTNAME)

  # If you got a main entry point, renaming your main into run or something else could help prepare your code
  # for testing, below is one of the example.
  #add_library(${TESTNAME} STATIC ${TESTNAME}.cxx)
  #target_link_libraries(${TESTNAME} PRIVATE Catch2::Catch2WithMain)
  #add_executable(r${TESTNAME} run.cxx)
  #target_link_libraries(r977 PRIVATE 977)

  add_executable(t${TESTNAME} ${TESTNAME}.cxx)
  target_link_libraries(t${TESTNAME} PRIVATE
                      Catch2::Catch2WithMain)
  set_property(TARGET t${TESTNAME} PROPERTY CXX_STANDARD 23)
  catch_discover_tests(t${TESTNAME})
endmacro()

catch_add_test(977)
catch_add_test(111)
catch_add_test(643)
catch_add_test(1)
catch_add_test(2351)
catch_add_test(1832)

# linked lists
catch_add_test(876)
catch_add_test(83)
catch_add_test(21)

# Hash table / map
catch_add_test(383)

# stack
catch_add_test(20)

# Greedy
catch_add_test(1323)
