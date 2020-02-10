# llvm_compiler

1. GCC is a program language compiler developed by GNU
2. LLVM contains a series of modularized compiler components and tool chains
3. LLVM can optimize program languages and links during compilation, runtime, and idle time and generate code.
4. LLVM can serve as a background for compilers in multiple languages. 
5. Clang is a C, C++, Objective-C, or Objective-C++ compiler that is compiled in C++ based on LLVM


Higher expressiveness increases the burden of the compiler to generate good assembly code from the 
complex structures compiled by programmers. C++ standards are increasingly expressive and abstract. 
Python is popular because it is more readable and expressive, even at the cost of a lower running speed.

We must first consider whether the same code segment can generate more efficient assembly commands.

Compiler has two main structures
1. Frontend
2. Optimizer
3. Machine Code Generation
