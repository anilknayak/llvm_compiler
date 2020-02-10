# llvm_compiler

1. GCC is a program language compiler developed by GNU
2. LLVM contains a series of modularized compiler components and tool chains
3. LLVM can optimize program languages and links during compilation, runtime, and idle time and generate code.
4. LLVM can serve as a background for compilers in multiple languages. 
5. Clang is a C, C++, Objective-C, or Objective-C++ compiler that is compiled in C++ based on LLVM

## Why LLVM
1. LLVM’s intermediate representation (IR) is its great innovation. LLVM works on a representation of programs that you can actually read if you can read assembly. This may not seem like a great revelation, but it is: other compilers’ IRs tend to be in-memory structures so complicated that you can’t really write them down. This makes other compilers harder to understand and messier to implement.
2. LLVM is nicely written: its architecture is way more modular than other compilers. Part of the reason for this niceness comes from its original implementor.

## LLVM workflow
1. The front end, which takes your source code and turns it into an intermediate representation or IR. This translation simplifies the job of the rest of the compiler, which doesn’t want to deal with the full complexity of C++ source code.
2. The passes, which transform IR to IR. In ordinary circumstances, passes usually optimize the code: that is, they produce an IR program as output that does the same thing as the IR they took as input, except that it’s faster. This is where you want to hack. Your research tool can work by looking at and changing IR as it flows through the compilation process.
3. The back end, which generates actual machine code. You almost certainly don’t need to touch this part.


Higher expressiveness increases the burden of the compiler to generate good assembly code from the 
complex structures compiled by programmers. C++ standards are increasingly expressive and abstract. 
Python is popular because it is more readable and expressive, even at the cost of a lower running speed.

We must first consider whether the same code segment can generate more efficient assembly commands.

Compiler has two main structures
1. Frontend
2. Optimizer
3. Machine Code Generation

# LLVM Learning outline
### hello_world: LLVM compiler in high level
### llvm_pass: Learn LLVM compiler passes (code optimizer)
### More to come ...
