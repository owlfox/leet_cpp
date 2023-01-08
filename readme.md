## Introduction
This repository uses cmake to build and test my c++ solutions to leetcode.
At the moment I'm using vscode Microsoft cmake extension to build and run the tests.

## Goals:
* Practice data structures and algorithms in leet code that are essential for a developer to success in daily tasks.
* Incoproate modern build and test tools/flows into the repo like cmake(For cmake basics, see examples in `modern_cmake` folder).
* all codes here should be easy to build and come with easy to understand tests.
<<<<<<< HEAD
* All major data structures and algorithms should be reviewed.
* Bear good engineering writing in mind, write clean and well documented code for your future self.
=======

>>>>>>> b29e6273b7c722c53f77eec2c8deb3f446572b3b

Note: Somehow this is also a repo with many of my c/c++ related code/learning material.. 
Bear with me I will clean this up..

<<<<<<< HEAD

## Leet code solutions and their unit tests
1. catch2 is being used to test, which is installed by `conan`, a c/c++ library manager( `pip install conan`)

2. run followed commands to build and test:

```
cmake -S ./ -B build
cd build;
conan install ../
=======
# WIP...

## dependencies 
* `conan`, a c/c++ library manager: `pip install conan`

## cpp dependency catch2
```
mkdir -p build && cd build
conan install ..
cmake ..
ninja
>>>>>>> b29e6273b7c722c53f77eec2c8deb3f446572b3b
make && make test
```

# TODO
<<<<<<< HEAD
* learn cmake 
    install cmake-3.25.1 from https://github.com/Kitware/CMake/releases, bash the *.sh to install locally
    source source.sh



=======
* learn cmake
    install it from https://github.com/Kitware/CMake/releases, bash with *.sh
    source source.sh
    cd
* try ninja
>>>>>>> b29e6273b7c722c53f77eec2c8deb3f446572b3b
* RxCPP
* Actor CPP
* networking with boost.asio
* logger
* DSP example
* Dahua Data structure
* Error report / deadly signal handler examples for program crash:
  * http://msinilo.pl/blog2/post/p269/
