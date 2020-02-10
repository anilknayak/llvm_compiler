# Mutable Function pass
When you look for patterns in the program and, optionally, change the code when you find them.
For that you can write a mutable function pass which will convert the operator operation logic while compilation.

## Simple Add cpp program
1. example.cpp: adds 10+2 and prints 12
2. `cc example.cpp`: compiles and build binary `a.out` run that file. Output will be 12

## Make mutable function pass
1. mkdir build
2. cd build
3. cmake ..
4. make
5. cd ..

After this step you have already created a '.so' file for your function pass under the build directory module directory.

## Invoke Function pass
clang -Xclang -load -Xclang build/mutable_function_pass/libMutableFunctionPass.so ./mutable_function_pass/example.cpp

1. `-Xclang -load -Xclang path/to/lib*.so` : will load and activate the pass
2. If you need to process larger projects, you can just add those arguments to a Makefile’s CFLAGS or the equivalent for your build system
3. `a.out`: will be generated after invoking the mutable function pass and generate new code by replacing the 
operators with * (multiply operator)
4. Now the output of the binary will change to 20, because the the add operator is overridden by * operator.

