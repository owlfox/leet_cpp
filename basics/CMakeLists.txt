
project(basics LANGUAGES CXX)

# add_executable(targetName [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL]
#   source1 [source2 ...]
# )
catch_add_test(types types.cpp)
catch_add_test(pack pack.cpp)