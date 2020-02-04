
project(poco LANGUAGES CXX)

add_executable(hello hello.cpp)
target_link_libraries(hello ${CONAN_LIBS})

add_executable(server server.cpp)
target_link_libraries(server ${CONAN_LIBS})