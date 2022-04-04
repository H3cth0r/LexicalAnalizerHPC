
// The compile command
// Ubuntu:
// clang++ -shared -fPIC -std=c++11 -I./pybind11/include/ `python3.5 -m pybind11 --includes` pybind.cpp -o mymodule.so `python3.5-config --ldflags`
//
// Mac:
// (Should be similar to Linux)
//
// Mysys/Windows:
// g++ -std=c++14 -shared -fPIC -static-libgcc -static-libstdc++ -I./include/ -I./pybind11/include/ `python3.6 -m pybind11 --includes` *.cpp -o mymodule.pyd `python3.6-config --ldflags` -lmingw32 -mwindows -L libwinpthread-1.dll
//
// Make sure your module is named the same as the module you are making (i.e.
// mymodule.so and the PYBIND11_MODULE
//
// Make sure you are also using the correct version of python!
#include <pybind11/pybind11.h>
#include <string>



int add(int a, int b){
    return a+b;
}

struct Pet{
    Pet(const std::string &name) : name(name){}
    void setName(const std::string &name_){
        name = name_;
    }
    const std::string &getName() const { return name; }

    std::string name;
};



// Creates a macro function that will be called
// whenever the module is imported into python
// 'mymodule' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
namespace py = pybind11;
PYBIND11_MODULE(cmake_example, m){
    m.doc() = "example plugin"; // Optional docstring
    m.def("add", &add, "Add two integers.");

    py::class_<Pet>(m, "Pet")
            .def(py::init<const std::string &>())   // our constructor
            .def("setName", &Pet::setName)      // Expose member methods
            .def("getName", &Pet::getName)      // Think about the syntax "&Pet then "::" and the method name
            .def_readwrite("name",&Pet::name);  // Expose member variables
}