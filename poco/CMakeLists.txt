
project(poco LANGUAGES CXX)

add_executable(hello hello.cpp)
target_link_libraries(hello ${CONAN_LIBS})