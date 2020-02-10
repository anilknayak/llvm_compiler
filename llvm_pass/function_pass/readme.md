# Simple Function Pass
1. LLVM invokes the method above with every function it finds in the program we’re compiling.

## Steps
1. mkdir build
2. cd build
3. cmake ..
4. make
5. cd ..

After this step you have already created a '.so' file for your function pass under the build directory module directory.

## Invoke Function pass
clang -Xclang -load -Xclang build/function_pass/libInvokeFunctionPass.so ../hello_world/hello.cpp

1. `-Xclang -load -Xclang path/to/lib*.so` : will load and activate the pass
2. If you need to process larger projects, you can just add those arguments to a Makefile’s CFLAGS or the equivalent for your build system

