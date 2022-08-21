# dict-counter

## todo

- Dockerize

## Instructions

### Clion

The best option is to use CLion or other IDE that supports C++ and CMake projects.

Main target: `dict_counter`, arguments: `<input_file> <output_file>`.

Test target: `dict_test`.

### CMake build 
 
`mkdir build && cd build`  
`cmake ..`  
`cmake --build .`  
`./src/dict_counter <input_file> <output_file>`

For testing, run `ctest` from the `build` directory
