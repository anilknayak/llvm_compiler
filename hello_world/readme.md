This is just a sample hello world program to understand the high level llvm compiler

1. hello.cpp: C++ program
2. `clang++ hello.cpp -o hello`: Build the hello program using clang++ compiler
3. `clang++ -S -emit-llvm hello.cpp`: clang++ used to emit LLVM IR
a. -emit-llvm: Use LLVM representation for assembler and object files
b. -S: only runs preprocessor and compilation steps
4. `lli hello.ll`: This `lli` runs the intermediate LLVM representation object file
5. `llvm-as hello.ll`: This will generate object code using LLVM compiler (hello.bc)
6. `llc hello.bc -mcpu=help`: This will output the supported CPU arch, for which the code is going to build and run on that CPU architecture.
7. `llc hello.bc`: This will generate assembly code using LLVM compiler (hello.s)
8. `opt hello.ll --time-passes`: This will gives us the execution time of the code and LLVM IR parsing time.


This is just a starting point of LLVM compiler for code generation for C++. LLVM is widely used as the C++ compiler. Many C++ application has been build using LLVM compiler support. Which is very efficient in terms of optimizer, which optimizes the code block to run on the different CPU archtecture by using vector extension units in the Complex Instruction Set Computer (CISC) or Reduced Instruction Set Computer (RISC) architecture. Modern computing systems with multiple kernels, vector processing capabilities. Compiler optimizes using the vector processing provided by the CPU arch and performing the multiplication, addition and bit mask efficiently.

More Tutorial on LLVM follow this github repo.