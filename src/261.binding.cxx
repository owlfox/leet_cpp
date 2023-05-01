#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // Include this header for automatic conversion
#include "261.cxx"  // Include your existing solution code here

namespace py = pybind11;

PYBIND11_MODULE(solution, m) {
    py::class_<Solution>(m, "Solution")
        .def(py::init<>())
        .def("validTree", &Solution::validTree);
}