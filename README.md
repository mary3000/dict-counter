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

### Check on a huge file

There is also automatic script, that build (if neccessary) and runs the program on a huge file (`huge.txt`).
If output ends with `SUCCESS`, check was passed. If it end with `FAIL` or any other output - something went wrong.

Just run:  
`bash test_huge.sh`
