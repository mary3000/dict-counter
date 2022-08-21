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

There is also an automatic script, that builds (if necessary) and runs the program on a huge file (`huge.txt`).
If output ends with `SUCCESS`, check was passed. If it ends with `FAIL` or any other output - something went wrong.

1. Put some huge file in the root of the project, and name it `huge.txt`
2. Put the expected dictionary file in the same directory; name it `out_huge.txt`
3. Run `bash test_huge.sh`
