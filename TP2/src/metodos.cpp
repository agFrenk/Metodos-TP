#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h> 
#include "power_iteration.h"

namespace py = pybind11;

PYBIND11_MODULE(metnum, m) {
    m.def(
        "power_iteration", &power_iteration,
        "Function that calculates eigenvector",
        py::arg("X"),
        py::arg("niter") = 5000,
        py::arg("epsilon") = 1e-16
    );
    m.def(
        "power_iteration_deflation", &power_iteration_deflation,
        "Function that calculates multiple eigenvectors using deflation",
        py::arg("X"),
        py::arg("num") = 2,
        py::arg("niter") = 1000,
        py::arg("epsilon") = 1e-6
    );
}