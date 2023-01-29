## Introduction
This repository uses cmake to build and test my C++ solutions to leetcode or say, ideally, any good/1337/leet code snippet I found interesting while practicing C++ system programming.

## Goals:
* Practice data structures and algorithms in leet code that are essential for a developer to success in daily tasks.
* Incoproate modern build and test tools/flows with cmake.
* All major data structures and algorithms interviewer cares should be reviewed.
* Bear good engineering writing in mind, write clean and well documented code for your future self. All codes here should be easy to build and come with easy to understand tests.(I forget from time to time..- -)

Note: Somehow this is also a repo with many of my c/c++ related code/learning material.. 
Bear with me I will clean this up..


## Leet code solutions and their unit tests
1. run followed commands to build and test or just `make`:

```
cmake -S ./ -B build
cmake --build build && cd build && ctest && cd -

```

# TODO
When I got time and interest.. I think some code relates to followed topics will be added.
* RxCPP
* Actor CPP
* networking with boost.asio
* logger
* DSP example
* Dahua Data structure
* Error report / deadly signal handler examples for program crash:
  * http://msinilo.pl/blog2/post/p269/

# Reference
1. https://github.com/PacktPublishing/Modern-CMake-for-Cpp
