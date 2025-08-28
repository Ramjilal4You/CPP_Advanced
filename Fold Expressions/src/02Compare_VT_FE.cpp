#include <iostream>

// =================================
// Before C++17: Recursive Variadic Template Function
template<typename T>
T SumVariadicTemplate(T value) {
    return value;
}

template<typename T, typename... Args>
T SumVariadicTemplate(T first, Args... args) {
    return first + SumVariadicTemplate(args...);
}

// In C++17 and later, you can use fold expressions to achieve the same result more concisely.
template<typename... Args>
auto SumFoldExpression(Args... args) {
    return (... + args);    // left fold expression
}

int main() {
    int vt_res = SumVariadicTemplate(1, 2, 3, 4);
    int fe_res = SumFoldExpression(1, 2, 3, 4);

    std::cout << "Sum (before fold expressions): " << vt_res << std::endl;
    std::cout << "Sum (Using fold expressions): " << fe_res << std::endl;
    return 0;
}

/*
========================================================
// Command to compile and generate assembly code    
==> g++ -std=c++14 -fdump-tree-original .\02BeforeCpp17.cpp
==> g++ -std=c++14 -S 02BeforeCpp17.cpp
========================================================
*/