.phony: default
default:
	cmake -S ./ -B build
	cmake --build build && cd build && ctest && cd -