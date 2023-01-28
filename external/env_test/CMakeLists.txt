
project(env_test LANGUAGES CXX)

# add_executable(targetName [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL]
#   source1 [source2 ...]
# )
add_executable(hello hello.cpp)
catch_add_test(catch catch.cpp)