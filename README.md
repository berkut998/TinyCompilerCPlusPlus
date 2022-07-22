# TinyCompilerCPlusPlus

A translation this project (https://github.com/berkut998/TinyCompiler) to c++.

Compiler for a simple programming language into a small assembly language.The programming language has this syntax:
    
    function   ::= '[' arg-list ']' expression

    arg-list   ::= /* nothing */
                 | variable arg-list

    expression ::= term
                 | expression '+' term
                 | expression '-' term

    term       ::= factor
                 | term '*' factor
                 | term '/' factor

    factor     ::= number
                 | variable
                 | '(' expression ')'


Small processor with two registers (R0 and R1), a stack, and an array of input arguments. The processor supports the following instructions:

    "IM n"     // load the constant value n into R0
    "AR n"     // load the n-th input argument into R0
    "SW"       // swap R0 and R1
    "PU"       // push R0 onto the stack
    "PO"       // pop the top value off of the stack into R0
    "AD"       // add R1 to R0 and put the result in R0
    "SU"       // subtract R1 from R0 and put the result in R0
    "MU"       // multiply R0 by R1 and put the result in R0
    "DI"       // divide R0 by R1 and put the result in R0



Do not support error processing, all input should be valid.

Application screenshots:

![image](https://user-images.githubusercontent.com/66470614/180432847-34281d7a-377c-428a-9bc4-b0daa54f2c7e.png)
