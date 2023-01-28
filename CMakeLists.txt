cmake_minimum_required(VERSION 3.21.0)
project(LeetWithCatch2 CXX)
enable_testing()
add_subdirectory(src)

#Although it is generally recommended to separate test and your source code.
#It is kind of tedious to jump between files, an overkill for the purpose of practicing leet code.
#So I decide to keep catch2 tests and c++ solutions in the same files.
#add_subdirectory(test)