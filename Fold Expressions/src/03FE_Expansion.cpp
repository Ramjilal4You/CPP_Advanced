#include <iostream>

// In C++17 and later, you can use fold expressions to achieve the same result more concisely.
template<typename... Args>
auto sum_fold(Args... args) {
    return (... + args);    // left fold expression
}

int main() {
    int sum = sum_fold(11, 12, 13, 14, 15);
    
    return 0;
}

/*
========================================================
// Command to compile and generate assembly code
==> g++ -std=c++17 -fdump-tree-original .\03FE_Expansion.cpp
==> g++ -std=c++17 -S 03FE_Expansion.cpp
========================================================

// Assembly code generated
pushl   %ebp                
movl    %esp, %ebp
movl    8(%ebp), %edx      ; Load 1st argument into edx
movl    12(%ebp), %eax     ; Load 2nd argument into eax
addl    %eax, %edx         ; edx = arg1 + arg2
movl    16(%ebp), %eax     ; Load 3rd argument into eax
addl    %eax, %edx         ; edx = (arg1 + arg2) + arg3
movl    20(%ebp), %eax     ; Load 4th argument into eax
addl    %eax, %edx         ; edx = ((arg1 + arg2) + arg3) + arg4
movl    24(%ebp), %eax     ; Load 5th argument into eax
addl    %edx, %eax         ; eax = (((arg1 + arg2) + arg3) + arg4) + arg5
popl    %ebp               
ret                        ; Return with result in eax

*/