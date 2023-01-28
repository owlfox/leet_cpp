

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
  add_library(${TESTNAME} STATIC ${TESTNAME}.cxx)
  target_link_libraries(${TESTNAME} PRIVATE Catch2::Catch2WithMain)

  # If you got a main entry point, renaming your main into run or something else could help prepare your code
  # for testing, below is one of the example.
  #add_executable(r${TESTNAME} run.cxx)
  #target_link_libraries(r977 PRIVATE 977)

  add_executable(t${TESTNAME} ${TESTNAME}.cxx)
  target_link_libraries(t${TESTNAME} PRIVATE
                      ${TESTNAME}
                      Catch2::Catch2WithMain)
  catch_discover_tests(t${TESTNAME})
endmacro()

catch_add_test(977)