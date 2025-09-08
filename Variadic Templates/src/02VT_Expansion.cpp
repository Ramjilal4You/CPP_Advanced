// Variadic Templates Expansion
#include<iostream>

// Base case: function with one parameter
template<class T>
T Sum(T last){
    return last;
}

// Recursive case: function with multiple parameters
template<class T, class... Args>
T Sum(T first, Args... args){
    return first + Sum(args...); // Recursive call with one less argument
}

int main(){
    int res = Sum(1, 2, 3, 4);  // Outputs 6
    std::cout << res;
    return 0;
}

//g++ -fdump-tree-original .\01Function_Templates.cpp
//g++ -S .\01Function_Templates.cpp
